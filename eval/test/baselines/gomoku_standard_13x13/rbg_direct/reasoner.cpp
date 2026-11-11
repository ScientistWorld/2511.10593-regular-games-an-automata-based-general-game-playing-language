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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx7y0: " << board[rx7y0] << ", " << "rx8y0: " << board[rx8y0] << ", " << "rx9y0: " << board[rx9y0] << ", " << "rx10y0: " << board[rx10y0] << ", " << "rx11y0: " << board[rx11y0] << ", " << "rx12y0: " << board[rx12y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx7y1: " << board[rx7y1] << ", " << "rx8y1: " << board[rx8y1] << ", " << "rx9y1: " << board[rx9y1] << ", " << "rx10y1: " << board[rx10y1] << ", " << "rx11y1: " << board[rx11y1] << ", " << "rx12y1: " << board[rx12y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx7y2: " << board[rx7y2] << ", " << "rx8y2: " << board[rx8y2] << ", " << "rx9y2: " << board[rx9y2] << ", " << "rx10y2: " << board[rx10y2] << ", " << "rx11y2: " << board[rx11y2] << ", " << "rx12y2: " << board[rx12y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx8y3: " << board[rx8y3] << ", " << "rx9y3: " << board[rx9y3] << ", " << "rx10y3: " << board[rx10y3] << ", " << "rx11y3: " << board[rx11y3] << ", " << "rx12y3: " << board[rx12y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx8y4: " << board[rx8y4] << ", " << "rx9y4: " << board[rx9y4] << ", " << "rx10y4: " << board[rx10y4] << ", " << "rx11y4: " << board[rx11y4] << ", " << "rx12y4: " << board[rx12y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx8y5: " << board[rx8y5] << ", " << "rx9y5: " << board[rx9y5] << ", " << "rx10y5: " << board[rx10y5] << ", " << "rx11y5: " << board[rx11y5] << ", " << "rx12y5: " << board[rx12y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx8y6: " << board[rx8y6] << ", " << "rx9y6: " << board[rx9y6] << ", " << "rx10y6: " << board[rx10y6] << ", " << "rx11y6: " << board[rx11y6] << ", " << "rx12y6: " << board[rx12y6] << ", " << "rx0y7: " << board[rx0y7] << ", " << "rx1y7: " << board[rx1y7] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx7y7: " << board[rx7y7] << ", " << "rx8y7: " << board[rx8y7] << ", " << "rx9y7: " << board[rx9y7] << ", " << "rx10y7: " << board[rx10y7] << ", " << "rx11y7: " << board[rx11y7] << ", " << "rx12y7: " << board[rx12y7] << ", " << "rx0y8: " << board[rx0y8] << ", " << "rx1y8: " << board[rx1y8] << ", " << "rx2y8: " << board[rx2y8] << ", " << "rx3y8: " << board[rx3y8] << ", " << "rx4y8: " << board[rx4y8] << ", " << "rx5y8: " << board[rx5y8] << ", " << "rx6y8: " << board[rx6y8] << ", " << "rx7y8: " << board[rx7y8] << ", " << "rx8y8: " << board[rx8y8] << ", " << "rx9y8: " << board[rx9y8] << ", " << "rx10y8: " << board[rx10y8] << ", " << "rx11y8: " << board[rx11y8] << ", " << "rx12y8: " << board[rx12y8] << ", " << "rx0y9: " << board[rx0y9] << ", " << "rx1y9: " << board[rx1y9] << ", " << "rx2y9: " << board[rx2y9] << ", " << "rx3y9: " << board[rx3y9] << ", " << "rx4y9: " << board[rx4y9] << ", " << "rx5y9: " << board[rx5y9] << ", " << "rx6y9: " << board[rx6y9] << ", " << "rx7y9: " << board[rx7y9] << ", " << "rx8y9: " << board[rx8y9] << ", " << "rx9y9: " << board[rx9y9] << ", " << "rx10y9: " << board[rx10y9] << ", " << "rx11y9: " << board[rx11y9] << ", " << "rx12y9: " << board[rx12y9] << ", " << "rx0y10: " << board[rx0y10] << ", " << "rx1y10: " << board[rx1y10] << ", " << "rx2y10: " << board[rx2y10] << ", " << "rx3y10: " << board[rx3y10] << ", " << "rx4y10: " << board[rx4y10] << ", " << "rx5y10: " << board[rx5y10] << ", " << "rx6y10: " << board[rx6y10] << ", " << "rx7y10: " << board[rx7y10] << ", " << "rx8y10: " << board[rx8y10] << ", " << "rx9y10: " << board[rx9y10] << ", " << "rx10y10: " << board[rx10y10] << ", " << "rx11y10: " << board[rx11y10] << ", " << "rx12y10: " << board[rx12y10] << ", " << "rx0y11: " << board[rx0y11] << ", " << "rx1y11: " << board[rx1y11] << ", " << "rx2y11: " << board[rx2y11] << ", " << "rx3y11: " << board[rx3y11] << ", " << "rx4y11: " << board[rx4y11] << ", " << "rx5y11: " << board[rx5y11] << ", " << "rx6y11: " << board[rx6y11] << ", " << "rx7y11: " << board[rx7y11] << ", " << "rx8y11: " << board[rx8y11] << ", " << "rx9y11: " << board[rx9y11] << ", " << "rx10y11: " << board[rx10y11] << ", " << "rx11y11: " << board[rx11y11] << ", " << "rx12y11: " << board[rx12y11] << ", " << "rx0y12: " << board[rx0y12] << ", " << "rx1y12: " << board[rx1y12] << ", " << "rx2y12: " << board[rx2y12] << ", " << "rx3y12: " << board[rx3y12] << ", " << "rx4y12: " << board[rx4y12] << ", " << "rx5y12: " << board[rx5y12] << ", " << "rx6y12: " << board[rx6y12] << ", " << "rx7y12: " << board[rx7y12] << ", " << "rx8y12: " << board[rx8y12] << ", " << "rx9y12: " << board[rx9y12] << ", " << "rx10y12: " << board[rx10y12] << ", " << "rx11y12: " << board[rx11y12] << ", " << "rx12y12: " << board[rx12y12]<< "}" << std::endl;
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
        case 111:
{
            state_172(moves, mr.mr,rgCache);
            return;
}
        case 2:
{
            state_10(moves, mr.mr,rgCache);
            return;
}
        case 405:
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
            apply_state_172(mr.mr,rgCache);
            return;
}
        case 2:
{
            apply_state_10(mr.mr,rgCache);
            return;
}
        case 405:
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
        case 62:
{
            apply_any_15_15_15(rgCache);
            break;
}
        case 121:
{
            apply_any_177_177_177(rgCache);
            break;
}
        case 405:
{
            apply_any_begin_begin_begin(rgCache);
            break;
}
    }
}

