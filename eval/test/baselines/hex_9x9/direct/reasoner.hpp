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

using Piece = uint;
using Player = uint;
using Position = uint;
using PositionOrNull = uint;
using Score = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint empty = 0;
constexpr uint border = 1;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint V__1_1 = 0;
constexpr uint V__1_2 = 1;
constexpr uint V__1_3 = 2;
constexpr uint V__1_4 = 3;
constexpr uint V__1_5 = 4;
constexpr uint V__1_6 = 5;
constexpr uint V__1_7 = 6;
constexpr uint V__1_8 = 7;
constexpr uint V__1_9 = 8;
constexpr uint V__2_1 = 9;
constexpr uint V__2_2 = 10;
constexpr uint V__2_3 = 11;
constexpr uint V__2_4 = 12;
constexpr uint V__2_5 = 13;
constexpr uint V__2_6 = 14;
constexpr uint V__2_7 = 15;
constexpr uint V__2_8 = 16;
constexpr uint V__2_9 = 17;
constexpr uint V__3_1 = 18;
constexpr uint V__3_2 = 19;
constexpr uint V__3_3 = 20;
constexpr uint V__3_4 = 21;
constexpr uint V__3_5 = 22;
constexpr uint V__3_6 = 23;
constexpr uint V__3_7 = 24;
constexpr uint V__3_8 = 25;
constexpr uint V__3_9 = 26;
constexpr uint V__4_1 = 27;
constexpr uint V__4_2 = 28;
constexpr uint V__4_3 = 29;
constexpr uint V__4_4 = 30;
constexpr uint V__4_5 = 31;
constexpr uint V__4_6 = 32;
constexpr uint V__4_7 = 33;
constexpr uint V__4_8 = 34;
constexpr uint V__4_9 = 35;
constexpr uint V__5_1 = 36;
constexpr uint V__5_2 = 37;
constexpr uint V__5_3 = 38;
constexpr uint V__5_4 = 39;
constexpr uint V__5_5 = 40;
constexpr uint V__5_6 = 41;
constexpr uint V__5_7 = 42;
constexpr uint V__5_8 = 43;
constexpr uint V__5_9 = 44;
constexpr uint V__6_1 = 45;
constexpr uint V__6_2 = 46;
constexpr uint V__6_3 = 47;
constexpr uint V__6_4 = 48;
constexpr uint V__6_5 = 49;
constexpr uint V__6_6 = 50;
constexpr uint V__6_7 = 51;
constexpr uint V__6_8 = 52;
constexpr uint V__6_9 = 53;
constexpr uint V__7_1 = 54;
constexpr uint V__7_2 = 55;
constexpr uint V__7_3 = 56;
constexpr uint V__7_4 = 57;
constexpr uint V__7_5 = 58;
constexpr uint V__7_6 = 59;
constexpr uint V__7_7 = 60;
constexpr uint V__7_8 = 61;
constexpr uint V__7_9 = 62;
constexpr uint V__8_1 = 63;
constexpr uint V__8_2 = 64;
constexpr uint V__8_3 = 65;
constexpr uint V__8_4 = 66;
constexpr uint V__8_5 = 67;
constexpr uint V__8_6 = 68;
constexpr uint V__8_7 = 69;
constexpr uint V__8_8 = 70;
constexpr uint V__8_9 = 71;
constexpr uint V__9_1 = 72;
constexpr uint V__9_2 = 73;
constexpr uint V__9_3 = 74;
constexpr uint V__9_4 = 75;
constexpr uint V__9_5 = 76;
constexpr uint V__9_6 = 77;
constexpr uint V__9_7 = 78;
constexpr uint V__9_8 = 79;
constexpr uint V__9_9 = 80;
constexpr uint null = 81;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
const Arr<std::vector<PositionOrNull>, 2> firstEdgeiter = Arr<std::vector<PositionOrNull>, 2>{std::vector<PositionOrNull>{V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,},std::vector<PositionOrNull>{V__1_1,V__2_1,V__3_1,V__4_1,V__5_1,V__6_1,V__7_1,V__8_1,V__9_1,},};
constexpr Arr<PositionOrNull, 82> upLeft = Arr<PositionOrNull, 82>{null,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,null,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,};
constexpr Arr<PositionOrNull, 82> upRight = Arr<PositionOrNull, 82>{null,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 82> left = Arr<PositionOrNull, 82>{null,null,null,null,null,null,null,null,null,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,};
constexpr Arr<PositionOrNull, 82> right = Arr<PositionOrNull, 82>{V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 82> downLeft = Arr<PositionOrNull, 82>{null,null,null,null,null,null,null,null,null,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,null,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,null,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,null,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,null,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,null,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,null,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,null,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,null,};
constexpr Arr<PositionOrNull, 82> downRight = Arr<PositionOrNull, 82>{V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,null,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,null,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,null,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,null,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,null,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,null,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,null,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,null,null,};
constexpr Arr<Arr<Bool, 82>, 2> firstEdge = Arr<Arr<Bool, 82>, 2>{Arr<Bool, 82>{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 82>{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},};
constexpr Arr<Arr<Bool, 82>, 2> secondEdge = Arr<Arr<Bool, 82>, 2>{Arr<Bool, 82>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,},Arr<Bool, 82>{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,},};

using move_representation = std::array<uint,1>;
class GameState;

class RgCache;

struct Move
{
move_representation mr = {unusedTag};

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
Arr<Piece, 82> board = Arr<Piece, 82>{empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,border,};
PositionOrNull pos = null;
Player turn_arg0_me = white;
Player turn_arg1_op = white;
Player win_arg0_p = white;
Player reachableEdge_arg0_p = white;
Arr<Arr<Bool, 82>, 2> reachableEdge_arg1_edge = Arr<Arr<Bool, 82>, 2>{Arr<Bool, 82>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 82>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 1;

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
return currentState == 2;
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
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_10([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_13([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_14([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_17([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_4([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_6([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_7([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_8([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_begin([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_end([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_1([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_10([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_13([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_14([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_17([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_4([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_6([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_7([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_8([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_begin([[maybe_unused]]RgCache& rgCache);
bool is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_end([[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_3__1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_3__2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_3_turn_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_3_turn_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_rules_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_6([[maybe_unused]]RgCache& rgCache);
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
state_cache_rules_3_turn_9_win_5_reachableEdge_10.reset();
state_cache_rules_3_turn_9_win_5_reachableEdge_12.reset();
state_cache_rules_3_turn_9_win_5_reachableEdge_14.reset();
state_cache_rules_3_turn_9_win_5_reachableEdge_16.reset();
state_cache_rules_3_turn_9_win_5_reachableEdge_6.reset();
state_cache_rules_3_turn_9_win_5_reachableEdge_8.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_10.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_12.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_14.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_16.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_6.reset();
state_cache_rules_5_turn_9_win_5_reachableEdge_8.reset();
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
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_10;
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_12;
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_14;
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_16;
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_6;
std::bitset<82> state_cache_rules_3_turn_9_win_5_reachableEdge_8;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_10;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_12;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_14;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_16;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_6;
std::bitset<82> state_cache_rules_5_turn_9_win_5_reachableEdge_8;
};


}  // namespace reasoner
