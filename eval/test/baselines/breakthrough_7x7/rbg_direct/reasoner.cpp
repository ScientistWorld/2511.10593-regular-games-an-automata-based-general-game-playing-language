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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
    ss << "counters = " << "{" << "b: " << counters[b] << ", " << "e: " << counters[e] << ", " << "w: " << counters[w]<< "}" << std::endl;
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
        case 111:
{
            state_53(moves, mr.mr,rgCache);
            return;
}
        case 75:
{
            state_4(moves, mr.mr,rgCache);
            return;
}
        case 213:
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
        case 111:
{
            apply_state_53(mr.mr,rgCache);
            return;
}
        case 75:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 213:
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
        case 32:
{
            apply_any_26_26_26();
            break;
}
        case 157:
{
            apply_any_75_75_75();
            break;
}
        case 213:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_102_103_102()
{
    if (is_legal_26_50_26_26_50_50_26_50_26())
    {
        if (is_legal_102_103_103())
        {
            return true;
        }
    }
    if (is_legal_26_54_26_26_54_54_26_54_26())
    {
        if (is_legal_102_103_103())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_102_103_103()
{
    return true;
}

bool GameState::is_legal_104_105_104()
{
    if (is_legal_75_5_75_75_5_5_75_5_75())
    {
        if (is_legal_104_105_105())
        {
            return true;
        }
    }
    if (is_legal_75_99_75_75_99_99_75_99_75())
    {
        if (is_legal_104_105_105())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_104_105_105()
{
    return true;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_26()
{
    const auto old11_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_26_50_26_26_50_50_26_50_30())
    {
        goals[white - 2] = old11_0;
        return true;
    }
    goals[white - 2] = old11_0;
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_29()
{
    const auto old12_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_26_50_26_26_50_50_26_50_33())
    {
        goals[black - 2] = old12_0;
        return true;
    }
    goals[black - 2] = old12_0;
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_30()
{
    if (is_legal_26_50_26_26_50_50_26_50_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_31()
{
    if (is_legal_26_50_26_26_50_50_26_50_29())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_32()
{
    if (!is_legal_38_39_38())
    {
        if (is_legal_26_50_26_26_50_50_26_50_48())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_33()
{
    if (is_legal_26_50_26_26_50_50_26_50_34())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_34()
{
    if (is_legal_26_50_26_26_50_50_26_50_32())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_47()
{
    if (is_legal_26_50_26_26_50_50_26_50_51())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_48()
{
    if (is_legal_26_50_26_26_50_50_26_50_47())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_50()
{
    return true;
}

bool GameState::is_legal_26_50_26_26_50_50_26_50_51()
{
    if (is_legal_26_50_26_26_50_50_26_50_50())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_26()
{
    const auto old17_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_26_54_26_26_54_54_26_54_30())
    {
        goals[white - 2] = old17_0;
        return true;
    }
    goals[white - 2] = old17_0;
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_29()
{
    const auto old18_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_26_54_26_26_54_54_26_54_33())
    {
        goals[black - 2] = old18_0;
        return true;
    }
    goals[black - 2] = old18_0;
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_30()
{
    if (is_legal_26_54_26_26_54_54_26_54_31())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_31()
{
    if (is_legal_26_54_26_26_54_54_26_54_29())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_32()
{
    if (is_legal_38_39_38())
    {
        if (is_legal_26_54_26_26_54_54_26_54_37())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_33()
{
    if (is_legal_26_54_26_26_54_54_26_54_34())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_34()
{
    if (is_legal_26_54_26_26_54_54_26_54_32())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_35()
{
    if (is_legal_26_54_26_26_54_54_26_54_55())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_36()
{
    const auto old25_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_26_54_26_26_54_54_26_54_43())
    {
        counters[board[coord]] = old25_0;
        return true;
    }
    counters[board[coord]] = old25_0;
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_37()
{
    if (is_legal_26_54_26_26_54_54_26_54_36())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_42()
{
    if (is_legal_26_54_26_26_54_54_26_54_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_43()
{
    const auto old28_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_26_54_26_26_54_54_26_54_44())
    {
        counters[w] = old28_0;
        return true;
    }
    counters[w] = old28_0;
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_44()
{
    if (is_legal_26_54_26_26_54_54_26_54_46())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_45()
{
    const auto old30_0 = board[coord];
    board[coord] = w;
    if (is_legal_26_54_26_26_54_54_26_54_42())
    {
        board[coord] = old30_0;
        return true;
    }
    board[coord] = old30_0;
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_46()
{
    if (is_legal_26_54_26_26_54_54_26_54_45())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_54()
{
    return true;
}

bool GameState::is_legal_26_54_26_26_54_54_26_54_55()
{
    if (is_legal_26_54_26_26_54_54_26_54_54())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_38_39_38()
{
    const auto old4_0 = coord;
    coord = direction_up[coord];
    if (is_legal_38_39_41())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_38_39_39()
{
    return true;
}

bool GameState::is_legal_38_39_40()
{
    if (is_legal_38_39_39())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_38_39_41()
{
    if (coord!=null)
    {
        if (is_legal_38_39_40())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_10()
{
    const auto old22_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_4_27_4_4_27_27_4_27_11())
    {
        counters[e] = old22_0;
        return true;
    }
    counters[e] = old22_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_11()
{
    if (is_legal_4_27_4_4_27_27_4_27_13())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_12()
{
    const auto old24_0 = board[coord];
    board[coord] = e;
    if (is_legal_4_27_4_4_27_27_4_27_9())
    {
        board[coord] = old24_0;
        return true;
    }
    board[coord] = old24_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_13()
{
    if (is_legal_4_27_4_4_27_27_4_27_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_14()
{
    if (board[coord]==e)
    {
        if (is_legal_4_27_4_4_27_27_4_27_18())
        {
            return true;
        }
    }
    const auto old27_0 = coord;
    coord = direction_left[coord];
    if (is_legal_4_27_4_4_27_27_4_27_22())
    {
        coord = old27_0;
        return true;
    }
    coord = old27_0;
    const auto old28_0 = coord;
    coord = direction_right[coord];
    if (is_legal_4_27_4_4_27_27_4_27_24())
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_15()
{
    if (is_legal_4_27_4_4_27_27_4_27_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_16()
{
    if (coord!=null)
    {
        if (is_legal_4_27_4_4_27_27_4_27_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_17()
{
    if (is_legal_4_27_4_4_27_27_4_27_28())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_18()
{
    if (is_legal_4_27_4_4_27_27_4_27_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_19()
{
    if (board[coord]==b)
    {
        if (is_legal_4_27_4_4_27_27_4_27_25())
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_4_27_4_4_27_27_4_27_25())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_20()
{
    if (is_legal_4_27_4_4_27_27_4_27_19())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_21()
{
    if (is_legal_4_27_4_4_27_27_4_27_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_22()
{
    if (coord!=null)
    {
        if (is_legal_4_27_4_4_27_27_4_27_21())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_23()
{
    if (is_legal_4_27_4_4_27_27_4_27_20())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_24()
{
    if (coord!=null)
    {
        if (is_legal_4_27_4_4_27_27_4_27_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_25()
{
    if (is_legal_4_27_4_4_27_27_4_27_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_27()
{
    return true;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_28()
{
    if (is_legal_4_27_4_4_27_27_4_27_27())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_4()
{
    const auto old42_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    if (is_legal_4_27_4_4_27_27_4_27_7())
    {
        coord = old42_0;
        return true;
    }    }
    coord = old42_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_7()
{
    if (board[coord]==w)
    {
        if (is_legal_4_27_4_4_27_27_4_27_8())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_8()
{
    const auto old44_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_4_27_4_4_27_27_4_27_10())
    {
        counters[board[coord]] = old44_0;
        return true;
    }
    counters[board[coord]] = old44_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_9()
{
    const auto old45_0 = coord;
    coord = direction_up[coord];
    if (is_legal_4_27_4_4_27_27_4_27_16())
    {
        coord = old45_0;
        return true;
    }
    coord = old45_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_53()
{
    const auto old22_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    if (is_legal_53_76_53_53_76_76_53_76_56())
    {
        coord = old22_0;
        return true;
    }    }
    coord = old22_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_56()
{
    if (board[coord]==b)
    {
        if (is_legal_53_76_53_53_76_76_53_76_57())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_57()
{
    const auto old24_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_53_76_53_53_76_76_53_76_59())
    {
        counters[board[coord]] = old24_0;
        return true;
    }
    counters[board[coord]] = old24_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_58()
{
    const auto old25_0 = coord;
    coord = direction_down[coord];
    if (is_legal_53_76_53_53_76_76_53_76_65())
    {
        coord = old25_0;
        return true;
    }
    coord = old25_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_59()
{
    const auto old26_0 = counters[e];
    counters[e] = counters[e]+1;
    if (is_legal_53_76_53_53_76_76_53_76_60())
    {
        counters[e] = old26_0;
        return true;
    }
    counters[e] = old26_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_60()
{
    if (is_legal_53_76_53_53_76_76_53_76_62())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_61()
{
    const auto old28_0 = board[coord];
    board[coord] = e;
    if (is_legal_53_76_53_53_76_76_53_76_58())
    {
        board[coord] = old28_0;
        return true;
    }
    board[coord] = old28_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_62()
{
    if (is_legal_53_76_53_53_76_76_53_76_61())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_63()
{
    if (board[coord]==e)
    {
        if (is_legal_53_76_53_53_76_76_53_76_67())
        {
            return true;
        }
    }
    const auto old31_0 = coord;
    coord = direction_left[coord];
    if (is_legal_53_76_53_53_76_76_53_76_71())
    {
        coord = old31_0;
        return true;
    }
    coord = old31_0;
    const auto old32_0 = coord;
    coord = direction_right[coord];
    if (is_legal_53_76_53_53_76_76_53_76_73())
    {
        coord = old32_0;
        return true;
    }
    coord = old32_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_64()
{
    if (is_legal_53_76_53_53_76_76_53_76_63())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_65()
{
    if (coord!=null)
    {
        if (is_legal_53_76_53_53_76_76_53_76_64())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_66()
{
    if (is_legal_53_76_53_53_76_76_53_76_77())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_67()
{
    if (is_legal_53_76_53_53_76_76_53_76_66())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_68()
{
    if (board[coord]==e)
    {
        if (is_legal_53_76_53_53_76_76_53_76_74())
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_53_76_53_53_76_76_53_76_74())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_69()
{
    if (is_legal_53_76_53_53_76_76_53_76_68())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_70()
{
    if (is_legal_53_76_53_53_76_76_53_76_69())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_71()
{
    if (coord!=null)
    {
        if (is_legal_53_76_53_53_76_76_53_76_70())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_72()
{
    if (is_legal_53_76_53_53_76_76_53_76_69())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_73()
{
    if (coord!=null)
    {
        if (is_legal_53_76_53_53_76_76_53_76_72())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_74()
{
    if (is_legal_53_76_53_53_76_76_53_76_66())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_76()
{
    return true;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_77()
{
    if (is_legal_53_76_53_53_76_76_53_76_76())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_2()
{
    if (is_legal_75_5_75_75_5_5_75_5_6())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_3()
{
    if (is_legal_75_5_75_75_5_5_75_5_2())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_5()
{
    return true;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_6()
{
    if (is_legal_75_5_75_75_5_5_75_5_5())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_75()
{
    const auto old22_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_75_5_75_75_5_5_75_5_79())
    {
        goals[black - 2] = old22_0;
        return true;
    }
    goals[black - 2] = old22_0;
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_78()
{
    const auto old23_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_75_5_75_75_5_5_75_5_82())
    {
        goals[white - 2] = old23_0;
        return true;
    }
    goals[white - 2] = old23_0;
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_79()
{
    if (is_legal_75_5_75_75_5_5_75_5_80())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_80()
{
    if (is_legal_75_5_75_75_5_5_75_5_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_81()
{
    if (is_legal_87_88_87())
    {
        if (is_legal_75_5_75_75_5_5_75_5_86())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_82()
{
    if (is_legal_75_5_75_75_5_5_75_5_83())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_83()
{
    if (is_legal_75_5_75_75_5_5_75_5_81())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_84()
{
    if (is_legal_75_5_75_75_5_5_75_5_3())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_85()
{
    const auto old30_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_75_5_75_75_5_5_75_5_92())
    {
        counters[board[coord]] = old30_0;
        return true;
    }
    counters[board[coord]] = old30_0;
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_86()
{
    if (is_legal_75_5_75_75_5_5_75_5_85())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_91()
{
    if (is_legal_75_5_75_75_5_5_75_5_84())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_92()
{
    const auto old33_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_75_5_75_75_5_5_75_5_93())
    {
        counters[b] = old33_0;
        return true;
    }
    counters[b] = old33_0;
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_93()
{
    if (is_legal_75_5_75_75_5_5_75_5_95())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_94()
{
    const auto old35_0 = board[coord];
    board[coord] = b;
    if (is_legal_75_5_75_75_5_5_75_5_91())
    {
        board[coord] = old35_0;
        return true;
    }
    board[coord] = old35_0;
    return false;
}

bool GameState::is_legal_75_5_75_75_5_5_75_5_95()
{
    if (is_legal_75_5_75_75_5_5_75_5_94())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_100()
{
    if (is_legal_75_99_75_75_99_99_75_99_99())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_75()
{
    const auto old12_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_75_99_75_75_99_99_75_99_79())
    {
        goals[black - 2] = old12_0;
        return true;
    }
    goals[black - 2] = old12_0;
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_78()
{
    const auto old13_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_75_99_75_75_99_99_75_99_82())
    {
        goals[white - 2] = old13_0;
        return true;
    }
    goals[white - 2] = old13_0;
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_79()
{
    if (is_legal_75_99_75_75_99_99_75_99_80())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_80()
{
    if (is_legal_75_99_75_75_99_99_75_99_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_81()
{
    if (!is_legal_87_88_87())
    {
        if (is_legal_75_99_75_75_99_99_75_99_97())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_82()
{
    if (is_legal_75_99_75_75_99_99_75_99_83())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_83()
{
    if (is_legal_75_99_75_75_99_99_75_99_81())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_96()
{
    if (is_legal_75_99_75_75_99_99_75_99_100())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_97()
{
    if (is_legal_75_99_75_75_99_99_75_99_96())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_99_75_75_99_99_75_99_99()
{
    return true;
}

bool GameState::is_legal_87_88_87()
{
    const auto old4_0 = coord;
    coord = direction_down[coord];
    if (is_legal_87_88_90())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_87_88_88()
{
    return true;
}

bool GameState::is_legal_87_88_89()
{
    if (is_legal_87_88_88())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_87_88_90()
{
    if (coord!=null)
    {
        if (is_legal_87_88_89())
        {
            return true;
        }
    }
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old214_0 = counters[e];
    counters[e] = counters[e]+1;
    state_11(moves, mr,rgCache);
    counters[e] = old214_0;
}

void GameState::state_100([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_99(moves, mr,rgCache);
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
    mr.emplace_back(0 + coord);
    state_13(moves, mr,rgCache);
    mr.pop_back();
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

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old222_0 = board[coord];
    board[coord] = e;
    state_9(moves, mr,rgCache);
    board[coord] = old222_0;
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(50);
    rgCache.state_cache_20.reset();
    state_12(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_18(moves, mr,rgCache);
    }
    const auto old225_0 = coord;
    coord = direction_left[coord];
    state_22(moves, mr,rgCache);
    coord = old225_0;
    const auto old226_0 = coord;
    coord = direction_right[coord];
    state_24(moves, mr,rgCache);
    coord = old226_0;
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_14(moves, mr,rgCache);
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_15(moves, mr,rgCache);
    }
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_28(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_17(moves, mr,rgCache);
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        state_25(moves, mr,rgCache);
        return;
    }
    if (board[coord]==e)
    {
        state_25(moves, mr,rgCache);
        return;
    }
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_6(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_20;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_19(moves, mr,rgCache);
}

void GameState::state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_20(moves, mr,rgCache);
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_21(moves, mr,rgCache);
    }
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_20(moves, mr,rgCache);
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_23(moves, mr,rgCache);
    }
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_17(moves, mr,rgCache);
}

void GameState::state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old240_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_30(moves, mr,rgCache);
    goals[white - 2] = old240_0;
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_102_103_102())
    {
        state_108(moves, mr,rgCache);
        return;
    }
    state_109(moves, mr,rgCache);
}

void GameState::state_28([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(51);
    state_27(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_29([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old268_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_33(moves, mr,rgCache);
    goals[black - 2] = old268_0;
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_2(moves, mr,rgCache);
}

void GameState::state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_31(moves, mr,rgCache);
}

void GameState::state_31([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_29(moves, mr,rgCache);
}

void GameState::state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_38_39_38())
    {
        state_37(moves, mr,rgCache);
        return;
    }
    state_48(moves, mr,rgCache);
}

void GameState::state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_34(moves, mr,rgCache);
}

void GameState::state_34([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_32(moves, mr,rgCache);
}

void GameState::state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_55(moves, mr,rgCache);
}

void GameState::state_36([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old277_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_43(moves, mr,rgCache);
    counters[board[coord]] = old277_0;
}

void GameState::state_37([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_36(moves, mr,rgCache);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old280_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    state_7(moves, mr,rgCache);    }
    coord = old280_0;
}

void GameState::state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_35(moves, mr,rgCache);
}

void GameState::state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old284_0 = counters[w];
    counters[w] = counters[w]+1;
    state_44(moves, mr,rgCache);
    counters[w] = old284_0;
}

void GameState::state_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_46(moves, mr,rgCache);
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old286_0 = board[coord];
    board[coord] = w;
    state_42(moves, mr,rgCache);
    board[coord] = old286_0;
}

void GameState::state_46([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_45(moves, mr,rgCache);
}

void GameState::state_47([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_51(moves, mr,rgCache);
}

void GameState::state_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_47(moves, mr,rgCache);
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_27_4_4_27_27_4_27_4())
    {
        state_106(moves, mr,rgCache);
        return;
    }
    state_107(moves, mr,rgCache);
}

void GameState::state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_50(moves, mr,rgCache);
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old317_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    state_56(moves, mr,rgCache);    }
    coord = old317_0;
}

void GameState::state_54([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_53_76_53_53_76_76_53_76_53())
    {
        state_110(moves, mr,rgCache);
        return;
    }
    state_111(moves, mr,rgCache);
}

void GameState::state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_54(moves, mr,rgCache);
}

void GameState::state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        state_57(moves, mr,rgCache);
    }
}

void GameState::state_57([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old344_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_59(moves, mr,rgCache);
    counters[board[coord]] = old344_0;
}

void GameState::state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old345_0 = coord;
    coord = direction_down[coord];
    state_65(moves, mr,rgCache);
    coord = old345_0;
}

void GameState::state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old346_0 = counters[e];
    counters[e] = counters[e]+1;
    state_60(moves, mr,rgCache);
    counters[e] = old346_0;
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(54);
    state_5(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_60([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_62(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old349_0 = board[coord];
    board[coord] = e;
    state_58(moves, mr,rgCache);
    board[coord] = old349_0;
}

void GameState::state_62([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(55);
    rgCache.state_cache_69.reset();
    state_61(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_67(moves, mr,rgCache);
    }
    const auto old352_0 = coord;
    coord = direction_left[coord];
    state_71(moves, mr,rgCache);
    coord = old352_0;
    const auto old353_0 = coord;
    coord = direction_right[coord];
    state_73(moves, mr,rgCache);
    coord = old353_0;
}

void GameState::state_64([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_63(moves, mr,rgCache);
}

void GameState::state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_64(moves, mr,rgCache);
    }
}

void GameState::state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0 + coord);
    state_77(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_67([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_66(moves, mr,rgCache);
}

void GameState::state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_74(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_74(moves, mr,rgCache);
        return;
    }
}

void GameState::state_69([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_69;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_68(moves, mr,rgCache);
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        state_8(moves, mr,rgCache);
    }
}

void GameState::state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_69(moves, mr,rgCache);
}

void GameState::state_71([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_70(moves, mr,rgCache);
    }
}

void GameState::state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_69(moves, mr,rgCache);
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_72(moves, mr,rgCache);
    }
}

void GameState::state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_66(moves, mr,rgCache);
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old367_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_79(moves, mr,rgCache);
    goals[black - 2] = old367_0;
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_104_105_104())
    {
        state_112(moves, mr,rgCache);
        return;
    }
    state_113(moves, mr,rgCache);
}

void GameState::state_77([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(56);
    state_76(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old397_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_82(moves, mr,rgCache);
    goals[white - 2] = old397_0;
}

void GameState::state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_80(moves, mr,rgCache);
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old399_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_10(moves, mr,rgCache);
    counters[board[coord]] = old399_0;
}

void GameState::state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_78(moves, mr,rgCache);
}

void GameState::state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_87_88_87())
    {
        state_86(moves, mr,rgCache);
        return;
    }
    state_97(moves, mr,rgCache);
}

void GameState::state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_83(moves, mr,rgCache);
}

void GameState::state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_81(moves, mr,rgCache);
}

void GameState::state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_3(moves, mr,rgCache);
}

void GameState::state_85([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old406_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_92(moves, mr,rgCache);
    counters[board[coord]] = old406_0;
}

void GameState::state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_85(moves, mr,rgCache);
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old410_0 = coord;
    coord = direction_up[coord];
    state_16(moves, mr,rgCache);
    coord = old410_0;
}

void GameState::state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_84(moves, mr,rgCache);
}

void GameState::state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old413_0 = counters[b];
    counters[b] = counters[b]+1;
    state_93(moves, mr,rgCache);
    counters[b] = old413_0;
}

void GameState::state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_95(moves, mr,rgCache);
}

void GameState::state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old415_0 = board[coord];
    board[coord] = b;
    state_91(moves, mr,rgCache);
    board[coord] = old415_0;
}

void GameState::state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_94(moves, mr,rgCache);
}

void GameState::state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_100(moves, mr,rgCache);
}

void GameState::state_97([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_96(moves, mr,rgCache);
}

void GameState::state_99([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_2(moves, mr,rgCache);
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old214_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_11(mr,rgCache))
    {
        return true;
    }
    counters[e] = old214_0;
    return false;
}

bool GameState::apply_state_100([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_99(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_106([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old422_0 = player;
    player = white;
    currentState = 75;
    return true;
    player = old422_0;
    return false;
}

bool GameState::apply_state_107([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old424_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old424_0;
    return false;
}

bool GameState::apply_state_108([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old426_0 = player;
    player = keeper;
    currentState = 32;
    return true;
    player = old426_0;
    return false;
}

bool GameState::apply_state_109([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old428_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old428_0;
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

bool GameState::apply_state_110([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old430_0 = player;
    player = black;
    currentState = 111;
    return true;
    player = old430_0;
    return false;
}

bool GameState::apply_state_111([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old432_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old432_0;
    return false;
}

bool GameState::apply_state_112([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old434_0 = player;
    player = keeper;
    currentState = 157;
    return true;
    player = old434_0;
    return false;
}

bool GameState::apply_state_113([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old436_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old436_0;
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old222_0 = board[coord];
    board[coord] = e;
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    board[coord] = old222_0;
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 50:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 0 ... 49:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 51:
{
                                        board[coord] = e;
                                        coord = mr[rgCache.currentMrId - 2] - 0;
                                        return apply_state_27(mr,rgCache);
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

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_0(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 50)
    {
        rgCache.currentMrId++;
        rgCache.state_cache_20.reset();
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
    if (board[coord]==e)
    {
        if (apply_state_18(mr,rgCache))
        {
            return true;
        }
    }
    const auto old225_0 = coord;
    coord = direction_left[coord];
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    coord = old225_0;
    const auto old226_0 = coord;
    coord = direction_right[coord];
    if (apply_state_24(mr,rgCache))
    {
        return true;
    }
    coord = old226_0;
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_14(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_15(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_28(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_17(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_25(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==e)
    {
        if (apply_state_25(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_6(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_20;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_19(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_21(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_23(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_17(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old240_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_30(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old240_0;
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_102_103_102())
    {
        if (apply_state_108(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_109(mr,rgCache))
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
                return apply_state_27(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_28([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_1(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 51)
    {
        rgCache.currentMrId++;
        if (apply_state_27(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_29([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old268_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_33(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old268_0;
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

bool GameState::apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_31(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_31([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_29(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_38_39_38())
    {
        if (apply_state_37(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_48(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_34(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_34([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_32(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_55(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_36([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old277_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_43(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old277_0;
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

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
                                    return apply_state_27(mr,rgCache);
                            }
                            break;
                    }
                    break;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_35(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old284_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_44(mr,rgCache))
    {
        return true;
    }
    counters[w] = old284_0;
    return false;
}

bool GameState::apply_state_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_46(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old286_0 = board[coord];
    board[coord] = w;
    if (apply_state_42(mr,rgCache))
    {
        return true;
    }
    board[coord] = old286_0;
    return false;
}

bool GameState::apply_state_46([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_45(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_47([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_51(mr,rgCache))
    {
        return true;
    }
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

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_state_106(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_107(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old314_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old314_0;
    return false;
}

bool GameState::apply_state_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_50(mr,rgCache))
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
                                    return apply_state_76(mr,rgCache);
                            }
                            break;
                    }
                    break;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_54([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_53_76_53_53_76_76_53_76_53())
    {
        if (apply_state_110(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_111(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_54(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_57(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_57([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old344_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_59(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old344_0;
    return false;
}

bool GameState::apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old345_0 = coord;
    coord = direction_down[coord];
    if (apply_state_65(mr,rgCache))
    {
        return true;
    }
    coord = old345_0;
    return false;
}

bool GameState::apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old346_0 = counters[e];
    counters[e] = counters[e]+1;
    if (apply_state_60(mr,rgCache))
    {
        return true;
    }
    counters[e] = old346_0;
    return false;
}

bool GameState::switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 54:
{
                return apply_state_5(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_4(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 54)
    {
        rgCache.currentMrId++;
        if (apply_state_5(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_60([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_62(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old349_0 = board[coord];
    board[coord] = e;
    if (apply_state_58(mr,rgCache))
    {
        return true;
    }
    board[coord] = old349_0;
    return false;
}

bool GameState::switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
                        case 0 ... 49:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 56:
{
                                        board[coord] = e;
                                        coord = mr[rgCache.currentMrId - 2] - 0;
                                        return apply_state_76(mr,rgCache);
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

bool GameState::apply_state_62([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_5(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 55)
    {
        rgCache.currentMrId++;
        rgCache.state_cache_69.reset();
        if (apply_state_61(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_67(mr,rgCache))
        {
            return true;
        }
    }
    const auto old352_0 = coord;
    coord = direction_left[coord];
    if (apply_state_71(mr,rgCache))
    {
        return true;
    }
    coord = old352_0;
    const auto old353_0 = coord;
    coord = direction_right[coord];
    if (apply_state_73(mr,rgCache))
    {
        return true;
    }
    coord = old353_0;
    return false;
}

bool GameState::apply_state_64([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_63(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_64(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_77(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_67([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_66(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_74(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_74(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_69([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_69;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_68(mr,rgCache))
    {
        return true;
    }
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

bool GameState::apply_state_71([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_70(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_69(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_72(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_66(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            default:
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        default:
                            goals[black - 2] = 100;
                            goals[white - 2] = 0;
                            counters[board[coord]] = counters[board[coord]]-1;
                            counters[b] = counters[b]+1;
                            board[coord] = b;
                            return apply_state_5(mr,rgCache);
                    }
                }
                break;
        }
    }
    if (mr.size()!=rgCache.currentMrId)
    {
        return false;
    }
    goals[black - 2] = 100;
    goals[white - 2] = 0;
    player = keeper;
    currentState = 214;
    return true;
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_6(mr ,rgCache);
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_104_105_104())
    {
        if (apply_state_112(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_113(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 56:
{
                return apply_state_76(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_77([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_7(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 56)
    {
        rgCache.currentMrId++;
        if (apply_state_76(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old397_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_82(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old397_0;
    return false;
}

bool GameState::apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_80(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old399_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_10(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old399_0;
    return false;
}

bool GameState::apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_78(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_87_88_87())
    {
        if (apply_state_86(mr,rgCache))
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

bool GameState::apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_83(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_83([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_81(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_84([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_3(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_85([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old406_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_92(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old406_0;
    return false;
}

bool GameState::apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_85(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old410_0 = coord;
    coord = direction_up[coord];
    if (apply_state_16(mr,rgCache))
    {
        return true;
    }
    coord = old410_0;
    return false;
}

bool GameState::apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_84(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old413_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_93(mr,rgCache))
    {
        return true;
    }
    counters[b] = old413_0;
    return false;
}

bool GameState::apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_95(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old415_0 = board[coord];
    board[coord] = b;
    if (apply_state_91(mr,rgCache))
    {
        return true;
    }
    board[coord] = old415_0;
    return false;
}

bool GameState::apply_state_95([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_94(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_100(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_97([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_96(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_99([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old419_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    player = old419_0;
    return false;
}

bool GameState::switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    return apply_state_5(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_8(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_26_26_110()
{
    const auto old47_0 = player;
    player = black;
    currentState = 111;
    return true;
    if (apply_any_26_26_53())
    {
        return true;
    }
    player = old47_0;
    return false;
}

bool GameState::apply_any_26_26_111()
{
    const auto old49_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    if (apply_any_26_26_end())
    {
        return true;
    }
    player = old49_0;
    return false;
}

bool GameState::apply_any_26_26_26()
{
    const auto old25_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_26_26_30())
    {
        return true;
    }
    goals[white - 2] = old25_0;
    return false;
}

bool GameState::apply_any_26_26_29()
{
    const auto old26_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_26_26_33())
    {
        return true;
    }
    goals[black - 2] = old26_0;
    return false;
}

bool GameState::apply_any_26_26_30()
{
    if (apply_any_26_26_31())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_31()
{
    if (apply_any_26_26_29())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_32()
{
    if (is_legal_38_39_38())
    {
        if (apply_any_26_26_37())
        {
            return true;
        }
        return false;
    }
    if (apply_any_26_26_48())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_33()
{
    if (apply_any_26_26_34())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_34()
{
    if (apply_any_26_26_32())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_35()
{
    if (apply_any_26_26_55())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_36()
{
    const auto old34_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_26_26_43())
    {
        return true;
    }
    counters[board[coord]] = old34_0;
    return false;
}

bool GameState::apply_any_26_26_37()
{
    if (apply_any_26_26_36())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_42()
{
    if (apply_any_26_26_35())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_43()
{
    const auto old37_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_26_26_44())
    {
        return true;
    }
    counters[w] = old37_0;
    return false;
}

bool GameState::apply_any_26_26_44()
{
    if (apply_any_26_26_46())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_45()
{
    const auto old39_0 = board[coord];
    board[coord] = w;
    if (apply_any_26_26_42())
    {
        return true;
    }
    board[coord] = old39_0;
    return false;
}

bool GameState::apply_any_26_26_46()
{
    if (apply_any_26_26_45())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_47()
{
    if (apply_any_26_26_51())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_48()
{
    if (apply_any_26_26_47())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_50()
{
    const auto old43_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    if (apply_any_26_26_end())
    {
        return true;
    }
    player = old43_0;
    return false;
}

bool GameState::apply_any_26_26_51()
{
    if (apply_any_26_26_50())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_53()
{
    return true;
}

bool GameState::apply_any_26_26_54()
{
    if (is_legal_53_76_53_53_76_76_53_76_53())
    {
        if (apply_any_26_26_110())
        {
            return true;
        }
        return false;
    }
    if (apply_any_26_26_111())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_55()
{
    if (apply_any_26_26_54())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_end()
{
    return true;
}

bool GameState::apply_any_75_75_100()
{
    if (apply_any_75_75_99())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_106()
{
    const auto old51_0 = player;
    player = white;
    currentState = 75;
    return true;
    if (apply_any_75_75_4())
    {
        return true;
    }
    player = old51_0;
    return false;
}

bool GameState::apply_any_75_75_107()
{
    const auto old53_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    if (apply_any_75_75_end())
    {
        return true;
    }
    player = old53_0;
    return false;
}

bool GameState::apply_any_75_75_2()
{
    if (apply_any_75_75_6())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_3()
{
    if (apply_any_75_75_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_4()
{
    return true;
}

bool GameState::apply_any_75_75_5()
{
    if (is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_any_75_75_106())
        {
            return true;
        }
        return false;
    }
    if (apply_any_75_75_107())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_6()
{
    if (apply_any_75_75_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_75()
{
    const auto old31_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_75_75_79())
    {
        return true;
    }
    goals[black - 2] = old31_0;
    return false;
}

bool GameState::apply_any_75_75_78()
{
    const auto old32_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_75_75_82())
    {
        return true;
    }
    goals[white - 2] = old32_0;
    return false;
}

bool GameState::apply_any_75_75_79()
{
    if (apply_any_75_75_80())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_80()
{
    if (apply_any_75_75_78())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_81()
{
    if (is_legal_87_88_87())
    {
        if (apply_any_75_75_86())
        {
            return true;
        }
        return false;
    }
    if (apply_any_75_75_97())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_82()
{
    if (apply_any_75_75_83())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_83()
{
    if (apply_any_75_75_81())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_84()
{
    if (apply_any_75_75_3())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_85()
{
    const auto old40_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_75_75_92())
    {
        return true;
    }
    counters[board[coord]] = old40_0;
    return false;
}

bool GameState::apply_any_75_75_86()
{
    if (apply_any_75_75_85())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_91()
{
    if (apply_any_75_75_84())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_92()
{
    const auto old43_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_75_75_93())
    {
        return true;
    }
    counters[b] = old43_0;
    return false;
}

bool GameState::apply_any_75_75_93()
{
    if (apply_any_75_75_95())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_94()
{
    const auto old45_0 = board[coord];
    board[coord] = b;
    if (apply_any_75_75_91())
    {
        return true;
    }
    board[coord] = old45_0;
    return false;
}

bool GameState::apply_any_75_75_95()
{
    if (apply_any_75_75_94())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_96()
{
    if (apply_any_75_75_100())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_97()
{
    if (apply_any_75_75_96())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_99()
{
    const auto old49_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    if (apply_any_75_75_end())
    {
        return true;
    }
    player = old49_0;
    return false;
}

bool GameState::apply_any_75_75_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_106()
{
    const auto old12_0 = player;
    player = white;
    currentState = 75;
    return true;
    if (apply_any_begin_begin_4())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_107()
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 214;
    return true;
    if (apply_any_begin_begin_end())
    {
        return true;
    }
    player = old14_0;
    return false;
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
    if (is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_any_begin_begin_106())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_107())
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