bool GameState::is_legal_101_102_101()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_101_102_104())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_101_102_102()
{
    return true;
}

bool GameState::is_legal_101_102_103()
{
    if (board[coord]==w)
    {
        if (is_legal_101_102_105())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_101_102_104()
{
    if (is_legal_101_102_103())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_101_102_105()
{
    if (is_legal_101_102_102())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_10()
{
    const auto old5_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    if (is_legal_10_16_10_10_16_16_10_16_13())
    {
        coord = old5_0;
        return true;
    }    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_13()
{
    if (board[coord]==e)
    {
        if (is_legal_10_16_10_10_16_16_10_16_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_14()
{
    if (is_legal_10_16_10_10_16_16_10_16_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_16()
{
    return true;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_17()
{
    if (is_legal_10_16_10_10_16_16_10_16_16())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_119_120_119()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_119_120_122())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_119_120_120()
{
    return true;
}

bool GameState::is_legal_119_120_121()
{
    if (board[coord]==w)
    {
        if (is_legal_119_120_123())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_119_120_122()
{
    if (is_legal_119_120_121())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_119_120_123()
{
    if (is_legal_119_120_120())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_132_133_132()
{
    const auto old6_0 = coord;
    coord = direction_left[coord];
    if (is_legal_132_133_136())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_132_133_133()
{
    return true;
}

bool GameState::is_legal_132_133_134()
{
    if (board[coord]==w)
    {
        if (is_legal_132_133_137())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_132_133_135()
{
    if (is_legal_132_133_134())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_132_133_136()
{
    if (is_legal_132_133_135())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_132_133_137()
{
    if (is_legal_132_133_133())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_155_156_155()
{
    const auto old6_0 = coord;
    coord = direction_right[coord];
    if (is_legal_155_156_159())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_155_156_156()
{
    return true;
}

bool GameState::is_legal_155_156_157()
{
    if (board[coord]==w)
    {
        if (is_legal_155_156_160())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_155_156_158()
{
    if (is_legal_155_156_157())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_155_156_159()
{
    if (is_legal_155_156_158())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_155_156_160()
{
    if (is_legal_155_156_156())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_15_169_15_15_169_169_15_169_19(rgCache))
    {
        counters[board[coord]] = old15_0;
        return true;
    }
    counters[board[coord]] = old15_0;
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_161([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_15_169_15_15_169_169_15_169_163(rgCache))
    {
        goals[white - 2] = old16_0;
        return true;
    }
    goals[white - 2] = old16_0;
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_15_169_15_15_169_169_15_169_166(rgCache))
    {
        goals[black - 2] = old17_0;
        return true;
    }
    goals[black - 2] = old17_0;
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_163([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_164([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_165([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_170(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_166([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_167([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_165(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_169([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_170([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_169(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_98.reset();
    const auto result_24 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_24)
    {
        if (is_legal_15_169_15_15_169_169_15_169_161(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_15_169_15_15_169_169_15_169_20(rgCache))
    {
        counters[w] = old25_0;
        return true;
    }
    counters[w] = old25_0;
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old27_0 = board[coord];
    board[coord] = w;
    if (is_legal_15_169_15_15_169_169_15_169_18(rgCache))
    {
        board[coord] = old27_0;
        return true;
    }
    board[coord] = old27_0;
    return false;
}

bool GameState::is_legal_15_169_15_15_169_169_15_169_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_15_173_15_15_173_173_15_173_19(rgCache))
    {
        counters[board[coord]] = old10_0;
        return true;
    }
    counters[board[coord]] = old10_0;
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_173([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_174([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_173_15_15_173_173_15_173_173(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_98.reset();
    const auto result_12 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_12)
    {
        if (is_legal_15_173_15_15_173_173_15_173_24(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_15_173_15_15_173_173_15_173_20(rgCache))
    {
        counters[w] = old13_0;
        return true;
    }
    counters[w] = old13_0;
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_173_15_15_173_173_15_173_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = w;
    if (is_legal_15_173_15_15_173_173_15_173_18(rgCache))
    {
        board[coord] = old15_0;
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_173_15_15_173_173_15_173_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_23([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_173_15_15_173_173_15_173_174(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_173_15_15_173_173_15_173_24([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_173_15_15_173_173_15_173_23(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_172()
{
    const auto old5_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    if (is_legal_172_178_172_172_178_178_172_178_175())
    {
        coord = old5_0;
        return true;
    }    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_175()
{
    if (board[coord]==e)
    {
        if (is_legal_172_178_172_172_178_178_172_178_176())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_176()
{
    if (is_legal_172_178_172_172_178_178_172_178_179())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_178()
{
    return true;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_179()
{
    if (is_legal_172_178_172_172_178_178_172_178_178())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_11([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_12([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_177([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_177_11_177_177_11_11_177_11_181(rgCache))
    {
        counters[board[coord]] = old13_0;
        return true;
    }
    counters[board[coord]] = old13_0;
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_180([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_193.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_260.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_14 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (!result_14)
    {
        if (is_legal_177_11_177_177_11_11_177_11_186(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_181([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_177_11_177_177_11_11_177_11_182(rgCache))
    {
        counters[b] = old15_0;
        return true;
    }
    counters[b] = old15_0;
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_182([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_184(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_183([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = board[coord];
    board[coord] = b;
    if (is_legal_177_11_177_177_11_11_177_11_180(rgCache))
    {
        board[coord] = old17_0;
        return true;
    }
    board[coord] = old17_0;
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_184([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_183(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_185([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_186([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_185(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_8([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_11_177_177_11_11_177_11_9([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_177([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_177_331_177_177_331_331_177_331_181(rgCache))
    {
        counters[board[coord]] = old15_0;
        return true;
    }
    counters[board[coord]] = old15_0;
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_180([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_193.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_260.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_16 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (result_16)
    {
        if (is_legal_177_331_177_177_331_331_177_331_323(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_181([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_177_331_177_177_331_331_177_331_182(rgCache))
    {
        counters[b] = old17_0;
        return true;
    }
    counters[b] = old17_0;
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_182([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_184(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_183([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = board[coord];
    board[coord] = b;
    if (is_legal_177_331_177_177_331_331_177_331_180(rgCache))
    {
        board[coord] = old19_0;
        return true;
    }
    board[coord] = old19_0;
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_184([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_183(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_323([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_177_331_177_177_331_331_177_331_325(rgCache))
    {
        goals[black - 2] = old21_0;
        return true;
    }
    goals[black - 2] = old21_0;
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_324([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_177_331_177_177_331_331_177_331_328(rgCache))
    {
        goals[white - 2] = old22_0;
        return true;
    }
    goals[white - 2] = old22_0;
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_325([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_326(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_326([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_324(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_327([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_332(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_328([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_329(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_329([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_327(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_331([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_177_331_177_177_331_331_177_331_332([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_331_177_177_331_331_177_331_331(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_187([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_189(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_190(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_219(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_220(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_256(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_257(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_286(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_287(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_188([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_187_188_189([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_196_197_196())
    {
        if (is_legal_187_188_195(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_190([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old101_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_187_188_193(rgCache))
    {
        coord = old101_0;
        return true;
    }
    coord = old101_0;
    return false;
}

bool GameState::is_legal_187_188_191([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_189(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_190(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_192([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_194(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_193([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_193;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_187_188_192(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_194([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_191(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_195([[maybe_unused]]RgCache& rgCache)
{
    const auto old107_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_187_188_202(rgCache))
    {
        coord = old107_0;
        return true;
    }
    coord = old107_0;
    return false;
}

bool GameState::is_legal_187_188_201([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_203(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_202([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_201(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_203([[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_187_188_205(rgCache))
    {
        coord = old110_0;
        return true;
    }
    coord = old110_0;
    return false;
}

bool GameState::is_legal_187_188_204([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_206(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_205([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_204(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_206([[maybe_unused]]RgCache& rgCache)
{
    const auto old113_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_187_188_208(rgCache))
    {
        coord = old113_0;
        return true;
    }
    coord = old113_0;
    return false;
}

bool GameState::is_legal_187_188_207([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_209(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_208([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_207(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_209([[maybe_unused]]RgCache& rgCache)
{
    const auto old116_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_187_188_211(rgCache))
    {
        coord = old116_0;
        return true;
    }
    coord = old116_0;
    return false;
}

bool GameState::is_legal_187_188_210([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_212(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_211([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_210(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_212([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_214_215_214())
    {
        if (is_legal_187_188_213(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_213([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_188(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_219([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_227_228_227())
    {
        if (is_legal_187_188_226(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_220([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_220;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old122_0 = coord;
    coord = direction_up[coord];
    if (is_legal_187_188_224(rgCache))
    {
        coord = old122_0;
        return true;
    }
    coord = old122_0;
    return false;
}

bool GameState::is_legal_187_188_221([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_219(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_220(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_222([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_225(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_223([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_222(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_224([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_224;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_187_188_223(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_225([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_221(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_226([[maybe_unused]]RgCache& rgCache)
{
    const auto old129_0 = coord;
    coord = direction_down[coord];
    if (is_legal_187_188_235(rgCache))
    {
        coord = old129_0;
        return true;
    }
    coord = old129_0;
    return false;
}

bool GameState::is_legal_187_188_233([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_236(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_234([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_233(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_235([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_234(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_236([[maybe_unused]]RgCache& rgCache)
{
    const auto old133_0 = coord;
    coord = direction_down[coord];
    if (is_legal_187_188_239(rgCache))
    {
        coord = old133_0;
        return true;
    }
    coord = old133_0;
    return false;
}

bool GameState::is_legal_187_188_237([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_240(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_238([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_237(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_239([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_238(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_240([[maybe_unused]]RgCache& rgCache)
{
    const auto old137_0 = coord;
    coord = direction_down[coord];
    if (is_legal_187_188_243(rgCache))
    {
        coord = old137_0;
        return true;
    }
    coord = old137_0;
    return false;
}

bool GameState::is_legal_187_188_241([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_244(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_242([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_241(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_243([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_242(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_244([[maybe_unused]]RgCache& rgCache)
{
    const auto old141_0 = coord;
    coord = direction_down[coord];
    if (is_legal_187_188_247(rgCache))
    {
        coord = old141_0;
        return true;
    }
    coord = old141_0;
    return false;
}

bool GameState::is_legal_187_188_245([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_248(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_246([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_245(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_247([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_246(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_248([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_250_251_250())
    {
        if (is_legal_187_188_249(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_249([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_188(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_256([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_263_264_263())
    {
        if (is_legal_187_188_262(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_257([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old148_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_187_188_260(rgCache))
    {
        coord = old148_0;
        return true;
    }
    coord = old148_0;
    return false;
}

bool GameState::is_legal_187_188_258([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_256(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_257(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_259([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_261(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_260([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_260;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_187_188_259(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_261([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_258(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_262([[maybe_unused]]RgCache& rgCache)
{
    const auto old154_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_187_188_269(rgCache))
    {
        coord = old154_0;
        return true;
    }
    coord = old154_0;
    return false;
}

bool GameState::is_legal_187_188_268([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_270(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_269([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_268(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_270([[maybe_unused]]RgCache& rgCache)
{
    const auto old157_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_187_188_272(rgCache))
    {
        coord = old157_0;
        return true;
    }
    coord = old157_0;
    return false;
}

bool GameState::is_legal_187_188_271([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_273(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_272([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_271(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_273([[maybe_unused]]RgCache& rgCache)
{
    const auto old160_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_187_188_275(rgCache))
    {
        coord = old160_0;
        return true;
    }
    coord = old160_0;
    return false;
}

bool GameState::is_legal_187_188_274([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_276(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_275([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_274(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_276([[maybe_unused]]RgCache& rgCache)
{
    const auto old163_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_187_188_278(rgCache))
    {
        coord = old163_0;
        return true;
    }
    coord = old163_0;
    return false;
}

bool GameState::is_legal_187_188_277([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_279(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_278([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_277(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_279([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_281_282_281())
    {
        if (is_legal_187_188_280(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_280([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_188(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_286([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_294_295_294())
    {
        if (is_legal_187_188_293(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_287([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_287;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = coord;
    coord = direction_left[coord];
    if (is_legal_187_188_291(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_187_188_288([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_286(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_287(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_289([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_290([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_289(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_291([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_291;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_187_188_290(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_292([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_288(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_293([[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = coord;
    coord = direction_right[coord];
    if (is_legal_187_188_302(rgCache))
    {
        coord = old176_0;
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::is_legal_187_188_300([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_303(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_301([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_300(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_302([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_301(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_303([[maybe_unused]]RgCache& rgCache)
{
    const auto old180_0 = coord;
    coord = direction_right[coord];
    if (is_legal_187_188_306(rgCache))
    {
        coord = old180_0;
        return true;
    }
    coord = old180_0;
    return false;
}

bool GameState::is_legal_187_188_304([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_307(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_305([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_304(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_306([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_305(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_307([[maybe_unused]]RgCache& rgCache)
{
    const auto old184_0 = coord;
    coord = direction_right[coord];
    if (is_legal_187_188_310(rgCache))
    {
        coord = old184_0;
        return true;
    }
    coord = old184_0;
    return false;
}

bool GameState::is_legal_187_188_308([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_311(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_309([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_308(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_310([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_309(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_311([[maybe_unused]]RgCache& rgCache)
{
    const auto old188_0 = coord;
    coord = direction_right[coord];
    if (is_legal_187_188_314(rgCache))
    {
        coord = old188_0;
        return true;
    }
    coord = old188_0;
    return false;
}

bool GameState::is_legal_187_188_312([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_187_188_315(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_313([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_312(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_314([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_313(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_315([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_317_318_317())
    {
        if (is_legal_187_188_316(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_316([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_188(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_196_197_196()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_196_197_199())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_196_197_197()
{
    return true;
}

bool GameState::is_legal_196_197_198()
{
    if (board[coord]==b)
    {
        if (is_legal_196_197_200())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_196_197_199()
{
    if (is_legal_196_197_198())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_196_197_200()
{
    if (is_legal_196_197_197())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_214_215_214()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_214_215_217())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_214_215_215()
{
    return true;
}

bool GameState::is_legal_214_215_216()
{
    if (board[coord]==b)
    {
        if (is_legal_214_215_218())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_214_215_217()
{
    if (is_legal_214_215_216())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_214_215_218()
{
    if (is_legal_214_215_215())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_227_228_227()
{
    const auto old6_0 = coord;
    coord = direction_up[coord];
    if (is_legal_227_228_231())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_227_228_228()
{
    return true;
}

bool GameState::is_legal_227_228_229()
{
    if (board[coord]==b)
    {
        if (is_legal_227_228_232())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_227_228_230()
{
    if (is_legal_227_228_229())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_227_228_231()
{
    if (is_legal_227_228_230())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_227_228_232()
{
    if (is_legal_227_228_228())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_100([[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_25_26_107(rgCache))
    {
        coord = old92_0;
        return true;
    }
    coord = old92_0;
    return false;
}

bool GameState::is_legal_25_26_106([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_108(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_107([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_106(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_108([[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_25_26_110(rgCache))
    {
        coord = old95_0;
        return true;
    }
    coord = old95_0;
    return false;
}

bool GameState::is_legal_25_26_109([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_111(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_110([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_109(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_111([[maybe_unused]]RgCache& rgCache)
{
    const auto old98_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_25_26_113(rgCache))
    {
        coord = old98_0;
        return true;
    }
    coord = old98_0;
    return false;
}

bool GameState::is_legal_25_26_112([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_114(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_113([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_112(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_114([[maybe_unused]]RgCache& rgCache)
{
    const auto old101_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_25_26_116(rgCache))
    {
        coord = old101_0;
        return true;
    }
    coord = old101_0;
    return false;
}

bool GameState::is_legal_25_26_115([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_117(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_116([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_115(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_117([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_119_120_119())
    {
        if (is_legal_25_26_118(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_118([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_124([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_132_133_132())
    {
        if (is_legal_25_26_131(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_125([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_125;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old107_0 = coord;
    coord = direction_left[coord];
    if (is_legal_25_26_129(rgCache))
    {
        coord = old107_0;
        return true;
    }
    coord = old107_0;
    return false;
}

bool GameState::is_legal_25_26_126([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_124(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_125(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_127([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_130(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_128([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_127(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_129([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_129;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_25_26_128(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_130([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_126(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_131([[maybe_unused]]RgCache& rgCache)
{
    const auto old114_0 = coord;
    coord = direction_right[coord];
    if (is_legal_25_26_140(rgCache))
    {
        coord = old114_0;
        return true;
    }
    coord = old114_0;
    return false;
}

bool GameState::is_legal_25_26_138([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_141(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_139([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_138(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_140([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_139(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old118_0 = coord;
    coord = direction_right[coord];
    if (is_legal_25_26_144(rgCache))
    {
        coord = old118_0;
        return true;
    }
    coord = old118_0;
    return false;
}

bool GameState::is_legal_25_26_142([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_145(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_143([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_142(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_144([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_145([[maybe_unused]]RgCache& rgCache)
{
    const auto old122_0 = coord;
    coord = direction_right[coord];
    if (is_legal_25_26_148(rgCache))
    {
        coord = old122_0;
        return true;
    }
    coord = old122_0;
    return false;
}

bool GameState::is_legal_25_26_146([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_149(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_147([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_146(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_148([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_147(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_149([[maybe_unused]]RgCache& rgCache)
{
    const auto old126_0 = coord;
    coord = direction_right[coord];
    if (is_legal_25_26_152(rgCache))
    {
        coord = old126_0;
        return true;
    }
    coord = old126_0;
    return false;
}

bool GameState::is_legal_25_26_150([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_153(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_151([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_150(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_152([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_151(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_153([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_155_156_155())
    {
        if (is_legal_25_26_154(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_154([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_124(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_125(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_27(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_28(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_57(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_58(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_94(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_95(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_26([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_25_26_27([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        if (is_legal_25_26_33(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_28([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_28;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old141_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_25_26_31(rgCache))
    {
        coord = old141_0;
        return true;
    }
    coord = old141_0;
    return false;
}

bool GameState::is_legal_25_26_29([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_27(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_28(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_30([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_32(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_31([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_31;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_25_26_30(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_32([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_29(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_33([[maybe_unused]]RgCache& rgCache)
{
    const auto old147_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_25_26_40(rgCache))
    {
        coord = old147_0;
        return true;
    }
    coord = old147_0;
    return false;
}

bool GameState::is_legal_25_26_39([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_41(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_40([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_39(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_41([[maybe_unused]]RgCache& rgCache)
{
    const auto old150_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_25_26_43(rgCache))
    {
        coord = old150_0;
        return true;
    }
    coord = old150_0;
    return false;
}

bool GameState::is_legal_25_26_42([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_44(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_43([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_42(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_44([[maybe_unused]]RgCache& rgCache)
{
    const auto old153_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_25_26_46(rgCache))
    {
        coord = old153_0;
        return true;
    }
    coord = old153_0;
    return false;
}

bool GameState::is_legal_25_26_45([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_47(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_46([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_45(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_47([[maybe_unused]]RgCache& rgCache)
{
    const auto old156_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_25_26_49(rgCache))
    {
        coord = old156_0;
        return true;
    }
    coord = old156_0;
    return false;
}

bool GameState::is_legal_25_26_48([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_50(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_49([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_48(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_50([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_52_53_52())
    {
        if (is_legal_25_26_51(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_51([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_57([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_65_66_65())
    {
        if (is_legal_25_26_64(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_58([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_58;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old162_0 = coord;
    coord = direction_up[coord];
    if (is_legal_25_26_62(rgCache))
    {
        coord = old162_0;
        return true;
    }
    coord = old162_0;
    return false;
}

bool GameState::is_legal_25_26_59([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_57(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_58(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_60([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_63(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_61([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_60(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_62([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_62;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_25_26_61(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_63([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_59(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_64([[maybe_unused]]RgCache& rgCache)
{
    const auto old169_0 = coord;
    coord = direction_down[coord];
    if (is_legal_25_26_73(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_25_26_71([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_74(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_72([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_71(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_73([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_72(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_74([[maybe_unused]]RgCache& rgCache)
{
    const auto old173_0 = coord;
    coord = direction_down[coord];
    if (is_legal_25_26_77(rgCache))
    {
        coord = old173_0;
        return true;
    }
    coord = old173_0;
    return false;
}

bool GameState::is_legal_25_26_75([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_78(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_76([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_75(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_77([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_78([[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = coord;
    coord = direction_down[coord];
    if (is_legal_25_26_81(rgCache))
    {
        coord = old177_0;
        return true;
    }
    coord = old177_0;
    return false;
}

bool GameState::is_legal_25_26_79([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_82(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_80([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_79(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_81([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_80(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_82([[maybe_unused]]RgCache& rgCache)
{
    const auto old181_0 = coord;
    coord = direction_down[coord];
    if (is_legal_25_26_85(rgCache))
    {
        coord = old181_0;
        return true;
    }
    coord = old181_0;
    return false;
}

bool GameState::is_legal_25_26_83([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_86(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_84([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_83(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_85([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_84(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_86([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_88_89_88())
    {
        if (is_legal_25_26_87(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_87([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_94([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_101_102_101())
    {
        if (is_legal_25_26_100(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_95([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_95;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old188_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_25_26_98(rgCache))
    {
        coord = old188_0;
        return true;
    }
    coord = old188_0;
    return false;
}

bool GameState::is_legal_25_26_96([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_94(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_95(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_97([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_99(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_98([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_98;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_25_26_97(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_99([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_96(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_250_251_250()
{
    const auto old6_0 = coord;
    coord = direction_down[coord];
    if (is_legal_250_251_254())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_250_251_251()
{
    return true;
}

bool GameState::is_legal_250_251_252()
{
    if (board[coord]==b)
    {
        if (is_legal_250_251_255())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_250_251_253()
{
    if (is_legal_250_251_252())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_250_251_254()
{
    if (is_legal_250_251_253())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_250_251_255()
{
    if (is_legal_250_251_251())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_263_264_263()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_263_264_266())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_263_264_264()
{
    return true;
}

bool GameState::is_legal_263_264_265()
{
    if (board[coord]==b)
    {
        if (is_legal_263_264_267())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_263_264_266()
{
    if (is_legal_263_264_265())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_263_264_267()
{
    if (is_legal_263_264_264())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_281_282_281()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_281_282_284())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_281_282_282()
{
    return true;
}

bool GameState::is_legal_281_282_283()
{
    if (board[coord]==b)
    {
        if (is_legal_281_282_285())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_281_282_284()
{
    if (is_legal_281_282_283())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_281_282_285()
{
    if (is_legal_281_282_282())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_294_295_294()
{
    const auto old6_0 = coord;
    coord = direction_left[coord];
    if (is_legal_294_295_298())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_294_295_295()
{
    return true;
}

bool GameState::is_legal_294_295_296()
{
    if (board[coord]==b)
    {
        if (is_legal_294_295_299())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_294_295_297()
{
    if (is_legal_294_295_296())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_294_295_298()
{
    if (is_legal_294_295_297())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_294_295_299()
{
    if (is_legal_294_295_295())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_317_318_317()
{
    const auto old6_0 = coord;
    coord = direction_right[coord];
    if (is_legal_317_318_321())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_317_318_318()
{
    return true;
}

bool GameState::is_legal_317_318_319()
{
    if (board[coord]==b)
    {
        if (is_legal_317_318_322())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_317_318_320()
{
    if (is_legal_317_318_319())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_317_318_321()
{
    if (is_legal_317_318_320())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_317_318_322()
{
    if (is_legal_317_318_318())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_334_335_334([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_169_15_15_169_169_15_169_15(rgCache))
    {
        if (is_legal_334_335_335(rgCache))
        {
            return true;
        }
    }
    if (is_legal_15_173_15_15_173_173_15_173_15(rgCache))
    {
        if (is_legal_334_335_335(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_334_335_335([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_336_337_336([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_177_11_177_177_11_11_177_11_177(rgCache))
    {
        if (is_legal_336_337_337(rgCache))
        {
            return true;
        }
    }
    if (is_legal_177_331_177_177_331_331_177_331_177(rgCache))
    {
        if (is_legal_336_337_337(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_336_337_337([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_34_35_34()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_34_35_37())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_34_35_35()
{
    return true;
}

bool GameState::is_legal_34_35_36()
{
    if (board[coord]==w)
    {
        if (is_legal_34_35_38())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_37()
{
    if (is_legal_34_35_36())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_38()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_52_53_52()
{
    const auto old5_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_52_53_55())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_52_53_53()
{
    return true;
}

bool GameState::is_legal_52_53_54()
{
    if (board[coord]==w)
    {
        if (is_legal_52_53_56())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_52_53_55()
{
    if (is_legal_52_53_54())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_52_53_56()
{
    if (is_legal_52_53_53())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_65_66_65()
{
    const auto old6_0 = coord;
    coord = direction_up[coord];
    if (is_legal_65_66_69())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_65_66_66()
{
    return true;
}

bool GameState::is_legal_65_66_67()
{
    if (board[coord]==w)
    {
        if (is_legal_65_66_70())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_65_66_68()
{
    if (is_legal_65_66_67())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_65_66_69()
{
    if (is_legal_65_66_68())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_65_66_70()
{
    if (is_legal_65_66_66())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_88_89_88()
{
    const auto old6_0 = coord;
    coord = direction_down[coord];
    if (is_legal_88_89_92())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_88_89_89()
{
    return true;
}

bool GameState::is_legal_88_89_90()
{
    if (board[coord]==w)
    {
        if (is_legal_88_89_93())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_88_89_91()
{
    if (is_legal_88_89_90())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_88_89_92()
{
    if (is_legal_88_89_91())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_88_89_93()
{
    if (is_legal_88_89_89())
    {
        return true;
    }
    return false;
}

void GameState::state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old406_0 = goals[black - 2];
    goals[black - 2] = 50;
    state_5(moves, mr,rgCache);
    goals[black - 2] = old406_0;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old407_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    state_13(moves, mr,rgCache);    }
    coord = old407_0;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        state_338(moves, mr,rgCache);
        return;
    }
    state_339(moves, mr,rgCache);
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(0);
    state_11(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_14(moves, mr,rgCache);
    }
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_17(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old463_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_19(moves, mr,rgCache);
    counters[board[coord]] = old463_0;
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_334_335_334(rgCache))
    {
        state_340(moves, mr,rgCache);
        return;
    }
    state_341(moves, mr,rgCache);
}

void GameState::state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old497_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_163(moves, mr,rgCache);
    goals[white - 2] = old497_0;
}

void GameState::state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old498_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_166(moves, mr,rgCache);
    goals[black - 2] = old498_0;
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_164(moves, mr,rgCache);
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_162(moves, mr,rgCache);
}

void GameState::state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_170(moves, mr,rgCache);
}

void GameState::state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_167(moves, mr,rgCache);
}

void GameState::state_167([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_165(moves, mr,rgCache);
}

void GameState::state_169([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(171);
    state_16(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_170([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_169(moves, mr,rgCache);
}

void GameState::state_172([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old508_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    state_175(moves, mr,rgCache);    }
    coord = old508_0;
}

void GameState::state_173([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_172_178_172_172_178_178_172_178_172())
    {
        state_342(moves, mr,rgCache);
        return;
    }
    state_343(moves, mr,rgCache);
}

void GameState::state_174([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(172);
    state_173(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_175([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_176(moves, mr,rgCache);
    }
}

void GameState::state_176([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_179(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_177([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old516_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_181(moves, mr,rgCache);
    counters[board[coord]] = old516_0;
}

void GameState::state_178([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_336_337_336(rgCache))
    {
        state_344(moves, mr,rgCache);
        return;
    }
    state_345(moves, mr,rgCache);
}

void GameState::state_179([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(173);
    state_178(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_98.reset();
    const auto result_543 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_543)
    {
        state_161(moves, mr,rgCache);
        return;
    }
    state_24(moves, mr,rgCache);
}

void GameState::state_180([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_193.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_260.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_545 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (!result_545)
    {
        state_186(moves, mr,rgCache);
        return;
    }
    state_323(moves, mr,rgCache);
}

void GameState::state_181([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old547_0 = counters[b];
    counters[b] = counters[b]+1;
    state_182(moves, mr,rgCache);
    counters[b] = old547_0;
}

void GameState::state_182([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_184(moves, mr,rgCache);
}

void GameState::state_183([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old549_0 = board[coord];
    board[coord] = b;
    state_180(moves, mr,rgCache);
    board[coord] = old549_0;
}

void GameState::state_184([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_183(moves, mr,rgCache);
}

void GameState::state_185([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_9(moves, mr,rgCache);
}

void GameState::state_186([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_185(moves, mr,rgCache);
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old562_0 = counters[w];
    counters[w] = counters[w]+1;
    state_20(moves, mr,rgCache);
    counters[w] = old562_0;
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_3(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_22(moves, mr,rgCache);
}

void GameState::state_21([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old585_0 = board[coord];
    board[coord] = w;
    state_18(moves, mr,rgCache);
    board[coord] = old585_0;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_21(moves, mr,rgCache);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_174(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_23(moves, mr,rgCache);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(174);
    state_1(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_323([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old714_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_325(moves, mr,rgCache);
    goals[black - 2] = old714_0;
}

void GameState::state_324([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old715_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_328(moves, mr,rgCache);
    goals[white - 2] = old715_0;
}

void GameState::state_325([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_326(moves, mr,rgCache);
}

void GameState::state_326([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_324(moves, mr,rgCache);
}

void GameState::state_327([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_332(moves, mr,rgCache);
}

void GameState::state_328([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_329(moves, mr,rgCache);
}

void GameState::state_329([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_327(moves, mr,rgCache);
}

void GameState::state_331([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_332([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_331(moves, mr,rgCache);
}

void GameState::state_338([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_339([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_340([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_341([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_342([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_343([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_344([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_345([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_8(moves, mr,rgCache);
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_6(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(175);
    state_4(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_12(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_8(moves, mr,rgCache);
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old798_0 = goals[white - 2];
    goals[white - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[white - 2] = old798_0;
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old406_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_state_5(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old406_0;
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_16(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_state_338(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_339(mr,rgCache))
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
            case 0:
{
                return apply_state_11(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_1(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 0)
    {
        rgCache.currentMrId++;
        if (apply_state_11(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_14(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
                            counters[board[coord]] = counters[board[coord]]-1;
                            counters[w] = counters[w]+1;
                            board[coord] = w;
                            return apply_state_173(mr,rgCache);
                    }
                }
                break;
        }
    }
    if (mr.size()!=rgCache.currentMrId)
    {
        return false;
    }
    counters[board[coord]] = counters[board[coord]]-1;
    counters[w] = counters[w]+1;
    board[coord] = w;
    goals[white - 2] = 100;
    goals[black - 2] = 0;
    player = keeper;
    currentState = 406;
    return true;
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_334_335_334(rgCache))
    {
        if (apply_state_340(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_341(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old497_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_163(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old497_0;
    return false;
}

bool GameState::apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old498_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_166(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old498_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_164(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_162(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_170(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_167(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_167([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_165(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_169([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old504_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old504_0;
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 171:
{
                return apply_state_16(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_3(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 171)
    {
        rgCache.currentMrId++;
        if (apply_state_16(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_170([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_169(mr,rgCache))
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
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_178(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_172([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_4(mr ,rgCache);
    return false;
}

bool GameState::apply_state_173([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_172_178_172_172_178_178_172_178_172())
    {
        if (apply_state_342(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_343(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 172:
{
                return apply_state_173(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_174([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_5(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 172)
    {
        rgCache.currentMrId++;
        if (apply_state_173(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_175([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_176(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_176([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_179(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
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
                            counters[board[coord]] = counters[board[coord]]-1;
                            counters[b] = counters[b]+1;
                            board[coord] = b;
                            return apply_state_11(mr,rgCache);
                    }
                }
                break;
        }
    }
    if (mr.size()!=rgCache.currentMrId)
    {
        return false;
    }
    counters[board[coord]] = counters[board[coord]]-1;
    counters[b] = counters[b]+1;
    board[coord] = b;
    goals[black - 2] = 100;
    goals[white - 2] = 0;
    player = keeper;
    currentState = 406;
    return true;
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_177([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_6(mr ,rgCache);
    return false;
}

bool GameState::apply_state_178([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_336_337_336(rgCache))
    {
        if (apply_state_344(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_345(mr,rgCache))
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
            case 173:
{
                return apply_state_178(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_179([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_7(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 173)
    {
        rgCache.currentMrId++;
        if (apply_state_178(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_98.reset();
    const auto result_543 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_543)
    {
        if (apply_state_161(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_24(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_180([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_193.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_260.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_545 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (!result_545)
    {
        if (apply_state_186(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_323(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_181([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old547_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_182(mr,rgCache))
    {
        return true;
    }
    counters[b] = old547_0;
    return false;
}

bool GameState::apply_state_182([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_184(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_183([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old549_0 = board[coord];
    board[coord] = b;
    if (apply_state_180(mr,rgCache))
    {
        return true;
    }
    board[coord] = old549_0;
    return false;
}

bool GameState::apply_state_184([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_183(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_185([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_186([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_185(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old562_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }
    counters[w] = old562_0;
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_3(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_21([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old585_0 = board[coord];
    board[coord] = w;
    if (apply_state_18(mr,rgCache))
    {
        return true;
    }
    board[coord] = old585_0;
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_174(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_23(mr,rgCache))
    {
        return true;
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
            case 174:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 170:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 175:
{
                                        if (mr.size() >rgCache.currentMrId)
                                        {
                                            switch (mr[rgCache.currentMrId++])
                                            {
                                                case 1 ... 170:
{
                                                    if (mr.size() >rgCache.currentMrId)
                                                    {
                                                        switch (mr[rgCache.currentMrId++])
                                                        {
                                                            case 0:
{
                                                                goals[black - 2] = 50;
                                                                return apply_state_11(mr,rgCache);
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

bool GameState::apply_state_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_8(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 174)
    {
        rgCache.currentMrId++;
        if (apply_state_1(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_323([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old714_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_325(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old714_0;
    return false;
}

bool GameState::apply_state_324([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old715_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_328(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old715_0;
    return false;
}

bool GameState::apply_state_325([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_326(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_326([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_324(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_327([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_332(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_328([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_329(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_329([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_327(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_331([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old722_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old722_0;
    return false;
}

bool GameState::apply_state_332([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_331(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_338([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old800_0 = player;
    player = white;
    currentState = 2;
    return true;
    player = old800_0;
    return false;
}

bool GameState::apply_state_339([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old802_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old802_0;
    return false;
}

bool GameState::apply_state_340([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old804_0 = player;
    player = keeper;
    currentState = 62;
    return true;
    player = old804_0;
    return false;
}

bool GameState::apply_state_341([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old806_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old806_0;
    return false;
}

bool GameState::apply_state_342([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old808_0 = player;
    player = black;
    currentState = 111;
    return true;
    player = old808_0;
    return false;
}

bool GameState::apply_state_343([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old810_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old810_0;
    return false;
}

bool GameState::apply_state_344([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old812_0 = player;
    player = keeper;
    currentState = 121;
    return true;
    player = old812_0;
    return false;
}

bool GameState::apply_state_345([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old814_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    player = old814_0;
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
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

bool GameState::switch_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 175:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 170:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 0:
{
                                        return apply_state_11(mr,rgCache);
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

bool GameState::apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_9(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 175)
    {
        rgCache.currentMrId++;
        if (apply_state_4(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
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

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
                                    switch (mr[rgCache.currentMrId++])
                                    {
                                        default:
                                            switch (mr[rgCache.currentMrId++])
                                            {
                                                default:
                                                    goals[white - 2] = 50;
                                                    goals[black - 2] = 50;
                                                    return apply_state_11(mr,rgCache);
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_10(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_15_15_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old23_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_15_15_19(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old23_0;
    return false;
}

bool GameState::apply_any_15_15_161([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_15_15_163(rgCache))
    {
        return true;
    }
    goals[white - 2] = old24_0;
    return false;
}

bool GameState::apply_any_15_15_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_15_15_166(rgCache))
    {
        return true;
    }
    goals[black - 2] = old25_0;
    return false;
}

bool GameState::apply_any_15_15_163([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_164([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_165([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_170(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_166([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_167([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_165(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_169([[maybe_unused]]RgCache& rgCache)
{
    const auto old31_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    if (apply_any_15_15_end(rgCache))
    {
        return true;
    }
    player = old31_0;
    return false;
}

bool GameState::apply_any_15_15_170([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_169(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_172([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_15_15_173([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_172_178_172_172_178_178_172_178_172())
    {
        if (apply_any_15_15_342(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_15_15_343(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_174([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_173(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_98.reset();
    const auto result_34 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_34)
    {
        if (apply_any_15_15_161(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_15_15_24(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old36_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_15_15_20(rgCache))
    {
        return true;
    }
    counters[w] = old36_0;
    return false;
}

bool GameState::apply_any_15_15_20([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old38_0 = board[coord];
    board[coord] = w;
    if (apply_any_15_15_18(rgCache))
    {
        return true;
    }
    board[coord] = old38_0;
    return false;
}

bool GameState::apply_any_15_15_22([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_23([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_174(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_24([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_23(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_342([[maybe_unused]]RgCache& rgCache)
{
    const auto old43_0 = player;
    player = black;
    currentState = 111;
    return true;
    if (apply_any_15_15_172(rgCache))
    {
        return true;
    }
    player = old43_0;
    return false;
}

bool GameState::apply_any_15_15_343([[maybe_unused]]RgCache& rgCache)
{
    const auto old45_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    if (apply_any_15_15_end(rgCache))
    {
        return true;
    }
    player = old45_0;
    return false;
}

bool GameState::apply_any_15_15_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_177_177_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_177_177_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_177_177_338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_177_177_339(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_12([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_177([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_177_177_181(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old26_0;
    return false;
}

bool GameState::apply_any_177_177_180([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_193.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_260.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_27 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (!result_27)
    {
        if (apply_any_177_177_186(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_177_177_323(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_181([[maybe_unused]]RgCache& rgCache)
{
    const auto old29_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_177_177_182(rgCache))
    {
        return true;
    }
    counters[b] = old29_0;
    return false;
}

bool GameState::apply_any_177_177_182([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_184(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_183([[maybe_unused]]RgCache& rgCache)
{
    const auto old31_0 = board[coord];
    board[coord] = b;
    if (apply_any_177_177_180(rgCache))
    {
        return true;
    }
    board[coord] = old31_0;
    return false;
}

bool GameState::apply_any_177_177_184([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_183(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_185([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_186([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_185(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_323([[maybe_unused]]RgCache& rgCache)
{
    const auto old35_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_177_177_325(rgCache))
    {
        return true;
    }
    goals[black - 2] = old35_0;
    return false;
}

bool GameState::apply_any_177_177_324([[maybe_unused]]RgCache& rgCache)
{
    const auto old36_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_177_177_328(rgCache))
    {
        return true;
    }
    goals[white - 2] = old36_0;
    return false;
}

bool GameState::apply_any_177_177_325([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_326(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_326([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_324(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_327([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_332(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_328([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_329(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_329([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_327(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_331([[maybe_unused]]RgCache& rgCache)
{
    const auto old42_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    if (apply_any_177_177_end(rgCache))
    {
        return true;
    }
    player = old42_0;
    return false;
}

bool GameState::apply_any_177_177_332([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_331(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_338([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = player;
    player = white;
    currentState = 2;
    return true;
    if (apply_any_177_177_10(rgCache))
    {
        return true;
    }
    player = old47_0;
    return false;
}

bool GameState::apply_any_177_177_339([[maybe_unused]]RgCache& rgCache)
{
    const auto old49_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    if (apply_any_177_177_end(rgCache))
    {
        return true;
    }
    player = old49_0;
    return false;
}

bool GameState::apply_any_177_177_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_9([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_177_177_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_177_177_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_any_begin_begin_5(rgCache))
    {
        return true;
    }
    goals[black - 2] = old14_0;
    return false;
}

bool GameState::apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_begin_begin_338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_339(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_12([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_3(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_3([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_1(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_338([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = player;
    player = white;
    currentState = 2;
    return true;
    if (apply_any_begin_begin_10(rgCache))
    {
        return true;
    }
    player = old24_0;
    return false;
}

bool GameState::apply_any_begin_begin_339([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = player;
    player = keeper;
    currentState = 406;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old26_0;
    return false;
}

bool GameState::apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_5([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_4(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = goals[white - 2];
    goals[white - 2] = 50;
    if (apply_any_begin_begin_2(rgCache))
    {
        return true;
    }
    goals[white - 2] = old22_0;
    return false;
}

bool GameState::apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

}  // namespace reasoner
