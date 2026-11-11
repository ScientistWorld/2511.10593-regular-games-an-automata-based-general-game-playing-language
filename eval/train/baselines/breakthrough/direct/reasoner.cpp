#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.existsOppPawn_arg0_me) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.turn_arg0_me) ^ hash(gameState.existsOppPawn_arg0_me) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && turn_arg0_me==rhs.turn_arg0_me && existsOppPawn_arg0_me==rhs.existsOppPawn_arg0_me && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__0_0: " << board[V__0_0] << ", " << "V__0_1: " << board[V__0_1] << ", " << "V__0_2: " << board[V__0_2] << ", " << "V__0_3: " << board[V__0_3] << ", " << "V__0_4: " << board[V__0_4] << ", " << "V__0_5: " << board[V__0_5] << ", " << "V__0_6: " << board[V__0_6] << ", " << "V__0_7: " << board[V__0_7] << ", " << "V__1_0: " << board[V__1_0] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_2: " << board[V__1_2] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_4: " << board[V__1_4] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_6: " << board[V__1_6] << ", " << "V__1_7: " << board[V__1_7] << ", " << "V__2_0: " << board[V__2_0] << ", " << "V__2_1: " << board[V__2_1] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_3: " << board[V__2_3] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_5: " << board[V__2_5] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__2_7: " << board[V__2_7] << ", " << "V__3_0: " << board[V__3_0] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_2: " << board[V__3_2] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_4: " << board[V__3_4] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_6: " << board[V__3_6] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__4_0: " << board[V__4_0] << ", " << "V__4_1: " << board[V__4_1] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_3: " << board[V__4_3] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_5: " << board[V__4_5] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__4_7: " << board[V__4_7] << ", " << "V__5_0: " << board[V__5_0] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_2: " << board[V__5_2] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_4: " << board[V__5_4] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_6: " << board[V__5_6] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__6_0: " << board[V__6_0] << ", " << "V__6_1: " << board[V__6_1] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_3: " << board[V__6_3] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_5: " << board[V__6_5] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__6_7: " << board[V__6_7] << ", " << "V__7_0: " << board[V__7_0] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_2: " << board[V__7_2] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_4: " << board[V__7_4] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_6: " << board[V__7_6] << ", " << "V__7_7: " << board[V__7_7]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "turn_arg0_me = " << turn_arg0_me << std::endl;
    ss << "existsOppPawn_arg0_me = " << existsOppPawn_arg0_me << std::endl;
    ss << "goals = " << "{" << "black: " << goals[black-2] << ", " << "white: " << goals[white-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "black: " << visible[black-2] << ", " << "white: " << visible[white-2]<< "}" << std::endl;
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
        case 6:
{
            state_rules_3_turn_1(moves, mr.mr);
            return;
}
        case 38:
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
        case 6:
{
            apply_state_rules_3_turn_1(mr.mr,rgCache);
            return;
}
        case 38:
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
        case 14:
{
            apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_17();
            break;
}
        case 46:
{
            apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_17();
            break;
}
    }
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_1()
{
    const auto old6_0 = existsOppPawn_arg0_me;
    existsOppPawn_arg0_me = turn_arg0_me;
    if (is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_2())
    {
        existsOppPawn_arg0_me = old6_0;
        return true;
    }
    existsOppPawn_arg0_me = old6_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_2()
{
    if (is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_1()
{
    if (board[pos]==piece[opponent[existsOppPawn_arg0_me - 2] - 2])
    {
        if (is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_2()
{
    if (is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_begin()
{
    const auto old8_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_1())
    {
        pos = old8_0;
        return true;
    }    }
    pos = old8_0;
    return false;
}

bool GameState::is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_existsOppPawn_end()
{
    return true;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_1()
{
    const auto old6_0 = existsOppPawn_arg0_me;
    existsOppPawn_arg0_me = turn_arg0_me;
    if (is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_2())
    {
        existsOppPawn_arg0_me = old6_0;
        return true;
    }
    existsOppPawn_arg0_me = old6_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_2()
{
    if (is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_1()
{
    if (board[pos]==piece[opponent[existsOppPawn_arg0_me - 2] - 2])
    {
        if (is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_2()
{
    if (is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_begin()
{
    const auto old8_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_1())
    {
        pos = old8_0;
        return true;
    }    }
    pos = old8_0;
    return false;
}

bool GameState::is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_existsOppPawn_end()
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
    const auto old72_0 = turn_arg0_me;
    turn_arg0_me = white;
    state_rules_3__1(moves, mr);
    turn_arg0_me = old72_0;
}

void GameState::state_rules_3__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_begin(moves, mr);
}

void GameState::state_rules_3_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old75_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    state_rules_3_turn_2(moves, mr);    }
    pos = old75_0;
}

void GameState::state_rules_3_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_3_turn_15(moves, mr);
        return;
    }
    if (board[pos]==piece[opponent[turn_arg0_me - 2] - 2])
    {
        state_rules_3_turn_15(moves, mr);
        return;
    }
}

void GameState::state_rules_3_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 66;
    state_rules_3_turn_12(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_3_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_10(moves, mr);
}

void GameState::state_rules_3_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 67;
    state_rules_3_turn_14(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_3_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_10(moves, mr);
}

void GameState::state_rules_3_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_6(moves, mr);
}

void GameState::state_rules_3_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old94_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    state_rules_3_turn_18(moves, mr);
    board[pos] = old94_0;
}

void GameState::state_rules_3_turn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        state_rules_3_turn_19(moves, mr);
        return;
    }
    state_rules_3_turn_21(moves, mr);
}

void GameState::state_rules_3_turn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old104_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_3_turn_23(moves, mr);
    goals[turn_arg0_me - 2] = old104_0;
}

void GameState::state_rules_3_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==piece[turn_arg0_me - 2])
    {
        state_rules_3_turn_3(moves, mr);
    }
}

