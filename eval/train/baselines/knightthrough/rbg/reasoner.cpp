#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.coord_temp) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.coord_temp) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && coord==rhs.coord && coord_temp==rhs.coord_temp && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx7y0: " << board[rx7y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx7y1: " << board[rx7y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx7y2: " << board[rx7y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx0y7: " << board[rx0y7] << ", " << "rx1y7: " << board[rx1y7] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx7y7: " << board[rx7y7]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
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
        case 16:
{
            state_45(moves, mr.mr);
            return;
}
        case 15:
{
            state_4(moves, mr.mr);
            return;
}
        case 50:
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
        case 16:
{
            apply_state_45(mr.mr,rgCache);
            return;
}
        case 15:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 50:
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
        case 7:
{
            apply_any_18_18_18();
            break;
}
        case 41:
{
            apply_any_59_59_59();
            break;
}
        case 50:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_45()
{
    const auto old8_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_45_60_45_45_60_60_45_60_48())
    {
        coord = old8_0;
        return true;
    }    }
    coord = old8_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_48()
{
    if (board[coord]==b)
    {
        if (is_legal_45_60_45_45_60_60_45_60_54())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_50()
{
    const auto old10_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (is_legal_45_60_45_45_60_60_45_60_56())
    {
        coord_temp = old10_0;
        return true;
    }    }
    coord_temp = old10_0;
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_53()
{
    const auto old11_0 = board[coord];
    board[coord] = e;
    if (is_legal_45_60_45_45_60_60_45_60_50())
    {
        board[coord] = old11_0;
        return true;
    }
    board[coord] = old11_0;
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
    if (board[coord_temp]==e)
    {
        if (is_legal_45_60_45_45_60_60_45_60_60())
        {
            return true;
        }
        return false;
    }
    if (board[coord_temp]==w)
    {
        if (is_legal_45_60_45_45_60_60_45_60_60())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_56()
{
    if (is_legal_45_60_45_45_60_60_45_60_55())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_45_60_45_45_60_60_45_60_60()
{
    return true;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_12()
{
    const auto old8_0 = board[coord];
    board[coord] = e;
    if (is_legal_4_19_4_4_19_19_4_19_9())
    {
        board[coord] = old8_0;
        return true;
    }
    board[coord] = old8_0;
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
    if (board[coord_temp]==b)
    {
        if (is_legal_4_19_4_4_19_19_4_19_19())
        {
            return true;
        }
        return false;
    }
    if (board[coord_temp]==e)
    {
        if (is_legal_4_19_4_4_19_19_4_19_19())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_15()
{
    if (is_legal_4_19_4_4_19_19_4_19_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_19()
{
    return true;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_4()
{
    const auto old13_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_4_19_4_4_19_19_4_19_7())
    {
        coord = old13_0;
        return true;
    }    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_7()
{
    if (board[coord]==w)
    {
        if (is_legal_4_19_4_4_19_19_4_19_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_19_4_4_19_19_4_19_9()
{
    const auto old15_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (is_legal_4_19_4_4_19_19_4_19_15())
    {
        coord_temp = old15_0;
        return true;
    }    }
    coord_temp = old15_0;
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + coord;
    state_12(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old52_0 = board[coord];
    board[coord] = e;
    state_9(moves, mr);
    board[coord] = old52_0;
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
    const auto old56_0 = coord;
    coord = coord_temp;
    state_14(moves, mr);
    coord = old56_0;
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 0 + coord;
    state_19(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old58_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_22(moves, mr);
    goals[white - 2] = old58_0;
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_4_19_4_4_19_19_4_19_4())
    {
        state_39(moves, mr);
        return;
    }
    state_90(moves, mr);
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old59_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_25(moves, mr);
    goals[black - 2] = old59_0;
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (direction_up[coord]!=null)
    {
        state_35(moves, mr);
        return;
    }
    state_39(moves, mr);
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (!is_legal_45_60_45_45_60_60_45_60_45())
    {
        state_39(moves, mr);
        return;
    }
    state_94(moves, mr);
}

void GameState::state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old60_0 = board[coord];
    board[coord] = w;
    state_27(moves, mr);
    board[coord] = old60_0;
}

void GameState::state_39([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old61_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_7(moves, mr);    }
    coord = old61_0;
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old63_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_48(moves, mr);    }
    coord = old63_0;
}

void GameState::state_48([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==b)
    {
        state_51(moves, mr);
    }
}

void GameState::state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old81_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    state_56(moves, mr);    }
    coord_temp = old81_0;
}

void GameState::state_51([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[0] = 0 + coord;
    state_53(moves, mr);
    mr[0] = unusedTag;
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old83_0 = board[coord];
    board[coord] = e;
    state_50(moves, mr);
    board[coord] = old83_0;
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
    const auto old87_0 = coord;
    coord = coord_temp;
    state_55(moves, mr);
    coord = old87_0;
}

void GameState::state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    mr[1] = 0 + coord;
    state_60(moves, mr);
    mr[1] = unusedTag;
}

void GameState::state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old89_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_63(moves, mr);
    goals[black - 2] = old89_0;
}

void GameState::state_60([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old90_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_66(moves, mr);
    goals[white - 2] = old90_0;
}

void GameState::state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (direction_down[coord]==null)
    {
        state_39(moves, mr);
        return;
    }
    state_76(moves, mr);
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    if (board[coord]==w)
    {
        state_10(moves, mr);
    }
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old92_0 = board[coord];
    board[coord] = b;
    state_2(moves, mr);
    board[coord] = old92_0;
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    const auto old93_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    state_15(moves, mr);    }
    coord_temp = old93_0;
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
{
    moves.emplace_back(mr);
}

void GameState::state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr)
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
    if (mr[0] == 0 + coord)
    {
        if (apply_state_12(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old52_0 = board[coord];
    board[coord] = e;
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    board[coord] = old52_0;
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
    const auto old56_0 = coord;
    coord = coord_temp;
    if (apply_state_14(mr,rgCache))
    {
        return true;
    }
    coord = old56_0;
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 0 + coord)
    {
        if (apply_state_19(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old58_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old58_0;
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = player;
    player = keeper;
    currentState = 7;
    return true;
    player = old97_0;
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_state_39(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_90(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old59_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_25(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old59_0;
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_up[coord]!=null)
    {
        if (apply_state_35(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_39(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_45_60_45_45_60_60_45_60_45())
    {
        if (apply_state_39(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_94(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old60_0 = board[coord];
    board[coord] = w;
    if (apply_state_27(mr,rgCache))
    {
        return true;
    }
    board[coord] = old60_0;
    return false;
}

bool GameState::apply_state_39([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old62_0 = player;
    player = keeper;
    currentState = 51;
    return true;
    player = old62_0;
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old61_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (apply_state_7(mr,rgCache))
    {
        return true;
    }    }
    coord = old61_0;
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old63_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (apply_state_48(mr,rgCache))
    {
        return true;
    }    }
    coord = old63_0;
    return false;
}

bool GameState::apply_state_48([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_51(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old81_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap2iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (apply_state_56(mr,rgCache))
    {
        return true;
    }    }
    coord_temp = old81_0;
    return false;
}

bool GameState::apply_state_51([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_53(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old83_0 = board[coord];
    board[coord] = e;
    if (apply_state_50(mr,rgCache))
    {
        return true;
    }
    board[coord] = old83_0;
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
    const auto old87_0 = coord;
    coord = coord_temp;
    if (apply_state_55(mr,rgCache))
    {
        return true;
    }
    coord = old87_0;
    return false;
}

bool GameState::apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 0 + coord)
    {
        if (apply_state_60(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old89_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_63(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old89_0;
    return false;
}

bool GameState::apply_state_60([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = player;
    player = keeper;
    currentState = 41;
    return true;
    player = old100_0;
    return false;
}

bool GameState::apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_66(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old90_0;
    return false;
}

bool GameState::apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_down[coord]==null)
    {
        if (apply_state_39(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_76(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (apply_state_10(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = board[coord];
    board[coord] = b;
    if (apply_state_2(mr,rgCache))
    {
        return true;
    }
    board[coord] = old92_0;
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old93_0 = coord_temp;
    for (const auto& coord_tempIt : ReachableMap1iter[coord - 1])
    {
    coord_temp = coord_tempIt;
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }    }
    coord_temp = old93_0;
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = player;
    player = white;
    currentState = 15;
    return true;
    player = old96_0;
    return false;
}

bool GameState::apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old99_0 = player;
    player = black;
    currentState = 16;
    return true;
    player = old99_0;
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
    const auto old9_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_18_18_22())
    {
        return true;
    }
    goals[white - 2] = old9_0;
    return false;
}

bool GameState::apply_any_18_18_22()
{
    const auto old10_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_18_18_25())
    {
        return true;
    }
    goals[black - 2] = old10_0;
    return false;
}

bool GameState::apply_any_18_18_25()
{
    if (direction_up[coord]!=null)
    {
        if (apply_any_18_18_35())
        {
            return true;
        }
        return false;
    }
    if (apply_any_18_18_39())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_27()
{
    if (!is_legal_45_60_45_45_60_60_45_60_45())
    {
        if (apply_any_18_18_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_18_18_94())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_18_18_35()
{
    const auto old11_0 = board[coord];
    board[coord] = w;
    if (apply_any_18_18_27())
    {
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::apply_any_18_18_39()
{
    const auto old12_0 = player;
    player = keeper;
    currentState = 51;
    return true;
    if (apply_any_18_18_end())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_18_18_45()
{
    return true;
}

bool GameState::apply_any_18_18_94()
{
    const auto old14_0 = player;
    player = black;
    currentState = 16;
    return true;
    if (apply_any_18_18_45())
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_18_18_end()
{
    return true;
}

bool GameState::apply_any_59_59_2()
{
    if (!is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_any_59_59_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_59_59_90())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_39()
{
    const auto old9_0 = player;
    player = keeper;
    currentState = 51;
    return true;
    if (apply_any_59_59_end())
    {
        return true;
    }
    player = old9_0;
    return false;
}

bool GameState::apply_any_59_59_4()
{
    return true;
}

bool GameState::apply_any_59_59_59()
{
    const auto old10_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_59_59_63())
    {
        return true;
    }
    goals[black - 2] = old10_0;
    return false;
}

bool GameState::apply_any_59_59_63()
{
    const auto old11_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_59_59_66())
    {
        return true;
    }
    goals[white - 2] = old11_0;
    return false;
}

bool GameState::apply_any_59_59_66()
{
    if (direction_down[coord]==null)
    {
        if (apply_any_59_59_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_59_59_76())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_59_59_76()
{
    const auto old12_0 = board[coord];
    board[coord] = b;
    if (apply_any_59_59_2())
    {
        return true;
    }
    board[coord] = old12_0;
    return false;
}

bool GameState::apply_any_59_59_90()
{
    const auto old14_0 = player;
    player = white;
    currentState = 15;
    return true;
    if (apply_any_59_59_4())
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_59_59_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_2()
{
    if (!is_legal_4_19_4_4_19_19_4_19_4())
    {
        if (apply_any_begin_begin_39())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_90())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_39()
{
    const auto old6_0 = player;
    player = keeper;
    currentState = 51;
    return true;
    if (apply_any_begin_begin_end())
    {
        return true;
    }
    player = old6_0;
    return false;
}

bool GameState::apply_any_begin_begin_4()
{
    return true;
}

bool GameState::apply_any_begin_begin_90()
{
    const auto old9_0 = player;
    player = white;
    currentState = 15;
    return true;
    if (apply_any_begin_begin_4())
    {
        return true;
    }
    player = old9_0;
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
