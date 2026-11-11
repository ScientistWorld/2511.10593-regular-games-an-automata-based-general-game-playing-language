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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__0_0: " << board[V__0_0] << ", " << "V__0_1: " << board[V__0_1] << ", " << "V__0_2: " << board[V__0_2] << ", " << "V__0_3: " << board[V__0_3] << ", " << "V__0_4: " << board[V__0_4] << ", " << "V__0_5: " << board[V__0_5] << ", " << "V__1_0: " << board[V__1_0] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__2_0: " << board[V__2_0] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__3_0: " << board[V__3_0] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__4_0: " << board[V__4_0] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__5_0: " << board[V__5_0] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5]<< "}" << std::endl;
    ss << "me = " << me << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "tmp = " << tmp << std::endl;
    ss << "count = " << "{" << "white: " << count[white-2] << ", " << "black: " << count[black-2]<< "}" << std::endl;
    ss << "isCapture_arg0_dir = " << "{" << "null: " << isCapture_arg0_dir[null] << ", " << "V__0_0: " << isCapture_arg0_dir[V__0_0] << ", " << "V__0_1: " << isCapture_arg0_dir[V__0_1] << ", " << "V__0_2: " << isCapture_arg0_dir[V__0_2] << ", " << "V__0_3: " << isCapture_arg0_dir[V__0_3] << ", " << "V__0_4: " << isCapture_arg0_dir[V__0_4] << ", " << "V__0_5: " << isCapture_arg0_dir[V__0_5] << ", " << "V__1_0: " << isCapture_arg0_dir[V__1_0] << ", " << "V__1_1: " << isCapture_arg0_dir[V__1_1] << ", " << "V__1_2: " << isCapture_arg0_dir[V__1_2] << ", " << "V__1_3: " << isCapture_arg0_dir[V__1_3] << ", " << "V__1_4: " << isCapture_arg0_dir[V__1_4] << ", " << "V__1_5: " << isCapture_arg0_dir[V__1_5] << ", " << "V__2_0: " << isCapture_arg0_dir[V__2_0] << ", " << "V__2_1: " << isCapture_arg0_dir[V__2_1] << ", " << "V__2_2: " << isCapture_arg0_dir[V__2_2] << ", " << "V__2_3: " << isCapture_arg0_dir[V__2_3] << ", " << "V__2_4: " << isCapture_arg0_dir[V__2_4] << ", " << "V__2_5: " << isCapture_arg0_dir[V__2_5] << ", " << "V__3_0: " << isCapture_arg0_dir[V__3_0] << ", " << "V__3_1: " << isCapture_arg0_dir[V__3_1] << ", " << "V__3_2: " << isCapture_arg0_dir[V__3_2] << ", " << "V__3_3: " << isCapture_arg0_dir[V__3_3] << ", " << "V__3_4: " << isCapture_arg0_dir[V__3_4] << ", " << "V__3_5: " << isCapture_arg0_dir[V__3_5] << ", " << "V__4_0: " << isCapture_arg0_dir[V__4_0] << ", " << "V__4_1: " << isCapture_arg0_dir[V__4_1] << ", " << "V__4_2: " << isCapture_arg0_dir[V__4_2] << ", " << "V__4_3: " << isCapture_arg0_dir[V__4_3] << ", " << "V__4_4: " << isCapture_arg0_dir[V__4_4] << ", " << "V__4_5: " << isCapture_arg0_dir[V__4_5] << ", " << "V__5_0: " << isCapture_arg0_dir[V__5_0] << ", " << "V__5_1: " << isCapture_arg0_dir[V__5_1] << ", " << "V__5_2: " << isCapture_arg0_dir[V__5_2] << ", " << "V__5_3: " << isCapture_arg0_dir[V__5_3] << ", " << "V__5_4: " << isCapture_arg0_dir[V__5_4] << ", " << "V__5_5: " << isCapture_arg0_dir[V__5_5]<< "}" << std::endl;
    ss << "swapInLine_arg0_dir = " << "{" << "null: " << swapInLine_arg0_dir[null] << ", " << "V__0_0: " << swapInLine_arg0_dir[V__0_0] << ", " << "V__0_1: " << swapInLine_arg0_dir[V__0_1] << ", " << "V__0_2: " << swapInLine_arg0_dir[V__0_2] << ", " << "V__0_3: " << swapInLine_arg0_dir[V__0_3] << ", " << "V__0_4: " << swapInLine_arg0_dir[V__0_4] << ", " << "V__0_5: " << swapInLine_arg0_dir[V__0_5] << ", " << "V__1_0: " << swapInLine_arg0_dir[V__1_0] << ", " << "V__1_1: " << swapInLine_arg0_dir[V__1_1] << ", " << "V__1_2: " << swapInLine_arg0_dir[V__1_2] << ", " << "V__1_3: " << swapInLine_arg0_dir[V__1_3] << ", " << "V__1_4: " << swapInLine_arg0_dir[V__1_4] << ", " << "V__1_5: " << swapInLine_arg0_dir[V__1_5] << ", " << "V__2_0: " << swapInLine_arg0_dir[V__2_0] << ", " << "V__2_1: " << swapInLine_arg0_dir[V__2_1] << ", " << "V__2_2: " << swapInLine_arg0_dir[V__2_2] << ", " << "V__2_3: " << swapInLine_arg0_dir[V__2_3] << ", " << "V__2_4: " << swapInLine_arg0_dir[V__2_4] << ", " << "V__2_5: " << swapInLine_arg0_dir[V__2_5] << ", " << "V__3_0: " << swapInLine_arg0_dir[V__3_0] << ", " << "V__3_1: " << swapInLine_arg0_dir[V__3_1] << ", " << "V__3_2: " << swapInLine_arg0_dir[V__3_2] << ", " << "V__3_3: " << swapInLine_arg0_dir[V__3_3] << ", " << "V__3_4: " << swapInLine_arg0_dir[V__3_4] << ", " << "V__3_5: " << swapInLine_arg0_dir[V__3_5] << ", " << "V__4_0: " << swapInLine_arg0_dir[V__4_0] << ", " << "V__4_1: " << swapInLine_arg0_dir[V__4_1] << ", " << "V__4_2: " << swapInLine_arg0_dir[V__4_2] << ", " << "V__4_3: " << swapInLine_arg0_dir[V__4_3] << ", " << "V__4_4: " << swapInLine_arg0_dir[V__4_4] << ", " << "V__4_5: " << swapInLine_arg0_dir[V__4_5] << ", " << "V__5_0: " << swapInLine_arg0_dir[V__5_0] << ", " << "V__5_1: " << swapInLine_arg0_dir[V__5_1] << ", " << "V__5_2: " << swapInLine_arg0_dir[V__5_2] << ", " << "V__5_3: " << swapInLine_arg0_dir[V__5_3] << ", " << "V__5_4: " << swapInLine_arg0_dir[V__5_4] << ", " << "V__5_5: " << swapInLine_arg0_dir[V__5_5]<< "}" << std::endl;
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
        case 1004:
{
            state_turn_5(moves, mr.mr);
            return;
}
        case 764:
{
            state_turn_43(moves, mr.mr);
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
        case 1004:
{
            apply_state_turn_5(mr.mr,rgCache);
            return;
}
        case 764:
{
            apply_state_turn_43(mr.mr,rgCache);
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
        case 765:
{
            apply_any_turn_44_turn_44_turn_44();
            break;
}
        case 766:
{
            apply_any_turn_45_turn_45_turn_45();
            break;
}
    }
}

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_1()
{
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_14_swapInLine_4_1_turn_14_swapInLine_4_isCapture_end_turn_14_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_17_swapInLine_4_1_turn_17_swapInLine_4_isCapture_end_turn_17_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_20_swapInLine_4_1_turn_20_swapInLine_4_isCapture_end_turn_20_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_23_swapInLine_4_1_turn_23_swapInLine_4_isCapture_end_turn_23_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_26_swapInLine_4_1_turn_26_swapInLine_4_isCapture_end_turn_26_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_29_swapInLine_4_1_turn_29_swapInLine_4_isCapture_end_turn_29_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_32_swapInLine_4_1_turn_32_swapInLine_4_isCapture_end_turn_32_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old22_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = swapInLine_arg0_dir;
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_2())
    {
        isCapture_arg0_dir = old22_0;
        return true;
    }
    isCapture_arg0_dir = old22_0;
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
    const auto old25_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_4())
    {
        tmp = old25_0;
        return true;
    }
    tmp = old25_0;
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
    const auto old43_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_19())
    {
        tmp = old43_0;
        return true;
    }
    tmp = old43_0;
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

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_3()
{
    const auto old31_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_9())
    {
        tmp = old31_0;
        return true;
    }
    tmp = old31_0;
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
    const auto old37_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_35_swapInLine_4_1_turn_35_swapInLine_4_isCapture_end_turn_35_swapInLine_4_isCapture_14())
    {
        tmp = old37_0;
        return true;
    }
    tmp = old37_0;
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
    const auto old197_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_3())
    {
        tmp = old197_0;
        return true;
    }
    tmp = old197_0;
    const auto old224_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_6())
    {
        tmp = old224_0;
        return true;
    }
    tmp = old224_0;
    const auto old251_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_9())
    {
        tmp = old251_0;
        return true;
    }
    tmp = old251_0;
    const auto old278_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_12())
    {
        tmp = old278_0;
        return true;
    }
    tmp = old278_0;
    const auto old305_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_15())
    {
        tmp = old305_0;
        return true;
    }
    tmp = old305_0;
    const auto old332_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_18())
    {
        tmp = old332_0;
        return true;
    }
    tmp = old332_0;
    const auto old359_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_21())
    {
        tmp = old359_0;
        return true;
    }
    tmp = old359_0;
    const auto old386_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_24())
    {
        tmp = old386_0;
        return true;
    }
    tmp = old386_0;
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
    const auto old255_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_4())
    {
        tmp = old255_0;
        return true;
    }
    tmp = old255_0;
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
    const auto old273_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_19())
    {
        tmp = old273_0;
        return true;
    }
    tmp = old273_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_3()
{
    const auto old261_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_9())
    {
        tmp = old261_0;
        return true;
    }
    tmp = old261_0;
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
    const auto old267_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10_isCapture_14())
    {
        tmp = old267_0;
        return true;
    }
    tmp = old267_0;
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
    const auto old279_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old279_0;
        return true;
    }
    isCapture_arg0_dir = old279_0;
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
    const auto old282_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_4())
    {
        tmp = old282_0;
        return true;
    }
    tmp = old282_0;
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
    const auto old300_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_19())
    {
        tmp = old300_0;
        return true;
    }
    tmp = old300_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_3()
{
    const auto old288_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_9())
    {
        tmp = old288_0;
        return true;
    }
    tmp = old288_0;
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
    const auto old294_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_13_isCapture_14())
    {
        tmp = old294_0;
        return true;
    }
    tmp = old294_0;
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
    const auto old306_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old306_0;
        return true;
    }
    isCapture_arg0_dir = old306_0;
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
    const auto old309_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_4())
    {
        tmp = old309_0;
        return true;
    }
    tmp = old309_0;
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
    const auto old327_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_19())
    {
        tmp = old327_0;
        return true;
    }
    tmp = old327_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_3()
{
    const auto old315_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_9())
    {
        tmp = old315_0;
        return true;
    }
    tmp = old315_0;
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
    const auto old321_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_16_isCapture_14())
    {
        tmp = old321_0;
        return true;
    }
    tmp = old321_0;
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
    const auto old333_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old333_0;
        return true;
    }
    isCapture_arg0_dir = old333_0;
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
    const auto old336_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_4())
    {
        tmp = old336_0;
        return true;
    }
    tmp = old336_0;
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
    const auto old354_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_19())
    {
        tmp = old354_0;
        return true;
    }
    tmp = old354_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_3()
{
    const auto old342_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_9())
    {
        tmp = old342_0;
        return true;
    }
    tmp = old342_0;
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
    const auto old348_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_19_isCapture_14())
    {
        tmp = old348_0;
        return true;
    }
    tmp = old348_0;
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
    const auto old360_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old360_0;
        return true;
    }
    isCapture_arg0_dir = old360_0;
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
    const auto old363_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_4())
    {
        tmp = old363_0;
        return true;
    }
    tmp = old363_0;
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
    const auto old381_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_19())
    {
        tmp = old381_0;
        return true;
    }
    tmp = old381_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_3()
{
    const auto old369_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_9())
    {
        tmp = old369_0;
        return true;
    }
    tmp = old369_0;
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
    const auto old375_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_22_isCapture_14())
    {
        tmp = old375_0;
        return true;
    }
    tmp = old375_0;
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
    const auto old387_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old387_0;
        return true;
    }
    isCapture_arg0_dir = old387_0;
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
    const auto old390_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_4())
    {
        tmp = old390_0;
        return true;
    }
    tmp = old390_0;
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
    const auto old408_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_19())
    {
        tmp = old408_0;
        return true;
    }
    tmp = old408_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_3()
{
    const auto old396_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_9())
    {
        tmp = old396_0;
        return true;
    }
    tmp = old396_0;
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
    const auto old402_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_25_isCapture_14())
    {
        tmp = old402_0;
        return true;
    }
    tmp = old402_0;
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
    const auto old198_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old198_0;
        return true;
    }
    isCapture_arg0_dir = old198_0;
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
    const auto old201_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_4())
    {
        tmp = old201_0;
        return true;
    }
    tmp = old201_0;
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
    const auto old219_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_19())
    {
        tmp = old219_0;
        return true;
    }
    tmp = old219_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_3()
{
    const auto old207_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_9())
    {
        tmp = old207_0;
        return true;
    }
    tmp = old207_0;
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
    const auto old213_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_4_isCapture_14())
    {
        tmp = old213_0;
        return true;
    }
    tmp = old213_0;
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
    const auto old225_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old225_0;
        return true;
    }
    isCapture_arg0_dir = old225_0;
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
    const auto old228_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_4())
    {
        tmp = old228_0;
        return true;
    }
    tmp = old228_0;
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
    const auto old246_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_19())
    {
        tmp = old246_0;
        return true;
    }
    tmp = old246_0;
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_3()
{
    const auto old234_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_9())
    {
        tmp = old234_0;
        return true;
    }
    tmp = old234_0;
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
    const auto old240_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_7_isCapture_14())
    {
        tmp = old240_0;
        return true;
    }
    tmp = old240_0;
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
    const auto old252_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_2_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old252_0;
        return true;
    }
    isCapture_arg0_dir = old252_0;
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
    const auto old194_0 = pos;
    for (pos = V__0_0; pos <= V__5_5; ++pos)
    {
    if (is_legal_turn_42_1_turn_42_existsMove_end_turn_42_existsMove_1())
    {
        pos = old194_0;
        return true;
    }    }
    pos = old194_0;
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
    const auto old197_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_3())
    {
        tmp = old197_0;
        return true;
    }
    tmp = old197_0;
    const auto old224_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_6())
    {
        tmp = old224_0;
        return true;
    }
    tmp = old224_0;
    const auto old251_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_9())
    {
        tmp = old251_0;
        return true;
    }
    tmp = old251_0;
    const auto old278_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_12())
    {
        tmp = old278_0;
        return true;
    }
    tmp = old278_0;
    const auto old305_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_15())
    {
        tmp = old305_0;
        return true;
    }
    tmp = old305_0;
    const auto old332_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_18())
    {
        tmp = old332_0;
        return true;
    }
    tmp = old332_0;
    const auto old359_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_21())
    {
        tmp = old359_0;
        return true;
    }
    tmp = old359_0;
    const auto old386_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_24())
    {
        tmp = old386_0;
        return true;
    }
    tmp = old386_0;
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
    const auto old255_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_4())
    {
        tmp = old255_0;
        return true;
    }
    tmp = old255_0;
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
    const auto old273_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_19())
    {
        tmp = old273_0;
        return true;
    }
    tmp = old273_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_3()
{
    const auto old261_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_9())
    {
        tmp = old261_0;
        return true;
    }
    tmp = old261_0;
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
    const auto old267_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10_isCapture_14())
    {
        tmp = old267_0;
        return true;
    }
    tmp = old267_0;
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
    const auto old279_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old279_0;
        return true;
    }
    isCapture_arg0_dir = old279_0;
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
    const auto old282_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_4())
    {
        tmp = old282_0;
        return true;
    }
    tmp = old282_0;
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
    const auto old300_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_19())
    {
        tmp = old300_0;
        return true;
    }
    tmp = old300_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_3()
{
    const auto old288_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_9())
    {
        tmp = old288_0;
        return true;
    }
    tmp = old288_0;
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
    const auto old294_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_13_isCapture_14())
    {
        tmp = old294_0;
        return true;
    }
    tmp = old294_0;
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
    const auto old306_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old306_0;
        return true;
    }
    isCapture_arg0_dir = old306_0;
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
    const auto old309_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_4())
    {
        tmp = old309_0;
        return true;
    }
    tmp = old309_0;
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
    const auto old327_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_19())
    {
        tmp = old327_0;
        return true;
    }
    tmp = old327_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_3()
{
    const auto old315_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_9())
    {
        tmp = old315_0;
        return true;
    }
    tmp = old315_0;
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
    const auto old321_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_16_isCapture_14())
    {
        tmp = old321_0;
        return true;
    }
    tmp = old321_0;
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
    const auto old333_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old333_0;
        return true;
    }
    isCapture_arg0_dir = old333_0;
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
    const auto old336_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_4())
    {
        tmp = old336_0;
        return true;
    }
    tmp = old336_0;
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
    const auto old354_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_19())
    {
        tmp = old354_0;
        return true;
    }
    tmp = old354_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_3()
{
    const auto old342_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_9())
    {
        tmp = old342_0;
        return true;
    }
    tmp = old342_0;
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
    const auto old348_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_19_isCapture_14())
    {
        tmp = old348_0;
        return true;
    }
    tmp = old348_0;
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
    const auto old360_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old360_0;
        return true;
    }
    isCapture_arg0_dir = old360_0;
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
    const auto old363_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_4())
    {
        tmp = old363_0;
        return true;
    }
    tmp = old363_0;
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
    const auto old381_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_19())
    {
        tmp = old381_0;
        return true;
    }
    tmp = old381_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_3()
{
    const auto old369_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_9())
    {
        tmp = old369_0;
        return true;
    }
    tmp = old369_0;
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
    const auto old375_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_22_isCapture_14())
    {
        tmp = old375_0;
        return true;
    }
    tmp = old375_0;
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
    const auto old387_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old387_0;
        return true;
    }
    isCapture_arg0_dir = old387_0;
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
    const auto old390_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_4())
    {
        tmp = old390_0;
        return true;
    }
    tmp = old390_0;
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
    const auto old408_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_19())
    {
        tmp = old408_0;
        return true;
    }
    tmp = old408_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_3()
{
    const auto old396_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_9())
    {
        tmp = old396_0;
        return true;
    }
    tmp = old396_0;
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
    const auto old402_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_25_isCapture_14())
    {
        tmp = old402_0;
        return true;
    }
    tmp = old402_0;
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
    const auto old198_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old198_0;
        return true;
    }
    isCapture_arg0_dir = old198_0;
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
    const auto old201_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_4())
    {
        tmp = old201_0;
        return true;
    }
    tmp = old201_0;
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
    const auto old219_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_19())
    {
        tmp = old219_0;
        return true;
    }
    tmp = old219_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_3()
{
    const auto old207_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_9())
    {
        tmp = old207_0;
        return true;
    }
    tmp = old207_0;
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
    const auto old213_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_4_isCapture_14())
    {
        tmp = old213_0;
        return true;
    }
    tmp = old213_0;
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
    const auto old225_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old225_0;
        return true;
    }
    isCapture_arg0_dir = old225_0;
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
    const auto old228_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_4())
    {
        tmp = old228_0;
        return true;
    }
    tmp = old228_0;
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
    const auto old246_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_19())
    {
        tmp = old246_0;
        return true;
    }
    tmp = old246_0;
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_3()
{
    const auto old234_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_9())
    {
        tmp = old234_0;
        return true;
    }
    tmp = old234_0;
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
    const auto old240_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_7_isCapture_14())
    {
        tmp = old240_0;
        return true;
    }
    tmp = old240_0;
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
    const auto old252_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_2_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old252_0;
        return true;
    }
    isCapture_arg0_dir = old252_0;
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
    const auto old194_0 = pos;
    for (pos = V__0_0; pos <= V__5_5; ++pos)
    {
    if (is_legal_turn_4_1_turn_4_existsMove_end_turn_4_existsMove_1())
    {
        pos = old194_0;
        return true;
    }    }
    pos = old194_0;
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
    const auto old191_0 = tmp;
    tmp = up[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_3())
    {
        tmp = old191_0;
        return true;
    }
    tmp = old191_0;
    const auto old218_0 = tmp;
    tmp = down[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_6())
    {
        tmp = old218_0;
        return true;
    }
    tmp = old218_0;
    const auto old245_0 = tmp;
    tmp = left[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_9())
    {
        tmp = old245_0;
        return true;
    }
    tmp = old245_0;
    const auto old272_0 = tmp;
    tmp = right[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_12())
    {
        tmp = old272_0;
        return true;
    }
    tmp = old272_0;
    const auto old299_0 = tmp;
    tmp = upLeft[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_15())
    {
        tmp = old299_0;
        return true;
    }
    tmp = old299_0;
    const auto old326_0 = tmp;
    tmp = upRight[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_18())
    {
        tmp = old326_0;
        return true;
    }
    tmp = old326_0;
    const auto old353_0 = tmp;
    tmp = downLeft[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_21())
    {
        tmp = old353_0;
        return true;
    }
    tmp = old353_0;
    const auto old380_0 = tmp;
    tmp = downRight[pos];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_24())
    {
        tmp = old380_0;
        return true;
    }
    tmp = old380_0;
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
    const auto old249_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_4())
    {
        tmp = old249_0;
        return true;
    }
    tmp = old249_0;
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
    const auto old267_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_19())
    {
        tmp = old267_0;
        return true;
    }
    tmp = old267_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_3()
{
    const auto old255_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_9())
    {
        tmp = old255_0;
        return true;
    }
    tmp = old255_0;
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
    const auto old261_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10_isCapture_14())
    {
        tmp = old261_0;
        return true;
    }
    tmp = old261_0;
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
    const auto old273_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = right;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13__1())
    {
        isCapture_arg0_dir = old273_0;
        return true;
    }
    isCapture_arg0_dir = old273_0;
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
    const auto old276_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_4())
    {
        tmp = old276_0;
        return true;
    }
    tmp = old276_0;
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
    const auto old294_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_19())
    {
        tmp = old294_0;
        return true;
    }
    tmp = old294_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_3()
{
    const auto old282_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_9())
    {
        tmp = old282_0;
        return true;
    }
    tmp = old282_0;
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
    const auto old288_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_13_isCapture_14())
    {
        tmp = old288_0;
        return true;
    }
    tmp = old288_0;
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
    const auto old300_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upLeft;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16__1())
    {
        isCapture_arg0_dir = old300_0;
        return true;
    }
    isCapture_arg0_dir = old300_0;
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
    const auto old303_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_4())
    {
        tmp = old303_0;
        return true;
    }
    tmp = old303_0;
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
    const auto old321_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_19())
    {
        tmp = old321_0;
        return true;
    }
    tmp = old321_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_3()
{
    const auto old309_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_9())
    {
        tmp = old309_0;
        return true;
    }
    tmp = old309_0;
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
    const auto old315_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_16_isCapture_14())
    {
        tmp = old315_0;
        return true;
    }
    tmp = old315_0;
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
    const auto old327_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = upRight;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19__1())
    {
        isCapture_arg0_dir = old327_0;
        return true;
    }
    isCapture_arg0_dir = old327_0;
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
    const auto old330_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_4())
    {
        tmp = old330_0;
        return true;
    }
    tmp = old330_0;
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
    const auto old348_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_19())
    {
        tmp = old348_0;
        return true;
    }
    tmp = old348_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_3()
{
    const auto old336_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_9())
    {
        tmp = old336_0;
        return true;
    }
    tmp = old336_0;
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
    const auto old342_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_19_isCapture_14())
    {
        tmp = old342_0;
        return true;
    }
    tmp = old342_0;
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
    const auto old354_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downLeft;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22__1())
    {
        isCapture_arg0_dir = old354_0;
        return true;
    }
    isCapture_arg0_dir = old354_0;
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
    const auto old357_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_4())
    {
        tmp = old357_0;
        return true;
    }
    tmp = old357_0;
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
    const auto old375_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_19())
    {
        tmp = old375_0;
        return true;
    }
    tmp = old375_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_3()
{
    const auto old363_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_9())
    {
        tmp = old363_0;
        return true;
    }
    tmp = old363_0;
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
    const auto old369_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_22_isCapture_14())
    {
        tmp = old369_0;
        return true;
    }
    tmp = old369_0;
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
    const auto old381_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = downRight;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25__1())
    {
        isCapture_arg0_dir = old381_0;
        return true;
    }
    isCapture_arg0_dir = old381_0;
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
    const auto old384_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_4())
    {
        tmp = old384_0;
        return true;
    }
    tmp = old384_0;
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
    const auto old402_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_19())
    {
        tmp = old402_0;
        return true;
    }
    tmp = old402_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_3()
{
    const auto old390_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_9())
    {
        tmp = old390_0;
        return true;
    }
    tmp = old390_0;
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
    const auto old396_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_25_isCapture_14())
    {
        tmp = old396_0;
        return true;
    }
    tmp = old396_0;
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
    const auto old192_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = up;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4__1())
    {
        isCapture_arg0_dir = old192_0;
        return true;
    }
    isCapture_arg0_dir = old192_0;
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
    const auto old195_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_4())
    {
        tmp = old195_0;
        return true;
    }
    tmp = old195_0;
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
    const auto old213_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_19())
    {
        tmp = old213_0;
        return true;
    }
    tmp = old213_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_3()
{
    const auto old201_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_9())
    {
        tmp = old201_0;
        return true;
    }
    tmp = old201_0;
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
    const auto old207_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_4_isCapture_14())
    {
        tmp = old207_0;
        return true;
    }
    tmp = old207_0;
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
    const auto old219_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = down;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7__1())
    {
        isCapture_arg0_dir = old219_0;
        return true;
    }
    isCapture_arg0_dir = old219_0;
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
    const auto old222_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_4())
    {
        tmp = old222_0;
        return true;
    }
    tmp = old222_0;
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
    const auto old240_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_19())
    {
        tmp = old240_0;
        return true;
    }
    tmp = old240_0;
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_19()
{
    if (board[tmp]==me)
    {
        if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_22())
        {
            return true;
        }
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

bool GameState::is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_3()
{
    const auto old228_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_9())
    {
        tmp = old228_0;
        return true;
    }
    tmp = old228_0;
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
    const auto old234_0 = tmp;
    tmp = isCapture_arg0_dir[tmp];
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_7_isCapture_14())
    {
        tmp = old234_0;
        return true;
    }
    tmp = old234_0;
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
    const auto old246_0 = isCapture_arg0_dir;
    isCapture_arg0_dir = left;
    if (is_legal_turn_8_1_turn_8_isCorrectMove_end_turn_8_isCorrectMove_10__1())
    {
        isCapture_arg0_dir = old246_0;
        return true;
    }
    isCapture_arg0_dir = old246_0;
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
    const auto old1789_0 = board[pos];
    board[pos] = me;
    state_turn_11(moves, mr);
    board[pos] = old1789_0;
}