void GameState::state_rules_3_turn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_end(moves, mr);
}

void GameState::state_rules_3_turn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_1())
    {
        state_rules_3_turn_19(moves, mr);
        return;
    }
    state_rules_3_turn_20(moves, mr);
}

void GameState::state_rules_3_turn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_3_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old77_0 = board[pos];
    board[pos] = empty;
    state_rules_3_turn_4(moves, mr);
    board[pos] = old77_0;
}

void GameState::state_rules_3_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_rules_3_turn_5(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_rules_3_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old79_0 = pos;
    pos = directionF[turn_arg0_me - 2][pos];
    state_rules_3_turn_7(moves, mr);
    pos = old79_0;
    const auto old83_0 = pos;
    pos = directionFL[turn_arg0_me - 2][pos];
    state_rules_3_turn_11(moves, mr);
    pos = old83_0;
    const auto old86_0 = pos;
    pos = directionFR[turn_arg0_me - 2][pos];
    state_rules_3_turn_13(moves, mr);
    pos = old86_0;
}

void GameState::state_rules_3_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[2] = 0 + pos;
    state_rules_3_turn_16(moves, mr);
    mr[2] = unusedTag;
}

void GameState::state_rules_3_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 65;
    state_rules_3_turn_8(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_3_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_3_turn_9(moves, mr);
    }
}

void GameState::state_rules_3_turn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3_turn_6(moves, mr);
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
    const auto old108_0 = turn_arg0_me;
    turn_arg0_me = black;
    state_rules_5__1(moves, mr);
    turn_arg0_me = old108_0;
}

void GameState::state_rules_5__1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_begin(moves, mr);
}

void GameState::state_rules_5_turn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old111_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    state_rules_5_turn_2(moves, mr);    }
    pos = old111_0;
}

void GameState::state_rules_5_turn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_5_turn_15(moves, mr);
        return;
    }
    if (board[pos]==piece[opponent[turn_arg0_me - 2] - 2])
    {
        state_rules_5_turn_15(moves, mr);
        return;
    }
}

void GameState::state_rules_5_turn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 66;
    state_rules_5_turn_12(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_5_turn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_10(moves, mr);
}

void GameState::state_rules_5_turn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 67;
    state_rules_5_turn_14(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_5_turn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_10(moves, mr);
}

void GameState::state_rules_5_turn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_6(moves, mr);
}

void GameState::state_rules_5_turn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old130_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    state_rules_5_turn_18(moves, mr);
    board[pos] = old130_0;
}

void GameState::state_rules_5_turn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        state_rules_5_turn_19(moves, mr);
        return;
    }
    state_rules_5_turn_21(moves, mr);
}

void GameState::state_rules_5_turn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old140_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    state_rules_5_turn_23(moves, mr);
    goals[turn_arg0_me - 2] = old140_0;
}

