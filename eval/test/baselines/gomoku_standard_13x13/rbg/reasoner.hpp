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
using Bool = uint;
using PlayerOrSystem = uint;
using Board = Arr<Piece, 170>;
using Counters = Arr<RbgType1, 4>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y0 = 1;
constexpr uint rx0y1 = 2;
constexpr uint rx0y10 = 3;
constexpr uint rx0y11 = 4;
constexpr uint rx0y12 = 5;
constexpr uint rx0y2 = 6;
constexpr uint rx0y3 = 7;
constexpr uint rx0y4 = 8;
constexpr uint rx0y5 = 9;
constexpr uint rx0y6 = 10;
constexpr uint rx0y7 = 11;
constexpr uint rx0y8 = 12;
constexpr uint rx0y9 = 13;
constexpr uint rx10y0 = 14;
constexpr uint rx10y1 = 15;
constexpr uint rx10y10 = 16;
constexpr uint rx10y11 = 17;
constexpr uint rx10y12 = 18;
constexpr uint rx10y2 = 19;
constexpr uint rx10y3 = 20;
constexpr uint rx10y4 = 21;
constexpr uint rx10y5 = 22;
constexpr uint rx10y6 = 23;
constexpr uint rx10y7 = 24;
constexpr uint rx10y8 = 25;
constexpr uint rx10y9 = 26;
constexpr uint rx11y0 = 27;
constexpr uint rx11y1 = 28;
constexpr uint rx11y10 = 29;
constexpr uint rx11y11 = 30;
constexpr uint rx11y12 = 31;
constexpr uint rx11y2 = 32;
constexpr uint rx11y3 = 33;
constexpr uint rx11y4 = 34;
constexpr uint rx11y5 = 35;
constexpr uint rx11y6 = 36;
constexpr uint rx11y7 = 37;
constexpr uint rx11y8 = 38;
constexpr uint rx11y9 = 39;
constexpr uint rx12y0 = 40;
constexpr uint rx12y1 = 41;
constexpr uint rx12y10 = 42;
constexpr uint rx12y11 = 43;
constexpr uint rx12y12 = 44;
constexpr uint rx12y2 = 45;
constexpr uint rx12y3 = 46;
constexpr uint rx12y4 = 47;
constexpr uint rx12y5 = 48;
constexpr uint rx12y6 = 49;
constexpr uint rx12y7 = 50;
constexpr uint rx12y8 = 51;
constexpr uint rx12y9 = 52;
constexpr uint rx1y0 = 53;
constexpr uint rx1y1 = 54;
constexpr uint rx1y10 = 55;
constexpr uint rx1y11 = 56;
constexpr uint rx1y12 = 57;
constexpr uint rx1y2 = 58;
constexpr uint rx1y3 = 59;
constexpr uint rx1y4 = 60;
constexpr uint rx1y5 = 61;
constexpr uint rx1y6 = 62;
constexpr uint rx1y7 = 63;
constexpr uint rx1y8 = 64;
constexpr uint rx1y9 = 65;
constexpr uint rx2y0 = 66;
constexpr uint rx2y1 = 67;
constexpr uint rx2y10 = 68;
constexpr uint rx2y11 = 69;
constexpr uint rx2y12 = 70;
constexpr uint rx2y2 = 71;
constexpr uint rx2y3 = 72;
constexpr uint rx2y4 = 73;
constexpr uint rx2y5 = 74;
constexpr uint rx2y6 = 75;
constexpr uint rx2y7 = 76;
constexpr uint rx2y8 = 77;
constexpr uint rx2y9 = 78;
constexpr uint rx3y0 = 79;
constexpr uint rx3y1 = 80;
constexpr uint rx3y10 = 81;
constexpr uint rx3y11 = 82;
constexpr uint rx3y12 = 83;
constexpr uint rx3y2 = 84;
constexpr uint rx3y3 = 85;
constexpr uint rx3y4 = 86;
constexpr uint rx3y5 = 87;
constexpr uint rx3y6 = 88;
constexpr uint rx3y7 = 89;
constexpr uint rx3y8 = 90;
constexpr uint rx3y9 = 91;
constexpr uint rx4y0 = 92;
constexpr uint rx4y1 = 93;
constexpr uint rx4y10 = 94;
constexpr uint rx4y11 = 95;
constexpr uint rx4y12 = 96;
constexpr uint rx4y2 = 97;
constexpr uint rx4y3 = 98;
constexpr uint rx4y4 = 99;
constexpr uint rx4y5 = 100;
constexpr uint rx4y6 = 101;
constexpr uint rx4y7 = 102;
constexpr uint rx4y8 = 103;
constexpr uint rx4y9 = 104;
constexpr uint rx5y0 = 105;
constexpr uint rx5y1 = 106;
constexpr uint rx5y10 = 107;
constexpr uint rx5y11 = 108;
constexpr uint rx5y12 = 109;
constexpr uint rx5y2 = 110;
constexpr uint rx5y3 = 111;
constexpr uint rx5y4 = 112;
constexpr uint rx5y5 = 113;
constexpr uint rx5y6 = 114;
constexpr uint rx5y7 = 115;
constexpr uint rx5y8 = 116;
constexpr uint rx5y9 = 117;
constexpr uint rx6y0 = 118;
constexpr uint rx6y1 = 119;
constexpr uint rx6y10 = 120;
constexpr uint rx6y11 = 121;
constexpr uint rx6y12 = 122;
constexpr uint rx6y2 = 123;
constexpr uint rx6y3 = 124;
constexpr uint rx6y4 = 125;
constexpr uint rx6y5 = 126;
constexpr uint rx6y6 = 127;
constexpr uint rx6y7 = 128;
constexpr uint rx6y8 = 129;
constexpr uint rx6y9 = 130;
constexpr uint rx7y0 = 131;
constexpr uint rx7y1 = 132;
constexpr uint rx7y10 = 133;
constexpr uint rx7y11 = 134;
constexpr uint rx7y12 = 135;
constexpr uint rx7y2 = 136;
constexpr uint rx7y3 = 137;
constexpr uint rx7y4 = 138;
constexpr uint rx7y5 = 139;
constexpr uint rx7y6 = 140;
constexpr uint rx7y7 = 141;
constexpr uint rx7y8 = 142;
constexpr uint rx7y9 = 143;
constexpr uint rx8y0 = 144;
constexpr uint rx8y1 = 145;
constexpr uint rx8y10 = 146;
constexpr uint rx8y11 = 147;
constexpr uint rx8y12 = 148;
constexpr uint rx8y2 = 149;
constexpr uint rx8y3 = 150;
constexpr uint rx8y4 = 151;
constexpr uint rx8y5 = 152;
constexpr uint rx8y6 = 153;
constexpr uint rx8y7 = 154;
constexpr uint rx8y8 = 155;
constexpr uint rx8y9 = 156;
constexpr uint rx9y0 = 157;
constexpr uint rx9y1 = 158;
constexpr uint rx9y10 = 159;
constexpr uint rx9y11 = 160;
constexpr uint rx9y12 = 161;
constexpr uint rx9y2 = 162;
constexpr uint rx9y3 = 163;
constexpr uint rx9y4 = 164;
constexpr uint rx9y5 = 165;
constexpr uint rx9y6 = 166;
constexpr uint rx9y7 = 167;
constexpr uint rx9y8 = 168;
constexpr uint rx9y9 = 169;
constexpr uint null = 0;
constexpr uint b = 1;
constexpr uint e = 2;
constexpr uint w = 3;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 170;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 170> direction_down = Arr<CoordOrNull, 170>{null,rx0y1,rx0y2,rx0y11,rx0y12,null,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx10y1,rx10y2,rx10y11,rx10y12,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx11y1,rx11y2,rx11y11,rx11y12,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx1y1,rx1y2,rx1y11,rx1y12,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx2y1,rx2y2,rx2y11,rx2y12,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx9y1,rx9y2,rx9y11,rx9y12,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,};
constexpr Arr<CoordOrNull, 170> direction_right = Arr<CoordOrNull, 170>{null,rx1y0,rx1y1,rx1y10,rx1y11,rx1y12,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,};
constexpr Arr<CoordOrNull, 170> direction_left = Arr<CoordOrNull, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx0y0,rx0y1,rx0y10,rx0y11,rx0y12,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx1y0,rx1y1,rx1y10,rx1y11,rx1y12,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,};
constexpr Arr<CoordOrNull, 170> direction_up = Arr<CoordOrNull, 170>{null,null,rx0y0,rx0y9,rx0y10,rx0y11,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,};
constexpr Arr<RbgType4, 170> RbgCoordMap1 = Arr<RbgType4, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx0y0,rx0y9,rx0y10,rx0y11,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,};
constexpr Arr<RbgType5, 170> RbgCoordMap2 = Arr<RbgType5, 170>{null,rx1y1,rx1y2,rx1y11,rx1y12,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx11y1,rx11y2,rx11y11,rx11y12,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y1,rx2y2,rx2y11,rx2y12,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx9y1,rx9y2,rx9y11,rx9y12,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,};
constexpr Arr<RbgType6, 170> RbgCoordMap3 = Arr<RbgType6, 170>{null,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,};
constexpr Arr<RbgType7, 170> RbgCoordMap4 = Arr<RbgType7, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y1,rx9y2,rx9y11,rx9y12,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx11y1,rx11y2,rx11y11,rx11y12,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx0y1,rx0y2,rx0y11,rx0y12,null,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx1y1,rx1y2,rx1y11,rx1y12,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx2y1,rx2y2,rx2y11,rx2y12,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,};
constexpr Arr<RbgType7, 170> __gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx8y2,rx8y3,rx8y12,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx10y2,rx10y3,rx10y12,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y2,rx0y3,rx0y12,null,null,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx1y2,rx1y3,rx1y12,null,null,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx2y2,rx2y3,rx2y12,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx3y2,rx3y3,rx3y12,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,};
constexpr Arr<RbgType7, 170> __gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx7y3,rx7y4,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y3,rx0y4,null,null,null,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx1y3,rx1y4,null,null,null,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx2y3,rx2y4,null,null,null,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx3y3,rx3y4,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx4y3,rx4y4,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,};
constexpr Arr<RbgType7, 170> __gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y4,rx6y5,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,rx7y4,rx7y5,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,rx8y4,rx8y5,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y4,rx0y5,null,null,null,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,null,rx1y4,rx1y5,null,null,null,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,null,rx2y4,rx2y5,null,null,null,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,null,rx3y4,rx3y5,null,null,null,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,null,rx4y4,rx4y5,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,null,rx5y4,rx5y5,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,};
constexpr Arr<RbgType7, 170> __gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y5,rx5y6,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,null,rx6y5,rx6y6,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,null,rx7y5,rx7y6,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y5,rx0y6,null,null,null,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,null,null,rx1y5,rx1y6,null,null,null,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,null,null,rx2y5,rx2y6,null,null,null,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,null,null,rx3y5,rx3y6,null,null,null,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,null,null,rx4y5,rx4y6,null,null,null,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,null,null,};
constexpr Arr<CoordOrNull, 170> __gen_direction_right_direction_right = Arr<CoordOrNull, 170>{null,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,};
constexpr Arr<CoordOrNull, 170> __gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 170>{null,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,};
constexpr Arr<CoordOrNull, 170> __gen_direction_right___gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 170>{null,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 170> __gen_direction_right___gen_direction_right___gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 170>{null,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType5, 170> __gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 170>{null,rx2y2,rx2y3,rx2y12,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx12y2,rx12y3,rx12y12,null,null,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y2,rx3y3,rx3y12,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx8y2,rx8y3,rx8y12,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx10y2,rx10y3,rx10y12,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx11y2,rx11y3,rx11y12,null,null,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,};
constexpr Arr<RbgType5, 170> __gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 170>{null,rx3y3,rx3y4,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx4y3,rx4y4,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx7y3,rx7y4,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx10y3,rx10y4,null,null,null,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx11y3,rx11y4,null,null,null,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx12y3,rx12y4,null,null,null,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,};
constexpr Arr<RbgType5, 170> __gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 170>{null,rx4y4,rx4y5,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y4,rx5y5,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,rx6y4,rx6y5,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,rx7y4,rx7y5,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,rx8y4,rx8y5,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,null,rx9y4,rx9y5,null,null,null,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,null,rx10y4,rx10y5,null,null,null,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,null,rx11y4,rx11y5,null,null,null,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,null,rx12y4,rx12y5,null,null,null,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<RbgType5, 170> __gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 170>{null,rx5y5,rx5y6,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y5,rx6y6,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,null,rx7y5,rx7y6,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,null,rx8y5,rx8y6,null,null,null,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,null,null,rx9y5,rx9y6,null,null,null,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,null,null,rx10y5,rx10y6,null,null,null,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,null,null,rx11y5,rx11y6,null,null,null,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,null,null,rx12y5,rx12y6,null,null,null,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
constexpr Arr<CoordOrNull, 170> __gen_direction_down_direction_down = Arr<CoordOrNull, 170>{null,rx0y2,rx0y3,rx0y12,null,null,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx10y2,rx10y3,rx10y12,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx11y2,rx11y3,rx11y12,null,null,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx12y2,rx12y3,rx12y12,null,null,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx1y2,rx1y3,rx1y12,null,null,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx2y2,rx2y3,rx2y12,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx3y2,rx3y3,rx3y12,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx8y2,rx8y3,rx8y12,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,};
constexpr Arr<CoordOrNull, 170> __gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 170>{null,rx0y3,rx0y4,null,null,null,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx10y3,rx10y4,null,null,null,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx11y3,rx11y4,null,null,null,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx12y3,rx12y4,null,null,null,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx1y3,rx1y4,null,null,null,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx2y3,rx2y4,null,null,null,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx3y3,rx3y4,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx4y3,rx4y4,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx7y3,rx7y4,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,};
constexpr Arr<CoordOrNull, 170> __gen_direction_down___gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 170>{null,rx0y4,rx0y5,null,null,null,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,null,rx10y4,rx10y5,null,null,null,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,null,rx11y4,rx11y5,null,null,null,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,null,rx12y4,rx12y5,null,null,null,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,null,rx1y4,rx1y5,null,null,null,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,null,rx2y4,rx2y5,null,null,null,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,null,rx3y4,rx3y5,null,null,null,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,null,rx4y4,rx4y5,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,null,rx5y4,rx5y5,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,rx6y4,rx6y5,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,rx7y4,rx7y5,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,rx8y4,rx8y5,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,null,rx9y4,rx9y5,null,null,null,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,null,};
constexpr Arr<CoordOrNull, 170> __gen_direction_down___gen_direction_down___gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 170>{null,rx0y5,rx0y6,null,null,null,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,null,null,rx10y5,rx10y6,null,null,null,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,null,null,rx11y5,rx11y6,null,null,null,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,null,null,rx12y5,rx12y6,null,null,null,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,null,null,rx1y5,rx1y6,null,null,null,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,null,null,rx2y5,rx2y6,null,null,null,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,null,null,rx3y5,rx3y6,null,null,null,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,null,null,rx4y5,rx4y6,null,null,null,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,null,null,rx5y5,rx5y6,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,null,null,rx6y5,rx6y6,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,null,null,rx7y5,rx7y6,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,null,null,rx8y5,rx8y6,null,null,null,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,null,null,rx9y5,rx9y6,null,null,null,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,null,null,};

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
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,};
CoordOrNull coord = rx0y0;
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
bool is_legal_172_178_172_172_178_178_172_178_172();
bool is_legal_172_178_172_172_178_178_172_178_175();
bool is_legal_172_178_172_172_178_178_172_178_178();
bool is_legal_187_188_187([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_188([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_190([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_192([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_201([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_204([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_207([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_210([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_220([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_224([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_235([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_239([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_243([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_247([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_257([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_259([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_268([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_271([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_274([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_277([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_287([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_291([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_302([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_306([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_310([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_314([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_349([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_350([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_351([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_352([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_353([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_355([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_356([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_357([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_106([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_109([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_112([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_115([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_125([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_129([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_140([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_144([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_148([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_152([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_26([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_28([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_30([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_346([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_347([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_348([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_354([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_366([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_367([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_368([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_369([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_39([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_42([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_45([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_48([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_58([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_62([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_73([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_77([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_81([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_85([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_95([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_97([[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_172([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_173([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_175([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_176([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_178([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_180([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_181([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_323([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_325([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_338([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_342([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_172([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_173([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_175([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_176([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_178([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_180([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_181([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_323([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_325([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_338([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_342([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_180([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_181([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_323([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_325([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_338([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_181_181_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_161([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_172([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_173([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_18([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_23([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_342([[maybe_unused]]RgCache& rgCache);
bool apply_any_19_19_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_338([[maybe_unused]]RgCache& rgCache);
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
state_cache_125.reset();
state_cache_129.reset();
state_cache_190.reset();
state_cache_192.reset();
state_cache_220.reset();
state_cache_224.reset();
state_cache_257.reset();
state_cache_259.reset();
state_cache_28.reset();
state_cache_287.reset();
state_cache_291.reset();
state_cache_30.reset();
state_cache_367.reset();
state_cache_369.reset();
state_cache_58.reset();
state_cache_62.reset();
state_cache_95.reset();
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
std::bitset<170> state_cache_125;
std::bitset<170> state_cache_129;
std::bitset<170> state_cache_190;
std::bitset<170> state_cache_192;
std::bitset<170> state_cache_220;
std::bitset<170> state_cache_224;
std::bitset<170> state_cache_257;
std::bitset<170> state_cache_259;
std::bitset<170> state_cache_28;
std::bitset<170> state_cache_287;
std::bitset<170> state_cache_291;
std::bitset<170> state_cache_30;
std::bitset<170> state_cache_367;
std::bitset<170> state_cache_369;
std::bitset<170> state_cache_58;
std::bitset<170> state_cache_62;
std::bitset<170> state_cache_95;
std::bitset<170> state_cache_97;
};


}  // namespace reasoner