void GameState::state_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1790_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    state_turn_14__1(moves, mr);
    swapInLine_arg0_dir = old1790_0;
}

void GameState::state_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2359_0 = me;
    me = opponent[me - 2];
    state_turn_37(moves, mr);
    me = old2359_0;
}

void GameState::state_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1861_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    state_turn_17__1(moves, mr);
    swapInLine_arg0_dir = old1861_0;
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
    mr.emplace_back(37);
    state_turn_14_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1833_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_16(moves, mr);
    board[tmp] = old1833_0;
}

void GameState::state_turn_14_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1834_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_17(moves, mr);
    tmp = old1834_0;
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
    mr.emplace_back(37);
    state_turn_14_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1841_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_23(moves, mr);
    board[tmp] = old1841_0;
}

void GameState::state_turn_14_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1842_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_24(moves, mr);
    tmp = old1842_0;
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
    state_turn_14_swapInLine_5(moves, mr);
}

void GameState::state_turn_14_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_14_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1849_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_30(moves, mr);
    board[tmp] = old1849_0;
}

void GameState::state_turn_14_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_14_swapInLine_end(moves, mr);
}

void GameState::state_turn_14_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1850_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_31(moves, mr);
    tmp = old1850_0;
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
    mr.emplace_back(37);
    state_turn_14_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_14_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1825_0 = board[tmp];
    board[tmp] = me;
    state_turn_14_swapInLine_9(moves, mr);
    board[tmp] = old1825_0;
}

