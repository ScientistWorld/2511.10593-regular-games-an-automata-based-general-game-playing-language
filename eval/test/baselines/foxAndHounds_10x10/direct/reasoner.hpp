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
using Score = uint;
using Bool = uint;
using Position = uint;
using PositionOrNull = uint;
using PlayerOrSystem = uint;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint empty = 0;
constexpr uint fox = 1;
constexpr uint hound = 2;
constexpr uint border = 3;
constexpr uint foxPlayer = 2;
constexpr uint houndPlayer = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint V__0_0 = 0;
constexpr uint V__0_2 = 1;
constexpr uint V__0_4 = 2;
constexpr uint V__0_6 = 3;
constexpr uint V__0_8 = 4;
constexpr uint V__1_1 = 5;
constexpr uint V__1_3 = 6;
constexpr uint V__1_5 = 7;
constexpr uint V__1_7 = 8;
constexpr uint V__1_9 = 9;
constexpr uint V__2_0 = 10;
constexpr uint V__2_2 = 11;
constexpr uint V__2_4 = 12;
constexpr uint V__2_6 = 13;
constexpr uint V__2_8 = 14;
constexpr uint V__3_1 = 15;
constexpr uint V__3_3 = 16;
constexpr uint V__3_5 = 17;
constexpr uint V__3_7 = 18;
constexpr uint V__3_9 = 19;
constexpr uint V__4_0 = 20;
constexpr uint V__4_2 = 21;
constexpr uint V__4_4 = 22;
constexpr uint V__4_6 = 23;
constexpr uint V__4_8 = 24;
constexpr uint V__5_1 = 25;
constexpr uint V__5_3 = 26;
constexpr uint V__5_5 = 27;
constexpr uint V__5_7 = 28;
constexpr uint V__5_9 = 29;
constexpr uint V__6_0 = 30;
constexpr uint V__6_2 = 31;
constexpr uint V__6_4 = 32;
constexpr uint V__6_6 = 33;
constexpr uint V__6_8 = 34;
constexpr uint V__7_1 = 35;
constexpr uint V__7_3 = 36;
constexpr uint V__7_5 = 37;
constexpr uint V__7_7 = 38;
constexpr uint V__7_9 = 39;
constexpr uint V__8_0 = 40;
constexpr uint V__8_2 = 41;
constexpr uint V__8_4 = 42;
constexpr uint V__8_6 = 43;
constexpr uint V__8_8 = 44;
constexpr uint V__9_1 = 45;
constexpr uint V__9_3 = 46;
constexpr uint V__9_5 = 47;
constexpr uint V__9_7 = 48;
constexpr uint V__9_9 = 49;
constexpr uint null = 50;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
const std::vector<PositionOrNull> topLineiter = std::vector<PositionOrNull>{V__0_0,V__2_0,V__4_0,V__6_0,V__8_0,};
constexpr Arr<PositionOrNull, 51> upLeft = Arr<PositionOrNull, 51>{null,null,null,null,null,V__0_0,V__0_2,V__0_4,V__0_6,V__0_8,null,V__1_1,V__1_3,V__1_5,V__1_7,V__2_0,V__2_2,V__2_4,V__2_6,V__2_8,null,V__3_1,V__3_3,V__3_5,V__3_7,V__4_0,V__4_2,V__4_4,V__4_6,V__4_8,null,V__5_1,V__5_3,V__5_5,V__5_7,V__6_0,V__6_2,V__6_4,V__6_6,V__6_8,null,V__7_1,V__7_3,V__7_5,V__7_7,V__8_0,V__8_2,V__8_4,V__8_6,V__8_8,null,};
constexpr Arr<PositionOrNull, 51> upRight = Arr<PositionOrNull, 51>{null,V__1_1,V__1_3,V__1_5,V__1_7,V__2_0,V__2_2,V__2_4,V__2_6,V__2_8,null,V__3_1,V__3_3,V__3_5,V__3_7,V__4_0,V__4_2,V__4_4,V__4_6,V__4_8,null,V__5_1,V__5_3,V__5_5,V__5_7,V__6_0,V__6_2,V__6_4,V__6_6,V__6_8,null,V__7_1,V__7_3,V__7_5,V__7_7,V__8_0,V__8_2,V__8_4,V__8_6,V__8_8,null,V__9_1,V__9_3,V__9_5,V__9_7,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 51> downLeft = Arr<PositionOrNull, 51>{null,null,null,null,null,V__0_2,V__0_4,V__0_6,V__0_8,null,V__1_1,V__1_3,V__1_5,V__1_7,V__1_9,V__2_2,V__2_4,V__2_6,V__2_8,null,V__3_1,V__3_3,V__3_5,V__3_7,V__3_9,V__4_2,V__4_4,V__4_6,V__4_8,null,V__5_1,V__5_3,V__5_5,V__5_7,V__5_9,V__6_2,V__6_4,V__6_6,V__6_8,null,V__7_1,V__7_3,V__7_5,V__7_7,V__7_9,V__8_2,V__8_4,V__8_6,V__8_8,null,null,};
constexpr Arr<PositionOrNull, 51> downRight = Arr<PositionOrNull, 51>{V__1_1,V__1_3,V__1_5,V__1_7,V__1_9,V__2_2,V__2_4,V__2_6,V__2_8,null,V__3_1,V__3_3,V__3_5,V__3_7,V__3_9,V__4_2,V__4_4,V__4_6,V__4_8,null,V__5_1,V__5_3,V__5_5,V__5_7,V__5_9,V__6_2,V__6_4,V__6_6,V__6_8,null,V__7_1,V__7_3,V__7_5,V__7_7,V__7_9,V__8_2,V__8_4,V__8_6,V__8_8,null,V__9_1,V__9_3,V__9_5,V__9_7,V__9_9,null,null,null,null,null,null,};
constexpr Arr<Bool, 51> topLine = Arr<Bool, 51>{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,};
constexpr Arr<Bool, 51> bottomLine = Arr<Bool, 51>{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,};

using move_representation = std::array<uint,3>;
class GameState;

class RgCache;

struct Move
{
move_representation mr = {unusedTag,unusedTag,unusedTag};

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
Arr<Piece, 51> board = Arr<Piece, 51>{empty,empty,empty,empty,empty,empty,empty,empty,empty,hound,empty,empty,empty,empty,empty,empty,empty,empty,empty,hound,empty,empty,empty,empty,empty,empty,empty,empty,empty,hound,empty,empty,empty,empty,empty,empty,empty,empty,empty,hound,empty,empty,empty,empty,empty,empty,empty,empty,empty,hound,border,};
PositionOrNull pos = null;
Position foxPos = V__0_0;
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
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_begin();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_end();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_1();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_2();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_4();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_5();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_6();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_7();
bool is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_8();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_1();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_2();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_3();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_4();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_5();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_6();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_begin();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_call_1();
bool is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_end();
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_foxTurn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_houndTurn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_foxTurn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_houndTurn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_rules_1();
bool apply_any_begin_begin_rules_begin();
bool apply_any_foxTurn_19_foxTurn_19_end();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_19();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_20();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_21();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_22();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_23();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_24();
bool apply_any_foxTurn_19_foxTurn_19_foxTurn_end();
bool apply_any_foxTurn_19_foxTurn_19_houndTurn_1();
bool apply_any_foxTurn_19_foxTurn_19_houndTurn_2();
bool apply_any_foxTurn_19_foxTurn_19_houndTurn_4();
bool apply_any_foxTurn_19_foxTurn_19_houndTurn_5();
bool apply_any_foxTurn_19_foxTurn_19_houndTurn_begin();
bool apply_any_foxTurn_19_foxTurn_19_rules_10();
bool apply_any_houndTurn_17_houndTurn_17_end();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_1();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_2();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_4();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_5();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_6();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_7();
bool apply_any_houndTurn_17_houndTurn_17_foxTurn_begin();
bool apply_any_houndTurn_17_houndTurn_17_houndTurn_17();
bool apply_any_houndTurn_17_houndTurn_17_houndTurn_18();
bool apply_any_houndTurn_17_houndTurn_17_houndTurn_end();
bool apply_any_houndTurn_17_houndTurn_17_rules_11();
bool apply_any_houndTurn_17_houndTurn_17_rules_8();
bool apply_any_rules_5_rules_5_end();
bool apply_any_rules_5_rules_5_foxTurn_1();
bool apply_any_rules_5_rules_5_foxTurn_2();
bool apply_any_rules_5_rules_5_foxTurn_4();
bool apply_any_rules_5_rules_5_foxTurn_5();
bool apply_any_rules_5_rules_5_foxTurn_6();
bool apply_any_rules_5_rules_5_foxTurn_7();
bool apply_any_rules_5_rules_5_foxTurn_begin();
bool apply_any_rules_5_rules_5_rules_5();
bool apply_any_rules_5_rules_5_rules_6();
bool apply_any_rules_5_rules_5_rules_7();
bool apply_any_rules_5_rules_5_rules_8();
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
