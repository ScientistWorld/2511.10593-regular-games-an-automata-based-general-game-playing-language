#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.win_arg0_piece) ^ hash(gameState.winInDir_arg0_piece) ^ hash(gameState.winInDir_arg1_dir1) ^ hash(gameState.winInDir_arg2_dir2) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.win_arg0_piece) ^ hash(gameState.winInDir_arg0_piece) ^ hash(gameState.winInDir_arg1_dir1) ^ hash(gameState.winInDir_arg2_dir2) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && turn_arg0_me==rhs.turn_arg0_me && turn_arg1_op==rhs.turn_arg1_op && win_arg0_piece==rhs.win_arg0_piece && winInDir_arg0_piece==rhs.winInDir_arg0_piece && winInDir_arg1_dir1==rhs.winInDir_arg1_dir1 && winInDir_arg2_dir2==rhs.winInDir_arg2_dir2 && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_6: " << board[V__1_6] << ", " << "V__1_7: " << board[V__1_7] << ", " << "V__1_8: " << board[V__1_8] << ", " << "V__1_9: " << board[V__1_9] << ", " << "V__1_10: " << board[V__1_10] << ", " << "V__1_11: " << board[V__1_11] << ", " << "V__1_12: " << board[V__1_12] << ", " << "V__1_13: " << board[V__1_13] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__2_7: " << board[V__2_7] << ", " << "V__2_8: " << board[V__2_8] << ", " << "V__2_9: " << board[V__2_9] << ", " << "V__2_10: " << board[V__2_10] << ", " << "V__2_11: " << board[V__2_11] << ", " << "V__2_12: " << board[V__2_12] << ", " << "V__2_13: " << board[V__2_13] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__3_8: " << board[V__3_8] << ", " << "V__3_9: " << board[V__3_9] << ", " << "V__3_10: " << board[V__3_10] << ", " << "V__3_11: " << board[V__3_11] << ", " << "V__3_12: " << board[V__3_12] << ", " << "V__3_13: " << board[V__3_13] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__4_7: " << board[V__4_7] << ", " << "V__4_8: " << board[V__4_8] << ", " << "V__4_9: " << board[V__4_9] << ", " << "V__4_10: " << board[V__4_10] << ", " << "V__4_11: " << board[V__4_11] << ", " << "V__4_12: " << board[V__4_12] << ", " << "V__4_13: " << board[V__4_13] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__5_8: " << board[V__5_8] << ", " << "V__5_9: " << board[V__5_9] << ", " << "V__5_10: " << board[V__5_10] << ", " << "V__5_11: " << board[V__5_11] << ", " << "V__5_12: " << board[V__5_12] << ", " << "V__5_13: " << board[V__5_13] << ", " << "V__6_1: " << board[V__6_1] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__6_7: " << board[V__6_7] << ", " << "V__6_8: " << board[V__6_8] << ", " << "V__6_9: " << board[V__6_9] << ", " << "V__6_10: " << board[V__6_10] << ", " << "V__6_11: " << board[V__6_11] << ", " << "V__6_12: " << board[V__6_12] << ", " << "V__6_13: " << board[V__6_13] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_2: " << board[V__7_2] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_6: " << board[V__7_6] << ", " << "V__7_7: " << board[V__7_7] << ", " << "V__7_8: " << board[V__7_8] << ", " << "V__7_9: " << board[V__7_9] << ", " << "V__7_10: " << board[V__7_10] << ", " << "V__7_11: " << board[V__7_11] << ", " << "V__7_12: " << board[V__7_12] << ", " << "V__7_13: " << board[V__7_13] << ", " << "V__8_1: " << board[V__8_1] << ", " << "V__8_2: " << board[V__8_2] << ", " << "V__8_3: " << board[V__8_3] << ", " << "V__8_4: " << board[V__8_4] << ", " << "V__8_5: " << board[V__8_5] << ", " << "V__8_6: " << board[V__8_6] << ", " << "V__8_7: " << board[V__8_7] << ", " << "V__8_8: " << board[V__8_8] << ", " << "V__8_9: " << board[V__8_9] << ", " << "V__8_10: " << board[V__8_10] << ", " << "V__8_11: " << board[V__8_11] << ", " << "V__8_12: " << board[V__8_12] << ", " << "V__8_13: " << board[V__8_13] << ", " << "V__9_1: " << board[V__9_1] << ", " << "V__9_2: " << board[V__9_2] << ", " << "V__9_3: " << board[V__9_3] << ", " << "V__9_4: " << board[V__9_4] << ", " << "V__9_5: " << board[V__9_5] << ", " << "V__9_6: " << board[V__9_6] << ", " << "V__9_7: " << board[V__9_7] << ", " << "V__9_8: " << board[V__9_8] << ", " << "V__9_9: " << board[V__9_9] << ", " << "V__9_10: " << board[V__9_10] << ", " << "V__9_11: " << board[V__9_11] << ", " << "V__9_12: " << board[V__9_12] << ", " << "V__9_13: " << board[V__9_13] << ", " << "V__10_1: " << board[V__10_1] << ", " << "V__10_2: " << board[V__10_2] << ", " << "V__10_3: " << board[V__10_3] << ", " << "V__10_4: " << board[V__10_4] << ", " << "V__10_5: " << board[V__10_5] << ", " << "V__10_6: " << board[V__10_6] << ", " << "V__10_7: " << board[V__10_7] << ", " << "V__10_8: " << board[V__10_8] << ", " << "V__10_9: " << board[V__10_9] << ", " << "V__10_10: " << board[V__10_10] << ", " << "V__10_11: " << board[V__10_11] << ", " << "V__10_12: " << board[V__10_12] << ", " << "V__10_13: " << board[V__10_13] << ", " << "V__11_1: " << board[V__11_1] << ", " << "V__11_2: " << board[V__11_2] << ", " << "V__11_3: " << board[V__11_3] << ", " << "V__11_4: " << board[V__11_4] << ", " << "V__11_5: " << board[V__11_5] << ", " << "V__11_6: " << board[V__11_6] << ", " << "V__11_7: " << board[V__11_7] << ", " << "V__11_8: " << board[V__11_8] << ", " << "V__11_9: " << board[V__11_9] << ", " << "V__11_10: " << board[V__11_10] << ", " << "V__11_11: " << board[V__11_11] << ", " << "V__11_12: " << board[V__11_12] << ", " << "V__11_13: " << board[V__11_13] << ", " << "V__12_1: " << board[V__12_1] << ", " << "V__12_2: " << board[V__12_2] << ", " << "V__12_3: " << board[V__12_3] << ", " << "V__12_4: " << board[V__12_4] << ", " << "V__12_5: " << board[V__12_5] << ", " << "V__12_6: " << board[V__12_6] << ", " << "V__12_7: " << board[V__12_7] << ", " << "V__12_8: " << board[V__12_8] << ", " << "V__12_9: " << board[V__12_9] << ", " << "V__12_10: " << board[V__12_10] << ", " << "V__12_11: " << board[V__12_11] << ", " << "V__12_12: " << board[V__12_12] << ", " << "V__12_13: " << board[V__12_13] << ", " << "V__13_1: " << board[V__13_1] << ", " << "V__13_2: " << board[V__13_2] << ", " << "V__13_3: " << board[V__13_3] << ", " << "V__13_4: " << board[V__13_4] << ", " << "V__13_5: " << board[V__13_5] << ", " << "V__13_6: " << board[V__13_6] << ", " << "V__13_7: " << board[V__13_7] << ", " << "V__13_8: " << board[V__13_8] << ", " << "V__13_9: " << board[V__13_9] << ", " << "V__13_10: " << board[V__13_10] << ", " << "V__13_11: " << board[V__13_11] << ", " << "V__13_12: " << board[V__13_12] << ", " << "V__13_13: " << board[V__13_13]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "turn_arg0_me = " << turn_arg0_me << std::endl;
    ss << "turn_arg1_op = " << turn_arg1_op << std::endl;
    ss << "win_arg0_piece = " << win_arg0_piece << std::endl;
    ss << "winInDir_arg0_piece = " << winInDir_arg0_piece << std::endl;
    ss << "winInDir_arg1_dir1 = " << "{" << "null: " << winInDir_arg1_dir1[null] << ", " << "V__1_1: " << winInDir_arg1_dir1[V__1_1] << ", " << "V__1_2: " << winInDir_arg1_dir1[V__1_2] << ", " << "V__1_3: " << winInDir_arg1_dir1[V__1_3] << ", " << "V__1_4: " << winInDir_arg1_dir1[V__1_4] << ", " << "V__1_5: " << winInDir_arg1_dir1[V__1_5] << ", " << "V__1_6: " << winInDir_arg1_dir1[V__1_6] << ", " << "V__1_7: " << winInDir_arg1_dir1[V__1_7] << ", " << "V__1_8: " << winInDir_arg1_dir1[V__1_8] << ", " << "V__1_9: " << winInDir_arg1_dir1[V__1_9] << ", " << "V__1_10: " << winInDir_arg1_dir1[V__1_10] << ", " << "V__1_11: " << winInDir_arg1_dir1[V__1_11] << ", " << "V__1_12: " << winInDir_arg1_dir1[V__1_12] << ", " << "V__1_13: " << winInDir_arg1_dir1[V__1_13] << ", " << "V__2_1: " << winInDir_arg1_dir1[V__2_1] << ", " << "V__2_2: " << winInDir_arg1_dir1[V__2_2] << ", " << "V__2_3: " << winInDir_arg1_dir1[V__2_3] << ", " << "V__2_4: " << winInDir_arg1_dir1[V__2_4] << ", " << "V__2_5: " << winInDir_arg1_dir1[V__2_5] << ", " << "V__2_6: " << winInDir_arg1_dir1[V__2_6] << ", " << "V__2_7: " << winInDir_arg1_dir1[V__2_7] << ", " << "V__2_8: " << winInDir_arg1_dir1[V__2_8] << ", " << "V__2_9: " << winInDir_arg1_dir1[V__2_9] << ", " << "V__2_10: " << winInDir_arg1_dir1[V__2_10] << ", " << "V__2_11: " << winInDir_arg1_dir1[V__2_11] << ", " << "V__2_12: " << winInDir_arg1_dir1[V__2_12] << ", " << "V__2_13: " << winInDir_arg1_dir1[V__2_13] << ", " << "V__3_1: " << winInDir_arg1_dir1[V__3_1] << ", " << "V__3_2: " << winInDir_arg1_dir1[V__3_2] << ", " << "V__3_3: " << winInDir_arg1_dir1[V__3_3] << ", " << "V__3_4: " << winInDir_arg1_dir1[V__3_4] << ", " << "V__3_5: " << winInDir_arg1_dir1[V__3_5] << ", " << "V__3_6: " << winInDir_arg1_dir1[V__3_6] << ", " << "V__3_7: " << winInDir_arg1_dir1[V__3_7] << ", " << "V__3_8: " << winInDir_arg1_dir1[V__3_8] << ", " << "V__3_9: " << winInDir_arg1_dir1[V__3_9] << ", " << "V__3_10: " << winInDir_arg1_dir1[V__3_10] << ", " << "V__3_11: " << winInDir_arg1_dir1[V__3_11] << ", " << "V__3_12: " << winInDir_arg1_dir1[V__3_12] << ", " << "V__3_13: " << winInDir_arg1_dir1[V__3_13] << ", " << "V__4_1: " << winInDir_arg1_dir1[V__4_1] << ", " << "V__4_2: " << winInDir_arg1_dir1[V__4_2] << ", " << "V__4_3: " << winInDir_arg1_dir1[V__4_3] << ", " << "V__4_4: " << winInDir_arg1_dir1[V__4_4] << ", " << "V__4_5: " << winInDir_arg1_dir1[V__4_5] << ", " << "V__4_6: " << winInDir_arg1_dir1[V__4_6] << ", " << "V__4_7: " << winInDir_arg1_dir1[V__4_7] << ", " << "V__4_8: " << winInDir_arg1_dir1[V__4_8] << ", " << "V__4_9: " << winInDir_arg1_dir1[V__4_9] << ", " << "V__4_10: " << winInDir_arg1_dir1[V__4_10] << ", " << "V__4_11: " << winInDir_arg1_dir1[V__4_11] << ", " << "V__4_12: " << winInDir_arg1_dir1[V__4_12] << ", " << "V__4_13: " << winInDir_arg1_dir1[V__4_13] << ", " << "V__5_1: " << winInDir_arg1_dir1[V__5_1] << ", " << "V__5_2: " << winInDir_arg1_dir1[V__5_2] << ", " << "V__5_3: " << winInDir_arg1_dir1[V__5_3] << ", " << "V__5_4: " << winInDir_arg1_dir1[V__5_4] << ", " << "V__5_5: " << winInDir_arg1_dir1[V__5_5] << ", " << "V__5_6: " << winInDir_arg1_dir1[V__5_6] << ", " << "V__5_7: " << winInDir_arg1_dir1[V__5_7] << ", " << "V__5_8: " << winInDir_arg1_dir1[V__5_8] << ", " << "V__5_9: " << winInDir_arg1_dir1[V__5_9] << ", " << "V__5_10: " << winInDir_arg1_dir1[V__5_10] << ", " << "V__5_11: " << winInDir_arg1_dir1[V__5_11] << ", " << "V__5_12: " << winInDir_arg1_dir1[V__5_12] << ", " << "V__5_13: " << winInDir_arg1_dir1[V__5_13] << ", " << "V__6_1: " << winInDir_arg1_dir1[V__6_1] << ", " << "V__6_2: " << winInDir_arg1_dir1[V__6_2] << ", " << "V__6_3: " << winInDir_arg1_dir1[V__6_3] << ", " << "V__6_4: " << winInDir_arg1_dir1[V__6_4] << ", " << "V__6_5: " << winInDir_arg1_dir1[V__6_5] << ", " << "V__6_6: " << winInDir_arg1_dir1[V__6_6] << ", " << "V__6_7: " << winInDir_arg1_dir1[V__6_7] << ", " << "V__6_8: " << winInDir_arg1_dir1[V__6_8] << ", " << "V__6_9: " << winInDir_arg1_dir1[V__6_9] << ", " << "V__6_10: " << winInDir_arg1_dir1[V__6_10] << ", " << "V__6_11: " << winInDir_arg1_dir1[V__6_11] << ", " << "V__6_12: " << winInDir_arg1_dir1[V__6_12] << ", " << "V__6_13: " << winInDir_arg1_dir1[V__6_13] << ", " << "V__7_1: " << winInDir_arg1_dir1[V__7_1] << ", " << "V__7_2: " << winInDir_arg1_dir1[V__7_2] << ", " << "V__7_3: " << winInDir_arg1_dir1[V__7_3] << ", " << "V__7_4: " << winInDir_arg1_dir1[V__7_4] << ", " << "V__7_5: " << winInDir_arg1_dir1[V__7_5] << ", " << "V__7_6: " << winInDir_arg1_dir1[V__7_6] << ", " << "V__7_7: " << winInDir_arg1_dir1[V__7_7] << ", " << "V__7_8: " << winInDir_arg1_dir1[V__7_8] << ", " << "V__7_9: " << winInDir_arg1_dir1[V__7_9] << ", " << "V__7_10: " << winInDir_arg1_dir1[V__7_10] << ", " << "V__7_11: " << winInDir_arg1_dir1[V__7_11] << ", " << "V__7_12: " << winInDir_arg1_dir1[V__7_12] << ", " << "V__7_13: " << winInDir_arg1_dir1[V__7_13] << ", " << "V__8_1: " << winInDir_arg1_dir1[V__8_1] << ", " << "V__8_2: " << winInDir_arg1_dir1[V__8_2] << ", " << "V__8_3: " << winInDir_arg1_dir1[V__8_3] << ", " << "V__8_4: " << winInDir_arg1_dir1[V__8_4] << ", " << "V__8_5: " << winInDir_arg1_dir1[V__8_5] << ", " << "V__8_6: " << winInDir_arg1_dir1[V__8_6] << ", " << "V__8_7: " << winInDir_arg1_dir1[V__8_7] << ", " << "V__8_8: " << winInDir_arg1_dir1[V__8_8] << ", " << "V__8_9: " << winInDir_arg1_dir1[V__8_9] << ", " << "V__8_10: " << winInDir_arg1_dir1[V__8_10] << ", " << "V__8_11: " << winInDir_arg1_dir1[V__8_11] << ", " << "V__8_12: " << winInDir_arg1_dir1[V__8_12] << ", " << "V__8_13: " << winInDir_arg1_dir1[V__8_13] << ", " << "V__9_1: " << winInDir_arg1_dir1[V__9_1] << ", " << "V__9_2: " << winInDir_arg1_dir1[V__9_2] << ", " << "V__9_3: " << winInDir_arg1_dir1[V__9_3] << ", " << "V__9_4: " << winInDir_arg1_dir1[V__9_4] << ", " << "V__9_5: " << winInDir_arg1_dir1[V__9_5] << ", " << "V__9_6: " << winInDir_arg1_dir1[V__9_6] << ", " << "V__9_7: " << winInDir_arg1_dir1[V__9_7] << ", " << "V__9_8: " << winInDir_arg1_dir1[V__9_8] << ", " << "V__9_9: " << winInDir_arg1_dir1[V__9_9] << ", " << "V__9_10: " << winInDir_arg1_dir1[V__9_10] << ", " << "V__9_11: " << winInDir_arg1_dir1[V__9_11] << ", " << "V__9_12: " << winInDir_arg1_dir1[V__9_12] << ", " << "V__9_13: " << winInDir_arg1_dir1[V__9_13] << ", " << "V__10_1: " << winInDir_arg1_dir1[V__10_1] << ", " << "V__10_2: " << winInDir_arg1_dir1[V__10_2] << ", " << "V__10_3: " << winInDir_arg1_dir1[V__10_3] << ", " << "V__10_4: " << winInDir_arg1_dir1[V__10_4] << ", " << "V__10_5: " << winInDir_arg1_dir1[V__10_5] << ", " << "V__10_6: " << winInDir_arg1_dir1[V__10_6] << ", " << "V__10_7: " << winInDir_arg1_dir1[V__10_7] << ", " << "V__10_8: " << winInDir_arg1_dir1[V__10_8] << ", " << "V__10_9: " << winInDir_arg1_dir1[V__10_9] << ", " << "V__10_10: " << winInDir_arg1_dir1[V__10_10] << ", " << "V__10_11: " << winInDir_arg1_dir1[V__10_11] << ", " << "V__10_12: " << winInDir_arg1_dir1[V__10_12] << ", " << "V__10_13: " << winInDir_arg1_dir1[V__10_13] << ", " << "V__11_1: " << winInDir_arg1_dir1[V__11_1] << ", " << "V__11_2: " << winInDir_arg1_dir1[V__11_2] << ", " << "V__11_3: " << winInDir_arg1_dir1[V__11_3] << ", " << "V__11_4: " << winInDir_arg1_dir1[V__11_4] << ", " << "V__11_5: " << winInDir_arg1_dir1[V__11_5] << ", " << "V__11_6: " << winInDir_arg1_dir1[V__11_6] << ", " << "V__11_7: " << winInDir_arg1_dir1[V__11_7] << ", " << "V__11_8: " << winInDir_arg1_dir1[V__11_8] << ", " << "V__11_9: " << winInDir_arg1_dir1[V__11_9] << ", " << "V__11_10: " << winInDir_arg1_dir1[V__11_10] << ", " << "V__11_11: " << winInDir_arg1_dir1[V__11_11] << ", " << "V__11_12: " << winInDir_arg1_dir1[V__11_12] << ", " << "V__11_13: " << winInDir_arg1_dir1[V__11_13] << ", " << "V__12_1: " << winInDir_arg1_dir1[V__12_1] << ", " << "V__12_2: " << winInDir_arg1_dir1[V__12_2] << ", " << "V__12_3: " << winInDir_arg1_dir1[V__12_3] << ", " << "V__12_4: " << winInDir_arg1_dir1[V__12_4] << ", " << "V__12_5: " << winInDir_arg1_dir1[V__12_5] << ", " << "V__12_6: " << winInDir_arg1_dir1[V__12_6] << ", " << "V__12_7: " << winInDir_arg1_dir1[V__12_7] << ", " << "V__12_8: " << winInDir_arg1_dir1[V__12_8] << ", " << "V__12_9: " << winInDir_arg1_dir1[V__12_9] << ", " << "V__12_10: " << winInDir_arg1_dir1[V__12_10] << ", " << "V__12_11: " << winInDir_arg1_dir1[V__12_11] << ", " << "V__12_12: " << winInDir_arg1_dir1[V__12_12] << ", " << "V__12_13: " << winInDir_arg1_dir1[V__12_13] << ", " << "V__13_1: " << winInDir_arg1_dir1[V__13_1] << ", " << "V__13_2: " << winInDir_arg1_dir1[V__13_2] << ", " << "V__13_3: " << winInDir_arg1_dir1[V__13_3] << ", " << "V__13_4: " << winInDir_arg1_dir1[V__13_4] << ", " << "V__13_5: " << winInDir_arg1_dir1[V__13_5] << ", " << "V__13_6: " << winInDir_arg1_dir1[V__13_6] << ", " << "V__13_7: " << winInDir_arg1_dir1[V__13_7] << ", " << "V__13_8: " << winInDir_arg1_dir1[V__13_8] << ", " << "V__13_9: " << winInDir_arg1_dir1[V__13_9] << ", " << "V__13_10: " << winInDir_arg1_dir1[V__13_10] << ", " << "V__13_11: " << winInDir_arg1_dir1[V__13_11] << ", " << "V__13_12: " << winInDir_arg1_dir1[V__13_12] << ", " << "V__13_13: " << winInDir_arg1_dir1[V__13_13]<< "}" << std::endl;
    ss << "winInDir_arg2_dir2 = " << "{" << "null: " << winInDir_arg2_dir2[null] << ", " << "V__1_1: " << winInDir_arg2_dir2[V__1_1] << ", " << "V__1_2: " << winInDir_arg2_dir2[V__1_2] << ", " << "V__1_3: " << winInDir_arg2_dir2[V__1_3] << ", " << "V__1_4: " << winInDir_arg2_dir2[V__1_4] << ", " << "V__1_5: " << winInDir_arg2_dir2[V__1_5] << ", " << "V__1_6: " << winInDir_arg2_dir2[V__1_6] << ", " << "V__1_7: " << winInDir_arg2_dir2[V__1_7] << ", " << "V__1_8: " << winInDir_arg2_dir2[V__1_8] << ", " << "V__1_9: " << winInDir_arg2_dir2[V__1_9] << ", " << "V__1_10: " << winInDir_arg2_dir2[V__1_10] << ", " << "V__1_11: " << winInDir_arg2_dir2[V__1_11] << ", " << "V__1_12: " << winInDir_arg2_dir2[V__1_12] << ", " << "V__1_13: " << winInDir_arg2_dir2[V__1_13] << ", " << "V__2_1: " << winInDir_arg2_dir2[V__2_1] << ", " << "V__2_2: " << winInDir_arg2_dir2[V__2_2] << ", " << "V__2_3: " << winInDir_arg2_dir2[V__2_3] << ", " << "V__2_4: " << winInDir_arg2_dir2[V__2_4] << ", " << "V__2_5: " << winInDir_arg2_dir2[V__2_5] << ", " << "V__2_6: " << winInDir_arg2_dir2[V__2_6] << ", " << "V__2_7: " << winInDir_arg2_dir2[V__2_7] << ", " << "V__2_8: " << winInDir_arg2_dir2[V__2_8] << ", " << "V__2_9: " << winInDir_arg2_dir2[V__2_9] << ", " << "V__2_10: " << winInDir_arg2_dir2[V__2_10] << ", " << "V__2_11: " << winInDir_arg2_dir2[V__2_11] << ", " << "V__2_12: " << winInDir_arg2_dir2[V__2_12] << ", " << "V__2_13: " << winInDir_arg2_dir2[V__2_13] << ", " << "V__3_1: " << winInDir_arg2_dir2[V__3_1] << ", " << "V__3_2: " << winInDir_arg2_dir2[V__3_2] << ", " << "V__3_3: " << winInDir_arg2_dir2[V__3_3] << ", " << "V__3_4: " << winInDir_arg2_dir2[V__3_4] << ", " << "V__3_5: " << winInDir_arg2_dir2[V__3_5] << ", " << "V__3_6: " << winInDir_arg2_dir2[V__3_6] << ", " << "V__3_7: " << winInDir_arg2_dir2[V__3_7] << ", " << "V__3_8: " << winInDir_arg2_dir2[V__3_8] << ", " << "V__3_9: " << winInDir_arg2_dir2[V__3_9] << ", " << "V__3_10: " << winInDir_arg2_dir2[V__3_10] << ", " << "V__3_11: " << winInDir_arg2_dir2[V__3_11] << ", " << "V__3_12: " << winInDir_arg2_dir2[V__3_12] << ", " << "V__3_13: " << winInDir_arg2_dir2[V__3_13] << ", " << "V__4_1: " << winInDir_arg2_dir2[V__4_1] << ", " << "V__4_2: " << winInDir_arg2_dir2[V__4_2] << ", " << "V__4_3: " << winInDir_arg2_dir2[V__4_3] << ", " << "V__4_4: " << winInDir_arg2_dir2[V__4_4] << ", " << "V__4_5: " << winInDir_arg2_dir2[V__4_5] << ", " << "V__4_6: " << winInDir_arg2_dir2[V__4_6] << ", " << "V__4_7: " << winInDir_arg2_dir2[V__4_7] << ", " << "V__4_8: " << winInDir_arg2_dir2[V__4_8] << ", " << "V__4_9: " << winInDir_arg2_dir2[V__4_9] << ", " << "V__4_10: " << winInDir_arg2_dir2[V__4_10] << ", " << "V__4_11: " << winInDir_arg2_dir2[V__4_11] << ", " << "V__4_12: " << winInDir_arg2_dir2[V__4_12] << ", " << "V__4_13: " << winInDir_arg2_dir2[V__4_13] << ", " << "V__5_1: " << winInDir_arg2_dir2[V__5_1] << ", " << "V__5_2: " << winInDir_arg2_dir2[V__5_2] << ", " << "V__5_3: " << winInDir_arg2_dir2[V__5_3] << ", " << "V__5_4: " << winInDir_arg2_dir2[V__5_4] << ", " << "V__5_5: " << winInDir_arg2_dir2[V__5_5] << ", " << "V__5_6: " << winInDir_arg2_dir2[V__5_6] << ", " << "V__5_7: " << winInDir_arg2_dir2[V__5_7] << ", " << "V__5_8: " << winInDir_arg2_dir2[V__5_8] << ", " << "V__5_9: " << winInDir_arg2_dir2[V__5_9] << ", " << "V__5_10: " << winInDir_arg2_dir2[V__5_10] << ", " << "V__5_11: " << winInDir_arg2_dir2[V__5_11] << ", " << "V__5_12: " << winInDir_arg2_dir2[V__5_12] << ", " << "V__5_13: " << winInDir_arg2_dir2[V__5_13] << ", " << "V__6_1: " << winInDir_arg2_dir2[V__6_1] << ", " << "V__6_2: " << winInDir_arg2_dir2[V__6_2] << ", " << "V__6_3: " << winInDir_arg2_dir2[V__6_3] << ", " << "V__6_4: " << winInDir_arg2_dir2[V__6_4] << ", " << "V__6_5: " << winInDir_arg2_dir2[V__6_5] << ", " << "V__6_6: " << winInDir_arg2_dir2[V__6_6] << ", " << "V__6_7: " << winInDir_arg2_dir2[V__6_7] << ", " << "V__6_8: " << winInDir_arg2_dir2[V__6_8] << ", " << "V__6_9: " << winInDir_arg2_dir2[V__6_9] << ", " << "V__6_10: " << winInDir_arg2_dir2[V__6_10] << ", " << "V__6_11: " << winInDir_arg2_dir2[V__6_11] << ", " << "V__6_12: " << winInDir_arg2_dir2[V__6_12] << ", " << "V__6_13: " << winInDir_arg2_dir2[V__6_13] << ", " << "V__7_1: " << winInDir_arg2_dir2[V__7_1] << ", " << "V__7_2: " << winInDir_arg2_dir2[V__7_2] << ", " << "V__7_3: " << winInDir_arg2_dir2[V__7_3] << ", " << "V__7_4: " << winInDir_arg2_dir2[V__7_4] << ", " << "V__7_5: " << winInDir_arg2_dir2[V__7_5] << ", " << "V__7_6: " << winInDir_arg2_dir2[V__7_6] << ", " << "V__7_7: " << winInDir_arg2_dir2[V__7_7] << ", " << "V__7_8: " << winInDir_arg2_dir2[V__7_8] << ", " << "V__7_9: " << winInDir_arg2_dir2[V__7_9] << ", " << "V__7_10: " << winInDir_arg2_dir2[V__7_10] << ", " << "V__7_11: " << winInDir_arg2_dir2[V__7_11] << ", " << "V__7_12: " << winInDir_arg2_dir2[V__7_12] << ", " << "V__7_13: " << winInDir_arg2_dir2[V__7_13] << ", " << "V__8_1: " << winInDir_arg2_dir2[V__8_1] << ", " << "V__8_2: " << winInDir_arg2_dir2[V__8_2] << ", " << "V__8_3: " << winInDir_arg2_dir2[V__8_3] << ", " << "V__8_4: " << winInDir_arg2_dir2[V__8_4] << ", " << "V__8_5: " << winInDir_arg2_dir2[V__8_5] << ", " << "V__8_6: " << winInDir_arg2_dir2[V__8_6] << ", " << "V__8_7: " << winInDir_arg2_dir2[V__8_7] << ", " << "V__8_8: " << winInDir_arg2_dir2[V__8_8] << ", " << "V__8_9: " << winInDir_arg2_dir2[V__8_9] << ", " << "V__8_10: " << winInDir_arg2_dir2[V__8_10] << ", " << "V__8_11: " << winInDir_arg2_dir2[V__8_11] << ", " << "V__8_12: " << winInDir_arg2_dir2[V__8_12] << ", " << "V__8_13: " << winInDir_arg2_dir2[V__8_13] << ", " << "V__9_1: " << winInDir_arg2_dir2[V__9_1] << ", " << "V__9_2: " << winInDir_arg2_dir2[V__9_2] << ", " << "V__9_3: " << winInDir_arg2_dir2[V__9_3] << ", " << "V__9_4: " << winInDir_arg2_dir2[V__9_4] << ", " << "V__9_5: " << winInDir_arg2_dir2[V__9_5] << ", " << "V__9_6: " << winInDir_arg2_dir2[V__9_6] << ", " << "V__9_7: " << winInDir_arg2_dir2[V__9_7] << ", " << "V__9_8: " << winInDir_arg2_dir2[V__9_8] << ", " << "V__9_9: " << winInDir_arg2_dir2[V__9_9] << ", " << "V__9_10: " << winInDir_arg2_dir2[V__9_10] << ", " << "V__9_11: " << winInDir_arg2_dir2[V__9_11] << ", " << "V__9_12: " << winInDir_arg2_dir2[V__9_12] << ", " << "V__9_13: " << winInDir_arg2_dir2[V__9_13] << ", " << "V__10_1: " << winInDir_arg2_dir2[V__10_1] << ", " << "V__10_2: " << winInDir_arg2_dir2[V__10_2] << ", " << "V__10_3: " << winInDir_arg2_dir2[V__10_3] << ", " << "V__10_4: " << winInDir_arg2_dir2[V__10_4] << ", " << "V__10_5: " << winInDir_arg2_dir2[V__10_5] << ", " << "V__10_6: " << winInDir_arg2_dir2[V__10_6] << ", " << "V__10_7: " << winInDir_arg2_dir2[V__10_7] << ", " << "V__10_8: " << winInDir_arg2_dir2[V__10_8] << ", " << "V__10_9: " << winInDir_arg2_dir2[V__10_9] << ", " << "V__10_10: " << winInDir_arg2_dir2[V__10_10] << ", " << "V__10_11: " << winInDir_arg2_dir2[V__10_11] << ", " << "V__10_12: " << winInDir_arg2_dir2[V__10_12] << ", " << "V__10_13: " << winInDir_arg2_dir2[V__10_13] << ", " << "V__11_1: " << winInDir_arg2_dir2[V__11_1] << ", " << "V__11_2: " << winInDir_arg2_dir2[V__11_2] << ", " << "V__11_3: " << winInDir_arg2_dir2[V__11_3] << ", " << "V__11_4: " << winInDir_arg2_dir2[V__11_4] << ", " << "V__11_5: " << winInDir_arg2_dir2[V__11_5] << ", " << "V__11_6: " << winInDir_arg2_dir2[V__11_6] << ", " << "V__11_7: " << winInDir_arg2_dir2[V__11_7] << ", " << "V__11_8: " << winInDir_arg2_dir2[V__11_8] << ", " << "V__11_9: " << winInDir_arg2_dir2[V__11_9] << ", " << "V__11_10: " << winInDir_arg2_dir2[V__11_10] << ", " << "V__11_11: " << winInDir_arg2_dir2[V__11_11] << ", " << "V__11_12: " << winInDir_arg2_dir2[V__11_12] << ", " << "V__11_13: " << winInDir_arg2_dir2[V__11_13] << ", " << "V__12_1: " << winInDir_arg2_dir2[V__12_1] << ", " << "V__12_2: " << winInDir_arg2_dir2[V__12_2] << ", " << "V__12_3: " << winInDir_arg2_dir2[V__12_3] << ", " << "V__12_4: " << winInDir_arg2_dir2[V__12_4] << ", " << "V__12_5: " << winInDir_arg2_dir2[V__12_5] << ", " << "V__12_6: " << winInDir_arg2_dir2[V__12_6] << ", " << "V__12_7: " << winInDir_arg2_dir2[V__12_7] << ", " << "V__12_8: " << winInDir_arg2_dir2[V__12_8] << ", " << "V__12_9: " << winInDir_arg2_dir2[V__12_9] << ", " << "V__12_10: " << winInDir_arg2_dir2[V__12_10] << ", " << "V__12_11: " << winInDir_arg2_dir2[V__12_11] << ", " << "V__12_12: " << winInDir_arg2_dir2[V__12_12] << ", " << "V__12_13: " << winInDir_arg2_dir2[V__12_13] << ", " << "V__13_1: " << winInDir_arg2_dir2[V__13_1] << ", " << "V__13_2: " << winInDir_arg2_dir2[V__13_2] << ", " << "V__13_3: " << winInDir_arg2_dir2[V__13_3] << ", " << "V__13_4: " << winInDir_arg2_dir2[V__13_4] << ", " << "V__13_5: " << winInDir_arg2_dir2[V__13_5] << ", " << "V__13_6: " << winInDir_arg2_dir2[V__13_6] << ", " << "V__13_7: " << winInDir_arg2_dir2[V__13_7] << ", " << "V__13_8: " << winInDir_arg2_dir2[V__13_8] << ", " << "V__13_9: " << winInDir_arg2_dir2[V__13_9] << ", " << "V__13_10: " << winInDir_arg2_dir2[V__13_10] << ", " << "V__13_11: " << winInDir_arg2_dir2[V__13_11] << ", " << "V__13_12: " << winInDir_arg2_dir2[V__13_12] << ", " << "V__13_13: " << winInDir_arg2_dir2[V__13_13]<< "}" << std::endl;
    ss << "goals = " << "{" << "white: " << goals[white-2] << ", " << "black: " << goals[black-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "white: " << visible[white-2] << ", " << "black: " << visible[black-2]<< "}" << std::endl;
    ss << "currentState = " << currentState << std::endl;
    return ss.str();
}