void GameState::state_turn_14_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1826_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_14_swapInLine_10(moves, mr);
    tmp = old1826_0;
}

void GameState::state_turn_14_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1792_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_14_swapInLine_1(moves, mr);
    tmp = old1792_0;
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
    const auto old1932_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    state_turn_20__1(moves, mr);
    swapInLine_arg0_dir = old1932_0;
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
    mr.emplace_back(37);
    state_turn_17_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1904_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_16(moves, mr);
    board[tmp] = old1904_0;
}

void GameState::state_turn_17_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1905_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_17(moves, mr);
    tmp = old1905_0;
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
    mr.emplace_back(37);
    state_turn_17_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1912_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_23(moves, mr);
    board[tmp] = old1912_0;
}

void GameState::state_turn_17_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1913_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_24(moves, mr);
    tmp = old1913_0;
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
    state_turn_17_swapInLine_5(moves, mr);
}

void GameState::state_turn_17_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_17_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1920_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_30(moves, mr);
    board[tmp] = old1920_0;
}

void GameState::state_turn_17_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_17_swapInLine_end(moves, mr);
}

void GameState::state_turn_17_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1921_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_31(moves, mr);
    tmp = old1921_0;
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
    mr.emplace_back(37);
    state_turn_17_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_17_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1896_0 = board[tmp];
    board[tmp] = me;
    state_turn_17_swapInLine_9(moves, mr);
    board[tmp] = old1896_0;
}

