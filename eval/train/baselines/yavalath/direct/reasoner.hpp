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
constexpr uint V__2_1 = 5;
constexpr uint V__2_2 = 6;
constexpr uint V__2_3 = 7;
constexpr uint V__2_4 = 8;
constexpr uint V__2_5 = 9;
constexpr uint V__2_6 = 10;
constexpr uint V__3_1 = 11;
constexpr uint V__3_2 = 12;
constexpr uint V__3_3 = 13;
constexpr uint V__3_4 = 14;
constexpr uint V__3_5 = 15;
constexpr uint V__3_6 = 16;
constexpr uint V__3_7 = 17;
constexpr uint V__4_1 = 18;
constexpr uint V__4_2 = 19;
constexpr uint V__4_3 = 20;
constexpr uint V__4_4 = 21;
constexpr uint V__4_5 = 22;
constexpr uint V__4_6 = 23;
constexpr uint V__4_7 = 24;
constexpr uint V__4_8 = 25;
constexpr uint V__5_1 = 26;
constexpr uint V__5_2 = 27;
constexpr uint V__5_3 = 28;
constexpr uint V__5_4 = 29;
constexpr uint V__5_5 = 30;
constexpr uint V__5_6 = 31;
constexpr uint V__5_7 = 32;
constexpr uint V__5_8 = 33;
constexpr uint V__5_9 = 34;
constexpr uint V__6_2 = 35;
constexpr uint V__6_3 = 36;
constexpr uint V__6_4 = 37;
constexpr uint V__6_5 = 38;
constexpr uint V__6_6 = 39;
constexpr uint V__6_7 = 40;
constexpr uint V__6_8 = 41;
constexpr uint V__6_9 = 42;
constexpr uint V__7_3 = 43;
constexpr uint V__7_4 = 44;
constexpr uint V__7_5 = 45;
constexpr uint V__7_6 = 46;
constexpr uint V__7_7 = 47;
constexpr uint V__7_8 = 48;
constexpr uint V__7_9 = 49;
constexpr uint V__8_4 = 50;
constexpr uint V__8_5 = 51;
constexpr uint V__8_6 = 52;
constexpr uint V__8_7 = 53;
constexpr uint V__8_8 = 54;
constexpr uint V__8_9 = 55;
constexpr uint V__9_5 = 56;
constexpr uint V__9_6 = 57;
constexpr uint V__9_7 = 58;
constexpr uint V__9_8 = 59;
constexpr uint V__9_9 = 60;
constexpr uint null = 61;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<PositionOrNull, 62> upLeft = Arr<PositionOrNull, 62>{null,V__1_1,V__1_2,V__1_3,V__1_4,null,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,null,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,null,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,null,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_5,V__9_6,V__9_7,V__9_8,null,};
constexpr Arr<PositionOrNull, 62> upRight = Arr<PositionOrNull, 62>{null,V__2_1,V__2_2,V__2_3,V__2_4,null,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,null,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,null,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,null,null,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,null,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,null,V__9_5,V__9_6,V__9_7,V__9_8,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 62> left = Arr<PositionOrNull, 62>{null,null,null,null,null,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,null,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,null,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,null,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,};
constexpr Arr<PositionOrNull, 62> right = Arr<PositionOrNull, 62>{V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,null,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 62> downLeft = Arr<PositionOrNull, 62>{null,null,null,null,null,V__1_2,V__1_3,V__1_4,V__1_5,null,null,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,null,null,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,null,null,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,null,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,null,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,null,V__8_6,V__8_7,V__8_8,V__8_9,null,null,};
constexpr Arr<PositionOrNull, 62> downRight = Arr<PositionOrNull, 62>{V__1_2,V__1_3,V__1_4,V__1_5,null,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,null,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,null,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,null,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,null,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,V__9_6,V__9_7,V__9_8,V__9_9,null,null,};

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
Arr<Piece, 62> board = Arr<Piece, 62>{empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,border,};
PositionOrNull pos = null;
Player turn_arg0_me = white;
Player turn_arg1_op = white;
Player line3_arg0_p = white;
Player line3InDir_arg0_p = white;
Arr<PositionOrNull, 62> line3InDir_arg1_dir1 = Arr<PositionOrNull, 62>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Arr<PositionOrNull, 62> line3InDir_arg2_dir2 = Arr<PositionOrNull, 62>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Player line4_arg0_p = white;
Player line4InDir_arg0_p = white;
Arr<PositionOrNull, 62> line4InDir_arg1_dir1 = Arr<PositionOrNull, 62>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Arr<PositionOrNull, 62> line4InDir_arg2_dir2 = Arr<PositionOrNull, 62>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Goals goals = Goals{50,50,};
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
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_1();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_2();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_1();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_2();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_4();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_6();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_begin();
bool is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_end();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_1();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_2();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_3();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_4();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_10();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_11();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_12();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_13();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_2();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_3();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_4();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_5();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_6();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_7();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_8();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_9();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_begin();
bool is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_end();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_1();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_2();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_3();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_4();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_10();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_11();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_12();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_13();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_2();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_3();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_4();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_5();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_6();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_7();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_8();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_9();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_begin();
bool is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_end();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_1();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_2();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_3();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_4();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_10();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_11();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_12();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_13();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_2();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_3();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_4();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_5();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_6();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_7();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_8();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_9();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_begin();
bool is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_4();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_6();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_end();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_1();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_2();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_3();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_4();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_1();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_2();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_3();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_4();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_5();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_6();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_7();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_begin();
bool is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_end();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_1();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_2();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_3();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_4();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_1();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_2();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_3();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_4();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_5();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_6();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_7();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_begin();
bool is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_end();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_1();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_2();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_3();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_4();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_1();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_2();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_3();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_4();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_5();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_6();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_7();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_begin();
bool is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_end();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_1();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_2();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_1();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_2();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_4();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_6();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_begin();
bool is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_end();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_1();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_2();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_3();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_4();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_10();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_11();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_12();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_13();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_2();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_3();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_4();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_5();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_6();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_7();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_8();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_9();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_begin();
bool is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_end();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_1();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_2();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_3();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_4();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_10();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_11();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_12();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_13();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_2();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_3();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_4();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_5();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_6();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_7();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_8();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_9();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_begin();
bool is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_end();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_1();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_2();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_3();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_4();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_10();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_11();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_12();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_13();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_2();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_3();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_4();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_5();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_6();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_7();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_8();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_9();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_begin();
bool is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_4();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_6();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_end();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_1();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_2();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_3();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_4();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_1();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_2();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_3();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_4();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_5();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_6();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_7();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_begin();
bool is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_end();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_1();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_2();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_3();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_4();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_1();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_2();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_3();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_4();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_5();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_6();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_7();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_begin();
bool is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_end();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_1();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_2();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_3();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_4();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_1();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_2();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_3();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_4();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_5();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_6();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_7();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_begin();
bool is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_end();
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
bool apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_rules_1();
bool apply_any_begin_begin_rules_3__1();
bool apply_any_begin_begin_rules_3__2();
bool apply_any_begin_begin_rules_3_turn_1();
bool apply_any_begin_begin_rules_3_turn_begin();
bool apply_any_begin_begin_rules_begin();
bool apply_any_rules_3_turn_5_rules_3_turn_5_end();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_14();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_15();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_16();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_17();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_4();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin();
bool apply_any_rules_5_turn_5_rules_5_turn_5_end();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_14();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_15();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_16();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_17();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_6();
};
class RgCache{
public:
inline void reset()
{
    currentMrId = 0;
}
uint currentMrId = 0;
};


}  // namespace reasoner
