#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.win_arg0_p) ^ hash(gameState.reachableEdge_arg0_p) ^ hash(gameState.reachableEdge_arg1_edge) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.turn_arg1_op) ^ hash(gameState.win_arg0_p) ^ hash(gameState.reachableEdge_arg0_p) ^ hash(gameState.reachableEdge_arg1_edge) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && turn_arg0_me==rhs.turn_arg0_me && turn_arg1_op==rhs.turn_arg1_op && win_arg0_p==rhs.win_arg0_p && reachableEdge_arg0_p==rhs.reachableEdge_arg0_p && reachableEdge_arg1_edge==rhs.reachableEdge_arg1_edge && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_6: " << board[V__1_6] << ", " << "V__1_7: " << board[V__1_7] << ", " << "V__1_8: " << board[V__1_8] << ", " << "V__1_9: " << board[V__1_9] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__2_7: " << board[V__2_7] << ", " << "V__2_8: " << board[V__2_8] << ", " << "V__2_9: " << board[V__2_9] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__3_8: " << board[V__3_8] << ", " << "V__3_9: " << board[V__3_9] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__4_7: " << board[V__4_7] << ", " << "V__4_8: " << board[V__4_8] << ", " << "V__4_9: " << board[V__4_9] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__5_8: " << board[V__5_8] << ", " << "V__5_9: " << board[V__5_9] << ", " << "V__6_1: " << board[V__6_1] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__6_7: " << board[V__6_7] << ", " << "V__6_8: " << board[V__6_8] << ", " << "V__6_9: " << board[V__6_9] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_2: " << board[V__7_2] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_6: " << board[V__7_6] << ", " << "V__7_7: " << board[V__7_7] << ", " << "V__7_8: " << board[V__7_8] << ", " << "V__7_9: " << board[V__7_9] << ", " << "V__8_1: " << board[V__8_1] << ", " << "V__8_2: " << board[V__8_2] << ", " << "V__8_3: " << board[V__8_3] << ", " << "V__8_4: " << board[V__8_4] << ", " << "V__8_5: " << board[V__8_5] << ", " << "V__8_6: " << board[V__8_6] << ", " << "V__8_7: " << board[V__8_7] << ", " << "V__8_8: " << board[V__8_8] << ", " << "V__8_9: " << board[V__8_9] << ", " << "V__9_1: " << board[V__9_1] << ", " << "V__9_2: " << board[V__9_2] << ", " << "V__9_3: " << board[V__9_3] << ", " << "V__9_4: " << board[V__9_4] << ", " << "V__9_5: " << board[V__9_5] << ", " << "V__9_6: " << board[V__9_6] << ", " << "V__9_7: " << board[V__9_7] << ", " << "V__9_8: " << board[V__9_8] << ", " << "V__9_9: " << board[V__9_9]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "turn_arg0_me = " << turn_arg0_me << std::endl;
    ss << "turn_arg1_op = " << turn_arg1_op << std::endl;
    ss << "win_arg0_p = " << win_arg0_p << std::endl;
    ss << "reachableEdge_arg0_p = " << reachableEdge_arg0_p << std::endl;
    ss << "reachableEdge_arg1_edge = " << "{" << "white: " << "{" << "null: " << reachableEdge_arg1_edge[white-2][null] << ", " << "V__1_1: " << reachableEdge_arg1_edge[white-2][V__1_1] << ", " << "V__1_2: " << reachableEdge_arg1_edge[white-2][V__1_2] << ", " << "V__1_3: " << reachableEdge_arg1_edge[white-2][V__1_3] << ", " << "V__1_4: " << reachableEdge_arg1_edge[white-2][V__1_4] << ", " << "V__1_5: " << reachableEdge_arg1_edge[white-2][V__1_5] << ", " << "V__1_6: " << reachableEdge_arg1_edge[white-2][V__1_6] << ", " << "V__1_7: " << reachableEdge_arg1_edge[white-2][V__1_7] << ", " << "V__1_8: " << reachableEdge_arg1_edge[white-2][V__1_8] << ", " << "V__1_9: " << reachableEdge_arg1_edge[white-2][V__1_9] << ", " << "V__2_1: " << reachableEdge_arg1_edge[white-2][V__2_1] << ", " << "V__2_2: " << reachableEdge_arg1_edge[white-2][V__2_2] << ", " << "V__2_3: " << reachableEdge_arg1_edge[white-2][V__2_3] << ", " << "V__2_4: " << reachableEdge_arg1_edge[white-2][V__2_4] << ", " << "V__2_5: " << reachableEdge_arg1_edge[white-2][V__2_5] << ", " << "V__2_6: " << reachableEdge_arg1_edge[white-2][V__2_6] << ", " << "V__2_7: " << reachableEdge_arg1_edge[white-2][V__2_7] << ", " << "V__2_8: " << reachableEdge_arg1_edge[white-2][V__2_8] << ", " << "V__2_9: " << reachableEdge_arg1_edge[white-2][V__2_9] << ", " << "V__3_1: " << reachableEdge_arg1_edge[white-2][V__3_1] << ", " << "V__3_2: " << reachableEdge_arg1_edge[white-2][V__3_2] << ", " << "V__3_3: " << reachableEdge_arg1_edge[white-2][V__3_3] << ", " << "V__3_4: " << reachableEdge_arg1_edge[white-2][V__3_4] << ", " << "V__3_5: " << reachableEdge_arg1_edge[white-2][V__3_5] << ", " << "V__3_6: " << reachableEdge_arg1_edge[white-2][V__3_6] << ", " << "V__3_7: " << reachableEdge_arg1_edge[white-2][V__3_7] << ", " << "V__3_8: " << reachableEdge_arg1_edge[white-2][V__3_8] << ", " << "V__3_9: " << reachableEdge_arg1_edge[white-2][V__3_9] << ", " << "V__4_1: " << reachableEdge_arg1_edge[white-2][V__4_1] << ", " << "V__4_2: " << reachableEdge_arg1_edge[white-2][V__4_2] << ", " << "V__4_3: " << reachableEdge_arg1_edge[white-2][V__4_3] << ", " << "V__4_4: " << reachableEdge_arg1_edge[white-2][V__4_4] << ", " << "V__4_5: " << reachableEdge_arg1_edge[white-2][V__4_5] << ", " << "V__4_6: " << reachableEdge_arg1_edge[white-2][V__4_6] << ", " << "V__4_7: " << reachableEdge_arg1_edge[white-2][V__4_7] << ", " << "V__4_8: " << reachableEdge_arg1_edge[white-2][V__4_8] << ", " << "V__4_9: " << reachableEdge_arg1_edge[white-2][V__4_9] << ", " << "V__5_1: " << reachableEdge_arg1_edge[white-2][V__5_1] << ", " << "V__5_2: " << reachableEdge_arg1_edge[white-2][V__5_2] << ", " << "V__5_3: " << reachableEdge_arg1_edge[white-2][V__5_3] << ", " << "V__5_4: " << reachableEdge_arg1_edge[white-2][V__5_4] << ", " << "V__5_5: " << reachableEdge_arg1_edge[white-2][V__5_5] << ", " << "V__5_6: " << reachableEdge_arg1_edge[white-2][V__5_6] << ", " << "V__5_7: " << reachableEdge_arg1_edge[white-2][V__5_7] << ", " << "V__5_8: " << reachableEdge_arg1_edge[white-2][V__5_8] << ", " << "V__5_9: " << reachableEdge_arg1_edge[white-2][V__5_9] << ", " << "V__6_1: " << reachableEdge_arg1_edge[white-2][V__6_1] << ", " << "V__6_2: " << reachableEdge_arg1_edge[white-2][V__6_2] << ", " << "V__6_3: " << reachableEdge_arg1_edge[white-2][V__6_3] << ", " << "V__6_4: " << reachableEdge_arg1_edge[white-2][V__6_4] << ", " << "V__6_5: " << reachableEdge_arg1_edge[white-2][V__6_5] << ", " << "V__6_6: " << reachableEdge_arg1_edge[white-2][V__6_6] << ", " << "V__6_7: " << reachableEdge_arg1_edge[white-2][V__6_7] << ", " << "V__6_8: " << reachableEdge_arg1_edge[white-2][V__6_8] << ", " << "V__6_9: " << reachableEdge_arg1_edge[white-2][V__6_9] << ", " << "V__7_1: " << reachableEdge_arg1_edge[white-2][V__7_1] << ", " << "V__7_2: " << reachableEdge_arg1_edge[white-2][V__7_2] << ", " << "V__7_3: " << reachableEdge_arg1_edge[white-2][V__7_3] << ", " << "V__7_4: " << reachableEdge_arg1_edge[white-2][V__7_4] << ", " << "V__7_5: " << reachableEdge_arg1_edge[white-2][V__7_5] << ", " << "V__7_6: " << reachableEdge_arg1_edge[white-2][V__7_6] << ", " << "V__7_7: " << reachableEdge_arg1_edge[white-2][V__7_7] << ", " << "V__7_8: " << reachableEdge_arg1_edge[white-2][V__7_8] << ", " << "V__7_9: " << reachableEdge_arg1_edge[white-2][V__7_9] << ", " << "V__8_1: " << reachableEdge_arg1_edge[white-2][V__8_1] << ", " << "V__8_2: " << reachableEdge_arg1_edge[white-2][V__8_2] << ", " << "V__8_3: " << reachableEdge_arg1_edge[white-2][V__8_3] << ", " << "V__8_4: " << reachableEdge_arg1_edge[white-2][V__8_4] << ", " << "V__8_5: " << reachableEdge_arg1_edge[white-2][V__8_5] << ", " << "V__8_6: " << reachableEdge_arg1_edge[white-2][V__8_6] << ", " << "V__8_7: " << reachableEdge_arg1_edge[white-2][V__8_7] << ", " << "V__8_8: " << reachableEdge_arg1_edge[white-2][V__8_8] << ", " << "V__8_9: " << reachableEdge_arg1_edge[white-2][V__8_9] << ", " << "V__9_1: " << reachableEdge_arg1_edge[white-2][V__9_1] << ", " << "V__9_2: " << reachableEdge_arg1_edge[white-2][V__9_2] << ", " << "V__9_3: " << reachableEdge_arg1_edge[white-2][V__9_3] << ", " << "V__9_4: " << reachableEdge_arg1_edge[white-2][V__9_4] << ", " << "V__9_5: " << reachableEdge_arg1_edge[white-2][V__9_5] << ", " << "V__9_6: " << reachableEdge_arg1_edge[white-2][V__9_6] << ", " << "V__9_7: " << reachableEdge_arg1_edge[white-2][V__9_7] << ", " << "V__9_8: " << reachableEdge_arg1_edge[white-2][V__9_8] << ", " << "V__9_9: " << reachableEdge_arg1_edge[white-2][V__9_9]<< "}" << ", " << "black: " << "{" << "null: " << reachableEdge_arg1_edge[black-2][null] << ", " << "V__1_1: " << reachableEdge_arg1_edge[black-2][V__1_1] << ", " << "V__1_2: " << reachableEdge_arg1_edge[black-2][V__1_2] << ", " << "V__1_3: " << reachableEdge_arg1_edge[black-2][V__1_3] << ", " << "V__1_4: " << reachableEdge_arg1_edge[black-2][V__1_4] << ", " << "V__1_5: " << reachableEdge_arg1_edge[black-2][V__1_5] << ", " << "V__1_6: " << reachableEdge_arg1_edge[black-2][V__1_6] << ", " << "V__1_7: " << reachableEdge_arg1_edge[black-2][V__1_7] << ", " << "V__1_8: " << reachableEdge_arg1_edge[black-2][V__1_8] << ", " << "V__1_9: " << reachableEdge_arg1_edge[black-2][V__1_9] << ", " << "V__2_1: " << reachableEdge_arg1_edge[black-2][V__2_1] << ", " << "V__2_2: " << reachableEdge_arg1_edge[black-2][V__2_2] << ", " << "V__2_3: " << reachableEdge_arg1_edge[black-2][V__2_3] << ", " << "V__2_4: " << reachableEdge_arg1_edge[black-2][V__2_4] << ", " << "V__2_5: " << reachableEdge_arg1_edge[black-2][V__2_5] << ", " << "V__2_6: " << reachableEdge_arg1_edge[black-2][V__2_6] << ", " << "V__2_7: " << reachableEdge_arg1_edge[black-2][V__2_7] << ", " << "V__2_8: " << reachableEdge_arg1_edge[black-2][V__2_8] << ", " << "V__2_9: " << reachableEdge_arg1_edge[black-2][V__2_9] << ", " << "V__3_1: " << reachableEdge_arg1_edge[black-2][V__3_1] << ", " << "V__3_2: " << reachableEdge_arg1_edge[black-2][V__3_2] << ", " << "V__3_3: " << reachableEdge_arg1_edge[black-2][V__3_3] << ", " << "V__3_4: " << reachableEdge_arg1_edge[black-2][V__3_4] << ", " << "V__3_5: " << reachableEdge_arg1_edge[black-2][V__3_5] << ", " << "V__3_6: " << reachableEdge_arg1_edge[black-2][V__3_6] << ", " << "V__3_7: " << reachableEdge_arg1_edge[black-2][V__3_7] << ", " << "V__3_8: " << reachableEdge_arg1_edge[black-2][V__3_8] << ", " << "V__3_9: " << reachableEdge_arg1_edge[black-2][V__3_9] << ", " << "V__4_1: " << reachableEdge_arg1_edge[black-2][V__4_1] << ", " << "V__4_2: " << reachableEdge_arg1_edge[black-2][V__4_2] << ", " << "V__4_3: " << reachableEdge_arg1_edge[black-2][V__4_3] << ", " << "V__4_4: " << reachableEdge_arg1_edge[black-2][V__4_4] << ", " << "V__4_5: " << reachableEdge_arg1_edge[black-2][V__4_5] << ", " << "V__4_6: " << reachableEdge_arg1_edge[black-2][V__4_6] << ", " << "V__4_7: " << reachableEdge_arg1_edge[black-2][V__4_7] << ", " << "V__4_8: " << reachableEdge_arg1_edge[black-2][V__4_8] << ", " << "V__4_9: " << reachableEdge_arg1_edge[black-2][V__4_9] << ", " << "V__5_1: " << reachableEdge_arg1_edge[black-2][V__5_1] << ", " << "V__5_2: " << reachableEdge_arg1_edge[black-2][V__5_2] << ", " << "V__5_3: " << reachableEdge_arg1_edge[black-2][V__5_3] << ", " << "V__5_4: " << reachableEdge_arg1_edge[black-2][V__5_4] << ", " << "V__5_5: " << reachableEdge_arg1_edge[black-2][V__5_5] << ", " << "V__5_6: " << reachableEdge_arg1_edge[black-2][V__5_6] << ", " << "V__5_7: " << reachableEdge_arg1_edge[black-2][V__5_7] << ", " << "V__5_8: " << reachableEdge_arg1_edge[black-2][V__5_8] << ", " << "V__5_9: " << reachableEdge_arg1_edge[black-2][V__5_9] << ", " << "V__6_1: " << reachableEdge_arg1_edge[black-2][V__6_1] << ", " << "V__6_2: " << reachableEdge_arg1_edge[black-2][V__6_2] << ", " << "V__6_3: " << reachableEdge_arg1_edge[black-2][V__6_3] << ", " << "V__6_4: " << reachableEdge_arg1_edge[black-2][V__6_4] << ", " << "V__6_5: " << reachableEdge_arg1_edge[black-2][V__6_5] << ", " << "V__6_6: " << reachableEdge_arg1_edge[black-2][V__6_6] << ", " << "V__6_7: " << reachableEdge_arg1_edge[black-2][V__6_7] << ", " << "V__6_8: " << reachableEdge_arg1_edge[black-2][V__6_8] << ", " << "V__6_9: " << reachableEdge_arg1_edge[black-2][V__6_9] << ", " << "V__7_1: " << reachableEdge_arg1_edge[black-2][V__7_1] << ", " << "V__7_2: " << reachableEdge_arg1_edge[black-2][V__7_2] << ", " << "V__7_3: " << reachableEdge_arg1_edge[black-2][V__7_3] << ", " << "V__7_4: " << reachableEdge_arg1_edge[black-2][V__7_4] << ", " << "V__7_5: " << reachableEdge_arg1_edge[black-2][V__7_5] << ", " << "V__7_6: " << reachableEdge_arg1_edge[black-2][V__7_6] << ", " << "V__7_7: " << reachableEdge_arg1_edge[black-2][V__7_7] << ", " << "V__7_8: " << reachableEdge_arg1_edge[black-2][V__7_8] << ", " << "V__7_9: " << reachableEdge_arg1_edge[black-2][V__7_9] << ", " << "V__8_1: " << reachableEdge_arg1_edge[black-2][V__8_1] << ", " << "V__8_2: " << reachableEdge_arg1_edge[black-2][V__8_2] << ", " << "V__8_3: " << reachableEdge_arg1_edge[black-2][V__8_3] << ", " << "V__8_4: " << reachableEdge_arg1_edge[black-2][V__8_4] << ", " << "V__8_5: " << reachableEdge_arg1_edge[black-2][V__8_5] << ", " << "V__8_6: " << reachableEdge_arg1_edge[black-2][V__8_6] << ", " << "V__8_7: " << reachableEdge_arg1_edge[black-2][V__8_7] << ", " << "V__8_8: " << reachableEdge_arg1_edge[black-2][V__8_8] << ", " << "V__8_9: " << reachableEdge_arg1_edge[black-2][V__8_9] << ", " << "V__9_1: " << reachableEdge_arg1_edge[black-2][V__9_1] << ", " << "V__9_2: " << reachableEdge_arg1_edge[black-2][V__9_2] << ", " << "V__9_3: " << reachableEdge_arg1_edge[black-2][V__9_3] << ", " << "V__9_4: " << reachableEdge_arg1_edge[black-2][V__9_4] << ", " << "V__9_5: " << reachableEdge_arg1_edge[black-2][V__9_5] << ", " << "V__9_6: " << reachableEdge_arg1_edge[black-2][V__9_6] << ", " << "V__9_7: " << reachableEdge_arg1_edge[black-2][V__9_7] << ", " << "V__9_8: " << reachableEdge_arg1_edge[black-2][V__9_8] << ", " << "V__9_9: " << reachableEdge_arg1_edge[black-2][V__9_9]<< "}"<< "}" << std::endl;
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
            state_rules_3_turn_1(moves, mr.mr,rgCache);
            return;
}
        case 51:
{
            state_rules_5_turn_1(moves, mr.mr,rgCache);
            return;
}
        case 1:
{
            state_begin(moves, mr.mr,rgCache);
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
        case 51:
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
            apply_any_begin_begin_begin(rgCache);
            break;
}
        case 12:
{
            apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5(rgCache);
            break;
}
        case 56:
{
            apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5(rgCache);
            break;
}
    }
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old8_0 = win_arg0_p;
    win_arg0_p = turn_arg0_me;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2(rgCache))
    {
        win_arg0_p = old8_0;
        return true;
    }
    win_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_2([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_2([[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==win_arg0_p)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_3([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_10.reset();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_12.reset();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_14.reset();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_16.reset();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_6.reset();
    rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_8.reset();
    const auto result_13 = is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_1(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_4([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = pos;
    for (const auto& posIt : firstEdgeiter[win_arg0_p - 2])
    {
    pos = posIt;
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_1(rgCache))
    {
        pos = old10_0;
        return true;
    }    }
    pos = old10_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_win_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = reachableEdge_arg0_p;
    reachableEdge_arg0_p = win_arg0_p;
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_2(rgCache))
    {
        reachableEdge_arg0_p = old21_0;
        return true;
    }
    reachableEdge_arg0_p = old21_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_2([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = reachableEdge_arg1_edge;
    reachableEdge_arg1_edge = secondEdge;
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_3(rgCache))
    {
        reachableEdge_arg1_edge = old22_0;
        return true;
    }
    reachableEdge_arg1_edge = old22_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_3([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_1([[maybe_unused]]RgCache& rgCache)
{
    if (!rgCache.insert(*this, 25))
    {
        return false;
    }
    if (reachableEdge_arg1_edge[reachableEdge_arg0_p - 2][pos]==1)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_3(rgCache))
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_4(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_10([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_10;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_11(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_12([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_12;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_13(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_13([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_14([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_14;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_15(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_15([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_16([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_16;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_17(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_17([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_3([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_4([[maybe_unused]]RgCache& rgCache)
{
    const auto old28_0 = pos;
    pos = upLeft[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_6(rgCache))
    {
        pos = old28_0;
        return true;
    }
    pos = old28_0;
    const auto old31_0 = pos;
    pos = upRight[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_8(rgCache))
    {
        pos = old31_0;
        return true;
    }
    pos = old31_0;
    const auto old34_0 = pos;
    pos = left[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_10(rgCache))
    {
        pos = old34_0;
        return true;
    }
    pos = old34_0;
    const auto old37_0 = pos;
    pos = right[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_12(rgCache))
    {
        pos = old37_0;
        return true;
    }
    pos = old37_0;
    const auto old40_0 = pos;
    pos = downLeft[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_14(rgCache))
    {
        pos = old40_0;
        return true;
    }
    pos = old40_0;
    const auto old43_0 = pos;
    pos = downRight[pos];
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_16(rgCache))
    {
        pos = old43_0;
        return true;
    }
    pos = old43_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5([[maybe_unused]]RgCache& rgCache)
{
    if (!rgCache.insert(*this, 37))
    {
        return false;
    }
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_6([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_6;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_7(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_7([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_8([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_3_turn_9_win_5_reachableEdge_8;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_9(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_9([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_begin([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_9_win_5_1_rules_3_turn_9_win_5_reachableEdge_end_rules_3_turn_9_win_5_reachableEdge_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old8_0 = win_arg0_p;
    win_arg0_p = turn_arg0_me;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2(rgCache))
    {
        win_arg0_p = old8_0;
        return true;
    }
    win_arg0_p = old8_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_2([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_2([[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==win_arg0_p)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_3([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_10.reset();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_12.reset();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_14.reset();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_16.reset();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_6.reset();
    rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_8.reset();
    const auto result_13 = is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_1(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_4([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = pos;
    for (const auto& posIt : firstEdgeiter[win_arg0_p - 2])
    {
    pos = posIt;
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_1(rgCache))
    {
        pos = old10_0;
        return true;
    }    }
    pos = old10_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_win_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = reachableEdge_arg0_p;
    reachableEdge_arg0_p = win_arg0_p;
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_2(rgCache))
    {
        reachableEdge_arg0_p = old21_0;
        return true;
    }
    reachableEdge_arg0_p = old21_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_2([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = reachableEdge_arg1_edge;
    reachableEdge_arg1_edge = secondEdge;
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_3(rgCache))
    {
        reachableEdge_arg1_edge = old22_0;
        return true;
    }
    reachableEdge_arg1_edge = old22_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_3([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_1([[maybe_unused]]RgCache& rgCache)
{
    if (!rgCache.insert(*this, 69))
    {
        return false;
    }
    if (reachableEdge_arg1_edge[reachableEdge_arg0_p - 2][pos]==1)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_3(rgCache))
        {
            return true;
        }
        return false;
    }
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_4(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_10([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_10;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_11(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_12([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_12;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_13(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_13([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_14([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_14;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_15(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_15([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_16([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_16;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_17(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_17([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_3([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_4([[maybe_unused]]RgCache& rgCache)
{
    const auto old28_0 = pos;
    pos = upLeft[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_6(rgCache))
    {
        pos = old28_0;
        return true;
    }
    pos = old28_0;
    const auto old31_0 = pos;
    pos = upRight[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_8(rgCache))
    {
        pos = old31_0;
        return true;
    }
    pos = old31_0;
    const auto old34_0 = pos;
    pos = left[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_10(rgCache))
    {
        pos = old34_0;
        return true;
    }
    pos = old34_0;
    const auto old37_0 = pos;
    pos = right[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_12(rgCache))
    {
        pos = old37_0;
        return true;
    }
    pos = old37_0;
    const auto old40_0 = pos;
    pos = downLeft[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_14(rgCache))
    {
        pos = old40_0;
        return true;
    }
    pos = old40_0;
    const auto old43_0 = pos;
    pos = downRight[pos];
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_16(rgCache))
    {
        pos = old43_0;
        return true;
    }
    pos = old43_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5([[maybe_unused]]RgCache& rgCache)
{
    if (!rgCache.insert(*this, 81))
    {
        return false;
    }
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_6([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_6;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_7(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_7([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_8([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_rules_5_turn_9_win_5_reachableEdge_8;
    if (cache.test(pos))
    {
        return false;
    }
    cache.set(pos);
    if (board[pos]==reachableEdge_arg0_p)
    {
        if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_9(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_9([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_begin([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_9_win_5_1_rules_5_turn_9_win_5_reachableEdge_end_rules_5_turn_9_win_5_reachableEdge_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_begin(moves, mr,rgCache);
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

void GameState::state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = turn_arg0_me;
    turn_arg0_me = white;
    state_rules_3__1(moves, mr,rgCache);
    turn_arg0_me = old96_0;
}

void GameState::state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = turn_arg1_op;
    turn_arg1_op = black;
    state_rules_3__2(moves, mr,rgCache);
    turn_arg1_op = old97_0;
}

void GameState::state_rules_3__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_3_turn_begin(moves, mr,rgCache);
}

void GameState::state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = pos;
    for (pos = V__1_1; pos <= V__9_9; ++pos)
    {
    state_rules_3_turn_2(moves, mr,rgCache);    }
    pos = old100_0;
}

void GameState::state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        state_rules_3_turn_3(moves, mr,rgCache);
    }
}

void GameState::state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + pos;
    state_rules_3_turn_4(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_3_turn_6(moves, mr,rgCache);
    board[pos] = old104_0;
}

void GameState::state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1(rgCache))
    {
        state_rules_3_turn_7(moves, mr,rgCache);
        return;
    }
    state_rules_3_turn_8(moves, mr,rgCache);
}

void GameState::state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old141_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_3_turn_10(moves, mr,rgCache);
    goals[turn_arg0_me - 2] = old141_0;
}

void GameState::state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_3_turn_end(moves, mr,rgCache);
}

void GameState::state_rules_3_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_4(moves, mr,rgCache);
}

void GameState::state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old145_0 = turn_arg0_me;
    turn_arg0_me = black;
    state_rules_5__1(moves, mr,rgCache);
    turn_arg0_me = old145_0;
}

void GameState::state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = turn_arg1_op;
    turn_arg1_op = white;
    state_rules_5__2(moves, mr,rgCache);
    turn_arg1_op = old146_0;
}

void GameState::state_rules_5__2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_5_turn_begin(moves, mr,rgCache);
}

void GameState::state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old149_0 = pos;
    for (pos = V__1_1; pos <= V__9_9; ++pos)
    {
    state_rules_5_turn_2(moves, mr,rgCache);    }
    pos = old149_0;
}

void GameState::state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        state_rules_5_turn_3(moves, mr,rgCache);
    }
}

void GameState::state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + pos;
    state_rules_5_turn_4(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old153_0 = board[pos];
    board[pos] = turn_arg0_me;
    state_rules_5_turn_6(moves, mr,rgCache);
    board[pos] = old153_0;
}

void GameState::state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1(rgCache))
    {
        state_rules_5_turn_7(moves, mr,rgCache);
        return;
    }
    state_rules_5_turn_8(moves, mr,rgCache);
}

void GameState::state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old190_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_5_turn_10(moves, mr,rgCache);
    goals[turn_arg0_me - 2] = old190_0;
}

void GameState::state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_5_turn_end(moves, mr,rgCache);
}

void GameState::state_rules_5_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_6(moves, mr,rgCache);
}

void GameState::state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_1(moves, mr,rgCache);
}

void GameState::state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_rules_1(moves, mr,rgCache);
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
    const auto old96_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_state_rules_3__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old96_0;
    return false;
}

bool GameState::apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_state_rules_3__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old97_0;
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
            currentState = 12;
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
    const auto old142_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old142_0;
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
    const auto old103_0 = player;
    player = keeper;
    currentState = 12;
    return true;
    player = old103_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_3_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old104_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1(rgCache))
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
    const auto old141_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_3_turn_10(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old141_0;
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
    const auto old99_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    player = old99_0;
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
    const auto old145_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_state_rules_5__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old145_0;
    return false;
}

bool GameState::apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_state_rules_5__2(mr,rgCache))
    {
        return true;
    }
    turn_arg1_op = old146_0;
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
            currentState = 56;
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
    const auto old191_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old191_0;
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
    const auto old152_0 = player;
    player = keeper;
    currentState = 56;
    return true;
    player = old152_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old153_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_state_rules_5_turn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old153_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1(rgCache))
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
    const auto old190_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_5_turn_10(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old190_0;
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
    const auto old148_0 = player;
    player = turn_arg0_me;
    currentState = 51;
    return true;
    player = old148_0;
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

bool GameState::apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_rules_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_rules_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_begin_begin_rules_3__1(rgCache))
    {
        return true;
    }
    turn_arg0_me = old9_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_3__1([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_any_begin_begin_rules_3__2(rgCache))
    {
        return true;
    }
    turn_arg1_op = old10_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_3__2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_rules_3_turn_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_rules_3_turn_1([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_rules_3_turn_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    if (apply_any_begin_begin_rules_3_turn_1(rgCache))
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_begin([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_rules_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_end(rgCache))
    {
        return true;
    }
    player = old16_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_5([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6(rgCache))
    {
        return true;
    }
    board[pos] = old12_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_6([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_3_turn_9_1_rules_3_turn_9_win_end_rules_3_turn_9_1(rgCache))
    {
        if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_7([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_10(rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old15_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_3_turn_end([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_4(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_4([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1(rgCache))
    {
        return true;
    }
    turn_arg0_me = old19_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__1([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = turn_arg1_op;
    turn_arg1_op = white;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2(rgCache))
    {
        return true;
    }
    turn_arg1_op = old20_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5__2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = player;
    player = turn_arg0_me;
    currentState = 51;
    return true;
    if (apply_any_rules_3_turn_5_rules_3_turn_5_rules_5_turn_1(rgCache))
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1(rgCache))
    {
        return true;
    }
    turn_arg0_me = old13_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__1([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = turn_arg1_op;
    turn_arg1_op = black;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2(rgCache))
    {
        return true;
    }
    turn_arg1_op = old14_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3__2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = player;
    player = turn_arg0_me;
    currentState = 7;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_3_turn_1(rgCache))
    {
        return true;
    }
    player = old16_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_end(rgCache))
    {
        return true;
    }
    player = old21_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_5([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = board[pos];
    board[pos] = turn_arg0_me;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6(rgCache))
    {
        return true;
    }
    board[pos] = old17_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_6([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_rules_5_turn_9_1_rules_5_turn_9_win_end_rules_5_turn_9_1(rgCache))
    {
        if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_7([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_10(rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old20_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_5_turn_end([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_5_rules_5_turn_5_rules_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_rules_5_turn_5_rules_5_turn_5_rules_1(rgCache))
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