void GameState::state_turn_17_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1897_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_17_swapInLine_10(moves, mr);
    tmp = old1897_0;
}

void GameState::state_turn_17_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1863_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_17_swapInLine_1(moves, mr);
    tmp = old1863_0;
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
    const auto old2003_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    state_turn_23__1(moves, mr);
    swapInLine_arg0_dir = old2003_0;
}

void GameState::state_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2361_0 = me;
    me = opponent[me - 2];
    state_turn_38(moves, mr);
    me = old2361_0;
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
    mr.emplace_back(37);
    state_turn_20_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1975_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_16(moves, mr);
    board[tmp] = old1975_0;
}

void GameState::state_turn_20_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1976_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_17(moves, mr);
    tmp = old1976_0;
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
    mr.emplace_back(37);
    state_turn_20_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1983_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_23(moves, mr);
    board[tmp] = old1983_0;
}

void GameState::state_turn_20_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1984_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_24(moves, mr);
    tmp = old1984_0;
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
    state_turn_20_swapInLine_5(moves, mr);
}

void GameState::state_turn_20_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_20_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1991_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_30(moves, mr);
    board[tmp] = old1991_0;
}

void GameState::state_turn_20_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_20_swapInLine_end(moves, mr);
}

void GameState::state_turn_20_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1992_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_31(moves, mr);
    tmp = old1992_0;
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
    mr.emplace_back(37);
    state_turn_20_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_20_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1967_0 = board[tmp];
    board[tmp] = me;
    state_turn_20_swapInLine_9(moves, mr);
    board[tmp] = old1967_0;
}

