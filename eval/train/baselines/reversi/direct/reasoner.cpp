#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.me) ^ hash(gameState.pos) ^ hash(gameState.tmp) ^ hash(gameState.count) ^ hash(gameState.isCapture_arg0_dir) ^ hash(gameState.swapInLine_arg0_dir) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.me) ^ hash(gameState.pos) ^ hash(gameState.tmp) ^ hash(gameState.count) ^ hash(gameState.isCapture_arg0_dir) ^ hash(gameState.swapInLine_arg0_dir) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && me==rhs.me && pos==rhs.pos && tmp==rhs.tmp && count==rhs.count && isCapture_arg0_dir==rhs.isCapture_arg0_dir && swapInLine_arg0_dir==rhs.swapInLine_arg0_dir && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__0_0: " << board[V__0_0] << ", " << "V__0_1: " << board[V__0_1] << ", " << "V__0_2: " << board[V__0_2] << ", " << "V__0_3: " << board[V__0_3] << ", " << "V__0_4: " << board[V__0_4] << ", " << "V__0_5: " << board[V__0_5] << ", " << "V__0_6: " << board[V__0_6] << ", " << "V__0_7: " << board[V__0_7] << ", " << "V__1_0: " << board[V__1_0] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_6: " << board[V__1_6] << ", " << "V__1_7: " << board[V__1_7] << ", " << "V__2_0: " << board[V__2_0] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__2_7: " << board[V__2_7] << ", " << "V__3_0: " << board[V__3_0] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__4_0: " << board[V__4_0] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__4_7: " << board[V__4_7] << ", " << "V__5_0: " << board[V__5_0] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__6_0: " << board[V__6_0] << ", " << "V__6_1: " << board[V__6_1] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__6_7: " << board[V__6_7] << ", " << "V__7_0: " << board[V__7_0] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_2: " << board[V__7_2] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_6: " << board[V__7_6] << ", " << "V__7_7: " << board[V__7_7]<< "}" << std::endl;
    ss << "me = " << me << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "tmp = " << tmp << std::endl;
    ss << "count = " << "{" << "white: " << count[white-2] << ", " << "black: " << count[black-2]<< "}" << std::endl;
    ss << "isCapture_arg0_dir = " << "{" << "null: " << isCapture_arg0_dir[null] << ", " << "V__0_0: " << isCapture_arg0_dir[V__0_0] << ", " << "V__0_1: " << isCapture_arg0_dir[V__0_1] << ", " << "V__0_2: " << isCapture_arg0_dir[V__0_2] << ", " << "V__0_3: " << isCapture_arg0_dir[V__0_3] << ", " << "V__0_4: " << isCapture_arg0_dir[V__0_4] << ", " << "V__0_5: " << isCapture_arg0_dir[V__0_5] << ", " << "V__0_6: " << isCapture_arg0_dir[V__0_6] << ", " << "V__0_7: " << isCapture_arg0_dir[V__0_7] << ", " << "V__1_0: " << isCapture_arg0_dir[V__1_0] << ", " << "V__1_1: " << isCapture_arg0_dir[V__1_1] << ", " << "V__1_2: " << isCapture_arg0_dir[V__1_2] << ", " << "V__1_3: " << isCapture_arg0_dir[V__1_3] << ", " << "V__1_4: " << isCapture_arg0_dir[V__1_4] << ", " << "V__1_5: " << isCapture_arg0_dir[V__1_5] << ", " << "V__1_6: " << isCapture_arg0_dir[V__1_6] << ", " << "V__1_7: " << isCapture_arg0_dir[V__1_7] << ", " << "V__2_0: " << isCapture_arg0_dir[V__2_0] << ", " << "V__2_1: " << isCapture_arg0_dir[V__2_1] << ", " << "V__2_2: " << isCapture_arg0_dir[V__2_2] << ", " << "V__2_3: " << isCapture_arg0_dir[V__2_3] << ", " << "V__2_4: " << isCapture_arg0_dir[V__2_4] << ", " << "V__2_5: " << isCapture_arg0_dir[V__2_5] << ", " << "V__2_6: " << isCapture_arg0_dir[V__2_6] << ", " << "V__2_7: " << isCapture_arg0_dir[V__2_7] << ", " << "V__3_0: " << isCapture_arg0_dir[V__3_0] << ", " << "V__3_1: " << isCapture_arg0_dir[V__3_1] << ", " << "V__3_2: " << isCapture_arg0_dir[V__3_2] << ", " << "V__3_3: " << isCapture_arg0_dir[V__3_3] << ", " << "V__3_4: " << isCapture_arg0_dir[V__3_4] << ", " << "V__3_5: " << isCapture_arg0_dir[V__3_5] << ", " << "V__3_6: " << isCapture_arg0_dir[V__3_6] << ", " << "V__3_7: " << isCapture_arg0_dir[V__3_7] << ", " << "V__4_0: " << isCapture_arg0_dir[V__4_0] << ", " << "V__4_1: " << isCapture_arg0_dir[V__4_1] << ", " << "V__4_2: " << isCapture_arg0_dir[V__4_2] << ", " << "V__4_3: " << isCapture_arg0_dir[V__4_3] << ", " << "V__4_4: " << isCapture_arg0_dir[V__4_4] << ", " << "V__4_5: " << isCapture_arg0_dir[V__4_5] << ", " << "V__4_6: " << isCapture_arg0_dir[V__4_6] << ", " << "V__4_7: " << isCapture_arg0_dir[V__4_7] << ", " << "V__5_0: " << isCapture_arg0_dir[V__5_0] << ", " << "V__5_1: " << isCapture_arg0_dir[V__5_1] << ", " << "V__5_2: " << isCapture_arg0_dir[V__5_2] << ", " << "V__5_3: " << isCapture_arg0_dir[V__5_3] << ", " << "V__5_4: " << isCapture_arg0_dir[V__5_4] << ", " << "V__5_5: " << isCapture_arg0_dir[V__5_5] << ", " << "V__5_6: " << isCapture_arg0_dir[V__5_6] << ", " << "V__5_7: " << isCapture_arg0_dir[V__5_7] << ", " << "V__6_0: " << isCapture_arg0_dir[V__6_0] << ", " << "V__6_1: " << isCapture_arg0_dir[V__6_1] << ", " << "V__6_2: " << isCapture_arg0_dir[V__6_2] << ", " << "V__6_3: " << isCapture_arg0_dir[V__6_3] << ", " << "V__6_4: " << isCapture_arg0_dir[V__6_4] << ", " << "V__6_5: " << isCapture_arg0_dir[V__6_5] << ", " << "V__6_6: " << isCapture_arg0_dir[V__6_6] << ", " << "V__6_7: " << isCapture_arg0_dir[V__6_7] << ", " << "V__7_0: " << isCapture_arg0_dir[V__7_0] << ", " << "V__7_1: " << isCapture_arg0_dir[V__7_1] << ", " << "V__7_2: " << isCapture_arg0_dir[V__7_2] << ", " << "V__7_3: " << isCapture_arg0_dir[V__7_3] << ", " << "V__7_4: " << isCapture_arg0_dir[V__7_4] << ", " << "V__7_5: " << isCapture_arg0_dir[V__7_5] << ", " << "V__7_6: " << isCapture_arg0_dir[V__7_6] << ", " << "V__7_7: " << isCapture_arg0_dir[V__7_7]<< "}" << std::endl;
    ss << "swapInLine_arg0_dir = " << "{" << "null: " << swapInLine_arg0_dir[null] << ", " << "V__0_0: " << swapInLine_arg0_dir[V__0_0] << ", " << "V__0_1: " << swapInLine_arg0_dir[V__0_1] << ", " << "V__0_2: " << swapInLine_arg0_dir[V__0_2] << ", " << "V__0_3: " << swapInLine_arg0_dir[V__0_3] << ", " << "V__0_4: " << swapInLine_arg0_dir[V__0_4] << ", " << "V__0_5: " << swapInLine_arg0_dir[V__0_5] << ", " << "V__0_6: " << swapInLine_arg0_dir[V__0_6] << ", " << "V__0_7: " << swapInLine_arg0_dir[V__0_7] << ", " << "V__1_0: " << swapInLine_arg0_dir[V__1_0] << ", " << "V__1_1: " << swapInLine_arg0_dir[V__1_1] << ", " << "V__1_2: " << swapInLine_arg0_dir[V__1_2] << ", " << "V__1_3: " << swapInLine_arg0_dir[V__1_3] << ", " << "V__1_4: " << swapInLine_arg0_dir[V__1_4] << ", " << "V__1_5: " << swapInLine_arg0_dir[V__1_5] << ", " << "V__1_6: " << swapInLine_arg0_dir[V__1_6] << ", " << "V__1_7: " << swapInLine_arg0_dir[V__1_7] << ", " << "V__2_0: " << swapInLine_arg0_dir[V__2_0] << ", " << "V__2_1: " << swapInLine_arg0_dir[V__2_1] << ", " << "V__2_2: " << swapInLine_arg0_dir[V__2_2] << ", " << "V__2_3: " << swapInLine_arg0_dir[V__2_3] << ", " << "V__2_4: " << swapInLine_arg0_dir[V__2_4] << ", " << "V__2_5: " << swapInLine_arg0_dir[V__2_5] << ", " << "V__2_6: " << swapInLine_arg0_dir[V__2_6] << ", " << "V__2_7: " << swapInLine_arg0_dir[V__2_7] << ", " << "V__3_0: " << swapInLine_arg0_dir[V__3_0] << ", " << "V__3_1: " << swapInLine_arg0_dir[V__3_1] << ", " << "V__3_2: " << swapInLine_arg0_dir[V__3_2] << ", " << "V__3_3: " << swapInLine_arg0_dir[V__3_3] << ", " << "V__3_4: " << swapInLine_arg0_dir[V__3_4] << ", " << "V__3_5: " << swapInLine_arg0_dir[V__3_5] << ", " << "V__3_6: " << swapInLine_arg0_dir[V__3_6] << ", " << "V__3_7: " << swapInLine_arg0_dir[V__3_7] << ", " << "V__4_0: " << swapInLine_arg0_dir[V__4_0] << ", " << "V__4_1: " << swapInLine_arg0_dir[V__4_1] << ", " << "V__4_2: " << swapInLine_arg0_dir[V__4_2] << ", " << "V__4_3: " << swapInLine_arg0_dir[V__4_3] << ", " << "V__4_4: " << swapInLine_arg0_dir[V__4_4] << ", " << "V__4_5: " << swapInLine_arg0_dir[V__4_5] << ", " << "V__4_6: " << swapInLine_arg0_dir[V__4_6] << ", " << "V__4_7: " << swapInLine_arg0_dir[V__4_7] << ", " << "V__5_0: " << swapInLine_arg0_dir[V__5_0] << ", " << "V__5_1: " << swapInLine_arg0_dir[V__5_1] << ", " << "V__5_2: " << swapInLine_arg0_dir[V__5_2] << ", " << "V__5_3: " << swapInLine_arg0_dir[V__5_3] << ", " << "V__5_4: " << swapInLine_arg0_dir[V__5_4] << ", " << "V__5_5: " << swapInLine_arg0_dir[V__5_5] << ", " << "V__5_6: " << swapInLine_arg0_dir[V__5_6] << ", " << "V__5_7: " << swapInLine_arg0_dir[V__5_7] << ", " << "V__6_0: " << swapInLine_arg0_dir[V__6_0] << ", " << "V__6_1: " << swapInLine_arg0_dir[V__6_1] << ", " << "V__6_2: " << swapInLine_arg0_dir[V__6_2] << ", " << "V__6_3: " << swapInLine_arg0_dir[V__6_3] << ", " << "V__6_4: " << swapInLine_arg0_dir[V__6_4] << ", " << "V__6_5: " << swapInLine_arg0_dir[V__6_5] << ", " << "V__6_6: " << swapInLine_arg0_dir[V__6_6] << ", " << "V__6_7: " << swapInLine_arg0_dir[V__6_7] << ", " << "V__7_0: " << swapInLine_arg0_dir[V__7_0] << ", " << "V__7_1: " << swapInLine_arg0_dir[V__7_1] << ", " << "V__7_2: " << swapInLine_arg0_dir[V__7_2] << ", " << "V__7_3: " << swapInLine_arg0_dir[V__7_3] << ", " << "V__7_4: " << swapInLine_arg0_dir[V__7_4] << ", " << "V__7_5: " << swapInLine_arg0_dir[V__7_5] << ", " << "V__7_6: " << swapInLine_arg0_dir[V__7_6] << ", " << "V__7_7: " << swapInLine_arg0_dir[V__7_7]<< "}" << std::endl;
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
        case 1036:
{
            state_turn_43(moves, mr.mr);
            return;
}
        case 1356:
{
            state_turn_5(moves, mr.mr);
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
        case 1036:
{
            apply_state_turn_43(mr.mr,rgCache);
            return;
}
        case 1356:
{
            apply_state_turn_5(mr.mr,rgCache);
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
        case 9:
{
            apply_any_turn_10_turn_10_turn_10();
            break;
}
        case 1037:
{
            apply_any_turn_44_turn_44_turn_44();
            break;
}
        case 1038:
{
            apply_any_turn_45_turn_45_turn_45();
            break;
}
    }
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_2()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_2()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_2()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_2()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_2()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_2()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_2()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_1()
{
    const auto old32_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_2())
    {
        isCapture_arg0_dir = old32_0;
        return true;
    }
    isCapture_arg0_dir = old32_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_2()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_1()
{
    const auto old35_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_4())
    {
        tmp = old35_0;
        return true;
    }
    tmp = old35_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_10()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_11()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_12()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_13()
{
    const auto old53_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_19())
    {
        tmp = old53_0;
        return true;
    }
    tmp = old53_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_15()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_16()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_17()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_18()
{
    const auto old59_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_24())
    {
        tmp = old59_0;
        return true;
    }
    tmp = old59_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_20()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_21()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_22()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_23()
{
    const auto old65_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_29())
    {
        tmp = old65_0;
        return true;
    }
    tmp = old65_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_25()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_26()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_27()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_3()
{
    const auto old41_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_9())
    {
        tmp = old41_0;
        return true;
    }
    tmp = old41_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_32()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_5()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_6()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_7()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_8()
{
    const auto old47_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_14())
    {
        tmp = old47_0;
        return true;
    }
    tmp = old47_0;
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_end()
{
    return true;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_1()
{
    const auto old277_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_3())
    {
        tmp = old277_0;
        return true;
    }
    tmp = old277_0;
    const auto old316_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_6())
    {
        tmp = old316_0;
        return true;
    }
    tmp = old316_0;
    const auto old355_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_9())
    {
        tmp = old355_0;
        return true;
    }
    tmp = old355_0;
    const auto old394_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_12())
    {
        tmp = old394_0;
        return true;
    }
    tmp = old394_0;
    const auto old433_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_15())
    {
        tmp = old433_0;
        return true;
    }
    tmp = old433_0;
    const auto old472_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_18())
    {
        tmp = old472_0;
        return true;
    }
    tmp = old472_0;
    const auto old511_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_21())
    {
        tmp = old511_0;
        return true;
    }
    tmp = old511_0;
    const auto old550_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_24())
    {
        tmp = old550_0;
        return true;
    }
    tmp = old550_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_1()
{
    const auto old359_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_4())
    {
        tmp = old359_0;
        return true;
    }
    tmp = old359_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_13()
{
    const auto old377_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_19())
    {
        tmp = old377_0;
        return true;
    }
    tmp = old377_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_18()
{
    const auto old383_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_24())
    {
        tmp = old383_0;
        return true;
    }
    tmp = old383_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_23()
{
    const auto old389_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_29())
    {
        tmp = old389_0;
        return true;
    }
    tmp = old389_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_3()
{
    const auto old365_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_9())
    {
        tmp = old365_0;
        return true;
    }
    tmp = old365_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_8()
{
    const auto old371_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_14())
    {
        tmp = old371_0;
        return true;
    }
    tmp = old371_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_12()
{
    const auto old395_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old395_0;
        return true;
    }
    isCapture_arg0_dir = old395_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_1()
{
    const auto old398_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_4())
    {
        tmp = old398_0;
        return true;
    }
    tmp = old398_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_13()
{
    const auto old416_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_19())
    {
        tmp = old416_0;
        return true;
    }
    tmp = old416_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_18()
{
    const auto old422_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_24())
    {
        tmp = old422_0;
        return true;
    }
    tmp = old422_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_23()
{
    const auto old428_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_29())
    {
        tmp = old428_0;
        return true;
    }
    tmp = old428_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_3()
{
    const auto old404_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_9())
    {
        tmp = old404_0;
        return true;
    }
    tmp = old404_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_8()
{
    const auto old410_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_14())
    {
        tmp = old410_0;
        return true;
    }
    tmp = old410_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_14()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_15()
{
    const auto old434_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old434_0;
        return true;
    }
    isCapture_arg0_dir = old434_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_1()
{
    const auto old437_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_4())
    {
        tmp = old437_0;
        return true;
    }
    tmp = old437_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_13()
{
    const auto old455_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_19())
    {
        tmp = old455_0;
        return true;
    }
    tmp = old455_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_18()
{
    const auto old461_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_24())
    {
        tmp = old461_0;
        return true;
    }
    tmp = old461_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_23()
{
    const auto old467_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_29())
    {
        tmp = old467_0;
        return true;
    }
    tmp = old467_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_3()
{
    const auto old443_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_9())
    {
        tmp = old443_0;
        return true;
    }
    tmp = old443_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_8()
{
    const auto old449_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_14())
    {
        tmp = old449_0;
        return true;
    }
    tmp = old449_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_18()
{
    const auto old473_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old473_0;
        return true;
    }
    isCapture_arg0_dir = old473_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_1()
{
    const auto old476_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_4())
    {
        tmp = old476_0;
        return true;
    }
    tmp = old476_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_13()
{
    const auto old494_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_19())
    {
        tmp = old494_0;
        return true;
    }
    tmp = old494_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_18()
{
    const auto old500_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_24())
    {
        tmp = old500_0;
        return true;
    }
    tmp = old500_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_23()
{
    const auto old506_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_29())
    {
        tmp = old506_0;
        return true;
    }
    tmp = old506_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_3()
{
    const auto old482_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_9())
    {
        tmp = old482_0;
        return true;
    }
    tmp = old482_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_8()
{
    const auto old488_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_14())
    {
        tmp = old488_0;
        return true;
    }
    tmp = old488_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_21()
{
    const auto old512_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old512_0;
        return true;
    }
    isCapture_arg0_dir = old512_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_1()
{
    const auto old515_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_4())
    {
        tmp = old515_0;
        return true;
    }
    tmp = old515_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_13()
{
    const auto old533_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_19())
    {
        tmp = old533_0;
        return true;
    }
    tmp = old533_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_18()
{
    const auto old539_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_24())
    {
        tmp = old539_0;
        return true;
    }
    tmp = old539_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_23()
{
    const auto old545_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_29())
    {
        tmp = old545_0;
        return true;
    }
    tmp = old545_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_3()
{
    const auto old521_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_9())
    {
        tmp = old521_0;
        return true;
    }
    tmp = old521_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_8()
{
    const auto old527_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_14())
    {
        tmp = old527_0;
        return true;
    }
    tmp = old527_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_23()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_24()
{
    const auto old551_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old551_0;
        return true;
    }
    isCapture_arg0_dir = old551_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_1()
{
    const auto old554_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_4())
    {
        tmp = old554_0;
        return true;
    }
    tmp = old554_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_13()
{
    const auto old572_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_19())
    {
        tmp = old572_0;
        return true;
    }
    tmp = old572_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_18()
{
    const auto old578_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_24())
    {
        tmp = old578_0;
        return true;
    }
    tmp = old578_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_23()
{
    const auto old584_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_29())
    {
        tmp = old584_0;
        return true;
    }
    tmp = old584_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_3()
{
    const auto old560_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_9())
    {
        tmp = old560_0;
        return true;
    }
    tmp = old560_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_8()
{
    const auto old566_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_14())
    {
        tmp = old566_0;
        return true;
    }
    tmp = old566_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_3()
{
    const auto old278_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old278_0;
        return true;
    }
    isCapture_arg0_dir = old278_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_1()
{
    const auto old281_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_4())
    {
        tmp = old281_0;
        return true;
    }
    tmp = old281_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_13()
{
    const auto old299_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_19())
    {
        tmp = old299_0;
        return true;
    }
    tmp = old299_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_18()
{
    const auto old305_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_24())
    {
        tmp = old305_0;
        return true;
    }
    tmp = old305_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_23()
{
    const auto old311_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_29())
    {
        tmp = old311_0;
        return true;
    }
    tmp = old311_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_3()
{
    const auto old287_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_9())
    {
        tmp = old287_0;
        return true;
    }
    tmp = old287_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_8()
{
    const auto old293_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_14())
    {
        tmp = old293_0;
        return true;
    }
    tmp = old293_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_6()
{
    const auto old317_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old317_0;
        return true;
    }
    isCapture_arg0_dir = old317_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7__1()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_1()
{
    const auto old320_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_4())
    {
        tmp = old320_0;
        return true;
    }
    tmp = old320_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_10()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_11()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_12()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_13()
{
    const auto old338_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_19())
    {
        tmp = old338_0;
        return true;
    }
    tmp = old338_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_15()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_16()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_17()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_18()
{
    const auto old344_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_24())
    {
        tmp = old344_0;
        return true;
    }
    tmp = old344_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_20()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_21()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_22()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_23()
{
    const auto old350_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_29())
    {
        tmp = old350_0;
        return true;
    }
    tmp = old350_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_25()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_26()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_27()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_3()
{
    const auto old326_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_9())
    {
        tmp = old326_0;
        return true;
    }
    tmp = old326_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_32()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_5()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_6()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_7()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_8()
{
    const auto old332_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_14())
    {
        tmp = old332_0;
        return true;
    }
    tmp = old332_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_8()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_9()
{
    const auto old356_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old356_0;
        return true;
    }
    isCapture_arg0_dir = old356_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_begin()
{
    if (board[pos]==empty)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_end()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_3()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_begin()
{
    const auto old274_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_1())
    {
        pos = old274_0;
        return true;
    }    }
    pos = old274_0;
    return false;
}

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_end()
{
    return true;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_1()
{
    const auto old277_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_3())
    {
        tmp = old277_0;
        return true;
    }
    tmp = old277_0;
    const auto old316_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_6())
    {
        tmp = old316_0;
        return true;
    }
    tmp = old316_0;
    const auto old355_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_9())
    {
        tmp = old355_0;
        return true;
    }
    tmp = old355_0;
    const auto old394_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_12())
    {
        tmp = old394_0;
        return true;
    }
    tmp = old394_0;
    const auto old433_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_15())
    {
        tmp = old433_0;
        return true;
    }
    tmp = old433_0;
    const auto old472_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_18())
    {
        tmp = old472_0;
        return true;
    }
    tmp = old472_0;
    const auto old511_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_21())
    {
        tmp = old511_0;
        return true;
    }
    tmp = old511_0;
    const auto old550_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_24())
    {
        tmp = old550_0;
        return true;
    }
    tmp = old550_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_1()
{
    const auto old359_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_4())
    {
        tmp = old359_0;
        return true;
    }
    tmp = old359_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_13()
{
    const auto old377_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_19())
    {
        tmp = old377_0;
        return true;
    }
    tmp = old377_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_18()
{
    const auto old383_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_24())
    {
        tmp = old383_0;
        return true;
    }
    tmp = old383_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_23()
{
    const auto old389_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_29())
    {
        tmp = old389_0;
        return true;
    }
    tmp = old389_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_3()
{
    const auto old365_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_9())
    {
        tmp = old365_0;
        return true;
    }
    tmp = old365_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_8()
{
    const auto old371_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_14())
    {
        tmp = old371_0;
        return true;
    }
    tmp = old371_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_12()
{
    const auto old395_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old395_0;
        return true;
    }
    isCapture_arg0_dir = old395_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_1()
{
    const auto old398_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_4())
    {
        tmp = old398_0;
        return true;
    }
    tmp = old398_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_13()
{
    const auto old416_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_19())
    {
        tmp = old416_0;
        return true;
    }
    tmp = old416_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_18()
{
    const auto old422_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_24())
    {
        tmp = old422_0;
        return true;
    }
    tmp = old422_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_23()
{
    const auto old428_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_29())
    {
        tmp = old428_0;
        return true;
    }
    tmp = old428_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_3()
{
    const auto old404_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_9())
    {
        tmp = old404_0;
        return true;
    }
    tmp = old404_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_8()
{
    const auto old410_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_14())
    {
        tmp = old410_0;
        return true;
    }
    tmp = old410_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_14()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_15()
{
    const auto old434_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old434_0;
        return true;
    }
    isCapture_arg0_dir = old434_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_1()
{
    const auto old437_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_4())
    {
        tmp = old437_0;
        return true;
    }
    tmp = old437_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_13()
{
    const auto old455_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_19())
    {
        tmp = old455_0;
        return true;
    }
    tmp = old455_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_18()
{
    const auto old461_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_24())
    {
        tmp = old461_0;
        return true;
    }
    tmp = old461_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_23()
{
    const auto old467_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_29())
    {
        tmp = old467_0;
        return true;
    }
    tmp = old467_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_3()
{
    const auto old443_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_9())
    {
        tmp = old443_0;
        return true;
    }
    tmp = old443_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_8()
{
    const auto old449_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_14())
    {
        tmp = old449_0;
        return true;
    }
    tmp = old449_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_18()
{
    const auto old473_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old473_0;
        return true;
    }
    isCapture_arg0_dir = old473_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_1()
{
    const auto old476_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_4())
    {
        tmp = old476_0;
        return true;
    }
    tmp = old476_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_13()
{
    const auto old494_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_19())
    {
        tmp = old494_0;
        return true;
    }
    tmp = old494_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_18()
{
    const auto old500_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_24())
    {
        tmp = old500_0;
        return true;
    }
    tmp = old500_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_23()
{
    const auto old506_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_29())
    {
        tmp = old506_0;
        return true;
    }
    tmp = old506_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_3()
{
    const auto old482_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_9())
    {
        tmp = old482_0;
        return true;
    }
    tmp = old482_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_8()
{
    const auto old488_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_14())
    {
        tmp = old488_0;
        return true;
    }
    tmp = old488_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_21()
{
    const auto old512_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old512_0;
        return true;
    }
    isCapture_arg0_dir = old512_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_1()
{
    const auto old515_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_4())
    {
        tmp = old515_0;
        return true;
    }
    tmp = old515_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_13()
{
    const auto old533_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_19())
    {
        tmp = old533_0;
        return true;
    }
    tmp = old533_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_18()
{
    const auto old539_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_24())
    {
        tmp = old539_0;
        return true;
    }
    tmp = old539_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_23()
{
    const auto old545_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_29())
    {
        tmp = old545_0;
        return true;
    }
    tmp = old545_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_3()
{
    const auto old521_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_9())
    {
        tmp = old521_0;
        return true;
    }
    tmp = old521_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_8()
{
    const auto old527_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_14())
    {
        tmp = old527_0;
        return true;
    }
    tmp = old527_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_23()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_24()
{
    const auto old551_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old551_0;
        return true;
    }
    isCapture_arg0_dir = old551_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_1()
{
    const auto old554_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_4())
    {
        tmp = old554_0;
        return true;
    }
    tmp = old554_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_13()
{
    const auto old572_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_19())
    {
        tmp = old572_0;
        return true;
    }
    tmp = old572_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_18()
{
    const auto old578_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_24())
    {
        tmp = old578_0;
        return true;
    }
    tmp = old578_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_23()
{
    const auto old584_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_29())
    {
        tmp = old584_0;
        return true;
    }
    tmp = old584_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_3()
{
    const auto old560_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_9())
    {
        tmp = old560_0;
        return true;
    }
    tmp = old560_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_8()
{
    const auto old566_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_14())
    {
        tmp = old566_0;
        return true;
    }
    tmp = old566_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_3()
{
    const auto old278_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old278_0;
        return true;
    }
    isCapture_arg0_dir = old278_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_1()
{
    const auto old281_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_4())
    {
        tmp = old281_0;
        return true;
    }
    tmp = old281_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_13()
{
    const auto old299_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_19())
    {
        tmp = old299_0;
        return true;
    }
    tmp = old299_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_18()
{
    const auto old305_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_24())
    {
        tmp = old305_0;
        return true;
    }
    tmp = old305_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_23()
{
    const auto old311_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_29())
    {
        tmp = old311_0;
        return true;
    }
    tmp = old311_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_3()
{
    const auto old287_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_9())
    {
        tmp = old287_0;
        return true;
    }
    tmp = old287_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_8()
{
    const auto old293_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_14())
    {
        tmp = old293_0;
        return true;
    }
    tmp = old293_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_6()
{
    const auto old317_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old317_0;
        return true;
    }
    isCapture_arg0_dir = old317_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7__1()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_1()
{
    const auto old320_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_4())
    {
        tmp = old320_0;
        return true;
    }
    tmp = old320_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_10()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_11()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_12()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_13()
{
    const auto old338_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_19())
    {
        tmp = old338_0;
        return true;
    }
    tmp = old338_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_15()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_16()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_17()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_18()
{
    const auto old344_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_24())
    {
        tmp = old344_0;
        return true;
    }
    tmp = old344_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_20()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_21()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_22()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_23()
{
    const auto old350_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_29())
    {
        tmp = old350_0;
        return true;
    }
    tmp = old350_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_25()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_26()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_27()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_3()
{
    const auto old326_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_9())
    {
        tmp = old326_0;
        return true;
    }
    tmp = old326_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_32()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_5()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_6()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_7()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_8()
{
    const auto old332_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_14())
    {
        tmp = old332_0;
        return true;
    }
    tmp = old332_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_8()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_9()
{
    const auto old356_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old356_0;
        return true;
    }
    isCapture_arg0_dir = old356_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_begin()
{
    if (board[pos]==empty)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_end()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_3()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_begin()
{
    const auto old274_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_1())
    {
        pos = old274_0;
        return true;
    }    }
    pos = old274_0;
    return false;
}

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_end()
{
    return true;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_1()
{
    const auto old271_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_3())
    {
        tmp = old271_0;
        return true;
    }
    tmp = old271_0;
    const auto old310_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_6())
    {
        tmp = old310_0;
        return true;
    }
    tmp = old310_0;
    const auto old349_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_9())
    {
        tmp = old349_0;
        return true;
    }
    tmp = old349_0;
    const auto old388_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_12())
    {
        tmp = old388_0;
        return true;
    }
    tmp = old388_0;
    const auto old427_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_15())
    {
        tmp = old427_0;
        return true;
    }
    tmp = old427_0;
    const auto old466_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_18())
    {
        tmp = old466_0;
        return true;
    }
    tmp = old466_0;
    const auto old505_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_21())
    {
        tmp = old505_0;
        return true;
    }
    tmp = old505_0;
    const auto old544_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_24())
    {
        tmp = old544_0;
        return true;
    }
    tmp = old544_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_1()
{
    const auto old353_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_4())
    {
        tmp = old353_0;
        return true;
    }
    tmp = old353_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_13()
{
    const auto old371_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_19())
    {
        tmp = old371_0;
        return true;
    }
    tmp = old371_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_18()
{
    const auto old377_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_24())
    {
        tmp = old377_0;
        return true;
    }
    tmp = old377_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_23()
{
    const auto old383_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_29())
    {
        tmp = old383_0;
        return true;
    }
    tmp = old383_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_3()
{
    const auto old359_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_9())
    {
        tmp = old359_0;
        return true;
    }
    tmp = old359_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_8()
{
    const auto old365_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_14())
    {
        tmp = old365_0;
        return true;
    }
    tmp = old365_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_12()
{
    const auto old389_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old389_0;
        return true;
    }
    isCapture_arg0_dir = old389_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_1()
{
    const auto old392_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_4())
    {
        tmp = old392_0;
        return true;
    }
    tmp = old392_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_13()
{
    const auto old410_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_19())
    {
        tmp = old410_0;
        return true;
    }
    tmp = old410_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_18()
{
    const auto old416_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_24())
    {
        tmp = old416_0;
        return true;
    }
    tmp = old416_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_23()
{
    const auto old422_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_29())
    {
        tmp = old422_0;
        return true;
    }
    tmp = old422_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_3()
{
    const auto old398_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_9())
    {
        tmp = old398_0;
        return true;
    }
    tmp = old398_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_8()
{
    const auto old404_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_14())
    {
        tmp = old404_0;
        return true;
    }
    tmp = old404_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_14()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_15()
{
    const auto old428_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old428_0;
        return true;
    }
    isCapture_arg0_dir = old428_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_1()
{
    const auto old431_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_4())
    {
        tmp = old431_0;
        return true;
    }
    tmp = old431_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_13()
{
    const auto old449_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_19())
    {
        tmp = old449_0;
        return true;
    }
    tmp = old449_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_18()
{
    const auto old455_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_24())
    {
        tmp = old455_0;
        return true;
    }
    tmp = old455_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_23()
{
    const auto old461_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_29())
    {
        tmp = old461_0;
        return true;
    }
    tmp = old461_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_3()
{
    const auto old437_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_9())
    {
        tmp = old437_0;
        return true;
    }
    tmp = old437_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_8()
{
    const auto old443_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_14())
    {
        tmp = old443_0;
        return true;
    }
    tmp = old443_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_18()
{
    const auto old467_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old467_0;
        return true;
    }
    isCapture_arg0_dir = old467_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_1()
{
    const auto old470_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_4())
    {
        tmp = old470_0;
        return true;
    }
    tmp = old470_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_13()
{
    const auto old488_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_19())
    {
        tmp = old488_0;
        return true;
    }
    tmp = old488_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_18()
{
    const auto old494_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_24())
    {
        tmp = old494_0;
        return true;
    }
    tmp = old494_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_23()
{
    const auto old500_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_29())
    {
        tmp = old500_0;
        return true;
    }
    tmp = old500_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_3()
{
    const auto old476_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_9())
    {
        tmp = old476_0;
        return true;
    }
    tmp = old476_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_8()
{
    const auto old482_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_14())
    {
        tmp = old482_0;
        return true;
    }
    tmp = old482_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_21()
{
    const auto old506_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old506_0;
        return true;
    }
    isCapture_arg0_dir = old506_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_1()
{
    const auto old509_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_4())
    {
        tmp = old509_0;
        return true;
    }
    tmp = old509_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_13()
{
    const auto old527_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_19())
    {
        tmp = old527_0;
        return true;
    }
    tmp = old527_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_18()
{
    const auto old533_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_24())
    {
        tmp = old533_0;
        return true;
    }
    tmp = old533_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_23()
{
    const auto old539_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_29())
    {
        tmp = old539_0;
        return true;
    }
    tmp = old539_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_3()
{
    const auto old515_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_9())
    {
        tmp = old515_0;
        return true;
    }
    tmp = old515_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_8()
{
    const auto old521_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_14())
    {
        tmp = old521_0;
        return true;
    }
    tmp = old521_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_23()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_24()
{
    const auto old545_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old545_0;
        return true;
    }
    isCapture_arg0_dir = old545_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_1()
{
    const auto old548_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_4())
    {
        tmp = old548_0;
        return true;
    }
    tmp = old548_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_13()
{
    const auto old566_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_19())
    {
        tmp = old566_0;
        return true;
    }
    tmp = old566_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_18()
{
    const auto old572_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_24())
    {
        tmp = old572_0;
        return true;
    }
    tmp = old572_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_23()
{
    const auto old578_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_29())
    {
        tmp = old578_0;
        return true;
    }
    tmp = old578_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_3()
{
    const auto old554_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_9())
    {
        tmp = old554_0;
        return true;
    }
    tmp = old554_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_8()
{
    const auto old560_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_14())
    {
        tmp = old560_0;
        return true;
    }
    tmp = old560_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_3()
{
    const auto old272_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old272_0;
        return true;
    }
    isCapture_arg0_dir = old272_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_1()
{
    const auto old275_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_4())
    {
        tmp = old275_0;
        return true;
    }
    tmp = old275_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_13()
{
    const auto old293_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_19())
    {
        tmp = old293_0;
        return true;
    }
    tmp = old293_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_18()
{
    const auto old299_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_24())
    {
        tmp = old299_0;
        return true;
    }
    tmp = old299_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_23()
{
    const auto old305_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_29())
    {
        tmp = old305_0;
        return true;
    }
    tmp = old305_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_3()
{
    const auto old281_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_9())
    {
        tmp = old281_0;
        return true;
    }
    tmp = old281_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_8()
{
    const auto old287_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_14())
    {
        tmp = old287_0;
        return true;
    }
    tmp = old287_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_6()
{
    const auto old311_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old311_0;
        return true;
    }
    isCapture_arg0_dir = old311_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7__1()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_1()
{
    const auto old314_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_4())
    {
        tmp = old314_0;
        return true;
    }
    tmp = old314_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_10()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_11()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_12()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_13()
{
    const auto old332_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_19())
    {
        tmp = old332_0;
        return true;
    }
    tmp = old332_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_14()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_16())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_15()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_16()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_17()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_18()
{
    const auto old338_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_24())
    {
        tmp = old338_0;
        return true;
    }
    tmp = old338_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_21())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_20()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_21()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_22()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_23()
{
    const auto old344_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_29())
    {
        tmp = old344_0;
        return true;
    }
    tmp = old344_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_24()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_26())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_25()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_26()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_27()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_29()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_3()
{
    const auto old320_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_9())
    {
        tmp = old320_0;
        return true;
    }
    tmp = old320_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_32()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_4()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_6())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_7())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_5()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_6()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_7()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_8()
{
    const auto old326_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_14())
    {
        tmp = old326_0;
        return true;
    }
    tmp = old326_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_9()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_11())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_12())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_begin()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_end()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_8()
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_9()
{
    const auto old350_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old350_0;
        return true;
    }
    isCapture_arg0_dir = old350_0;
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_begin()
{
    if (board[pos]==empty)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_1())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_end()
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
    state_turn_begin(moves, mr);
}