void GameState::state_rules_5_turn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==piece[turn_arg0_me - 2])
    {
        state_rules_5_turn_3(moves, mr);
    }
}

void GameState::state_rules_5_turn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_end(moves, mr);
}

void GameState::state_rules_5_turn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_1())
    {
        state_rules_5_turn_19(moves, mr);
        return;
    }
    state_rules_5_turn_20(moves, mr);
}

void GameState::state_rules_5_turn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5_turn_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old113_0 = board[pos];
    board[pos] = empty;
    state_rules_5_turn_4(moves, mr);
    board[pos] = old113_0;
}

void GameState::state_rules_5_turn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_rules_5_turn_5(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_rules_5_turn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old115_0 = pos;
    pos = directionF[turn_arg0_me - 2][pos];
    state_rules_5_turn_7(moves, mr);
    pos = old115_0;
    const auto old119_0 = pos;
    pos = directionFL[turn_arg0_me - 2][pos];
    state_rules_5_turn_11(moves, mr);
    pos = old119_0;
    const auto old122_0 = pos;
    pos = directionFR[turn_arg0_me - 2][pos];
    state_rules_5_turn_13(moves, mr);
    pos = old122_0;
}

void GameState::state_rules_5_turn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[2] = 0 + pos;
    state_rules_5_turn_16(moves, mr);
    mr[2] = unusedTag;
}

void GameState::state_rules_5_turn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 65;
    state_rules_5_turn_8(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_rules_5_turn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_rules_5_turn_9(moves, mr);
    }
}

void GameState::state_rules_5_turn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_5_turn_6(moves, mr);
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
    player = turn_arg0_me;
    currentState = 6;
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
    const auto old72_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_state_rules_3__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old72_0;
    return false;
}

