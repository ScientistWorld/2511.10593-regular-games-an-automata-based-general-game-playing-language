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
constexpr Arr<RbgType2, 226> math_decr_226 = Arr<RbgType2, 226>{nan,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,};
constexpr Arr<RbgType2, 226> math_incr_226 = Arr<RbgType2, 226>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,nan,};
constexpr Arr<RbgType4, 226> RbgCoordMap1 = Arr<RbgType4, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx13y0,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y1,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,null,rx0y0,rx0y9,rx0y10,rx0y11,rx0y12,rx0y13,rx0y1,rx0y2,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,};
constexpr Arr<RbgType5, 226> RbgCoordMap2 = Arr<RbgType5, 226>{null,rx1y1,rx1y2,rx1y11,rx1y12,rx1y13,rx1y14,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx11y1,rx11y2,rx11y11,rx11y12,rx11y13,rx11y14,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,rx12y13,rx12y14,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx13y1,rx13y2,rx13y11,rx13y12,rx13y13,rx13y14,null,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx14y1,rx14y2,rx14y11,rx14y12,rx14y13,rx14y14,null,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,rx14y9,rx14y10,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y1,rx2y2,rx2y11,rx2y12,rx2y13,rx2y14,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,rx3y13,rx3y14,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,rx4y13,rx4y14,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,rx5y13,rx5y14,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,rx6y13,rx6y14,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,rx7y13,rx7y14,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,rx8y13,rx8y14,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,rx9y1,rx9y2,rx9y11,rx9y12,rx9y13,rx9y14,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,rx10y13,rx10y14,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,};
constexpr Arr<RbgType6, 226> RbgCoordMap3 = Arr<RbgType6, 226>{null,null,rx1y0,rx1y9,rx1y10,rx1y11,rx1y12,rx1y13,rx1y1,rx1y2,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,null,rx11y0,rx11y9,rx11y10,rx11y11,rx11y12,rx11y13,rx11y1,rx11y2,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,null,rx12y0,rx12y9,rx12y10,rx12y11,rx12y12,rx12y13,rx12y1,rx12y2,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,null,rx13y0,rx13y9,rx13y10,rx13y11,rx13y12,rx13y13,rx13y1,rx13y2,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,null,rx14y0,rx14y9,rx14y10,rx14y11,rx14y12,rx14y13,rx14y1,rx14y2,rx14y3,rx14y4,rx14y5,rx14y6,rx14y7,rx14y8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx2y0,rx2y9,rx2y10,rx2y11,rx2y12,rx2y13,rx2y1,rx2y2,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,null,rx3y0,rx3y9,rx3y10,rx3y11,rx3y12,rx3y13,rx3y1,rx3y2,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,null,rx4y0,rx4y9,rx4y10,rx4y11,rx4y12,rx4y13,rx4y1,rx4y2,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,null,rx5y0,rx5y9,rx5y10,rx5y11,rx5y12,rx5y13,rx5y1,rx5y2,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,null,rx6y0,rx6y9,rx6y10,rx6y11,rx6y12,rx6y13,rx6y1,rx6y2,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,null,rx7y0,rx7y9,rx7y10,rx7y11,rx7y12,rx7y13,rx7y1,rx7y2,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,null,rx8y0,rx8y9,rx8y10,rx8y11,rx8y12,rx8y13,rx8y1,rx8y2,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,null,rx9y0,rx9y9,rx9y10,rx9y11,rx9y12,rx9y13,rx9y1,rx9y2,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,null,rx10y0,rx10y9,rx10y10,rx10y11,rx10y12,rx10y13,rx10y1,rx10y2,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,};
constexpr Arr<RbgType7, 226> RbgCoordMap4 = Arr<RbgType7, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,rx9y1,rx9y2,rx9y11,rx9y12,rx9y13,rx9y14,null,rx9y3,rx9y4,rx9y5,rx9y6,rx9y7,rx9y8,rx9y9,rx9y10,rx10y1,rx10y2,rx10y11,rx10y12,rx10y13,rx10y14,null,rx10y3,rx10y4,rx10y5,rx10y6,rx10y7,rx10y8,rx10y9,rx10y10,rx11y1,rx11y2,rx11y11,rx11y12,rx11y13,rx11y14,null,rx11y3,rx11y4,rx11y5,rx11y6,rx11y7,rx11y8,rx11y9,rx11y10,rx12y1,rx12y2,rx12y11,rx12y12,rx12y13,rx12y14,null,rx12y3,rx12y4,rx12y5,rx12y6,rx12y7,rx12y8,rx12y9,rx12y10,rx13y1,rx13y2,rx13y11,rx13y12,rx13y13,rx13y14,null,rx13y3,rx13y4,rx13y5,rx13y6,rx13y7,rx13y8,rx13y9,rx13y10,rx0y1,rx0y2,rx0y11,rx0y12,rx0y13,rx0y14,null,rx0y3,rx0y4,rx0y5,rx0y6,rx0y7,rx0y8,rx0y9,rx0y10,rx1y1,rx1y2,rx1y11,rx1y12,rx1y13,rx1y14,null,rx1y3,rx1y4,rx1y5,rx1y6,rx1y7,rx1y8,rx1y9,rx1y10,rx2y1,rx2y2,rx2y11,rx2y12,rx2y13,rx2y14,null,rx2y3,rx2y4,rx2y5,rx2y6,rx2y7,rx2y8,rx2y9,rx2y10,rx3y1,rx3y2,rx3y11,rx3y12,rx3y13,rx3y14,null,rx3y3,rx3y4,rx3y5,rx3y6,rx3y7,rx3y8,rx3y9,rx3y10,rx4y1,rx4y2,rx4y11,rx4y12,rx4y13,rx4y14,null,rx4y3,rx4y4,rx4y5,rx4y6,rx4y7,rx4y8,rx4y9,rx4y10,rx5y1,rx5y2,rx5y11,rx5y12,rx5y13,rx5y14,null,rx5y3,rx5y4,rx5y5,rx5y6,rx5y7,rx5y8,rx5y9,rx5y10,rx6y1,rx6y2,rx6y11,rx6y12,rx6y13,rx6y14,null,rx6y3,rx6y4,rx6y5,rx6y6,rx6y7,rx6y8,rx6y9,rx6y10,rx7y1,rx7y2,rx7y11,rx7y12,rx7y13,rx7y14,null,rx7y3,rx7y4,rx7y5,rx7y6,rx7y7,rx7y8,rx7y9,rx7y10,rx8y1,rx8y2,rx8y11,rx8y12,rx8y13,rx8y14,null,rx8y3,rx8y4,rx8y5,rx8y6,rx8y7,rx8y8,rx8y9,rx8y10,};

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
Board board = Board{null,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,};
CoordOrNull coord = rx0y0;
Coord coord_temp = rx0y0;
Counters counters = Counters{0,0,225,0,};
Goals goals = Goals{0,0,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 405;

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
return currentState == 406;
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
bool is_legal_101_102_101();
bool is_legal_101_102_102();
bool is_legal_101_102_103();
bool is_legal_101_102_104();
bool is_legal_101_102_105();
bool is_legal_10_16_10_10_16_16_10_16_10();
bool is_legal_10_16_10_10_16_16_10_16_13();
bool is_legal_10_16_10_10_16_16_10_16_14();
bool is_legal_10_16_10_10_16_16_10_16_16();
bool is_legal_10_16_10_10_16_16_10_16_17();
bool is_legal_119_120_119();
bool is_legal_119_120_120();
bool is_legal_119_120_121();
bool is_legal_119_120_122();
bool is_legal_119_120_123();
bool is_legal_132_133_132();
bool is_legal_132_133_133();
bool is_legal_132_133_134();
bool is_legal_132_133_135();
bool is_legal_132_133_136();
bool is_legal_132_133_137();
bool is_legal_155_156_155();
bool is_legal_155_156_156();
bool is_legal_155_156_157();
bool is_legal_155_156_158();
bool is_legal_155_156_159();
bool is_legal_155_156_160();
bool is_legal_15_169_15_15_169_169_15_169_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_161([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_162([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_163([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_164([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_165([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_166([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_167([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_169([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_170([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_18([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_169_15_15_169_169_15_169_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_15([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_173([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_174([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_18([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_19([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_20([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_21([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_22([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_23([[maybe_unused]]RgCache& rgCache);
bool is_legal_15_173_15_15_173_173_15_173_24([[maybe_unused]]RgCache& rgCache);
bool is_legal_172_178_172_172_178_178_172_178_172();
bool is_legal_172_178_172_172_178_178_172_178_175();
bool is_legal_172_178_172_172_178_178_172_178_176();
bool is_legal_172_178_172_172_178_178_172_178_178();
bool is_legal_172_178_172_172_178_178_172_178_179();
bool is_legal_177_11_177_177_11_11_177_11_11([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_12([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_177([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_180([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_181([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_182([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_183([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_184([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_185([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_186([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_8([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_11_177_177_11_11_177_11_9([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_177([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_180([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_181([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_182([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_183([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_184([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_323([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_324([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_325([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_326([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_327([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_328([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_329([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_331([[maybe_unused]]RgCache& rgCache);
bool is_legal_177_331_177_177_331_331_177_331_332([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_187([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_188([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_189([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_190([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_191([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_192([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_193([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_194([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_195([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_201([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_202([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_203([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_204([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_205([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_206([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_207([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_208([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_209([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_210([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_211([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_212([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_213([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_219([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_220([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_221([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_222([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_223([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_224([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_225([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_226([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_233([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_234([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_235([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_236([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_237([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_238([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_239([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_240([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_241([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_242([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_243([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_244([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_245([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_246([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_247([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_248([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_249([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_256([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_257([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_258([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_259([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_260([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_261([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_262([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_268([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_269([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_270([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_271([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_272([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_273([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_274([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_275([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_276([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_277([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_278([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_279([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_280([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_286([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_287([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_288([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_289([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_290([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_291([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_292([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_293([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_300([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_301([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_302([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_303([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_304([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_305([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_306([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_307([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_308([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_309([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_310([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_311([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_312([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_313([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_314([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_315([[maybe_unused]]RgCache& rgCache);
bool is_legal_187_188_316([[maybe_unused]]RgCache& rgCache);
bool is_legal_196_197_196();
bool is_legal_196_197_197();
bool is_legal_196_197_198();
bool is_legal_196_197_199();
bool is_legal_196_197_200();
bool is_legal_214_215_214();
bool is_legal_214_215_215();
bool is_legal_214_215_216();
bool is_legal_214_215_217();
bool is_legal_214_215_218();
bool is_legal_227_228_227();
bool is_legal_227_228_228();
bool is_legal_227_228_229();
bool is_legal_227_228_230();
bool is_legal_227_228_231();
bool is_legal_227_228_232();
bool is_legal_25_26_100([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_106([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_107([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_108([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_109([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_110([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_111([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_112([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_113([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_114([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_115([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_116([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_117([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_118([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_124([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_125([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_126([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_127([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_128([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_129([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_130([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_131([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_138([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_139([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_140([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_141([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_142([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_143([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_144([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_145([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_146([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_147([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_148([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_149([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_150([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_151([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_152([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_153([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_154([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_25([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_26([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_27([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_28([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_29([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_30([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_31([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_32([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_33([[maybe_unused]]RgCache& rgCache);
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
bool is_legal_25_26_57([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_58([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_59([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_60([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_61([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_62([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_63([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_64([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_71([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_72([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_73([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_74([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_75([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_76([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_77([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_78([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_79([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_80([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_81([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_82([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_83([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_84([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_85([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_86([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_87([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_94([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_95([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_96([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_97([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_98([[maybe_unused]]RgCache& rgCache);
bool is_legal_25_26_99([[maybe_unused]]RgCache& rgCache);
bool is_legal_250_251_250();
bool is_legal_250_251_251();
bool is_legal_250_251_252();
bool is_legal_250_251_253();
bool is_legal_250_251_254();
bool is_legal_250_251_255();
bool is_legal_263_264_263();
bool is_legal_263_264_264();
bool is_legal_263_264_265();
bool is_legal_263_264_266();
bool is_legal_263_264_267();
bool is_legal_281_282_281();
bool is_legal_281_282_282();
bool is_legal_281_282_283();
bool is_legal_281_282_284();
bool is_legal_281_282_285();
bool is_legal_294_295_294();
bool is_legal_294_295_295();
bool is_legal_294_295_296();
bool is_legal_294_295_297();
bool is_legal_294_295_298();
bool is_legal_294_295_299();
bool is_legal_317_318_317();
bool is_legal_317_318_318();
bool is_legal_317_318_319();
bool is_legal_317_318_320();
bool is_legal_317_318_321();
bool is_legal_317_318_322();
bool is_legal_334_335_334([[maybe_unused]]RgCache& rgCache);
bool is_legal_334_335_335([[maybe_unused]]RgCache& rgCache);
bool is_legal_336_337_336([[maybe_unused]]RgCache& rgCache);
bool is_legal_336_337_337([[maybe_unused]]RgCache& rgCache);
bool is_legal_34_35_34();
bool is_legal_34_35_35();
bool is_legal_34_35_36();
bool is_legal_34_35_37();
bool is_legal_34_35_38();
bool is_legal_52_53_52();
bool is_legal_52_53_53();
bool is_legal_52_53_54();
bool is_legal_52_53_55();
bool is_legal_52_53_56();
bool is_legal_65_66_65();
bool is_legal_65_66_66();
bool is_legal_65_66_67();
bool is_legal_65_66_68();
bool is_legal_65_66_69();
bool is_legal_65_66_70();
bool is_legal_88_89_88();
bool is_legal_88_89_89();
bool is_legal_88_89_90();
bool is_legal_88_89_91();
bool is_legal_88_89_92();
bool is_legal_88_89_93();
void state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_167([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_169([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_170([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_172([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_173([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_174([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_175([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_176([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_177([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_178([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_179([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_180([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_181([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_182([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_183([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_184([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_185([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_186([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_323([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_324([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_325([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_326([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_327([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_328([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_329([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_331([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_332([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_338([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_339([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_340([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_341([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_342([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_343([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_344([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
void state_345([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache);
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
bool apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_167([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_169([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_170([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_172([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_173([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_174([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_175([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_176([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_177([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_178([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_179([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_180([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_181([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_182([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_183([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_184([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_185([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_186([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_323([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_324([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_325([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_326([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_327([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_328([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_329([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_331([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_332([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_338([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_339([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_340([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_341([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_342([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_343([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_344([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_345([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_15([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_161([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_162([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_163([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_164([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_165([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_166([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_167([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_169([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_170([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_172([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_173([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_174([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_18([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_19([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_20([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_21([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_22([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_23([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_24([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_342([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_343([[maybe_unused]]RgCache& rgCache);
bool apply_any_15_15_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_177([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_180([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_181([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_182([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_183([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_184([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_185([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_186([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_323([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_324([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_325([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_326([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_327([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_328([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_329([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_331([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_332([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_338([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_339([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_8([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_9([[maybe_unused]]RgCache& rgCache);
bool apply_any_177_177_end([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_1([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_12([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_3([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_338([[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_339([[maybe_unused]]RgCache& rgCache);
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
state_cache_125.reset();
state_cache_129.reset();
state_cache_190.reset();
state_cache_193.reset();
state_cache_220.reset();
state_cache_224.reset();
state_cache_257.reset();
state_cache_260.reset();
state_cache_28.reset();
state_cache_287.reset();
state_cache_291.reset();
state_cache_31.reset();
state_cache_58.reset();
state_cache_62.reset();
state_cache_95.reset();
state_cache_98.reset();
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
std::bitset<226> state_cache_193;
std::bitset<226> state_cache_220;
std::bitset<226> state_cache_224;
std::bitset<226> state_cache_257;
std::bitset<226> state_cache_260;
std::bitset<226> state_cache_28;
std::bitset<226> state_cache_287;
std::bitset<226> state_cache_291;
std::bitset<226> state_cache_31;
std::bitset<226> state_cache_58;
std::bitset<226> state_cache_62;
std::bitset<226> state_cache_95;
std::bitset<226> state_cache_98;
};


}  // namespace reasoner