void GameState::state_rules_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_1(moves, mr);
}

void GameState::state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_1(moves, mr);
}

void GameState::state_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2413_0 = board[pos];
    board[pos] = me;
    state_turn_11(moves, mr);
    board[pos] = old2413_0;
}

void GameState::state_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2414_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    state_turn_14__1(moves, mr);
    swapInLine_arg0_dir = old2414_0;
}

void GameState::state_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3207_0 = me;
    me = opponent[me - 2];
    state_turn_37(moves, mr);
    me = old3207_0;
}

void GameState::state_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2513_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    state_turn_17__1(moves, mr);
    swapInLine_arg0_dir = old2513_0;
}

void GameState::state_turn_14__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_begin(moves, mr);
}

void GameState::state_turn_14_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_1())
    {
        state_turn_14_swapInLine_2(moves, mr);
        return;
    }
    state_turn_14_swapInLine_3(moves, mr);
}

void GameState::state_turn_14_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_7(moves, mr);
}

void GameState::state_turn_14_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_6(moves, mr);
}

void GameState::state_turn_14_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2469_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_16(moves, mr);
    board[tmp] = old2469_0;
}

void GameState::state_turn_14_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2470_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_17(moves, mr);
    tmp = old2470_0;
}

void GameState::state_turn_14_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_14(moves, mr);
}

