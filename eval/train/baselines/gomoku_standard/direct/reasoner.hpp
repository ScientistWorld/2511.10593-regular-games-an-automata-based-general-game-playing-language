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

using Piece = uint;
using Player = uint;
using Position = uint;
using PositionOrNull = uint;
using Score = uint;
using Bool = uint;
using PlayerOrSystem = uint;
using Goals = Arr<Score, 2>;
using Visibility = Arr<Bool, 2>;

constexpr uint empty = 0;
constexpr uint border = 1;
constexpr uint white = 2;
constexpr uint black = 3;
constexpr uint keeper = 0;
constexpr uint random = 1;
constexpr uint V__10_1 = 0;
constexpr uint V__10_10 = 1;
constexpr uint V__10_11 = 2;
constexpr uint V__10_12 = 3;
constexpr uint V__10_13 = 4;
constexpr uint V__10_14 = 5;
constexpr uint V__10_15 = 6;
constexpr uint V__10_2 = 7;
constexpr uint V__10_3 = 8;
constexpr uint V__10_4 = 9;
constexpr uint V__10_5 = 10;
constexpr uint V__10_6 = 11;
constexpr uint V__10_7 = 12;
constexpr uint V__10_8 = 13;
constexpr uint V__10_9 = 14;
constexpr uint V__11_1 = 15;
constexpr uint V__11_10 = 16;
constexpr uint V__11_11 = 17;
constexpr uint V__11_12 = 18;
constexpr uint V__11_13 = 19;
constexpr uint V__11_14 = 20;
constexpr uint V__11_15 = 21;
constexpr uint V__11_2 = 22;
constexpr uint V__11_3 = 23;
constexpr uint V__11_4 = 24;
constexpr uint V__11_5 = 25;
constexpr uint V__11_6 = 26;
constexpr uint V__11_7 = 27;
constexpr uint V__11_8 = 28;
constexpr uint V__11_9 = 29;
constexpr uint V__12_1 = 30;
constexpr uint V__12_10 = 31;
constexpr uint V__12_11 = 32;
constexpr uint V__12_12 = 33;
constexpr uint V__12_13 = 34;
constexpr uint V__12_14 = 35;
constexpr uint V__12_15 = 36;
constexpr uint V__12_2 = 37;
constexpr uint V__12_3 = 38;
constexpr uint V__12_4 = 39;
constexpr uint V__12_5 = 40;
constexpr uint V__12_6 = 41;
constexpr uint V__12_7 = 42;
constexpr uint V__12_8 = 43;
constexpr uint V__12_9 = 44;
constexpr uint V__13_1 = 45;
constexpr uint V__13_10 = 46;
constexpr uint V__13_11 = 47;
constexpr uint V__13_12 = 48;
constexpr uint V__13_13 = 49;
constexpr uint V__13_14 = 50;
constexpr uint V__13_15 = 51;
constexpr uint V__13_2 = 52;
constexpr uint V__13_3 = 53;
constexpr uint V__13_4 = 54;
constexpr uint V__13_5 = 55;
constexpr uint V__13_6 = 56;
constexpr uint V__13_7 = 57;
constexpr uint V__13_8 = 58;
constexpr uint V__13_9 = 59;
constexpr uint V__14_1 = 60;
constexpr uint V__14_10 = 61;
constexpr uint V__14_11 = 62;
constexpr uint V__14_12 = 63;
constexpr uint V__14_13 = 64;
constexpr uint V__14_14 = 65;
constexpr uint V__14_15 = 66;
constexpr uint V__14_2 = 67;
constexpr uint V__14_3 = 68;
constexpr uint V__14_4 = 69;
constexpr uint V__14_5 = 70;
constexpr uint V__14_6 = 71;
constexpr uint V__14_7 = 72;
constexpr uint V__14_8 = 73;
constexpr uint V__14_9 = 74;
constexpr uint V__15_1 = 75;
constexpr uint V__15_10 = 76;
constexpr uint V__15_11 = 77;
constexpr uint V__15_12 = 78;
constexpr uint V__15_13 = 79;
constexpr uint V__15_14 = 80;
constexpr uint V__15_15 = 81;
constexpr uint V__15_2 = 82;
constexpr uint V__15_3 = 83;
constexpr uint V__15_4 = 84;
constexpr uint V__15_5 = 85;
constexpr uint V__15_6 = 86;
constexpr uint V__15_7 = 87;
constexpr uint V__15_8 = 88;
constexpr uint V__15_9 = 89;
constexpr uint V__1_1 = 90;
constexpr uint V__1_10 = 91;
constexpr uint V__1_11 = 92;
constexpr uint V__1_12 = 93;
constexpr uint V__1_13 = 94;
constexpr uint V__1_14 = 95;
constexpr uint V__1_15 = 96;
constexpr uint V__1_2 = 97;
constexpr uint V__1_3 = 98;
constexpr uint V__1_4 = 99;
constexpr uint V__1_5 = 100;
constexpr uint V__1_6 = 101;
constexpr uint V__1_7 = 102;
constexpr uint V__1_8 = 103;
constexpr uint V__1_9 = 104;
constexpr uint V__2_1 = 105;
constexpr uint V__2_10 = 106;
constexpr uint V__2_11 = 107;
constexpr uint V__2_12 = 108;
constexpr uint V__2_13 = 109;
constexpr uint V__2_14 = 110;
constexpr uint V__2_15 = 111;
constexpr uint V__2_2 = 112;
constexpr uint V__2_3 = 113;
constexpr uint V__2_4 = 114;
constexpr uint V__2_5 = 115;
constexpr uint V__2_6 = 116;
constexpr uint V__2_7 = 117;
constexpr uint V__2_8 = 118;
constexpr uint V__2_9 = 119;
constexpr uint V__3_1 = 120;
constexpr uint V__3_10 = 121;
constexpr uint V__3_11 = 122;
constexpr uint V__3_12 = 123;
constexpr uint V__3_13 = 124;
constexpr uint V__3_14 = 125;
constexpr uint V__3_15 = 126;
constexpr uint V__3_2 = 127;
constexpr uint V__3_3 = 128;
constexpr uint V__3_4 = 129;
constexpr uint V__3_5 = 130;
constexpr uint V__3_6 = 131;
constexpr uint V__3_7 = 132;
constexpr uint V__3_8 = 133;
constexpr uint V__3_9 = 134;
constexpr uint V__4_1 = 135;
constexpr uint V__4_10 = 136;
constexpr uint V__4_11 = 137;
constexpr uint V__4_12 = 138;
constexpr uint V__4_13 = 139;
constexpr uint V__4_14 = 140;
constexpr uint V__4_15 = 141;
constexpr uint V__4_2 = 142;
constexpr uint V__4_3 = 143;
constexpr uint V__4_4 = 144;
constexpr uint V__4_5 = 145;
constexpr uint V__4_6 = 146;
constexpr uint V__4_7 = 147;
constexpr uint V__4_8 = 148;
constexpr uint V__4_9 = 149;
constexpr uint V__5_1 = 150;
constexpr uint V__5_10 = 151;
constexpr uint V__5_11 = 152;
constexpr uint V__5_12 = 153;
constexpr uint V__5_13 = 154;
constexpr uint V__5_14 = 155;
constexpr uint V__5_15 = 156;
constexpr uint V__5_2 = 157;
constexpr uint V__5_3 = 158;
constexpr uint V__5_4 = 159;
constexpr uint V__5_5 = 160;
constexpr uint V__5_6 = 161;
constexpr uint V__5_7 = 162;
constexpr uint V__5_8 = 163;
constexpr uint V__5_9 = 164;
constexpr uint V__6_1 = 165;
constexpr uint V__6_10 = 166;
constexpr uint V__6_11 = 167;
constexpr uint V__6_12 = 168;
constexpr uint V__6_13 = 169;
constexpr uint V__6_14 = 170;
constexpr uint V__6_15 = 171;
constexpr uint V__6_2 = 172;
constexpr uint V__6_3 = 173;
constexpr uint V__6_4 = 174;
constexpr uint V__6_5 = 175;
constexpr uint V__6_6 = 176;
constexpr uint V__6_7 = 177;
constexpr uint V__6_8 = 178;
constexpr uint V__6_9 = 179;
constexpr uint V__7_1 = 180;
constexpr uint V__7_10 = 181;
constexpr uint V__7_11 = 182;
constexpr uint V__7_12 = 183;
constexpr uint V__7_13 = 184;
constexpr uint V__7_14 = 185;
constexpr uint V__7_15 = 186;
constexpr uint V__7_2 = 187;
constexpr uint V__7_3 = 188;
constexpr uint V__7_4 = 189;
constexpr uint V__7_5 = 190;
constexpr uint V__7_6 = 191;
constexpr uint V__7_7 = 192;
constexpr uint V__7_8 = 193;
constexpr uint V__7_9 = 194;
constexpr uint V__8_1 = 195;
constexpr uint V__8_10 = 196;
constexpr uint V__8_11 = 197;
constexpr uint V__8_12 = 198;
constexpr uint V__8_13 = 199;
constexpr uint V__8_14 = 200;
constexpr uint V__8_15 = 201;
constexpr uint V__8_2 = 202;
constexpr uint V__8_3 = 203;
constexpr uint V__8_4 = 204;
constexpr uint V__8_5 = 205;
constexpr uint V__8_6 = 206;
constexpr uint V__8_7 = 207;
constexpr uint V__8_8 = 208;
constexpr uint V__8_9 = 209;
constexpr uint V__9_1 = 210;
constexpr uint V__9_10 = 211;
constexpr uint V__9_11 = 212;
constexpr uint V__9_12 = 213;
constexpr uint V__9_13 = 214;
constexpr uint V__9_14 = 215;
constexpr uint V__9_15 = 216;
constexpr uint V__9_2 = 217;
constexpr uint V__9_3 = 218;
constexpr uint V__9_4 = 219;
constexpr uint V__9_5 = 220;
constexpr uint V__9_6 = 221;
constexpr uint V__9_7 = 222;
constexpr uint V__9_8 = 223;
constexpr uint V__9_9 = 224;
constexpr uint null = 225;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<PositionOrNull, 226> up = Arr<PositionOrNull, 226>{V__10_2,V__10_11,V__10_12,V__10_13,V__10_14,V__10_15,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,V__11_2,V__11_11,V__11_12,V__11_13,V__11_14,V__11_15,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,V__12_14,V__12_15,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,V__13_2,V__13_11,V__13_12,V__13_13,V__13_14,V__13_15,null,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__13_10,V__14_2,V__14_11,V__14_12,V__14_13,V__14_14,V__14_15,null,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,V__14_9,V__14_10,V__15_2,V__15_11,V__15_12,V__15_13,V__15_14,V__15_15,null,V__15_3,V__15_4,V__15_5,V__15_6,V__15_7,V__15_8,V__15_9,V__15_10,V__1_2,V__1_11,V__1_12,V__1_13,V__1_14,V__1_15,null,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__1_10,V__2_2,V__2_11,V__2_12,V__2_13,V__2_14,V__2_15,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,V__3_14,V__3_15,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,V__4_14,V__4_15,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,V__5_14,V__5_15,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,V__6_14,V__6_15,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,V__7_14,V__7_15,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,V__8_14,V__8_15,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,V__9_2,V__9_11,V__9_12,V__9_13,V__9_14,V__9_15,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,null,};
constexpr Arr<PositionOrNull, 226> right = Arr<PositionOrNull, 226>{V__11_1,V__11_10,V__11_11,V__11_12,V__11_13,V__11_14,V__11_15,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__12_1,V__12_10,V__12_11,V__12_12,V__12_13,V__12_14,V__12_15,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__13_1,V__13_10,V__13_11,V__13_12,V__13_13,V__13_14,V__13_15,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__14_1,V__14_10,V__14_11,V__14_12,V__14_13,V__14_14,V__14_15,V__14_2,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,V__14_9,V__15_1,V__15_10,V__15_11,V__15_12,V__15_13,V__15_14,V__15_15,V__15_2,V__15_3,V__15_4,V__15_5,V__15_6,V__15_7,V__15_8,V__15_9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_1,V__2_10,V__2_11,V__2_12,V__2_13,V__2_14,V__2_15,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_10,V__3_11,V__3_12,V__3_13,V__3_14,V__3_15,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_10,V__4_11,V__4_12,V__4_13,V__4_14,V__4_15,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_10,V__5_11,V__5_12,V__5_13,V__5_14,V__5_15,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_10,V__6_11,V__6_12,V__6_13,V__6_14,V__6_15,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_10,V__7_11,V__7_12,V__7_13,V__7_14,V__7_15,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_10,V__8_11,V__8_12,V__8_13,V__8_14,V__8_15,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__9_1,V__9_10,V__9_11,V__9_12,V__9_13,V__9_14,V__9_15,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__10_1,V__10_10,V__10_11,V__10_12,V__10_13,V__10_14,V__10_15,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,null,};
constexpr Arr<PositionOrNull, 226> down = Arr<PositionOrNull, 226>{null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_13,V__10_14,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_13,V__11_14,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_13,V__12_14,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,V__13_9,V__13_10,V__13_11,V__13_12,V__13_13,V__13_14,V__13_1,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,null,V__14_9,V__14_10,V__14_11,V__14_12,V__14_13,V__14_14,V__14_1,V__14_2,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,null,V__15_9,V__15_10,V__15_11,V__15_12,V__15_13,V__15_14,V__15_1,V__15_2,V__15_3,V__15_4,V__15_5,V__15_6,V__15_7,V__15_8,null,V__1_9,V__1_10,V__1_11,V__1_12,V__1_13,V__1_14,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_13,V__2_14,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_13,V__3_14,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_13,V__4_14,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_13,V__5_14,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_13,V__6_14,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_13,V__7_14,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_13,V__8_14,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_13,V__9_14,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,};
constexpr Arr<PositionOrNull, 226> left = Arr<PositionOrNull, 226>{V__9_1,V__9_10,V__9_11,V__9_12,V__9_13,V__9_14,V__9_15,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__10_1,V__10_10,V__10_11,V__10_12,V__10_13,V__10_14,V__10_15,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__11_1,V__11_10,V__11_11,V__11_12,V__11_13,V__11_14,V__11_15,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__12_1,V__12_10,V__12_11,V__12_12,V__12_13,V__12_14,V__12_15,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__13_1,V__13_10,V__13_11,V__13_12,V__13_13,V__13_14,V__13_15,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__14_1,V__14_10,V__14_11,V__14_12,V__14_13,V__14_14,V__14_15,V__14_2,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,V__14_9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_1,V__1_10,V__1_11,V__1_12,V__1_13,V__1_14,V__1_15,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__2_1,V__2_10,V__2_11,V__2_12,V__2_13,V__2_14,V__2_15,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_10,V__3_11,V__3_12,V__3_13,V__3_14,V__3_15,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_10,V__4_11,V__4_12,V__4_13,V__4_14,V__4_15,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_10,V__5_11,V__5_12,V__5_13,V__5_14,V__5_15,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_10,V__6_11,V__6_12,V__6_13,V__6_14,V__6_15,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_10,V__7_11,V__7_12,V__7_13,V__7_14,V__7_15,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_10,V__8_11,V__8_12,V__8_13,V__8_14,V__8_15,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,};
constexpr Arr<PositionOrNull, 226> upLeft = Arr<PositionOrNull, 226>{V__9_2,V__9_11,V__9_12,V__9_13,V__9_14,V__9_15,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,V__10_2,V__10_11,V__10_12,V__10_13,V__10_14,V__10_15,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,V__11_2,V__11_11,V__11_12,V__11_13,V__11_14,V__11_15,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,V__12_14,V__12_15,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,V__13_2,V__13_11,V__13_12,V__13_13,V__13_14,V__13_15,null,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__13_10,V__14_2,V__14_11,V__14_12,V__14_13,V__14_14,V__14_15,null,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,V__14_9,V__14_10,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_2,V__1_11,V__1_12,V__1_13,V__1_14,V__1_15,null,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__1_10,V__2_2,V__2_11,V__2_12,V__2_13,V__2_14,V__2_15,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,V__3_14,V__3_15,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,V__4_14,V__4_15,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,V__5_14,V__5_15,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,V__6_14,V__6_15,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,V__7_14,V__7_15,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,V__8_14,V__8_15,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,null,};
constexpr Arr<PositionOrNull, 226> upRight = Arr<PositionOrNull, 226>{V__11_2,V__11_11,V__11_12,V__11_13,V__11_14,V__11_15,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,V__12_14,V__12_15,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,V__13_2,V__13_11,V__13_12,V__13_13,V__13_14,V__13_15,null,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__13_10,V__14_2,V__14_11,V__14_12,V__14_13,V__14_14,V__14_15,null,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,V__14_9,V__14_10,V__15_2,V__15_11,V__15_12,V__15_13,V__15_14,V__15_15,null,V__15_3,V__15_4,V__15_5,V__15_6,V__15_7,V__15_8,V__15_9,V__15_10,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_2,V__2_11,V__2_12,V__2_13,V__2_14,V__2_15,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,V__3_14,V__3_15,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,V__4_14,V__4_15,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,V__5_14,V__5_15,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,V__6_14,V__6_15,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,V__7_14,V__7_15,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,V__8_14,V__8_15,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,V__9_2,V__9_11,V__9_12,V__9_13,V__9_14,V__9_15,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,V__10_2,V__10_11,V__10_12,V__10_13,V__10_14,V__10_15,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,null,};
constexpr Arr<PositionOrNull, 226> downLeft = Arr<PositionOrNull, 226>{null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_13,V__9_14,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_13,V__10_14,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_13,V__11_14,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_13,V__12_14,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,V__13_9,V__13_10,V__13_11,V__13_12,V__13_13,V__13_14,V__13_1,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,null,V__14_9,V__14_10,V__14_11,V__14_12,V__14_13,V__14_14,V__14_1,V__14_2,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_9,V__1_10,V__1_11,V__1_12,V__1_13,V__1_14,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_13,V__2_14,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_13,V__3_14,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_13,V__4_14,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_13,V__5_14,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_13,V__6_14,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_13,V__7_14,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_13,V__8_14,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,};
constexpr Arr<PositionOrNull, 226> downRight = Arr<PositionOrNull, 226>{null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_13,V__11_14,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_13,V__12_14,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,V__13_9,V__13_10,V__13_11,V__13_12,V__13_13,V__13_14,V__13_1,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,null,V__14_9,V__14_10,V__14_11,V__14_12,V__14_13,V__14_14,V__14_1,V__14_2,V__14_3,V__14_4,V__14_5,V__14_6,V__14_7,V__14_8,null,V__15_9,V__15_10,V__15_11,V__15_12,V__15_13,V__15_14,V__15_1,V__15_2,V__15_3,V__15_4,V__15_5,V__15_6,V__15_7,V__15_8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_13,V__2_14,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_13,V__3_14,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_13,V__4_14,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_13,V__5_14,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_13,V__6_14,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_13,V__7_14,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_13,V__8_14,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_13,V__9_14,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_13,V__10_14,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,};

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
Arr<Piece, 226> board = Arr<Piece, 226>{empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,border,};
PositionOrNull pos = null;
Player turn_arg0_me = white;
Player turn_arg1_op = white;
Piece win_arg0_piece = empty;
Piece winInDir_arg0_piece = empty;
Arr<PositionOrNull, 226> winInDir_arg1_dir1 = Arr<PositionOrNull, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Arr<PositionOrNull, 226> winInDir_arg2_dir2 = Arr<PositionOrNull, 226>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Goals goals = Goals{50,50,};
PlayerOrSystem player = keeper;
Visibility visible = Visibility{1,1,};
uint currentState = 1;

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
return currentState == 2;
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
bool is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_1();
bool is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_1();
bool is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_2();
bool is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_begin();
bool is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_10();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_11();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_12();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_13();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_14();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_15();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_16();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_17();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_18();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_19();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_20();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_21();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_22();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_23();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_24();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_25();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_26();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_27();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_28();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_4();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_5();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_6();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_7();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_8();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_9();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_10();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_11();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_12();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_13();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_14();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_15();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_16();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_17();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_18();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_19();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_20();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_21();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_22();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_23();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_24();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_25();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_26();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_27();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_28();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_4();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_5();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_6();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_7();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_8();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_9();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_5();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_10();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_11();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_12();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_13();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_14();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_15();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_16();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_17();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_18();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_19();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_20();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_21();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_22();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_23();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_24();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_25();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_26();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_27();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_28();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_4();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_5();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_6();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_7();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_8();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_9();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_7();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_1();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_10();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_11();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_12();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_13();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_14();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_15();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_16();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_17();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_18();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_19();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_2();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_20();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_21();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_22();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_23();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_24();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_25();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_26();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_27();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_28();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_3();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_4();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_5();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_6();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_7();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_8();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_9();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_end();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_9();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin();
bool is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end();
bool is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_1();
bool is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_1();
bool is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_2();
bool is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_begin();
bool is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_10();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_11();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_12();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_13();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_14();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_15();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_16();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_17();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_18();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_19();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_20();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_21();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_22();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_23();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_24();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_25();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_26();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_27();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_28();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_4();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_5();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_6();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_7();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_8();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_9();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_10();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_11();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_12();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_13();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_14();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_15();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_16();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_17();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_18();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_19();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_20();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_21();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_22();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_23();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_24();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_25();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_26();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_27();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_28();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_4();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_5();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_6();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_7();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_8();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_9();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_5();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_10();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_11();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_12();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_13();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_14();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_15();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_16();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_17();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_18();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_19();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_20();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_21();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_22();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_23();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_24();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_25();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_26();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_27();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_28();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_4();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_5();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_6();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_7();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_8();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_9();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_7();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_1();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_10();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_11();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_12();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_13();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_14();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_15();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_16();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_17();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_18();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_19();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_2();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_20();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_21();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_22();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_23();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_24();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_25();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_26();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_27();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_28();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_3();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_4();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_5();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_6();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_7();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_8();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_9();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_end();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_9();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin();
bool is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end();
void state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
void state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr);
bool switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_3_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_5_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache);
bool apply_any_begin_begin_begin();
bool apply_any_begin_begin_rules_1();
bool apply_any_begin_begin_rules_3__1();
bool apply_any_begin_begin_rules_3__2();
bool apply_any_begin_begin_rules_3_turn_1();
bool apply_any_begin_begin_rules_3_turn_begin();
bool apply_any_begin_begin_rules_begin();
bool apply_any_rules_3_turn_5_rules_3_turn_5_end();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_13();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_4();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1();
bool apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin();
bool apply_any_rules_5_turn_5_rules_5_turn_5_end();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_13();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end();
bool apply_any_rules_5_turn_5_rules_5_turn_5_rules_6();
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
