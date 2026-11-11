#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && coord==rhs.coord && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx7y0: " << board[rx7y0] << ", " << "rx8y0: " << board[rx8y0] << ", " << "rx9y0: " << board[rx9y0] << ", " << "rx10y0: " << board[rx10y0] << ", " << "rx11y0: " << board[rx11y0] << ", " << "rx12y0: " << board[rx12y0] << ", " << "rx13y0: " << board[rx13y0] << ", " << "rx14y0: " << board[rx14y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx7y1: " << board[rx7y1] << ", " << "rx8y1: " << board[rx8y1] << ", " << "rx9y1: " << board[rx9y1] << ", " << "rx10y1: " << board[rx10y1] << ", " << "rx11y1: " << board[rx11y1] << ", " << "rx12y1: " << board[rx12y1] << ", " << "rx13y1: " << board[rx13y1] << ", " << "rx14y1: " << board[rx14y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx7y2: " << board[rx7y2] << ", " << "rx8y2: " << board[rx8y2] << ", " << "rx9y2: " << board[rx9y2] << ", " << "rx10y2: " << board[rx10y2] << ", " << "rx11y2: " << board[rx11y2] << ", " << "rx12y2: " << board[rx12y2] << ", " << "rx13y2: " << board[rx13y2] << ", " << "rx14y2: " << board[rx14y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx8y3: " << board[rx8y3] << ", " << "rx9y3: " << board[rx9y3] << ", " << "rx10y3: " << board[rx10y3] << ", " << "rx11y3: " << board[rx11y3] << ", " << "rx12y3: " << board[rx12y3] << ", " << "rx13y3: " << board[rx13y3] << ", " << "rx14y3: " << board[rx14y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx8y4: " << board[rx8y4] << ", " << "rx9y4: " << board[rx9y4] << ", " << "rx10y4: " << board[rx10y4] << ", " << "rx11y4: " << board[rx11y4] << ", " << "rx12y4: " << board[rx12y4] << ", " << "rx13y4: " << board[rx13y4] << ", " << "rx14y4: " << board[rx14y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx8y5: " << board[rx8y5] << ", " << "rx9y5: " << board[rx9y5] << ", " << "rx10y5: " << board[rx10y5] << ", " << "rx11y5: " << board[rx11y5] << ", " << "rx12y5: " << board[rx12y5] << ", " << "rx13y5: " << board[rx13y5] << ", " << "rx14y5: " << board[rx14y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx8y6: " << board[rx8y6] << ", " << "rx9y6: " << board[rx9y6] << ", " << "rx10y6: " << board[rx10y6] << ", " << "rx11y6: " << board[rx11y6] << ", " << "rx12y6: " << board[rx12y6] << ", " << "rx13y6: " << board[rx13y6] << ", " << "rx14y6: " << board[rx14y6] << ", " << "rx0y7: " << board[rx0y7] << ", " << "rx1y7: " << board[rx1y7] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx7y7: " << board[rx7y7] << ", " << "rx8y7: " << board[rx8y7] << ", " << "rx9y7: " << board[rx9y7] << ", " << "rx10y7: " << board[rx10y7] << ", " << "rx11y7: " << board[rx11y7] << ", " << "rx12y7: " << board[rx12y7] << ", " << "rx13y7: " << board[rx13y7] << ", " << "rx14y7: " << board[rx14y7] << ", " << "rx0y8: " << board[rx0y8] << ", " << "rx1y8: " << board[rx1y8] << ", " << "rx2y8: " << board[rx2y8] << ", " << "rx3y8: " << board[rx3y8] << ", " << "rx4y8: " << board[rx4y8] << ", " << "rx5y8: " << board[rx5y8] << ", " << "rx6y8: " << board[rx6y8] << ", " << "rx7y8: " << board[rx7y8] << ", " << "rx8y8: " << board[rx8y8] << ", " << "rx9y8: " << board[rx9y8] << ", " << "rx10y8: " << board[rx10y8] << ", " << "rx11y8: " << board[rx11y8] << ", " << "rx12y8: " << board[rx12y8] << ", " << "rx13y8: " << board[rx13y8] << ", " << "rx14y8: " << board[rx14y8] << ", " << "rx0y9: " << board[rx0y9] << ", " << "rx1y9: " << board[rx1y9] << ", " << "rx2y9: " << board[rx2y9] << ", " << "rx3y9: " << board[rx3y9] << ", " << "rx4y9: " << board[rx4y9] << ", " << "rx5y9: " << board[rx5y9] << ", " << "rx6y9: " << board[rx6y9] << ", " << "rx7y9: " << board[rx7y9] << ", " << "rx8y9: " << board[rx8y9] << ", " << "rx9y9: " << board[rx9y9] << ", " << "rx10y9: " << board[rx10y9] << ", " << "rx11y9: " << board[rx11y9] << ", " << "rx12y9: " << board[rx12y9] << ", " << "rx13y9: " << board[rx13y9] << ", " << "rx14y9: " << board[rx14y9] << ", " << "rx0y10: " << board[rx0y10] << ", " << "rx1y10: " << board[rx1y10] << ", " << "rx2y10: " << board[rx2y10] << ", " << "rx3y10: " << board[rx3y10] << ", " << "rx4y10: " << board[rx4y10] << ", " << "rx5y10: " << board[rx5y10] << ", " << "rx6y10: " << board[rx6y10] << ", " << "rx7y10: " << board[rx7y10] << ", " << "rx8y10: " << board[rx8y10] << ", " << "rx9y10: " << board[rx9y10] << ", " << "rx10y10: " << board[rx10y10] << ", " << "rx11y10: " << board[rx11y10] << ", " << "rx12y10: " << board[rx12y10] << ", " << "rx13y10: " << board[rx13y10] << ", " << "rx14y10: " << board[rx14y10] << ", " << "rx0y11: " << board[rx0y11] << ", " << "rx1y11: " << board[rx1y11] << ", " << "rx2y11: " << board[rx2y11] << ", " << "rx3y11: " << board[rx3y11] << ", " << "rx4y11: " << board[rx4y11] << ", " << "rx5y11: " << board[rx5y11] << ", " << "rx6y11: " << board[rx6y11] << ", " << "rx7y11: " << board[rx7y11] << ", " << "rx8y11: " << board[rx8y11] << ", " << "rx9y11: " << board[rx9y11] << ", " << "rx10y11: " << board[rx10y11] << ", " << "rx11y11: " << board[rx11y11] << ", " << "rx12y11: " << board[rx12y11] << ", " << "rx13y11: " << board[rx13y11] << ", " << "rx14y11: " << board[rx14y11] << ", " << "rx0y12: " << board[rx0y12] << ", " << "rx1y12: " << board[rx1y12] << ", " << "rx2y12: " << board[rx2y12] << ", " << "rx3y12: " << board[rx3y12] << ", " << "rx4y12: " << board[rx4y12] << ", " << "rx5y12: " << board[rx5y12] << ", " << "rx6y12: " << board[rx6y12] << ", " << "rx7y12: " << board[rx7y12] << ", " << "rx8y12: " << board[rx8y12] << ", " << "rx9y12: " << board[rx9y12] << ", " << "rx10y12: " << board[rx10y12] << ", " << "rx11y12: " << board[rx11y12] << ", " << "rx12y12: " << board[rx12y12] << ", " << "rx13y12: " << board[rx13y12] << ", " << "rx14y12: " << board[rx14y12] << ", " << "rx0y13: " << board[rx0y13] << ", " << "rx1y13: " << board[rx1y13] << ", " << "rx2y13: " << board[rx2y13] << ", " << "rx3y13: " << board[rx3y13] << ", " << "rx4y13: " << board[rx4y13] << ", " << "rx5y13: " << board[rx5y13] << ", " << "rx6y13: " << board[rx6y13] << ", " << "rx7y13: " << board[rx7y13] << ", " << "rx8y13: " << board[rx8y13] << ", " << "rx9y13: " << board[rx9y13] << ", " << "rx10y13: " << board[rx10y13] << ", " << "rx11y13: " << board[rx11y13] << ", " << "rx12y13: " << board[rx12y13] << ", " << "rx13y13: " << board[rx13y13] << ", " << "rx14y13: " << board[rx14y13] << ", " << "rx0y14: " << board[rx0y14] << ", " << "rx1y14: " << board[rx1y14] << ", " << "rx2y14: " << board[rx2y14] << ", " << "rx3y14: " << board[rx3y14] << ", " << "rx4y14: " << board[rx4y14] << ", " << "rx5y14: " << board[rx5y14] << ", " << "rx6y14: " << board[rx6y14] << ", " << "rx7y14: " << board[rx7y14] << ", " << "rx8y14: " << board[rx8y14] << ", " << "rx9y14: " << board[rx9y14] << ", " << "rx10y14: " << board[rx10y14] << ", " << "rx11y14: " << board[rx11y14] << ", " << "rx12y14: " << board[rx12y14] << ", " << "rx13y14: " << board[rx13y14] << ", " << "rx14y14: " << board[rx14y14]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
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
        case 1:
{
            state_10(moves, mr.mr,rgCache);
            return;
}
        case 22:
{
            state_172(moves, mr.mr,rgCache);
            return;
}
        case 99:
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
        case 1:
{
            apply_state_10(mr.mr,rgCache);
            return;
}
        case 22:
{
            apply_state_172(mr.mr,rgCache);
            return;
}
        case 99:
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
            apply_any_181_181_181(rgCache);
            break;
}
        case 35:
{
            apply_any_19_19_19(rgCache);
            break;
}
        case 99:
{
            apply_any_begin_begin_begin(rgCache);
            break;
}
    }
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_10()
{
    const auto old3_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    if (is_legal_10_16_10_10_16_16_10_16_13())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_13()
{
    if (board[coord]==e)
    {
        if (is_legal_10_16_10_10_16_16_10_16_16())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_16()
{
    return true;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_172()
{
    const auto old3_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    if (is_legal_172_178_172_172_178_178_172_178_175())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_175()
{
    if (board[coord]==e)
    {
        if (is_legal_172_178_172_172_178_178_172_178_178())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_172_178_172_172_178_178_172_178_178()
{
    return true;
}

bool GameState::is_legal_187_188_187([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_187_188_349(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_190(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_351(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_220(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_353(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_257(rgCache))
    {
        return true;
    }
    if (is_legal_187_188_356(rgCache))
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

bool GameState::is_legal_187_188_190([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old42_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_187_188_192(rgCache))
    {
        coord = old42_0;
        return true;
    }
    coord = old42_0;
    if (is_legal_187_188_349(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_192([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_192;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_187_188_190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_201([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_187_188_204(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_204([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2_RbgCoordMap2[coord]]==b)
    {
        if (is_legal_187_188_207(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_207([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]==b)
    {
        if (is_legal_187_188_210(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_210([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]==b)
    {
        if (is_legal_187_188_350(rgCache))
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
    const auto old48_0 = coord;
    coord = direction_up[coord];
    if (is_legal_187_188_224(rgCache))
    {
        coord = old48_0;
        return true;
    }
    coord = old48_0;
    if (is_legal_187_188_351(rgCache))
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
    if (board[coord]==b)
    {
        if (is_legal_187_188_220(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_235([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]==b)
    {
        if (is_legal_187_188_239(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_239([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down_direction_down[coord]]==b)
    {
        if (is_legal_187_188_243(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_243([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down_direction_down[coord]]==b)
    {
        if (is_legal_187_188_247(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_247([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down___gen_direction_down_direction_down[coord]]==b)
    {
        if (is_legal_187_188_352(rgCache))
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
    const auto old54_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_187_188_259(rgCache))
    {
        coord = old54_0;
        return true;
    }
    coord = old54_0;
    if (is_legal_187_188_353(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_187_188_259([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_259;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_187_188_257(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_268([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_187_188_271(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_271([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4_RbgCoordMap4[coord]]==b)
    {
        if (is_legal_187_188_274(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_274([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]==b)
    {
        if (is_legal_187_188_277(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_277([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]==b)
    {
        if (is_legal_187_188_355(rgCache))
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
    const auto old60_0 = coord;
    coord = direction_left[coord];
    if (is_legal_187_188_291(rgCache))
    {
        coord = old60_0;
        return true;
    }
    coord = old60_0;
    if (is_legal_187_188_356(rgCache))
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
    if (board[coord]==b)
    {
        if (is_legal_187_188_287(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_302([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord]]==b)
    {
        if (is_legal_187_188_306(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_306([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right_direction_right[coord]]==b)
    {
        if (is_legal_187_188_310(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_310([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right_direction_right[coord]]==b)
    {
        if (is_legal_187_188_314(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_314([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right___gen_direction_right_direction_right[coord]]==b)
    {
        if (is_legal_187_188_357(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_349([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]!=b)
    {
        if (is_legal_187_188_201(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_350([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]!=b)
    {
        if (is_legal_187_188_188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_351([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord]]!=b)
    {
        if (is_legal_187_188_235(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_352([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down___gen_direction_down___gen_direction_down_direction_down[coord]]!=b)
    {
        if (is_legal_187_188_188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_353([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]!=b)
    {
        if (is_legal_187_188_268(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_355([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]!=b)
    {
        if (is_legal_187_188_188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_356([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord]]!=b)
    {
        if (is_legal_187_188_302(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_187_188_357([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right___gen_direction_right___gen_direction_right_direction_right[coord]]!=b)
    {
        if (is_legal_187_188_188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_106([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_25_26_109(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_109([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4_RbgCoordMap4[coord]]==w)
    {
        if (is_legal_25_26_112(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_112([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]==w)
    {
        if (is_legal_25_26_115(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_115([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]==w)
    {
        if (is_legal_25_26_346(rgCache))
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
    const auto old38_0 = coord;
    coord = direction_left[coord];
    if (is_legal_25_26_129(rgCache))
    {
        coord = old38_0;
        return true;
    }
    coord = old38_0;
    if (is_legal_25_26_347(rgCache))
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
    if (board[coord]==w)
    {
        if (is_legal_25_26_125(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_140([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord]]==w)
    {
        if (is_legal_25_26_144(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_144([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right_direction_right[coord]]==w)
    {
        if (is_legal_25_26_148(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_148([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right_direction_right[coord]]==w)
    {
        if (is_legal_25_26_152(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_152([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right___gen_direction_right_direction_right[coord]]==w)
    {
        if (is_legal_25_26_348(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_347(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_125(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_354(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_28(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_367(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_58(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_369(rgCache))
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

bool GameState::is_legal_25_26_28([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_28;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old52_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_25_26_30(rgCache))
    {
        coord = old52_0;
        return true;
    }
    coord = old52_0;
    if (is_legal_25_26_354(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_30([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_30;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_25_26_28(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_346([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4___gen_RbgCoordMap4_RbgCoordMap4[coord]]!=w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_347([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord]]!=w)
    {
        if (is_legal_25_26_140(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_348([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_right___gen_direction_right___gen_direction_right___gen_direction_right_direction_right[coord]]!=w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_354([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]!=w)
    {
        if (is_legal_25_26_39(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_366([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]!=w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_367([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_367;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_up[coord]]!=w)
    {
        if (is_legal_25_26_73(rgCache))
        {
            return true;
        }
    }
    if (is_legal_25_26_58(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_368([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down___gen_direction_down___gen_direction_down_direction_down[coord]]!=w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_369([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_369;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]!=w)
    {
        if (is_legal_25_26_106(rgCache))
        {
            return true;
        }
    }
    if (is_legal_25_26_95(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_39([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_25_26_42(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_42([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2_RbgCoordMap2[coord]]==w)
    {
        if (is_legal_25_26_45(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_45([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]==w)
    {
        if (is_legal_25_26_48(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_48([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap2___gen_RbgCoordMap2_RbgCoordMap2[coord]]==w)
    {
        if (is_legal_25_26_366(rgCache))
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
    const auto old58_0 = coord;
    coord = direction_up[coord];
    if (is_legal_25_26_62(rgCache))
    {
        coord = old58_0;
        return true;
    }
    coord = old58_0;
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
    if (board[coord]==w)
    {
        if (is_legal_25_26_367(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_73([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]==w)
    {
        if (is_legal_25_26_77(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_77([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down_direction_down[coord]]==w)
    {
        if (is_legal_25_26_81(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_81([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down_direction_down[coord]]==w)
    {
        if (is_legal_25_26_85(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_85([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_down___gen_direction_down___gen_direction_down_direction_down[coord]]==w)
    {
        if (is_legal_25_26_368(rgCache))
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
    const auto old64_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_25_26_97(rgCache))
    {
        coord = old64_0;
        return true;
    }
    coord = old64_0;
    return false;
}

bool GameState::is_legal_25_26_97([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_97;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_25_26_369(rgCache))
        {
            return true;
        }
    }
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old101_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    state_13(moves, mr,rgCache);    }
    coord = old101_0;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        state_165(moves, mr,rgCache);
        return;
    }
    state_338(moves, mr,rgCache);
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
    mr[0] = 0 + coord;
    state_16(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old116_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_163(moves, mr,rgCache);
    goals[white - 2] = old116_0;
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old117_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_165(moves, mr,rgCache);
    goals[black - 2] = old117_0;
}

void GameState::state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_172([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old119_0 = coord;
    for (coord = rx0y0; coord <= rx9y9; ++coord)
    {
    state_175(moves, mr,rgCache);    }
    coord = old119_0;
}

void GameState::state_173([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_172_178_172_172_178_178_172_178_172())
    {
        state_165(moves, mr,rgCache);
        return;
    }
    state_342(moves, mr,rgCache);
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
    mr[0] = 0 + coord;
    state_178(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_178([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_30.reset();
    rgCache.state_cache_367.reset();
    rgCache.state_cache_369.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_97.reset();
    const auto result_124 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_124)
    {
        state_161(moves, mr,rgCache);
        return;
    }
    state_23(moves, mr,rgCache);
}

void GameState::state_180([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_192.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_259.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_127 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (result_127)
    {
        state_323(moves, mr,rgCache);
        return;
    }
    state_8(moves, mr,rgCache);
}

void GameState::state_181([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old128_0 = board[coord];
    board[coord] = b;
    state_180(moves, mr,rgCache);
    board[coord] = old128_0;
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old142_0 = board[coord];
    board[coord] = w;
    state_18(moves, mr,rgCache);
    board[coord] = old142_0;
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = goals[black - 2];
    goals[black - 2] = 50;
    state_8(moves, mr,rgCache);
    goals[black - 2] = old100_0;
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_173(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_323([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old173_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_325(moves, mr,rgCache);
    goals[black - 2] = old173_0;
}

void GameState::state_325([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old218_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_165(moves, mr,rgCache);
    goals[white - 2] = old218_0;
}

void GameState::state_338([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_342([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_11(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old187_0 = goals[white - 2];
    goals[white - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[white - 2] = old187_0;
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 35;
            return true;
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
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_state_165(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_338(mr,rgCache))
    {
        return true;
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
    if (mr[0] == 0 + coord)
    {
        if (apply_state_16(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old190_0 = player;
    player = keeper;
    currentState = 35;
    return true;
    player = old190_0;
    return false;
}

bool GameState::apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old116_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_163(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old116_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old117_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_165(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old117_0;
    return false;
}

bool GameState::apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old118_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    player = old118_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 32;
            return true;
    }
    return false;
}

bool GameState::apply_state_172([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_173([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_172_178_172_172_178_178_172_178_172())
    {
        if (apply_state_165(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_342(mr,rgCache))
    {
        return true;
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
    if (mr[0] == 0 + coord)
    {
        if (apply_state_178(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_178([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = player;
    player = keeper;
    currentState = 32;
    return true;
    player = old193_0;
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_30.reset();
    rgCache.state_cache_367.reset();
    rgCache.state_cache_369.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_97.reset();
    const auto result_124 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_124)
    {
        if (apply_state_161(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_23(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_180([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_192.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_259.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_127 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (result_127)
    {
        if (apply_state_323(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            default:
                board[coord] = b;
                return apply_state_11(mr,rgCache);
        }
    }
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    board[coord] = b;
    goals[black - 2] = 100;
    goals[white - 2] = 0;
    player = keeper;
    currentState = 100;
    return true;
    return false;
}

bool GameState::apply_state_181([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            default:
                board[coord] = w;
                return apply_state_173(mr,rgCache);
        }
    }
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    board[coord] = w;
    goals[white - 2] = 100;
    goals[black - 2] = 0;
    player = keeper;
    currentState = 100;
    return true;
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old100_0;
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_173(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_323([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old173_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_325(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old173_0;
    return false;
}

bool GameState::apply_state_325([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old218_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_165(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old218_0;
    return false;
}

bool GameState::apply_state_338([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old189_0 = player;
    player = white;
    currentState = 1;
    return true;
    player = old189_0;
    return false;
}

bool GameState::apply_state_342([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old192_0 = player;
    player = black;
    currentState = 22;
    return true;
    player = old192_0;
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_11(mr,rgCache))
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
        default:
            goals[white - 2] = 50;
            goals[black - 2] = 50;
            return apply_state_11(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_4(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_181_181_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_181_181_11([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_181_181_165(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_181_181_338(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_181_181_165([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    if (apply_any_181_181_end(rgCache))
    {
        return true;
    }
    player = old10_0;
    return false;
}

bool GameState::apply_any_181_181_180([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_190.reset();
    rgCache.state_cache_192.reset();
    rgCache.state_cache_220.reset();
    rgCache.state_cache_224.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_259.reset();
    rgCache.state_cache_287.reset();
    rgCache.state_cache_291.reset();
    const auto result_12 = is_legal_187_188_187(rgCache);
    rgCache.decDepth();
    if (result_12)
    {
        if (apply_any_181_181_323(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_181_181_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_181_181_181([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = board[coord];
    board[coord] = b;
    if (apply_any_181_181_180(rgCache))
    {
        return true;
    }
    board[coord] = old13_0;
    return false;
}

bool GameState::apply_any_181_181_323([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_181_181_325(rgCache))
    {
        return true;
    }
    goals[black - 2] = old14_0;
    return false;
}

bool GameState::apply_any_181_181_325([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_181_181_165(rgCache))
    {
        return true;
    }
    goals[white - 2] = old18_0;
    return false;
}

bool GameState::apply_any_181_181_338([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = player;
    player = white;
    currentState = 1;
    return true;
    if (apply_any_181_181_10(rgCache))
    {
        return true;
    }
    player = old17_0;
    return false;
}

bool GameState::apply_any_181_181_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_181_181_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_181_181_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_161([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_19_19_163(rgCache))
    {
        return true;
    }
    goals[white - 2] = old10_0;
    return false;
}

bool GameState::apply_any_19_19_163([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_19_19_165(rgCache))
    {
        return true;
    }
    goals[black - 2] = old11_0;
    return false;
}

bool GameState::apply_any_19_19_165([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    if (apply_any_19_19_end(rgCache))
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_19_19_172([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_173([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_172_178_172_172_178_178_172_178_172())
    {
        if (apply_any_19_19_165(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_342(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_125.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_30.reset();
    rgCache.state_cache_367.reset();
    rgCache.state_cache_369.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_95.reset();
    rgCache.state_cache_97.reset();
    const auto result_13 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (apply_any_19_19_161(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_23(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = w;
    if (apply_any_19_19_18(rgCache))
    {
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::apply_any_19_19_23([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_19_19_173(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_342([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = player;
    player = black;
    currentState = 22;
    return true;
    if (apply_any_19_19_172(rgCache))
    {
        return true;
    }
    player = old18_0;
    return false;
}

bool GameState::apply_any_19_19_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_begin_begin_165(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_338(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_165([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old9_0;
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    const auto old8_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_any_begin_begin_8(rgCache))
    {
        return true;
    }
    goals[black - 2] = old8_0;
    return false;
}

bool GameState::apply_any_begin_begin_338([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = player;
    player = white;
    currentState = 1;
    return true;
    if (apply_any_begin_begin_10(rgCache))
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_begin_begin_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = goals[white - 2];
    goals[white - 2] = 50;
    if (apply_any_begin_begin_2(rgCache))
    {
        return true;
    }
    goals[white - 2] = old11_0;
    return false;
}

bool GameState::apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

}  // namespace reasoner