void GameState::state_turn_14_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_13(moves, mr);
}

void GameState::state_turn_14_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2477_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_23(moves, mr);
    board[tmp] = old2477_0;
}

void GameState::state_turn_14_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2478_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_24(moves, mr);
    tmp = old2478_0;
}

void GameState::state_turn_14_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_21(moves, mr);
}

void GameState::state_turn_14_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_20(moves, mr);
}

void GameState::state_turn_14_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2485_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_30(moves, mr);
    board[tmp] = old2485_0;
}

void GameState::state_turn_14_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2486_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_31(moves, mr);
    tmp = old2486_0;
}

void GameState::state_turn_14_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_28(moves, mr);
}

void GameState::state_turn_14_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_27(moves, mr);
}

void GameState::state_turn_14_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2493_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_37(moves, mr);
    board[tmp] = old2493_0;
}

void GameState::state_turn_14_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2494_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_38(moves, mr);
    tmp = old2494_0;
}

void GameState::state_turn_14_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_35(moves, mr);
}

void GameState::state_turn_14_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_34(moves, mr);
}

void GameState::state_turn_14_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_5(moves, mr);
}

void GameState::state_turn_14_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2501_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_44(moves, mr);
    board[tmp] = old2501_0;
}

void GameState::state_turn_14_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2502_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_45(moves, mr);
    tmp = old2502_0;
}

