#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.foxPos) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.pos) ^ hash(gameState.foxPos) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && pos==rhs.pos && foxPos==rhs.foxPos && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "V__0_0: " << board[V__0_0] << ", " << "V__0_2: " << board[V__0_2] << ", " << "V__0_4: " << board[V__0_4] << ", " << "V__0_6: " << board[V__0_6] << ", " << "V__2_0: " << board[V__2_0] << ", " << "V__2_2: " << board[V__2_2] << ", " << "V__2_4: " << board[V__2_4] << ", " << "V__2_6: " << board[V__2_6] << ", " << "V__4_0: " << board[V__4_0] << ", " << "V__4_2: " << board[V__4_2] << ", " << "V__4_4: " << board[V__4_4] << ", " << "V__4_6: " << board[V__4_6] << ", " << "V__6_0: " << board[V__6_0] << ", " << "V__6_2: " << board[V__6_2] << ", " << "V__6_4: " << board[V__6_4] << ", " << "V__6_6: " << board[V__6_6] << ", " << "V__1_1: " << board[V__1_1] << ", " << "V__1_3: " << board[V__1_3] << ", " << "V__1_5: " << board[V__1_5] << ", " << "V__1_7: " << board[V__1_7] << ", " << "V__3_1: " << board[V__3_1] << ", " << "V__3_3: " << board[V__3_3] << ", " << "V__3_5: " << board[V__3_5] << ", " << "V__3_7: " << board[V__3_7] << ", " << "V__5_1: " << board[V__5_1] << ", " << "V__5_3: " << board[V__5_3] << ", " << "V__5_5: " << board[V__5_5] << ", " << "V__5_7: " << board[V__5_7] << ", " << "V__7_1: " << board[V__7_1] << ", " << "V__7_3: " << board[V__7_3] << ", " << "V__7_5: " << board[V__7_5] << ", " << "V__7_7: " << board[V__7_7]<< "}" << std::endl;
    ss << "pos = " << pos << std::endl;
    ss << "foxPos = " << foxPos << std::endl;
    ss << "goals = " << "{" << "foxPlayer: " << goals[foxPlayer-2] << ", " << "houndPlayer: " << goals[houndPlayer-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "foxPlayer: " << visible[foxPlayer-2] << ", " << "houndPlayer: " << visible[houndPlayer-2]<< "}" << std::endl;
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
        case 67:
{
            state_rules_1(moves, mr.mr);
            return;
}
        case 34:
{
            state_foxTurn_7(moves, mr.mr);
            return;
}
        case 57:
{
            state_houndTurn_5(moves, mr.mr);
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
        case 67:
{
            apply_state_rules_1(mr.mr,rgCache);
            return;
}
        case 34:
{
            apply_state_foxTurn_7(mr.mr,rgCache);
            return;
}
        case 57:
{
            apply_state_houndTurn_5(mr.mr,rgCache);
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
        case 16:
{
            apply_any_foxTurn_19_foxTurn_19_foxTurn_19();
            break;
}
        case 47:
{
            apply_any_houndTurn_17_houndTurn_17_houndTurn_17();
            break;
}
        case 73:
{
            apply_any_rules_5_rules_5_rules_5();
            break;
}
    }
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_begin()
{
    const auto old12_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_1())
    {
        pos = old12_0;
        return true;
    }    }
    pos = old12_0;
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_end()
{
    return true;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_1()
{
    if (board[pos]==fox)
    {
        if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_2()
{
    const auto old14_0 = pos;
    pos = upLeft[pos];
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_4())
    {
        pos = old14_0;
        return true;
    }
    pos = old14_0;
    const auto old16_0 = pos;
    pos = upRight[pos];
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_5())
    {
        pos = old16_0;
        return true;
    }
    pos = old16_0;
    const auto old18_0 = pos;
    pos = downLeft[pos];
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_6())
    {
        pos = old18_0;
        return true;
    }
    pos = old18_0;
    const auto old20_0 = pos;
    pos = downRight[pos];
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_7())
    {
        pos = old20_0;
        return true;
    }
    pos = old20_0;
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3()
{
    if (board[pos]==empty)
    {
        if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_8())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_4()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_5()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_6()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_7()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_foxHasMove_call_1_foxHasMove_end_foxTurn_3_foxHasMove_8()
{
    if (is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_1()
{
    if (board[pos]==hound)
    {
        if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_2())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_2()
{
    const auto old12_0 = pos;
    pos = upLeft[pos];
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_4())
    {
        pos = old12_0;
        return true;
    }
    pos = old12_0;
    const auto old14_0 = pos;
    pos = upRight[pos];
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_5())
    {
        pos = old14_0;
        return true;
    }
    pos = old14_0;
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_3()
{
    if (board[pos]==empty)
    {
        if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_6())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_4()
{
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_5()
{
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_6()
{
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_end())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_begin()
{
    const auto old10_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndTurn_3_houndsHaveMove_1())
    {
        pos = old10_0;
        return true;
    }    }
    pos = old10_0;
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_call_1()
{
    if (is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_begin())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_end()
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

void GameState::state_foxTurn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old104_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    state_foxTurn_4(moves, mr);
    goals[houndPlayer - 2] = old104_0;
}

void GameState::state_foxTurn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_8(moves, mr);
}

void GameState::state_foxTurn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old113_0 = pos;
    pos = upRight[pos];
    state_foxTurn_12(moves, mr);
    pos = old113_0;
}

void GameState::state_foxTurn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_8(moves, mr);
}

void GameState::state_foxTurn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old116_0 = pos;
    pos = downLeft[pos];
    state_foxTurn_14(moves, mr);
    pos = old116_0;
}

void GameState::state_foxTurn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_8(moves, mr);
}

void GameState::state_foxTurn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old119_0 = pos;
    pos = downRight[pos];
    state_foxTurn_16(moves, mr);
    pos = old119_0;
}