void GameState::state_turn_20_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1968_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_20_swapInLine_10(moves, mr);
    tmp = old1968_0;
}

void GameState::state_turn_20_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1934_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_20_swapInLine_1(moves, mr);
    tmp = old1934_0;
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
    const auto old2074_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    state_turn_26__1(moves, mr);
    swapInLine_arg0_dir = old2074_0;
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
    mr.emplace_back(37);
    state_turn_23_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2046_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_16(moves, mr);
    board[tmp] = old2046_0;
}

void GameState::state_turn_23_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2047_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_17(moves, mr);
    tmp = old2047_0;
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
    mr.emplace_back(37);
    state_turn_23_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2054_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_23(moves, mr);
    board[tmp] = old2054_0;
}

void GameState::state_turn_23_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2055_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_24(moves, mr);
    tmp = old2055_0;
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
    state_turn_23_swapInLine_5(moves, mr);
}

void GameState::state_turn_23_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_23_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2062_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_30(moves, mr);
    board[tmp] = old2062_0;
}

void GameState::state_turn_23_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_23_swapInLine_end(moves, mr);
}

void GameState::state_turn_23_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2063_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_31(moves, mr);
    tmp = old2063_0;
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
    mr.emplace_back(37);
    state_turn_23_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_23_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2038_0 = board[tmp];
    board[tmp] = me;
    state_turn_23_swapInLine_9(moves, mr);
    board[tmp] = old2038_0;
}

void GameState::state_turn_23_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2039_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_23_swapInLine_10(moves, mr);
    tmp = old2039_0;
}

void GameState::state_turn_23_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2005_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_23_swapInLine_1(moves, mr);
    tmp = old2005_0;
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
    const auto old2145_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    state_turn_29__1(moves, mr);
    swapInLine_arg0_dir = old2145_0;
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
    mr.emplace_back(37);
    state_turn_26_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2117_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_16(moves, mr);
    board[tmp] = old2117_0;
}

void GameState::state_turn_26_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2118_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_17(moves, mr);
    tmp = old2118_0;
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
    mr.emplace_back(37);
    state_turn_26_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2125_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_23(moves, mr);
    board[tmp] = old2125_0;
}

void GameState::state_turn_26_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2126_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_24(moves, mr);
    tmp = old2126_0;
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
    state_turn_26_swapInLine_5(moves, mr);
}

void GameState::state_turn_26_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_26_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2133_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_30(moves, mr);
    board[tmp] = old2133_0;
}

void GameState::state_turn_26_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_26_swapInLine_end(moves, mr);
}

void GameState::state_turn_26_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2134_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_31(moves, mr);
    tmp = old2134_0;
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
    mr.emplace_back(37);
    state_turn_26_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_26_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2109_0 = board[tmp];
    board[tmp] = me;
    state_turn_26_swapInLine_9(moves, mr);
    board[tmp] = old2109_0;
}

