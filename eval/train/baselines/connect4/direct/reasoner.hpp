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
using TopPosition = uint;
using Score = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint empty = 0;
constexpr uint border = 1;
constexpr uint red = 2;
constexpr uint yellow = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint V__1_6 = 0;
constexpr uint V__2_6 = 1;
constexpr uint V__3_6 = 2;
constexpr uint V__4_6 = 3;
constexpr uint V__5_6 = 4;
constexpr uint V__6_6 = 5;
constexpr uint V__7_6 = 6;
constexpr uint V__1_1 = 7;
constexpr uint V__1_2 = 8;
constexpr uint V__1_3 = 9;
constexpr uint V__1_4 = 10;
constexpr uint V__1_5 = 11;
constexpr uint V__2_1 = 12;
constexpr uint V__2_2 = 13;
constexpr uint V__2_3 = 14;
constexpr uint V__2_4 = 15;
constexpr uint V__2_5 = 16;
constexpr uint V__3_1 = 17;
constexpr uint V__3_2 = 18;
constexpr uint V__3_3 = 19;
constexpr uint V__3_4 = 20;
constexpr uint V__3_5 = 21;
constexpr uint V__4_1 = 22;
constexpr uint V__4_2 = 23;
constexpr uint V__4_3 = 24;
constexpr uint V__4_4 = 25;
constexpr uint V__4_5 = 26;
constexpr uint V__5_1 = 27;
constexpr uint V__5_2 = 28;
constexpr uint V__5_3 = 29;
constexpr uint V__5_4 = 30;
constexpr uint V__5_5 = 31;
constexpr uint V__6_1 = 32;
constexpr uint V__6_2 = 33;
constexpr uint V__6_3 = 34;
constexpr uint V__6_4 = 35;
constexpr uint V__6_5 = 36;
constexpr uint V__7_1 = 37;
constexpr uint V__7_2 = 38;
constexpr uint V__7_3 = 39;
constexpr uint V__7_4 = 40;
constexpr uint V__7_5 = 41;
constexpr uint null = 42;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<Position, 43> up = Arr<Position, 43>{null,null,null,null,null,null,null,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,null,};
constexpr Arr<Position, 43> right = Arr<Position, 43>{V__2_6,V__3_6,V__4_6,V__5_6,V__6_6,V__7_6,null,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,null,null,null,null,null,null,};
constexpr Arr<Position, 43> down = Arr<Position, 43>{V__1_5,V__2_5,V__3_5,V__4_5,V__5_5,V__6_5,V__7_5,null,V__1_1,V__1_2,V__1_3,V__1_4,null,V__2_1,V__2_2,V__2_3,V__2_4,null,V__3_1,V__3_2,V__3_3,V__3_4,null,V__4_1,V__4_2,V__4_3,V__4_4,null,V__5_1,V__5_2,V__5_3,V__5_4,null,V__6_1,V__6_2,V__6_3,V__6_4,null,V__7_1,V__7_2,V__7_3,V__7_4,null,};
constexpr Arr<Position, 43> left = Arr<Position, 43>{null,V__1_6,V__2_6,V__3_6,V__4_6,V__5_6,V__6_6,null,null,null,null,null,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,null,};
constexpr Arr<Player, 2> opponent = Arr<Player, 2>{yellow,red,};

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
Arr<Piece, 43> board = Arr<Piece, 43>{empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,border,};
Position pos = V__1_1;
Player me = red;
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
bool is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_begin();
bool is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_call_1();
bool is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_end();
bool is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_1();
bool is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_2();
bool is_legal_win_call_1_win_end_turn_9_win_1();
bool is_legal_win_call_1_win_end_turn_9_win_10();
bool is_legal_win_call_1_win_end_turn_9_win_11();
bool is_legal_win_call_1_win_end_turn_9_win_12();
bool is_legal_win_call_1_win_end_turn_9_win_13();
bool is_legal_win_call_1_win_end_turn_9_win_14();
bool is_legal_win_call_1_win_end_turn_9_win_15();
bool is_legal_win_call_1_win_end_turn_9_win_16();
bool is_legal_win_call_1_win_end_turn_9_win_17();
bool is_legal_win_call_1_win_end_turn_9_win_18();
bool is_legal_win_call_1_win_end_turn_9_win_19();
bool is_legal_win_call_1_win_end_turn_9_win_2();
bool is_legal_win_call_1_win_end_turn_9_win_20();
bool is_legal_win_call_1_win_end_turn_9_win_21();
bool is_legal_win_call_1_win_end_turn_9_win_22();
bool is_legal_win_call_1_win_end_turn_9_win_23();
bool is_legal_win_call_1_win_end_turn_9_win_24();
bool is_legal_win_call_1_win_end_turn_9_win_25();
bool is_legal_win_call_1_win_end_turn_9_win_26();
bool is_legal_win_call_1_win_end_turn_9_win_27();
bool is_legal_win_call_1_win_end_turn_9_win_28();
bool is_legal_win_call_1_win_end_turn_9_win_29();
bool is_legal_win_call_1_win_end_turn_9_win_3();
bool is_legal_win_call_1_win_end_turn_9_win_30();
bool is_legal_win_call_1_win_end_turn_9_win_31();
bool is_legal_win_call_1_win_end_turn_9_win_32();
bool is_legal_win_call_1_win_end_turn_9_win_33();
bool is_legal_win_call_1_win_end_turn_9_win_34();
bool is_legal_win_call_1_win_end_turn_9_win_4();
bool is_legal_win_call_1_win_end_turn_9_win_5();
bool is_legal_win_call_1_win_end_turn_9_win_6();
bool is_legal_win_call_1_win_end_turn_9_win_7();
bool is_legal_win_call_1_win_end_turn_9_win_8();
bool is_legal_win_call_1_win_end_turn_9_win_9();
bool is_legal_win_call_1_win_end_win_begin();
bool is_legal_win_call_1_win_end_win_call_1();
bool is_legal_win_call_1_win_end_win_end();
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_goDown_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_goDown_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_rules_1();
bool apply_any_begin_begin_rules_begin();
bool apply_any_begin_begin_turn_1();
bool apply_any_begin_begin_turn_begin();
bool apply_any_turn_5_turn_5_end();
bool apply_any_turn_5_turn_5_goDown_1();
bool apply_any_turn_5_turn_5_goDown_10();
bool apply_any_turn_5_turn_5_goDown_11();
bool apply_any_turn_5_turn_5_goDown_12();
bool apply_any_turn_5_turn_5_goDown_13();
bool apply_any_turn_5_turn_5_goDown_14();
bool apply_any_turn_5_turn_5_goDown_15();
bool apply_any_turn_5_turn_5_goDown_16();
bool apply_any_turn_5_turn_5_goDown_17();
bool apply_any_turn_5_turn_5_goDown_18();
bool apply_any_turn_5_turn_5_goDown_19();
bool apply_any_turn_5_turn_5_goDown_2();
bool apply_any_turn_5_turn_5_goDown_20();
bool apply_any_turn_5_turn_5_goDown_21();
bool apply_any_turn_5_turn_5_goDown_3();
bool apply_any_turn_5_turn_5_goDown_4();
bool apply_any_turn_5_turn_5_goDown_5();
bool apply_any_turn_5_turn_5_goDown_6();
bool apply_any_turn_5_turn_5_goDown_7();
bool apply_any_turn_5_turn_5_goDown_8();
bool apply_any_turn_5_turn_5_goDown_9();
bool apply_any_turn_5_turn_5_goDown_begin();
bool apply_any_turn_5_turn_5_goDown_end();
bool apply_any_turn_5_turn_5_rules_1();
bool apply_any_turn_5_turn_5_rules_3();
bool apply_any_turn_5_turn_5_turn_1();
bool apply_any_turn_5_turn_5_turn_10();
bool apply_any_turn_5_turn_5_turn_11();
bool apply_any_turn_5_turn_5_turn_12();
bool apply_any_turn_5_turn_5_turn_13();
bool apply_any_turn_5_turn_5_turn_14();
bool apply_any_turn_5_turn_5_turn_16();
bool apply_any_turn_5_turn_5_turn_5();
bool apply_any_turn_5_turn_5_turn_6();
bool apply_any_turn_5_turn_5_turn_7();
bool apply_any_turn_5_turn_5_turn_8();
bool apply_any_turn_5_turn_5_turn_begin();
bool apply_any_turn_5_turn_5_turn_end();
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
