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
using Bool = uint;
using PlayerOrSystem = uint;
using Board = Arr<Piece, 65>;
using Counters = Arr<RbgType1, 3>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y0 = 0;
constexpr uint rx0y1 = 1;
constexpr uint rx0y2 = 2;
constexpr uint rx0y3 = 3;
constexpr uint rx0y4 = 4;
constexpr uint rx0y5 = 5;
constexpr uint rx0y6 = 6;
constexpr uint rx0y7 = 7;
constexpr uint rx1y0 = 8;
constexpr uint rx1y1 = 9;
constexpr uint rx1y2 = 10;
constexpr uint rx1y3 = 11;
constexpr uint rx1y4 = 12;
constexpr uint rx1y5 = 13;
constexpr uint rx1y6 = 14;
constexpr uint rx1y7 = 15;
constexpr uint rx2y0 = 16;
constexpr uint rx2y1 = 17;
constexpr uint rx2y2 = 18;
constexpr uint rx2y3 = 19;
constexpr uint rx2y4 = 20;
constexpr uint rx2y5 = 21;
constexpr uint rx2y6 = 22;
constexpr uint rx2y7 = 23;
constexpr uint rx3y0 = 24;
constexpr uint rx3y1 = 25;
constexpr uint rx3y2 = 26;
constexpr uint rx3y3 = 27;
constexpr uint rx3y4 = 28;
constexpr uint rx3y5 = 29;
constexpr uint rx3y6 = 30;
constexpr uint rx3y7 = 31;
constexpr uint rx4y0 = 32;
constexpr uint rx4y1 = 33;
constexpr uint rx4y2 = 34;
constexpr uint rx4y3 = 35;
constexpr uint rx4y4 = 36;
constexpr uint rx4y5 = 37;
constexpr uint rx4y6 = 38;
constexpr uint rx4y7 = 39;
constexpr uint rx5y0 = 40;
constexpr uint rx5y1 = 41;
constexpr uint rx5y2 = 42;
constexpr uint rx5y3 = 43;
constexpr uint rx5y4 = 44;
constexpr uint rx5y5 = 45;
constexpr uint rx5y6 = 46;
constexpr uint rx5y7 = 47;
constexpr uint rx6y0 = 48;
constexpr uint rx6y1 = 49;
constexpr uint rx6y2 = 50;
constexpr uint rx6y3 = 51;
constexpr uint rx6y4 = 52;
constexpr uint rx6y5 = 53;
constexpr uint rx6y6 = 54;
constexpr uint rx6y7 = 55;
constexpr uint rx7y0 = 56;
constexpr uint rx7y1 = 57;
constexpr uint rx7y2 = 58;
constexpr uint rx7y3 = 59;
constexpr uint rx7y4 = 60;
constexpr uint rx7y5 = 61;
constexpr uint rx7y6 = 62;
constexpr uint rx7y7 = 63;
constexpr uint null = 64;
constexpr uint b = 0;
constexpr uint e = 1;
constexpr uint w = 2;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 65;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 64> direction_down = Arr<CoordOrNull, 64>{rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,null,};
constexpr Arr<CoordOrNull, 64> direction_right = Arr<CoordOrNull, 64>{rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx7y0,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 64> direction_left = Arr<CoordOrNull, 64>{null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,};
constexpr Arr<CoordOrNull, 64> direction_up = Arr<CoordOrNull, 64>{null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,null,rx7y0,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,};
constexpr Arr<CoordOrNull, 64> __gen_direction_left_direction_up = Arr<CoordOrNull, 64>{null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,};
constexpr Arr<CoordOrNull, 64> __gen_direction_right_direction_up = Arr<CoordOrNull, 64>{null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,null,rx7y0,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 64> __gen_direction_left_direction_down = Arr<CoordOrNull, 64>{null,null,null,null,null,null,null,null,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,};
constexpr Arr<CoordOrNull, 64> __gen_direction_right_direction_down = Arr<CoordOrNull, 64>{rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,null,null,null,null,null,null,null,null,null,};

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
Board board = Board{b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,e,};
CoordOrNull coord = rx0y0;
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 55;

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
return currentState == 56;
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
bool is_legal_4_27_4_4_27_27_4_27_12();
bool is_legal_4_27_4_4_27_27_4_27_13();
bool is_legal_4_27_4_4_27_27_4_27_14();
bool is_legal_4_27_4_4_27_27_4_27_16();
bool is_legal_4_27_4_4_27_27_4_27_19();
bool is_legal_4_27_4_4_27_27_4_27_22();
bool is_legal_4_27_4_4_27_27_4_27_27();
bool is_legal_4_27_4_4_27_27_4_27_4();
bool is_legal_4_27_4_4_27_27_4_27_7();
bool is_legal_53_76_53_53_76_76_53_76_53();
bool is_legal_53_76_53_53_76_76_53_76_56();
bool is_legal_53_76_53_53_76_76_53_76_61();
bool is_legal_53_76_53_53_76_76_53_76_62();
bool is_legal_53_76_53_53_76_76_53_76_63();
bool is_legal_53_76_53_53_76_76_53_76_65();
bool is_legal_53_76_53_53_76_76_53_76_68();
bool is_legal_53_76_53_53_76_76_53_76_71();
bool is_legal_53_76_53_53_76_76_53_76_76();
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_100([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_106([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_110([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_71([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_100([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_106([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_110([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_71([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_26_26_100();
bool apply_any_26_26_110();
bool apply_any_26_26_26();
bool apply_any_26_26_30();
bool apply_any_26_26_33();
bool apply_any_26_26_35();
bool apply_any_26_26_43();
bool apply_any_26_26_53();
bool apply_any_26_26_end();
bool apply_any_75_75_100();
bool apply_any_75_75_106();
bool apply_any_75_75_2();
bool apply_any_75_75_4();
bool apply_any_75_75_5();
bool apply_any_75_75_75();
bool apply_any_75_75_79();
bool apply_any_75_75_82();
bool apply_any_75_75_92();
bool apply_any_75_75_end();
bool apply_any_begin_begin_100();
bool apply_any_begin_begin_106();
bool apply_any_begin_begin_2();
bool apply_any_begin_begin_4();
bool apply_any_begin_begin_5();
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_end();
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
state_cache_17.reset();
state_cache_22.reset();
state_cache_66.reset();
state_cache_71.reset();
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
std::bitset<65> state_cache_17;
std::bitset<65> state_cache_22;
std::bitset<65> state_cache_66;
std::bitset<65> state_cache_71;
};


}  // namespace reasoner