void GameState::state_foxTurn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_8(moves, mr);
}

void GameState::state_foxTurn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 0 + pos;
    state_foxTurn_18(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_foxTurn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_foxTurn_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (bottomLine[pos]==1)
    {
        state_foxTurn_20(moves, mr);
        return;
    }
    state_foxTurn_21(moves, mr);
}

void GameState::state_foxTurn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old106_0 = pos;
    pos = foxPos;
    state_foxTurn_5(moves, mr);
    pos = old106_0;
}

void GameState::state_foxTurn_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old126_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    state_foxTurn_22(moves, mr);
    goals[foxPlayer - 2] = old126_0;
}

void GameState::state_foxTurn_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old128_0 = foxPos;
    foxPos = pos;
    state_foxTurn_23(moves, mr);
    foxPos = old128_0;
}

void GameState::state_foxTurn_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_foxTurn_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old129_0 = board[pos];
    board[pos] = fox;
    state_foxTurn_24(moves, mr);
    board[pos] = old129_0;
}

void GameState::state_foxTurn_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_end(moves, mr);
}

void GameState::state_foxTurn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_foxTurn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old107_0 = board[pos];
    board[pos] = empty;
    state_foxTurn_6(moves, mr);
    board[pos] = old107_0;
}

void GameState::state_foxTurn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_foxTurn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 33;
    state_foxTurn_9(moves, mr);
    mr[0] = unusedTag;
    mr[0] = 34;
    state_foxTurn_11(moves, mr);
    mr[0] = unusedTag;
    mr[0] = 35;
    state_foxTurn_13(moves, mr);
    mr[0] = unusedTag;
    mr[0] = 36;
    state_foxTurn_15(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_foxTurn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_foxTurn_17(moves, mr);
    }
}

void GameState::state_foxTurn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old110_0 = pos;
    pos = upLeft[pos];
    state_foxTurn_10(moves, mr);
    pos = old110_0;
}

void GameState::state_foxTurn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1())
    {
        state_foxTurn_1(moves, mr);
        return;
    }
    state_foxTurn_2(moves, mr);
}

void GameState::state_foxTurn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_10(moves, mr);
}

void GameState::state_houndTurn_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old144_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    state_houndTurn_4(moves, mr);
    goals[foxPlayer - 2] = old144_0;
}

