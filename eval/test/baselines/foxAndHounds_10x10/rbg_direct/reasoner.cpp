#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.coord_temp) ^ hash(gameState.counters) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.coord_temp) ^ hash(gameState.counters) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && coord==rhs.coord && coord_temp==rhs.coord_temp && counters==rhs.counters && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx8y4: " << board[rx8y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx8y5: " << board[rx8y5] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx3y8: " << board[rx3y8] << ", " << "rx4y8: " << board[rx4y8] << ", " << "rx5y8: " << board[rx5y8] << ", " << "rx4y9: " << board[rx4y9]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
    ss << "counters = " << "{" << "e: " << counters[e] << ", " << "f: " << counters[f] << ", " << "h: " << counters[h] << ", " << "null: " << counters[null]<< "}" << std::endl;
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
        case 51:
{
            state_27(moves, mr.mr,rgCache);
            return;
}
        case 154:
{
            state_70(moves, mr.mr,rgCache);
            return;
}
        case 1:
{
            state_1(moves, mr.mr,rgCache);
            return;
}
        case 219:
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
        case 51:
{
            apply_state_27(mr.mr,rgCache);
            return;
}
        case 154:
{
            apply_state_70(mr.mr,rgCache);
            return;
}
        case 1:
{
            apply_state_1(mr.mr,rgCache);
            return;
}
        case 219:
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
        case 25:
{
            apply_any_17_17_17();
            break;
}
        case 81:
{
            apply_any_41_41_41();
            break;
}
        case 134:
{
            apply_any_6_6_6();
            break;
}
        case 189:
{
            apply_any_87_87_87();
            break;
}
        case 219:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_101_102_101()
{
    if (is_legal_41_67_41_41_67_67_41_67_41())
    {
        if (is_legal_101_102_102())
        {
            return true;
        }
    }
    if (is_legal_41_71_41_41_71_71_41_71_41())
    {
        if (is_legal_101_102_102())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_101_102_102()
{
    return true;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_17()
{
    const auto old10_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (is_legal_17_28_17_17_28_28_17_28_20())
    {
        coord = old10_0;
        return true;
    }    }
    coord = old10_0;
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_20()
{
    if (board[coord]==f)
    {
        if (is_legal_17_28_17_17_28_28_17_28_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_21()
{
    const auto old12_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_17_28_17_17_28_28_17_28_23())
    {
        counters[board[coord]] = old12_0;
        return true;
    }
    counters[board[coord]] = old12_0;
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_22()
{
    if (is_legal_17_28_17_17_28_28_17_28_29())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_23()
{
    const auto old14_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_17_28_17_17_28_28_17_28_24())
    {
        counters[e] = old14_0;
        return true;
    }
    counters[e] = old14_0;
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_24()
{
    if (is_legal_17_28_17_17_28_28_17_28_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_25()
{
    const auto old16_0 = board[coord];
    board[coord] = e;
    if (is_legal_17_28_17_17_28_28_17_28_22())
    {
        board[coord] = old16_0;
        return true;
    }
    board[coord] = old16_0;
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_26()
{
    if (is_legal_17_28_17_17_28_28_17_28_25())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_28()
{
    return true;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_29()
{
    if (is_legal_17_28_17_17_28_28_17_28_28())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_1_7_1_1_7_7_1_7_1()
{
    if (is_legal_1_7_1_1_7_7_1_7_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_1_7_1_1_7_7_1_7_4()
{
    if (is_legal_1_7_1_1_7_7_1_7_8())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_1_7_1_1_7_7_1_7_5()
{
    const auto old7_0 = coord;
    for (const auto& coordIt : {rx0y4,rx1y3,rx2y2,rx3y1,rx4y0})
    {
    coord = coordIt;
    if (is_legal_1_7_1_1_7_7_1_7_4())
    {
        coord = old7_0;
        return true;
    }    }
    coord = old7_0;
    return false;
}

bool GameState::is_legal_1_7_1_1_7_7_1_7_7()
{
    return true;
}

bool GameState::is_legal_1_7_1_1_7_7_1_7_8()
{
    if (is_legal_1_7_1_1_7_7_1_7_7())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_27()
{
    const auto old14_0 = coord;
    coord = direction_upRight[coord];
    if (is_legal_27_42_27_27_42_42_27_42_33())
    {
        coord = old14_0;
        return true;
    }
    coord = old14_0;
    const auto old15_0 = coord;
    coord = direction_downLeft[coord];
    if (is_legal_27_42_27_27_42_42_27_42_35())
    {
        coord = old15_0;
        return true;
    }
    coord = old15_0;
    const auto old16_0 = coord;
    coord = direction_upLeft[coord];
    if (is_legal_27_42_27_27_42_42_27_42_37())
    {
        coord = old16_0;
        return true;
    }
    coord = old16_0;
    const auto old17_0 = coord;
    coord = direction_downRight[coord];
    if (is_legal_27_42_27_27_42_42_27_42_39())
    {
        coord = old17_0;
        return true;
    }
    coord = old17_0;
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_30()
{
    if (board[coord]==e)
    {
        if (is_legal_27_42_27_27_42_42_27_42_40())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_31()
{
    if (is_legal_27_42_27_27_42_42_27_42_30())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_32()
{
    if (is_legal_27_42_27_27_42_42_27_42_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_33()
{
    if (is_legal_27_42_27_27_42_42_27_42_32())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_34()
{
    if (is_legal_27_42_27_27_42_42_27_42_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_35()
{
    if (is_legal_27_42_27_27_42_42_27_42_34())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_36()
{
    if (is_legal_27_42_27_27_42_42_27_42_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_37()
{
    if (is_legal_27_42_27_27_42_42_27_42_36())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_38()
{
    if (is_legal_27_42_27_27_42_42_27_42_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_39()
{
    if (is_legal_27_42_27_27_42_42_27_42_38())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_40()
{
    if (is_legal_27_42_27_27_42_42_27_42_43())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_42()
{
    return true;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_43()
{
    if (is_legal_27_42_27_27_42_42_27_42_42())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_41()
{
    const auto old16_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_41_67_41_41_67_67_41_67_45())
    {
        counters[board[coord]] = old16_0;
        return true;
    }
    counters[board[coord]] = old16_0;
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_44()
{
    const auto old17_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (is_legal_41_67_41_41_67_67_41_67_50())
    {
        goals[foxPlayer - 2] = old17_0;
        return true;
    }
    goals[foxPlayer - 2] = old17_0;
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_45()
{
    const auto old18_0 = counters[f];
    counters[f] = counters[f]+1;
    if (is_legal_41_67_41_41_67_67_41_67_46())
    {
        counters[f] = old18_0;
        return true;
    }
    counters[f] = old18_0;
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_46()
{
    if (is_legal_41_67_41_41_67_67_41_67_48())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_47()
{
    const auto old20_0 = board[coord];
    board[coord] = f;
    if (is_legal_41_67_41_41_67_67_41_67_44())
    {
        board[coord] = old20_0;
        return true;
    }
    board[coord] = old20_0;
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_48()
{
    if (is_legal_41_67_41_41_67_67_41_67_47())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_49()
{
    const auto old22_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (is_legal_41_67_41_41_67_67_41_67_53())
    {
        goals[houndPlayer - 2] = old22_0;
        return true;
    }
    goals[houndPlayer - 2] = old22_0;
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_50()
{
    if (is_legal_41_67_41_41_67_67_41_67_51())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_51()
{
    if (is_legal_41_67_41_41_67_67_41_67_49())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_52()
{
    if (!is_legal_58_59_58())
    {
        if (is_legal_41_67_41_41_67_67_41_67_65())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_53()
{
    if (is_legal_41_67_41_41_67_67_41_67_54())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_54()
{
    if (is_legal_41_67_41_41_67_67_41_67_52())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_64()
{
    if (is_legal_41_67_41_41_67_67_41_67_68())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_65()
{
    if (is_legal_41_67_41_41_67_67_41_67_64())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_67()
{
    return true;
}

bool GameState::is_legal_41_67_41_41_67_67_41_67_68()
{
    if (is_legal_41_67_41_41_67_67_41_67_67())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_41()
{
    const auto old17_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_41_71_41_41_71_71_41_71_45())
    {
        counters[board[coord]] = old17_0;
        return true;
    }
    counters[board[coord]] = old17_0;
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_44()
{
    const auto old18_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (is_legal_41_71_41_41_71_71_41_71_50())
    {
        goals[foxPlayer - 2] = old18_0;
        return true;
    }
    goals[foxPlayer - 2] = old18_0;
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_45()
{
    const auto old19_0 = counters[f];
    counters[f] = counters[f]+1;
    if (is_legal_41_71_41_41_71_71_41_71_46())
    {
        counters[f] = old19_0;
        return true;
    }
    counters[f] = old19_0;
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_46()
{
    if (is_legal_41_71_41_41_71_71_41_71_48())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_47()
{
    const auto old21_0 = board[coord];
    board[coord] = f;
    if (is_legal_41_71_41_41_71_71_41_71_44())
    {
        board[coord] = old21_0;
        return true;
    }
    board[coord] = old21_0;
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_48()
{
    if (is_legal_41_71_41_41_71_71_41_71_47())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_49()
{
    const auto old23_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (is_legal_41_71_41_41_71_71_41_71_53())
    {
        goals[houndPlayer - 2] = old23_0;
        return true;
    }
    goals[houndPlayer - 2] = old23_0;
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_50()
{
    if (is_legal_41_71_41_41_71_71_41_71_51())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_51()
{
    if (is_legal_41_71_41_41_71_71_41_71_49())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_52()
{
    if (is_legal_58_59_58())
    {
        if (is_legal_41_71_41_41_71_71_41_71_57())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_53()
{
    if (is_legal_41_71_41_41_71_71_41_71_54())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_54()
{
    if (is_legal_41_71_41_41_71_71_41_71_52())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_55()
{
    if (is_legal_41_71_41_41_71_71_41_71_72())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_56()
{
    if (is_legal_41_71_41_41_71_71_41_71_55())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_57()
{
    if (is_legal_41_71_41_41_71_71_41_71_56())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_71()
{
    return true;
}

bool GameState::is_legal_41_71_41_41_71_71_41_71_72()
{
    if (is_legal_41_71_41_41_71_71_41_71_71())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_58_59_58()
{
    const auto old6_0 = coord;
    coord = direction_downLeft[coord];
    if (is_legal_58_59_61())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    const auto old7_0 = coord;
    coord = direction_downRight[coord];
    if (is_legal_58_59_63())
    {
        coord = old7_0;
        return true;
    }
    coord = old7_0;
    return false;
}

bool GameState::is_legal_58_59_59()
{
    return true;
}

bool GameState::is_legal_58_59_60()
{
    if (is_legal_58_59_59())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_58_59_61()
{
    if (coord!=null)
    {
        if (is_legal_58_59_60())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_58_59_62()
{
    if (is_legal_58_59_59())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_58_59_63()
{
    if (coord!=null)
    {
        if (is_legal_58_59_62())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_10()
{
    const auto old9_0 = counters[f];
    counters[f] = counters[f]+1;
    if (is_legal_6_18_6_6_18_18_6_18_11())
    {
        counters[f] = old9_0;
        return true;
    }
    counters[f] = old9_0;
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_11()
{
    if (is_legal_6_18_6_6_18_18_6_18_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_12()
{
    const auto old11_0 = board[coord];
    board[coord] = f;
    if (is_legal_6_18_6_6_18_18_6_18_9())
    {
        board[coord] = old11_0;
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_13()
{
    if (is_legal_6_18_6_6_18_18_6_18_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_15()
{
    if (is_legal_6_18_6_6_18_18_6_18_19())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_18()
{
    return true;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_19()
{
    if (is_legal_6_18_6_6_18_18_6_18_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_6()
{
    const auto old15_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_6_18_6_6_18_18_6_18_10())
    {
        counters[board[coord]] = old15_0;
        return true;
    }
    counters[board[coord]] = old15_0;
    return false;
}

bool GameState::is_legal_6_18_6_6_18_18_6_18_9()
{
    if (is_legal_6_18_6_6_18_18_6_18_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_70()
{
    const auto old17_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (is_legal_70_88_70_70_88_88_70_88_73())
    {
        coord = old17_0;
        return true;
    }    }
    coord = old17_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_73()
{
    if (board[coord]==h)
    {
        if (is_legal_70_88_70_70_88_88_70_88_74())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_74()
{
    const auto old19_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_70_88_70_70_88_88_70_88_76())
    {
        counters[board[coord]] = old19_0;
        return true;
    }
    counters[board[coord]] = old19_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_75()
{
    const auto old20_0 = coord;
    coord = direction_upLeft[coord];
    if (is_legal_70_88_70_70_88_88_70_88_83())
    {
        coord = old20_0;
        return true;
    }
    coord = old20_0;
    const auto old21_0 = coord;
    coord = direction_upRight[coord];
    if (is_legal_70_88_70_70_88_88_70_88_85())
    {
        coord = old21_0;
        return true;
    }
    coord = old21_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_76()
{
    const auto old22_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_70_88_70_70_88_88_70_88_77())
    {
        counters[e] = old22_0;
        return true;
    }
    counters[e] = old22_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_77()
{
    if (is_legal_70_88_70_70_88_88_70_88_79())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_78()
{
    const auto old24_0 = board[coord];
    board[coord] = e;
    if (is_legal_70_88_70_70_88_88_70_88_75())
    {
        board[coord] = old24_0;
        return true;
    }
    board[coord] = old24_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_79()
{
    if (is_legal_70_88_70_70_88_88_70_88_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_80()
{
    if (board[coord]==e)
    {
        if (is_legal_70_88_70_70_88_88_70_88_86())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_81()
{
    if (is_legal_70_88_70_70_88_88_70_88_80())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_82()
{
    if (is_legal_70_88_70_70_88_88_70_88_81())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_83()
{
    if (is_legal_70_88_70_70_88_88_70_88_82())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_84()
{
    if (is_legal_70_88_70_70_88_88_70_88_81())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_85()
{
    if (is_legal_70_88_70_70_88_88_70_88_84())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_86()
{
    if (is_legal_70_88_70_70_88_88_70_88_89())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_88()
{
    return true;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_89()
{
    if (is_legal_70_88_70_70_88_88_70_88_88())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_100()
{
    if (is_legal_87_18_87_87_18_18_87_18_98())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_15()
{
    if (is_legal_87_18_87_87_18_18_87_18_19())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_16()
{
    if (is_legal_87_18_87_87_18_18_87_18_15())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_18()
{
    return true;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_19()
{
    if (is_legal_87_18_87_87_18_18_87_18_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_87()
{
    const auto old20_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_87_18_87_87_18_18_87_18_91())
    {
        counters[board[coord]] = old20_0;
        return true;
    }
    counters[board[coord]] = old20_0;
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_90()
{
    const auto old21_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    if (is_legal_87_18_87_87_18_18_87_18_96())
    {
        goals[foxPlayer - 2] = old21_0;
        return true;
    }
    goals[foxPlayer - 2] = old21_0;
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_91()
{
    const auto old22_0 = counters[h];
    counters[h] = counters[h]+1;
    if (is_legal_87_18_87_87_18_18_87_18_92())
    {
        counters[h] = old22_0;
        return true;
    }
    counters[h] = old22_0;
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_92()
{
    if (is_legal_87_18_87_87_18_18_87_18_94())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_93()
{
    const auto old24_0 = board[coord];
    board[coord] = h;
    if (is_legal_87_18_87_87_18_18_87_18_90())
    {
        board[coord] = old24_0;
        return true;
    }
    board[coord] = old24_0;
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_94()
{
    if (is_legal_87_18_87_87_18_18_87_18_93())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_95()
{
    const auto old26_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (is_legal_87_18_87_87_18_18_87_18_99())
    {
        goals[houndPlayer - 2] = old26_0;
        return true;
    }
    goals[houndPlayer - 2] = old26_0;
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_96()
{
    if (is_legal_87_18_87_87_18_18_87_18_97())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_97()
{
    if (is_legal_87_18_87_87_18_18_87_18_95())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_98()
{
    if (is_legal_87_18_87_87_18_18_87_18_16())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_18_87_87_18_18_87_18_99()
{
    if (is_legal_87_18_87_87_18_18_87_18_100())
    {
        return true;
    }
    return false;
}

void GameState::state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_5(moves, mr,rgCache);
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old221_0 = counters[f];
    counters[f] = counters[f]+1;
    state_11(moves, mr,rgCache);
    counters[f] = old221_0;
}

void GameState::state_100([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_98(moves, mr,rgCache);
}

void GameState::state_103([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_104([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_105([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_106([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_107([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_108([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_109([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_13(moves, mr,rgCache);
}

void GameState::state_110([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_111([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_112([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_113([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_114([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_115([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_116([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old226_0 = board[coord];
    board[coord] = f;
    state_9(moves, mr,rgCache);
    board[coord] = old226_0;
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_12(moves, mr,rgCache);
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_19(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_15(moves, mr,rgCache);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    state_20(moves, mr,rgCache);    }
    coord = old230_0;
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_17_28_17_17_28_28_17_28_17())
    {
        state_107(moves, mr,rgCache);
        return;
    }
    state_108(moves, mr,rgCache);
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(51);
    state_18(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_1_7_1_1_7_7_1_7_1())
    {
        state_103(moves, mr,rgCache);
        return;
    }
    state_104(moves, mr,rgCache);
}

void GameState::state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==f)
    {
        state_21(moves, mr,rgCache);
    }
}

void GameState::state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old246_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_23(moves, mr,rgCache);
    counters[board[coord]] = old246_0;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_29(moves, mr,rgCache);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old248_0 = counters[e];
    counters[e] = counters[e]+1;
    state_24(moves, mr,rgCache);
    counters[e] = old248_0;
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_26(moves, mr,rgCache);
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old250_0 = board[coord];
    board[coord] = e;
    state_22(moves, mr,rgCache);
    board[coord] = old250_0;
}

void GameState::state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_25(moves, mr,rgCache);
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old252_0 = coord;
    coord = direction_upRight[coord];
    state_33(moves, mr,rgCache);
    coord = old252_0;
    const auto old253_0 = coord;
    coord = direction_downLeft[coord];
    state_35(moves, mr,rgCache);
    coord = old253_0;
    const auto old254_0 = coord;
    coord = direction_upLeft[coord];
    state_37(moves, mr,rgCache);
    coord = old254_0;
    const auto old255_0 = coord;
    coord = direction_downRight[coord];
    state_39(moves, mr,rgCache);
    coord = old255_0;
}

void GameState::state_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_27_42_27_27_42_42_27_42_27())
    {
        state_109(moves, mr,rgCache);
        return;
    }
    state_110(moves, mr,rgCache);
}

void GameState::state_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_28(moves, mr,rgCache);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(52);
    state_2(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_40(moves, mr,rgCache);
    }
}

void GameState::state_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_31;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_30(moves, mr,rgCache);
}

void GameState::state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_31(moves, mr,rgCache);
}

void GameState::state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_32(moves, mr,rgCache);
}

void GameState::state_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_31(moves, mr,rgCache);
}

void GameState::state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_34(moves, mr,rgCache);
}

void GameState::state_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_31(moves, mr,rgCache);
}

void GameState::state_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_36(moves, mr,rgCache);
}

void GameState::state_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_31(moves, mr,rgCache);
}

void GameState::state_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_38(moves, mr,rgCache);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_8(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_43(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_41([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old286_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_45(moves, mr,rgCache);
    counters[board[coord]] = old286_0;
}

void GameState::state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_101_102_101())
    {
        state_111(moves, mr,rgCache);
        return;
    }
    state_112(moves, mr,rgCache);
}

void GameState::state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(53);
    state_42(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old319_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    state_50(moves, mr,rgCache);
    goals[foxPlayer - 2] = old319_0;
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old320_0 = counters[f];
    counters[f] = counters[f]+1;
    state_46(moves, mr,rgCache);
    counters[f] = old320_0;
}

void GameState::state_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_48(moves, mr,rgCache);
}

void GameState::state_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old322_0 = board[coord];
    board[coord] = f;
    state_44(moves, mr,rgCache);
    board[coord] = old322_0;
}

void GameState::state_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_47(moves, mr,rgCache);
}

void GameState::state_49([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old324_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    state_53(moves, mr,rgCache);
    goals[houndPlayer - 2] = old324_0;
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old325_0 = coord;
    for (const auto& coordIt : {rx0y4,rx1y3,rx2y2,rx3y1,rx4y0})
    {
    coord = coordIt;
    state_4(moves, mr,rgCache);    }
    coord = old325_0;
}

void GameState::state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_51(moves, mr,rgCache);
}

void GameState::state_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_49(moves, mr,rgCache);
}

void GameState::state_52([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_58_59_58())
    {
        state_57(moves, mr,rgCache);
        return;
    }
    state_65(moves, mr,rgCache);
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_54(moves, mr,rgCache);
}

void GameState::state_54([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_52(moves, mr,rgCache);
}

void GameState::state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_72(moves, mr,rgCache);
}

void GameState::state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_55(moves, mr,rgCache);
}

void GameState::state_57([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_56(moves, mr,rgCache);
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old337_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_10(moves, mr,rgCache);
    counters[board[coord]] = old337_0;
}

void GameState::state_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_68(moves, mr,rgCache);
}

void GameState::state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_64(moves, mr,rgCache);
}

void GameState::state_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_67(moves, mr,rgCache);
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_6_18_6_6_18_18_6_18_6())
    {
        state_105(moves, mr,rgCache);
        return;
    }
    state_106(moves, mr,rgCache);
}

void GameState::state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old355_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    state_73(moves, mr,rgCache);    }
    coord = old355_0;
}

void GameState::state_71([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_70_88_70_70_88_88_70_88_70())
    {
        state_113(moves, mr,rgCache);
        return;
    }
    state_114(moves, mr,rgCache);
}

void GameState::state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_71(moves, mr,rgCache);
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==h)
    {
        state_74(moves, mr,rgCache);
    }
}

void GameState::state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old375_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_76(moves, mr,rgCache);
    counters[board[coord]] = old375_0;
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old376_0 = coord;
    coord = direction_upLeft[coord];
    state_83(moves, mr,rgCache);
    coord = old376_0;
    const auto old377_0 = coord;
    coord = direction_upRight[coord];
    state_85(moves, mr,rgCache);
    coord = old377_0;
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old378_0 = counters[e];
    counters[e] = counters[e]+1;
    state_77(moves, mr,rgCache);
    counters[e] = old378_0;
}

void GameState::state_77([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_79(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old380_0 = board[coord];
    board[coord] = e;
    state_75(moves, mr,rgCache);
    board[coord] = old380_0;
}

void GameState::state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(55);
    rgCache.state_cache_81.reset();
    state_78(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(56);
    state_7(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_86(moves, mr,rgCache);
    }
}

void GameState::state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_81;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_80(moves, mr,rgCache);
}

void GameState::state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_81(moves, mr,rgCache);
}

void GameState::state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_82(moves, mr,rgCache);
}

void GameState::state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_81(moves, mr,rgCache);
}

void GameState::state_85([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_84(moves, mr,rgCache);
}

void GameState::state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_89(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_87([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old390_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_91(moves, mr,rgCache);
    counters[board[coord]] = old390_0;
}

void GameState::state_88([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_87_18_87_87_18_18_87_18_87())
    {
        state_115(moves, mr,rgCache);
        return;
    }
    state_116(moves, mr,rgCache);
}

void GameState::state_89([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(57);
    state_88(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_15(moves, mr,rgCache);
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old408_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    state_96(moves, mr,rgCache);
    goals[foxPlayer - 2] = old408_0;
}

void GameState::state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old409_0 = counters[h];
    counters[h] = counters[h]+1;
    state_92(moves, mr,rgCache);
    counters[h] = old409_0;
}

void GameState::state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_94(moves, mr,rgCache);
}

void GameState::state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old411_0 = board[coord];
    board[coord] = h;
    state_90(moves, mr,rgCache);
    board[coord] = old411_0;
}

void GameState::state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_93(moves, mr,rgCache);
}

void GameState::state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old413_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    state_99(moves, mr,rgCache);
    goals[houndPlayer - 2] = old413_0;
}

void GameState::state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_97(moves, mr,rgCache);
}

void GameState::state_97([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_95(moves, mr,rgCache);
}

void GameState::state_98([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_16(moves, mr,rgCache);
}

void GameState::state_99([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_100(moves, mr,rgCache);
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_3(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    return apply_state_7(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old221_0 = counters[f];
    counters[f] = counters[f]+1;
    if (apply_state_11(mr,rgCache))
    {
        return true;
    }
    counters[f] = old221_0;
    return false;
}

bool GameState::apply_state_100([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_98(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_103([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old420_0 = player;
    player = foxPlayer;
    currentState = 1;
    return true;
    player = old420_0;
    return false;
}

bool GameState::apply_state_104([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old422_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old422_0;
    return false;
}

bool GameState::apply_state_105([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old424_0 = player;
    player = keeper;
    currentState = 134;
    return true;
    player = old424_0;
    return false;
}

bool GameState::apply_state_106([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old426_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old426_0;
    return false;
}

bool GameState::apply_state_107([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old428_0 = player;
    player = keeper;
    currentState = 25;
    return true;
    player = old428_0;
    return false;
}

bool GameState::apply_state_108([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old430_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old430_0;
    return false;
}

bool GameState::apply_state_109([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old432_0 = player;
    player = foxPlayer;
    currentState = 51;
    return true;
    player = old432_0;
    return false;
}

bool GameState::apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_13(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_110([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old434_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old434_0;
    return false;
}

bool GameState::apply_state_111([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old436_0 = player;
    player = keeper;
    currentState = 81;
    return true;
    player = old436_0;
    return false;
}

bool GameState::apply_state_112([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old438_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old438_0;
    return false;
}

bool GameState::apply_state_113([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old440_0 = player;
    player = houndPlayer;
    currentState = 154;
    return true;
    player = old440_0;
    return false;
}

bool GameState::apply_state_114([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old442_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old442_0;
    return false;
}

bool GameState::apply_state_115([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old444_0 = player;
    player = keeper;
    currentState = 189;
    return true;
    player = old444_0;
    return false;
}

bool GameState::apply_state_116([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old446_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old446_0;
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old226_0 = board[coord];
    board[coord] = f;
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    board[coord] = old226_0;
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_12(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_19(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }    }
    coord = old230_0;
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_state_107(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_108(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 51:
{
                return apply_state_18(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_1(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 51)
    {
        rgCache.currentMrId++;
        if (apply_state_18(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_1_7_1_1_7_7_1_7_1())
    {
        if (apply_state_103(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_104(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==f)
    {
        if (apply_state_21(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old246_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_23(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old246_0;
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_29(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old248_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_24(mr,rgCache))
    {
        return true;
    }
    counters[e] = old248_0;
    return false;
}

bool GameState::apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_26(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old250_0 = board[coord];
    board[coord] = e;
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    board[coord] = old250_0;
    return false;
}

bool GameState::apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_25(mr,rgCache))
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
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    return apply_state_42(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_27_42_27_27_42_42_27_42_27())
    {
        if (apply_state_109(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_110(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_28(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 52:
{
                return apply_state_2(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_3(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 52)
    {
        rgCache.currentMrId++;
        if (apply_state_2(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_40(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_31;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_30(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_32(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_36(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_38(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_8(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_43(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_41([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old286_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_45(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old286_0;
    return false;
}

bool GameState::apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_101_102_101())
    {
        if (apply_state_111(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_112(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 53:
{
                return apply_state_42(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_4(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 53)
    {
        rgCache.currentMrId++;
        if (apply_state_42(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old319_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_state_50(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old319_0;
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old320_0 = counters[f];
    counters[f] = counters[f]+1;
    if (apply_state_46(mr,rgCache))
    {
        return true;
    }
    counters[f] = old320_0;
    return false;
}

bool GameState::apply_state_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_48(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old322_0 = board[coord];
    board[coord] = f;
    if (apply_state_44(mr,rgCache))
    {
        return true;
    }
    board[coord] = old322_0;
    return false;
}

bool GameState::apply_state_48([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_47(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_49([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old324_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (apply_state_53(mr,rgCache))
    {
        return true;
    }
    goals[houndPlayer - 2] = old324_0;
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old325_0 = coord;
    for (const auto& coordIt : {rx0y4,rx1y3,rx2y2,rx3y1,rx4y0})
    {
    coord = coordIt;
    if (apply_state_4(mr,rgCache))
    {
        return true;
    }    }
    coord = old325_0;
    return false;
}

bool GameState::apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_51(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_49(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_52([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_58_59_58())
    {
        if (apply_state_57(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_65(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_54(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_54([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_52(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_72(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_55(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_57([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_56(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    counters[board[coord]] = counters[board[coord]]-1;
                    counters[f] = counters[f]+1;
                    board[coord] = f;
                    return apply_state_18(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_5(mr ,rgCache);
    return false;
}

bool GameState::apply_state_64([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_68(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_64(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_67([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old344_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    player = old344_0;
    return false;
}

bool GameState::apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_67(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_6_18_6_6_18_18_6_18_6())
    {
        if (apply_state_105(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_106(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    switch (mr[rgCache.currentMrId++])
                    {
                        default:
                            switch (mr[rgCache.currentMrId++])
                            {
                                default:
                                    coord = mr[rgCache.currentMrId - 4] - 0;
                                    counters[board[coord]] = counters[board[coord]]-1;
                                    counters[e] = counters[e]+1;
                                    board[coord] = e;
                                    coord = mr[rgCache.currentMrId - 2] - 0;
                                    return apply_state_88(mr,rgCache);
                            }
                            break;
                    }
                    break;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_70([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_6(mr ,rgCache);
    return false;
}

bool GameState::apply_state_71([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_70_88_70_70_88_88_70_88_70())
    {
        if (apply_state_113(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_114(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_71(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==h)
    {
        if (apply_state_74(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old375_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_76(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old375_0;
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old376_0 = coord;
    coord = direction_upLeft[coord];
    if (apply_state_83(mr,rgCache))
    {
        return true;
    }
    coord = old376_0;
    const auto old377_0 = coord;
    coord = direction_upRight[coord];
    if (apply_state_85(mr,rgCache))
    {
        return true;
    }
    coord = old377_0;
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old378_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_77(mr,rgCache))
    {
        return true;
    }
    counters[e] = old378_0;
    return false;
}

bool GameState::apply_state_77([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_79(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old380_0 = board[coord];
    board[coord] = e;
    if (apply_state_75(mr,rgCache))
    {
        return true;
    }
    board[coord] = old380_0;
    return false;
}

bool GameState::switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 55:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 0 ... 50:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 57:
{
                                        board[coord] = e;
                                        coord = mr[rgCache.currentMrId - 2] - 0;
                                        return apply_state_88(mr,rgCache);
}
                                }
                            }
                            break;
}
                    }
                }
                break;
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_7(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 55)
    {
        rgCache.currentMrId++;
        rgCache.state_cache_81.reset();
        if (apply_state_78(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 56:
{
                return apply_state_7(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_8(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 56)
    {
        rgCache.currentMrId++;
        if (apply_state_7(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_86(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_81;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_80(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_81(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_83([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_82(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_81(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_85([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_84(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_89(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::switch_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    counters[board[coord]] = counters[board[coord]]-1;
                    counters[h] = counters[h]+1;
                    board[coord] = h;
                    goals[foxPlayer - 2] = 0;
                    goals[houndPlayer - 2] = 100;
                    return apply_state_18(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_87([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_9(mr ,rgCache);
    return false;
}

bool GameState::apply_state_88([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_87_18_87_87_18_18_87_18_87())
    {
        if (apply_state_115(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_116(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 57:
{
                return apply_state_88(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_89([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_10(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 57)
    {
        rgCache.currentMrId++;
        if (apply_state_88(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old408_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    if (apply_state_96(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old408_0;
    return false;
}

bool GameState::apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old409_0 = counters[h];
    counters[h] = counters[h]+1;
    if (apply_state_92(mr,rgCache))
    {
        return true;
    }
    counters[h] = old409_0;
    return false;
}

bool GameState::apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_94(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old411_0 = board[coord];
    board[coord] = h;
    if (apply_state_90(mr,rgCache))
    {
        return true;
    }
    board[coord] = old411_0;
    return false;
}

bool GameState::apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_93(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_95([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old413_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_state_99(mr,rgCache))
    {
        return true;
    }
    goals[houndPlayer - 2] = old413_0;
    return false;
}

bool GameState::apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_97(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_97([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_95(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_98([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_16(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_99([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_100(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    return apply_state_2(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_11(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_17_17_109()
{
    const auto old24_0 = player;
    player = foxPlayer;
    currentState = 51;
    return true;
    if (apply_any_17_17_27())
    {
        return true;
    }
    player = old24_0;
    return false;
}

bool GameState::apply_any_17_17_110()
{
    const auto old26_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_17_17_end())
    {
        return true;
    }
    player = old26_0;
    return false;
}

bool GameState::apply_any_17_17_17()
{
    const auto old14_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (apply_any_17_17_20())
    {
        return true;
    }    }
    coord = old14_0;
    return false;
}

bool GameState::apply_any_17_17_20()
{
    if (board[coord]==f)
    {
        if (apply_any_17_17_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_17_17_21()
{
    const auto old16_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_17_17_23())
    {
        return true;
    }
    counters[board[coord]] = old16_0;
    return false;
}

bool GameState::apply_any_17_17_22()
{
    if (apply_any_17_17_29())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_23()
{
    const auto old18_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_any_17_17_24())
    {
        return true;
    }
    counters[e] = old18_0;
    return false;
}

bool GameState::apply_any_17_17_24()
{
    if (apply_any_17_17_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_25()
{
    const auto old20_0 = board[coord];
    board[coord] = e;
    if (apply_any_17_17_22())
    {
        return true;
    }
    board[coord] = old20_0;
    return false;
}

bool GameState::apply_any_17_17_26()
{
    if (apply_any_17_17_25())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_27()
{
    return true;
}

bool GameState::apply_any_17_17_28()
{
    if (is_legal_27_42_27_27_42_42_27_42_27())
    {
        if (apply_any_17_17_109())
        {
            return true;
        }
        return false;
    }
    if (apply_any_17_17_110())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_29()
{
    if (apply_any_17_17_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_end()
{
    return true;
}

bool GameState::apply_any_41_41_113()
{
    const auto old47_0 = player;
    player = houndPlayer;
    currentState = 154;
    return true;
    if (apply_any_41_41_70())
    {
        return true;
    }
    player = old47_0;
    return false;
}

bool GameState::apply_any_41_41_114()
{
    const auto old49_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_41_41_end())
    {
        return true;
    }
    player = old49_0;
    return false;
}

bool GameState::apply_any_41_41_41()
{
    const auto old25_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_41_41_45())
    {
        return true;
    }
    counters[board[coord]] = old25_0;
    return false;
}

bool GameState::apply_any_41_41_44()
{
    const auto old26_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_any_41_41_50())
    {
        return true;
    }
    goals[foxPlayer - 2] = old26_0;
    return false;
}

bool GameState::apply_any_41_41_45()
{
    const auto old27_0 = counters[f];
    counters[f] = counters[f]+1;
    if (apply_any_41_41_46())
    {
        return true;
    }
    counters[f] = old27_0;
    return false;
}

bool GameState::apply_any_41_41_46()
{
    if (apply_any_41_41_48())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_47()
{
    const auto old29_0 = board[coord];
    board[coord] = f;
    if (apply_any_41_41_44())
    {
        return true;
    }
    board[coord] = old29_0;
    return false;
}

bool GameState::apply_any_41_41_48()
{
    if (apply_any_41_41_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_49()
{
    const auto old31_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (apply_any_41_41_53())
    {
        return true;
    }
    goals[houndPlayer - 2] = old31_0;
    return false;
}

bool GameState::apply_any_41_41_50()
{
    if (apply_any_41_41_51())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_51()
{
    if (apply_any_41_41_49())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_52()
{
    if (is_legal_58_59_58())
    {
        if (apply_any_41_41_57())
        {
            return true;
        }
        return false;
    }
    if (apply_any_41_41_65())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_53()
{
    if (apply_any_41_41_54())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_54()
{
    if (apply_any_41_41_52())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_55()
{
    if (apply_any_41_41_72())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_56()
{
    if (apply_any_41_41_55())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_57()
{
    if (apply_any_41_41_56())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_64()
{
    if (apply_any_41_41_68())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_65()
{
    if (apply_any_41_41_64())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_67()
{
    const auto old43_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_41_41_end())
    {
        return true;
    }
    player = old43_0;
    return false;
}

bool GameState::apply_any_41_41_68()
{
    if (apply_any_41_41_67())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_70()
{
    return true;
}

bool GameState::apply_any_41_41_71()
{
    if (is_legal_70_88_70_70_88_88_70_88_70())
    {
        if (apply_any_41_41_113())
        {
            return true;
        }
        return false;
    }
    if (apply_any_41_41_114())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_72()
{
    if (apply_any_41_41_71())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_41_41_end()
{
    return true;
}

bool GameState::apply_any_6_6_10()
{
    const auto old13_0 = counters[f];
    counters[f] = counters[f]+1;
    if (apply_any_6_6_11())
    {
        return true;
    }
    counters[f] = old13_0;
    return false;
}

bool GameState::apply_any_6_6_107()
{
    const auto old22_0 = player;
    player = keeper;
    currentState = 25;
    return true;
    if (apply_any_6_6_17())
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_6_6_108()
{
    const auto old24_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_6_6_end())
    {
        return true;
    }
    player = old24_0;
    return false;
}

bool GameState::apply_any_6_6_11()
{
    if (apply_any_6_6_13())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_12()
{
    const auto old15_0 = board[coord];
    board[coord] = f;
    if (apply_any_6_6_9())
    {
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::apply_any_6_6_13()
{
    if (apply_any_6_6_12())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_15()
{
    if (apply_any_6_6_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_17()
{
    return true;
}

bool GameState::apply_any_6_6_18()
{
    if (is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_any_6_6_107())
        {
            return true;
        }
        return false;
    }
    if (apply_any_6_6_108())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_19()
{
    if (apply_any_6_6_18())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_6()
{
    const auto old19_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_6_6_10())
    {
        return true;
    }
    counters[board[coord]] = old19_0;
    return false;
}

bool GameState::apply_any_6_6_9()
{
    if (apply_any_6_6_15())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_6_6_end()
{
    return true;
}

bool GameState::apply_any_87_87_100()
{
    if (apply_any_87_87_98())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_107()
{
    const auto old36_0 = player;
    player = keeper;
    currentState = 25;
    return true;
    if (apply_any_87_87_17())
    {
        return true;
    }
    player = old36_0;
    return false;
}

bool GameState::apply_any_87_87_108()
{
    const auto old38_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_87_87_end())
    {
        return true;
    }
    player = old38_0;
    return false;
}

bool GameState::apply_any_87_87_15()
{
    if (apply_any_87_87_19())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_16()
{
    if (apply_any_87_87_15())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_17()
{
    return true;
}

bool GameState::apply_any_87_87_18()
{
    if (is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_any_87_87_107())
        {
            return true;
        }
        return false;
    }
    if (apply_any_87_87_108())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_19()
{
    if (apply_any_87_87_18())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_87()
{
    const auto old24_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_87_87_91())
    {
        return true;
    }
    counters[board[coord]] = old24_0;
    return false;
}

bool GameState::apply_any_87_87_90()
{
    const auto old25_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    if (apply_any_87_87_96())
    {
        return true;
    }
    goals[foxPlayer - 2] = old25_0;
    return false;
}

bool GameState::apply_any_87_87_91()
{
    const auto old26_0 = counters[h];
    counters[h] = counters[h]+1;
    if (apply_any_87_87_92())
    {
        return true;
    }
    counters[h] = old26_0;
    return false;
}

bool GameState::apply_any_87_87_92()
{
    if (apply_any_87_87_94())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_93()
{
    const auto old28_0 = board[coord];
    board[coord] = h;
    if (apply_any_87_87_90())
    {
        return true;
    }
    board[coord] = old28_0;
    return false;
}

bool GameState::apply_any_87_87_94()
{
    if (apply_any_87_87_93())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_95()
{
    const auto old30_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_any_87_87_99())
    {
        return true;
    }
    goals[houndPlayer - 2] = old30_0;
    return false;
}

bool GameState::apply_any_87_87_96()
{
    if (apply_any_87_87_97())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_97()
{
    if (apply_any_87_87_95())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_98()
{
    if (apply_any_87_87_16())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_99()
{
    if (apply_any_87_87_100())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_87_87_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_1()
{
    return true;
}

bool GameState::apply_any_begin_begin_103()
{
    const auto old10_0 = player;
    player = foxPlayer;
    currentState = 1;
    return true;
    if (apply_any_begin_begin_1())
    {
        return true;
    }
    player = old10_0;
    return false;
}

bool GameState::apply_any_begin_begin_104()
{
    const auto old12_0 = player;
    player = keeper;
    currentState = 220;
    return true;
    if (apply_any_begin_begin_end())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_2()
{
    if (is_legal_1_7_1_1_7_7_1_7_1())
    {
        if (apply_any_begin_begin_103())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_104())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_3()
{
    if (apply_any_begin_begin_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin()
{
    if (apply_any_begin_begin_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_end()
{
    return true;
}

}  // namespace reasoner