void GameState::state_turn_14_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_42(moves, mr);
}

void GameState::state_turn_14_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_41(moves, mr);
}

void GameState::state_turn_14_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_3(moves, mr);
}

void GameState::state_turn_14_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_14_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_14_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_14_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_14_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2461_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_9(moves, mr);
    board[tmp] = old2461_0;
}

void GameState::state_turn_14_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2462_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_10(moves, mr);
    tmp = old2462_0;
}

void GameState::state_turn_14_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2416_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_14_swapInLine_1(moves, mr);
    tmp = old2416_0;
}

void GameState::state_turn_14_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_15(moves, mr);
}

void GameState::state_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_13(moves, mr);
}

void GameState::state_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2612_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    state_turn_20__1(moves, mr);
    swapInLine_arg0_dir = old2612_0;
}

void GameState::state_turn_17__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_begin(moves, mr);
}

void GameState::state_turn_17_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_1())
    {
        state_turn_17_swapInLine_2(moves, mr);
        return;
    }
    state_turn_17_swapInLine_3(moves, mr);
}

void GameState::state_turn_17_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_7(moves, mr);
}

void GameState::state_turn_17_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_6(moves, mr);
}

void GameState::state_turn_17_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2568_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_16(moves, mr);
    board[tmp] = old2568_0;
}

void GameState::state_turn_17_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2569_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_17(moves, mr);
    tmp = old2569_0;
}

void GameState::state_turn_17_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_14(moves, mr);
}

void GameState::state_turn_17_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_13(moves, mr);
}

void GameState::state_turn_17_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2576_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_23(moves, mr);
    board[tmp] = old2576_0;
}

void GameState::state_turn_17_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2577_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_24(moves, mr);
    tmp = old2577_0;
}

void GameState::state_turn_17_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_21(moves, mr);
}

void GameState::state_turn_17_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_20(moves, mr);
}

void GameState::state_turn_17_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2584_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_30(moves, mr);
    board[tmp] = old2584_0;
}

void GameState::state_turn_17_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2585_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_31(moves, mr);
    tmp = old2585_0;
}

void GameState::state_turn_17_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_28(moves, mr);
}

void GameState::state_turn_17_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_27(moves, mr);
}

void GameState::state_turn_17_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2592_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_37(moves, mr);
    board[tmp] = old2592_0;
}

void GameState::state_turn_17_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2593_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_38(moves, mr);
    tmp = old2593_0;
}

void GameState::state_turn_17_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_35(moves, mr);
}

void GameState::state_turn_17_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_34(moves, mr);
}

void GameState::state_turn_17_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_5(moves, mr);
}

void GameState::state_turn_17_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2600_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_44(moves, mr);
    board[tmp] = old2600_0;
}

void GameState::state_turn_17_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2601_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_45(moves, mr);
    tmp = old2601_0;
}

void GameState::state_turn_17_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_42(moves, mr);
}

void GameState::state_turn_17_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_41(moves, mr);
}

void GameState::state_turn_17_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_3(moves, mr);
}

void GameState::state_turn_17_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_17_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_17_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_17_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_17_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2560_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_9(moves, mr);
    board[tmp] = old2560_0;
}

void GameState::state_turn_17_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2561_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_10(moves, mr);
    tmp = old2561_0;
}

void GameState::state_turn_17_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2515_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_17_swapInLine_1(moves, mr);
    tmp = old2515_0;
}

void GameState::state_turn_17_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_18(moves, mr);
}

void GameState::state_turn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_16(moves, mr);
}

void GameState::state_turn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2711_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    state_turn_23__1(moves, mr);
    swapInLine_arg0_dir = old2711_0;
}

void GameState::state_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3209_0 = me;
    me = opponent[me - 2];
    state_turn_38(moves, mr);
    me = old3209_0;
}

void GameState::state_turn_20__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_begin(moves, mr);
}

void GameState::state_turn_20_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_1())
    {
        state_turn_20_swapInLine_2(moves, mr);
        return;
    }
    state_turn_20_swapInLine_3(moves, mr);
}

void GameState::state_turn_20_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_7(moves, mr);
}

void GameState::state_turn_20_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_6(moves, mr);
}

void GameState::state_turn_20_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2667_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_16(moves, mr);
    board[tmp] = old2667_0;
}

void GameState::state_turn_20_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2668_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_17(moves, mr);
    tmp = old2668_0;
}

void GameState::state_turn_20_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_14(moves, mr);
}

void GameState::state_turn_20_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_13(moves, mr);
}

void GameState::state_turn_20_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2675_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_23(moves, mr);
    board[tmp] = old2675_0;
}

void GameState::state_turn_20_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2676_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_24(moves, mr);
    tmp = old2676_0;
}

void GameState::state_turn_20_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_21(moves, mr);
}

void GameState::state_turn_20_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_20(moves, mr);
}