void GameState::state_houndTurn_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==empty)
    {
        state_houndTurn_15(moves, mr);
    }
}

void GameState::state_houndTurn_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old152_0 = pos;
    pos = upLeft[pos];
    state_houndTurn_12(moves, mr);
    pos = old152_0;
}

void GameState::state_houndTurn_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_houndTurn_10(moves, mr);
}

void GameState::state_houndTurn_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old155_0 = pos;
    pos = upRight[pos];
    state_houndTurn_14(moves, mr);
    pos = old155_0;
}

void GameState::state_houndTurn_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_houndTurn_10(moves, mr);
}

void GameState::state_houndTurn_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[2] = 0 + pos;
    state_houndTurn_16(moves, mr);
    mr[2] = unusedTag;
}

void GameState::state_houndTurn_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_houndTurn_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old160_0 = board[pos];
    board[pos] = hound;
    state_houndTurn_18(moves, mr);
    board[pos] = old160_0;
}

void GameState::state_houndTurn_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_houndTurn_end(moves, mr);
}

void GameState::state_houndTurn_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_houndTurn_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_houndTurn_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old147_0 = pos;
    for (pos = V__0_0; pos <= V__7_7; ++pos)
    {
    state_houndTurn_6(moves, mr);    }
    pos = old147_0;
}

void GameState::state_houndTurn_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[pos]==hound)
    {
        state_houndTurn_7(moves, mr);
    }
}

void GameState::state_houndTurn_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_houndTurn_8(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_houndTurn_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old150_0 = board[pos];
    board[pos] = empty;
    state_houndTurn_9(moves, mr);
    board[pos] = old150_0;
}

void GameState::state_houndTurn_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 33;
    state_houndTurn_11(moves, mr);
    mr[1] = unusedTag;
    mr[1] = 34;
    state_houndTurn_13(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_houndTurn_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_call_1())
    {
        state_houndTurn_1(moves, mr);
        return;
    }
    state_houndTurn_2(moves, mr);
}

void GameState::state_houndTurn_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_11(moves, mr);
}

void GameState::state_rules_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old81_0 = pos;
    for (const auto& posIt : topLineiter)
    {
    pos = posIt;
    state_rules_2(moves, mr);    }
    pos = old81_0;
}

void GameState::state_rules_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_houndTurn_begin(moves, mr);
}

void GameState::state_rules_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_8(moves, mr);
}

void GameState::state_rules_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_3(moves, mr);
}

void GameState::state_rules_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + pos;
    state_rules_4(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_rules_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_rules_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old85_0 = foxPos;
    foxPos = pos;
    state_rules_6(moves, mr);
    foxPos = old85_0;
}

void GameState::state_rules_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old86_0 = board[pos];
    board[pos] = fox;
    state_rules_7(moves, mr);
    board[pos] = old86_0;
}

void GameState::state_rules_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_rules_8(moves, mr);
}

void GameState::state_rules_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_foxTurn_begin(moves, mr);
}

void GameState::state_rules_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    player = foxPlayer;
    currentState = 67;
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

bool GameState::apply_state_foxTurn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_state_foxTurn_4(mr,rgCache))
    {
        return true;
    }
    goals[houndPlayer - 2] = old104_0;
    return false;
}

bool GameState::apply_state_foxTurn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old113_0 = pos;
    pos = upRight[pos];
    if (apply_state_foxTurn_12(mr,rgCache))
    {
        return true;
    }
    pos = old113_0;
    return false;
}

bool GameState::apply_state_foxTurn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old116_0 = pos;
    pos = downLeft[pos];
    if (apply_state_foxTurn_14(mr,rgCache))
    {
        return true;
    }
    pos = old116_0;
    return false;
}

bool GameState::apply_state_foxTurn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old119_0 = pos;
    pos = downRight[pos];
    if (apply_state_foxTurn_16(mr,rgCache))
    {
        return true;
    }
    pos = old119_0;
    return false;
}

