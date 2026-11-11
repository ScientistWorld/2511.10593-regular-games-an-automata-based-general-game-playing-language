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
using Board = Arr<Piece, 226>;
using Counters = Arr<RbgType1, 4>;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint rx0y0 = 1;
constexpr uint rx0y1 = 2;
constexpr uint rx0y10 = 3;
constexpr uint rx0y11 = 4;
constexpr uint rx0y12 = 5;
constexpr uint rx0y13 = 6;
constexpr uint rx0y14 = 7;
constexpr uint rx0y2 = 8;
constexpr uint rx0y3 = 9;
constexpr uint rx0y4 = 10;
constexpr uint rx0y5 = 11;
constexpr uint rx0y6 = 12;
constexpr uint rx0y7 = 13;
constexpr uint rx0y8 = 14;
constexpr uint rx0y9 = 15;
constexpr uint rx10y0 = 16;
constexpr uint rx10y1 = 17;
constexpr uint rx10y10 = 18;
constexpr uint rx10y11 = 19;
constexpr uint rx10y12 = 20;
constexpr uint rx10y13 = 21;
constexpr uint rx10y14 = 22;
constexpr uint rx10y2 = 23;
constexpr uint rx10y3 = 24;
constexpr uint rx10y4 = 25;
constexpr uint rx10y5 = 26;
constexpr uint rx10y6 = 27;
constexpr uint rx10y7 = 28;
constexpr uint rx10y8 = 29;
constexpr uint rx10y9 = 30;
constexpr uint rx11y0 = 31;
constexpr uint rx11y1 = 32;
constexpr uint rx11y10 = 33;
constexpr uint rx11y11 = 34;
constexpr uint rx11y12 = 35;
constexpr uint rx11y13 = 36;
constexpr uint rx11y14 = 37;
constexpr uint rx11y2 = 38;
constexpr uint rx11y3 = 39;
constexpr uint rx11y4 = 40;
constexpr uint rx11y5 = 41;
constexpr uint rx11y6 = 42;
constexpr uint rx11y7 = 43;
constexpr uint rx11y8 = 44;
constexpr uint rx11y9 = 45;
constexpr uint rx12y0 = 46;
constexpr uint rx12y1 = 47;
constexpr uint rx12y10 = 48;
constexpr uint rx12y11 = 49;
constexpr uint rx12y12 = 50;
constexpr uint rx12y13 = 51;
constexpr uint rx12y14 = 52;
constexpr uint rx12y2 = 53;
constexpr uint rx12y3 = 54;
constexpr uint rx12y4 = 55;
constexpr uint rx12y5 = 56;
constexpr uint rx12y6 = 57;
constexpr uint rx12y7 = 58;
constexpr uint rx12y8 = 59;
constexpr uint rx12y9 = 60;
constexpr uint rx13y0 = 61;
constexpr uint rx13y1 = 62;
constexpr uint rx13y10 = 63;
constexpr uint rx13y11 = 64;
constexpr uint rx13y12 = 65;
constexpr uint rx13y13 = 66;
constexpr uint rx13y14 = 67;
constexpr uint rx13y2 = 68;
constexpr uint rx13y3 = 69;
constexpr uint rx13y4 = 70;
constexpr uint rx13y5 = 71;
constexpr uint rx13y6 = 72;
constexpr uint rx13y7 = 73;
constexpr uint rx13y8 = 74;
constexpr uint rx13y9 = 75;
constexpr uint rx14y0 = 76;
constexpr uint rx14y1 = 77;
constexpr uint rx14y10 = 78;
constexpr uint rx14y11 = 79;
constexpr uint rx14y12 = 80;
constexpr uint rx14y13 = 81;
constexpr uint rx14y14 = 82;
constexpr uint rx14y2 = 83;
constexpr uint rx14y3 = 84;
constexpr uint rx14y4 = 85;
constexpr uint rx14y5 = 86;
constexpr uint rx14y6 = 87;
constexpr uint rx14y7 = 88;
constexpr uint rx14y8 = 89;
constexpr uint rx14y9 = 90;
constexpr uint rx1y0 = 91;
constexpr uint rx1y1 = 92;
constexpr uint rx1y10 = 93;
constexpr uint rx1y11 = 94;
constexpr uint rx1y12 = 95;
constexpr uint rx1y13 = 96;
constexpr uint rx1y14 = 97;
constexpr uint rx1y2 = 98;
constexpr uint rx1y3 = 99;
constexpr uint rx1y4 = 100;
constexpr uint rx1y5 = 101;
constexpr uint rx1y6 = 102;
constexpr uint rx1y7 = 103;
constexpr uint rx1y8 = 104;
constexpr uint rx1y9 = 105;
constexpr uint rx2y0 = 106;
constexpr uint rx2y1 = 107;
constexpr uint rx2y10 = 108;
constexpr uint rx2y11 = 109;
constexpr uint rx2y12 = 110;
constexpr uint rx2y13 = 111;
constexpr uint rx2y14 = 112;
constexpr uint rx2y2 = 113;
constexpr uint rx2y3 = 114;
constexpr uint rx2y4 = 115;
constexpr uint rx2y5 = 116;
constexpr uint rx2y6 = 117;
constexpr uint rx2y7 = 118;
constexpr uint rx2y8 = 119;
constexpr uint rx2y9 = 120;
constexpr uint rx3y0 = 121;
constexpr uint rx3y1 = 122;
constexpr uint rx3y10 = 123;
constexpr uint rx3y11 = 124;
constexpr uint rx3y12 = 125;
constexpr uint rx3y13 = 126;
constexpr uint rx3y14 = 127;
constexpr uint rx3y2 = 128;
constexpr uint rx3y3 = 129;
constexpr uint rx3y4 = 130;
constexpr uint rx3y5 = 131;
constexpr uint rx3y6 = 132;
constexpr uint rx3y7 = 133;
constexpr uint rx3y8 = 134;
constexpr uint rx3y9 = 135;
constexpr uint rx4y0 = 136;
constexpr uint rx4y1 = 137;
constexpr uint rx4y10 = 138;
constexpr uint rx4y11 = 139;
constexpr uint rx4y12 = 140;
constexpr uint rx4y13 = 141;
constexpr uint rx4y14 = 142;
constexpr uint rx4y2 = 143;
constexpr uint rx4y3 = 144;
constexpr uint rx4y4 = 145;
constexpr uint rx4y5 = 146;
constexpr uint rx4y6 = 147;
constexpr uint rx4y7 = 148;
constexpr uint rx4y8 = 149;
constexpr uint rx4y9 = 150;
constexpr uint rx5y0 = 151;
constexpr uint rx5y1 = 152;
constexpr uint rx5y10 = 153;
constexpr uint rx5y11 = 154;
constexpr uint rx5y12 = 155;
constexpr uint rx5y13 = 156;
constexpr uint rx5y14 = 157;
constexpr uint rx5y2 = 158;
constexpr uint rx5y3 = 159;
constexpr uint rx5y4 = 160;
constexpr uint rx5y5 = 161;
constexpr uint rx5y6 = 162;
constexpr uint rx5y7 = 163;
constexpr uint rx5y8 = 164;
constexpr uint rx5y9 = 165;
constexpr uint rx6y0 = 166;
constexpr uint rx6y1 = 167;
constexpr uint rx6y10 = 168;
constexpr uint rx6y11 = 169;
constexpr uint rx6y12 = 170;
constexpr uint rx6y13 = 171;
constexpr uint rx6y14 = 172;
constexpr uint rx6y2 = 173;
constexpr uint rx6y3 = 174;
constexpr uint rx6y4 = 175;
constexpr uint rx6y5 = 176;
constexpr uint rx6y6 = 177;
constexpr uint rx6y7 = 178;
constexpr uint rx6y8 = 179;
constexpr uint rx6y9 = 180;
constexpr uint rx7y0 = 181;
constexpr uint rx7y1 = 182;
constexpr uint rx7y10 = 183;
constexpr uint rx7y11 = 184;
constexpr uint rx7y12 = 185;
constexpr uint rx7y13 = 186;
constexpr uint rx7y14 = 187;
constexpr uint rx7y2 = 188;
constexpr uint rx7y3 = 189;
constexpr uint rx7y4 = 190;
constexpr uint rx7y5 = 191;
constexpr uint rx7y6 = 192;
constexpr uint rx7y7 = 193;
constexpr uint rx7y8 = 194;
constexpr uint rx7y9 = 195;
constexpr uint rx8y0 = 196;
constexpr uint rx8y1 = 197;
constexpr uint rx8y10 = 198;
constexpr uint rx8y11 = 199;
constexpr uint rx8y12 = 200;
constexpr uint rx8y13 = 201;
constexpr uint rx8y14 = 202;
constexpr uint rx8y2 = 203;
constexpr uint rx8y3 = 204;
constexpr uint rx8y4 = 205;
constexpr uint rx8y5 = 206;
constexpr uint rx8y6 = 207;
constexpr uint rx8y7 = 208;
constexpr uint rx8y8 = 209;
constexpr uint rx8y9 = 210;
constexpr uint rx9y0 = 211;
constexpr uint rx9y1 = 212;
constexpr uint rx9y10 = 213;
constexpr uint rx9y11 = 214;
constexpr uint rx9y12 = 215;
constexpr uint rx9y13 = 216;
constexpr uint rx9y14 = 217;
constexpr uint rx9y2 = 218;
constexpr uint rx9y3 = 219;
constexpr uint rx9y4 = 220;
constexpr uint rx9y5 = 221;
constexpr uint rx9y6 = 222;
constexpr uint rx9y7 = 223;
constexpr uint rx9y8 = 224;
constexpr uint rx9y9 = 225;
constexpr uint null = 0;
constexpr uint b = 1;
constexpr uint e = 2;
constexpr uint w = 3;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint nan = 226;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<CoordOrNull, 226> direction_down = Arr<CoordOrNull, 226>{null,rx0y1,rx0y2,rx0y11,rx0y12,rx0y13,rx0y14,null,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx10y1,rx10y2,rx10y11,rx10y12,rx10y13,rx10y14,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx11y1,rx11y2,rx11y11,rx11y12,rx11y13,rx11y14,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,rx12y13,rx12y14,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx13y1,rx13y2,rx13y11,rx13y12,rx13y13,rx13y14,null,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx14y1,rx14y2,rx14y11,rx14y12,rx14y13,rx14y14,null,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx1y1,rx1y2,rx1y11,rx1y12,rx1y13,rx1y14,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx2y1,rx2y2,rx2y11,rx2y12,rx2y13,rx2y14,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,rx3y13,rx3y14,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,rx4y13,rx4y14,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,rx5y13,rx5y14,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,rx6y13,rx6y14,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,rx7y13,rx7y14,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,rx8y13,rx8y14,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx9y1,rx9y2,rx9y11,rx9y12,rx9y13,rx9y14,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,};
constexpr Arr<CoordOrNull, 226> direction_right = Arr<CoordOrNull, 226>{null,rx1y0,rx1y1,rx1y10,rx1y11,rx1y12,rx1y13,rx1y14,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx14y0,rx14y1,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y13,rx2y14,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,};
constexpr Arr<CoordOrNull, 226> direction_left = Arr<CoordOrNull, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx0y0,rx0y1,rx0y10,rx0y11,rx0y12,rx0y13,rx0y14,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx1y0,rx1y1,rx1y10,rx1y11,rx1y12,rx1y13,rx1y14,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y13,rx2y14,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,};
constexpr Arr<CoordOrNull, 226> direction_up = Arr<CoordOrNull, 226>{null,null,rx0y0,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx13y0,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y1,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,null,rx14y0,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx14y1,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,};
constexpr Arr<RbgType4, 226> RbgCoordMap1 = Arr<RbgType4, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx13y0,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y1,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,null,rx0y0,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,};
constexpr Arr<RbgType5, 226> RbgCoordMap2 = Arr<RbgType5, 226>{null,rx1y1,rx1y2,rx1y11,rx1y12,rx1y13,rx1y14,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx11y1,rx11y2,rx11y11,rx11y12,rx11y13,rx11y14,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,rx12y13,rx12y14,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx13y1,rx13y2,rx13y11,rx13y12,rx13y13,rx13y14,null,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx14y1,rx14y2,rx14y11,rx14y12,rx14y13,rx14y14,null,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y1,rx2y2,rx2y11,rx2y12,rx2y13,rx2y14,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,rx3y13,rx3y14,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,rx4y13,rx4y14,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,rx5y13,rx5y14,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,rx6y13,rx6y14,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,rx7y13,rx7y14,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,rx8y13,rx8y14,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx9y1,rx9y2,rx9y11,rx9y12,rx9y13,rx9y14,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,rx10y13,rx10y14,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,};
constexpr Arr<RbgType6, 226> RbgCoordMap3 = Arr<RbgType6, 226>{null,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx13y0,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y1,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,null,rx14y0,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx14y1,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,};
constexpr Arr<RbgType7, 226> RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y1,rx9y2,rx9y11,rx9y12,rx9y13,rx9y14,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,rx10y13,rx10y14,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx11y1,rx11y2,rx11y11,rx11y12,rx11y13,rx11y14,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,rx12y13,rx12y14,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx13y1,rx13y2,rx13y11,rx13y12,rx13y13,rx13y14,null,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx0y1,rx0y2,rx0y11,rx0y12,rx0y13,rx0y14,null,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx1y1,rx1y2,rx1y11,rx1y12,rx1y13,rx1y14,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx2y1,rx2y2,rx2y11,rx2y12,rx2y13,rx2y14,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,rx3y13,rx3y14,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,rx4y13,rx4y14,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,rx5y13,rx5y14,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,rx6y13,rx6y14,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,rx7y13,rx7y14,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,rx8y13,rx8y14,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,};
constexpr Arr<RbgType7, 226> __gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx8y2,rx8y3,rx8y12,rx8y13,rx8y14,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,rx9y13,rx9y14,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx10y2,rx10y3,rx10y12,rx10y13,rx10y14,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx11y2,rx11y3,rx11y12,rx11y13,rx11y14,null,null,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx12y2,rx12y3,rx12y12,rx12y13,rx12y14,null,null,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y2,rx0y3,rx0y12,rx0y13,rx0y14,null,null,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx1y2,rx1y3,rx1y12,rx1y13,rx1y14,null,null,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx2y2,rx2y3,rx2y12,rx2y13,rx2y14,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx3y2,rx3y3,rx3y12,rx3y13,rx3y14,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,rx4y13,rx4y14,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,rx5y13,rx5y14,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,rx6y13,rx6y14,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,rx7y13,rx7y14,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,};
constexpr Arr<RbgType7, 226> __gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx7y3,rx7y4,rx7y13,rx7y14,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,rx8y13,rx8y14,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,rx9y13,rx9y14,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx10y3,rx10y4,rx10y13,rx10y14,null,null,null,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx11y3,rx11y4,rx11y13,rx11y14,null,null,null,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y3,rx0y4,rx0y13,rx0y14,null,null,null,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx1y3,rx1y4,rx1y13,rx1y14,null,null,null,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx2y3,rx2y4,rx2y13,rx2y14,null,null,null,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx3y3,rx3y4,rx3y13,rx3y14,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx4y3,rx4y4,rx4y13,rx4y14,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,rx5y13,rx5y14,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,rx6y13,rx6y14,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,};
constexpr Arr<RbgType7, 226> __gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y4,rx6y5,rx6y14,null,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx7y4,rx7y5,rx7y14,null,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx8y4,rx8y5,rx8y14,null,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx9y4,rx9y5,rx9y14,null,null,null,null,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx10y4,rx10y5,rx10y14,null,null,null,null,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y4,rx0y5,rx0y14,null,null,null,null,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx1y4,rx1y5,rx1y14,null,null,null,null,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx2y4,rx2y5,rx2y14,null,null,null,null,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx3y4,rx3y5,rx3y14,null,null,null,null,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx4y4,rx4y5,rx4y14,null,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx5y4,rx5y5,rx5y14,null,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,};
constexpr Arr<RbgType7, 226> __gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y5,rx5y6,null,null,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx6y5,rx6y6,null,null,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx7y5,rx7y6,null,null,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx8y5,rx8y6,null,null,null,null,null,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx9y5,rx9y6,null,null,null,null,null,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx0y5,rx0y6,null,null,null,null,null,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx0y14,rx1y5,rx1y6,null,null,null,null,null,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y14,rx2y5,rx2y6,null,null,null,null,null,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y14,rx3y5,rx3y6,null,null,null,null,null,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx4y5,rx4y6,null,null,null,null,null,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,};
constexpr Arr<CoordOrNull, 226> __gen_direction_right_direction_right = Arr<CoordOrNull, 226>{null,rx2y0,rx2y1,rx2y10,rx2y11,rx2y12,rx2y13,rx2y14,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx14y0,rx14y1,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,};
constexpr Arr<CoordOrNull, 226> __gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 226>{null,rx3y0,rx3y1,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx14y0,rx14y1,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,};
constexpr Arr<CoordOrNull, 226> __gen_direction_right___gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 226>{null,rx4y0,rx4y1,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx14y0,rx14y1,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,};
constexpr Arr<CoordOrNull, 226> __gen_direction_right___gen_direction_right___gen_direction_right___gen_direction_right_direction_right = Arr<CoordOrNull, 226>{null,rx5y0,rx5y1,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y0,rx6y1,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx7y0,rx7y1,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx8y0,rx8y1,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx9y0,rx9y1,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx10y0,rx10y1,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx11y0,rx11y1,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx12y0,rx12y1,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx13y0,rx13y1,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx14y0,rx14y1,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,};
constexpr Arr<RbgType5, 226> __gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 226>{null,rx2y2,rx2y3,rx2y12,rx2y13,rx2y14,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx12y2,rx12y3,rx12y12,rx12y13,rx12y14,null,null,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx13y2,rx13y3,rx13y12,rx13y13,rx13y14,null,null,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx14y2,rx14y3,rx14y12,rx14y13,rx14y14,null,null,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx3y2,rx3y3,rx3y12,rx3y13,rx3y14,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,rx4y13,rx4y14,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,rx5y13,rx5y14,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,rx6y13,rx6y14,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,rx7y13,rx7y14,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx8y2,rx8y3,rx8y12,rx8y13,rx8y14,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,rx9y13,rx9y14,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx10y2,rx10y3,rx10y12,rx10y13,rx10y14,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx11y2,rx11y3,rx11y12,rx11y13,rx11y14,null,null,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,};
constexpr Arr<RbgType5, 226> __gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 226>{null,rx3y3,rx3y4,rx3y13,rx3y14,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx13y3,rx13y4,rx13y13,rx13y14,null,null,null,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx14y3,rx14y4,rx14y13,rx14y14,null,null,null,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx4y3,rx4y4,rx4y13,rx4y14,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,rx5y13,rx5y14,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,rx6y13,rx6y14,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx7y3,rx7y4,rx7y13,rx7y14,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,rx8y13,rx8y14,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,rx9y13,rx9y14,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx10y3,rx10y4,rx10y13,rx10y14,null,null,null,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx11y3,rx11y4,rx11y13,rx11y14,null,null,null,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx12y3,rx12y4,rx12y13,rx12y14,null,null,null,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,};
constexpr Arr<RbgType5, 226> __gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 226>{null,rx4y4,rx4y5,rx4y14,null,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx14y4,rx14y5,rx14y14,null,null,null,null,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx5y4,rx5y5,rx5y14,null,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx6y4,rx6y5,rx6y14,null,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx7y4,rx7y5,rx7y14,null,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx8y4,rx8y5,rx8y14,null,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx9y4,rx9y5,rx9y14,null,null,null,null,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx10y4,rx10y5,rx10y14,null,null,null,null,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx11y4,rx11y5,rx11y14,null,null,null,null,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx12y4,rx12y5,rx12y14,null,null,null,null,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx13y4,rx13y5,rx13y14,null,null,null,null,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,};
constexpr Arr<RbgType5, 226> __gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2 = Arr<RbgType5, 226>{null,rx5y5,rx5y6,null,null,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx6y5,rx6y6,null,null,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx7y5,rx7y6,null,null,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx8y5,rx8y6,null,null,null,null,null,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx9y5,rx9y6,null,null,null,null,null,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,rx10y5,rx10y6,null,null,null,null,null,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx11y5,rx11y6,null,null,null,null,null,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx12y5,rx12y6,null,null,null,null,null,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx13y5,rx13y6,null,null,null,null,null,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx14y5,rx14y6,null,null,null,null,null,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,};
constexpr Arr<CoordOrNull, 226> __gen_direction_down_direction_down = Arr<CoordOrNull, 226>{null,rx0y2,rx0y3,rx0y12,rx0y13,rx0y14,null,null,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx10y2,rx10y3,rx10y12,rx10y13,rx10y14,null,null,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx11y2,rx11y3,rx11y12,rx11y13,rx11y14,null,null,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx12y2,rx12y3,rx12y12,rx12y13,rx12y14,null,null,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx13y2,rx13y3,rx13y12,rx13y13,rx13y14,null,null,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx14y2,rx14y3,rx14y12,rx14y13,rx14y14,null,null,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx1y2,rx1y3,rx1y12,rx1y13,rx1y14,null,null,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx2y2,rx2y3,rx2y12,rx2y13,rx2y14,null,null,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx3y2,rx3y3,rx3y12,rx3y13,rx3y14,null,null,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx4y2,rx4y3,rx4y12,rx4y13,rx4y14,null,null,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx5y2,rx5y3,rx5y12,rx5y13,rx5y14,null,null,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx6y2,rx6y3,rx6y12,rx6y13,rx6y14,null,null,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx7y2,rx7y3,rx7y12,rx7y13,rx7y14,null,null,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx8y2,rx8y3,rx8y12,rx8y13,rx8y14,null,null,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx9y2,rx9y3,rx9y12,rx9y13,rx9y14,null,null,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,};
constexpr Arr<CoordOrNull, 226> __gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 226>{null,rx0y3,rx0y4,rx0y13,rx0y14,null,null,null,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx10y3,rx10y4,rx10y13,rx10y14,null,null,null,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx11y3,rx11y4,rx11y13,rx11y14,null,null,null,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx12y3,rx12y4,rx12y13,rx12y14,null,null,null,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx13y3,rx13y4,rx13y13,rx13y14,null,null,null,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx14y3,rx14y4,rx14y13,rx14y14,null,null,null,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,rx1y3,rx1y4,rx1y13,rx1y14,null,null,null,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx2y3,rx2y4,rx2y13,rx2y14,null,null,null,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx3y3,rx3y4,rx3y13,rx3y14,null,null,null,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx4y3,rx4y4,rx4y13,rx4y14,null,null,null,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx5y3,rx5y4,rx5y13,rx5y14,null,null,null,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx6y3,rx6y4,rx6y13,rx6y14,null,null,null,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx7y3,rx7y4,rx7y13,rx7y14,null,null,null,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx8y3,rx8y4,rx8y13,rx8y14,null,null,null,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx9y3,rx9y4,rx9y13,rx9y14,null,null,null,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,};
constexpr Arr<CoordOrNull, 226> __gen_direction_down___gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 226>{null,rx0y4,rx0y5,rx0y14,null,null,null,null,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx10y4,rx10y5,rx10y14,null,null,null,null,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx11y4,rx11y5,rx11y14,null,null,null,null,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx12y4,rx12y5,rx12y14,null,null,null,null,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx13y4,rx13y5,rx13y14,null,null,null,null,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx14y4,rx14y5,rx14y14,null,null,null,null,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx1y4,rx1y5,rx1y14,null,null,null,null,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx2y4,rx2y5,rx2y14,null,null,null,null,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx3y4,rx3y5,rx3y14,null,null,null,null,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx4y4,rx4y5,rx4y14,null,null,null,null,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx5y4,rx5y5,rx5y14,null,null,null,null,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx6y4,rx6y5,rx6y14,null,null,null,null,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx7y4,rx7y5,rx7y14,null,null,null,null,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx8y4,rx8y5,rx8y14,null,null,null,null,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx9y4,rx9y5,rx9y14,null,null,null,null,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,};
constexpr Arr<CoordOrNull, 226> __gen_direction_down___gen_direction_down___gen_direction_down___gen_direction_down_direction_down = Arr<CoordOrNull, 226>{null,rx0y5,rx0y6,null,null,null,null,null,rx0y7,rx0y8,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx0y14,rx10y5,rx10y6,null,null,null,null,null,rx10y7,rx10y8,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y14,rx11y5,rx11y6,null,null,null,null,null,rx11y7,rx11y8,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y14,rx12y5,rx12y6,null,null,null,null,null,rx12y7,rx12y8,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y14,rx13y5,rx13y6,null,null,null,null,null,rx13y7,rx13y8,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y14,rx14y5,rx14y6,null,null,null,null,null,rx14y7,rx14y8,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx14y14,rx1y5,rx1y6,null,null,null,null,null,rx1y7,rx1y8,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y14,rx2y5,rx2y6,null,null,null,null,null,rx2y7,rx2y8,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y14,rx3y5,rx3y6,null,null,null,null,null,rx3y7,rx3y8,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y14,rx4y5,rx4y6,null,null,null,null,null,rx4y7,rx4y8,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y14,rx5y5,rx5y6,null,null,null,null,null,rx5y7,rx5y8,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y14,rx6y5,rx6y6,null,null,null,null,null,rx6y7,rx6y8,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y14,rx7y5,rx7y6,null,null,null,null,null,rx7y7,rx7y8,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y14,rx8y5,rx8y6,null,null,null,null,null,rx8y7,rx8y8,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y14,rx9y5,rx9y6,null,null,null,null,null,rx9y7,rx9y8,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y14,};

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
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,};
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
std::bitset<226> state_cache_125;
std::bitset<226> state_cache_129;
std::bitset<226> state_cache_190;
std::bitset<226> state_cache_192;
std::bitset<226> state_cache_220;
std::bitset<226> state_cache_224;
std::bitset<226> state_cache_257;
std::bitset<226> state_cache_259;
std::bitset<226> state_cache_28;
std::bitset<226> state_cache_287;
std::bitset<226> state_cache_291;
std::bitset<226> state_cache_30;
std::bitset<226> state_cache_367;
std::bitset<226> state_cache_369;
std::bitset<226> state_cache_58;
std::bitset<226> state_cache_62;
std::bitset<226> state_cache_95;
std::bitset<226> state_cache_97;
};


}  // namespace reasoner
