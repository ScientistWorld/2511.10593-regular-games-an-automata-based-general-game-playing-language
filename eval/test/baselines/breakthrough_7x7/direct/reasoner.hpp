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
using Position = uint;
using PositionOrNull = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint blackPawn = 0;
constexpr uint empty = 1;
constexpr uint whitePawn = 2;
constexpr uint border = 3;
constexpr uint black = 2;
constexpr uint white = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint V__0_0 = 0;
constexpr uint V__0_1 = 1;
constexpr uint V__0_2 = 2;
constexpr uint V__0_3 = 3;
constexpr uint V__0_4 = 4;
constexpr uint V__0_5 = 5;
constexpr uint V__0_6 = 6;
constexpr uint V__1_0 = 7;
constexpr uint V__1_1 = 8;
constexpr uint V__1_2 = 9;
constexpr uint V__1_3 = 10;
constexpr uint V__1_4 = 11;
constexpr uint V__1_5 = 12;
constexpr uint V__1_6 = 13;
constexpr uint V__2_0 = 14;
constexpr uint V__2_1 = 15;
constexpr uint V__2_2 = 16;
constexpr uint V__2_3 = 17;
constexpr uint V__2_4 = 18;
constexpr uint V__2_5 = 19;
constexpr uint V__2_6 = 20;
constexpr uint V__3_0 = 21;
constexpr uint V__3_1 = 22;
constexpr uint V__3_2 = 23;
constexpr uint V__3_3 = 24;
constexpr uint V__3_4 = 25;
constexpr uint V__3_5 = 26;
constexpr uint V__3_6 = 27;
constexpr uint V__4_0 = 28;
constexpr uint V__4_1 = 29;
constexpr uint V__4_2 = 30;
constexpr uint V__4_3 = 31;
constexpr uint V__4_4 = 32;
constexpr uint V__4_5 = 33;
constexpr uint V__4_6 = 34;
constexpr uint V__5_0 = 35;
constexpr uint V__5_1 = 36;
constexpr uint V__5_2 = 37;
constexpr uint V__5_3 = 38;
constexpr uint V__5_4 = 39;
constexpr uint V__5_5 = 40;
constexpr uint V__5_6 = 41;
constexpr uint V__6_0 = 42;
constexpr uint V__6_1 = 43;
constexpr uint V__6_2 = 44;
constexpr uint V__6_3 = 45;
constexpr uint V__6_4 = 46;
constexpr uint V__6_5 = 47;
constexpr uint V__6_6 = 48;
constexpr uint null = 49;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<PositionOrNull, 50> left = Arr<PositionOrNull, 50>{null,null,null,null,null,null,null,V__0_0,V__0_1,V__0_2,V__0_3,V__0_4,V__0_5,V__0_6,V__1_0,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__2_0,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__3_0,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__4_0,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__5_0,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,null,};
constexpr Arr<PositionOrNull, 50> right = Arr<PositionOrNull, 50>{V__1_0,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__2_0,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__3_0,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__4_0,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__5_0,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__6_0,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,null,null,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 50> up = Arr<PositionOrNull, 50>{V__0_0,V__0_0,V__0_1,V__0_2,V__0_3,V__0_4,V__0_5,V__1_0,V__1_0,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__2_0,V__2_0,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_0,V__3_0,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__4_0,V__4_0,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__5_0,V__5_0,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__6_0,V__6_0,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,null,};
constexpr Arr<PositionOrNull, 50> down = Arr<PositionOrNull, 50>{V__0_1,V__0_2,V__0_3,V__0_4,V__0_5,V__0_6,V__0_6,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_6,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_6,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_6,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_6,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_6,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_6,null,};
constexpr Arr<PositionOrNull, 50> upLeft = Arr<PositionOrNull, 50>{null,null,null,null,null,null,null,V__0_0,V__0_0,V__0_1,V__0_2,V__0_3,V__0_4,V__0_5,V__1_0,V__1_0,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__2_0,V__2_0,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_0,V__3_0,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__4_0,V__4_0,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__5_0,V__5_0,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,null,};
constexpr Arr<PositionOrNull, 50> upRight = Arr<PositionOrNull, 50>{V__1_0,V__1_0,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__2_0,V__2_0,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__3_0,V__3_0,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__4_0,V__4_0,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__5_0,V__5_0,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__6_0,V__6_0,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,null,null,null,null,null,null,null,null,};
constexpr Arr<PositionOrNull, 50> downLeft = Arr<PositionOrNull, 50>{null,null,null,null,null,null,null,V__0_1,V__0_2,V__0_3,V__0_4,V__0_5,V__0_6,V__0_6,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_6,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_6,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_6,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_6,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_6,null,};
constexpr Arr<PositionOrNull, 50> downRight = Arr<PositionOrNull, 50>{V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_6,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_6,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_6,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_6,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_6,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_6,null,null,null,null,null,null,null,null,};
constexpr Arr<Arr<PositionOrNull, 50>, 2> directionF = Arr<Arr<PositionOrNull, 50>, 2>{down,up,};
constexpr Arr<Arr<PositionOrNull, 50>, 2> directionFL = Arr<Arr<PositionOrNull, 50>, 2>{downLeft,upLeft,};
constexpr Arr<Arr<PositionOrNull, 50>, 2> directionFR = Arr<Arr<PositionOrNull, 50>, 2>{downRight,upRight,};
constexpr Arr<Piece, 2> piece = Arr<Piece, 2>{blackPawn,whitePawn,};
constexpr Arr<Player, 2> opponent = Arr<Player, 2>{white,black,};

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
Arr<Piece, 50> board = Arr<Piece, 50>{blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,blackPawn,blackPawn,empty,empty,empty,whitePawn,whitePawn,border,};
PositionOrNull pos = null;
Player turn_arg0_me = black;
Player existsOppPawn_arg0_me = black;
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
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_1();
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_2();
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_1();
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_2();
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_begin();
bool is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_end();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_1();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_2();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_1();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_2();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_begin();
bool is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_end();
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_rules_1();
bool apply_any_begin_begin_rules_3__1();
bool apply_any_begin_begin_rules_3_turn_1();
bool apply_any_begin_begin_rules_3_turn_begin();
bool apply_any_begin_begin_rules_begin();
bool apply_any_rules_3_turn_17_rules_3_turn_17_end();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_17();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_18();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_19();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_20();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_21();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_23();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_end();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_4();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_5__1();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_1();
bool apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_begin();
bool apply_any_rules_5_turn_17_rules_5_turn_17_end();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_1();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_3__1();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_1();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_begin();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_17();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_18();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_19();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_20();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_21();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_23();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_end();
bool apply_any_rules_5_turn_17_rules_5_turn_17_rules_6();
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