void GameState::state_turn_26_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2110_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_26_swapInLine_10(moves, mr);
    tmp = old2110_0;
}

void GameState::state_turn_26_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2076_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_26_swapInLine_1(moves, mr);
    tmp = old2076_0;
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
    const auto old2216_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    state_turn_32__1(moves, mr);
    swapInLine_arg0_dir = old2216_0;
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
    mr.emplace_back(37);
    state_turn_29_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2188_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_16(moves, mr);
    board[tmp] = old2188_0;
}

void GameState::state_turn_29_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2189_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_17(moves, mr);
    tmp = old2189_0;
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
    mr.emplace_back(37);
    state_turn_29_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2196_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_23(moves, mr);
    board[tmp] = old2196_0;
}

void GameState::state_turn_29_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2197_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_24(moves, mr);
    tmp = old2197_0;
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
    state_turn_29_swapInLine_5(moves, mr);
}

void GameState::state_turn_29_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_29_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2204_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_30(moves, mr);
    board[tmp] = old2204_0;
}

void GameState::state_turn_29_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_29_swapInLine_end(moves, mr);
}

void GameState::state_turn_29_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2205_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_31(moves, mr);
    tmp = old2205_0;
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
    mr.emplace_back(37);
    state_turn_29_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_29_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2180_0 = board[tmp];
    board[tmp] = me;
    state_turn_29_swapInLine_9(moves, mr);
    board[tmp] = old2180_0;
}

void GameState::state_turn_29_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2181_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_29_swapInLine_10(moves, mr);
    tmp = old2181_0;
}

void GameState::state_turn_29_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2147_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_29_swapInLine_1(moves, mr);
    tmp = old2147_0;
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
    const auto old2287_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    state_turn_35__1(moves, mr);
    swapInLine_arg0_dir = old2287_0;
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
    mr.emplace_back(37);
    state_turn_32_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2259_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_16(moves, mr);
    board[tmp] = old2259_0;
}

void GameState::state_turn_32_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2260_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_17(moves, mr);
    tmp = old2260_0;
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
    mr.emplace_back(37);
    state_turn_32_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2267_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_23(moves, mr);
    board[tmp] = old2267_0;
}

void GameState::state_turn_32_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2268_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_24(moves, mr);
    tmp = old2268_0;
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
    state_turn_32_swapInLine_5(moves, mr);
}

void GameState::state_turn_32_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_32_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2275_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_30(moves, mr);
    board[tmp] = old2275_0;
}

void GameState::state_turn_32_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_32_swapInLine_end(moves, mr);
}

void GameState::state_turn_32_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2276_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_31(moves, mr);
    tmp = old2276_0;
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
    mr.emplace_back(37);
    state_turn_32_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_32_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2251_0 = board[tmp];
    board[tmp] = me;
    state_turn_32_swapInLine_9(moves, mr);
    board[tmp] = old2251_0;
}

void GameState::state_turn_32_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2252_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_32_swapInLine_10(moves, mr);
    tmp = old2252_0;
}

void GameState::state_turn_32_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2218_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_32_swapInLine_1(moves, mr);
    tmp = old2218_0;
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
    mr.emplace_back(37);
    state_turn_35_swapInLine_19(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2330_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_16(moves, mr);
    board[tmp] = old2330_0;
}

void GameState::state_turn_35_swapInLine_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2331_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_17(moves, mr);
    tmp = old2331_0;
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
    mr.emplace_back(37);
    state_turn_35_swapInLine_26(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2338_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_23(moves, mr);
    board[tmp] = old2338_0;
}

void GameState::state_turn_35_swapInLine_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2339_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_24(moves, mr);
    tmp = old2339_0;
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
    state_turn_35_swapInLine_5(moves, mr);
}

void GameState::state_turn_35_swapInLine_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(37);
    state_turn_35_swapInLine_33(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2346_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_30(moves, mr);
    board[tmp] = old2346_0;
}

void GameState::state_turn_35_swapInLine_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_35_swapInLine_end(moves, mr);
}

void GameState::state_turn_35_swapInLine_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2347_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_31(moves, mr);
    tmp = old2347_0;
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
    mr.emplace_back(37);
    state_turn_35_swapInLine_12(moves, mr);
    mr.pop_back();
}

void GameState::state_turn_35_swapInLine_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2322_0 = board[tmp];
    board[tmp] = me;
    state_turn_35_swapInLine_9(moves, mr);
    board[tmp] = old2322_0;
}

void GameState::state_turn_35_swapInLine_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2323_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    state_turn_35_swapInLine_10(moves, mr);
    tmp = old2323_0;
}

void GameState::state_turn_35_swapInLine_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2289_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    state_turn_35_swapInLine_1(moves, mr);
    tmp = old2289_0;
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
    const auto old2631_0 = tmp;
    tmp = V__0_0;
    state_turn_46(moves, mr);
    tmp = old2631_0;
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
    const auto old2635_0 = count[white - 2];
    count[white - 2] = count[white - 2]+1;
    state_turn_52(moves, mr);
    count[white - 2] = old2635_0;
}

void GameState::state_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old1526_0 = pos;
    for (pos = V__0_0; pos <= V__5_5; ++pos)
    {
    state_turn_6(moves, mr);    }
    pos = old1526_0;
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
    const auto old2642_0 = tmp;
    tmp = nextPos[tmp];
    state_turn_56(moves, mr);
    tmp = old2642_0;
}

void GameState::state_turn_52([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_51(moves, mr);
}

void GameState::state_turn_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2639_0 = count[black - 2];
    count[black - 2] = count[black - 2]+1;
    state_turn_55(moves, mr);
    count[black - 2] = old2639_0;
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
    mr.emplace_back(38);
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
    const auto old2650_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_turn_63(moves, mr);
    goals[white - 2] = old2650_0;
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
    const auto old2651_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_turn_64(moves, mr);
    goals[black - 2] = old2651_0;
}

void GameState::state_turn_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_62(moves, mr);
}

void GameState::state_turn_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2655_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_turn_67(moves, mr);
    goals[white - 2] = old2655_0;
}

void GameState::state_turn_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_62(moves, mr);
}

void GameState::state_turn_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old2656_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_turn_68(moves, mr);
    goals[black - 2] = old2656_0;
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
    const auto old1525_0 = player;
    player = me;
    currentState = 1004;
    return true;
    player = old1525_0;
    return false;
}

bool GameState::apply_state_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1789_0 = board[pos];
    board[pos] = me;
    if (apply_state_turn_11(mr,rgCache))
    {
        return true;
    }
    board[pos] = old1789_0;
    return false;
}

bool GameState::apply_state_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1790_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    if (apply_state_turn_14__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old1790_0;
    return false;
}

bool GameState::apply_state_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2359_0 = me;
    me = opponent[me - 2];
    if (apply_state_turn_37(mr,rgCache))
    {
        return true;
    }
    me = old2359_0;
    return false;
}

