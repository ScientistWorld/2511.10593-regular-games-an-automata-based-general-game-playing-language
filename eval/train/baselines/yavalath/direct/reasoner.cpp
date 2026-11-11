#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.line3_arg0_p) ^ hash(gameState.line3InDir_arg0_p) ^ hash(gameState.line3InDir_arg1_dir1) ^ hash(gameState.line3InDir_arg2_dir2) ^ hash(gameState.line4_arg0_p) ^ hash(gameState.line4InDir_arg0_p) ^ hash(gameState.line4InDir_arg1_dir1) ^ hash(gameState.line4InDir_arg2_dir2) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.line3_arg0_p) ^ hash(gameState.line3InDir_arg0_p) ^ hash(gameState.line3InDir_arg1_dir1) ^ hash(gameState.line3InDir_arg2_dir2) ^ hash(gameState.line4_arg0_p) ^ hash(gameState.line4InDir_arg0_p) ^ hash(gameState.line4InDir_arg1_dir1) ^ hash(gameState.line4InDir_arg2_dir2) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && turn_arg0_me==rhs.turn_arg0_me && turn_arg1_op==rhs.turn_arg1_op && line3_arg0_p==rhs.line3_arg0_p && line3InDir_arg0_p==rhs.line3InDir_arg0_p && line3InDir_arg1_dir1==rhs.line3InDir_arg1_dir1 && line3InDir_arg2_dir2==rhs.line3InDir_arg2_dir2 && line4_arg0_p==rhs.line4_arg0_p && line4InDir_arg0_p==rhs.line4InDir_arg0_p && line4InDir_arg1_dir1==rhs.line4InDir_arg1_dir1 && line4InDir_arg2_dir2==rhs.line4InDir_arg2_dir2 && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__8_4: " << board[V__8_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__8_5: " << board[V__8_5] << ", " << "V__9_5: " << board[V__9_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__7_6: " << board[V__7_6] << ", " << "V__8_6: " << board[V__8_6] << ", " << "V__9_6: " << board[V__9_6] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__4_7: " << board[V__4_7] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__6_7: " << board[V__6_7] << ", " << "V__7_7: " << board[V__7_7] << ", " << "V__8_7: " << board[V__8_7] << ", " << "V__9_7: " << board[V__9_7] << ", " << "V__4_8: " << board[V__4_8] << ", " << "V__5_8: " << board[V__5_8] << ", " << "V__6_8: " << board[V__6_8] << ", " << "V__7_8: " << board[V__7_8] << ", " << "V__8_8: " << board[V__8_8] << ", " << "V__9_8: " << board[V__9_8] << ", " << "V__5_9: " << board[V__5_9] << ", " << "V__6_9: " << board[V__6_9] << ", " << "V__7_9: " << board[V__7_9] << ", " << "V__8_9: " << board[V__8_9] << ", " << "V__9_9: " << board[V__9_9]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "turn_arg0_me = " << turn_arg0_me << std::endl;
    ss << "turn_arg1_op = " << turn_arg1_op << std::endl;
    ss << "line3_arg0_p = " << line3_arg0_p << std::endl;
    ss << "line3InDir_arg0_p = " << line3InDir_arg0_p << std::endl;
    ss << "line3InDir_arg1_dir1 = " << "{" << "null: " << line3InDir_arg1_dir1[null] << ", " << "V__1_1: " << line3InDir_arg1_dir1[V__1_1] << ", " << "V__2_1: " << line3InDir_arg1_dir1[V__2_1] << ", " << "V__3_1: " << line3InDir_arg1_dir1[V__3_1] << ", " << "V__4_1: " << line3InDir_arg1_dir1[V__4_1] << ", " << "V__5_1: " << line3InDir_arg1_dir1[V__5_1] << ", " << "V__1_2: " << line3InDir_arg1_dir1[V__1_2] << ", " << "V__2_2: " << line3InDir_arg1_dir1[V__2_2] << ", " << "V__3_2: " << line3InDir_arg1_dir1[V__3_2] << ", " << "V__4_2: " << line3InDir_arg1_dir1[V__4_2] << ", " << "V__5_2: " << line3InDir_arg1_dir1[V__5_2] << ", " << "V__6_2: " << line3InDir_arg1_dir1[V__6_2] << ", " << "V__1_3: " << line3InDir_arg1_dir1[V__1_3] << ", " << "V__2_3: " << line3InDir_arg1_dir1[V__2_3] << ", " << "V__3_3: " << line3InDir_arg1_dir1[V__3_3] << ", " << "V__4_3: " << line3InDir_arg1_dir1[V__4_3] << ", " << "V__5_3: " << line3InDir_arg1_dir1[V__5_3] << ", " << "V__6_3: " << line3InDir_arg1_dir1[V__6_3] << ", " << "V__7_3: " << line3InDir_arg1_dir1[V__7_3] << ", " << "V__1_4: " << line3InDir_arg1_dir1[V__1_4] << ", " << "V__2_4: " << line3InDir_arg1_dir1[V__2_4] << ", " << "V__3_4: " << line3InDir_arg1_dir1[V__3_4] << ", " << "V__4_4: " << line3InDir_arg1_dir1[V__4_4] << ", " << "V__5_4: " << line3InDir_arg1_dir1[V__5_4] << ", " << "V__6_4: " << line3InDir_arg1_dir1[V__6_4] << ", " << "V__7_4: " << line3InDir_arg1_dir1[V__7_4] << ", " << "V__8_4: " << line3InDir_arg1_dir1[V__8_4] << ", " << "V__1_5: " << line3InDir_arg1_dir1[V__1_5] << ", " << "V__2_5: " << line3InDir_arg1_dir1[V__2_5] << ", " << "V__3_5: " << line3InDir_arg1_dir1[V__3_5] << ", " << "V__4_5: " << line3InDir_arg1_dir1[V__4_5] << ", " << "V__5_5: " << line3InDir_arg1_dir1[V__5_5] << ", " << "V__6_5: " << line3InDir_arg1_dir1[V__6_5] << ", " << "V__7_5: " << line3InDir_arg1_dir1[V__7_5] << ", " << "V__8_5: " << line3InDir_arg1_dir1[V__8_5] << ", " << "V__9_5: " << line3InDir_arg1_dir1[V__9_5] << ", " << "V__2_6: " << line3InDir_arg1_dir1[V__2_6] << ", " << "V__3_6: " << line3InDir_arg1_dir1[V__3_6] << ", " << "V__4_6: " << line3InDir_arg1_dir1[V__4_6] << ", " << "V__5_6: " << line3InDir_arg1_dir1[V__5_6] << ", " << "V__6_6: " << line3InDir_arg1_dir1[V__6_6] << ", " << "V__7_6: " << line3InDir_arg1_dir1[V__7_6] << ", " << "V__8_6: " << line3InDir_arg1_dir1[V__8_6] << ", " << "V__9_6: " << line3InDir_arg1_dir1[V__9_6] << ", " << "V__3_7: " << line3InDir_arg1_dir1[V__3_7] << ", " << "V__4_7: " << line3InDir_arg1_dir1[V__4_7] << ", " << "V__5_7: " << line3InDir_arg1_dir1[V__5_7] << ", " << "V__6_7: " << line3InDir_arg1_dir1[V__6_7] << ", " << "V__7_7: " << line3InDir_arg1_dir1[V__7_7] << ", " << "V__8_7: " << line3InDir_arg1_dir1[V__8_7] << ", " << "V__9_7: " << line3InDir_arg1_dir1[V__9_7] << ", " << "V__4_8: " << line3InDir_arg1_dir1[V__4_8] << ", " << "V__5_8: " << line3InDir_arg1_dir1[V__5_8] << ", " << "V__6_8: " << line3InDir_arg1_dir1[V__6_8] << ", " << "V__7_8: " << line3InDir_arg1_dir1[V__7_8] << ", " << "V__8_8: " << line3InDir_arg1_dir1[V__8_8] << ", " << "V__9_8: " << line3InDir_arg1_dir1[V__9_8] << ", " << "V__5_9: " << line3InDir_arg1_dir1[V__5_9] << ", " << "V__6_9: " << line3InDir_arg1_dir1[V__6_9] << ", " << "V__7_9: " << line3InDir_arg1_dir1[V__7_9] << ", " << "V__8_9: " << line3InDir_arg1_dir1[V__8_9] << ", " << "V__9_9: " << line3InDir_arg1_dir1[V__9_9]<< "}" << std::endl;
    ss << "line3InDir_arg2_dir2 = " << "{" << "null: " << line3InDir_arg2_dir2[null] << ", " << "V__1_1: " << line3InDir_arg2_dir2[V__1_1] << ", " << "V__2_1: " << line3InDir_arg2_dir2[V__2_1] << ", " << "V__3_1: " << line3InDir_arg2_dir2[V__3_1] << ", " << "V__4_1: " << line3InDir_arg2_dir2[V__4_1] << ", " << "V__5_1: " << line3InDir_arg2_dir2[V__5_1] << ", " << "V__1_2: " << line3InDir_arg2_dir2[V__1_2] << ", " << "V__2_2: " << line3InDir_arg2_dir2[V__2_2] << ", " << "V__3_2: " << line3InDir_arg2_dir2[V__3_2] << ", " << "V__4_2: " << line3InDir_arg2_dir2[V__4_2] << ", " << "V__5_2: " << line3InDir_arg2_dir2[V__5_2] << ", " << "V__6_2: " << line3InDir_arg2_dir2[V__6_2] << ", " << "V__1_3: " << line3InDir_arg2_dir2[V__1_3] << ", " << "V__2_3: " << line3InDir_arg2_dir2[V__2_3] << ", " << "V__3_3: " << line3InDir_arg2_dir2[V__3_3] << ", " << "V__4_3: " << line3InDir_arg2_dir2[V__4_3] << ", " << "V__5_3: " << line3InDir_arg2_dir2[V__5_3] << ", " << "V__6_3: " << line3InDir_arg2_dir2[V__6_3] << ", " << "V__7_3: " << line3InDir_arg2_dir2[V__7_3] << ", " << "V__1_4: " << line3InDir_arg2_dir2[V__1_4] << ", " << "V__2_4: " << line3InDir_arg2_dir2[V__2_4] << ", " << "V__3_4: " << line3InDir_arg2_dir2[V__3_4] << ", " << "V__4_4: " << line3InDir_arg2_dir2[V__4_4] << ", " << "V__5_4: " << line3InDir_arg2_dir2[V__5_4] << ", " << "V__6_4: " << line3InDir_arg2_dir2[V__6_4] << ", " << "V__7_4: " << line3InDir_arg2_dir2[V__7_4] << ", " << "V__8_4: " << line3InDir_arg2_dir2[V__8_4] << ", " << "V__1_5: " << line3InDir_arg2_dir2[V__1_5] << ", " << "V__2_5: " << line3InDir_arg2_dir2[V__2_5] << ", " << "V__3_5: " << line3InDir_arg2_dir2[V__3_5] << ", " << "V__4_5: " << line3InDir_arg2_dir2[V__4_5] << ", " << "V__5_5: " << line3InDir_arg2_dir2[V__5_5] << ", " << "V__6_5: " << line3InDir_arg2_dir2[V__6_5] << ", " << "V__7_5: " << line3InDir_arg2_dir2[V__7_5] << ", " << "V__8_5: " << line3InDir_arg2_dir2[V__8_5] << ", " << "V__9_5: " << line3InDir_arg2_dir2[V__9_5] << ", " << "V__2_6: " << line3InDir_arg2_dir2[V__2_6] << ", " << "V__3_6: " << line3InDir_arg2_dir2[V__3_6] << ", " << "V__4_6: " << line3InDir_arg2_dir2[V__4_6] << ", " << "V__5_6: " << line3InDir_arg2_dir2[V__5_6] << ", " << "V__6_6: " << line3InDir_arg2_dir2[V__6_6] << ", " << "V__7_6: " << line3InDir_arg2_dir2[V__7_6] << ", " << "V__8_6: " << line3InDir_arg2_dir2[V__8_6] << ", " << "V__9_6: " << line3InDir_arg2_dir2[V__9_6] << ", " << "V__3_7: " << line3InDir_arg2_dir2[V__3_7] << ", " << "V__4_7: " << line3InDir_arg2_dir2[V__4_7] << ", " << "V__5_7: " << line3InDir_arg2_dir2[V__5_7] << ", " << "V__6_7: " << line3InDir_arg2_dir2[V__6_7] << ", " << "V__7_7: " << line3InDir_arg2_dir2[V__7_7] << ", " << "V__8_7: " << line3InDir_arg2_dir2[V__8_7] << ", " << "V__9_7: " << line3InDir_arg2_dir2[V__9_7] << ", " << "V__4_8: " << line3InDir_arg2_dir2[V__4_8] << ", " << "V__5_8: " << line3InDir_arg2_dir2[V__5_8] << ", " << "V__6_8: " << line3InDir_arg2_dir2[V__6_8] << ", " << "V__7_8: " << line3InDir_arg2_dir2[V__7_8] << ", " << "V__8_8: " << line3InDir_arg2_dir2[V__8_8] << ", " << "V__9_8: " << line3InDir_arg2_dir2[V__9_8] << ", " << "V__5_9: " << line3InDir_arg2_dir2[V__5_9] << ", " << "V__6_9: " << line3InDir_arg2_dir2[V__6_9] << ", " << "V__7_9: " << line3InDir_arg2_dir2[V__7_9] << ", " << "V__8_9: " << line3InDir_arg2_dir2[V__8_9] << ", " << "V__9_9: " << line3InDir_arg2_dir2[V__9_9]<< "}" << std::endl;
    ss << "line4_arg0_p = " << line4_arg0_p << std::endl;
    ss << "line4InDir_arg0_p = " << line4InDir_arg0_p << std::endl;
    ss << "line4InDir_arg1_dir1 = " << "{" << "null: " << line4InDir_arg1_dir1[null] << ", " << "V__1_1: " << line4InDir_arg1_dir1[V__1_1] << ", " << "V__2_1: " << line4InDir_arg1_dir1[V__2_1] << ", " << "V__3_1: " << line4InDir_arg1_dir1[V__3_1] << ", " << "V__4_1: " << line4InDir_arg1_dir1[V__4_1] << ", " << "V__5_1: " << line4InDir_arg1_dir1[V__5_1] << ", " << "V__1_2: " << line4InDir_arg1_dir1[V__1_2] << ", " << "V__2_2: " << line4InDir_arg1_dir1[V__2_2] << ", " << "V__3_2: " << line4InDir_arg1_dir1[V__3_2] << ", " << "V__4_2: " << line4InDir_arg1_dir1[V__4_2] << ", " << "V__5_2: " << line4InDir_arg1_dir1[V__5_2] << ", " << "V__6_2: " << line4InDir_arg1_dir1[V__6_2] << ", " << "V__1_3: " << line4InDir_arg1_dir1[V__1_3] << ", " << "V__2_3: " << line4InDir_arg1_dir1[V__2_3] << ", " << "V__3_3: " << line4InDir_arg1_dir1[V__3_3] << ", " << "V__4_3: " << line4InDir_arg1_dir1[V__4_3] << ", " << "V__5_3: " << line4InDir_arg1_dir1[V__5_3] << ", " << "V__6_3: " << line4InDir_arg1_dir1[V__6_3] << ", " << "V__7_3: " << line4InDir_arg1_dir1[V__7_3] << ", " << "V__1_4: " << line4InDir_arg1_dir1[V__1_4] << ", " << "V__2_4: " << line4InDir_arg1_dir1[V__2_4] << ", " << "V__3_4: " << line4InDir_arg1_dir1[V__3_4] << ", " << "V__4_4: " << line4InDir_arg1_dir1[V__4_4] << ", " << "V__5_4: " << line4InDir_arg1_dir1[V__5_4] << ", " << "V__6_4: " << line4InDir_arg1_dir1[V__6_4] << ", " << "V__7_4: " << line4InDir_arg1_dir1[V__7_4] << ", " << "V__8_4: " << line4InDir_arg1_dir1[V__8_4] << ", " << "V__1_5: " << line4InDir_arg1_dir1[V__1_5] << ", " << "V__2_5: " << line4InDir_arg1_dir1[V__2_5] << ", " << "V__3_5: " << line4InDir_arg1_dir1[V__3_5] << ", " << "V__4_5: " << line4InDir_arg1_dir1[V__4_5] << ", " << "V__5_5: " << line4InDir_arg1_dir1[V__5_5] << ", " << "V__6_5: " << line4InDir_arg1_dir1[V__6_5] << ", " << "V__7_5: " << line4InDir_arg1_dir1[V__7_5] << ", " << "V__8_5: " << line4InDir_arg1_dir1[V__8_5] << ", " << "V__9_5: " << line4InDir_arg1_dir1[V__9_5] << ", " << "V__2_6: " << line4InDir_arg1_dir1[V__2_6] << ", " << "V__3_6: " << line4InDir_arg1_dir1[V__3_6] << ", " << "V__4_6: " << line4InDir_arg1_dir1[V__4_6] << ", " << "V__5_6: " << line4InDir_arg1_dir1[V__5_6] << ", " << "V__6_6: " << line4InDir_arg1_dir1[V__6_6] << ", " << "V__7_6: " << line4InDir_arg1_dir1[V__7_6] << ", " << "V__8_6: " << line4InDir_arg1_dir1[V__8_6] << ", " << "V__9_6: " << line4InDir_arg1_dir1[V__9_6] << ", " << "V__3_7: " << line4InDir_arg1_dir1[V__3_7] << ", " << "V__4_7: " << line4InDir_arg1_dir1[V__4_7] << ", " << "V__5_7: " << line4InDir_arg1_dir1[V__5_7] << ", " << "V__6_7: " << line4InDir_arg1_dir1[V__6_7] << ", " << "V__7_7: " << line4InDir_arg1_dir1[V__7_7] << ", " << "V__8_7: " << line4InDir_arg1_dir1[V__8_7] << ", " << "V__9_7: " << line4InDir_arg1_dir1[V__9_7] << ", " << "V__4_8: " << line4InDir_arg1_dir1[V__4_8] << ", " << "V__5_8: " << line4InDir_arg1_dir1[V__5_8] << ", " << "V__6_8: " << line4InDir_arg1_dir1[V__6_8] << ", " << "V__7_8: " << line4InDir_arg1_dir1[V__7_8] << ", " << "V__8_8: " << line4InDir_arg1_dir1[V__8_8] << ", " << "V__9_8: " << line4InDir_arg1_dir1[V__9_8] << ", " << "V__5_9: " << line4InDir_arg1_dir1[V__5_9] << ", " << "V__6_9: " << line4InDir_arg1_dir1[V__6_9] << ", " << "V__7_9: " << line4InDir_arg1_dir1[V__7_9] << ", " << "V__8_9: " << line4InDir_arg1_dir1[V__8_9] << ", " << "V__9_9: " << line4InDir_arg1_dir1[V__9_9]<< "}" << std::endl;
    ss << "line4InDir_arg2_dir2 = " << "{" << "null: " << line4InDir_arg2_dir2[null] << ", " << "V__1_1: " << line4InDir_arg2_dir2[V__1_1] << ", " << "V__2_1: " << line4InDir_arg2_dir2[V__2_1] << ", " << "V__3_1: " << line4InDir_arg2_dir2[V__3_1] << ", " << "V__4_1: " << line4InDir_arg2_dir2[V__4_1] << ", " << "V__5_1: " << line4InDir_arg2_dir2[V__5_1] << ", " << "V__1_2: " << line4InDir_arg2_dir2[V__1_2] << ", " << "V__2_2: " << line4InDir_arg2_dir2[V__2_2] << ", " << "V__3_2: " << line4InDir_arg2_dir2[V__3_2] << ", " << "V__4_2: " << line4InDir_arg2_dir2[V__4_2] << ", " << "V__5_2: " << line4InDir_arg2_dir2[V__5_2] << ", " << "V__6_2: " << line4InDir_arg2_dir2[V__6_2] << ", " << "V__1_3: " << line4InDir_arg2_dir2[V__1_3] << ", " << "V__2_3: " << line4InDir_arg2_dir2[V__2_3] << ", " << "V__3_3: " << line4InDir_arg2_dir2[V__3_3] << ", " << "V__4_3: " << line4InDir_arg2_dir2[V__4_3] << ", " << "V__5_3: " << line4InDir_arg2_dir2[V__5_3] << ", " << "V__6_3: " << line4InDir_arg2_dir2[V__6_3] << ", " << "V__7_3: " << line4InDir_arg2_dir2[V__7_3] << ", " << "V__1_4: " << line4InDir_arg2_dir2[V__1_4] << ", " << "V__2_4: " << line4InDir_arg2_dir2[V__2_4] << ", " << "V__3_4: " << line4InDir_arg2_dir2[V__3_4] << ", " << "V__4_4: " << line4InDir_arg2_dir2[V__4_4] << ", " << "V__5_4: " << line4InDir_arg2_dir2[V__5_4] << ", " << "V__6_4: " << line4InDir_arg2_dir2[V__6_4] << ", " << "V__7_4: " << line4InDir_arg2_dir2[V__7_4] << ", " << "V__8_4: " << line4InDir_arg2_dir2[V__8_4] << ", " << "V__1_5: " << line4InDir_arg2_dir2[V__1_5] << ", " << "V__2_5: " << line4InDir_arg2_dir2[V__2_5] << ", " << "V__3_5: " << line4InDir_arg2_dir2[V__3_5] << ", " << "V__4_5: " << line4InDir_arg2_dir2[V__4_5] << ", " << "V__5_5: " << line4InDir_arg2_dir2[V__5_5] << ", " << "V__6_5: " << line4InDir_arg2_dir2[V__6_5] << ", " << "V__7_5: " << line4InDir_arg2_dir2[V__7_5] << ", " << "V__8_5: " << line4InDir_arg2_dir2[V__8_5] << ", " << "V__9_5: " << line4InDir_arg2_dir2[V__9_5] << ", " << "V__2_6: " << line4InDir_arg2_dir2[V__2_6] << ", " << "V__3_6: " << line4InDir_arg2_dir2[V__3_6] << ", " << "V__4_6: " << line4InDir_arg2_dir2[V__4_6] << ", " << "V__5_6: " << line4InDir_arg2_dir2[V__5_6] << ", " << "V__6_6: " << line4InDir_arg2_dir2[V__6_6] << ", " << "V__7_6: " << line4InDir_arg2_dir2[V__7_6] << ", " << "V__8_6: " << line4InDir_arg2_dir2[V__8_6] << ", " << "V__9_6: " << line4InDir_arg2_dir2[V__9_6] << ", " << "V__3_7: " << line4InDir_arg2_dir2[V__3_7] << ", " << "V__4_7: " << line4InDir_arg2_dir2[V__4_7] << ", " << "V__5_7: " << line4InDir_arg2_dir2[V__5_7] << ", " << "V__6_7: " << line4InDir_arg2_dir2[V__6_7] << ", " << "V__7_7: " << line4InDir_arg2_dir2[V__7_7] << ", " << "V__8_7: " << line4InDir_arg2_dir2[V__8_7] << ", " << "V__9_7: " << line4InDir_arg2_dir2[V__9_7] << ", " << "V__4_8: " << line4InDir_arg2_dir2[V__4_8] << ", " << "V__5_8: " << line4InDir_arg2_dir2[V__5_8] << ", " << "V__6_8: " << line4InDir_arg2_dir2[V__6_8] << ", " << "V__7_8: " << line4InDir_arg2_dir2[V__7_8] << ", " << "V__8_8: " << line4InDir_arg2_dir2[V__8_8] << ", " << "V__9_8: " << line4InDir_arg2_dir2[V__9_8] << ", " << "V__5_9: " << line4InDir_arg2_dir2[V__5_9] << ", " << "V__6_9: " << line4InDir_arg2_dir2[V__6_9] << ", " << "V__7_9: " << line4InDir_arg2_dir2[V__7_9] << ", " << "V__8_9: " << line4InDir_arg2_dir2[V__8_9] << ", " << "V__9_9: " << line4InDir_arg2_dir2[V__9_9]<< "}" << std::endl;
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
        case 139:
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
        case 139:
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
        case 83:
{
            apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5();
            break;
}
        case 215:
{
            apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5();
            break;
}
    }
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_1()
{
    const auto old8_0 = line4_arg0_p;
    line4_arg0_p = turn_arg0_me;
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_2())
    {
        line4_arg0_p = old8_0;
        return true;
    }
    line4_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_2()
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_1()
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_2()
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_4()
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_6()
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_begin()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_1())
    {
        if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_2())
        {
            return true;
        }
    }
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_1())
    {
        if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_4())
        {
            return true;
        }
    }
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_1())
    {
        if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_line4_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = upLeft;
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = downRight;
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_4()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_10()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_13()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_4()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_7()
{
    if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_3_1_rules_3_turn_13_line4_3_line4InDir_end_rules_3_turn_13_line4_3_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = upRight;
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = downLeft;
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_4()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_10()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_13()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_4()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_7()
{
    if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_5_1_rules_3_turn_13_line4_5_line4InDir_end_rules_3_turn_13_line4_5_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = left;
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = right;
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_4()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_10()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_13()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_4()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_7()
{
    if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_13_line4_7_1_rules_3_turn_13_line4_7_line4InDir_end_rules_3_turn_13_line4_7_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_1()
{
    const auto old8_0 = line3_arg0_p;
    line3_arg0_p = turn_arg0_me;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_2())
    {
        line3_arg0_p = old8_0;
        return true;
    }
    line3_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_2()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_1()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_2()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_4()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_begin()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_1())
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_2())
        {
            return true;
        }
    }
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_1())
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_4())
        {
            return true;
        }
    }
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_1())
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_line3_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = upLeft;
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = downRight;
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_4()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_1()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_3()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_5()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_7()
{
    if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_3_1_rules_3_turn_9_line3_3_line3InDir_end_rules_3_turn_9_line3_3_line3InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = upRight;
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = downLeft;
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_4()
{
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_1()
{
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_3()
{
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_5()
{
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_7()
{
    if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_5_1_rules_3_turn_9_line3_5_line3InDir_end_rules_3_turn_9_line3_5_line3InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = left;
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = right;
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_4()
{
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_1()
{
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_3()
{
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_5()
{
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_7()
{
    if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_line3_7_1_rules_3_turn_9_line3_7_line3InDir_end_rules_3_turn_9_line3_7_line3InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_1()
{
    const auto old8_0 = line4_arg0_p;
    line4_arg0_p = turn_arg0_me;
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_2())
    {
        line4_arg0_p = old8_0;
        return true;
    }
    line4_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_2()
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_1()
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_2()
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_4()
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_6()
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_begin()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_1())
    {
        if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_2())
        {
            return true;
        }
    }
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_1())
    {
        if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_4())
        {
            return true;
        }
    }
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_1())
    {
        if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_line4_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = upLeft;
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = downRight;
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_4()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_10()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_13()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_4()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_7()
{
    if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_3_1_rules_5_turn_13_line4_3_line4InDir_end_rules_5_turn_13_line4_3_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = upRight;
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = downLeft;
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_4()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_10()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_13()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_4()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_7()
{
    if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_5_1_rules_5_turn_13_line4_5_line4InDir_end_rules_5_turn_13_line4_5_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_1()
{
    const auto old19_0 = line4InDir_arg0_p;
    line4InDir_arg0_p = line4_arg0_p;
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_2())
    {
        line4InDir_arg0_p = old19_0;
        return true;
    }
    line4InDir_arg0_p = old19_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_2()
{
    const auto old20_0 = line4InDir_arg1_dir1;
    line4InDir_arg1_dir1 = left;
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_3())
    {
        line4InDir_arg1_dir1 = old20_0;
        return true;
    }
    line4InDir_arg1_dir1 = old20_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_3()
{
    const auto old21_0 = line4InDir_arg2_dir2;
    line4InDir_arg2_dir2 = right;
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_4())
    {
        line4InDir_arg2_dir2 = old21_0;
        return true;
    }
    line4InDir_arg2_dir2 = old21_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_4()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_10()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_11()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_12()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_13()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_2()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_3()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_4())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_4()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_5()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_6()
{
    if (board[line4InDir_arg1_dir1[line4InDir_arg1_dir1[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_7()
{
    if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_8()
{
    if (board[line4InDir_arg2_dir2[line4InDir_arg2_dir2[pos]]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_9())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_9()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_begin()
{
    if (board[line4InDir_arg1_dir1[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_2())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_5())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_8())
        {
            return true;
        }
    }
    if (board[line4InDir_arg2_dir2[pos]]==line4InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_13_line4_7_1_rules_5_turn_13_line4_7_line4InDir_end_rules_5_turn_13_line4_7_line4InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_1()
{
    const auto old8_0 = line3_arg0_p;
    line3_arg0_p = turn_arg0_me;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_2())
    {
        line3_arg0_p = old8_0;
        return true;
    }
    line3_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_2()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_1()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_2()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_4()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_begin()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_1())
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_2())
        {
            return true;
        }
    }
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_1())
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_4())
        {
            return true;
        }
    }
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_1())
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_line3_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = upLeft;
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = downRight;
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_4()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_1()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_3()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_5()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_7()
{
    if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_3_1_rules_5_turn_9_line3_3_line3InDir_end_rules_5_turn_9_line3_3_line3InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = upRight;
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = downLeft;
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_4()
{
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_1()
{
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_3()
{
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_5()
{
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_7()
{
    if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_5_1_rules_5_turn_9_line3_5_line3InDir_end_rules_5_turn_9_line3_5_line3InDir_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_1()
{
    const auto old13_0 = line3InDir_arg0_p;
    line3InDir_arg0_p = line3_arg0_p;
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_2())
    {
        line3InDir_arg0_p = old13_0;
        return true;
    }
    line3InDir_arg0_p = old13_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_2()
{
    const auto old14_0 = line3InDir_arg1_dir1;
    line3InDir_arg1_dir1 = left;
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_3())
    {
        line3InDir_arg1_dir1 = old14_0;
        return true;
    }
    line3InDir_arg1_dir1 = old14_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_3()
{
    const auto old15_0 = line3InDir_arg2_dir2;
    line3InDir_arg2_dir2 = right;
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_4())
    {
        line3InDir_arg2_dir2 = old15_0;
        return true;
    }
    line3InDir_arg2_dir2 = old15_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_4()
{
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_1()
{
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_2()
{
    if (board[line3InDir_arg1_dir1[line3InDir_arg1_dir1[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_3()
{
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_4()
{
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_5())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_5()
{
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_6()
{
    if (board[line3InDir_arg2_dir2[line3InDir_arg2_dir2[pos]]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_7()
{
    if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_begin()
{
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_2())
        {
            return true;
        }
    }
    if (board[line3InDir_arg1_dir1[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_4())
        {
            return true;
        }
    }
    if (board[line3InDir_arg2_dir2[pos]]==line3InDir_arg0_p)
    {
        if (is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_line3_7_1_rules_5_turn_9_line3_7_line3InDir_end_rules_5_turn_9_line3_7_line3InDir_end()
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
    const auto old272_0 = turn_arg0_me;
    turn_arg0_me = white;
    state_rules_3__1(moves, mr);
    turn_arg0_me = old272_0;
}

void GameState::state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old273_0 = turn_arg1_op;
    turn_arg1_op = black;
    state_rules_3__2(moves, mr);
    turn_arg1_op = old273_0;
}

void GameState::state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_begin(moves, mr);
}

void GameState::state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old276_0 = pos;
    for (pos = V__1_1; pos <= V__9_9; ++pos)
    {
    state_rules_3_turn_2(moves, mr);    }
    pos = old276_0;
}

void GameState::state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old408_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_3_turn_14(moves, mr);
    goals[turn_arg0_me - 2] = old408_0;
}

void GameState::state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old411_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    state_rules_3_turn_16(moves, mr);
    goals[turn_arg0_me - 2] = old411_0;
}

void GameState::state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old409_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    state_rules_3_turn_15(moves, mr);
    goals[turn_arg1_op - 2] = old409_0;
}

void GameState::state_rules_3_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_12(moves, mr);
}

void GameState::state_rules_3_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old412_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    state_rules_3_turn_17(moves, mr);
    goals[turn_arg1_op - 2] = old412_0;
}

void GameState::state_rules_3_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_12(moves, mr);
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
    const auto old280_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_3_turn_6(moves, mr);
    board[pos] = old280_0;
}

void GameState::state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_1())
    {
        state_rules_3_turn_7(moves, mr);
        return;
    }
    state_rules_3_turn_8(moves, mr);
}

void GameState::state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_1())
    {
        state_rules_3_turn_10(moves, mr);
        return;
    }
    state_rules_3_turn_11(moves, mr);
}

void GameState::state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_end(moves, mr);
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
    const auto old417_0 = turn_arg0_me;
    turn_arg0_me = black;
    state_rules_5__1(moves, mr);
    turn_arg0_me = old417_0;
}

void GameState::state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old418_0 = turn_arg1_op;
    turn_arg1_op = white;
    state_rules_5__2(moves, mr);
    turn_arg1_op = old418_0;
}

void GameState::state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_begin(moves, mr);
}

void GameState::state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old421_0 = pos;
    for (pos = V__1_1; pos <= V__9_9; ++pos)
    {
    state_rules_5_turn_2(moves, mr);    }
    pos = old421_0;
}

void GameState::state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old553_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_5_turn_14(moves, mr);
    goals[turn_arg0_me - 2] = old553_0;
}

void GameState::state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old556_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    state_rules_5_turn_16(moves, mr);
    goals[turn_arg0_me - 2] = old556_0;
}

void GameState::state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old554_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    state_rules_5_turn_15(moves, mr);
    goals[turn_arg1_op - 2] = old554_0;
}

void GameState::state_rules_5_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_12(moves, mr);
}

void GameState::state_rules_5_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old557_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    state_rules_5_turn_17(moves, mr);
    goals[turn_arg1_op - 2] = old557_0;
}

void GameState::state_rules_5_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_12(moves, mr);
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
    const auto old425_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_5_turn_6(moves, mr);
    board[pos] = old425_0;
}

void GameState::state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_1())
    {
        state_rules_5_turn_7(moves, mr);
        return;
    }
    state_rules_5_turn_8(moves, mr);
}

void GameState::state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_1())
    {
        state_rules_5_turn_10(moves, mr);
        return;
    }
    state_rules_5_turn_11(moves, mr);
}

void GameState::state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_end(moves, mr);
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
    const auto old272_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_state_rules_3__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old272_0;
    return false;
}

bool GameState::apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old273_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_state_rules_3__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old273_0;
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
            currentState = 83;
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
    const auto old408_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_3_turn_14(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old408_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old411_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    if (apply_state_rules_3_turn_16(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old411_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old414_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old414_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old409_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_state_rules_3_turn_15(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old409_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_12(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old412_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    if (apply_state_rules_3_turn_17(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old412_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_12(mr,rgCache))
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
    const auto old279_0 = player;
    player = keeper;
    currentState = 83;
    return true;
    player = old279_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old280_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_3_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old280_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_1())
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
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_1())
    {
        if (apply_state_rules_3_turn_10(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_3_turn_11(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old275_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    player = old275_0;
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
    const auto old417_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_state_rules_5__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old417_0;
    return false;
}

bool GameState::apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old418_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_state_rules_5__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old418_0;
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
            currentState = 215;
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
    const auto old553_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_5_turn_14(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old553_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old556_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    if (apply_state_rules_5_turn_16(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old556_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old559_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old559_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old554_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_state_rules_5_turn_15(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old554_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_12(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old557_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    if (apply_state_rules_5_turn_17(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old557_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_12(mr,rgCache))
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
    const auto old424_0 = player;
    player = keeper;
    currentState = 215;
    return true;
    player = old424_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old425_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_5_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old425_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_1())
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
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_1())
    {
        if (apply_state_rules_5_turn_10(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_5_turn_11(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old420_0 = player;
    player = turn_arg0_me;
    currentState = 139;
    return true;
    player = old420_0;
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
    const auto old23_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_14())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old23_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11()
{
    const auto old26_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_16())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old26_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12()
{
    const auto old29_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_end())
    {
        return true;
    }
    player = old29_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_14()
{
    const auto old24_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_15())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old24_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_15()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_16()
{
    const auto old27_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_17())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old27_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_17()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5()
{
    const auto old18_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6())
    {
        return true;
    }
    board[pos] = old18_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6()
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_line3_end_rules_3_turn_9_1())
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
    if (is_legal_rules_3_turn_13_1_rules_3_turn_13_line4_end_rules_3_turn_13_1())
    {
        if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_11())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8()
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end())
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
    const auto old32_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1())
    {
        return true;
    }
    turn_arg0_me = old32_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1()
{
    const auto old33_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2())
    {
        return true;
    }
    turn_arg1_op = old33_0;
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
    const auto old35_0 = player;
    player = turn_arg0_me;
    currentState = 139;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1())
    {
        return true;
    }
    player = old35_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_end()
{
    return true;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_1()
{
    const auto old19_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1())
    {
        return true;
    }
    turn_arg0_me = old19_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1()
{
    const auto old20_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2())
    {
        return true;
    }
    turn_arg1_op = old20_0;
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
    const auto old22_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10()
{
    const auto old28_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_14())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old28_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11()
{
    const auto old31_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 0;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_16())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old31_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12()
{
    const auto old34_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_end())
    {
        return true;
    }
    player = old34_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_14()
{
    const auto old29_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 0;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_15())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old29_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_15()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_16()
{
    const auto old32_0 = goals[turn_arg1_op - 2];
    goals[turn_arg1_op - 2] = 100;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_17())
    {
        return true;
    }
    goals[turn_arg1_op - 2] = old32_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_17()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5()
{
    const auto old23_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6())
    {
        return true;
    }
    board[pos] = old23_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6()
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_line3_end_rules_5_turn_9_1())
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
    if (is_legal_rules_5_turn_13_1_rules_5_turn_13_line4_end_rules_5_turn_13_1())
    {
        if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_11())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8()
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end())
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
