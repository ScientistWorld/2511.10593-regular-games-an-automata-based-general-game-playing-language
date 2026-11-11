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
constexpr Arr<RbgType2, 82> math_decr_82 = Arr<RbgType2, 82>{nan,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,};
constexpr Arr<RbgType2, 82> math_incr_82 = Arr<RbgType2, 82>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,nan,};

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
Board board = Board{e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,null,};
CoordOrNull coord = hx0y0;
Coord coord_temp = hx0y0;
Counters counters = Counters{0,81,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 227;

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
return currentState == 228;
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
bool is_legal_118_119_118();
bool is_legal_118_119_119();
bool is_legal_118_119_120();
bool is_legal_118_119_121();
bool is_legal_123_124_123([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_124([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_125([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_126([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_127([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_128([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_129([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_130([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_131([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_132([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_133([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_134([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_135([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_136([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_137([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_138([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_139([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_140([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_141([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_142([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_143([[maybe_unused]]RgCache& rgCache);
bool is_legal_123_124_144([[maybe_unused]]RgCache& rgCache);
bool is_legal_145_146_145();
bool is_legal_145_146_146();
bool is_legal_145_146_147();
bool is_legal_145_146_148();
bool is_legal_158_159_158([[maybe_unused]]RgCache& rgCache);
bool is_legal_158_159_159([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_160([[maybe_unused]]RgCache& rgCache);
bool is_legal_160_161_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_23([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_26([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_27([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_28([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_29([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_30([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_31([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_32([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_33([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_34([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_35([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_36([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_37([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_38([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_39([[maybe_unused]]RgCache& rgCache);
bool is_legal_19_20_40([[maybe_unused]]RgCache& rgCache);
bool is_legal_41_42_41();
bool is_legal_41_42_42();
bool is_legal_41_42_43();
bool is_legal_41_42_44();
bool is_legal_46_47_46([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_47([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_48([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_49([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_50([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_51([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_52([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_53([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_54([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_55([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_56([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_57([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_58([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_59([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_60([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_61([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_62([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_63([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_64([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_65([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_66([[maybe_unused]]RgCache& rgCache);
bool is_legal_46_47_67([[maybe_unused]]RgCache& rgCache);
bool is_legal_4_10_4_4_10_10_4_10_10();
bool is_legal_4_10_4_4_10_10_4_10_11();
bool is_legal_4_10_4_4_10_10_4_10_4();
bool is_legal_4_10_4_4_10_10_4_10_7();
bool is_legal_4_10_4_4_10_10_4_10_8();
bool is_legal_68_69_68();
bool is_legal_68_69_69();
bool is_legal_68_69_70();
bool is_legal_68_69_71();
bool is_legal_81_87_81_81_87_87_81_87_81();
bool is_legal_81_87_81_81_87_87_81_87_84();
bool is_legal_81_87_81_81_87_87_81_87_85();
bool is_legal_81_87_81_81_87_87_81_87_87();
bool is_legal_81_87_81_81_87_87_81_87_88();
bool is_legal_86_155_86_86_155_155_86_155_149([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_150([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_151([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_152([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_153([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_155([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_156([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_89([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_90([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_91([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_92([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_155_86_86_155_155_86_155_93([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_122([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_2([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_3([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_5([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_6([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_89([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_90([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_91([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_92([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_93([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_94([[maybe_unused]]RgCache& rgCache);
bool is_legal_86_5_86_86_5_5_86_5_95([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_100([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_101([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_102([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_103([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_104([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_105([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_106([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_107([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_108([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_109([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_110([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_111([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_112([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_113([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_114([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_115([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_116([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_117([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_96([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_97([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_98([[maybe_unused]]RgCache& rgCache);
bool is_legal_96_97_99([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_13([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_14([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_72([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_73([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_74([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_75([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_76([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_78([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_79([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_78_9_9_78_78_9_78_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_13([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_14([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_16([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_17([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_18([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_45([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_82([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_83([[maybe_unused]]RgCache& rgCache);
bool is_legal_9_82_9_9_82_82_9_82_9([[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_122([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_167([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_168([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_169([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_85([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_87([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_88([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_89([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_122([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_167([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_168([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_169([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_83([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_85([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_87([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_88([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_89([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_95([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_122([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_149([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_150([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_151([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_152([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_153([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_155([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_156([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_3([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_5([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_6([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_86([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_89([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_90([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_91([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_92([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_93([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_94([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_95([[maybe_unused]]RgCache& rgCache);
bool apply_any_86_86_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_13([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_14([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_15([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_16([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_166([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_167([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_17([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_18([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_45([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_72([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_73([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_74([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_75([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_76([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_78([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_79([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_81([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_82([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_83([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_9([[maybe_unused]]RgCache& rgCache);
bool apply_any_9_9_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_5([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_6([[maybe_unused]]RgCache& rgCache);
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
state_cache_102.reset();
state_cache_104.reset();
state_cache_106.reset();
state_cache_108.reset();
state_cache_110.reset();
state_cache_112.reset();
state_cache_114.reset();
state_cache_126.reset();
state_cache_129.reset();
state_cache_131.reset();
state_cache_133.reset();
state_cache_135.reset();
state_cache_137.reset();
state_cache_139.reset();
state_cache_141.reset();
state_cache_17 = false;
state_cache_22.reset();
state_cache_25.reset();
state_cache_27.reset();
state_cache_29.reset();
state_cache_31.reset();
state_cache_33.reset();
state_cache_35.reset();
state_cache_37.reset();
state_cache_49.reset();
state_cache_52.reset();
state_cache_54.reset();
state_cache_56.reset();
state_cache_58.reset();
state_cache_60.reset();
state_cache_62.reset();
state_cache_64.reset();
state_cache_94 = false;
state_cache_99.reset();
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
std::bitset<82> state_cache_102;
std::bitset<82> state_cache_104;
std::bitset<82> state_cache_106;
std::bitset<82> state_cache_108;
std::bitset<82> state_cache_110;
std::bitset<82> state_cache_112;
std::bitset<82> state_cache_114;
std::bitset<82> state_cache_126;
std::bitset<82> state_cache_129;
std::bitset<82> state_cache_131;
std::bitset<82> state_cache_133;
std::bitset<82> state_cache_135;
std::bitset<82> state_cache_137;
std::bitset<82> state_cache_139;
std::bitset<82> state_cache_141;
bool state_cache_17;
std::bitset<82> state_cache_22;
std::bitset<82> state_cache_25;
std::bitset<82> state_cache_27;
std::bitset<82> state_cache_29;
std::bitset<82> state_cache_31;
std::bitset<82> state_cache_33;
std::bitset<82> state_cache_35;
std::bitset<82> state_cache_37;
std::bitset<82> state_cache_49;
std::bitset<82> state_cache_52;
std::bitset<82> state_cache_54;
std::bitset<82> state_cache_56;
std::bitset<82> state_cache_58;
std::bitset<82> state_cache_60;
std::bitset<82> state_cache_62;
std::bitset<82> state_cache_64;
bool state_cache_94;
std::bitset<82> state_cache_99;
};


}  // namespace reasoner
