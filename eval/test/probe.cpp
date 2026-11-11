// Symbol probe: exercises the forward-model API without any I/O so that every
// external symbol referenced by this object comes from the submitted header.
#include <vector>
#include <reasoner.hpp>

void rg_eval_probe(unsigned k) {
  reasoner::GameState state;
  reasoner::RgCache cache;
  std::vector<reasoner::Move> moves;
  for (unsigned i = 0; i < k; ++i) {
    const auto who = state.getCurrentPlayer();
    if (who == reasoner::keeper) {
      if (state.isTerminal()) break;
      state.applyAnyMove(cache);
      continue;
    }
    state.getAllMoves(moves, cache);
    if (moves.empty()) break;
    reasoner::GameState copy = state;
    copy.applyMove(moves[i % moves.size()], cache);
    state = copy;
    volatile auto score = state.getPlayerScore(2 + (i % reasoner::PLAYERS_COUNT));
    (void)score;
  }
}