void GameState::state_turn_20_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2683_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_30(moves, mr);
    board[tmp] = old2683_0;
}

void GameState::state_turn_20_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2684_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_31(moves, mr);
    tmp = old2684_0;
}

void GameState::state_turn_20_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_28(moves, mr);
}

void GameState::state_turn_20_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_27(moves, mr);
}

void GameState::state_turn_20_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2691_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_37(moves, mr);
    board[tmp] = old2691_0;
}

void GameState::state_turn_20_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2692_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_38(moves, mr);
    tmp = old2692_0;
}

void GameState::state_turn_20_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_35(moves, mr);
}

void GameState::state_turn_20_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_34(moves, mr);
}

void GameState::state_turn_20_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_5(moves, mr);
}

void GameState::state_turn_20_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2699_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_44(moves, mr);
    board[tmp] = old2699_0;
}

void GameState::state_turn_20_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2700_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_45(moves, mr);
    tmp = old2700_0;
}

void GameState::state_turn_20_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_42(moves, mr);
}

void GameState::state_turn_20_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_41(moves, mr);
}

void GameState::state_turn_20_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_3(moves, mr);
}

void GameState::state_turn_20_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_20_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_20_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_20_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_20_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2659_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_9(moves, mr);
    board[tmp] = old2659_0;
}

void GameState::state_turn_20_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2660_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_10(moves, mr);
    tmp = old2660_0;
}

void GameState::state_turn_20_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2614_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_20_swapInLine_1(moves, mr);
    tmp = old2614_0;
}

void GameState::state_turn_20_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_21(moves, mr);
}

void GameState::state_turn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_19(moves, mr);
}

void GameState::state_turn_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2810_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    state_turn_26__1(moves, mr);
    swapInLine_arg0_dir = old2810_0;
}

void GameState::state_turn_23__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_begin(moves, mr);
}

void GameState::state_turn_23_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_1())
    {
        state_turn_23_swapInLine_2(moves, mr);
        return;
    }
    state_turn_23_swapInLine_3(moves, mr);
}

void GameState::state_turn_23_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_7(moves, mr);
}

void GameState::state_turn_23_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_6(moves, mr);
}

void GameState::state_turn_23_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2766_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_16(moves, mr);
    board[tmp] = old2766_0;
}

void GameState::state_turn_23_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2767_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_17(moves, mr);
    tmp = old2767_0;
}

void GameState::state_turn_23_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_14(moves, mr);
}

void GameState::state_turn_23_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_13(moves, mr);
}

void GameState::state_turn_23_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2774_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_23(moves, mr);
    board[tmp] = old2774_0;
}

void GameState::state_turn_23_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2775_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_24(moves, mr);
    tmp = old2775_0;
}

void GameState::state_turn_23_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_21(moves, mr);
}

void GameState::state_turn_23_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_20(moves, mr);
}

void GameState::state_turn_23_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2782_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_30(moves, mr);
    board[tmp] = old2782_0;
}

void GameState::state_turn_23_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2783_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_31(moves, mr);
    tmp = old2783_0;
}

void GameState::state_turn_23_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_28(moves, mr);
}

void GameState::state_turn_23_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_27(moves, mr);
}

void GameState::state_turn_23_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2790_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_37(moves, mr);
    board[tmp] = old2790_0;
}

void GameState::state_turn_23_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2791_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_38(moves, mr);
    tmp = old2791_0;
}

void GameState::state_turn_23_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_35(moves, mr);
}

void GameState::state_turn_23_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_34(moves, mr);
}

void GameState::state_turn_23_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_5(moves, mr);
}

void GameState::state_turn_23_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2798_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_44(moves, mr);
    board[tmp] = old2798_0;
}

void GameState::state_turn_23_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2799_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_45(moves, mr);
    tmp = old2799_0;
}

void GameState::state_turn_23_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_42(moves, mr);
}

void GameState::state_turn_23_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_41(moves, mr);
}

void GameState::state_turn_23_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_3(moves, mr);
}

void GameState::state_turn_23_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_23_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_23_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_23_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_23_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2758_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_9(moves, mr);
    board[tmp] = old2758_0;
}

void GameState::state_turn_23_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2759_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_10(moves, mr);
    tmp = old2759_0;
}

void GameState::state_turn_23_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2713_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_23_swapInLine_1(moves, mr);
    tmp = old2713_0;
}

void GameState::state_turn_23_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_24(moves, mr);
}

void GameState::state_turn_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_22(moves, mr);
}

void GameState::state_turn_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2909_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    state_turn_29__1(moves, mr);
    swapInLine_arg0_dir = old2909_0;
}

void GameState::state_turn_26__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_begin(moves, mr);
}

void GameState::state_turn_26_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_1())
    {
        state_turn_26_swapInLine_2(moves, mr);
        return;
    }
    state_turn_26_swapInLine_3(moves, mr);
}

void GameState::state_turn_26_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_7(moves, mr);
}

void GameState::state_turn_26_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_6(moves, mr);
}

void GameState::state_turn_26_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2865_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_16(moves, mr);
    board[tmp] = old2865_0;
}

void GameState::state_turn_26_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2866_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_17(moves, mr);
    tmp = old2866_0;
}

void GameState::state_turn_26_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_14(moves, mr);
}

void GameState::state_turn_26_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_13(moves, mr);
}

void GameState::state_turn_26_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2873_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_23(moves, mr);
    board[tmp] = old2873_0;
}

void GameState::state_turn_26_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2874_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_24(moves, mr);
    tmp = old2874_0;
}

void GameState::state_turn_26_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_21(moves, mr);
}

void GameState::state_turn_26_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_20(moves, mr);
}

void GameState::state_turn_26_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2881_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_30(moves, mr);
    board[tmp] = old2881_0;
}

void GameState::state_turn_26_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2882_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_31(moves, mr);
    tmp = old2882_0;
}

void GameState::state_turn_26_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_28(moves, mr);
}

void GameState::state_turn_26_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_27(moves, mr);
}

void GameState::state_turn_26_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2889_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_37(moves, mr);
    board[tmp] = old2889_0;
}

void GameState::state_turn_26_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2890_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_38(moves, mr);
    tmp = old2890_0;
}

void GameState::state_turn_26_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_35(moves, mr);
}

void GameState::state_turn_26_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_34(moves, mr);
}

void GameState::state_turn_26_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_5(moves, mr);
}

void GameState::state_turn_26_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2897_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_44(moves, mr);
    board[tmp] = old2897_0;
}

void GameState::state_turn_26_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2898_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_45(moves, mr);
    tmp = old2898_0;
}

void GameState::state_turn_26_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_42(moves, mr);
}

void GameState::state_turn_26_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_41(moves, mr);
}

void GameState::state_turn_26_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_3(moves, mr);
}

void GameState::state_turn_26_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_26_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_26_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_26_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_26_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2857_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_9(moves, mr);
    board[tmp] = old2857_0;
}

void GameState::state_turn_26_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2858_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_10(moves, mr);
    tmp = old2858_0;
}

void GameState::state_turn_26_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2812_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_26_swapInLine_1(moves, mr);
    tmp = old2812_0;
}

void GameState::state_turn_26_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_27(moves, mr);
}

void GameState::state_turn_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_25(moves, mr);
}

void GameState::state_turn_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3008_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    state_turn_32__1(moves, mr);
    swapInLine_arg0_dir = old3008_0;
}

void GameState::state_turn_29__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_begin(moves, mr);
}

void GameState::state_turn_29_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_1())
    {
        state_turn_29_swapInLine_2(moves, mr);
        return;
    }
    state_turn_29_swapInLine_3(moves, mr);
}

void GameState::state_turn_29_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_7(moves, mr);
}

void GameState::state_turn_29_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_6(moves, mr);
}

void GameState::state_turn_29_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2964_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_16(moves, mr);
    board[tmp] = old2964_0;
}

void GameState::state_turn_29_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2965_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_17(moves, mr);
    tmp = old2965_0;
}

void GameState::state_turn_29_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_14(moves, mr);
}

void GameState::state_turn_29_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_13(moves, mr);
}

void GameState::state_turn_29_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2972_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_23(moves, mr);
    board[tmp] = old2972_0;
}

void GameState::state_turn_29_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2973_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_24(moves, mr);
    tmp = old2973_0;
}

void GameState::state_turn_29_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_21(moves, mr);
}

void GameState::state_turn_29_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_20(moves, mr);
}

void GameState::state_turn_29_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2980_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_30(moves, mr);
    board[tmp] = old2980_0;
}

void GameState::state_turn_29_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2981_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_31(moves, mr);
    tmp = old2981_0;
}

void GameState::state_turn_29_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_28(moves, mr);
}

void GameState::state_turn_29_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_27(moves, mr);
}

void GameState::state_turn_29_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2988_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_37(moves, mr);
    board[tmp] = old2988_0;
}

void GameState::state_turn_29_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2989_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_38(moves, mr);
    tmp = old2989_0;
}

void GameState::state_turn_29_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_35(moves, mr);
}

void GameState::state_turn_29_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_34(moves, mr);
}

void GameState::state_turn_29_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_5(moves, mr);
}

void GameState::state_turn_29_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2996_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_44(moves, mr);
    board[tmp] = old2996_0;
}

void GameState::state_turn_29_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2997_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_45(moves, mr);
    tmp = old2997_0;
}

void GameState::state_turn_29_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_42(moves, mr);
}

void GameState::state_turn_29_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_41(moves, mr);
}

void GameState::state_turn_29_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_3(moves, mr);
}

void GameState::state_turn_29_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_29_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_29_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_29_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_29_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2956_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_9(moves, mr);
    board[tmp] = old2956_0;
}

void GameState::state_turn_29_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2957_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_10(moves, mr);
    tmp = old2957_0;
}

void GameState::state_turn_29_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2911_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_29_swapInLine_1(moves, mr);
    tmp = old2911_0;
}

void GameState::state_turn_29_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_30(moves, mr);
}

void GameState::state_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_end(moves, mr);
}

void GameState::state_turn_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_28(moves, mr);
}

void GameState::state_turn_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3107_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    state_turn_35__1(moves, mr);
    swapInLine_arg0_dir = old3107_0;
}

void GameState::state_turn_32__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_begin(moves, mr);
}

void GameState::state_turn_32_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_1())
    {
        state_turn_32_swapInLine_2(moves, mr);
        return;
    }
    state_turn_32_swapInLine_3(moves, mr);
}

void GameState::state_turn_32_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_7(moves, mr);
}

void GameState::state_turn_32_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_6(moves, mr);
}

void GameState::state_turn_32_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3063_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_16(moves, mr);
    board[tmp] = old3063_0;
}

void GameState::state_turn_32_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3064_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_17(moves, mr);
    tmp = old3064_0;
}

void GameState::state_turn_32_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_14(moves, mr);
}

void GameState::state_turn_32_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_13(moves, mr);
}

void GameState::state_turn_32_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3071_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_23(moves, mr);
    board[tmp] = old3071_0;
}

void GameState::state_turn_32_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3072_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_24(moves, mr);
    tmp = old3072_0;
}

void GameState::state_turn_32_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_21(moves, mr);
}

void GameState::state_turn_32_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_20(moves, mr);
}

void GameState::state_turn_32_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3079_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_30(moves, mr);
    board[tmp] = old3079_0;
}

void GameState::state_turn_32_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3080_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_31(moves, mr);
    tmp = old3080_0;
}

void GameState::state_turn_32_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_28(moves, mr);
}

void GameState::state_turn_32_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_27(moves, mr);
}