void GameState::getAllMoves(std::vector<Move>& moves, RgCache& rgCache)
{
    rgCache.reset();
moves.clear();
Move mr
;
    switch (currentState)
    {
        case 7:
{
            state_rules_3_turn_1(moves, mr.mr);
            return;
}
        case 170:
{
            state_rules_5_turn_1(moves, mr.mr);
            return;
}
        case 1:
{
            state_begin(moves, mr.mr);
            return;
}
    }
}

void GameState::applyMove(const Move& mr, RgCache& rgCache)
{
    rgCache.reset();
    switch (currentState)
    {
        case 7:
{
            apply_state_rules_3_turn_1(mr.mr,rgCache);
            return;
}
        case 170:
{
            apply_state_rules_5_turn_1(mr.mr,rgCache);
            return;
}
        case 1:
{
            apply_state_begin(mr.mr,rgCache);
            return;
}
    }
}

void GameState::applyAnyMove([[maybe_unused]]RgCache& rgCache)
{
    switch (currentState)
    {
        case 1:
{
            apply_any_begin_begin_begin();
            break;
}
        case 20:
{
            apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5();
            break;
}
        case 183:
{
            apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5();
            break;
}
    }
}

bool GameState::is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_1()
{
    if (is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_1()
{
    if (board[pos]==empty)
    {
        if (is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_2()
{
    if (is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_begin()
{
    const auto old6_0 = pos;
    for (pos = V__10_1; pos <= V__9_9; ++pos)
    {
    if (is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_1())
    {
        pos = old6_0;
        return true;
    }    }
    pos = old6_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_existsNonempty_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1()
{
    const auto old141_0 = win_arg0_piece;
    win_arg0_piece = turn_arg0_me;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2())
    {
        win_arg0_piece = old141_0;
        return true;
    }
    win_arg0_piece = old141_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__1()
{
    const auto old144_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = upLeft;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__2())
    {
        winInDir_arg1_dir1 = old144_0;
        return true;
    }
    winInDir_arg1_dir1 = old144_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__2()
{
    const auto old145_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = downRight;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__3())
    {
        winInDir_arg2_dir2 = old145_0;
        return true;
    }
    winInDir_arg2_dir2 = old145_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_12()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_14()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_16()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_19()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_23()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_28()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_9()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2_winInDir_end()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__1()
{
    const auto old183_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = up;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__2())
    {
        winInDir_arg1_dir1 = old183_0;
        return true;
    }
    winInDir_arg1_dir1 = old183_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__2()
{
    const auto old184_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = down;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__3())
    {
        winInDir_arg2_dir2 = old184_0;
        return true;
    }
    winInDir_arg2_dir2 = old184_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_12()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_14()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_16()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_19()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_23()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_28()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_9()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4_winInDir_end()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_5()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__1()
{
    const auto old222_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = upRight;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__2())
    {
        winInDir_arg1_dir1 = old222_0;
        return true;
    }
    winInDir_arg1_dir1 = old222_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__2()
{
    const auto old223_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = downLeft;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__3())
    {
        winInDir_arg2_dir2 = old223_0;
        return true;
    }
    winInDir_arg2_dir2 = old223_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_12()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_14()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_16()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_19()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_23()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_28()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_9()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6_winInDir_end()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_7())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_7()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__1()
{
    const auto old261_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = left;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__2())
    {
        winInDir_arg1_dir1 = old261_0;
        return true;
    }
    winInDir_arg1_dir1 = old261_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__2()
{
    const auto old262_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = right;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__3())
    {
        winInDir_arg2_dir2 = old262_0;
        return true;
    }
    winInDir_arg2_dir2 = old262_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_12()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_14()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_16()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_19()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_23()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_28()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_3()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_9()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8_winInDir_end()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_9()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin()
{
    const auto old143_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2__1())
    {
        winInDir_arg0_piece = old143_0;
        return true;
    }
    winInDir_arg0_piece = old143_0;
    const auto old182_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4__1())
    {
        winInDir_arg0_piece = old182_0;
        return true;
    }
    winInDir_arg0_piece = old182_0;
    const auto old221_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_6__1())
    {
        winInDir_arg0_piece = old221_0;
        return true;
    }
    winInDir_arg0_piece = old221_0;
    const auto old260_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_8__1())
    {
        winInDir_arg0_piece = old260_0;
        return true;
    }
    winInDir_arg0_piece = old260_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_1()
{
    if (is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_1()
{
    if (board[pos]==empty)
    {
        if (is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_2()
{
    if (is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_begin()
{
    const auto old6_0 = pos;
    for (pos = V__10_1; pos <= V__9_9; ++pos)
    {
    if (is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_1())
    {
        pos = old6_0;
        return true;
    }    }
    pos = old6_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_existsNonempty_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1()
{
    const auto old141_0 = win_arg0_piece;
    win_arg0_piece = turn_arg0_me;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2())
    {
        win_arg0_piece = old141_0;
        return true;
    }
    win_arg0_piece = old141_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__1()
{
    const auto old144_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = upLeft;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__2())
    {
        winInDir_arg1_dir1 = old144_0;
        return true;
    }
    winInDir_arg1_dir1 = old144_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__2()
{
    const auto old145_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = downRight;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__3())
    {
        winInDir_arg2_dir2 = old145_0;
        return true;
    }
    winInDir_arg2_dir2 = old145_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_12()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_14()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_16()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_19()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_23()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_28()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_9()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2_winInDir_end()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__1()
{
    const auto old183_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = up;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__2())
    {
        winInDir_arg1_dir1 = old183_0;
        return true;
    }
    winInDir_arg1_dir1 = old183_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__2()
{
    const auto old184_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = down;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__3())
    {
        winInDir_arg2_dir2 = old184_0;
        return true;
    }
    winInDir_arg2_dir2 = old184_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_12()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_14()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_16()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_19()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_23()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_28()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_9()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4_winInDir_end()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_5()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__1()
{
    const auto old222_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = upRight;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__2())
    {
        winInDir_arg1_dir1 = old222_0;
        return true;
    }
    winInDir_arg1_dir1 = old222_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__2()
{
    const auto old223_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = downLeft;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__3())
    {
        winInDir_arg2_dir2 = old223_0;
        return true;
    }
    winInDir_arg2_dir2 = old223_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_12()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_14()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_16()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_19()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_23()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_28()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_9()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6_winInDir_end()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_7())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_7()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__1()
{
    const auto old261_0 = winInDir_arg1_dir1;
    winInDir_arg1_dir1 = left;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__2())
    {
        winInDir_arg1_dir1 = old261_0;
        return true;
    }
    winInDir_arg1_dir1 = old261_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__2()
{
    const auto old262_0 = winInDir_arg2_dir2;
    winInDir_arg2_dir2 = right;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__3())
    {
        winInDir_arg2_dir2 = old262_0;
        return true;
    }
    winInDir_arg2_dir2 = old262_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_1()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_4())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_10()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_11()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_12()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_13()
{
    if (board[winInDir_arg2_dir2[pos]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_14()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_15()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_16()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_17()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_18()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_19()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_2()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_20()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_21()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_22()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_23()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_24()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_25()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_26()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_27()
{
    if (board[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[winInDir_arg2_dir2[pos]]]]]]!=winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_28()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_3()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_4()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_7())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_5()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_20())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_7()
{
    if (board[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[winInDir_arg1_dir1[pos]]]]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_10())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_8()
{
    if (board[winInDir_arg2_dir2[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_9()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_begin()
{
    if (board[winInDir_arg1_dir1[pos]]==winInDir_arg0_piece)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_1())
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8_winInDir_end()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_9()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin()
{
    const auto old143_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2__1())
    {
        winInDir_arg0_piece = old143_0;
        return true;
    }
    winInDir_arg0_piece = old143_0;
    const auto old182_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4__1())
    {
        winInDir_arg0_piece = old182_0;
        return true;
    }
    winInDir_arg0_piece = old182_0;
    const auto old221_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_6__1())
    {
        winInDir_arg0_piece = old221_0;
        return true;
    }
    winInDir_arg0_piece = old221_0;
    const auto old260_0 = winInDir_arg0_piece;
    winInDir_arg0_piece = win_arg0_piece;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_8__1())
    {
        winInDir_arg0_piece = old260_0;
        return true;
    }
    winInDir_arg0_piece = old260_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end()
{
    return true;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_begin(moves, mr);
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
}

void GameState::state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old334_0 = turn_arg0_me;
    turn_arg0_me = white;
    state_rules_3__1(moves, mr);
    turn_arg0_me = old334_0;
}

void GameState::state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old335_0 = turn_arg1_op;
    turn_arg1_op = black;
    state_rules_3__2(moves, mr);
    turn_arg1_op = old335_0;
}

void GameState::state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_begin(moves, mr);
}

void GameState::state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old338_0 = pos;
    for (pos = V__10_1; pos <= V__9_9; ++pos)
    {
    state_rules_3_turn_2(moves, mr);    }
    pos = old338_0;
}

void GameState::state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old505_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    state_rules_3_turn_11(moves, mr);
    goals[turn_arg1_op - 2] = old505_0;
}

void GameState::state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_end(moves, mr);
}

void GameState::state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_3_turn_3(moves, mr);
    }
}

void GameState::state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_rules_3_turn_4(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old342_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_3_turn_6(moves, mr);
    board[pos] = old342_0;
}

void GameState::state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1())
    {
        state_rules_3_turn_7(moves, mr);
        return;
    }
    state_rules_3_turn_8(moves, mr);
}

void GameState::state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old504_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_3_turn_10(moves, mr);
    goals[turn_arg0_me - 2] = old504_0;
}

