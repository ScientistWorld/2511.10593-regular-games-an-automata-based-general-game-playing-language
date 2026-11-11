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
using Board = Arr<Piece, 62>;
using Counters = Arr<RbgType1, 62>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint hx0y0 = 0;
constexpr uint hx0y1 = 1;
constexpr uint hx0y2 = 2;
constexpr uint hx0y3 = 3;
constexpr uint hx0y4 = 4;
constexpr uint hx0y5 = 5;
constexpr uint hx0y6 = 6;
constexpr uint hx0y7 = 7;
constexpr uint hx0y8 = 8;
constexpr uint hx1y0 = 9;
constexpr uint hx1y1 = 10;
constexpr uint hx1y2 = 11;
constexpr uint hx1y3 = 12;
constexpr uint hx1y4 = 13;
constexpr uint hx1y5 = 14;
constexpr uint hx1y6 = 15;
constexpr uint hx1y7 = 16;
constexpr uint hx1y8 = 17;
constexpr uint hx2y0 = 18;
constexpr uint hx2y1 = 19;
constexpr uint hx2y2 = 20;
constexpr uint hx2y3 = 21;
constexpr uint hx2y4 = 22;
constexpr uint hx2y5 = 23;
constexpr uint hx2y6 = 24;
constexpr uint hx2y7 = 25;
constexpr uint hx2y8 = 26;
constexpr uint hx3y0 = 27;
constexpr uint hx3y1 = 28;
constexpr uint hx3y2 = 29;
constexpr uint hx3y3 = 30;
constexpr uint hx3y4 = 31;
constexpr uint hx3y5 = 32;
constexpr uint hx3y6 = 33;
constexpr uint hx3y7 = 34;
constexpr uint hx3y8 = 35;
constexpr uint hx4y0 = 36;
constexpr uint hx4y1 = 37;
constexpr uint hx4y2 = 38;
constexpr uint hx4y3 = 39;
constexpr uint hx4y4 = 40;
constexpr uint hx4y5 = 41;
constexpr uint hx4y6 = 42;
constexpr uint hx4y7 = 43;
constexpr uint hx4y8 = 44;
constexpr uint hx5y1 = 45;
constexpr uint hx5y2 = 46;
constexpr uint hx5y3 = 47;
constexpr uint hx5y4 = 48;
constexpr uint hx5y5 = 49;
constexpr uint hx5y6 = 50;
constexpr uint hx5y7 = 51;
constexpr uint hx6y2 = 52;
constexpr uint hx6y3 = 53;
constexpr uint hx6y4 = 54;
constexpr uint hx6y5 = 55;
constexpr uint hx6y6 = 56;
constexpr uint hx7y3 = 57;
constexpr uint hx7y4 = 58;
constexpr uint hx7y5 = 59;
constexpr uint hx8y4 = 60;
constexpr uint null = 61;
constexpr uint b = 0;
constexpr uint e = 1;
constexpr uint w = 2;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 62;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 62> direction_E = Arr<CoordOrNull, 62>{hx1y0,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx2y0,hx2y1,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx3y0,hx3y1,hx3y2,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y0,hx4y1,hx4y2,hx4y3,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,null,hx5y1,hx5y2,hx5y3,hx5y4,hx5y5,hx5y6,hx5y7,null,null,hx6y2,hx6y3,hx6y4,hx6y5,hx6y6,null,null,hx7y3,hx7y4,hx7y5,null,null,hx8y4,null,null,null,};
constexpr Arr<CoordOrNull, 62> direction_SE = Arr<CoordOrNull, 62>{hx1y1,hx1y2,hx1y3,hx1y4,hx0y5,hx0y6,hx0y7,hx0y8,null,hx2y1,hx2y2,hx2y3,hx2y4,hx1y5,hx1y6,hx1y7,hx1y8,null,hx3y1,hx3y2,hx3y3,hx3y4,hx2y5,hx2y6,hx2y7,hx2y8,null,hx4y1,hx4y2,hx4y3,hx4y4,hx3y5,hx3y6,hx3y7,hx3y8,null,hx5y1,hx5y2,hx5y3,hx5y4,hx4y5,hx4y6,hx4y7,hx4y8,null,hx6y2,hx6y3,hx6y4,hx5y5,hx5y6,hx5y7,null,hx7y3,hx7y4,hx6y5,hx6y6,null,hx8y4,hx7y5,null,null,null,};
constexpr Arr<CoordOrNull, 62> direction_SW = Arr<CoordOrNull, 62>{hx0y1,hx0y2,hx0y3,hx0y4,null,null,null,null,null,hx1y1,hx1y2,hx1y3,hx1y4,hx0y5,hx0y6,hx0y7,hx0y8,null,hx2y1,hx2y2,hx2y3,hx2y4,hx1y5,hx1y6,hx1y7,hx1y8,null,hx3y1,hx3y2,hx3y3,hx3y4,hx2y5,hx2y6,hx2y7,hx2y8,null,hx4y1,hx4y2,hx4y3,hx4y4,hx3y5,hx3y6,hx3y7,hx3y8,null,hx5y2,hx5y3,hx5y4,hx4y5,hx4y6,hx4y7,hx4y8,hx6y3,hx6y4,hx5y5,hx5y6,hx5y7,hx7y4,hx6y5,hx6y6,hx7y5,null,};
constexpr Arr<CoordOrNull, 62> direction_W = Arr<CoordOrNull, 62>{null,null,null,null,null,null,null,null,null,hx0y0,hx0y1,hx0y2,hx0y3,hx0y4,hx0y5,hx0y6,hx0y7,hx0y8,hx1y0,hx1y1,hx1y2,hx1y3,hx1y4,hx1y5,hx1y6,hx1y7,hx1y8,hx2y0,hx2y1,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx3y0,hx3y1,hx3y2,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y1,hx4y2,hx4y3,hx4y4,hx4y5,hx4y6,hx4y7,hx5y2,hx5y3,hx5y4,hx5y5,hx5y6,hx6y3,hx6y4,hx6y5,hx7y4,null,};
constexpr Arr<CoordOrNull, 62> direction_NE = Arr<CoordOrNull, 62>{null,hx0y0,hx0y1,hx0y2,hx0y3,hx1y4,hx1y5,hx1y6,hx1y7,null,hx1y0,hx1y1,hx1y2,hx1y3,hx2y4,hx2y5,hx2y6,hx2y7,null,hx2y0,hx2y1,hx2y2,hx2y3,hx3y4,hx3y5,hx3y6,hx3y7,null,hx3y0,hx3y1,hx3y2,hx3y3,hx4y4,hx4y5,hx4y6,hx4y7,null,hx4y0,hx4y1,hx4y2,hx4y3,hx5y4,hx5y5,hx5y6,hx5y7,null,hx5y1,hx5y2,hx5y3,hx6y4,hx6y5,hx6y6,null,hx6y2,hx6y3,hx7y4,hx7y5,null,hx7y3,hx8y4,null,null,};
constexpr Arr<CoordOrNull, 62> direction_NW = Arr<CoordOrNull, 62>{null,null,null,null,null,hx0y4,hx0y5,hx0y6,hx0y7,null,hx0y0,hx0y1,hx0y2,hx0y3,hx1y4,hx1y5,hx1y6,hx1y7,null,hx1y0,hx1y1,hx1y2,hx1y3,hx2y4,hx2y5,hx2y6,hx2y7,null,hx2y0,hx2y1,hx2y2,hx2y3,hx3y4,hx3y5,hx3y6,hx3y7,null,hx3y0,hx3y1,hx3y2,hx3y3,hx4y4,hx4y5,hx4y6,hx4y7,hx4y0,hx4y1,hx4y2,hx4y3,hx5y4,hx5y5,hx5y6,hx5y1,hx5y2,hx5y3,hx6y4,hx6y5,hx6y2,hx6y3,hx7y4,hx7y3,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_SE_direction_SE = Arr<CoordOrNull, 62>{hx2y2,hx2y3,hx2y4,hx1y5,hx0y6,hx0y7,hx0y8,null,null,hx3y2,hx3y3,hx3y4,hx2y5,hx1y6,hx1y7,hx1y8,null,null,hx4y2,hx4y3,hx4y4,hx3y5,hx2y6,hx2y7,hx2y8,null,null,hx5y2,hx5y3,hx5y4,hx4y5,hx3y6,hx3y7,hx3y8,null,null,hx6y2,hx6y3,hx6y4,hx5y5,hx4y6,hx4y7,hx4y8,null,null,hx7y3,hx7y4,hx6y5,hx5y6,hx5y7,null,null,hx8y4,hx7y5,hx6y6,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_SE___gen_direction_SE_direction_SE = Arr<CoordOrNull, 62>{hx3y3,hx3y4,hx2y5,hx1y6,hx0y7,hx0y8,null,null,null,hx4y3,hx4y4,hx3y5,hx2y6,hx1y7,hx1y8,null,null,null,hx5y3,hx5y4,hx4y5,hx3y6,hx2y7,hx2y8,null,null,null,hx6y3,hx6y4,hx5y5,hx4y6,hx3y7,hx3y8,null,null,null,hx7y3,hx7y4,hx6y5,hx5y6,hx4y7,hx4y8,null,null,null,hx8y4,hx7y5,hx6y6,hx5y7,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_E_direction_E = Arr<CoordOrNull, 62>{hx2y0,hx2y1,hx2y2,hx2y3,hx2y4,hx2y5,hx2y6,hx2y7,hx2y8,hx3y0,hx3y1,hx3y2,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y0,hx4y1,hx4y2,hx4y3,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,null,hx5y1,hx5y2,hx5y3,hx5y4,hx5y5,hx5y6,hx5y7,null,null,null,hx6y2,hx6y3,hx6y4,hx6y5,hx6y6,null,null,null,null,hx7y3,hx7y4,hx7y5,null,null,null,null,hx8y4,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_E___gen_direction_E_direction_E = Arr<CoordOrNull, 62>{hx3y0,hx3y1,hx3y2,hx3y3,hx3y4,hx3y5,hx3y6,hx3y7,hx3y8,hx4y0,hx4y1,hx4y2,hx4y3,hx4y4,hx4y5,hx4y6,hx4y7,hx4y8,null,hx5y1,hx5y2,hx5y3,hx5y4,hx5y5,hx5y6,hx5y7,null,null,null,hx6y2,hx6y3,hx6y4,hx6y5,hx6y6,null,null,null,null,null,hx7y3,hx7y4,hx7y5,null,null,null,null,null,null,hx8y4,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_SW_direction_SW = Arr<CoordOrNull, 62>{hx0y2,hx0y3,hx0y4,null,null,null,null,null,null,hx1y2,hx1y3,hx1y4,hx0y5,null,null,null,null,null,hx2y2,hx2y3,hx2y4,hx1y5,hx0y6,hx0y7,hx0y8,null,null,hx3y2,hx3y3,hx3y4,hx2y5,hx1y6,hx1y7,hx1y8,null,null,hx4y2,hx4y3,hx4y4,hx3y5,hx2y6,hx2y7,hx2y8,null,null,hx5y3,hx5y4,hx4y5,hx3y6,hx3y7,hx3y8,null,hx6y4,hx5y5,hx4y6,hx4y7,hx4y8,hx6y5,hx5y6,hx5y7,hx6y6,null,};
constexpr Arr<CoordOrNull, 62> __gen_direction_SW___gen_direction_SW_direction_SW = Arr<CoordOrNull, 62>{hx0y3,hx0y4,null,null,null,null,null,null,null,hx1y3,hx1y4,hx0y5,null,null,null,null,null,null,hx2y3,hx2y4,hx1y5,hx0y6,null,null,null,null,null,hx3y3,hx3y4,hx2y5,hx1y6,hx0y7,hx0y8,null,null,null,hx4y3,hx4y4,hx3y5,hx2y6,hx1y7,hx1y8,null,null,null,hx5y4,hx4y5,hx3y6,hx2y7,hx2y8,null,null,hx5y5,hx4y6,hx3y7,hx3y8,null,hx5y6,hx4y7,hx4y8,hx5y7,null,};

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
Board board = Board{e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,null,};
CoordOrNull coord = hx0y0;
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 99;

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
return currentState == 100;
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
bool is_legal_10_16_10_10_16_16_10_16_10();
bool is_legal_10_16_10_10_16_16_10_16_13();
bool is_legal_10_16_10_10_16_16_10_16_16();
bool is_legal_151_157_151_151_157_157_151_157_151();
bool is_legal_151_157_151_151_157_157_151_157_154();
bool is_legal_151_157_151_151_157_157_151_157_157();
bool is_legal_166_167_166([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_167([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_169([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_173([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_177([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_181([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_184([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_188([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_192([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_196([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_199([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_203([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_207([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_211([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_216([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_217([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_219([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_223([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_227([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_231([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_235([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_238([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_242([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_246([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_250([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_254([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_257([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_261([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_265([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_269([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_273([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_26([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_28([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_32([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_36([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_40([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_43([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_47([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_51([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_55([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_58([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_62([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_66([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_70([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_100([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_105([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_109([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_113([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_116([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_120([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_124([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_128([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_132([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_75([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_76([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_78([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_82([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_90([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_94([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_97([[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_135([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_159([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_213([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_214([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_215([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_276([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_281([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_283([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_296([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_300([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_135([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_159([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_213([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_214([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_215([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_276([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_281([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_283([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_296([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_300([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_159([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_160([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_213([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_214([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_215([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_276([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_281([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_283([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_296([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_160_160_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_135([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_140([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_142([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_152([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_18([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_214([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_23([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_300([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_72([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_74([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_214([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_296([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_8([[maybe_unused]]RgCache& rgCache);
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
state_cache_100.reset();
state_cache_105.reset();
state_cache_116.reset();
state_cache_120.reset();
state_cache_169.reset();
state_cache_173.reset();
state_cache_184.reset();
state_cache_188.reset();
state_cache_199.reset();
state_cache_203.reset();
state_cache_219.reset();
state_cache_223.reset();
state_cache_238.reset();
state_cache_242.reset();
state_cache_257.reset();
state_cache_261.reset();
state_cache_28.reset();
state_cache_32.reset();
state_cache_43.reset();
state_cache_47.reset();
state_cache_58.reset();
state_cache_62.reset();
state_cache_78.reset();
state_cache_82.reset();
state_cache_97.reset();
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
std::bitset<62> state_cache_100;
std::bitset<62> state_cache_105;
std::bitset<62> state_cache_116;
std::bitset<62> state_cache_120;
std::bitset<62> state_cache_169;
std::bitset<62> state_cache_173;
std::bitset<62> state_cache_184;
std::bitset<62> state_cache_188;
std::bitset<62> state_cache_199;
std::bitset<62> state_cache_203;
std::bitset<62> state_cache_219;
std::bitset<62> state_cache_223;
std::bitset<62> state_cache_238;
std::bitset<62> state_cache_242;
std::bitset<62> state_cache_257;
std::bitset<62> state_cache_261;
std::bitset<62> state_cache_28;
std::bitset<62> state_cache_32;
std::bitset<62> state_cache_43;
std::bitset<62> state_cache_47;
std::bitset<62> state_cache_58;
std::bitset<62> state_cache_62;
std::bitset<62> state_cache_78;
std::bitset<62> state_cache_82;
std::bitset<62> state_cache_97;
};


}  // namespace reasoner