bool GameState::apply_state_foxTurn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 0 + pos)
    {
        if (apply_state_foxTurn_18(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_foxTurn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old123_0 = player;
    player = keeper;
    currentState = 16;
    return true;
    player = old123_0;
    return false;
}

bool GameState::apply_state_foxTurn_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (bottomLine[pos]==1)
    {
        if (apply_state_foxTurn_20(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_foxTurn_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = pos;
    pos = foxPos;
    if (apply_state_foxTurn_5(mr,rgCache))
    {
        return true;
    }
    pos = old106_0;
    return false;
}

bool GameState::apply_state_foxTurn_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old126_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_state_foxTurn_22(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old126_0;
    return false;
}

bool GameState::apply_state_foxTurn_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old128_0 = foxPos;
    foxPos = pos;
    if (apply_state_foxTurn_23(mr,rgCache))
    {
        return true;
    }
    foxPos = old128_0;
    return false;
}

bool GameState::apply_state_foxTurn_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old127_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old127_0;
    return false;
}

bool GameState::apply_state_foxTurn_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old129_0 = board[pos];
    board[pos] = fox;
    if (apply_state_foxTurn_24(mr,rgCache))
    {
        return true;
    }
    board[pos] = old129_0;
    return false;
}

bool GameState::apply_state_foxTurn_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old105_0;
    return false;
}

bool GameState::apply_state_foxTurn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old107_0 = board[pos];
    board[pos] = empty;
    if (apply_state_foxTurn_6(mr,rgCache))
    {
        return true;
    }
    board[pos] = old107_0;
    return false;
}

bool GameState::apply_state_foxTurn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old108_0 = player;
    player = foxPlayer;
    currentState = 34;
    return true;
    player = old108_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        case 35:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = downLeft[pos];
                    player = keeper;
                    currentState = 16;
                    return true;
            }
            break;
}
        case 36:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = downRight[pos];
                    player = keeper;
                    currentState = 16;
                    return true;
            }
            break;
}
        case 33:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = upLeft[pos];
                    player = keeper;
                    currentState = 16;
                    return true;
            }
            break;
}
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    pos = upRight[pos];
                    player = keeper;
                    currentState = 16;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_foxTurn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_foxTurn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_foxTurn_17(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_foxTurn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = pos;
    pos = upLeft[pos];
    if (apply_state_foxTurn_10(mr,rgCache))
    {
        return true;
    }
    pos = old110_0;
    return false;
}