void GameState::state_turn_32_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3087_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_37(moves, mr);
    board[tmp] = old3087_0;
}

void GameState::state_turn_32_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3088_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_38(moves, mr);
    tmp = old3088_0;
}

void GameState::state_turn_32_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_35(moves, mr);
}

void GameState::state_turn_32_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_34(moves, mr);
}

void GameState::state_turn_32_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_5(moves, mr);
}

void GameState::state_turn_32_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3095_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_44(moves, mr);
    board[tmp] = old3095_0;
}

void GameState::state_turn_32_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3096_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_45(moves, mr);
    tmp = old3096_0;
}

void GameState::state_turn_32_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_42(moves, mr);
}

void GameState::state_turn_32_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_41(moves, mr);
}

void GameState::state_turn_32_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_3(moves, mr);
}

void GameState::state_turn_32_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_32_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_32_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_32_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_32_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3055_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_9(moves, mr);
    board[tmp] = old3055_0;
}

void GameState::state_turn_32_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3056_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_10(moves, mr);
    tmp = old3056_0;
}

void GameState::state_turn_32_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3010_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_32_swapInLine_1(moves, mr);
    tmp = old3010_0;
}

void GameState::state_turn_32_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_33(moves, mr);
}

void GameState::state_turn_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_31(moves, mr);
}

void GameState::state_turn_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_12(moves, mr);
}

void GameState::state_turn_35__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_begin(moves, mr);
}

void GameState::state_turn_35_swapInLine_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_1())
    {
        state_turn_35_swapInLine_2(moves, mr);
        return;
    }
    state_turn_35_swapInLine_3(moves, mr);
}

void GameState::state_turn_35_swapInLine_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_7(moves, mr);
}

void GameState::state_turn_35_swapInLine_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_6(moves, mr);
}

void GameState::state_turn_35_swapInLine_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_22(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_25(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3162_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_16(moves, mr);
    board[tmp] = old3162_0;
}

void GameState::state_turn_35_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3163_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_17(moves, mr);
    tmp = old3163_0;
}

void GameState::state_turn_35_swapInLine_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_14(moves, mr);
}

void GameState::state_turn_35_swapInLine_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_13(moves, mr);
}

void GameState::state_turn_35_swapInLine_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_8(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_11(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_29(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_32(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3170_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_23(moves, mr);
    board[tmp] = old3170_0;
}

void GameState::state_turn_35_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3171_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_24(moves, mr);
    tmp = old3171_0;
}

void GameState::state_turn_35_swapInLine_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_21(moves, mr);
}

void GameState::state_turn_35_swapInLine_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_20(moves, mr);
}

void GameState::state_turn_35_swapInLine_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_36(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_39(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3178_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_30(moves, mr);
    board[tmp] = old3178_0;
}

void GameState::state_turn_35_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3179_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_31(moves, mr);
    tmp = old3179_0;
}

void GameState::state_turn_35_swapInLine_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_28(moves, mr);
}

void GameState::state_turn_35_swapInLine_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_27(moves, mr);
}

void GameState::state_turn_35_swapInLine_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_43(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_46(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_40(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3186_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_37(moves, mr);
    board[tmp] = old3186_0;
}

void GameState::state_turn_35_swapInLine_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3187_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_38(moves, mr);
    tmp = old3187_0;
}

void GameState::state_turn_35_swapInLine_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_35(moves, mr);
}

void GameState::state_turn_35_swapInLine_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_34(moves, mr);
}

void GameState::state_turn_35_swapInLine_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_5(moves, mr);
}

void GameState::state_turn_35_swapInLine_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_47(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3194_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_44(moves, mr);
    board[tmp] = old3194_0;
}

void GameState::state_turn_35_swapInLine_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3195_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_45(moves, mr);
    tmp = old3195_0;
}

void GameState::state_turn_35_swapInLine_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_42(moves, mr);
}

void GameState::state_turn_35_swapInLine_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_41(moves, mr);
}

void GameState::state_turn_35_swapInLine_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_3(moves, mr);
}

void GameState::state_turn_35_swapInLine_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==opponent[me - 2])
    {
        state_turn_35_swapInLine_15(moves, mr);
    }
    if (board[tmp]==me)
    {
        state_turn_35_swapInLine_18(moves, mr);
    }
}

void GameState::state_turn_35_swapInLine_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_turn_35_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3154_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_9(moves, mr);
    board[tmp] = old3154_0;
}

void GameState::state_turn_35_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3155_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_10(moves, mr);
    tmp = old3155_0;
}

void GameState::state_turn_35_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3109_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_35_swapInLine_1(moves, mr);
    tmp = old3109_0;
}

void GameState::state_turn_35_swapInLine_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_36(moves, mr);
}

void GameState::state_turn_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_34(moves, mr);
}

void GameState::state_turn_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_3(moves, mr);
}

void GameState::state_turn_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1())
    {
        state_turn_39(moves, mr);
        return;
    }
    state_turn_40(moves, mr);
}

void GameState::state_turn_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_3(moves, mr);
}

void GameState::state_turn_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_41(moves, mr);
}

void GameState::state_turn_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3575_0 = tmp;
    tmp = V__0_0;
    state_turn_46(moves, mr);
    tmp = old3575_0;
}

void GameState::state_turn_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_47(moves, mr);
}

void GameState::state_turn_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==white)
    {
        state_turn_49(moves, mr);
        return;
    }
    state_turn_50(moves, mr);
}

void GameState::state_turn_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if ((count[black - 2]<count[white - 2])==1)
    {
        state_turn_60(moves, mr);
        return;
    }
    state_turn_61(moves, mr);
}

void GameState::state_turn_49([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3579_0 = count[white - 2];
    count[white - 2] = count[white - 2]+1;
    state_turn_52(moves, mr);
    count[white - 2] = old3579_0;
}

void GameState::state_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2054_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    state_turn_6(moves, mr);    }
    pos = old2054_0;
}

void GameState::state_turn_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[tmp]==black)
    {
        state_turn_53(moves, mr);
        return;
    }
    state_turn_54(moves, mr);
}

void GameState::state_turn_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3586_0 = tmp;
    tmp = nextPos[tmp];
    state_turn_56(moves, mr);
    tmp = old3586_0;
}

void GameState::state_turn_52([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_51(moves, mr);
}

void GameState::state_turn_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3583_0 = count[black - 2];
    count[black - 2] = count[black - 2]+1;
    state_turn_55(moves, mr);
    count[black - 2] = old3583_0;
}

void GameState::state_turn_54([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_51(moves, mr);
}

void GameState::state_turn_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_54(moves, mr);
}

void GameState::state_turn_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (tmp==null)
    {
        state_turn_57(moves, mr);
        return;
    }
    state_turn_58(moves, mr);
}

void GameState::state_turn_57([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_48(moves, mr);
}

void GameState::state_turn_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(66);
    state_turn_59(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_47(moves, mr);
}

void GameState::state_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_1())
    {
        state_turn_7(moves, mr);
    }
}

void GameState::state_turn_60([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3594_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_turn_63(moves, mr);
    goals[white - 2] = old3594_0;
}

void GameState::state_turn_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if ((count[white - 2]<count[black - 2])==1)
    {
        state_turn_65(moves, mr);
        return;
    }
    state_turn_66(moves, mr);
}

void GameState::state_turn_62([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3595_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_turn_64(moves, mr);
    goals[black - 2] = old3595_0;
}

void GameState::state_turn_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_62(moves, mr);
}

void GameState::state_turn_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3599_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_turn_67(moves, mr);
    goals[white - 2] = old3599_0;
}

void GameState::state_turn_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_62(moves, mr);
}

void GameState::state_turn_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old3600_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_turn_68(moves, mr);
    goals[black - 2] = old3600_0;
}

void GameState::state_turn_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_66(moves, mr);
}

void GameState::state_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(0 + pos);
    state_turn_9(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1())
    {
        state_turn_1(moves, mr);
        return;
    }
    state_turn_2(moves, mr);
}

void GameState::state_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3(moves, mr);
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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

bool GameState::apply_state_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2053_0 = player;
    player = me;
    currentState = 1356;
    return true;
    player = old2053_0;
    return false;
}

bool GameState::apply_state_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2413_0 = board[pos];
    board[pos] = me;
    if (apply_state_turn_11(mr,rgCache))
    {
        return true;
    }
    board[pos] = old2413_0;
    return false;
}

bool GameState::apply_state_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2414_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    if (apply_state_turn_14__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2414_0;
    return false;
}

bool GameState::apply_state_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3207_0 = me;
    me = opponent[me - 2];
    if (apply_state_turn_37(mr,rgCache))
    {
        return true;
    }
    me = old3207_0;
    return false;
}

bool GameState::apply_state_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2513_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    if (apply_state_turn_17__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2513_0;
    return false;
}