void GameState::state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_1())
    {
        state_rules_3_turn_12(moves, mr);
        return;
    }
    state_rules_3_turn_13(moves, mr);
}

void GameState::state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_4(moves, mr);
}

void GameState::state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old516_0 = turn_arg0_me;
    turn_arg0_me = black;
    state_rules_5__1(moves, mr);
    turn_arg0_me = old516_0;
}

void GameState::state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old517_0 = turn_arg1_op;
    turn_arg1_op = white;
    state_rules_5__2(moves, mr);
    turn_arg1_op = old517_0;
}

void GameState::state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_begin(moves, mr);
}

void GameState::state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old520_0 = pos;
    for (pos = V__10_1; pos <= V__9_9; ++pos)
    {
    state_rules_5_turn_2(moves, mr);    }
    pos = old520_0;
}

void GameState::state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old687_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    state_rules_5_turn_11(moves, mr);
    goals[turn_arg1_op - 2] = old687_0;
}

void GameState::state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_end(moves, mr);
}

void GameState::state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_5_turn_3(moves, mr);
    }
}

void GameState::state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_rules_5_turn_4(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old524_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_5_turn_6(moves, mr);
    board[pos] = old524_0;
}

void GameState::state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1())
    {
        state_rules_5_turn_7(moves, mr);
        return;
    }
    state_rules_5_turn_8(moves, mr);
}

