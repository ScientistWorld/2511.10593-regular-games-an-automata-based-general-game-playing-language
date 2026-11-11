#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.me) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.me) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && me==rhs.me && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_6: " << board[V__1_6] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__6_1: " << board[V__6_1] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_2: " << board[V__7_2] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_6: " << board[V__7_6] << ", " << "null: " << board[null]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "me = " << me << std::endl;
    ss << "goals = " << "{" << "red: " << goals[red-2] << ", " << "yellow: " << goals[yellow-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "red: " << visible[red-2] << ", " << "yellow: " << visible[yellow-2]<< "}" << std::endl;
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
        case 34:
{
            state_turn_1(moves, mr.mr);
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
        case 34:
{
            apply_state_turn_1(mr.mr,rgCache);
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
        case 46:
{
            apply_any_turn_5_turn_5_turn_5();
            break;
}
    }
}

bool GameState::is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_begin()
{
    const auto old6_0 = pos;
    for (pos = V__1_6; pos <= V__7_6; ++pos)
    {
    if (is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_1())
    {
        pos = old6_0;
        return true;
    }    }
    pos = old6_0;
    return false;
}

bool GameState::is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_call_1()
{
    if (is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_end()
{
    return true;
}

bool GameState::is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_1()
{
    if (board[pos]==empty)
    {
        if (is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_existsNonempty_call_1_existsNonempty_end_turn_15_existsNonempty_2()
{
    if (is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_1()
{
    if (is_legal_win_call_1_win_end_win_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_10()
{
    if (is_legal_win_call_1_win_end_turn_9_win_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_11()
{
    if (is_legal_win_call_1_win_end_turn_9_win_9())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_12()
{
    if (board[down[left[down[left[pos]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_13()
{
    if (board[down[left[down[left[down[left[pos]]]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_15())
        {
            return true;
        }
    }
    if (board[up[right[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_14()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_15()
{
    if (is_legal_win_call_1_win_end_turn_9_win_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_16()
{
    if (is_legal_win_call_1_win_end_turn_9_win_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_17()
{
    if (board[down[down[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_18())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_18()
{
    if (board[down[down[down[pos]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_19()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_2()
{
    if (board[up[left[up[left[pos]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_3())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_20()
{
    if (board[down[right[down[right[pos]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_21()
{
    if (board[down[right[down[right[down[right[pos]]]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_23())
        {
            return true;
        }
    }
    if (board[up[left[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_24())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_22()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_23()
{
    if (is_legal_win_call_1_win_end_turn_9_win_22())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_24()
{
    if (is_legal_win_call_1_win_end_turn_9_win_22())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_25()
{
    if (board[right[right[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_26())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_26()
{
    if (board[right[right[right[pos]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_28())
        {
            return true;
        }
    }
    if (board[left[pos]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_29())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_27()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_28()
{
    if (is_legal_win_call_1_win_end_turn_9_win_27())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_29()
{
    if (is_legal_win_call_1_win_end_turn_9_win_27())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_3()
{
    if (board[up[left[up[left[up[left[pos]]]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_5())
        {
            return true;
        }
    }
    if (board[down[right[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_30()
{
    if (board[up[right[up[right[pos]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_31())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_31()
{
    if (board[up[right[up[right[up[right[pos]]]]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_33())
        {
            return true;
        }
    }
    if (board[down[left[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_34())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_32()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_33()
{
    if (is_legal_win_call_1_win_end_turn_9_win_32())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_34()
{
    if (is_legal_win_call_1_win_end_turn_9_win_32())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_4()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_5()
{
    if (is_legal_win_call_1_win_end_turn_9_win_4())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_6()
{
    if (is_legal_win_call_1_win_end_turn_9_win_4())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_7()
{
    if (board[left[left[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_8())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_8()
{
    if (board[left[left[left[pos]]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_10())
        {
            return true;
        }
    }
    if (board[right[pos]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_11())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_turn_9_win_9()
{
    if (is_legal_win_call_1_win_end_turn_9_win_1())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_win_begin()
{
    if (board[up[left[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_2())
        {
            return true;
        }
    }
    if (board[left[pos]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_7())
        {
            return true;
        }
    }
    if (board[down[left[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_12())
        {
            return true;
        }
    }
    if (board[down[pos]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_17())
        {
            return true;
        }
    }
    if (board[down[right[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_20())
        {
            return true;
        }
    }
    if (board[right[pos]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_25())
        {
            return true;
        }
    }
    if (board[up[right[pos]]]==me)
    {
        if (is_legal_win_call_1_win_end_turn_9_win_30())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_win_call_1()
{
    if (is_legal_win_call_1_win_end_win_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_win_call_1_win_end_win_end()
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

void GameState::state_goDown_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[down[pos]]!=empty)
    {
        state_goDown_15(moves, mr);
        return;
    }
    state_goDown_16(moves, mr);
}

void GameState::state_goDown_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old110_0 = pos;
    pos = down[pos];
    state_goDown_13(moves, mr);
    pos = old110_0;
}

void GameState::state_goDown_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_10(moves, mr);
}

void GameState::state_goDown_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[down[pos]]!=empty)
    {
        state_goDown_19(moves, mr);
        return;
    }
    state_goDown_20(moves, mr);
}

void GameState::state_goDown_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old115_0 = pos;
    pos = down[pos];
    state_goDown_17(moves, mr);
    pos = old115_0;
}

void GameState::state_goDown_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_14(moves, mr);
}

void GameState::state_goDown_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_1(moves, mr);
}

void GameState::state_goDown_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[down[pos]]!=empty)
    {
        state_goDown_7(moves, mr);
        return;
    }
    state_goDown_8(moves, mr);
}

void GameState::state_goDown_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old120_0 = pos;
    pos = down[pos];
    state_goDown_21(moves, mr);
    pos = old120_0;
}

void GameState::state_goDown_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_18(moves, mr);
}

void GameState::state_goDown_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old100_0 = pos;
    pos = down[pos];
    state_goDown_5(moves, mr);
    pos = old100_0;
}

void GameState::state_goDown_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_2(moves, mr);
}

void GameState::state_goDown_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[down[pos]]!=empty)
    {
        state_goDown_11(moves, mr);
        return;
    }
    state_goDown_12(moves, mr);
}

void GameState::state_goDown_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_end(moves, mr);
}

void GameState::state_goDown_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old105_0 = pos;
    pos = down[pos];
    state_goDown_9(moves, mr);
    pos = old105_0;
}

void GameState::state_goDown_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_6(moves, mr);
}

void GameState::state_goDown_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[down[pos]]!=empty)
    {
        state_goDown_3(moves, mr);
        return;
    }
    state_goDown_4(moves, mr);
}

void GameState::state_goDown_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_6(moves, mr);
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
    const auto old92_0 = pos;
    for (pos = V__1_6; pos <= V__7_6; ++pos)
    {
    state_turn_2(moves, mr);    }
    pos = old92_0;
}

void GameState::state_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old176_0 = goals[opponent[me - 2] - 2];
    goals[opponent[me - 2] - 2] = 0;
    state_turn_11(moves, mr);
    goals[opponent[me - 2] - 2] = old176_0;
}

void GameState::state_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_call_1())
    {
        state_turn_13(moves, mr);
        return;
    }
    state_turn_14(moves, mr);
}

void GameState::state_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old186_0 = me;
    me = opponent[me - 2];
    state_turn_16(moves, mr);
    me = old186_0;
}

void GameState::state_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_turn_end(moves, mr);
}

void GameState::state_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_turn_3(moves, mr);
    }
}

void GameState::state_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_turn_4(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_goDown_begin(moves, mr);
}

void GameState::state_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_win_call_1_win_end_win_call_1())
    {
        state_turn_7(moves, mr);
        return;
    }
    state_turn_8(moves, mr);
}

void GameState::state_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old175_0 = goals[me - 2];
    goals[me - 2] = 100;
    state_turn_10(moves, mr);
    goals[me - 2] = old175_0;
}

void GameState::state_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old178_0 = board[pos];
    board[pos] = me;
    state_turn_12(moves, mr);
    board[pos] = old178_0;
}

void GameState::state_turn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_turn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3(moves, mr);
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    player = me;
    currentState = 34;
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

bool GameState::apply_state_goDown_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[down[pos]]!=empty)
    {
        if (apply_state_goDown_15(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_goDown_16(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = pos;
    pos = down[pos];
    if (apply_state_goDown_13(mr,rgCache))
    {
        return true;
    }
    pos = old110_0;
    return false;
}

bool GameState::apply_state_goDown_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[down[pos]]!=empty)
    {
        if (apply_state_goDown_19(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_goDown_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old115_0 = pos;
    pos = down[pos];
    if (apply_state_goDown_17(mr,rgCache))
    {
        return true;
    }
    pos = old115_0;
    return false;
}

bool GameState::apply_state_goDown_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_1(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[down[pos]]!=empty)
    {
        if (apply_state_goDown_7(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_goDown_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old120_0 = pos;
    pos = down[pos];
    if (apply_state_goDown_21(mr,rgCache))
    {
        return true;
    }
    pos = old120_0;
    return false;
}

bool GameState::apply_state_goDown_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_18(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = pos;
    pos = down[pos];
    if (apply_state_goDown_5(mr,rgCache))
    {
        return true;
    }
    pos = old100_0;
    return false;
}

bool GameState::apply_state_goDown_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[down[pos]]!=empty)
    {
        if (apply_state_goDown_11(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_goDown_12(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = pos;
    pos = down[pos];
    if (apply_state_goDown_9(mr,rgCache))
    {
        return true;
    }
    pos = old105_0;
    return false;
}

bool GameState::apply_state_goDown_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[down[pos]]!=empty)
    {
        if (apply_state_goDown_3(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_goDown_4(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_goDown_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_6(mr,rgCache))
    {
        return true;
    }
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

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 46;
            return true;
    }
    return false;
}

bool GameState::apply_state_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = goals[opponent[me - 2] - 2];
    goals[opponent[me - 2] - 2] = 0;
    if (apply_state_turn_11(mr,rgCache))
    {
        return true;
    }
    goals[opponent[me - 2] - 2] = old176_0;
    return false;
}

bool GameState::apply_state_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old177_0;
    return false;
}

bool GameState::apply_state_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_call_1())
    {
        if (apply_state_turn_13(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old185_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old185_0;
    return false;
}

bool GameState::apply_state_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old186_0 = me;
    me = opponent[me - 2];
    if (apply_state_turn_16(mr,rgCache))
    {
        return true;
    }
    me = old186_0;
    return false;
}

bool GameState::apply_state_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_turn_3(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_turn_4(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = player;
    player = keeper;
    currentState = 46;
    return true;
    player = old95_0;
    return false;
}

bool GameState::apply_state_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_goDown_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_win_call_1_win_end_win_call_1())
    {
        if (apply_state_turn_7(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_turn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = goals[me - 2];
    goals[me - 2] = 100;
    if (apply_state_turn_10(mr,rgCache))
    {
        return true;
    }
    goals[me - 2] = old175_0;
    return false;
}

bool GameState::apply_state_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = board[pos];
    board[pos] = me;
    if (apply_state_turn_12(mr,rgCache))
    {
        return true;
    }
    board[pos] = old178_0;
    return false;
}

bool GameState::apply_state_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old91_0 = player;
    player = me;
    currentState = 34;
    return true;
    player = old91_0;
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
    return true;
}

bool GameState::apply_any_begin_begin_turn_begin()
{
    const auto old8_0 = player;
    player = me;
    currentState = 34;
    return true;
    if (apply_any_begin_begin_turn_1())
    {
        return true;
    }
    player = old8_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_end()
{
    return true;
}

bool GameState::apply_any_turn_5_turn_5_goDown_1()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_10()
{
    if (board[down[pos]]!=empty)
    {
        if (apply_any_turn_5_turn_5_goDown_15())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_goDown_16())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_11()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_12()
{
    const auto old55_0 = pos;
    pos = down[pos];
    if (apply_any_turn_5_turn_5_goDown_13())
    {
        return true;
    }
    pos = old55_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_13()
{
    if (apply_any_turn_5_turn_5_goDown_10())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_14()
{
    if (board[down[pos]]!=empty)
    {
        if (apply_any_turn_5_turn_5_goDown_19())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_goDown_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_15()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_16()
{
    const auto old60_0 = pos;
    pos = down[pos];
    if (apply_any_turn_5_turn_5_goDown_17())
    {
        return true;
    }
    pos = old60_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_17()
{
    if (apply_any_turn_5_turn_5_goDown_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_18()
{
    if (apply_any_turn_5_turn_5_goDown_1())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_19()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_2()
{
    if (board[down[pos]]!=empty)
    {
        if (apply_any_turn_5_turn_5_goDown_7())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_goDown_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_20()
{
    const auto old65_0 = pos;
    pos = down[pos];
    if (apply_any_turn_5_turn_5_goDown_21())
    {
        return true;
    }
    pos = old65_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_21()
{
    if (apply_any_turn_5_turn_5_goDown_18())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_3()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_4()
{
    const auto old45_0 = pos;
    pos = down[pos];
    if (apply_any_turn_5_turn_5_goDown_5())
    {
        return true;
    }
    pos = old45_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_5()
{
    if (apply_any_turn_5_turn_5_goDown_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_6()
{
    if (board[down[pos]]!=empty)
    {
        if (apply_any_turn_5_turn_5_goDown_11())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_goDown_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_7()
{
    if (apply_any_turn_5_turn_5_goDown_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_8()
{
    const auto old50_0 = pos;
    pos = down[pos];
    if (apply_any_turn_5_turn_5_goDown_9())
    {
        return true;
    }
    pos = old50_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_9()
{
    if (apply_any_turn_5_turn_5_goDown_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_begin()
{
    if (board[down[pos]]!=empty)
    {
        if (apply_any_turn_5_turn_5_goDown_3())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_goDown_4())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_goDown_end()
{
    if (apply_any_turn_5_turn_5_turn_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_rules_1()
{
    if (apply_any_turn_5_turn_5_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_rules_3()
{
    if (apply_any_turn_5_turn_5_rules_1())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_1()
{
    return true;
}

bool GameState::apply_any_turn_5_turn_5_turn_10()
{
    const auto old73_0 = goals[opponent[me - 2] - 2];
    goals[opponent[me - 2] - 2] = 0;
    if (apply_any_turn_5_turn_5_turn_11())
    {
        return true;
    }
    goals[opponent[me - 2] - 2] = old73_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_11()
{
    const auto old74_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_turn_5_turn_5_end())
    {
        return true;
    }
    player = old74_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_12()
{
    if (!is_legal_existsNonempty_call_1_existsNonempty_end_existsNonempty_call_1())
    {
        if (apply_any_turn_5_turn_5_turn_13())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_turn_14())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_13()
{
    const auto old78_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_turn_5_turn_5_end())
    {
        return true;
    }
    player = old78_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_14()
{
    const auto old79_0 = me;
    me = opponent[me - 2];
    if (apply_any_turn_5_turn_5_turn_16())
    {
        return true;
    }
    me = old79_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_16()
{
    if (apply_any_turn_5_turn_5_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_5()
{
    if (apply_any_turn_5_turn_5_goDown_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_6()
{
    if (is_legal_win_call_1_win_end_win_call_1())
    {
        if (apply_any_turn_5_turn_5_turn_7())
        {
            return true;
        }
        return false;
    }
    if (apply_any_turn_5_turn_5_turn_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_7()
{
    const auto old72_0 = goals[me - 2];
    goals[me - 2] = 100;
    if (apply_any_turn_5_turn_5_turn_10())
    {
        return true;
    }
    goals[me - 2] = old72_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_8()
{
    const auto old75_0 = board[pos];
    board[pos] = me;
    if (apply_any_turn_5_turn_5_turn_12())
    {
        return true;
    }
    board[pos] = old75_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_begin()
{
    const auto old40_0 = player;
    player = me;
    currentState = 34;
    return true;
    if (apply_any_turn_5_turn_5_turn_1())
    {
        return true;
    }
    player = old40_0;
    return false;
}

bool GameState::apply_any_turn_5_turn_5_turn_end()
{
    if (apply_any_turn_5_turn_5_rules_3())
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