bool GameState::apply_state_foxTurn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1())
    {
        if (apply_state_foxTurn_1(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_foxTurn_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_foxTurn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_houndTurn_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old144_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_state_houndTurn_4(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old144_0;
    return false;
}

bool GameState::apply_state_houndTurn_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==empty)
    {
        if (apply_state_houndTurn_15(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_houndTurn_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old152_0 = pos;
    pos = upLeft[pos];
    if (apply_state_houndTurn_12(mr,rgCache))
    {
        return true;
    }
    pos = old152_0;
    return false;
}

bool GameState::apply_state_houndTurn_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_houndTurn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_houndTurn_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old155_0 = pos;
    pos = upRight[pos];
    if (apply_state_houndTurn_14(mr,rgCache))
    {
        return true;
    }
    pos = old155_0;
    return false;
}

bool GameState::apply_state_houndTurn_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_houndTurn_10(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_houndTurn_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[2] == 0 + pos)
    {
        if (apply_state_houndTurn_16(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_houndTurn_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old159_0 = player;
    player = keeper;
    currentState = 47;
    return true;
    player = old159_0;
    return false;
}

bool GameState::apply_state_houndTurn_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old160_0 = board[pos];
    board[pos] = hound;
    if (apply_state_houndTurn_18(mr,rgCache))
    {
        return true;
    }
    board[pos] = old160_0;
    return false;
}

bool GameState::apply_state_houndTurn_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_houndTurn_end(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_houndTurn_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = player;
    player = houndPlayer;
    currentState = 57;
    return true;
    player = old146_0;
    return false;
}

bool GameState::apply_state_houndTurn_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old145_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    player = old145_0;
    return false;
}

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            return apply_state_houndTurn_8(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_houndTurn_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_houndTurn_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[pos]==hound)
    {
        if (apply_state_houndTurn_7(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_houndTurn_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_houndTurn_8(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        case 33:
{
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    board[pos] = empty;
                    pos = upLeft[pos];
                    player = keeper;
                    currentState = 47;
                    return true;
            }
            break;
}
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    board[pos] = empty;
                    pos = upRight[pos];
                    player = keeper;
                    currentState = 47;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_houndTurn_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_houndTurn_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 33)
    {
        if (apply_state_houndTurn_11(mr,rgCache))
        {
            return true;
        }
    }
    if (mr[1] == 34)
    {
        if (apply_state_houndTurn_13(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_houndTurn_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_call_1())
    {
        if (apply_state_houndTurn_1(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_houndTurn_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_houndTurn_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_11(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            pos = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 73;
            return true;
    }
    return false;
}

bool GameState::apply_state_rules_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_4(mr ,rgCache);
    return false;
}

bool GameState::apply_state_rules_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_houndTurn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + pos)
    {
        if (apply_state_rules_4(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_rules_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old84_0 = player;
    player = keeper;
    currentState = 73;
    return true;
    player = old84_0;
    return false;
}

bool GameState::apply_state_rules_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old85_0 = foxPos;
    foxPos = pos;
    if (apply_state_rules_6(mr,rgCache))
    {
        return true;
    }
    foxPos = old85_0;
    return false;
}

bool GameState::apply_state_rules_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = board[pos];
    board[pos] = fox;
    if (apply_state_rules_7(mr,rgCache))
    {
        return true;
    }
    board[pos] = old86_0;
    return false;
}

bool GameState::apply_state_rules_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_rules_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_foxTurn_begin(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_rules_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old80_0 = player;
    player = foxPlayer;
    currentState = 67;
    return true;
    player = old80_0;
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
    return true;
}

bool GameState::apply_any_begin_begin_rules_begin()
{
    const auto old4_0 = player;
    player = foxPlayer;
    currentState = 67;
    return true;
    if (apply_any_begin_begin_rules_1())
    {
        return true;
    }
    player = old4_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_end()
{
    return true;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_19()
{
    if (bottomLine[pos]==1)
    {
        if (apply_any_foxTurn_19_foxTurn_19_foxTurn_20())
        {
            return true;
        }
        return false;
    }
    if (apply_any_foxTurn_19_foxTurn_19_foxTurn_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_20()
{
    const auto old16_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_any_foxTurn_19_foxTurn_19_foxTurn_22())
    {
        return true;
    }
    goals[foxPlayer - 2] = old16_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_21()
{
    const auto old18_0 = foxPos;
    foxPos = pos;
    if (apply_any_foxTurn_19_foxTurn_19_foxTurn_23())
    {
        return true;
    }
    foxPos = old18_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_22()
{
    const auto old17_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_foxTurn_19_foxTurn_19_end())
    {
        return true;
    }
    player = old17_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_23()
{
    const auto old19_0 = board[pos];
    board[pos] = fox;
    if (apply_any_foxTurn_19_foxTurn_19_foxTurn_24())
    {
        return true;
    }
    board[pos] = old19_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_24()
{
    if (apply_any_foxTurn_19_foxTurn_19_foxTurn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_foxTurn_end()
{
    if (apply_any_foxTurn_19_foxTurn_19_rules_10())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_houndTurn_1()
{
    const auto old25_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_any_foxTurn_19_foxTurn_19_houndTurn_4())
    {
        return true;
    }
    goals[foxPlayer - 2] = old25_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_houndTurn_2()
{
    const auto old27_0 = player;
    player = houndPlayer;
    currentState = 57;
    return true;
    if (apply_any_foxTurn_19_foxTurn_19_houndTurn_5())
    {
        return true;
    }
    player = old27_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_houndTurn_4()
{
    const auto old26_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_foxTurn_19_foxTurn_19_end())
    {
        return true;
    }
    player = old26_0;
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_houndTurn_5()
{
    return true;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_houndTurn_begin()
{
    if (!is_legal_houndsHaveMove_call_1_houndsHaveMove_end_houndsHaveMove_call_1())
    {
        if (apply_any_foxTurn_19_foxTurn_19_houndTurn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_foxTurn_19_foxTurn_19_houndTurn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_foxTurn_19_foxTurn_19_rules_10()
{
    if (apply_any_foxTurn_19_foxTurn_19_houndTurn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_end()
{
    return true;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_1()
{
    const auto old16_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_4())
    {
        return true;
    }
    goals[houndPlayer - 2] = old16_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_2()
{
    const auto old18_0 = pos;
    pos = foxPos;
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_5())
    {
        return true;
    }
    pos = old18_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_4()
{
    const auto old17_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_houndTurn_17_houndTurn_17_end())
    {
        return true;
    }
    player = old17_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_5()
{
    const auto old19_0 = board[pos];
    board[pos] = empty;
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_6())
    {
        return true;
    }
    board[pos] = old19_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_6()
{
    const auto old20_0 = player;
    player = foxPlayer;
    currentState = 34;
    return true;
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_7())
    {
        return true;
    }
    player = old20_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_7()
{
    return true;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_foxTurn_begin()
{
    if (!is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1())
    {
        if (apply_any_houndTurn_17_houndTurn_17_foxTurn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_houndTurn_17()
{
    const auto old21_0 = board[pos];
    board[pos] = hound;
    if (apply_any_houndTurn_17_houndTurn_17_houndTurn_18())
    {
        return true;
    }
    board[pos] = old21_0;
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_houndTurn_18()
{
    if (apply_any_houndTurn_17_houndTurn_17_houndTurn_end())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_houndTurn_end()
{
    if (apply_any_houndTurn_17_houndTurn_17_rules_11())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_rules_11()
{
    if (apply_any_houndTurn_17_houndTurn_17_rules_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_houndTurn_17_houndTurn_17_rules_8()
{
    if (apply_any_houndTurn_17_houndTurn_17_foxTurn_begin())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_rules_5_end()
{
    return true;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_1()
{
    const auto old18_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_any_rules_5_rules_5_foxTurn_4())
    {
        return true;
    }
    goals[houndPlayer - 2] = old18_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_2()
{
    const auto old20_0 = pos;
    pos = foxPos;
    if (apply_any_rules_5_rules_5_foxTurn_5())
    {
        return true;
    }
    pos = old20_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_4()
{
    const auto old19_0 = player;
    player = keeper;
    currentState = 2;
    return true;
    if (apply_any_rules_5_rules_5_end())
    {
        return true;
    }
    player = old19_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_5()
{
    const auto old21_0 = board[pos];
    board[pos] = empty;
    if (apply_any_rules_5_rules_5_foxTurn_6())
    {
        return true;
    }
    board[pos] = old21_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_6()
{
    const auto old22_0 = player;
    player = foxPlayer;
    currentState = 34;
    return true;
    if (apply_any_rules_5_rules_5_foxTurn_7())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_7()
{
    return true;
}

bool GameState::apply_any_rules_5_rules_5_foxTurn_begin()
{
    if (!is_legal_foxHasMove_call_1_foxHasMove_end_foxHasMove_call_1())
    {
        if (apply_any_rules_5_rules_5_foxTurn_1())
        {
            return true;
        }
        return false;
    }
    if (apply_any_rules_5_rules_5_foxTurn_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_rules_5_rules_5()
{
    const auto old12_0 = foxPos;
    foxPos = pos;
    if (apply_any_rules_5_rules_5_rules_6())
    {
        return true;
    }
    foxPos = old12_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_rules_6()
{
    const auto old13_0 = board[pos];
    board[pos] = fox;
    if (apply_any_rules_5_rules_5_rules_7())
    {
        return true;
    }
    board[pos] = old13_0;
    return false;
}

bool GameState::apply_any_rules_5_rules_5_rules_7()
{
    if (apply_any_rules_5_rules_5_rules_8())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_rules_5_rules_5_rules_8()
{
    if (apply_any_rules_5_rules_5_foxTurn_begin())
    {
        return true;
    }
    return false;
}

}  // namespace reasoner
