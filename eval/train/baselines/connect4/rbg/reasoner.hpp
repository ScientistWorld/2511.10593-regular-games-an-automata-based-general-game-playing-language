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
using RbgType4 = uint;
using RbgType5 = uint;
using RbgType6 = uint;
using RbgType7 = uint;
using RbgType8 = uint;
using RbgType9 = uint;
using RbgType10 = uint;
using RbgType11 = uint;
using RbgType12 = uint;
using RbgType13 = uint;
using RbgType14 = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Board = Arr<Piece, 43>;
using Counters = Arr<RbgType1, 4>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y0 = 1;
constexpr uint rx0y1 = 2;
constexpr uint rx0y2 = 3;
constexpr uint rx0y3 = 4;
constexpr uint rx0y4 = 5;
constexpr uint rx0y5 = 6;
constexpr uint rx1y0 = 7;
constexpr uint rx1y1 = 8;
constexpr uint rx1y2 = 9;
constexpr uint rx1y3 = 10;
constexpr uint rx1y4 = 11;
constexpr uint rx1y5 = 12;
constexpr uint rx2y0 = 13;
constexpr uint rx2y1 = 14;
constexpr uint rx2y2 = 15;
constexpr uint rx2y3 = 16;
constexpr uint rx2y4 = 17;
constexpr uint rx2y5 = 18;
constexpr uint rx3y0 = 19;
constexpr uint rx3y1 = 20;
constexpr uint rx3y2 = 21;
constexpr uint rx3y3 = 22;
constexpr uint rx3y4 = 23;
constexpr uint rx3y5 = 24;
constexpr uint rx4y0 = 25;
constexpr uint rx4y1 = 26;
constexpr uint rx4y2 = 27;
constexpr uint rx4y3 = 28;
constexpr uint rx4y4 = 29;
constexpr uint rx4y5 = 30;
constexpr uint rx5y0 = 31;
constexpr uint rx5y1 = 32;
constexpr uint rx5y2 = 33;
constexpr uint rx5y3 = 34;
constexpr uint rx5y4 = 35;
constexpr uint rx5y5 = 36;
constexpr uint rx6y0 = 37;
constexpr uint rx6y1 = 38;
constexpr uint rx6y2 = 39;
constexpr uint rx6y3 = 40;
constexpr uint rx6y4 = 41;
constexpr uint rx6y5 = 42;
constexpr uint null = 0;
constexpr uint e = 1;
constexpr uint r = 2;
constexpr uint y = 3;
constexpr uint red = 2;
constexpr uint yellow = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 43;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 43> direction_down = Arr<CoordOrNull, 43>{null,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,};
constexpr Arr<CoordOrNull, 43> direction_right = Arr<CoordOrNull, 43>{null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 43> direction_left = Arr<CoordOrNull, 43>{null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,};
constexpr Arr<RbgType4, 43> RbgCoordMap1 = Arr<RbgType4, 43>{null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,};
constexpr Arr<RbgType6, 43> RbgCoordMap3 = Arr<RbgType6, 43>{null,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,null,null,null,null,null,null,};
constexpr Arr<RbgType10, 43> RbgCoordMap7 = Arr<RbgType10, 43>{null,null,null,null,null,null,null,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,null,};
constexpr Arr<RbgType12, 43> RbgCoordMap9 = Arr<RbgType12, 43>{null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,};
constexpr Arr<RbgType10, 43> __gen_RbgCoordMap7_RbgCoordMap7 = Arr<RbgType10, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y2,rx0y3,rx0y4,rx0y5,null,null,rx1y2,rx1y3,rx1y4,rx1y5,null,null,rx2y2,rx2y3,rx2y4,rx2y5,null,null,rx3y2,rx3y3,rx3y4,rx3y5,null,null,rx4y2,rx4y3,rx4y4,rx4y5,null,null,};
constexpr Arr<RbgType10, 43> __gen_RbgCoordMap7___gen_RbgCoordMap7_RbgCoordMap7 = Arr<RbgType10, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y3,rx0y4,rx0y5,null,null,null,rx1y3,rx1y4,rx1y5,null,null,null,rx2y3,rx2y4,rx2y5,null,null,null,rx3y3,rx3y4,rx3y5,null,null,null,};
constexpr Arr<RbgType11, 43> __gen_RbgCoordMap8___gen_RbgCoordMap7_RbgCoordMap7 = Arr<RbgType11, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y0,rx3y1,rx3y2,null,null,null,rx4y0,rx4y1,rx4y2,null,null,null,rx5y0,rx5y1,rx5y2,null,null,null,rx6y0,rx6y1,rx6y2,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 43> __gen_direction_down_direction_down = Arr<CoordOrNull, 43>{null,rx0y2,rx0y3,rx0y4,rx0y5,null,null,rx1y2,rx1y3,rx1y4,rx1y5,null,null,rx2y2,rx2y3,rx2y4,rx2y5,null,null,rx3y2,rx3y3,rx3y4,rx3y5,null,null,rx4y2,rx4y3,rx4y4,rx4y5,null,null,rx5y2,rx5y3,rx5y4,rx5y5,null,null,rx6y2,rx6y3,rx6y4,rx6y5,null,null,};
constexpr Arr<CoordOrNull, 43> __gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 43>{null,rx0y3,rx0y4,rx0y5,null,null,null,rx1y3,rx1y4,rx1y5,null,null,null,rx2y3,rx2y4,rx2y5,null,null,null,rx3y3,rx3y4,rx3y5,null,null,null,rx4y3,rx4y4,rx4y5,null,null,null,rx5y3,rx5y4,rx5y5,null,null,null,rx6y3,rx6y4,rx6y5,null,null,null,};
constexpr Arr<RbgType12, 43> __gen_RbgCoordMap9_RbgCoordMap9 = Arr<RbgType12, 43>{null,rx2y2,rx2y3,rx2y4,rx2y5,null,null,rx3y2,rx3y3,rx3y4,rx3y5,null,null,rx4y2,rx4y3,rx4y4,rx4y5,null,null,rx5y2,rx5y3,rx5y4,rx5y5,null,null,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType12, 43> __gen_RbgCoordMap9___gen_RbgCoordMap9_RbgCoordMap9 = Arr<RbgType12, 43>{null,rx3y3,rx3y4,rx3y5,null,null,null,rx4y3,rx4y4,rx4y5,null,null,null,rx5y3,rx5y4,rx5y5,null,null,null,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType13, 43> __gen_RbgCoordMap10___gen_RbgCoordMap9_RbgCoordMap9 = Arr<RbgType13, 43>{null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,null,null,null,rx1y0,rx1y1,rx1y2,null,null,null,rx2y0,rx2y1,rx2y2,null,null,null,rx3y0,rx3y1,rx3y2,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType4, 43> __gen_RbgCoordMap1_RbgCoordMap1 = Arr<RbgType4, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,null,null,rx1y0,rx1y1,rx1y2,rx1y3,null,null,rx2y0,rx2y1,rx2y2,rx2y3,null,null,rx3y0,rx3y1,rx3y2,rx3y3,null,null,rx4y0,rx4y1,rx4y2,rx4y3,};
constexpr Arr<RbgType4, 43> __gen_RbgCoordMap1___gen_RbgCoordMap1_RbgCoordMap1 = Arr<RbgType4, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,null,null,null,rx1y0,rx1y1,rx1y2,null,null,null,rx2y0,rx2y1,rx2y2,null,null,null,rx3y0,rx3y1,rx3y2,};
constexpr Arr<RbgType5, 43> __gen_RbgCoordMap2___gen_RbgCoordMap1_RbgCoordMap1 = Arr<RbgType5, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y3,rx3y4,rx3y5,null,null,null,rx4y3,rx4y4,rx4y5,null,null,null,rx5y3,rx5y4,rx5y5,null,null,null,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,};
constexpr Arr<RbgType6, 43> __gen_RbgCoordMap3_RbgCoordMap3 = Arr<RbgType6, 43>{null,null,null,rx2y0,rx2y1,rx2y2,rx2y3,null,null,rx3y0,rx3y1,rx3y2,rx3y3,null,null,rx4y0,rx4y1,rx4y2,rx4y3,null,null,rx5y0,rx5y1,rx5y2,rx5y3,null,null,rx6y0,rx6y1,rx6y2,rx6y3,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType6, 43> __gen_RbgCoordMap3___gen_RbgCoordMap3_RbgCoordMap3 = Arr<RbgType6, 43>{null,null,null,null,rx3y0,rx3y1,rx3y2,null,null,null,rx4y0,rx4y1,rx4y2,null,null,null,rx5y0,rx5y1,rx5y2,null,null,null,rx6y0,rx6y1,rx6y2,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType7, 43> __gen_RbgCoordMap4___gen_RbgCoordMap3_RbgCoordMap3 = Arr<RbgType7, 43>{null,null,null,null,null,null,null,null,null,rx0y3,rx0y4,rx0y5,null,null,null,rx1y3,rx1y4,rx1y5,null,null,null,rx2y3,rx2y4,rx2y5,null,null,null,rx3y3,rx3y4,rx3y5,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 43> __gen_direction_left_direction_left = Arr<CoordOrNull, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,};
constexpr Arr<CoordOrNull, 43> __gen_direction_left___gen_direction_left_direction_left = Arr<CoordOrNull, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,};
constexpr Arr<RbgType8, 43> __gen_RbgCoordMap5___gen_direction_left_direction_left = Arr<RbgType8, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 43> __gen_direction_right_direction_right = Arr<CoordOrNull, 43>{null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 43> __gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 43>{null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType9, 43> __gen_RbgCoordMap6___gen_direction_right_direction_right = Arr<RbgType9, 43>{null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,null,null,null,null,null,null,null,null,null,null,null,};

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
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,};
CoordOrNull coord = rx0y0;
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 89;

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
return currentState == 90;
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
bool is_legal_10_17_10_10_17_17_10_17_10();
bool is_legal_10_17_10_10_17_17_10_17_13();
bool is_legal_10_17_10_10_17_17_10_17_17();
bool is_legal_148_155_148_148_155_155_148_155_148();
bool is_legal_148_155_148_148_155_155_148_155_151();
bool is_legal_148_155_148_148_155_155_148_155_155();
bool is_legal_154_11_157_154_11_11_154_11_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_157_154_11_11_154_11_157([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_157_154_11_11_154_11_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_157_154_11_11_292([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_157_154_277_277_154_277_157([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_157_154_277_277_154_277_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_157_154_277_277_154_277_277([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_157_154_277_277_293([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_166();
bool is_legal_166_167_167();
bool is_legal_166_167_171();
bool is_legal_166_167_173();
bool is_legal_166_167_184();
bool is_legal_166_167_186();
bool is_legal_166_167_200();
bool is_legal_166_167_201();
bool is_legal_166_167_216();
bool is_legal_166_167_217();
bool is_legal_166_167_229();
bool is_legal_166_167_231();
bool is_legal_166_167_245();
bool is_legal_166_167_249();
bool is_legal_166_167_254();
bool is_legal_166_167_256();
bool is_legal_16_145_19_16_145_145_16_145_145([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_19_16_145_145_16_145_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_19_16_145_145_16_145_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_19_16_145_145_295([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_19_16_149_149_16_149_149([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_19_16_149_149_16_149_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_19_16_149_149_16_149_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_19_16_149_149_296([[maybe_unused]]RgCache& rgCache);
bool is_legal_280_281_280([[maybe_unused]]RgCache& rgCache);
bool is_legal_280_281_281([[maybe_unused]]RgCache& rgCache);
bool is_legal_282_283_282([[maybe_unused]]RgCache& rgCache);
bool is_legal_282_283_283([[maybe_unused]]RgCache& rgCache);
bool is_legal_34_35_113();
bool is_legal_34_35_117();
bool is_legal_34_35_122();
bool is_legal_34_35_124();
bool is_legal_34_35_34();
bool is_legal_34_35_35();
bool is_legal_34_35_39();
bool is_legal_34_35_41();
bool is_legal_34_35_52();
bool is_legal_34_35_54();
bool is_legal_34_35_68();
bool is_legal_34_35_69();
bool is_legal_34_35_84();
bool is_legal_34_35_85();
bool is_legal_34_35_97();
bool is_legal_34_35_99();
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_133([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_137([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_269([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_271([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_288([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_294([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_297([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_133([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_137([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_269([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_271([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_288([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_294([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_297([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_14([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_141([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_157([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_265([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_269([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_271([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_284([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_294([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_157_157_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_133([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_137([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_139([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_141([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_152([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_25([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_288([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_297([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_32([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_14([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_141([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_284([[maybe_unused]]RgCache& rgCache);
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
state_cache_154_11_157.reset();
state_cache_154_277_157.reset();
state_cache_157.reset();
state_cache_16_145_19.reset();
state_cache_16_149_19.reset();
state_cache_19.reset();
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
std::bitset<43> state_cache_154_11_157;
std::bitset<43> state_cache_154_277_157;
std::bitset<43> state_cache_157;
std::bitset<43> state_cache_16_145_19;
std::bitset<43> state_cache_16_149_19;
std::bitset<43> state_cache_19;
};


}  // namespace reasoner
