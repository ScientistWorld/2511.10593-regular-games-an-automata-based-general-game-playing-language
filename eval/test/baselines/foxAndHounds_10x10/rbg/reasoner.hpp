#include <array>
#include <bitset>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>

#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>

namespace reasoner {
template<class T, std::size_t N>
using Arr = std::array<T, N>;
struct gameStateHasher;

using RbgType1 = uint;
using Player = uint;
using Score = uint;
using Piece = uint;
using Coord = uint;
using CoordOrNull = uint;
using RbgType2 = uint;
using RbgType3 = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Board = Arr<Piece, 51>;
using Counters = Arr<RbgType1, 4>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y4 = 1;
constexpr uint rx0y5 = 2;
constexpr uint rx1y3 = 3;
constexpr uint rx1y4 = 4;
constexpr uint rx1y5 = 5;
constexpr uint rx1y6 = 6;
constexpr uint rx2y2 = 7;
constexpr uint rx2y3 = 8;
constexpr uint rx2y4 = 9;
constexpr uint rx2y5 = 10;
constexpr uint rx2y6 = 11;
constexpr uint rx2y7 = 12;
constexpr uint rx3y1 = 13;
constexpr uint rx3y2 = 14;
constexpr uint rx3y3 = 15;
constexpr uint rx3y4 = 16;
constexpr uint rx3y5 = 17;
constexpr uint rx3y6 = 18;
constexpr uint rx3y7 = 19;
constexpr uint rx3y8 = 20;
constexpr uint rx4y0 = 21;
constexpr uint rx4y1 = 22;
constexpr uint rx4y2 = 23;
constexpr uint rx4y3 = 24;
constexpr uint rx4y4 = 25;
constexpr uint rx4y5 = 26;
constexpr uint rx4y6 = 27;
constexpr uint rx4y7 = 28;
constexpr uint rx4y8 = 29;
constexpr uint rx4y9 = 30;
constexpr uint rx5y1 = 31;
constexpr uint rx5y2 = 32;
constexpr uint rx5y3 = 33;
constexpr uint rx5y4 = 34;
constexpr uint rx5y5 = 35;
constexpr uint rx5y6 = 36;
constexpr uint rx5y7 = 37;
constexpr uint rx5y8 = 38;
constexpr uint rx6y2 = 39;
constexpr uint rx6y3 = 40;
constexpr uint rx6y4 = 41;
constexpr uint rx6y5 = 42;
constexpr uint rx6y6 = 43;
constexpr uint rx6y7 = 44;
constexpr uint rx7y3 = 45;
constexpr uint rx7y4 = 46;
constexpr uint rx7y5 = 47;
constexpr uint rx7y6 = 48;
constexpr uint rx8y4 = 49;
constexpr uint rx8y5 = 50;
constexpr uint null = 0;
constexpr uint e = 1;
constexpr uint f = 2;
constexpr uint h = 3;
constexpr uint foxPlayer = 2;
constexpr uint houndPlayer = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 51;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 51> direction_downLeft = Arr<CoordOrNull, 51>{null,rx0y5,null,rx1y4,rx1y5,rx1y6,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,null,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,rx7y4,rx7y5,rx7y6,null,rx8y5,null,};
constexpr Arr<CoordOrNull, 51> direction_downRight = Arr<CoordOrNull, 51>{null,rx1y4,rx1y5,rx2y3,rx2y4,rx2y5,rx2y6,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,null,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,null,rx7y3,rx7y4,rx7y5,rx7y6,null,null,rx8y4,rx8y5,null,null,null,};
constexpr Arr<CoordOrNull, 51> direction_upLeft = Arr<CoordOrNull, 51>{null,null,null,null,rx0y4,rx0y5,null,null,rx1y3,rx1y4,rx1y5,rx1y6,null,null,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx6y3,rx6y4,rx6y5,rx6y6,rx7y4,rx7y5,};
constexpr Arr<CoordOrNull, 51> direction_upRight = Arr<CoordOrNull, 51>{null,null,rx0y4,null,rx1y3,rx1y4,rx1y5,null,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,null,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,null,rx7y3,rx7y4,rx7y5,null,rx8y4,};

using move_representation = std::array<uint,2>;
class GameState;

class RgCache;

struct Move
{
move_representation mr = {unusedTag,unusedTag};

    Move(void) = default;
    Move(const move_representation& mv) : mr(mv)
    {}

