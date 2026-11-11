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
using Counters = Arr<RbgType1, 4>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y0 = 1;
constexpr uint rx0y1 = 2;
constexpr uint rx0y2 = 3;
constexpr uint rx0y3 = 4;
constexpr uint rx0y4 = 5;
constexpr uint rx0y5 = 6;
constexpr uint rx0y6 = 7;
constexpr uint rx0y7 = 8;
constexpr uint rx1y0 = 9;
constexpr uint rx1y1 = 10;
constexpr uint rx1y2 = 11;
constexpr uint rx1y3 = 12;
constexpr uint rx1y4 = 13;
constexpr uint rx1y5 = 14;
constexpr uint rx1y6 = 15;
constexpr uint rx1y7 = 16;
constexpr uint rx2y0 = 17;
constexpr uint rx2y1 = 18;
constexpr uint rx2y2 = 19;
constexpr uint rx2y3 = 20;
constexpr uint rx2y4 = 21;
constexpr uint rx2y5 = 22;
constexpr uint rx2y6 = 23;
constexpr uint rx2y7 = 24;
constexpr uint rx3y0 = 25;
constexpr uint rx3y1 = 26;
constexpr uint rx3y2 = 27;
constexpr uint rx3y3 = 28;
constexpr uint rx3y4 = 29;
constexpr uint rx3y5 = 30;
constexpr uint rx3y6 = 31;
constexpr uint rx3y7 = 32;
constexpr uint rx4y0 = 33;
constexpr uint rx4y1 = 34;
constexpr uint rx4y2 = 35;
constexpr uint rx4y3 = 36;
constexpr uint rx4y4 = 37;
constexpr uint rx4y5 = 38;
constexpr uint rx4y6 = 39;
constexpr uint rx4y7 = 40;
constexpr uint rx5y0 = 41;
constexpr uint rx5y1 = 42;
constexpr uint rx5y2 = 43;
constexpr uint rx5y3 = 44;
constexpr uint rx5y4 = 45;
constexpr uint rx5y5 = 46;
constexpr uint rx5y6 = 47;
constexpr uint rx5y7 = 48;
constexpr uint rx6y0 = 49;
constexpr uint rx6y1 = 50;
constexpr uint rx6y2 = 51;
constexpr uint rx6y3 = 52;
constexpr uint rx6y4 = 53;
constexpr uint rx6y5 = 54;
constexpr uint rx6y6 = 55;
constexpr uint rx6y7 = 56;
constexpr uint rx7y0 = 57;
constexpr uint rx7y1 = 58;
constexpr uint rx7y2 = 59;
constexpr uint rx7y3 = 60;
constexpr uint rx7y4 = 61;
constexpr uint rx7y5 = 62;
constexpr uint rx7y6 = 63;
constexpr uint rx7y7 = 64;
constexpr uint null = 0;
constexpr uint b = 1;
constexpr uint e = 2;
constexpr uint w = 3;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 65;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
const Arr<std::vector<Coord>, 64> ReachableMap1iter = Arr<std::vector<Coord>, 64>{std::vector<Coord>{},std::vector<Coord>{rx2y0,},std::vector<Coord>{rx1y0,rx2y1,},std::vector<Coord>{rx1y1,rx2y2,},std::vector<Coord>{rx1y2,rx2y3,},std::vector<Coord>{rx1y3,rx2y4,},std::vector<Coord>{rx1y4,rx2y5,},std::vector<Coord>{rx1y5,rx2y6,},std::vector<Coord>{},std::vector<Coord>{rx3y0,},std::vector<Coord>{rx0y0,rx2y0,rx3y1,},std::vector<Coord>{rx0y1,rx2y1,rx3y2,},std::vector<Coord>{rx0y2,rx2y2,rx3y3,},std::vector<Coord>{rx0y3,rx2y3,rx3y4,},std::vector<Coord>{rx0y4,rx2y4,rx3y5,},std::vector<Coord>{rx0y5,rx2y5,rx3y6,},std::vector<Coord>{},std::vector<Coord>{rx0y0,rx4y0,},std::vector<Coord>{rx1y0,rx3y0,rx0y1,rx4y1,},std::vector<Coord>{rx1y1,rx3y1,rx0y2,rx4y2,},std::vector<Coord>{rx1y2,rx3y2,rx0y3,rx4y3,},std::vector<Coord>{rx1y3,rx3y3,rx0y4,rx4y4,},std::vector<Coord>{rx1y4,rx3y4,rx0y5,rx4y5,},std::vector<Coord>{rx1y5,rx3y5,rx0y6,rx4y6,},std::vector<Coord>{},std::vector<Coord>{rx1y0,rx5y0,},std::vector<Coord>{rx2y0,rx4y0,rx1y1,rx5y1,},std::vector<Coord>{rx2y1,rx4y1,rx1y2,rx5y2,},std::vector<Coord>{rx2y2,rx4y2,rx1y3,rx5y3,},std::vector<Coord>{rx2y3,rx4y3,rx1y4,rx5y4,},std::vector<Coord>{rx2y4,rx4y4,rx1y5,rx5y5,},std::vector<Coord>{rx2y5,rx4y5,rx1y6,rx5y6,},std::vector<Coord>{},std::vector<Coord>{rx2y0,rx6y0,},std::vector<Coord>{rx3y0,rx5y0,rx2y1,rx6y1,},std::vector<Coord>{rx3y1,rx5y1,rx2y2,rx6y2,},std::vector<Coord>{rx3y2,rx5y2,rx2y3,rx6y3,},std::vector<Coord>{rx3y3,rx5y3,rx2y4,rx6y4,},std::vector<Coord>{rx3y4,rx5y4,rx2y5,rx6y5,},std::vector<Coord>{rx3y5,rx5y5,rx2y6,rx6y6,},std::vector<Coord>{},std::vector<Coord>{rx3y0,rx7y0,},std::vector<Coord>{rx4y0,rx6y0,rx3y1,rx7y1,},std::vector<Coord>{rx4y1,rx6y1,rx3y2,rx7y2,},std::vector<Coord>{rx4y2,rx6y2,rx3y3,rx7y3,},std::vector<Coord>{rx4y3,rx6y3,rx3y4,rx7y4,},std::vector<Coord>{rx4y4,rx6y4,rx3y5,rx7y5,},std::vector<Coord>{rx4y5,rx6y5,rx3y6,rx7y6,},std::vector<Coord>{},std::vector<Coord>{rx4y0,},std::vector<Coord>{rx5y0,rx7y0,rx4y1,},std::vector<Coord>{rx5y1,rx7y1,rx4y2,},std::vector<Coord>{rx5y2,rx7y2,rx4y3,},std::vector<Coord>{rx5y3,rx7y3,rx4y4,},std::vector<Coord>{rx5y4,rx7y4,rx4y5,},std::vector<Coord>{rx5y5,rx7y5,rx4y6,},std::vector<Coord>{},std::vector<Coord>{rx5y0,},std::vector<Coord>{rx6y0,rx5y1,},std::vector<Coord>{rx6y1,rx5y2,},std::vector<Coord>{rx6y2,rx5y3,},std::vector<Coord>{rx6y3,rx5y4,},std::vector<Coord>{rx6y4,rx5y5,},std::vector<Coord>{rx6y5,rx5y6,},};
const Arr<std::vector<Coord>, 64> ReachableMap2iter = Arr<std::vector<Coord>, 64>{std::vector<Coord>{rx2y1,rx1y2,},std::vector<Coord>{rx2y2,rx1y3,},std::vector<Coord>{rx2y3,rx1y4,},std::vector<Coord>{rx2y4,rx1y5,},std::vector<Coord>{rx2y5,rx1y6,},std::vector<Coord>{rx2y6,rx1y7,},std::vector<Coord>{rx2y7,},std::vector<Coord>{},std::vector<Coord>{rx3y1,rx0y2,rx2y2,},std::vector<Coord>{rx3y2,rx0y3,rx2y3,},std::vector<Coord>{rx3y3,rx0y4,rx2y4,},std::vector<Coord>{rx3y4,rx0y5,rx2y5,},std::vector<Coord>{rx3y5,rx0y6,rx2y6,},std::vector<Coord>{rx3y6,rx0y7,rx2y7,},std::vector<Coord>{rx3y7,},std::vector<Coord>{},std::vector<Coord>{rx0y1,rx4y1,rx1y2,rx3y2,},std::vector<Coord>{rx0y2,rx4y2,rx1y3,rx3y3,},std::vector<Coord>{rx0y3,rx4y3,rx1y4,rx3y4,},std::vector<Coord>{rx0y4,rx4y4,rx1y5,rx3y5,},std::vector<Coord>{rx0y5,rx4y5,rx1y6,rx3y6,},std::vector<Coord>{rx0y6,rx4y6,rx1y7,rx3y7,},std::vector<Coord>{rx0y7,rx4y7,},std::vector<Coord>{},std::vector<Coord>{rx1y1,rx5y1,rx2y2,rx4y2,},std::vector<Coord>{rx1y2,rx5y2,rx2y3,rx4y3,},std::vector<Coord>{rx1y3,rx5y3,rx2y4,rx4y4,},std::vector<Coord>{rx1y4,rx5y4,rx2y5,rx4y5,},std::vector<Coord>{rx1y5,rx5y5,rx2y6,rx4y6,},std::vector<Coord>{rx1y6,rx5y6,rx2y7,rx4y7,},std::vector<Coord>{rx1y7,rx5y7,},std::vector<Coord>{},std::vector<Coord>{rx2y1,rx6y1,rx3y2,rx5y2,},std::vector<Coord>{rx2y2,rx6y2,rx3y3,rx5y3,},std::vector<Coord>{rx2y3,rx6y3,rx3y4,rx5y4,},std::vector<Coord>{rx2y4,rx6y4,rx3y5,rx5y5,},std::vector<Coord>{rx2y5,rx6y5,rx3y6,rx5y6,},std::vector<Coord>{rx2y6,rx6y6,rx3y7,rx5y7,},std::vector<Coord>{rx2y7,rx6y7,},std::vector<Coord>{},std::vector<Coord>{rx3y1,rx7y1,rx4y2,rx6y2,},std::vector<Coord>{rx3y2,rx7y2,rx4y3,rx6y3,},std::vector<Coord>{rx3y3,rx7y3,rx4y4,rx6y4,},std::vector<Coord>{rx3y4,rx7y4,rx4y5,rx6y5,},std::vector<Coord>{rx3y5,rx7y5,rx4y6,rx6y6,},std::vector<Coord>{rx3y6,rx7y6,rx4y7,rx6y7,},std::vector<Coord>{rx3y7,rx7y7,},std::vector<Coord>{},std::vector<Coord>{rx4y1,rx5y2,rx7y2,},std::vector<Coord>{rx4y2,rx5y3,rx7y3,},std::vector<Coord>{rx4y3,rx5y4,rx7y4,},std::vector<Coord>{rx4y4,rx5y5,rx7y5,},std::vector<Coord>{rx4y5,rx5y6,rx7y6,},std::vector<Coord>{rx4y6,rx5y7,rx7y7,},std::vector<Coord>{rx4y7,},std::vector<Coord>{},std::vector<Coord>{rx5y1,rx6y2,},std::vector<Coord>{rx5y2,rx6y3,},std::vector<Coord>{rx5y3,rx6y4,},std::vector<Coord>{rx5y4,rx6y5,},std::vector<Coord>{rx5y5,rx6y6,},std::vector<Coord>{rx5y6,rx6y7,},std::vector<Coord>{rx5y7,},std::vector<Coord>{},};
constexpr Arr<CoordOrNull, 65> direction_down = Arr<CoordOrNull, 65>{null,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,null,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,null,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,null,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,null,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,null,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,null,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,null,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,null,};
constexpr Arr<CoordOrNull, 65> direction_right = Arr<CoordOrNull, 65>{null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx7y0,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 65> direction_left = Arr<CoordOrNull, 65>{null,null,null,null,null,null,null,null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,};
constexpr Arr<CoordOrNull, 65> direction_up = Arr<CoordOrNull, 65>{null,null,rx0y0,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,null,rx1y0,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,null,rx2y0,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,null,rx3y0,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,null,rx4y0,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,null,rx5y0,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,null,rx6y0,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,null,rx7y0,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,};
constexpr Arr<RbgType2, 65> math_decr_65 = Arr<RbgType2, 65>{nan,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,};
constexpr Arr<RbgType2, 65> math_incr_65 = Arr<RbgType2, 65>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,nan,};
constexpr Arr<Arr<Bool, 64>, 64> ReachableMap1 = Arr<Arr<Bool, 64>, 64>{Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},};
constexpr Arr<Arr<Bool, 64>, 64> ReachableMap2 = Arr<Arr<Bool, 64>, 64>{Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},Arr<Bool, 64>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},};

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
Board board = Board{null,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,b,b,e,e,e,e,w,w,};
CoordOrNull coord = rx0y0;
Coord coord_temp = rx0y0;
Counters counters = Counters{16,16,32,16,};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 181;

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
return currentState == 182;
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
bool is_legal_18_42_18_18_42_42_18_42_18();
bool is_legal_18_42_18_18_42_42_18_42_21();
bool is_legal_18_42_18_18_42_42_18_42_22();
bool is_legal_18_42_18_18_42_42_18_42_23();
bool is_legal_18_42_18_18_42_42_18_42_24();
bool is_legal_18_42_18_18_42_42_18_42_25();
bool is_legal_18_42_18_18_42_42_18_42_26();
bool is_legal_18_42_18_18_42_42_18_42_39();
bool is_legal_18_42_18_18_42_42_18_42_40();
bool is_legal_18_42_18_18_42_42_18_42_42();
bool is_legal_18_42_18_18_42_42_18_42_43();
bool is_legal_18_46_18_18_46_46_18_46_18();
bool is_legal_18_46_18_18_46_46_18_46_21();
bool is_legal_18_46_18_18_46_46_18_46_22();
bool is_legal_18_46_18_18_46_46_18_46_23();
bool is_legal_18_46_18_18_46_46_18_46_24();
bool is_legal_18_46_18_18_46_46_18_46_25();
bool is_legal_18_46_18_18_46_46_18_46_26();
bool is_legal_18_46_18_18_46_46_18_46_27();
bool is_legal_18_46_18_18_46_46_18_46_28();
bool is_legal_18_46_18_18_46_46_18_46_29();
bool is_legal_18_46_18_18_46_46_18_46_34();
bool is_legal_18_46_18_18_46_46_18_46_35();
bool is_legal_18_46_18_18_46_46_18_46_36();
bool is_legal_18_46_18_18_46_46_18_46_37();
bool is_legal_18_46_18_18_46_46_18_46_38();
bool is_legal_18_46_18_18_46_46_18_46_46();
bool is_legal_18_46_18_18_46_46_18_46_47();
bool is_legal_30_31_30();
bool is_legal_30_31_31();
bool is_legal_30_31_32();
bool is_legal_30_31_33();
bool is_legal_45_60_45_45_60_60_45_60_45();
bool is_legal_45_60_45_45_60_60_45_60_48();
bool is_legal_45_60_45_45_60_60_45_60_49();
bool is_legal_45_60_45_45_60_60_45_60_50();
bool is_legal_45_60_45_45_60_60_45_60_51();
bool is_legal_45_60_45_45_60_60_45_60_52();
bool is_legal_45_60_45_45_60_60_45_60_53();
bool is_legal_45_60_45_45_60_60_45_60_54();
bool is_legal_45_60_45_45_60_60_45_60_55();
bool is_legal_45_60_45_45_60_60_45_60_56();
bool is_legal_45_60_45_45_60_60_45_60_57();
bool is_legal_45_60_45_45_60_60_45_60_58();
bool is_legal_45_60_45_45_60_60_45_60_60();
bool is_legal_45_60_45_45_60_60_45_60_61();
bool is_legal_4_19_4_4_19_19_4_19_10();
bool is_legal_4_19_4_4_19_19_4_19_11();
bool is_legal_4_19_4_4_19_19_4_19_12();
bool is_legal_4_19_4_4_19_19_4_19_13();
bool is_legal_4_19_4_4_19_19_4_19_14();
bool is_legal_4_19_4_4_19_19_4_19_15();
bool is_legal_4_19_4_4_19_19_4_19_16();
bool is_legal_4_19_4_4_19_19_4_19_17();
bool is_legal_4_19_4_4_19_19_4_19_19();
bool is_legal_4_19_4_4_19_19_4_19_20();
bool is_legal_4_19_4_4_19_19_4_19_4();
bool is_legal_4_19_4_4_19_19_4_19_7();
bool is_legal_4_19_4_4_19_19_4_19_8();
bool is_legal_4_19_4_4_19_19_4_19_9();
bool is_legal_59_5_59_59_5_5_59_5_2();
bool is_legal_59_5_59_59_5_5_59_5_3();
bool is_legal_59_5_59_59_5_5_59_5_5();
bool is_legal_59_5_59_59_5_5_59_5_59();
bool is_legal_59_5_59_59_5_5_59_5_6();
bool is_legal_59_5_59_59_5_5_59_5_62();
bool is_legal_59_5_59_59_5_5_59_5_63();
bool is_legal_59_5_59_59_5_5_59_5_64();
bool is_legal_59_5_59_59_5_5_59_5_65();
bool is_legal_59_5_59_59_5_5_59_5_66();
bool is_legal_59_5_59_59_5_5_59_5_67();
bool is_legal_59_5_59_59_5_5_59_5_68();
bool is_legal_59_5_59_59_5_5_59_5_69();
bool is_legal_59_5_59_59_5_5_59_5_70();
bool is_legal_59_5_59_59_5_5_59_5_75();
bool is_legal_59_5_59_59_5_5_59_5_76();
bool is_legal_59_5_59_59_5_5_59_5_77();
bool is_legal_59_5_59_59_5_5_59_5_78();
bool is_legal_59_5_59_59_5_5_59_5_79();
bool is_legal_59_83_59_59_83_83_59_83_59();
bool is_legal_59_83_59_59_83_83_59_83_62();
bool is_legal_59_83_59_59_83_83_59_83_63();
bool is_legal_59_83_59_59_83_83_59_83_64();
bool is_legal_59_83_59_59_83_83_59_83_65();
bool is_legal_59_83_59_59_83_83_59_83_66();
bool is_legal_59_83_59_59_83_83_59_83_67();
bool is_legal_59_83_59_59_83_83_59_83_80();
bool is_legal_59_83_59_59_83_83_59_83_81();
bool is_legal_59_83_59_59_83_83_59_83_83();
bool is_legal_59_83_59_59_83_83_59_83_84();
bool is_legal_71_72_71();
bool is_legal_71_72_72();
bool is_legal_71_72_73();
bool is_legal_71_72_74();
bool is_legal_86_87_86();
bool is_legal_86_87_87();
bool is_legal_88_89_88();
bool is_legal_88_89_89();
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_49([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_52([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_54([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_57([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_60([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_62([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_69([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_77([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_97([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_48([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_49([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_52([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_54([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_57([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_60([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_62([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_64([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_67([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_69([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_70([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_77([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_83([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_95([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_97([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_18_18_18();
bool apply_any_18_18_21();
bool apply_any_18_18_22();
bool apply_any_18_18_23();
bool apply_any_18_18_24();
bool apply_any_18_18_25();
bool apply_any_18_18_26();
bool apply_any_18_18_27();
bool apply_any_18_18_28();
bool apply_any_18_18_29();
bool apply_any_18_18_34();
bool apply_any_18_18_35();
bool apply_any_18_18_36();
bool apply_any_18_18_37();
bool apply_any_18_18_38();
bool apply_any_18_18_39();
bool apply_any_18_18_40();
bool apply_any_18_18_42();
bool apply_any_18_18_43();
bool apply_any_18_18_45();
bool apply_any_18_18_46();
bool apply_any_18_18_47();
bool apply_any_18_18_94();
bool apply_any_18_18_95();
bool apply_any_18_18_end();
bool apply_any_59_59_2();
bool apply_any_59_59_3();
bool apply_any_59_59_4();
bool apply_any_59_59_5();
bool apply_any_59_59_59();
bool apply_any_59_59_6();
bool apply_any_59_59_62();
bool apply_any_59_59_63();
bool apply_any_59_59_64();
bool apply_any_59_59_65();
bool apply_any_59_59_66();
bool apply_any_59_59_67();
bool apply_any_59_59_68();
bool apply_any_59_59_69();
bool apply_any_59_59_70();
bool apply_any_59_59_75();
bool apply_any_59_59_76();
bool apply_any_59_59_77();
bool apply_any_59_59_78();
bool apply_any_59_59_79();
bool apply_any_59_59_80();
bool apply_any_59_59_81();
bool apply_any_59_59_83();
bool apply_any_59_59_84();
bool apply_any_59_59_90();
bool apply_any_59_59_91();
bool apply_any_59_59_end();
bool apply_any_begin_begin_2();
bool apply_any_begin_begin_4();
bool apply_any_begin_begin_5();
bool apply_any_begin_begin_6();
bool apply_any_begin_begin_90();
bool apply_any_begin_begin_91();
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_end();
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