bool GameState::apply_state_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1861_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    if (apply_state_turn_17__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old1861_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1833_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1833_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1834_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old1834_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1841_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1841_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1842_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old1842_0;
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
    if (apply_state_turn_14_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1849_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1849_0;
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
    const auto old1850_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old1850_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1825_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_14_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1825_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1826_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_14_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old1826_0;
    return false;
}

bool GameState::apply_state_turn_14_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1792_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_14_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old1792_0;
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
    const auto old1932_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    if (apply_state_turn_20__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old1932_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1904_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1904_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1905_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old1905_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1912_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1912_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1913_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old1913_0;
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
    if (apply_state_turn_17_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1920_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1920_0;
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
    const auto old1921_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old1921_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1896_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_17_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1896_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1897_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_17_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old1897_0;
    return false;
}

bool GameState::apply_state_turn_17_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1863_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_17_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old1863_0;
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
    const auto old2003_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    if (apply_state_turn_23__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2003_0;
    return false;
}

bool GameState::apply_state_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2361_0 = me;
    me = opponent[me - 2];
    if (apply_state_turn_38(mr,rgCache))
    {
        return true;
    }
    me = old2361_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1975_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1975_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1976_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old1976_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1983_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1983_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1984_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old1984_0;
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
    if (apply_state_turn_20_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1991_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1991_0;
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
    const auto old1992_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old1992_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old1967_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_20_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old1967_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1968_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_20_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old1968_0;
    return false;
}

bool GameState::apply_state_turn_20_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1934_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_20_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old1934_0;
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
    const auto old2074_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    if (apply_state_turn_26__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2074_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2046_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2046_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2047_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2047_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2054_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2054_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2055_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2055_0;
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
    if (apply_state_turn_23_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2062_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2062_0;
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
    const auto old2063_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2063_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2038_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_23_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2038_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2039_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_23_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2039_0;
    return false;
}

bool GameState::apply_state_turn_23_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2005_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_23_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2005_0;
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
    const auto old2145_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    if (apply_state_turn_29__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2145_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2117_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2117_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2118_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2118_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2125_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2125_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2126_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2126_0;
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
    if (apply_state_turn_26_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2133_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2133_0;
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
    const auto old2134_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2134_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2109_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_26_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2109_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2110_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_26_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2110_0;
    return false;
}

bool GameState::apply_state_turn_26_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2076_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_26_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2076_0;
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
    const auto old2216_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    if (apply_state_turn_32__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2216_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2188_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2188_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2189_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2189_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2196_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2196_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2197_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2197_0;
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
    if (apply_state_turn_29_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2204_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2204_0;
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
    const auto old2205_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2205_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2180_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_29_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2180_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2181_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_29_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2181_0;
    return false;
}

bool GameState::apply_state_turn_29_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2147_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_29_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2147_0;
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
    const auto old2287_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    if (apply_state_turn_35__1(mr,rgCache))
    {
        return true;
    }
    swapInLine_arg0_dir = old2287_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2259_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2259_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2260_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2260_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2267_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2267_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2268_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2268_0;
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
    if (apply_state_turn_32_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2275_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2275_0;
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
    const auto old2276_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2276_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2251_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_32_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2251_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2252_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_32_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2252_0;
    return false;
}

bool GameState::apply_state_turn_32_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2218_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_32_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2218_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2330_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_16(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2330_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2331_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_17(mr,rgCache))
    {
        return true;
    }
    tmp = old2331_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2338_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_23(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2338_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2339_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_24(mr,rgCache))
    {
        return true;
    }
    tmp = old2339_0;
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
    if (apply_state_turn_35_swapInLine_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2346_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_30(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2346_0;
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
    const auto old2347_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_31(mr,rgCache))
    {
        return true;
    }
    tmp = old2347_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 37)
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
    const auto old2322_0 = board[tmp];
    board[tmp] = me;
    if (apply_state_turn_35_swapInLine_9(mr,rgCache))
    {
        return true;
    }
    board[tmp] = old2322_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2323_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_state_turn_35_swapInLine_10(mr,rgCache))
    {
        return true;
    }
    tmp = old2323_0;
    return false;
}

bool GameState::apply_state_turn_35_swapInLine_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2289_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_state_turn_35_swapInLine_1(mr,rgCache))
    {
        return true;
    }
    tmp = old2289_0;
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
    const auto old2627_0 = player;
    player = opponent[me - 2];
    currentState = 764;
    return true;
    player = old2627_0;
    return false;
}

bool GameState::apply_state_turn_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2630_0 = player;
    player = keeper;
    currentState = 766;
    return true;
    player = old2630_0;
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
    currentState = 765;
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
    const auto old2631_0 = tmp;
    tmp = V__0_0;
    if (apply_state_turn_46(mr,rgCache))
    {
        return true;
    }
    tmp = old2631_0;
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
    const auto old2635_0 = count[white - 2];
    count[white - 2] = count[white - 2]+1;
    if (apply_state_turn_52(mr,rgCache))
    {
        return true;
    }
    count[white - 2] = old2635_0;
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
    const auto old2642_0 = tmp;
    tmp = nextPos[tmp];
    if (apply_state_turn_56(mr,rgCache))
    {
        return true;
    }
    tmp = old2642_0;
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
    const auto old2639_0 = count[black - 2];
    count[black - 2] = count[black - 2]+1;
    if (apply_state_turn_55(mr,rgCache))
    {
        return true;
    }
    count[black - 2] = old2639_0;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 38)
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
    const auto old2650_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_turn_63(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old2650_0;
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
    const auto old2659_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old2659_0;
    return false;
}