bool GameState::apply_state_turn_14__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_1())
    {
        if (apply_state_turn_14_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_14_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2469_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2469_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2470_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2470_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2477_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2477_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2478_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2478_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2485_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2485_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2486_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2486_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2493_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2493_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2494_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2494_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2501_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2501_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2502_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2502_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_14_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_14_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_14_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_14_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2461_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2461_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2462_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2462_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2416_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_14_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2416_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_15(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2612_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    if (apply_state_turn_20__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2612_0;
    return false;
}

bool GameState::apply_state_turn_17__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_1())
    {
        if (apply_state_turn_17_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_17_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2568_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2568_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2569_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2569_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2576_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2576_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2577_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2577_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2584_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2584_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2585_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2585_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2592_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2592_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2593_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2593_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2600_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2600_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2601_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2601_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_17_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_17_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_17_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_17_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2560_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2560_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2561_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2561_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2515_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_17_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2515_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_18(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_16(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2711_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    if (apply_state_turn_23__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2711_0;
    return false;
}

bool GameState::apply_state_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3209_0 = me;
    me = opponent[me - 2];
    if (apply_state_turn_38(mr,rgCache))
    {
        return true;
    }
    me = old3209_0;
    return false;
}

bool GameState::apply_state_turn_20__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_1())
    {
        if (apply_state_turn_20_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_20_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2667_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2667_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2668_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2668_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2675_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2675_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2676_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2676_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2683_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2683_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2684_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2684_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2691_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2691_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2692_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2692_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2699_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2699_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2700_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2700_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_20_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_20_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_20_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_20_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2659_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2659_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2660_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2660_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2614_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_20_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2614_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_19(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2810_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    if (apply_state_turn_26__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2810_0;
    return false;
}

bool GameState::apply_state_turn_23__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_1())
    {
        if (apply_state_turn_23_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_23_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2766_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2766_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2767_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2767_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2774_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2774_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2775_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2775_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2782_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2782_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2783_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2783_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2790_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2790_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2791_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2791_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2798_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2798_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2799_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2799_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_23_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_23_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_23_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_23_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2758_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2758_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2759_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2759_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2713_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_23_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2713_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_24(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_22(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2909_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    if (apply_state_turn_29__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2909_0;
    return false;
}

bool GameState::apply_state_turn_26__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_1())
    {
        if (apply_state_turn_26_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_26_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2865_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2865_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2866_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2866_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2873_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2873_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2874_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2874_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2881_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2881_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2882_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2882_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2889_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2889_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2890_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2890_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2897_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2897_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2898_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2898_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_26_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_26_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_26_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_26_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2857_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2857_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2858_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2858_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2812_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_26_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2812_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_25(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3008_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    if (apply_state_turn_32__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old3008_0;
    return false;
}

bool GameState::apply_state_turn_29__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_1())
    {
        if (apply_state_turn_29_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_29_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2964_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2964_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2965_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2965_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2972_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2972_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2973_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2973_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2980_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2980_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2981_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2981_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2988_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2988_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2989_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old2989_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2996_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2996_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2997_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old2997_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_29_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_29_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_29_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_29_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2956_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2956_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2957_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2957_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2911_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_29_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2911_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_30(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3107_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    if (apply_state_turn_35__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old3107_0;
    return false;
}

bool GameState::apply_state_turn_32__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_1())
    {
        if (apply_state_turn_32_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_32_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3063_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3063_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3064_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old3064_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3071_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3071_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3072_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old3072_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3079_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3079_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3080_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old3080_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3087_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3087_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3088_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old3088_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3095_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3095_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3096_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old3096_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_32_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_32_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_32_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_32_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3055_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3055_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3056_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old3056_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3010_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_32_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old3010_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_33(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_12(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_1())
    {
        if (apply_state_turn_35_swapInLine_2(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_35_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_7(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_22(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3162_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3162_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3163_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old3163_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_8(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_29(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_32(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_26(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3170_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3170_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3171_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old3171_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_36(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_39(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_33(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3178_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3178_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3179_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old3179_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_43(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_46(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_40(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3186_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_37(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3186_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3187_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_38(mr,rgCache))
    {
        return true;
    }
    tmp = old3187_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_47(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3194_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_44(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3194_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3195_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_45(mr,rgCache))
    {
        return true;
    }
    tmp = old3195_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_35_swapInLine_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_state_turn_35_swapInLine_15(mr,rgCache))
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_state_turn_35_swapInLine_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_35_swapInLine_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3154_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old3154_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3155_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old3155_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3109_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_35_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old3109_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_36(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1())
    {
        if (apply_state_turn_39(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_40(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3571_0 = player;
    player = opponent[me - 2];
    currentState = 1036;
    return true;
    player = old3571_0;
    return false;
}

bool GameState::apply_state_turn_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3574_0 = player;
    player = keeper;
    currentState = 1038;
    return true;
    player = old3574_0;
    return false;
}

bool GameState::apply_state_turn_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()!=rgCache.currentMrId)
    {
        return false;
    }
    player = keeper;
    currentState = 1037;
    return true;
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_turn_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_turn_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_41(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3575_0 = tmp;
    tmp = V__0_0;
    if (apply_state_turn_46(mr,rgCache))
    {
        return true;
    }
    tmp = old3575_0;
    return false;
}

bool GameState::apply_state_turn_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_47(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==white)
    {
        if (apply_state_turn_49(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_turn_50(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_48([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((count[black - 2]<count[white - 2])==1)
    {
        if (apply_state_turn_60(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_turn_61(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_49([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3579_0 = count[white - 2];
    count[white - 2] = count[white - 2]+1;
    if (apply_state_turn_52(mr,rgCache))
    {
        return true;
    }
    count[white - 2] = old3579_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 9;
            return true;
    }
    return false;
}

bool GameState::apply_state_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_turn_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[tmp]==black)
    {
        if (apply_state_turn_53(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_turn_54(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3586_0 = tmp;
    tmp = nextPos[tmp];
    if (apply_state_turn_56(mr,rgCache))
    {
        return true;
    }
    tmp = old3586_0;
    return false;
}

bool GameState::apply_state_turn_52([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_51(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3583_0 = count[black - 2];
    count[black - 2] = count[black - 2]+1;
    if (apply_state_turn_55(mr,rgCache))
    {
        return true;
    }
    count[black - 2] = old3583_0;
    return false;
}

bool GameState::apply_state_turn_54([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_51(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_54(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (tmp==null)
    {
        if (apply_state_turn_57(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_turn_58(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_57([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_48(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 66)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_59(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_47(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_1())
    {
        if (apply_state_turn_7(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_60([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3594_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_turn_63(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old3594_0;
    return false;
}

bool GameState::apply_state_turn_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((count[white - 2]<count[black - 2])==1)
    {
        if (apply_state_turn_65(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_turn_66(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_62([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3603_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old3603_0;
    return false;
}

bool GameState::apply_state_turn_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3595_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_turn_64(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old3595_0;
    return false;
}

bool GameState::apply_state_turn_64([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_62(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3599_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_turn_67(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old3599_0;
    return false;
}

bool GameState::apply_state_turn_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_62(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_67([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old3600_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_turn_68(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old3600_0;
    return false;
}

bool GameState::apply_state_turn_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_66(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + pos)
    {
        rgCache.currentMrId++;
        if (apply_state_turn_9(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_turn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2412_0 = player;
    player = keeper;
    currentState = 9;
    return true;
    player = old2412_0;
    return false;
}

bool GameState::apply_state_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1())
    {
        if (apply_state_turn_1(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3(mr,rgCache))
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
    if (apply_any_begin_begin_turn_begin())
    {
        return true;
    }
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

bool GameState::apply_any_begin_begin_turn_1()
{
    const auto old17_0 = player;
    player = me;
    currentState = 1356;
    return true;
    if (apply_any_begin_begin_turn_5())
    {
        return true;
    }
    player = old17_0;
    return false;
}

bool GameState::apply_any_begin_begin_turn_2()
{
    const auto old18_0 = me;
    me = opponent[me - 2];
    if (apply_any_begin_begin_turn_38())
    {
        return true;
    }
    me = old18_0;
    return false;
}

bool GameState::apply_any_begin_begin_turn_38()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1())
    {
        if (apply_any_begin_begin_turn_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_turn_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_turn_39()
{
    const auto old21_0 = player;
    player = opponent[me - 2];
    currentState = 1036;
    return true;
    if (apply_any_begin_begin_turn_43())
    {
        return true;
    }
    player = old21_0;
    return false;
}

bool GameState::apply_any_begin_begin_turn_40()
{
    const auto old22_0 = player;
    player = keeper;
    currentState = 1038;
    return true;
    if (apply_any_begin_begin_turn_45())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_begin_begin_turn_43()
{
    return true;
}

bool GameState::apply_any_begin_begin_turn_45()
{
    return true;
}

bool GameState::apply_any_begin_begin_turn_5()
{
    return true;
}

bool GameState::apply_any_begin_begin_turn_begin()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1())
    {
        if (apply_any_begin_begin_turn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_turn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_rules_1()
{
    if (apply_any_turn_10_turn_10_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_rules_3()
{
    if (apply_any_turn_10_turn_10_rules_1())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_1()
{
    const auto old428_0 = player;
    player = me;
    currentState = 1356;
    return true;
    if (apply_any_turn_10_turn_10_turn_5())
    {
        return true;
    }
    player = old428_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_10()
{
    const auto old429_0 = board[pos];
    board[pos] = me;
    if (apply_any_turn_10_turn_10_turn_11())
    {
        return true;
    }
    board[pos] = old429_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_11()
{
    const auto old430_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    if (apply_any_turn_10_turn_10_turn_14__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old430_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_12()
{
    const auto old895_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_10_turn_10_turn_37())
    {
        return true;
    }
    me = old895_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_13()
{
    const auto old488_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    if (apply_any_turn_10_turn_10_turn_17__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old488_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14__1()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_1()
{
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_15()
{
    const auto old444_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old444_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_16()
{
    const auto old445_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_17())
    {
        return true;
    }
    tmp = old445_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_22()
{
    const auto old452_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old452_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_23()
{
    const auto old453_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_24())
    {
        return true;
    }
    tmp = old453_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_29()
{
    const auto old460_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old460_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_30()
{
    const auto old461_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_31())
    {
        return true;
    }
    tmp = old461_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_36()
{
    const auto old468_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old468_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_37()
{
    const auto old469_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_38())
    {
        return true;
    }
    tmp = old469_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_43()
{
    const auto old476_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old476_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_44()
{
    const auto old477_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_45())
    {
        return true;
    }
    tmp = old477_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_14_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_8()
{
    const auto old436_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old436_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_9()
{
    const auto old437_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_10())
    {
        return true;
    }
    tmp = old437_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_begin()
{
    const auto old432_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_1())
    {
        return true;
    }
    tmp = old432_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_15())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_15()
{
    if (apply_any_turn_10_turn_10_turn_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_16()
{
    const auto old546_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    if (apply_any_turn_10_turn_10_turn_20__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old546_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17__1()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_1()
{
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_15()
{
    const auto old502_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old502_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_16()
{
    const auto old503_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_17())
    {
        return true;
    }
    tmp = old503_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_22()
{
    const auto old510_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old510_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_23()
{
    const auto old511_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_24())
    {
        return true;
    }
    tmp = old511_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_29()
{
    const auto old518_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old518_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_30()
{
    const auto old519_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_31())
    {
        return true;
    }
    tmp = old519_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_36()
{
    const auto old526_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old526_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_37()
{
    const auto old527_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_38())
    {
        return true;
    }
    tmp = old527_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_43()
{
    const auto old534_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old534_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_44()
{
    const auto old535_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_45())
    {
        return true;
    }
    tmp = old535_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_17_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_8()
{
    const auto old494_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old494_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_9()
{
    const auto old495_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_10())
    {
        return true;
    }
    tmp = old495_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_begin()
{
    const auto old490_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_1())
    {
        return true;
    }
    tmp = old490_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_18())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_18()
{
    if (apply_any_turn_10_turn_10_turn_16())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_19()
{
    const auto old604_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    if (apply_any_turn_10_turn_10_turn_23__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old604_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_2()
{
    const auto old897_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_10_turn_10_turn_38())
    {
        return true;
    }
    me = old897_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20__1()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_1()
{
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_15()
{
    const auto old560_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old560_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_16()
{
    const auto old561_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_17())
    {
        return true;
    }
    tmp = old561_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_22()
{
    const auto old568_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old568_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_23()
{
    const auto old569_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_24())
    {
        return true;
    }
    tmp = old569_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_29()
{
    const auto old576_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old576_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_30()
{
    const auto old577_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_31())
    {
        return true;
    }
    tmp = old577_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_36()
{
    const auto old584_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old584_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_37()
{
    const auto old585_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_38())
    {
        return true;
    }
    tmp = old585_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_43()
{
    const auto old592_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old592_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_44()
{
    const auto old593_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_45())
    {
        return true;
    }
    tmp = old593_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_20_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_8()
{
    const auto old552_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old552_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_9()
{
    const auto old553_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_10())
    {
        return true;
    }
    tmp = old553_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_begin()
{
    const auto old548_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_1())
    {
        return true;
    }
    tmp = old548_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_21()
{
    if (apply_any_turn_10_turn_10_turn_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_22()
{
    const auto old662_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    if (apply_any_turn_10_turn_10_turn_26__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old662_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23__1()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_1()
{
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_15()
{
    const auto old618_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old618_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_16()
{
    const auto old619_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_17())
    {
        return true;
    }
    tmp = old619_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_22()
{
    const auto old626_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old626_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_23()
{
    const auto old627_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_24())
    {
        return true;
    }
    tmp = old627_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_29()
{
    const auto old634_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old634_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_30()
{
    const auto old635_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_31())
    {
        return true;
    }
    tmp = old635_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_36()
{
    const auto old642_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old642_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_37()
{
    const auto old643_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_38())
    {
        return true;
    }
    tmp = old643_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_43()
{
    const auto old650_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old650_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_44()
{
    const auto old651_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_45())
    {
        return true;
    }
    tmp = old651_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_23_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_8()
{
    const auto old610_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old610_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_9()
{
    const auto old611_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_10())
    {
        return true;
    }
    tmp = old611_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_begin()
{
    const auto old606_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_1())
    {
        return true;
    }
    tmp = old606_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_24())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_24()
{
    if (apply_any_turn_10_turn_10_turn_22())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_25()
{
    const auto old720_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    if (apply_any_turn_10_turn_10_turn_29__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old720_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26__1()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_1()
{
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_15()
{
    const auto old676_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old676_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_16()
{
    const auto old677_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_17())
    {
        return true;
    }
    tmp = old677_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_22()
{
    const auto old684_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old684_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_23()
{
    const auto old685_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_24())
    {
        return true;
    }
    tmp = old685_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_29()
{
    const auto old692_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old692_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_30()
{
    const auto old693_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_31())
    {
        return true;
    }
    tmp = old693_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_36()
{
    const auto old700_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old700_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_37()
{
    const auto old701_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_38())
    {
        return true;
    }
    tmp = old701_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_43()
{
    const auto old708_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old708_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_44()
{
    const auto old709_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_45())
    {
        return true;
    }
    tmp = old709_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_26_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_8()
{
    const auto old668_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old668_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_9()
{
    const auto old669_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_10())
    {
        return true;
    }
    tmp = old669_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_begin()
{
    const auto old664_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_1())
    {
        return true;
    }
    tmp = old664_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_27()
{
    if (apply_any_turn_10_turn_10_turn_25())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_28()
{
    const auto old778_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    if (apply_any_turn_10_turn_10_turn_32__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old778_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29__1()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_1()
{
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_15()
{
    const auto old734_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old734_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_16()
{
    const auto old735_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_17())
    {
        return true;
    }
    tmp = old735_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_22()
{
    const auto old742_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old742_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_23()
{
    const auto old743_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_24())
    {
        return true;
    }
    tmp = old743_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_29()
{
    const auto old750_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old750_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_30()
{
    const auto old751_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_31())
    {
        return true;
    }
    tmp = old751_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_36()
{
    const auto old758_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old758_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_37()
{
    const auto old759_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_38())
    {
        return true;
    }
    tmp = old759_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_43()
{
    const auto old766_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old766_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_44()
{
    const auto old767_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_45())
    {
        return true;
    }
    tmp = old767_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_29_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_8()
{
    const auto old726_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old726_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_9()
{
    const auto old727_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_10())
    {
        return true;
    }
    tmp = old727_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_begin()
{
    const auto old722_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_1())
    {
        return true;
    }
    tmp = old722_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_30())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_3()
{
    if (apply_any_turn_10_turn_10_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_30()
{
    if (apply_any_turn_10_turn_10_turn_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_31()
{
    const auto old836_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    if (apply_any_turn_10_turn_10_turn_35__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old836_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32__1()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_1()
{
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_15()
{
    const auto old792_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old792_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_16()
{
    const auto old793_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_17())
    {
        return true;
    }
    tmp = old793_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_22()
{
    const auto old800_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old800_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_23()
{
    const auto old801_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_24())
    {
        return true;
    }
    tmp = old801_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_29()
{
    const auto old808_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old808_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_30()
{
    const auto old809_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_31())
    {
        return true;
    }
    tmp = old809_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_36()
{
    const auto old816_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old816_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_37()
{
    const auto old817_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_38())
    {
        return true;
    }
    tmp = old817_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_43()
{
    const auto old824_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old824_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_44()
{
    const auto old825_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_45())
    {
        return true;
    }
    tmp = old825_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_32_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_8()
{
    const auto old784_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old784_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_9()
{
    const auto old785_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_10())
    {
        return true;
    }
    tmp = old785_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_begin()
{
    const auto old780_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_1())
    {
        return true;
    }
    tmp = old780_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_33()
{
    if (apply_any_turn_10_turn_10_turn_31())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_34()
{
    if (apply_any_turn_10_turn_10_turn_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35__1()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_1()
{
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_2())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_10()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_7())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_11()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_12()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_13()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_22())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_25())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_14()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_15()
{
    const auto old850_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old850_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_16()
{
    const auto old851_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_17())
    {
        return true;
    }
    tmp = old851_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_17()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_18()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_19()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_2()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_8())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_20()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_29())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_21()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_22()
{
    const auto old858_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old858_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_23()
{
    const auto old859_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_24())
    {
        return true;
    }
    tmp = old859_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_24()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_25()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_26()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_27()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_36())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_39())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_28()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_33())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_29()
{
    const auto old866_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old866_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_3()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_30()
{
    const auto old867_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_31())
    {
        return true;
    }
    tmp = old867_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_31()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_32()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_33()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_34()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_43())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_46())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_35()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_36()
{
    const auto old874_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_37())
    {
        return true;
    }
    board[tmp] = old874_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_37()
{
    const auto old875_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_38())
    {
        return true;
    }
    tmp = old875_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_38()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_39()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_40()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_41()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_42()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_43()
{
    const auto old882_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_44())
    {
        return true;
    }
    board[tmp] = old882_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_44()
{
    const auto old883_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_45())
    {
        return true;
    }
    tmp = old883_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_45()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_46()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_47()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_5()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_6()
{
    if (board[tmp]==opponent[me - 2])
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_15())
        {
            return true;
        }
    }
    if (board[tmp]==me)
    {
        if (apply_any_turn_10_turn_10_turn_35_swapInLine_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_7()
{
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_8()
{
    const auto old842_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old842_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_9()
{
    const auto old843_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_10())
    {
        return true;
    }
    tmp = old843_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_begin()
{
    const auto old838_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_1())
    {
        return true;
    }
    tmp = old838_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_end()
{
    if (apply_any_turn_10_turn_10_turn_36())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_36()
{
    if (apply_any_turn_10_turn_10_turn_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_37()
{
    if (apply_any_turn_10_turn_10_turn_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_38()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1())
    {
        if (apply_any_turn_10_turn_10_turn_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_39()
{
    const auto old900_0 = player;
    player = opponent[me - 2];
    currentState = 1036;
    return true;
    if (apply_any_turn_10_turn_10_turn_43())
    {
        return true;
    }
    player = old900_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_40()
{
    const auto old901_0 = player;
    player = keeper;
    currentState = 1038;
    return true;
    if (apply_any_turn_10_turn_10_turn_45())
    {
        return true;
    }
    player = old901_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_43()
{
    return true;
}

bool GameState::apply_any_turn_10_turn_10_turn_45()
{
    return true;
}

bool GameState::apply_any_turn_10_turn_10_turn_5()
{
    return true;
}

bool GameState::apply_any_turn_10_turn_10_turn_begin()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1())
    {
        if (apply_any_turn_10_turn_10_turn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_10_turn_10_turn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_end()
{
    if (apply_any_turn_10_turn_10_rules_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_rules_1()
{
    if (apply_any_turn_44_turn_44_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_rules_3()
{
    if (apply_any_turn_44_turn_44_rules_1())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_1()
{
    const auto old18_0 = player;
    player = me;
    currentState = 1356;
    return true;
    if (apply_any_turn_44_turn_44_turn_5())
    {
        return true;
    }
    player = old18_0;
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_2()
{
    const auto old19_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_44_turn_44_turn_38())
    {
        return true;
    }
    me = old19_0;
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_3()
{
    if (apply_any_turn_44_turn_44_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_38()
{
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_1())
    {
        if (apply_any_turn_44_turn_44_turn_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_44_turn_44_turn_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_39()
{
    const auto old22_0 = player;
    player = opponent[me - 2];
    currentState = 1036;
    return true;
    if (apply_any_turn_44_turn_44_turn_43())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_40()
{
    const auto old24_0 = player;
    player = keeper;
    currentState = 1038;
    return true;
    if (apply_any_turn_44_turn_44_turn_45())
    {
        return true;
    }
    player = old24_0;
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_41()
{
    if (apply_any_turn_44_turn_44_turn_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_43()
{
    return true;
}

bool GameState::apply_any_turn_44_turn_44_turn_44()
{
    if (apply_any_turn_44_turn_44_turn_41())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_45()
{
    return true;
}

bool GameState::apply_any_turn_44_turn_44_turn_5()
{
    return true;
}

bool GameState::apply_any_turn_44_turn_44_turn_begin()
{
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_1())
    {
        if (apply_any_turn_44_turn_44_turn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_44_turn_44_turn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_44_turn_44_turn_end()
{
    if (apply_any_turn_44_turn_44_rules_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_end()
{
    return true;
}

bool GameState::apply_any_turn_45_turn_45_turn_45()
{
    const auto old25_0 = tmp;
    tmp = V__0_0;
    if (apply_any_turn_45_turn_45_turn_46())
    {
        return true;
    }
    tmp = old25_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_46()
{
    if (apply_any_turn_45_turn_45_turn_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_47()
{
    if (board[tmp]==white)
    {
        if (apply_any_turn_45_turn_45_turn_49())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_45_turn_45_turn_50())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_48()
{
    if ((count[black - 2]<count[white - 2])==1)
    {
        if (apply_any_turn_45_turn_45_turn_60())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_45_turn_45_turn_61())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_49()
{
    const auto old29_0 = count[white - 2];
    count[white - 2] = count[white - 2]+1;
    if (apply_any_turn_45_turn_45_turn_52())
    {
        return true;
    }
    count[white - 2] = old29_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_50()
{
    if (board[tmp]==black)
    {
        if (apply_any_turn_45_turn_45_turn_53())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_45_turn_45_turn_54())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_51()
{
    const auto old36_0 = tmp;
    tmp = nextPos[tmp];
    if (apply_any_turn_45_turn_45_turn_56())
    {
        return true;
    }
    tmp = old36_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_52()
{
    if (apply_any_turn_45_turn_45_turn_51())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_53()
{
    const auto old33_0 = count[black - 2];
    count[black - 2] = count[black - 2]+1;
    if (apply_any_turn_45_turn_45_turn_55())
    {
        return true;
    }
    count[black - 2] = old33_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_54()
{
    if (apply_any_turn_45_turn_45_turn_51())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_55()
{
    if (apply_any_turn_45_turn_45_turn_54())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_56()
{
    if (tmp==null)
    {
        if (apply_any_turn_45_turn_45_turn_57())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_45_turn_45_turn_58())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_57()
{
    if (apply_any_turn_45_turn_45_turn_48())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_58()
{
    if (apply_any_turn_45_turn_45_turn_59())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_59()
{
    if (apply_any_turn_45_turn_45_turn_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_60()
{
    const auto old44_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_turn_45_turn_45_turn_63())
    {
        return true;
    }
    goals[white - 2] = old44_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_61()
{
    if ((count[white - 2]<count[black - 2])==1)
    {
        if (apply_any_turn_45_turn_45_turn_65())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_45_turn_45_turn_66())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_62()
{
    const auto old53_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_turn_45_turn_45_end())
    {
        return true;
    }
    player = old53_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_63()
{
    const auto old45_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_turn_45_turn_45_turn_64())
    {
        return true;
    }
    goals[black - 2] = old45_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_64()
{
    if (apply_any_turn_45_turn_45_turn_62())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_65()
{
    const auto old49_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_turn_45_turn_45_turn_67())
    {
        return true;
    }
    goals[white - 2] = old49_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_66()
{
    if (apply_any_turn_45_turn_45_turn_62())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_67()
{
    const auto old50_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_turn_45_turn_45_turn_68())
    {
        return true;
    }
    goals[black - 2] = old50_0;
    return false;
}

bool GameState::apply_any_turn_45_turn_45_turn_68()
{
    if (apply_any_turn_45_turn_45_turn_66())
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
