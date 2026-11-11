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
constexpr Arr<CoordOrNull, 43> direction_up = Arr<CoordOrNull, 43>{null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,};
constexpr Arr<RbgType4, 43> RbgCoordMap1 = Arr<RbgType4, 43>{null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,};
constexpr Arr<RbgType5, 43> RbgCoordMap2 = Arr<RbgType5, 43>{null,rx3y3,rx3y4,rx3y5,null,null,null,rx4y3,rx4y4,rx4y5,null,null,null,rx5y3,rx5y4,rx5y5,null,null,null,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType6, 43> RbgCoordMap3 = Arr<RbgType6, 43>{null,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,null,null,null,null,null,null,};
constexpr Arr<RbgType7, 43> RbgCoordMap4 = Arr<RbgType7, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y3,rx0y4,rx0y5,null,null,null,rx1y3,rx1y4,rx1y5,null,null,null,rx2y3,rx2y4,rx2y5,null,null,null,rx3y3,rx3y4,rx3y5,null,null,null,};
constexpr Arr<RbgType8, 43> RbgCoordMap5 = Arr<RbgType8, 43>{null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType9, 43> RbgCoordMap6 = Arr<RbgType9, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,};
constexpr Arr<RbgType10, 43> RbgCoordMap7 = Arr<RbgType10, 43>{null,null,null,null,null,null,null,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,null,};
constexpr Arr<RbgType11, 43> RbgCoordMap8 = Arr<RbgType11, 43>{null,null,null,null,rx3y0,rx3y1,rx3y2,null,null,null,rx4y0,rx4y1,rx4y2,null,null,null,rx5y0,rx5y1,rx5y2,null,null,null,rx6y0,rx6y1,rx6y2,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType12, 43> RbgCoordMap9 = Arr<RbgType12, 43>{null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,null,null,null,null,null,null,null,};
constexpr Arr<RbgType13, 43> RbgCoordMap10 = Arr<RbgType13, 43>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,null,null,null,rx1y0,rx1y1,rx1y2,null,null,null,rx2y0,rx2y1,rx2y2,null,null,null,rx3y0,rx3y1,rx3y2,};
constexpr Arr<RbgType14, 43> math_decr_43 = Arr<RbgType14, 43>{nan,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,};
constexpr Arr<RbgType14, 43> math_incr_43 = Arr<RbgType14, 43>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,nan,};

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
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,};
CoordOrNull coord = rx0y0;
Coord coord_temp = rx0y0;
Counters counters = Counters{0,42,0,0,};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 371;

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
return currentState == 372;
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
bool is_legal_10_17_10_10_17_17_10_17_14();
bool is_legal_10_17_10_10_17_17_10_17_15();
bool is_legal_10_17_10_10_17_17_10_17_17();
bool is_legal_10_17_10_10_17_17_10_17_18();
bool is_legal_148_155_148_148_155_155_148_155_148();
bool is_legal_148_155_148_148_155_155_148_155_151();
bool is_legal_148_155_148_148_155_155_148_155_152();
bool is_legal_148_155_148_148_155_155_148_155_153();
bool is_legal_148_155_148_148_155_155_148_155_155();
bool is_legal_148_155_148_148_155_155_148_155_156();
bool is_legal_154_11_154_154_11_11_154_11_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_154([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_157([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_158([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_162([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_164([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_165([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_264([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_265([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_266([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_267([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_268([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_8([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_11_154_154_11_11_154_11_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_154([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_157([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_158([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_162([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_269([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_270([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_271([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_272([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_273([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_274([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_275([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_277([[maybe_unused]]RgCache& rgCache);
bool is_legal_154_277_154_154_277_277_154_277_278([[maybe_unused]]RgCache& rgCache);
bool is_legal_166_167_166();
bool is_legal_166_167_167();
bool is_legal_166_167_168();
bool is_legal_166_167_169();
bool is_legal_166_167_170();
bool is_legal_166_167_171();
bool is_legal_166_167_172();
bool is_legal_166_167_173();
bool is_legal_166_167_174();
bool is_legal_166_167_175();
bool is_legal_166_167_176();
bool is_legal_166_167_177();
bool is_legal_166_167_178();
bool is_legal_166_167_179();
bool is_legal_166_167_180();
bool is_legal_166_167_181();
bool is_legal_166_167_182();
bool is_legal_166_167_183();
bool is_legal_166_167_184();
bool is_legal_166_167_185();
bool is_legal_166_167_186();
bool is_legal_166_167_187();
bool is_legal_166_167_188();
bool is_legal_166_167_189();
bool is_legal_166_167_190();
bool is_legal_166_167_191();
bool is_legal_166_167_192();
bool is_legal_166_167_193();
bool is_legal_166_167_194();
bool is_legal_166_167_195();
bool is_legal_166_167_196();
bool is_legal_166_167_197();
bool is_legal_166_167_198();
bool is_legal_166_167_199();
bool is_legal_166_167_200();
bool is_legal_166_167_201();
bool is_legal_166_167_202();
bool is_legal_166_167_203();
bool is_legal_166_167_204();
bool is_legal_166_167_205();
bool is_legal_166_167_206();
bool is_legal_166_167_207();
bool is_legal_166_167_208();
bool is_legal_166_167_209();
bool is_legal_166_167_210();
bool is_legal_166_167_211();
bool is_legal_166_167_212();
bool is_legal_166_167_213();
bool is_legal_166_167_214();
bool is_legal_166_167_215();
bool is_legal_166_167_216();
bool is_legal_166_167_217();
bool is_legal_166_167_218();
bool is_legal_166_167_219();
bool is_legal_166_167_220();
bool is_legal_166_167_221();
bool is_legal_166_167_222();
bool is_legal_166_167_223();
bool is_legal_166_167_224();
bool is_legal_166_167_225();
bool is_legal_166_167_226();
bool is_legal_166_167_227();
bool is_legal_166_167_228();
bool is_legal_166_167_229();
bool is_legal_166_167_230();
bool is_legal_166_167_231();
bool is_legal_166_167_232();
bool is_legal_166_167_233();
bool is_legal_166_167_234();
bool is_legal_166_167_235();
bool is_legal_166_167_236();
bool is_legal_166_167_237();
bool is_legal_166_167_238();
bool is_legal_166_167_239();
bool is_legal_166_167_240();
bool is_legal_166_167_241();
bool is_legal_166_167_242();
bool is_legal_166_167_243();
bool is_legal_166_167_244();
bool is_legal_166_167_245();
bool is_legal_166_167_246();
bool is_legal_166_167_247();
bool is_legal_166_167_248();
bool is_legal_166_167_249();
bool is_legal_166_167_250();
bool is_legal_166_167_251();
bool is_legal_166_167_252();
bool is_legal_166_167_253();
bool is_legal_166_167_254();
bool is_legal_166_167_255();
bool is_legal_166_167_256();
bool is_legal_166_167_257();
bool is_legal_166_167_258();
bool is_legal_166_167_259();
bool is_legal_166_167_260();
bool is_legal_166_167_261();
bool is_legal_166_167_262();
bool is_legal_166_167_263();
bool is_legal_16_145_16_16_145_145_16_145_137([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_138([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_139([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_140([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_141([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_142([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_143([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_145([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_146([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_23([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_145_16_16_145_145_16_145_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_132([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_133([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_134([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_135([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_136([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_149([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_150([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_23([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_32([[maybe_unused]]RgCache& rgCache);
bool is_legal_16_149_16_16_149_149_16_149_33([[maybe_unused]]RgCache& rgCache);
bool is_legal_26_27_26();
bool is_legal_26_27_27();
bool is_legal_26_27_28();
bool is_legal_26_27_29();
bool is_legal_26_27_30();
bool is_legal_26_27_31();
bool is_legal_280_281_280([[maybe_unused]]RgCache& rgCache);
bool is_legal_280_281_281([[maybe_unused]]RgCache& rgCache);
bool is_legal_282_283_282([[maybe_unused]]RgCache& rgCache);
bool is_legal_282_283_283([[maybe_unused]]RgCache& rgCache);
bool is_legal_34_35_100();
bool is_legal_34_35_101();
bool is_legal_34_35_102();
bool is_legal_34_35_103();
bool is_legal_34_35_104();
bool is_legal_34_35_105();
bool is_legal_34_35_106();
bool is_legal_34_35_107();
bool is_legal_34_35_108();
bool is_legal_34_35_109();
bool is_legal_34_35_110();
bool is_legal_34_35_111();
bool is_legal_34_35_112();
bool is_legal_34_35_113();
bool is_legal_34_35_114();
bool is_legal_34_35_115();
bool is_legal_34_35_116();
bool is_legal_34_35_117();
bool is_legal_34_35_118();
bool is_legal_34_35_119();
bool is_legal_34_35_120();
bool is_legal_34_35_121();
bool is_legal_34_35_122();
bool is_legal_34_35_123();
bool is_legal_34_35_124();
bool is_legal_34_35_125();
bool is_legal_34_35_126();
bool is_legal_34_35_127();
bool is_legal_34_35_128();
bool is_legal_34_35_129();
bool is_legal_34_35_130();
bool is_legal_34_35_131();
bool is_legal_34_35_34();
bool is_legal_34_35_35();
bool is_legal_34_35_36();
bool is_legal_34_35_37();
bool is_legal_34_35_38();
bool is_legal_34_35_39();
bool is_legal_34_35_40();
bool is_legal_34_35_41();
bool is_legal_34_35_42();
bool is_legal_34_35_43();
bool is_legal_34_35_44();
bool is_legal_34_35_45();
bool is_legal_34_35_46();
bool is_legal_34_35_47();
bool is_legal_34_35_48();
bool is_legal_34_35_49();
bool is_legal_34_35_50();
bool is_legal_34_35_51();
bool is_legal_34_35_52();
bool is_legal_34_35_53();
bool is_legal_34_35_54();
bool is_legal_34_35_55();
bool is_legal_34_35_56();
bool is_legal_34_35_57();
bool is_legal_34_35_58();
bool is_legal_34_35_59();
bool is_legal_34_35_60();
bool is_legal_34_35_61();
bool is_legal_34_35_62();
bool is_legal_34_35_63();
bool is_legal_34_35_64();
bool is_legal_34_35_65();
bool is_legal_34_35_66();
bool is_legal_34_35_67();
bool is_legal_34_35_68();
bool is_legal_34_35_69();
bool is_legal_34_35_70();
bool is_legal_34_35_71();
bool is_legal_34_35_72();
bool is_legal_34_35_73();
bool is_legal_34_35_74();
bool is_legal_34_35_75();
bool is_legal_34_35_76();
bool is_legal_34_35_77();
bool is_legal_34_35_78();
bool is_legal_34_35_79();
bool is_legal_34_35_80();
bool is_legal_34_35_81();
bool is_legal_34_35_82();
bool is_legal_34_35_83();
bool is_legal_34_35_84();
bool is_legal_34_35_85();
bool is_legal_34_35_86();
bool is_legal_34_35_87();
bool is_legal_34_35_88();
bool is_legal_34_35_89();
bool is_legal_34_35_90();
bool is_legal_34_35_91();
bool is_legal_34_35_92();
bool is_legal_34_35_93();
bool is_legal_34_35_94();
bool is_legal_34_35_95();
bool is_legal_34_35_96();
bool is_legal_34_35_97();
bool is_legal_34_35_98();
bool is_legal_34_35_99();
void state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_132([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_133([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
void state_145([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_146([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_148([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_264([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_266([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_267([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_268([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_269([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_270([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_271([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_272([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_273([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_274([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_275([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_277([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_278([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_285([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_287([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_288([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_289([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_291([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
bool apply_state_132([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_133([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
bool apply_state_145([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_146([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_148([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_158([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_159([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_264([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_266([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_267([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_268([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_269([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_270([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_271([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_272([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_273([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_274([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_275([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_277([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_278([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_285([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_287([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_288([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_289([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_291([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_154([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_157([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_158([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_159([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_160([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_161([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_164([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_264([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_265([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_266([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_267([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_268([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_269([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_270([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_271([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_272([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_273([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_274([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_275([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_277([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_278([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_284([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_285([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_9([[maybe_unused]]RgCache& rgCache);
bool apply_any_154_154_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_132([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_133([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_134([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_135([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_136([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_137([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_138([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_139([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_140([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_141([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_142([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_143([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_145([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_146([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_148([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_149([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_150([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_16([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_20([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_21([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_22([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_23([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_24([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_25([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_288([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_289([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_32([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_33([[maybe_unused]]RgCache& rgCache);
bool apply_any_16_16_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_284([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_285([[maybe_unused]]RgCache& rgCache);
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
state_cache_154_11_159.reset();
state_cache_154_11_161.reset();
state_cache_154_277_159.reset();
state_cache_154_277_161.reset();
state_cache_158.reset();
state_cache_159.reset();
state_cache_161.reset();
state_cache_16_145_21.reset();
state_cache_16_145_23.reset();
state_cache_16_149_21.reset();
state_cache_16_149_23.reset();
state_cache_20.reset();
state_cache_21.reset();
state_cache_23.reset();
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
std::bitset<43> state_cache_154_11_159;
std::bitset<43> state_cache_154_11_161;
std::bitset<43> state_cache_154_277_159;
std::bitset<43> state_cache_154_277_161;
std::bitset<43> state_cache_158;
std::bitset<43> state_cache_159;
std::bitset<43> state_cache_161;
std::bitset<43> state_cache_16_145_21;
std::bitset<43> state_cache_16_145_23;
std::bitset<43> state_cache_16_149_21;
std::bitset<43> state_cache_16_149_23;
std::bitset<43> state_cache_20;
std::bitset<43> state_cache_21;
std::bitset<43> state_cache_23;
};


}  // namespace reasoner