bool GameState::apply_state_rules_3__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
            board[pos] = empty;
            return apply_state_rules_3_turn_5(mr,rgCache);
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
    if (board[pos]==empty)
    {
        if (apply_state_rules_3_turn_15(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[pos]==piece[opponent[turn_arg0_me - 2] - 2])
    {
        if (apply_state_rules_3_turn_15(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 66)
    {
        if (apply_state_rules_3_turn_12(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 67)
    {
        if (apply_state_rules_3_turn_14(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old93_0 = player;
    player = keeper;
    currentState = 14;
    return true;
    player = old93_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    if (apply_state_rules_3_turn_18(mr,rgCache))
    {
        return true;
    }
    board[pos] = old94_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        if (apply_state_rules_3_turn_19(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_rules_3_turn_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_3_turn_23(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old104_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==piece[turn_arg0_me - 2])
    {
        if (apply_state_rules_3_turn_3(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_1())
    {
        if (apply_state_rules_3_turn_19(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_3_turn_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old105_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old77_0 = board[pos];
    board[pos] = empty;
    if (apply_state_rules_3_turn_4(mr,rgCache))
    {
        return true;
    }
    board[pos] = old77_0;
    return false;
}

bool GameState::apply_state_rules_3_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_rules_3_turn_5(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        case 65:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionF[turn_arg0_me - 2][pos];
                    player = keeper;
                    currentState = 14;
                    return true;
            }
            break;
}
        case 66:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionFL[turn_arg0_me - 2][pos];
                    pos = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 14;
                    return true;
            }
            break;
}
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionFR[turn_arg0_me - 2][pos];
                    pos = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 14;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_3_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[2] == 0 + pos)
    {
        if (apply_state_rules_3_turn_16(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 65)
    {
        if (apply_state_rules_3_turn_8(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_rules_3_turn_9(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3_turn_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old74_0 = player;
    player = turn_arg0_me;
    currentState = 6;
    return true;
    player = old74_0;
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
    const auto old108_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_state_rules_5__1(mr,rgCache))
    {
        return true;
    }
    turn_arg0_me = old108_0;
    return false;
}

bool GameState::apply_state_rules_5__1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            board[pos] = empty;
            return apply_state_rules_5_turn_5(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_5_turn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_rules_5_turn_15(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[pos]==piece[opponent[turn_arg0_me - 2] - 2])
    {
        if (apply_state_rules_5_turn_15(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 66)
    {
        if (apply_state_rules_5_turn_12(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 67)
    {
        if (apply_state_rules_5_turn_14(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old129_0 = player;
    player = keeper;
    currentState = 46;
    return true;
    player = old129_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    if (apply_state_rules_5_turn_18(mr,rgCache))
    {
        return true;
    }
    board[pos] = old130_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        if (apply_state_rules_5_turn_19(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_rules_5_turn_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old140_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_state_rules_5_turn_23(mr,rgCache))
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old140_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==piece[turn_arg0_me - 2])
    {
        if (apply_state_rules_5_turn_3(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_1())
    {
        if (apply_state_rules_5_turn_19(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_rules_5_turn_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old141_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old141_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old113_0 = board[pos];
    board[pos] = empty;
    if (apply_state_rules_5_turn_4(mr,rgCache))
    {
        return true;
    }
    board[pos] = old113_0;
    return false;
}

bool GameState::apply_state_rules_5_turn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_rules_5_turn_5(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        case 65:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionF[turn_arg0_me - 2][pos];
                    player = keeper;
                    currentState = 46;
                    return true;
            }
            break;
}
        case 66:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionFL[turn_arg0_me - 2][pos];
                    pos = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 46;
                    return true;
            }
            break;
}
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = directionFR[turn_arg0_me - 2][pos];
                    pos = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 46;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_4(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_5_turn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[2] == 0 + pos)
    {
        if (apply_state_rules_5_turn_16(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 65)
    {
        if (apply_state_rules_5_turn_8(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_rules_5_turn_9(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_5_turn_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_5_turn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = player;
    player = turn_arg0_me;
    currentState = 38;
    return true;
    player = old110_0;
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
    const auto old8_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_begin_begin_rules_3__1())
    {
        return true;
    }
    turn_arg0_me = old8_0;
    return false;
}

bool GameState::apply_any_begin_begin_rules_3__1()
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
    const auto old10_0 = player;
    player = turn_arg0_me;
    currentState = 6;
    return true;
    if (apply_any_begin_begin_rules_3_turn_1())
    {
        return true;
    }
    player = old10_0;
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

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_end()
{
    return true;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_17()
{
    const auto old12_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_18())
    {
        return true;
    }
    board[pos] = old12_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_18()
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_19())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_19()
{
    const auto old17_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_23())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old17_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_20()
{
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_21()
{
    if (!is_legal_rules_3_turn_22_1_rules_3_turn_22_existsOppPawn_end_rules_3_turn_22_1())
    {
        if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_19())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_23()
{
    const auto old18_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_3_turn_17_rules_3_turn_17_end())
    {
        return true;
    }
    player = old18_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_3_turn_end()
{
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_4())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_4()
{
    const auto old21_0 = turn_arg0_me;
    turn_arg0_me = black;
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_5__1())
    {
        return true;
    }
    turn_arg0_me = old21_0;
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_5__1()
{
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_1()
{
    return true;
}

bool GameState::apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_begin()
{
    const auto old23_0 = player;
    player = turn_arg0_me;
    currentState = 38;
    return true;
    if (apply_any_rules_3_turn_17_rules_3_turn_17_rules_5_turn_1())
    {
        return true;
    }
    player = old23_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_end()
{
    return true;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_1()
{
    const auto old13_0 = turn_arg0_me;
    turn_arg0_me = white;
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_3__1())
    {
        return true;
    }
    turn_arg0_me = old13_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_3__1()
{
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_1()
{
    return true;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_begin()
{
    const auto old15_0 = player;
    player = turn_arg0_me;
    currentState = 6;
    return true;
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_3_turn_1())
    {
        return true;
    }
    player = old15_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_17()
{
    const auto old16_0 = board[pos];
    board[pos] = piece[turn_arg0_me - 2];
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_18())
    {
        return true;
    }
    board[pos] = old16_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_18()
{
    if (directionF[turn_arg0_me - 2][pos]==pos)
    {
        if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_19())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_19()
{
    const auto old21_0 = goals[turn_arg0_me - 2];
    goals[turn_arg0_me - 2] = 100;
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_23())
    {
        return true;
    }
    goals[turn_arg0_me - 2] = old21_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_20()
{
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_21()
{
    if (!is_legal_rules_5_turn_22_1_rules_5_turn_22_existsOppPawn_end_rules_5_turn_22_1())
    {
        if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_19())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_20())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_23()
{
    const auto old22_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_turn_17_rules_5_turn_17_end())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_5_turn_end()
{
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_turn_17_rules_5_turn_17_rules_6()
{
    if (apply_any_rules_5_turn_17_rules_5_turn_17_rules_1())
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