bool GameState::apply_state_turn_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2651_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_turn_64(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old2651_0;
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
    const auto old2655_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_turn_67(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old2655_0;
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
    const auto old2656_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_turn_68(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old2656_0;
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
    const auto old1788_0 = player;
    player = keeper;
    currentState = 9;
    return true;
    player = old1788_0;
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
    currentState = 1004;
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
    currentState = 764;
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
    currentState = 766;
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
    const auto old316_0 = player;
    player = me;
    currentState = 1004;
    return true;
    if (apply_any_turn_10_turn_10_turn_5())
    {
        return true;
    }
    player = old316_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_10()
{
    const auto old317_0 = board[pos];
    board[pos] = me;
    if (apply_any_turn_10_turn_10_turn_11())
    {
        return true;
    }
    board[pos] = old317_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_11()
{
    const auto old318_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = up;
    if (apply_any_turn_10_turn_10_turn_14__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old318_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_12()
{
    const auto old655_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_10_turn_10_turn_37())
    {
        return true;
    }
    me = old655_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_13()
{
    const auto old360_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = down;
    if (apply_any_turn_10_turn_10_turn_17__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old360_0;
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
    const auto old332_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old332_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_16()
{
    const auto old333_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_17())
    {
        return true;
    }
    tmp = old333_0;
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
    const auto old340_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old340_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_23()
{
    const auto old341_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_24())
    {
        return true;
    }
    tmp = old341_0;
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
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_5())
    {
        return true;
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
    const auto old348_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old348_0;
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
    const auto old349_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_31())
    {
        return true;
    }
    tmp = old349_0;
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
    const auto old324_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old324_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_9()
{
    const auto old325_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_10())
    {
        return true;
    }
    tmp = old325_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_14_swapInLine_begin()
{
    const auto old320_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_14_swapInLine_1())
    {
        return true;
    }
    tmp = old320_0;
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
    const auto old402_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = left;
    if (apply_any_turn_10_turn_10_turn_20__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old402_0;
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
    const auto old374_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old374_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_16()
{
    const auto old375_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_17())
    {
        return true;
    }
    tmp = old375_0;
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
    const auto old382_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old382_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_23()
{
    const auto old383_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_24())
    {
        return true;
    }
    tmp = old383_0;
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
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_5())
    {
        return true;
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
    const auto old390_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old390_0;
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
    const auto old391_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_31())
    {
        return true;
    }
    tmp = old391_0;
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
    const auto old366_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old366_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_9()
{
    const auto old367_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_10())
    {
        return true;
    }
    tmp = old367_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_17_swapInLine_begin()
{
    const auto old362_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_17_swapInLine_1())
    {
        return true;
    }
    tmp = old362_0;
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
    const auto old444_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = right;
    if (apply_any_turn_10_turn_10_turn_23__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old444_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_2()
{
    const auto old657_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_10_turn_10_turn_38())
    {
        return true;
    }
    me = old657_0;
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
    const auto old416_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old416_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_16()
{
    const auto old417_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_17())
    {
        return true;
    }
    tmp = old417_0;
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
    const auto old424_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old424_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_23()
{
    const auto old425_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_24())
    {
        return true;
    }
    tmp = old425_0;
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
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_5())
    {
        return true;
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
    const auto old432_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old432_0;
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
    const auto old433_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_31())
    {
        return true;
    }
    tmp = old433_0;
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
    const auto old408_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old408_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_9()
{
    const auto old409_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_10())
    {
        return true;
    }
    tmp = old409_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_20_swapInLine_begin()
{
    const auto old404_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_20_swapInLine_1())
    {
        return true;
    }
    tmp = old404_0;
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
    const auto old486_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upLeft;
    if (apply_any_turn_10_turn_10_turn_26__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old486_0;
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
    const auto old458_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old458_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_16()
{
    const auto old459_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_17())
    {
        return true;
    }
    tmp = old459_0;
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
    const auto old466_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old466_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_23()
{
    const auto old467_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_24())
    {
        return true;
    }
    tmp = old467_0;
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
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_5())
    {
        return true;
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
    const auto old474_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old474_0;
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
    const auto old475_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_31())
    {
        return true;
    }
    tmp = old475_0;
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
    const auto old450_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old450_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_9()
{
    const auto old451_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_10())
    {
        return true;
    }
    tmp = old451_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_23_swapInLine_begin()
{
    const auto old446_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_23_swapInLine_1())
    {
        return true;
    }
    tmp = old446_0;
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
    const auto old528_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = upRight;
    if (apply_any_turn_10_turn_10_turn_29__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old528_0;
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
    const auto old500_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old500_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_16()
{
    const auto old501_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_17())
    {
        return true;
    }
    tmp = old501_0;
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
    const auto old508_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old508_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_23()
{
    const auto old509_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_24())
    {
        return true;
    }
    tmp = old509_0;
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
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_5())
    {
        return true;
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
    const auto old516_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old516_0;
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
    const auto old517_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_31())
    {
        return true;
    }
    tmp = old517_0;
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
    const auto old492_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old492_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_9()
{
    const auto old493_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_10())
    {
        return true;
    }
    tmp = old493_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_26_swapInLine_begin()
{
    const auto old488_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_26_swapInLine_1())
    {
        return true;
    }
    tmp = old488_0;
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
    const auto old570_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downLeft;
    if (apply_any_turn_10_turn_10_turn_32__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old570_0;
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
    const auto old542_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old542_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_16()
{
    const auto old543_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_17())
    {
        return true;
    }
    tmp = old543_0;
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
    const auto old550_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old550_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_23()
{
    const auto old551_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_24())
    {
        return true;
    }
    tmp = old551_0;
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
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_5())
    {
        return true;
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
    const auto old558_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old558_0;
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
    const auto old559_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_31())
    {
        return true;
    }
    tmp = old559_0;
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
    const auto old534_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old534_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_9()
{
    const auto old535_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_10())
    {
        return true;
    }
    tmp = old535_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_29_swapInLine_begin()
{
    const auto old530_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_29_swapInLine_1())
    {
        return true;
    }
    tmp = old530_0;
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
    const auto old612_0 = swapInLine_arg0_dir;
    swapInLine_arg0_dir = downRight;
    if (apply_any_turn_10_turn_10_turn_35__1())
    {
        return true;
    }
    swapInLine_arg0_dir = old612_0;
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
    const auto old584_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old584_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_16()
{
    const auto old585_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_17())
    {
        return true;
    }
    tmp = old585_0;
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
    const auto old592_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old592_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_23()
{
    const auto old593_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_24())
    {
        return true;
    }
    tmp = old593_0;
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
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_5())
    {
        return true;
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
    const auto old600_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old600_0;
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
    const auto old601_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_31())
    {
        return true;
    }
    tmp = old601_0;
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
    const auto old576_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old576_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_9()
{
    const auto old577_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_10())
    {
        return true;
    }
    tmp = old577_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_32_swapInLine_begin()
{
    const auto old572_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_32_swapInLine_1())
    {
        return true;
    }
    tmp = old572_0;
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
    const auto old626_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_16())
    {
        return true;
    }
    board[tmp] = old626_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_16()
{
    const auto old627_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_17())
    {
        return true;
    }
    tmp = old627_0;
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
    const auto old634_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_23())
    {
        return true;
    }
    board[tmp] = old634_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_23()
{
    const auto old635_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_24())
    {
        return true;
    }
    tmp = old635_0;
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
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_5())
    {
        return true;
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
    const auto old642_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_30())
    {
        return true;
    }
    board[tmp] = old642_0;
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
    const auto old643_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_31())
    {
        return true;
    }
    tmp = old643_0;
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
    const auto old618_0 = board[tmp];
    board[tmp] = me;
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_9())
    {
        return true;
    }
    board[tmp] = old618_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_9()
{
    const auto old619_0 = tmp;
    tmp = swapInLine_arg0_dir[tmp];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_10())
    {
        return true;
    }
    tmp = old619_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_35_swapInLine_begin()
{
    const auto old614_0 = tmp;
    tmp = swapInLine_arg0_dir[pos];
    if (apply_any_turn_10_turn_10_turn_35_swapInLine_1())
    {
        return true;
    }
    tmp = old614_0;
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
    const auto old660_0 = player;
    player = opponent[me - 2];
    currentState = 764;
    return true;
    if (apply_any_turn_10_turn_10_turn_43())
    {
        return true;
    }
    player = old660_0;
    return false;
}

bool GameState::apply_any_turn_10_turn_10_turn_40()
{
    const auto old661_0 = player;
    player = keeper;
    currentState = 766;
    return true;
    if (apply_any_turn_10_turn_10_turn_45())
    {
        return true;
    }
    player = old661_0;
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
    currentState = 1004;
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
    currentState = 764;
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
    currentState = 766;
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