void GameState::state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old686_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_5_turn_10(moves, mr);
    goals[turn_arg0_me - 2] = old686_0;
}

void GameState::state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_1())
    {
        state_rules_5_turn_12(moves, mr);
        return;
    }
    state_rules_5_turn_13(moves, mr);
}

void GameState::state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_6(moves, mr);
}

void GameState::state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_1(moves, mr);
}

void GameState::state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_1(moves, mr);
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    turn_arg0_me = white;
    turn_arg1_op = black;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old334_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_state_rules_3__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old334_0;
    return false;
}

bool GameState::apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old335_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_state_rules_3__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old335_0;
    return false;
}

bool GameState::apply_state_rules_3__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 20;
            return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_3_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old505_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_state_rules_3_turn_11(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old505_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old506_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old506_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old513_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old513_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_rules_3_turn_3(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_rules_3_turn_4(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old341_0 = player;
    player = keeper;
    currentState = 20;
    return true;
    player = old341_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old342_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_3_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old342_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1())
    {
        if (apply_state_rules_3_turn_7(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_3_turn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old504_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_3_turn_10(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old504_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_1())
    {
        if (apply_state_rules_3_turn_12(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_3_turn_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old337_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    player = old337_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_4(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old516_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_state_rules_5__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old516_0;
    return false;
}

bool GameState::apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old517_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_state_rules_5__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old517_0;
    return false;
}

bool GameState::apply_state_rules_5__2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 183;
            return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_5_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old687_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_state_rules_5_turn_11(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old687_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old688_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old688_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old695_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old695_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_rules_5_turn_3(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_rules_5_turn_4(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old523_0 = player;
    player = keeper;
    currentState = 183;
    return true;
    player = old523_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old524_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_5_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old524_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1())
    {
        if (apply_state_rules_5_turn_7(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_5_turn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old686_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_5_turn_10(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old686_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_1())
    {
        if (apply_state_rules_5_turn_12(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_5_turn_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old519_0 = player;
    player = turn_arg0_me;
    currentState = 170;
    return true;
    player = old519_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_1(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_1(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin()
{
    if (apply_any_begin_begin_rules_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_rules_1()
{
    const auto old9_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_begin_begin_rules_3__1())
    {
        return true;
    }
    turn_arg0_me = old9_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_3__1()
{
    const auto old10_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_any_begin_begin_rules_3__2())
    {
        return true;
    }
    turn_arg1_op = old10_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_3__2()
{
    if (apply_any_begin_begin_rules_3_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_rules_3_turn_1()
{
    return true;
}

bool GameState::apply_any_begin_begin_rules_3_turn_begin()
{
    const auto old12_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    if (apply_any_begin_begin_rules_3_turn_1())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_begin()
{
    if (apply_any_begin_begin_rules_1())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_end()
{
    return true;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10()
{
    const auto old19_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old19_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11()
{
    const auto old20_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_end())
    {
        return true;
    }
    player = old20_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12()
{
    const auto old23_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_end())
    {
        return true;
    }
    player = old23_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_13()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5()
{
    const auto old15_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6())
    {
        return true;
    }
    board[pos] = old15_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1())
    {
        if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7()
{
    const auto old18_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old18_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8()
{
    if (!is_legal_rules_3_turn_14_1_rules_3_turn_14_existsNonempty_end_rules_3_turn_14_1())
    {
        if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_4())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_4()
{
    const auto old26_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1())
    {
        return true;
    }
    turn_arg0_me = old26_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1()
{
    const auto old27_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2())
    {
        return true;
    }
    turn_arg1_op = old27_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1()
{
    return true;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin()
{
    const auto old29_0 = player;
    player = turn_arg0_me;
    currentState = 170;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1())
    {
        return true;
    }
    player = old29_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_end()
{
    return true;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_1()
{
    const auto old16_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1())
    {
        return true;
    }
    turn_arg0_me = old16_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1()
{
    const auto old17_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2())
    {
        return true;
    }
    turn_arg1_op = old17_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1()
{
    return true;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin()
{
    const auto old19_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1())
    {
        return true;
    }
    player = old19_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10()
{
    const auto old24_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old24_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11()
{
    const auto old25_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_end())
    {
        return true;
    }
    player = old25_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12()
{
    const auto old28_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_end())
    {
        return true;
    }
    player = old28_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_13()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5()
{
    const auto old20_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6())
    {
        return true;
    }
    board[pos] = old20_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1())
    {
        if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7()
{
    const auto old23_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old23_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8()
{
    if (!is_legal_rules_5_turn_14_1_rules_5_turn_14_existsNonempty_end_rules_5_turn_14_1())
    {
        if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_6()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_1())
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