    bool operator==(const Move& rhs) const
    {
        return mr == rhs.mr;
    }
};


namespace
{
inline void combine(size_t& acc, size_t x) noexcept
{
    acc ^= x;
}

inline size_t hash(uint x) noexcept
{
    return x;
}

template<template<typename, size_t, typename...> class Container, typename T, size_t N, typename... Args>
size_t hash(const Container<T, N, Args...>& range) noexcept
{
    size_t acc = 0;
    for (const auto& x : range)
    {
        acc ^= hash(x);
    }
    return acc;
}
}  // namespace

struct move_hash
{
    size_t operator()(const move_representation& move) const noexcept
    {
        return hash(move);
    }
};

class GameState
{
private:
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,h,e,e,e,e,e,e,e,h,e,e,e,e,e,h,e,e,e,h,e,h,};
CoordOrNull coord = rx4y0;
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 49;

public:
struct Hasher
    {
        size_t operator()(const std::tuple<GameState, uint>& state) const noexcept;
        size_t operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept;
    };

bool operator==(const GameState& rhs) const;
public:
  bool isTerminal()const
  {
return currentState == 50;
  }

  Score getPlayerScore(Player player)const
  {
return goals[player- 2];
  }

  PlayerOrSystem getCurrentPlayer()const
  {
return player;
  }

std::string getStateDescription()const;
void getAllMoves(std::vector<Move>& moves, RgCache& rgCache);
void applyMove(const Move& mr, RgCache& rgCache);
void applyAnyMove([[maybe_unused]]RgCache& rgCache);
private:
bool is_legal_17_28_17_17_28_28_17_28_17();
bool is_legal_17_28_17_17_28_28_17_28_20();
bool is_legal_17_28_17_17_28_28_17_28_28();
bool is_legal_27_42_27_27_42_42_27_42_27();
bool is_legal_27_42_27_27_42_42_27_42_30();
bool is_legal_27_42_27_27_42_42_27_42_42();
bool is_legal_58_59_58();
bool is_legal_58_59_59();
bool is_legal_70_88_70_70_88_88_70_88_70();
bool is_legal_70_88_70_70_88_88_70_88_73();
bool is_legal_70_88_70_70_88_88_70_88_75();
bool is_legal_70_88_70_70_88_88_70_88_78();
bool is_legal_70_88_70_70_88_88_70_88_79();
bool is_legal_70_88_70_70_88_88_70_88_80();
bool is_legal_70_88_70_70_88_88_70_88_88();
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_104([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_107([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_109([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_113([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_88([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_104([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_107([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_109([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_113([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_70([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_88([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_10_10_10();
bool apply_any_10_10_104();
bool apply_any_10_10_107();
bool apply_any_10_10_15();
bool apply_any_10_10_17();
bool apply_any_10_10_end();
bool apply_any_17_17_104();
bool apply_any_17_17_109();
bool apply_any_17_17_17();
bool apply_any_17_17_20();
bool apply_any_17_17_22();
bool apply_any_17_17_23();
bool apply_any_17_17_27();
bool apply_any_17_17_end();
bool apply_any_45_45_104();
bool apply_any_45_45_113();
bool apply_any_45_45_44();
bool apply_any_45_45_45();
bool apply_any_45_45_50();
bool apply_any_45_45_53();
bool apply_any_45_45_55();
bool apply_any_45_45_70();
bool apply_any_45_45_end();
bool apply_any_91_91_104();
bool apply_any_91_91_107();
bool apply_any_91_91_15();
bool apply_any_91_91_17();
bool apply_any_91_91_90();
bool apply_any_91_91_91();
bool apply_any_91_91_96();
bool apply_any_91_91_end();
bool apply_any_begin_begin_5();
bool apply_any_begin_begin_begin();
};
class RgCache{
public:
RgCache()
{
    pattern_cache.reserve(2);
    pattern_cache.resize(1);
}
inline void reset()
{
    currentMrId = 0;

    depth = 0;
    pattern_cache[0].clear();
    state_cache.clear();
state_cache_30.reset();
state_cache_80.reset();
}
inline void clearCurrent() { pattern_cache[depth].clear(); }
inline bool insert(const GameState& gameState, const uint nodeId)
{
    return pattern_cache[depth].insert(std::make_tuple(gameState, nodeId)).second;
}inline bool insert(const GameState& gameState, const move_representation& mr, const uint nodeId)
{
    return state_cache.insert(std::make_tuple(gameState, mr, nodeId)).second;
}inline void incDepth()
{
    ++depth;
    if (depth >= pattern_cache.size())
    {
        pattern_cache.push_back({});
    }
    else
    {
        pattern_cache[depth].clear();
    }
}
inline void decDepth() { --depth; }

unsigned depth = 0;
std::unordered_set<std::tuple<GameState, move_representation, uint>, GameState::Hasher> state_cache;
std::vector<std::unordered_set<std::tuple<GameState, uint>, GameState::Hasher>> pattern_cache;
uint currentMrId = 0;
std::bitset<51> state_cache_30;
std::bitset<51> state_cache_80;
};


}  // namespace reasoner
