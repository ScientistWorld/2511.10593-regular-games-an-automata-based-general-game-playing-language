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
using Board = Arr<Piece, 82>;
using Counters = Arr<RbgType1, 82>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint hx0y0 = 0;
constexpr uint hx0y1 = 1;
constexpr uint hx0y10 = 2;
constexpr uint hx0y11 = 3;
constexpr uint hx0y12 = 4;
constexpr uint hx0y13 = 5;
constexpr uint hx0y14 = 6;
constexpr uint hx0y15 = 7;
constexpr uint hx0y16 = 8;
constexpr uint hx0y2 = 9;
constexpr uint hx0y3 = 10;
constexpr uint hx0y4 = 11;
constexpr uint hx0y5 = 12;
constexpr uint hx0y6 = 13;
constexpr uint hx0y7 = 14;
constexpr uint hx0y8 = 15;
constexpr uint hx0y9 = 16;
constexpr uint hx1y1 = 17;
constexpr uint hx1y10 = 18;
constexpr uint hx1y11 = 19;
constexpr uint hx1y12 = 20;
constexpr uint hx1y13 = 21;
constexpr uint hx1y14 = 22;
constexpr uint hx1y15 = 23;
constexpr uint hx1y2 = 24;
constexpr uint hx1y3 = 25;
constexpr uint hx1y4 = 26;
constexpr uint hx1y5 = 27;
constexpr uint hx1y6 = 28;
constexpr uint hx1y7 = 29;
constexpr uint hx1y8 = 30;
constexpr uint hx1y9 = 31;
constexpr uint hx2y10 = 32;
constexpr uint hx2y11 = 33;
constexpr uint hx2y12 = 34;
constexpr uint hx2y13 = 35;
constexpr uint hx2y14 = 36;
constexpr uint hx2y2 = 37;
constexpr uint hx2y3 = 38;
constexpr uint hx2y4 = 39;
constexpr uint hx2y5 = 40;
constexpr uint hx2y6 = 41;
constexpr uint hx2y7 = 42;
constexpr uint hx2y8 = 43;
constexpr uint hx2y9 = 44;
constexpr uint hx3y10 = 45;
constexpr uint hx3y11 = 46;
constexpr uint hx3y12 = 47;
constexpr uint hx3y13 = 48;
constexpr uint hx3y3 = 49;
constexpr uint hx3y4 = 50;
constexpr uint hx3y5 = 51;
constexpr uint hx3y6 = 52;
constexpr uint hx3y7 = 53;
constexpr uint hx3y8 = 54;
constexpr uint hx3y9 = 55;
constexpr uint hx4y10 = 56;
constexpr uint hx4y11 = 57;
constexpr uint hx4y12 = 58;
constexpr uint hx4y4 = 59;
constexpr uint hx4y5 = 60;
constexpr uint hx4y6 = 61;
constexpr uint hx4y7 = 62;
constexpr uint hx4y8 = 63;
constexpr uint hx4y9 = 64;
constexpr uint hx5y10 = 65;
constexpr uint hx5y11 = 66;
constexpr uint hx5y5 = 67;
constexpr uint hx5y6 = 68;
constexpr uint hx5y7 = 69;
constexpr uint hx5y8 = 70;
constexpr uint hx5y9 = 71;
constexpr uint hx6y10 = 72;
constexpr uint hx6y6 = 73;
constexpr uint hx6y7 = 74;
constexpr uint hx6y8 = 75;
constexpr uint hx6y9 = 76;
constexpr uint hx7y7 = 77;
constexpr uint hx7y8 = 78;
constexpr uint hx7y9 = 79;
constexpr uint hx8y8 = 80;
constexpr uint null = 81;
constexpr uint b = 0;
constexpr uint e = 1;
constexpr uint r = 2;
constexpr uint red = 2;
constexpr uint blue = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 82;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 82> direction_SE = Arr<CoordOrNull, 82>{hx1y1,hx1y2,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,null,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx0y9,hx0y10,hx2y2,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,null,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx1y9,hx1y10,hx2y11,hx2y12,hx2y13,hx2y14,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx2y9,hx2y10,hx3y11,hx3y12,hx3y13,null,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx3y9,hx3y10,hx4y11,hx4y12,null,hx5y5,hx5y6,hx5y7,hx5y8,hx4y9,hx4y10,hx5y11,null,hx6y6,hx6y7,hx6y8,hx5y9,hx5y10,null,hx7y7,hx7y8,hx6y9,hx6y10,hx8y8,hx7y9,null,null,null,};
constexpr Arr<CoordOrNull, 82> direction_SW = Arr<CoordOrNull, 82>{hx0y1,hx0y2,null,null,null,null,null,null,null,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,null,null,hx1y2,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx0y9,hx0y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx1y9,hx1y10,hx2y11,hx2y12,hx2y13,hx2y14,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx2y9,hx2y10,hx3y11,hx3y12,hx3y13,hx4y5,hx4y6,hx4y7,hx4y8,hx3y9,hx3y10,hx4y11,hx4y12,hx5y6,hx5y7,hx5y8,hx4y9,hx4y10,hx5y11,hx6y7,hx6y8,hx5y9,hx5y10,hx7y8,hx6y9,hx6y10,hx7y9,null,};
constexpr Arr<CoordOrNull, 82> direction_E = Arr<CoordOrNull, 82>{null,hx1y1,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,null,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,null,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,null,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y13,null,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx4y10,hx4y11,hx4y12,null,null,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx5y10,hx5y11,null,null,hx5y5,hx5y6,hx5y7,hx5y8,hx5y9,hx6y10,null,null,hx6y6,hx6y7,hx6y8,hx6y9,null,null,hx7y7,hx7y8,hx7y9,null,hx8y8,null,null,null,};
constexpr Arr<CoordOrNull, 82> direction_NE = Arr<CoordOrNull, 82>{null,hx0y0,hx1y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx0y1,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx1y8,null,hx2y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx2y8,hx3y9,hx3y10,hx3y11,hx3y12,hx3y13,null,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx3y8,hx4y9,hx4y10,hx4y11,hx4y12,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx4y8,hx5y9,hx5y10,hx5y11,null,hx4y4,hx4y5,hx4y6,hx4y7,hx5y8,hx6y9,hx6y10,null,hx5y5,hx5y6,hx5y7,hx6y8,hx7y9,null,hx6y6,hx6y7,hx7y8,null,hx7y7,hx8y8,null,null,};
constexpr Arr<CoordOrNull, 82> direction_NW = Arr<CoordOrNull, 82>{null,null,hx0y9,hx0y10,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,null,null,null,null,null,null,null,hx0y8,hx0y0,hx1y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx0y1,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx1y8,hx2y9,hx2y10,hx2y11,hx2y12,hx2y13,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx2y8,hx3y9,hx3y10,hx3y11,hx3y12,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx3y8,hx4y9,hx4y10,hx4y11,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx4y8,hx5y9,hx5y10,hx4y4,hx4y5,hx4y6,hx4y7,hx5y8,hx6y9,hx5y5,hx5y6,hx5y7,hx6y8,hx6y6,hx6y7,hx7y8,hx7y7,null,};
constexpr Arr<CoordOrNull, 82> direction_W = Arr<CoordOrNull, 82>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,hx0y1,hx0y10,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,hx0y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx4y10,hx4y11,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx5y10,hx5y6,hx5y7,hx5y8,hx5y9,hx6y7,hx6y8,hx6y9,hx7y8,null,};

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
Board board = Board{e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,null,};
CoordOrNull coord = hx0y0;
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 56;

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
return currentState == 57;
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
bool is_legal_126_124_124([[maybe_unused]]RgCache& rgCache);
bool is_legal_126_124_126([[maybe_unused]]RgCache& rgCache);
bool is_legal_126_124_128([[maybe_unused]]RgCache& rgCache);
bool is_legal_158_159_158([[maybe_unused]]RgCache& rgCache);
bool is_legal_158_159_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_158_159_172([[maybe_unused]]RgCache& rgCache);
bool is_legal_158_159_173([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_175([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_176([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_20_177([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_20_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_20_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_178_47_178([[maybe_unused]]RgCache& rgCache);
bool is_legal_178_47_47([[maybe_unused]]RgCache& rgCache);
bool is_legal_178_47_51([[maybe_unused]]RgCache& rgCache);
bool is_legal_179_97_101([[maybe_unused]]RgCache& rgCache);
bool is_legal_179_97_179([[maybe_unused]]RgCache& rgCache);
bool is_legal_179_97_97([[maybe_unused]]RgCache& rgCache);
bool is_legal_4_10_4_4_10_10_4_10_10();
bool is_legal_4_10_4_4_10_10_4_10_4();
bool is_legal_4_10_4_4_10_10_4_10_7();
bool is_legal_81_87_81_81_87_87_81_87_81();
bool is_legal_81_87_81_81_87_87_81_87_84();
bool is_legal_81_87_81_81_87_87_81_87_87();
bool is_legal_86_5_86_86_5_5_86_5_5([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_89([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_82([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_9([[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_168([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_85([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_87([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_89([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_168([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_85([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_87([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_89([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_13([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_166([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_17([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_72([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_73([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_81([[maybe_unused]]RgCache& rgCache);
bool apply_any_13_13_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_149([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_150([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_89([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_90([[maybe_unused]]RgCache& rgCache);
bool apply_any_90_90_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache);
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
state_cache_101.reset();
state_cache_128.reset();
state_cache_17 = false;
state_cache_2 = false;
state_cache_24.reset();
state_cache_51.reset();
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
std::bitset<82> state_cache_101;
std::bitset<82> state_cache_128;
bool state_cache_17;
bool state_cache_2;
std::bitset<82> state_cache_24;
std::bitset<82> state_cache_51;
};


}  // namespace reasoner
