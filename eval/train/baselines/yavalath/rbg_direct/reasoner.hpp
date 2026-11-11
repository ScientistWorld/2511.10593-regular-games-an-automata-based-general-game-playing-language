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
constexpr Arr<RbgType2, 62> math_decr_62 = Arr<RbgType2, 62>{nan,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,};
constexpr Arr<RbgType2, 62> math_incr_62 = Arr<RbgType2, 62>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,nan,};

using move_representation = boost::container::small_vector<uint,12>;
class GameState;

class RgCache;

struct Move
{
move_representation mr;

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
Coord coord_temp = hx0y0;
Counters counters = Counters{0,61,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 381;

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
return currentState == 382;
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
bool is_legal_10_16_10_10_16_16_10_16_14();
bool is_legal_10_16_10_10_16_16_10_16_16();
bool is_legal_10_16_10_10_16_16_10_16_17();
bool is_legal_151_157_151_151_157_157_151_157_151();
bool is_legal_151_157_151_151_157_157_151_157_154();
bool is_legal_151_157_151_151_157_157_151_157_155();
bool is_legal_151_157_151_151_157_157_151_157_157();
bool is_legal_151_157_151_151_157_157_151_157_158();
bool is_legal_156_11_156_156_11_11_156_11_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_156([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_162([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_164([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_165([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_8([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_11_156_156_11_11_156_11_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_156([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_162([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_213([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_214([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_215([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_275([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_276([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_277([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_278([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_279([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_280([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_281([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_282([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_283([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_284([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_285([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_286([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_287([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_289([[maybe_unused]]RgCache& rgCache);
bool is_legal_156_289_156_156_289_289_156_289_290([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_134([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_135([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_136([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_137([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_138([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_139([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_140([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_141([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_142([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_143([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_144([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_145([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_146([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_148([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_149([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_18([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_72([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_73([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_148_15_15_148_148_15_148_74([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_152([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_153([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_18([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_23([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_152_15_15_152_152_15_152_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_166([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_167([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_168([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_169([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_170([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_171([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_172([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_173([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_174([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_175([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_176([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_177([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_178([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_179([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_180([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_181([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_182([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_183([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_184([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_185([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_186([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_187([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_188([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_189([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_190([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_191([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_192([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_193([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_194([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_195([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_196([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_197([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_198([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_199([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_200([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_201([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_202([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_203([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_204([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_205([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_206([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_207([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_208([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_209([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_210([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_211([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_212([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_216([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_217([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_218([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_219([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_220([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_221([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_222([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_223([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_224([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_225([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_226([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_227([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_228([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_229([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_230([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_231([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_232([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_233([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_234([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_235([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_236([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_237([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_238([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_239([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_240([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_241([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_242([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_243([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_244([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_245([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_246([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_247([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_248([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_249([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_250([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_251([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_252([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_253([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_254([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_255([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_256([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_257([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_258([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_259([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_260([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_261([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_262([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_263([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_264([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_265([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_266([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_267([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_268([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_269([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_270([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_271([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_272([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_273([[maybe_unused]]RgCache& rgCache);
bool is_legal_216_217_274([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_26([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_27([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_28([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_29([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_30([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_31([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_32([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_33([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_34([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_35([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_36([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_37([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_38([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_39([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_40([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_41([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_42([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_43([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_44([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_45([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_46([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_47([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_48([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_49([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_50([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_51([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_52([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_53([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_54([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_55([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_56([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_57([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_58([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_59([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_60([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_61([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_62([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_63([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_64([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_65([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_66([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_67([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_68([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_69([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_70([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_71([[maybe_unused]]RgCache& rgCache);
bool is_legal_292_293_292([[maybe_unused]]RgCache& rgCache);
bool is_legal_292_293_293([[maybe_unused]]RgCache& rgCache);
bool is_legal_294_295_294([[maybe_unused]]RgCache& rgCache);
bool is_legal_294_295_295([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_100([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_101([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_102([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_103([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_104([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_105([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_106([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_107([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_108([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_109([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_110([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_111([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_112([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_113([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_114([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_115([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_116([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_117([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_118([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_119([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_120([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_121([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_122([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_123([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_124([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_125([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_126([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_127([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_128([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_129([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_130([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_131([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_132([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_133([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_75([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_76([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_77([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_78([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_79([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_80([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_81([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_82([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_83([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_84([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_85([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_87([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_88([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_89([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_90([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_91([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_92([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_93([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_94([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_95([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_96([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_97([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_98([[maybe_unused]]RgCache& rgCache);
bool is_legal_75_76_99([[maybe_unused]]RgCache& rgCache);
void state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_134([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_135([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_136([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_137([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_138([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_143([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_144([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_145([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_146([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_148([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_158([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_159([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_213([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_214([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_215([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_275([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_276([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_277([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_278([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_279([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_280([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_281([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_282([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_283([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_285([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_287([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_289([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_296([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_297([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_298([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_299([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_300([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_301([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_302([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_303([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_134([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_135([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_136([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_137([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_138([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_143([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_144([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_145([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_146([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_148([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_158([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_159([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_213([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_214([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_215([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_275([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_276([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_277([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_278([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_279([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_280([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_281([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_282([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_283([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_285([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_287([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_289([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_296([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_297([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_298([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_299([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_300([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_301([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_302([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_303([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_134([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_135([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_136([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_137([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_138([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_139([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_140([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_141([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_142([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_143([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_144([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_145([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_146([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_148([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_149([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_15([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_152([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_153([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_18([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_20([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_21([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_22([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_23([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_24([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_300([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_301([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_72([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_73([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_74([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_156([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_159([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_160([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_161([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_164([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_213([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_214([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_215([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_275([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_276([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_277([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_278([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_279([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_280([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_281([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_282([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_283([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_284([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_285([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_286([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_287([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_289([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_290([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_296([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_297([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_9([[maybe_unused]]RgCache& rgCache);
bool apply_any_156_156_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_296([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_297([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_3([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_5([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_6([[maybe_unused]]RgCache& rgCache);
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
state_cache_101.reset();
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
std::bitset<62> state_cache_101;
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
