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
using Board = Arr<Piece, 122>;
using Counters = Arr<RbgType1, 122>;
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
constexpr uint hx0y17 = 9;
constexpr uint hx0y18 = 10;
constexpr uint hx0y19 = 11;
constexpr uint hx0y2 = 12;
constexpr uint hx0y20 = 13;
constexpr uint hx0y3 = 14;
constexpr uint hx0y4 = 15;
constexpr uint hx0y5 = 16;
constexpr uint hx0y6 = 17;
constexpr uint hx0y7 = 18;
constexpr uint hx0y8 = 19;
constexpr uint hx0y9 = 20;
constexpr uint hx10y10 = 21;
constexpr uint hx1y1 = 22;
constexpr uint hx1y10 = 23;
constexpr uint hx1y11 = 24;
constexpr uint hx1y12 = 25;
constexpr uint hx1y13 = 26;
constexpr uint hx1y14 = 27;
constexpr uint hx1y15 = 28;
constexpr uint hx1y16 = 29;
constexpr uint hx1y17 = 30;
constexpr uint hx1y18 = 31;
constexpr uint hx1y19 = 32;
constexpr uint hx1y2 = 33;
constexpr uint hx1y3 = 34;
constexpr uint hx1y4 = 35;
constexpr uint hx1y5 = 36;
constexpr uint hx1y6 = 37;
constexpr uint hx1y7 = 38;
constexpr uint hx1y8 = 39;
constexpr uint hx1y9 = 40;
constexpr uint hx2y10 = 41;
constexpr uint hx2y11 = 42;
constexpr uint hx2y12 = 43;
constexpr uint hx2y13 = 44;
constexpr uint hx2y14 = 45;
constexpr uint hx2y15 = 46;
constexpr uint hx2y16 = 47;
constexpr uint hx2y17 = 48;
constexpr uint hx2y18 = 49;
constexpr uint hx2y2 = 50;
constexpr uint hx2y3 = 51;
constexpr uint hx2y4 = 52;
constexpr uint hx2y5 = 53;
constexpr uint hx2y6 = 54;
constexpr uint hx2y7 = 55;
constexpr uint hx2y8 = 56;
constexpr uint hx2y9 = 57;
constexpr uint hx3y10 = 58;
constexpr uint hx3y11 = 59;
constexpr uint hx3y12 = 60;
constexpr uint hx3y13 = 61;
constexpr uint hx3y14 = 62;
constexpr uint hx3y15 = 63;
constexpr uint hx3y16 = 64;
constexpr uint hx3y17 = 65;
constexpr uint hx3y3 = 66;
constexpr uint hx3y4 = 67;
constexpr uint hx3y5 = 68;
constexpr uint hx3y6 = 69;
constexpr uint hx3y7 = 70;
constexpr uint hx3y8 = 71;
constexpr uint hx3y9 = 72;
constexpr uint hx4y10 = 73;
constexpr uint hx4y11 = 74;
constexpr uint hx4y12 = 75;
constexpr uint hx4y13 = 76;
constexpr uint hx4y14 = 77;
constexpr uint hx4y15 = 78;
constexpr uint hx4y16 = 79;
constexpr uint hx4y4 = 80;
constexpr uint hx4y5 = 81;
constexpr uint hx4y6 = 82;
constexpr uint hx4y7 = 83;
constexpr uint hx4y8 = 84;
constexpr uint hx4y9 = 85;
constexpr uint hx5y10 = 86;
constexpr uint hx5y11 = 87;
constexpr uint hx5y12 = 88;
constexpr uint hx5y13 = 89;
constexpr uint hx5y14 = 90;
constexpr uint hx5y15 = 91;
constexpr uint hx5y5 = 92;
constexpr uint hx5y6 = 93;
constexpr uint hx5y7 = 94;
constexpr uint hx5y8 = 95;
constexpr uint hx5y9 = 96;
constexpr uint hx6y10 = 97;
constexpr uint hx6y11 = 98;
constexpr uint hx6y12 = 99;
constexpr uint hx6y13 = 100;
constexpr uint hx6y14 = 101;
constexpr uint hx6y6 = 102;
constexpr uint hx6y7 = 103;
constexpr uint hx6y8 = 104;
constexpr uint hx6y9 = 105;
constexpr uint hx7y10 = 106;
constexpr uint hx7y11 = 107;
constexpr uint hx7y12 = 108;
constexpr uint hx7y13 = 109;
constexpr uint hx7y7 = 110;
constexpr uint hx7y8 = 111;
constexpr uint hx7y9 = 112;
constexpr uint hx8y10 = 113;
constexpr uint hx8y11 = 114;
constexpr uint hx8y12 = 115;
constexpr uint hx8y8 = 116;
constexpr uint hx8y9 = 117;
constexpr uint hx9y10 = 118;
constexpr uint hx9y11 = 119;
constexpr uint hx9y9 = 120;
constexpr uint null = 121;
constexpr uint b = 0;
constexpr uint e = 1;
constexpr uint r = 2;
constexpr uint red = 2;
constexpr uint blue = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 122;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 122> direction_SE = Arr<CoordOrNull, 122>{hx1y1,hx1y2,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,hx0y17,hx0y18,hx0y19,hx0y20,hx1y3,null,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,hx1y10,null,hx2y2,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx1y19,null,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx2y18,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx3y17,null,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx4y16,null,hx5y5,hx5y6,hx5y7,hx5y8,hx5y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx5y15,null,hx6y6,hx6y7,hx6y8,hx6y9,hx6y10,hx6y11,hx6y12,hx6y13,hx6y14,null,hx7y7,hx7y8,hx7y9,hx7y10,hx7y11,hx7y12,hx7y13,null,hx8y8,hx8y9,hx8y10,hx8y11,hx8y12,null,hx9y9,hx9y10,hx9y11,null,hx10y10,null,};
constexpr Arr<CoordOrNull, 122> direction_SW = Arr<CoordOrNull, 122>{hx0y1,hx0y2,null,null,null,null,null,null,null,null,null,null,hx0y3,null,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,hx0y9,hx0y10,hx9y11,hx1y2,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,hx0y17,hx0y18,hx0y19,hx0y20,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx1y19,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx2y18,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx3y17,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx4y16,hx5y6,hx5y7,hx5y8,hx5y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx5y15,hx6y7,hx6y8,hx6y9,hx6y10,hx6y11,hx6y12,hx6y13,hx6y14,hx7y8,hx7y9,hx7y10,hx7y11,hx7y12,hx7y13,hx8y9,hx8y10,hx8y11,hx8y12,hx9y10,null,};
constexpr Arr<CoordOrNull, 122> direction_E = Arr<CoordOrNull, 122>{null,hx1y1,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx1y19,hx1y2,null,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,null,null,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx2y18,null,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx3y17,null,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx4y16,null,null,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx5y15,null,null,hx5y5,hx5y6,hx5y7,hx5y8,hx5y9,hx6y10,hx6y11,hx6y12,hx6y13,hx6y14,null,null,hx6y6,hx6y7,hx6y8,hx6y9,hx7y10,hx7y11,hx7y12,hx7y13,null,null,hx7y7,hx7y8,hx7y9,hx8y10,hx8y11,hx8y12,null,null,hx8y8,hx8y9,hx9y10,hx9y11,null,null,hx9y9,hx10y10,null,null,null,};
constexpr Arr<CoordOrNull, 122> direction_NE = Arr<CoordOrNull, 122>{null,hx0y0,hx0y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx0y1,hx1y19,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,null,null,hx1y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx2y18,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx3y17,null,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx3y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx4y16,null,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx5y15,null,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx5y9,hx6y10,hx6y11,hx6y12,hx6y13,hx6y14,null,hx5y5,hx5y6,hx5y7,hx5y8,hx6y9,hx7y10,hx7y11,hx7y12,hx7y13,null,hx6y6,hx6y7,hx6y8,hx7y9,hx8y10,hx8y11,hx8y12,null,hx7y7,hx7y8,hx8y9,hx9y10,hx9y11,null,hx8y8,hx9y9,hx10y10,null,null,};
constexpr Arr<CoordOrNull, 122> direction_NW = Arr<CoordOrNull, 122>{null,null,null,hx0y10,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,hx0y17,hx0y18,null,hx0y19,null,null,null,null,null,null,null,hx9y9,hx0y0,hx0y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx0y1,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,hx1y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx3y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,hx5y9,hx6y10,hx6y11,hx6y12,hx6y13,hx5y5,hx5y6,hx5y7,hx5y8,hx6y9,hx7y10,hx7y11,hx7y12,hx6y6,hx6y7,hx6y8,hx7y9,hx8y10,hx8y11,hx7y7,hx7y8,hx8y9,hx9y10,hx8y8,null,};
constexpr Arr<CoordOrNull, 122> direction_W = Arr<CoordOrNull, 122>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,hx9y10,hx0y1,hx0y10,hx0y11,hx0y12,hx0y13,hx0y14,hx0y15,hx0y16,hx0y17,hx0y18,hx0y19,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,hx0y9,hx1y10,hx1y11,hx1y12,hx1y13,hx1y14,hx1y15,hx1y16,hx1y17,hx1y18,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx1y9,hx2y10,hx2y11,hx2y12,hx2y13,hx2y14,hx2y15,hx2y16,hx2y17,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx2y9,hx3y10,hx3y11,hx3y12,hx3y13,hx3y14,hx3y15,hx3y16,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx3y9,hx4y10,hx4y11,hx4y12,hx4y13,hx4y14,hx4y15,hx4y5,hx4y6,hx4y7,hx4y8,hx4y9,hx5y10,hx5y11,hx5y12,hx5y13,hx5y14,hx5y6,hx5y7,hx5y8,hx5y9,hx6y10,hx6y11,hx6y12,hx6y13,hx6y7,hx6y8,hx6y9,hx7y10,hx7y11,hx7y12,hx7y8,hx7y9,hx8y10,hx8y11,hx8y9,null,};

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
Board board = Board{e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,null,};
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
std::bitset<122> state_cache_101;
std::bitset<122> state_cache_128;
bool state_cache_17;
bool state_cache_2;
std::bitset<122> state_cache_24;
std::bitset<122> state_cache_51;
};


}  // namespace reasoner
