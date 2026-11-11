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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx7y0: " << board[rx7y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx7y1: " << board[rx7y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx7y2: " << board[rx7y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx0y7: " << board[rx0y7] << ", " << "rx1y7: " << board[rx1y7] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx7y7: " << board[rx7y7]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
    ss << "counters = " << "{" << "b: " << counters[b] << ", " << "e: " << counters[e] << ", " << "w: " << counters[w] << ", " << "null: " << counters[null]<< "}" << std::endl;
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
        case 61:
{
            state_4(moves, mr.mr);
            return;
}
        case 66:
{
            state_45(moves, mr.mr);
            return;
}
        case 181:
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
        case 61:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 66:
{
            apply_state_45(mr.mr,rgCache);
            return;
}
        case 181:
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
        case 9:
{
            apply_any_18_18_18();
            break;
}
        case 109:
{
            apply_any_59_59_59();
            break;
}
        case 181:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_18()
{
    const auto old11_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_18_42_18_18_42_42_18_42_22())
    {
        goals[white - 2] = old11_0;
        return true;
    }
    goals[white - 2] = old11_0;
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_21()
{
    const auto old12_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_18_42_18_18_42_42_18_42_25())
    {
        goals[black - 2] = old12_0;
        return true;
    }
    goals[black - 2] = old12_0;
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_22()
{
    if (is_legal_18_42_18_18_42_42_18_42_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_23()
{
    if (is_legal_18_42_18_18_42_42_18_42_21())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_24()
{
    if (!is_legal_30_31_30())
    {
        if (is_legal_18_42_18_18_42_42_18_42_40())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_25()
{
    if (is_legal_18_42_18_18_42_42_18_42_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_26()
{
    if (is_legal_18_42_18_18_42_42_18_42_24())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_39()
{
    if (is_legal_18_42_18_18_42_42_18_42_43())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_40()
{
    if (is_legal_18_42_18_18_42_42_18_42_39())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_42()
{
    return true;
}

bool GameState::is_legal_18_42_18_18_42_42_18_42_43()
{
    if (is_legal_18_42_18_18_42_42_18_42_42())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_18()
{
    const auto old17_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_18_46_18_18_46_46_18_46_22())
    {
        goals[white - 2] = old17_0;
        return true;
    }
    goals[white - 2] = old17_0;
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_21()
{
    const auto old18_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_18_46_18_18_46_46_18_46_25())
    {
        goals[black - 2] = old18_0;
        return true;
    }
    goals[black - 2] = old18_0;
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_22()
{
    if (is_legal_18_46_18_18_46_46_18_46_23())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_23()
{
    if (is_legal_18_46_18_18_46_46_18_46_21())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_24()
{
    if (is_legal_30_31_30())
    {
        if (is_legal_18_46_18_18_46_46_18_46_29())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_25()
{
    if (is_legal_18_46_18_18_46_46_18_46_26())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_26()
{
    if (is_legal_18_46_18_18_46_46_18_46_24())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_27()
{
    if (is_legal_18_46_18_18_46_46_18_46_47())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_28()
{
    const auto old25_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_18_46_18_18_46_46_18_46_35())
    {
        counters[board[coord]] = old25_0;
        return true;
    }
    counters[board[coord]] = old25_0;
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_29()
{
    if (is_legal_18_46_18_18_46_46_18_46_28())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_34()
{
    if (is_legal_18_46_18_18_46_46_18_46_27())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_35()
{
    const auto old28_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_18_46_18_18_46_46_18_46_36())
    {
        counters[w] = old28_0;
        return true;
    }
    counters[w] = old28_0;
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_36()
{
    if (is_legal_18_46_18_18_46_46_18_46_38())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_37()
{
    const auto old30_0 = board[coord];
    board[coord] = w;
    if (is_legal_18_46_18_18_46_46_18_46_34())
    {
        board[coord] = old30_0;
        return true;
    }
    board[coord] = old30_0;
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_38()
{
    if (is_legal_18_46_18_18_46_46_18_46_37())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_46()
{
    return true;
}

bool GameState::is_legal_18_46_18_18_46_46_18_46_47()
{
    if (is_legal_18_46_18_18_46_46_18_46_46())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_30_31_30()
{
    const auto old4_0 = coord;
    coord = direction_up[coord];
    if (is_legal_30_31_33())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_30_31_31()
{
    return true;
}

bool GameState::is_legal_30_31_32()
{
    if (is_legal_30_31_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_30_31_33()
{
    if (coord!=null)
    {
        if (is_legal_30_31_32())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_45()
{
    const auto old14_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_45_60_45_45_60_60_45_60_48())
    {
        coord = old14_0;
        return true;
    }    }
    coord = old14_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_48()
{
    if (board[coord]==b)
    {
        if (is_legal_45_60_45_45_60_60_45_60_49())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_49()
{
    const auto old16_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_45_60_45_45_60_60_45_60_51())
    {
        counters[board[coord]] = old16_0;
        return true;
    }
    counters[board[coord]] = old16_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_50()
{
    const auto old17_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (is_legal_45_60_45_45_60_60_45_60_56())
    {
        coord_temp = old17_0;
        return true;
    }    }
    coord_temp = old17_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_51()
{
    const auto old18_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_45_60_45_45_60_60_45_60_52())
    {
        counters[e] = old18_0;
        return true;
    }
    counters[e] = old18_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_52()
{
    if (is_legal_45_60_45_45_60_60_45_60_54())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_53()
{
    const auto old20_0 = board[coord];
    board[coord] = e;
    if (is_legal_45_60_45_45_60_60_45_60_50())
    {
        board[coord] = old20_0;
        return true;
    }
    board[coord] = old20_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_54()
{
    if (is_legal_45_60_45_45_60_60_45_60_53())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_55()
{
    if (board[coord]==e)
    {
        if (is_legal_45_60_45_45_60_60_45_60_58())
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_45_60_45_45_60_60_45_60_58())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_56()
{
    if (is_legal_45_60_45_45_60_60_45_60_57())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_57()
{
    const auto old25_0 = coord;
    coord = coord_temp;
    if (is_legal_45_60_45_45_60_60_45_60_55())
    {
        coord = old25_0;
        return true;
    }
    coord = old25_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_58()
{
    if (is_legal_45_60_45_45_60_60_45_60_61())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_60()
{
    return true;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_61()
{
    if (is_legal_45_60_45_45_60_60_45_60_60())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_10()
{
    const auto old14_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_4_19_4_4_19_19_4_19_11())
    {
        counters[e] = old14_0;
        return true;
    }
    counters[e] = old14_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_11()
{
    if (is_legal_4_19_4_4_19_19_4_19_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_12()
{
    const auto old16_0 = board[coord];
    board[coord] = e;
    if (is_legal_4_19_4_4_19_19_4_19_9())
    {
        board[coord] = old16_0;
        return true;
    }
    board[coord] = old16_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_13()
{
    if (is_legal_4_19_4_4_19_19_4_19_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_14()
{
    if (board[coord]==b)
    {
        if (is_legal_4_19_4_4_19_19_4_19_17())
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_4_19_4_4_19_19_4_19_17())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_15()
{
    if (is_legal_4_19_4_4_19_19_4_19_16())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_16()
{
    const auto old21_0 = coord;
    coord = coord_temp;
    if (is_legal_4_19_4_4_19_19_4_19_14())
    {
        coord = old21_0;
        return true;
    }
    coord = old21_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_17()
{
    if (is_legal_4_19_4_4_19_19_4_19_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_19()
{
    return true;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_20()
{
    if (is_legal_4_19_4_4_19_19_4_19_19())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_4()
{
    const auto old24_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_4_19_4_4_19_19_4_19_7())
    {
        coord = old24_0;
        return true;
    }    }
    coord = old24_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_7()
{
    if (board[coord]==w)
    {
        if (is_legal_4_19_4_4_19_19_4_19_8())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_8()
{
    const auto old26_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_4_19_4_4_19_19_4_19_10())
    {
        counters[board[coord]] = old26_0;
        return true;
    }
    counters[board[coord]] = old26_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_9()
{
    const auto old27_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (is_legal_4_19_4_4_19_19_4_19_15())
    {
        coord_temp = old27_0;
        return true;
    }    }
    coord_temp = old27_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_2()
{
    if (is_legal_59_5_59_59_5_5_59_5_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_3()
{
    if (is_legal_59_5_59_59_5_5_59_5_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_5()
{
    return true;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_59()
{
    const auto old21_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_59_5_59_59_5_5_59_5_63())
    {
        goals[black - 2] = old21_0;
        return true;
    }
    goals[black - 2] = old21_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_6()
{
    if (is_legal_59_5_59_59_5_5_59_5_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_62()
{
    const auto old23_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_59_5_59_59_5_5_59_5_66())
    {
        goals[white - 2] = old23_0;
        return true;
    }
    goals[white - 2] = old23_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_63()
{
    if (is_legal_59_5_59_59_5_5_59_5_64())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_64()
{
    if (is_legal_59_5_59_59_5_5_59_5_62())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_65()
{
    if (is_legal_71_72_71())
    {
        if (is_legal_59_5_59_59_5_5_59_5_70())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_66()
{
    if (is_legal_59_5_59_59_5_5_59_5_67())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_67()
{
    if (is_legal_59_5_59_59_5_5_59_5_65())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_68()
{
    if (is_legal_59_5_59_59_5_5_59_5_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_69()
{
    const auto old30_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_59_5_59_59_5_5_59_5_76())
    {
        counters[board[coord]] = old30_0;
        return true;
    }
    counters[board[coord]] = old30_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_70()
{
    if (is_legal_59_5_59_59_5_5_59_5_69())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_75()
{
    if (is_legal_59_5_59_59_5_5_59_5_68())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_76()
{
    const auto old33_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_59_5_59_59_5_5_59_5_77())
    {
        counters[b] = old33_0;
        return true;
    }
    counters[b] = old33_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_77()
{
    if (is_legal_59_5_59_59_5_5_59_5_79())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_78()
{
    const auto old35_0 = board[coord];
    board[coord] = b;
    if (is_legal_59_5_59_59_5_5_59_5_75())
    {
        board[coord] = old35_0;
        return true;
    }
    board[coord] = old35_0;
    return false;
}

bool GameState::is_legal_59_5_59_59_5_5_59_5_79()
{
    if (is_legal_59_5_59_59_5_5_59_5_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_59()
{
    const auto old11_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_59_83_59_59_83_83_59_83_63())
    {
        goals[black - 2] = old11_0;
        return true;
    }
    goals[black - 2] = old11_0;
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_62()
{
    const auto old12_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_59_83_59_59_83_83_59_83_66())
    {
        goals[white - 2] = old12_0;
        return true;
    }
    goals[white - 2] = old12_0;
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_63()
{
    if (is_legal_59_83_59_59_83_83_59_83_64())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_64()
{
    if (is_legal_59_83_59_59_83_83_59_83_62())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_65()
{
    if (!is_legal_71_72_71())
    {
        if (is_legal_59_83_59_59_83_83_59_83_81())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_66()
{
    if (is_legal_59_83_59_59_83_83_59_83_67())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_67()
{
    if (is_legal_59_83_59_59_83_83_59_83_65())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_80()
{
    if (is_legal_59_83_59_59_83_83_59_83_84())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_81()
{
    if (is_legal_59_83_59_59_83_83_59_83_80())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_83()
{
    return true;
}

bool GameState::is_legal_59_83_59_59_83_83_59_83_84()
{
    if (is_legal_59_83_59_59_83_83_59_83_83())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_71_72_71()
{
    const auto old4_0 = coord;
    coord = direction_down[coord];
    if (is_legal_71_72_74())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_71_72_72()
{
    return true;
}

bool GameState::is_legal_71_72_73()
{
    if (is_legal_71_72_72())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_71_72_74()
{
    if (coord!=null)
    {
        if (is_legal_71_72_73())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_86_87_86()
{
    if (is_legal_18_42_18_18_42_42_18_42_18())
    {
        if (is_legal_86_87_87())
        {
            return true;
        }
    }
    if (is_legal_18_46_18_18_46_46_18_46_18())
    {
        if (is_legal_86_87_87())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_86_87_87()
{
    return true;
}

bool GameState::is_legal_88_89_88()
{
    if (is_legal_59_5_59_59_5_5_59_5_59())
    {
        if (is_legal_88_89_89())
        {
            return true;
        }
    }
    if (is_legal_59_83_59_59_83_83_59_83_59())
    {
        if (is_legal_88_89_89())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_88_89_89()
{
    return true;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old182_0 = counters[e];
    counters[e] = counters[e]+1;
    state_11(moves, mr);
    counters[e] = old182_0;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(0 + coord);
    state_13(moves, mr);
    mr.pop_back();
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old184_0 = board[coord];
    board[coord] = e;
    state_9(moves, mr);
    board[coord] = old184_0;
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(65);
    state_12(moves, mr);
    mr.pop_back();
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==b)
    {
        state_17(moves, mr);
        return;
    }
    if (board[coord]==e)
    {
        state_17(moves, mr);
        return;
    }
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_16(moves, mr);
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old189_0 = coord;
    coord = coord_temp;
    state_14(moves, mr);
    coord = old189_0;
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(0 + coord);
    state_20(moves, mr);
    mr.pop_back();
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old191_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_22(moves, mr);
    goals[white - 2] = old191_0;
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_86_87_86())
    {
        state_92(moves, mr);
        return;
    }
    state_93(moves, mr);
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_6(moves, mr);
}

void GameState::state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(66);
    state_19(moves, mr);
    mr.pop_back();
}

void GameState::state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old220_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_25(moves, mr);
    goals[black - 2] = old220_0;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_23(moves, mr);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_21(moves, mr);
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_30_31_30())
    {
        state_29(moves, mr);
        return;
    }
    state_40(moves, mr);
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_26(moves, mr);
}

void GameState::state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_24(moves, mr);
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_47(moves, mr);
}

void GameState::state_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old228_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_35(moves, mr);
    counters[board[coord]] = old228_0;
}

void GameState::state_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_28(moves, mr);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_2(moves, mr);
}

void GameState::state_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_27(moves, mr);
}

void GameState::state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old235_0 = counters[w];
    counters[w] = counters[w]+1;
    state_36(moves, mr);
    counters[w] = old235_0;
}

void GameState::state_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_38(moves, mr);
}

void GameState::state_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old237_0 = board[coord];
    board[coord] = w;
    state_34(moves, mr);
    board[coord] = old237_0;
}

void GameState::state_38([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_37(moves, mr);
}

void GameState::state_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_43(moves, mr);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old240_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_7(moves, mr);    }
    coord = old240_0;
}

void GameState::state_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_39(moves, mr);
}

void GameState::state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_42(moves, mr);
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old245_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_48(moves, mr);    }
    coord = old245_0;
}

void GameState::state_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_45_60_45_45_60_60_45_60_45())
    {
        state_94(moves, mr);
        return;
    }
    state_95(moves, mr);
}

void GameState::state_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_46(moves, mr);
}

void GameState::state_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==b)
    {
        state_49(moves, mr);
    }
}

void GameState::state_49([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old262_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_51(moves, mr);
    counters[board[coord]] = old262_0;
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_4_19_4_4_19_19_4_19_4())
    {
        state_90(moves, mr);
        return;
    }
    state_91(moves, mr);
}

void GameState::state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old277_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    state_56(moves, mr);    }
    coord_temp = old277_0;
}

void GameState::state_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old278_0 = counters[e];
    counters[e] = counters[e]+1;
    state_52(moves, mr);
    counters[e] = old278_0;
}

void GameState::state_52([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(0 + coord);
    state_54(moves, mr);
    mr.pop_back();
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old280_0 = board[coord];
    board[coord] = e;
    state_50(moves, mr);
    board[coord] = old280_0;
}

void GameState::state_54([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(69);
    state_53(moves, mr);
    mr.pop_back();
}

void GameState::state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==e)
    {
        state_58(moves, mr);
        return;
    }
    if (board[coord]==w)
    {
        state_58(moves, mr);
        return;
    }
}

void GameState::state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_57(moves, mr);
}

void GameState::state_57([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old285_0 = coord;
    coord = coord_temp;
    state_55(moves, mr);
    coord = old285_0;
}

void GameState::state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(0 + coord);
    state_61(moves, mr);
    mr.pop_back();
}

void GameState::state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old287_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_63(moves, mr);
    goals[black - 2] = old287_0;
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_5(moves, mr);
}

void GameState::state_60([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_88_89_88())
    {
        state_96(moves, mr);
        return;
    }
    state_97(moves, mr);
}

void GameState::state_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr.emplace_back(70);
    state_60(moves, mr);
    mr.pop_back();
}

void GameState::state_62([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old318_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_66(moves, mr);
    goals[white - 2] = old318_0;
}

void GameState::state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_64(moves, mr);
}

void GameState::state_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_62(moves, mr);
}

void GameState::state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (is_legal_71_72_71())
    {
        state_70(moves, mr);
        return;
    }
    state_81(moves, mr);
}

void GameState::state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_67(moves, mr);
}

void GameState::state_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_65(moves, mr);
}

void GameState::state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_3(moves, mr);
}

void GameState::state_69([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old326_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_76(moves, mr);
    counters[board[coord]] = old326_0;
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==w)
    {
        state_8(moves, mr);
    }
}

void GameState::state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_69(moves, mr);
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_68(moves, mr);
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old333_0 = counters[b];
    counters[b] = counters[b]+1;
    state_77(moves, mr);
    counters[b] = old333_0;
}

void GameState::state_77([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_79(moves, mr);
}

void GameState::state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old335_0 = board[coord];
    board[coord] = b;
    state_75(moves, mr);
    board[coord] = old335_0;
}

void GameState::state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_78(moves, mr);
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old337_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_10(moves, mr);
    counters[board[coord]] = old337_0;
}

void GameState::state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_84(moves, mr);
}

void GameState::state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_80(moves, mr);
}

void GameState::state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_83(moves, mr);
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old347_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    state_15(moves, mr);    }
    coord_temp = old347_0;
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_97([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    state_2(moves, mr);
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
}

bool GameState::apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old182_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_11(mr,rgCache))
    {
        return true;
    }
    counters[e] = old182_0;
    return false;
}

bool GameState::apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_13(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old184_0 = board[coord];
    board[coord] = e;
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    board[coord] = old184_0;
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
    {
        rgCache.currentMrId++;
        if (apply_state_12(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==e)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_16(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old189_0 = coord;
    coord = coord_temp;
    if (apply_state_14(mr,rgCache))
    {
        return true;
    }
    coord = old189_0;
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_20(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old191_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old191_0;
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_87_86())
    {
        if (apply_state_92(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_93(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_6(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 66:
{
                return apply_state_19(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_0(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 66)
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

bool GameState::apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old220_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_25(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old220_0;
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_23(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_30_31_30())
    {
        if (apply_state_29(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_40(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_26(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_24(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_47(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old228_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_35(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old228_0;
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

bool GameState::apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_27(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old235_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_36(mr,rgCache))
    {
        return true;
    }
    counters[w] = old235_0;
    return false;
}

bool GameState::apply_state_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_38(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_37([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old237_0 = board[coord];
    board[coord] = w;
    if (apply_state_34(mr,rgCache))
    {
        return true;
    }
    board[coord] = old237_0;
    return false;
}

bool GameState::apply_state_38([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_37(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_43(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old240_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (apply_state_7(mr,rgCache))
    {
        return true;
    }    }
    coord = old240_0;
    return false;
}

bool GameState::apply_state_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_39(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old242_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old242_0;
    return false;
}

bool GameState::apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_42(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old245_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (apply_state_48(mr,rgCache))
    {
        return true;
    }    }
    coord = old245_0;
    return false;
}

bool GameState::apply_state_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_45_60_45_45_60_60_45_60_45())
    {
        if (apply_state_94(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_95(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_46(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_48([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_49(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_49([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old262_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_51(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old262_0;
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_state_90(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_91(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old277_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (apply_state_56(mr,rgCache))
    {
        return true;
    }    }
    coord_temp = old277_0;
    return false;
}

bool GameState::apply_state_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old278_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_52(mr,rgCache))
    {
        return true;
    }
    counters[e] = old278_0;
    return false;
}

bool GameState::apply_state_52([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_54(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old280_0 = board[coord];
    board[coord] = e;
    if (apply_state_50(mr,rgCache))
    {
        return true;
    }
    board[coord] = old280_0;
    return false;
}

bool GameState::apply_state_54([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 69)
    {
        rgCache.currentMrId++;
        if (apply_state_53(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_58(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_58(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_57(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_57([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old285_0 = coord;
    coord = coord_temp;
    if (apply_state_55(mr,rgCache))
    {
        return true;
    }
    coord = old285_0;
    return false;
}

bool GameState::apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_61(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old287_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_63(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old287_0;
    return false;
}

bool GameState::apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_5(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_60([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_88_89_88())
    {
        if (apply_state_96(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_97(mr,rgCache))
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
            case 70:
{
                return apply_state_60(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_1(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 70)
    {
        rgCache.currentMrId++;
        if (apply_state_60(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_62([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old318_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_66(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old318_0;
    return false;
}

bool GameState::apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_64(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_64([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_62(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_71_72_71())
    {
        if (apply_state_70(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_81(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_67(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_67([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_65(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_69([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old326_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_76(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old326_0;
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (apply_state_8(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_70([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_69(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_68(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old333_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_77(mr,rgCache))
    {
        return true;
    }
    counters[b] = old333_0;
    return false;
}

bool GameState::apply_state_77([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_79(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old335_0 = board[coord];
    board[coord] = b;
    if (apply_state_75(mr,rgCache))
    {
        return true;
    }
    board[coord] = old335_0;
    return false;
}

bool GameState::apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_78(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old337_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_10(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old337_0;
    return false;
}

bool GameState::apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_84(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_80(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_83([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old340_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old340_0;
    return false;
}

bool GameState::apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_83(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old347_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }    }
    coord_temp = old347_0;
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old350_0 = player;
    player = white;
    currentState = 61;
    return true;
    player = old350_0;
    return false;
}

bool GameState::apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old352_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old352_0;
    return false;
}

bool GameState::apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old354_0 = player;
    player = keeper;
    currentState = 9;
    return true;
    player = old354_0;
    return false;
}

bool GameState::apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old356_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old356_0;
    return false;
}

bool GameState::apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old358_0 = player;
    player = black;
    currentState = 66;
    return true;
    player = old358_0;
    return false;
}

bool GameState::apply_state_95([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old360_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old360_0;
    return false;
}

bool GameState::apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old362_0 = player;
    player = keeper;
    currentState = 109;
    return true;
    player = old362_0;
    return false;
}

bool GameState::apply_state_97([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old364_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    player = old364_0;
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_2(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_18_18_18()
{
    const auto old25_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_18_18_22())
    {
        return true;
    }
    goals[white - 2] = old25_0;
    return false;
}

bool GameState::apply_any_18_18_21()
{
    const auto old26_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_18_18_25())
    {
        return true;
    }
    goals[black - 2] = old26_0;
    return false;
}

bool GameState::apply_any_18_18_22()
{
    if (apply_any_18_18_23())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_23()
{
    if (apply_any_18_18_21())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_24()
{
    if (is_legal_30_31_30())
    {
        if (apply_any_18_18_29())
        {
            return true;
        }
        return false;
    }
    if (apply_any_18_18_40())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_25()
{
    if (apply_any_18_18_26())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_26()
{
    if (apply_any_18_18_24())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_27()
{
    if (apply_any_18_18_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_28()
{
    const auto old34_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_18_18_35())
    {
        return true;
    }
    counters[board[coord]] = old34_0;
    return false;
}

bool GameState::apply_any_18_18_29()
{
    if (apply_any_18_18_28())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_34()
{
    if (apply_any_18_18_27())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_35()
{
    const auto old37_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_18_18_36())
    {
        return true;
    }
    counters[w] = old37_0;
    return false;
}

bool GameState::apply_any_18_18_36()
{
    if (apply_any_18_18_38())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_37()
{
    const auto old39_0 = board[coord];
    board[coord] = w;
    if (apply_any_18_18_34())
    {
        return true;
    }
    board[coord] = old39_0;
    return false;
}

bool GameState::apply_any_18_18_38()
{
    if (apply_any_18_18_37())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_39()
{
    if (apply_any_18_18_43())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_40()
{
    if (apply_any_18_18_39())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_42()
{
    const auto old43_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    if (apply_any_18_18_end())
    {
        return true;
    }
    player = old43_0;
    return false;
}

bool GameState::apply_any_18_18_43()
{
    if (apply_any_18_18_42())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_45()
{
    return true;
}

bool GameState::apply_any_18_18_46()
{
    if (is_legal_45_60_45_45_60_60_45_60_45())
    {
        if (apply_any_18_18_94())
        {
            return true;
        }
        return false;
    }
    if (apply_any_18_18_95())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_47()
{
    if (apply_any_18_18_46())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_94()
{
    const auto old47_0 = player;
    player = black;
    currentState = 66;
    return true;
    if (apply_any_18_18_45())
    {
        return true;
    }
    player = old47_0;
    return false;
}

bool GameState::apply_any_18_18_95()
{
    const auto old49_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    if (apply_any_18_18_end())
    {
        return true;
    }
    player = old49_0;
    return false;
}

bool GameState::apply_any_18_18_end()
{
    return true;
}

bool GameState::apply_any_59_59_2()
{
    if (apply_any_59_59_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_3()
{
    if (apply_any_59_59_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_4()
{
    return true;
}

bool GameState::apply_any_59_59_5()
{
    if (is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_any_59_59_90())
        {
            return true;
        }
        return false;
    }
    if (apply_any_59_59_91())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_59()
{
    const auto old29_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_59_59_63())
    {
        return true;
    }
    goals[black - 2] = old29_0;
    return false;
}

bool GameState::apply_any_59_59_6()
{
    if (apply_any_59_59_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_62()
{
    const auto old31_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_59_59_66())
    {
        return true;
    }
    goals[white - 2] = old31_0;
    return false;
}

bool GameState::apply_any_59_59_63()
{
    if (apply_any_59_59_64())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_64()
{
    if (apply_any_59_59_62())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_65()
{
    if (is_legal_71_72_71())
    {
        if (apply_any_59_59_70())
        {
            return true;
        }
        return false;
    }
    if (apply_any_59_59_81())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_66()
{
    if (apply_any_59_59_67())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_67()
{
    if (apply_any_59_59_65())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_68()
{
    if (apply_any_59_59_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_69()
{
    const auto old39_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_59_59_76())
    {
        return true;
    }
    counters[board[coord]] = old39_0;
    return false;
}

bool GameState::apply_any_59_59_70()
{
    if (apply_any_59_59_69())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_75()
{
    if (apply_any_59_59_68())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_76()
{
    const auto old42_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_59_59_77())
    {
        return true;
    }
    counters[b] = old42_0;
    return false;
}

bool GameState::apply_any_59_59_77()
{
    if (apply_any_59_59_79())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_78()
{
    const auto old44_0 = board[coord];
    board[coord] = b;
    if (apply_any_59_59_75())
    {
        return true;
    }
    board[coord] = old44_0;
    return false;
}

bool GameState::apply_any_59_59_79()
{
    if (apply_any_59_59_78())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_80()
{
    if (apply_any_59_59_84())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_81()
{
    if (apply_any_59_59_80())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_83()
{
    const auto old48_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    if (apply_any_59_59_end())
    {
        return true;
    }
    player = old48_0;
    return false;
}

bool GameState::apply_any_59_59_84()
{
    if (apply_any_59_59_83())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_90()
{
    const auto old51_0 = player;
    player = white;
    currentState = 61;
    return true;
    if (apply_any_59_59_4())
    {
        return true;
    }
    player = old51_0;
    return false;
}

bool GameState::apply_any_59_59_91()
{
    const auto old53_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    if (apply_any_59_59_end())
    {
        return true;
    }
    player = old53_0;
    return false;
}

bool GameState::apply_any_59_59_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_2()
{
    if (apply_any_begin_begin_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_4()
{
    return true;
}

bool GameState::apply_any_begin_begin_5()
{
    if (is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_any_begin_begin_90())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_91())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_6()
{
    if (apply_any_begin_begin_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_90()
{
    const auto old12_0 = player;
    player = white;
    currentState = 61;
    return true;
    if (apply_any_begin_begin_4())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_91()
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 182;
    return true;
    if (apply_any_begin_begin_end())
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_begin_begin_begin()
{
    if (apply_any_begin_begin_2())
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
