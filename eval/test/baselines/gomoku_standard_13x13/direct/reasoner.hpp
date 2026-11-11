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
constexpr uint V__10_2 = 5;
constexpr uint V__10_3 = 6;
constexpr uint V__10_4 = 7;
constexpr uint V__10_5 = 8;
constexpr uint V__10_6 = 9;
constexpr uint V__10_7 = 10;
constexpr uint V__10_8 = 11;
constexpr uint V__10_9 = 12;
constexpr uint V__11_1 = 13;
constexpr uint V__11_10 = 14;
constexpr uint V__11_11 = 15;
constexpr uint V__11_12 = 16;
constexpr uint V__11_13 = 17;
constexpr uint V__11_2 = 18;
constexpr uint V__11_3 = 19;
constexpr uint V__11_4 = 20;
constexpr uint V__11_5 = 21;
constexpr uint V__11_6 = 22;
constexpr uint V__11_7 = 23;
constexpr uint V__11_8 = 24;
constexpr uint V__11_9 = 25;
constexpr uint V__12_1 = 26;
constexpr uint V__12_10 = 27;
constexpr uint V__12_11 = 28;
constexpr uint V__12_12 = 29;
constexpr uint V__12_13 = 30;
constexpr uint V__12_2 = 31;
constexpr uint V__12_3 = 32;
constexpr uint V__12_4 = 33;
constexpr uint V__12_5 = 34;
constexpr uint V__12_6 = 35;
constexpr uint V__12_7 = 36;
constexpr uint V__12_8 = 37;
constexpr uint V__12_9 = 38;
constexpr uint V__13_1 = 39;
constexpr uint V__13_10 = 40;
constexpr uint V__13_11 = 41;
constexpr uint V__13_12 = 42;
constexpr uint V__13_13 = 43;
constexpr uint V__13_2 = 44;
constexpr uint V__13_3 = 45;
constexpr uint V__13_4 = 46;
constexpr uint V__13_5 = 47;
constexpr uint V__13_6 = 48;
constexpr uint V__13_7 = 49;
constexpr uint V__13_8 = 50;
constexpr uint V__13_9 = 51;
constexpr uint V__1_1 = 52;
constexpr uint V__1_10 = 53;
constexpr uint V__1_11 = 54;
constexpr uint V__1_12 = 55;
constexpr uint V__1_13 = 56;
constexpr uint V__1_2 = 57;
constexpr uint V__1_3 = 58;
constexpr uint V__1_4 = 59;
constexpr uint V__1_5 = 60;
constexpr uint V__1_6 = 61;
constexpr uint V__1_7 = 62;
constexpr uint V__1_8 = 63;
constexpr uint V__1_9 = 64;
constexpr uint V__2_1 = 65;
constexpr uint V__2_10 = 66;
constexpr uint V__2_11 = 67;
constexpr uint V__2_12 = 68;
constexpr uint V__2_13 = 69;
constexpr uint V__2_2 = 70;
constexpr uint V__2_3 = 71;
constexpr uint V__2_4 = 72;
constexpr uint V__2_5 = 73;
constexpr uint V__2_6 = 74;
constexpr uint V__2_7 = 75;
constexpr uint V__2_8 = 76;
constexpr uint V__2_9 = 77;
constexpr uint V__3_1 = 78;
constexpr uint V__3_10 = 79;
constexpr uint V__3_11 = 80;
constexpr uint V__3_12 = 81;
constexpr uint V__3_13 = 82;
constexpr uint V__3_2 = 83;
constexpr uint V__3_3 = 84;
constexpr uint V__3_4 = 85;
constexpr uint V__3_5 = 86;
constexpr uint V__3_6 = 87;
constexpr uint V__3_7 = 88;
constexpr uint V__3_8 = 89;
constexpr uint V__3_9 = 90;
constexpr uint V__4_1 = 91;
constexpr uint V__4_10 = 92;
constexpr uint V__4_11 = 93;
constexpr uint V__4_12 = 94;
constexpr uint V__4_13 = 95;
constexpr uint V__4_2 = 96;
constexpr uint V__4_3 = 97;
constexpr uint V__4_4 = 98;
constexpr uint V__4_5 = 99;
constexpr uint V__4_6 = 100;
constexpr uint V__4_7 = 101;
constexpr uint V__4_8 = 102;
constexpr uint V__4_9 = 103;
constexpr uint V__5_1 = 104;
constexpr uint V__5_10 = 105;
constexpr uint V__5_11 = 106;
constexpr uint V__5_12 = 107;
constexpr uint V__5_13 = 108;
constexpr uint V__5_2 = 109;
constexpr uint V__5_3 = 110;
constexpr uint V__5_4 = 111;
constexpr uint V__5_5 = 112;
constexpr uint V__5_6 = 113;
constexpr uint V__5_7 = 114;
constexpr uint V__5_8 = 115;
constexpr uint V__5_9 = 116;
constexpr uint V__6_1 = 117;
constexpr uint V__6_10 = 118;
constexpr uint V__6_11 = 119;
constexpr uint V__6_12 = 120;
constexpr uint V__6_13 = 121;
constexpr uint V__6_2 = 122;
constexpr uint V__6_3 = 123;
constexpr uint V__6_4 = 124;
constexpr uint V__6_5 = 125;
constexpr uint V__6_6 = 126;
constexpr uint V__6_7 = 127;
constexpr uint V__6_8 = 128;
constexpr uint V__6_9 = 129;
constexpr uint V__7_1 = 130;
constexpr uint V__7_10 = 131;
constexpr uint V__7_11 = 132;
constexpr uint V__7_12 = 133;
constexpr uint V__7_13 = 134;
constexpr uint V__7_2 = 135;
constexpr uint V__7_3 = 136;
constexpr uint V__7_4 = 137;
constexpr uint V__7_5 = 138;
constexpr uint V__7_6 = 139;
constexpr uint V__7_7 = 140;
constexpr uint V__7_8 = 141;
constexpr uint V__7_9 = 142;
constexpr uint V__8_1 = 143;
constexpr uint V__8_10 = 144;
constexpr uint V__8_11 = 145;
constexpr uint V__8_12 = 146;
constexpr uint V__8_13 = 147;
constexpr uint V__8_2 = 148;
constexpr uint V__8_3 = 149;
constexpr uint V__8_4 = 150;
constexpr uint V__8_5 = 151;
constexpr uint V__8_6 = 152;
constexpr uint V__8_7 = 153;
constexpr uint V__8_8 = 154;
constexpr uint V__8_9 = 155;
constexpr uint V__9_1 = 156;
constexpr uint V__9_10 = 157;
constexpr uint V__9_11 = 158;
constexpr uint V__9_12 = 159;
constexpr uint V__9_13 = 160;
constexpr uint V__9_2 = 161;
constexpr uint V__9_3 = 162;
constexpr uint V__9_4 = 163;
constexpr uint V__9_5 = 164;
constexpr uint V__9_6 = 165;
constexpr uint V__9_7 = 166;
constexpr uint V__9_8 = 167;
constexpr uint V__9_9 = 168;
constexpr uint null = 169;

