// Evaluator-owned forward-model driver (held-out slice).
//
// Links against a submitted `reasoner.hpp/.cpp` exposing the RG forward-model
// API (reasoner::GameState, reasoner::RgCache, reasoner::Move, getAllMoves,
// applyMove, applyAnyMove, getCurrentPlayer, isTerminal, getPlayerScore,
// reasoner::PLAYERS_COUNT, reasoner::keeper, reasoner::random).
//
// Modes:
//   perft DEPTH         exhaustive game tree to DEPTH player decisions
//   play  COUNT SEED    COUNT uniformly random playouts (flat Monte Carlo)
//
// All state of this driver has internal linkage so linked code cannot reach it.
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <reasoner.hpp>

namespace {

struct Rng {
  std::uint64_t s;
  explicit Rng(std::uint64_t seed) : s(seed * 0x9E3779B97F4A7C15ULL + 0x632BE59BD9B4E019ULL) {}
  std::uint64_t next() {
    std::uint64_t z = (s += 0x9E3779B97F4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
  }
  std::uint32_t below(std::uint32_t n) {
    return static_cast<std::uint32_t>(((next() >> 32) * static_cast<std::uint64_t>(n)) >> 32);
  }
};

constexpr unsigned MAX_PERFT_DEPTH = 64;
constexpr std::uint64_t MAX_PLIES = 1000000;

reasoner::RgCache g_cache;
std::vector<reasoner::Move> g_moves[MAX_PERFT_DEPTH + 1];
std::vector<reasoner::Move> g_play_moves;
std::uint64_t g_states = 0, g_leaves = 0, g_terminals = 0;

[[noreturn]] void fail(int code, const char* what) {
  std::cout << "DRIVER_ERROR " << code << " " << what << std::endl;
  std::exit(code);
}

// Settle keeper (deterministic system) moves; random-player moves are drawn
// uniformly. Returns false when the game reached a terminal state.
bool settle(reasoner::GameState& state, std::vector<reasoner::Move>& buf, Rng& rng) {
  for (std::uint64_t guard = 0;; ++guard) {
    if (guard > MAX_PLIES) fail(5, "keeper/random loop does not terminate");
    const auto who = state.getCurrentPlayer();
    if (who == reasoner::keeper) {
      if (state.isTerminal()) return false;
      state.applyAnyMove(g_cache);
    } else if (who == reasoner::random) {
      state.getAllMoves(buf, g_cache);
      if (buf.empty()) fail(6, "random player without moves");
      const std::uint32_t pick = rng.below(static_cast<std::uint32_t>(buf.size()));
      state.applyMove(buf[pick], g_cache);
    } else {
      if (state.isTerminal()) return false;
      return true;
    }
  }
}

bool settle_keeper(reasoner::GameState& state) {
  for (std::uint64_t guard = 0;; ++guard) {
    if (guard > MAX_PLIES) fail(5, "keeper loop does not terminate");
    if (state.getCurrentPlayer() != reasoner::keeper) return !state.isTerminal();
    if (state.isTerminal()) return false;
    state.applyAnyMove(g_cache);
  }
}

// Exhaustive tree: keeper moves are settled; real-player and random-player
// decisions are both expanded (labeling-invariant counts).
void perft(reasoner::GameState& state, unsigned depth) {
  ++g_states;
  if (depth == 0) { ++g_leaves; return; }
  auto& moves = g_moves[depth];
  state.getAllMoves(moves, g_cache);
  if (moves.empty()) fail(3, "nonterminal decision state without legal moves");
  const std::size_t n = moves.size();
  for (std::size_t i = 0; i < n; ++i) {
    reasoner::GameState next = state;
    next.applyMove(g_moves[depth][i], g_cache);
    if (!settle_keeper(next)) { ++g_states; ++g_terminals; continue; }
    perft(next, depth - 1);
  }
}

}  // namespace

int main(int argc, char** argv) {
  if (argc < 3) fail(1, "usage: perft DEPTH | play COUNT SEED");
  const std::string mode = argv[1];
  reasoner::GameState initial;
  std::vector<reasoner::Move> buf;
  if (mode == "perft") {
    const unsigned depth = static_cast<unsigned>(std::stoul(argv[2]));
    if (depth > MAX_PERFT_DEPTH) fail(1, "depth too large");
    if (!settle_keeper(initial)) fail(4, "initial state is terminal");
    perft(initial, depth);
    std::cout << "PERFT " << g_leaves << " " << g_states << " " << g_terminals << std::endl;
    return 0;
  }
  if (mode != "play" || argc < 4) fail(1, "usage: play COUNT SEED");
  const std::uint64_t count = std::stoull(argv[2]);
  Rng rng(std::stoull(argv[3]));
  const unsigned players = reasoner::PLAYERS_COUNT;
  // Per-playout aggregates: plies, mean branching over player decisions,
  // and each player's final score (first and second moments).
  long double sum_depth = 0, sq_depth = 0, sum_branch = 0, sq_branch = 0;
  std::vector<long double> sum_score(players, 0), sq_score(players, 0);
  std::uint64_t total_plies = 0, total_moves = 0, min_depth = ~0ULL, max_depth = 0;
  for (std::uint64_t sim = 0; sim < count; ++sim) {
    reasoner::GameState state = initial;
    std::uint64_t depth = 0, moves_here = 0;
    if (!settle(state, buf, rng)) fail(4, "initial state is terminal");
    while (true) {
      state.getAllMoves(g_play_moves, g_cache);
      const std::size_t n = g_play_moves.size();
      if (n == 0) fail(3, "nonterminal player state without legal moves");
      ++depth;
      moves_here += n;
      if (depth > MAX_PLIES) fail(5, "playout does not terminate");
      state.applyMove(g_play_moves[rng.below(static_cast<std::uint32_t>(n))], g_cache);
      if (!settle(state, buf, rng)) break;
    }
    total_plies += depth;
    total_moves += moves_here;
    if (depth < min_depth) min_depth = depth;
    if (depth > max_depth) max_depth = depth;
    const long double d = static_cast<long double>(depth);
    const long double b = static_cast<long double>(moves_here) / d;
    sum_depth += d; sq_depth += d * d; sum_branch += b; sq_branch += b * b;
    for (unsigned p = 0; p < players; ++p) {
      const long double sc = static_cast<long double>(state.getPlayerScore(p + 2));
      sum_score[p] += sc; sq_score[p] += sc * sc;
    }
  }
  std::cout.precision(17);
  std::cout << "PLAY " << count << " " << total_plies << " " << total_moves << " " << min_depth << " " << max_depth
            << " " << static_cast<double>(sum_depth) << " " << static_cast<double>(sq_depth)
            << " " << static_cast<double>(sum_branch) << " " << static_cast<double>(sq_branch) << " " << players;
  for (unsigned p = 0; p < players; ++p)
    std::cout << " " << static_cast<double>(sum_score[p]) << " " << static_cast<double>(sq_score[p]);
  std::cout << std::endl;
  return 0;
}