constexpr uint PLAYERS_COUNT = 2;
constexpr uint unusedTag = std::numeric_limits<uint>::max();
constexpr Arr<PositionOrNull, 170> up = Arr<PositionOrNull, 170>{V__10_2,V__10_11,V__10_12,V__10_13,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,V__11_2,V__11_11,V__11_12,V__11_13,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,V__13_2,V__13_11,V__13_12,V__13_13,null,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__13_10,V__1_2,V__1_11,V__1_12,V__1_13,null,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__1_10,V__2_2,V__2_11,V__2_12,V__2_13,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,V__9_2,V__9_11,V__9_12,V__9_13,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,null,};
constexpr Arr<PositionOrNull, 170> right = Arr<PositionOrNull, 170>{V__11_1,V__11_10,V__11_11,V__11_12,V__11_13,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__12_1,V__12_10,V__12_11,V__12_12,V__12_13,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__13_1,V__13_10,V__13_11,V__13_12,V__13_13,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_1,V__2_10,V__2_11,V__2_12,V__2_13,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_10,V__3_11,V__3_12,V__3_13,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_10,V__4_11,V__4_12,V__4_13,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_10,V__5_11,V__5_12,V__5_13,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_10,V__6_11,V__6_12,V__6_13,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_10,V__7_11,V__7_12,V__7_13,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_10,V__8_11,V__8_12,V__8_13,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__9_1,V__9_10,V__9_11,V__9_12,V__9_13,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__10_1,V__10_10,V__10_11,V__10_12,V__10_13,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,null,};
constexpr Arr<PositionOrNull, 170> down = Arr<PositionOrNull, 170>{null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,V__13_9,V__13_10,V__13_11,V__13_12,V__13_1,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,null,V__1_9,V__1_10,V__1_11,V__1_12,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,};
constexpr Arr<PositionOrNull, 170> left = Arr<PositionOrNull, 170>{V__9_1,V__9_10,V__9_11,V__9_12,V__9_13,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__10_1,V__10_10,V__10_11,V__10_12,V__10_13,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__11_1,V__11_10,V__11_11,V__11_12,V__11_13,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__12_1,V__12_10,V__12_11,V__12_12,V__12_13,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_1,V__1_10,V__1_11,V__1_12,V__1_13,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__2_1,V__2_10,V__2_11,V__2_12,V__2_13,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__3_1,V__3_10,V__3_11,V__3_12,V__3_13,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__4_1,V__4_10,V__4_11,V__4_12,V__4_13,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__5_1,V__5_10,V__5_11,V__5_12,V__5_13,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__6_1,V__6_10,V__6_11,V__6_12,V__6_13,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__7_1,V__7_10,V__7_11,V__7_12,V__7_13,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__8_1,V__8_10,V__8_11,V__8_12,V__8_13,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,null,};
constexpr Arr<PositionOrNull, 170> upLeft = Arr<PositionOrNull, 170>{V__9_2,V__9_11,V__9_12,V__9_13,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,V__10_2,V__10_11,V__10_12,V__10_13,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,V__11_2,V__11_11,V__11_12,V__11_13,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_2,V__1_11,V__1_12,V__1_13,null,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,V__1_9,V__1_10,V__2_2,V__2_11,V__2_12,V__2_13,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,null,};
constexpr Arr<PositionOrNull, 170> upRight = Arr<PositionOrNull, 170>{V__11_2,V__11_11,V__11_12,V__11_13,null,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,V__11_9,V__11_10,V__12_2,V__12_11,V__12_12,V__12_13,null,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,V__12_9,V__12_10,V__13_2,V__13_11,V__13_12,V__13_13,null,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,V__13_9,V__13_10,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_2,V__2_11,V__2_12,V__2_13,null,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,V__2_9,V__2_10,V__3_2,V__3_11,V__3_12,V__3_13,null,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,V__3_9,V__3_10,V__4_2,V__4_11,V__4_12,V__4_13,null,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,V__4_9,V__4_10,V__5_2,V__5_11,V__5_12,V__5_13,null,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,V__5_9,V__5_10,V__6_2,V__6_11,V__6_12,V__6_13,null,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,V__6_9,V__6_10,V__7_2,V__7_11,V__7_12,V__7_13,null,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,V__7_9,V__7_10,V__8_2,V__8_11,V__8_12,V__8_13,null,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,V__8_9,V__8_10,V__9_2,V__9_11,V__9_12,V__9_13,null,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,V__9_9,V__9_10,V__10_2,V__10_11,V__10_12,V__10_13,null,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,V__10_9,V__10_10,null,};
constexpr Arr<PositionOrNull, 170> downLeft = Arr<PositionOrNull, 170>{null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__1_9,V__1_10,V__1_11,V__1_12,V__1_1,V__1_2,V__1_3,V__1_4,V__1_5,V__1_6,V__1_7,V__1_8,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,};
constexpr Arr<PositionOrNull, 170> downRight = Arr<PositionOrNull, 170>{null,V__11_9,V__11_10,V__11_11,V__11_12,V__11_1,V__11_2,V__11_3,V__11_4,V__11_5,V__11_6,V__11_7,V__11_8,null,V__12_9,V__12_10,V__12_11,V__12_12,V__12_1,V__12_2,V__12_3,V__12_4,V__12_5,V__12_6,V__12_7,V__12_8,null,V__13_9,V__13_10,V__13_11,V__13_12,V__13_1,V__13_2,V__13_3,V__13_4,V__13_5,V__13_6,V__13_7,V__13_8,null,null,null,null,null,null,null,null,null,null,null,null,null,null,V__2_9,V__2_10,V__2_11,V__2_12,V__2_1,V__2_2,V__2_3,V__2_4,V__2_5,V__2_6,V__2_7,V__2_8,null,V__3_9,V__3_10,V__3_11,V__3_12,V__3_1,V__3_2,V__3_3,V__3_4,V__3_5,V__3_6,V__3_7,V__3_8,null,V__4_9,V__4_10,V__4_11,V__4_12,V__4_1,V__4_2,V__4_3,V__4_4,V__4_5,V__4_6,V__4_7,V__4_8,null,V__5_9,V__5_10,V__5_11,V__5_12,V__5_1,V__5_2,V__5_3,V__5_4,V__5_5,V__5_6,V__5_7,V__5_8,null,V__6_9,V__6_10,V__6_11,V__6_12,V__6_1,V__6_2,V__6_3,V__6_4,V__6_5,V__6_6,V__6_7,V__6_8,null,V__7_9,V__7_10,V__7_11,V__7_12,V__7_1,V__7_2,V__7_3,V__7_4,V__7_5,V__7_6,V__7_7,V__7_8,null,V__8_9,V__8_10,V__8_11,V__8_12,V__8_1,V__8_2,V__8_3,V__8_4,V__8_5,V__8_6,V__8_7,V__8_8,null,V__9_9,V__9_10,V__9_11,V__9_12,V__9_1,V__9_2,V__9_3,V__9_4,V__9_5,V__9_6,V__9_7,V__9_8,null,V__10_9,V__10_10,V__10_11,V__10_12,V__10_1,V__10_2,V__10_3,V__10_4,V__10_5,V__10_6,V__10_7,V__10_8,null,};

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
Arr<Piece, 170> board = Arr<Piece, 170>{empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,border,};
PositionOrNull pos = null;
Player turn_arg0_me = white;
Player turn_arg1_op = white;
Piece win_arg0_piece = empty;
Piece winInDir_arg0_piece = empty;
Arr<PositionOrNull, 170> winInDir_arg1_dir1 = Arr<PositionOrNull, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
Arr<PositionOrNull, 170> winInDir_arg2_dir2 = Arr<PositionOrNull, 170>{null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,};
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
