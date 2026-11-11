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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "hx0y0: " << board[hx0y0] << ", " << "hx1y0: " << board[hx1y0] << ", " << "hx2y0: " << board[hx2y0] << ", " << "hx3y0: " << board[hx3y0] << ", " << "hx4y0: " << board[hx4y0] << ", " << "hx0y1: " << board[hx0y1] << ", " << "hx1y1: " << board[hx1y1] << ", " << "hx2y1: " << board[hx2y1] << ", " << "hx3y1: " << board[hx3y1] << ", " << "hx4y1: " << board[hx4y1] << ", " << "hx5y1: " << board[hx5y1] << ", " << "hx0y2: " << board[hx0y2] << ", " << "hx1y2: " << board[hx1y2] << ", " << "hx2y2: " << board[hx2y2] << ", " << "hx3y2: " << board[hx3y2] << ", " << "hx4y2: " << board[hx4y2] << ", " << "hx5y2: " << board[hx5y2] << ", " << "hx6y2: " << board[hx6y2] << ", " << "hx0y3: " << board[hx0y3] << ", " << "hx1y3: " << board[hx1y3] << ", " << "hx2y3: " << board[hx2y3] << ", " << "hx3y3: " << board[hx3y3] << ", " << "hx4y3: " << board[hx4y3] << ", " << "hx5y3: " << board[hx5y3] << ", " << "hx6y3: " << board[hx6y3] << ", " << "hx7y3: " << board[hx7y3] << ", " << "hx0y4: " << board[hx0y4] << ", " << "hx1y4: " << board[hx1y4] << ", " << "hx2y4: " << board[hx2y4] << ", " << "hx3y4: " << board[hx3y4] << ", " << "hx4y4: " << board[hx4y4] << ", " << "hx5y4: " << board[hx5y4] << ", " << "hx6y4: " << board[hx6y4] << ", " << "hx7y4: " << board[hx7y4] << ", " << "hx8y4: " << board[hx8y4] << ", " << "hx0y5: " << board[hx0y5] << ", " << "hx1y5: " << board[hx1y5] << ", " << "hx2y5: " << board[hx2y5] << ", " << "hx3y5: " << board[hx3y5] << ", " << "hx4y5: " << board[hx4y5] << ", " << "hx5y5: " << board[hx5y5] << ", " << "hx6y5: " << board[hx6y5] << ", " << "hx7y5: " << board[hx7y5] << ", " << "hx0y6: " << board[hx0y6] << ", " << "hx1y6: " << board[hx1y6] << ", " << "hx2y6: " << board[hx2y6] << ", " << "hx3y6: " << board[hx3y6] << ", " << "hx4y6: " << board[hx4y6] << ", " << "hx5y6: " << board[hx5y6] << ", " << "hx6y6: " << board[hx6y6] << ", " << "hx0y7: " << board[hx0y7] << ", " << "hx1y7: " << board[hx1y7] << ", " << "hx2y7: " << board[hx2y7] << ", " << "hx3y7: " << board[hx3y7] << ", " << "hx4y7: " << board[hx4y7] << ", " << "hx5y7: " << board[hx5y7] << ", " << "hx0y8: " << board[hx0y8] << ", " << "hx1y8: " << board[hx1y8] << ", " << "hx2y8: " << board[hx2y8] << ", " << "hx3y8: " << board[hx3y8] << ", " << "hx4y8: " << board[hx4y8]<< "}" << std::endl;
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
        case 20:
{
            state_151(moves, mr.mr,rgCache);
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
        case 20:
{
            apply_state_151(mr.mr,rgCache);
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
        case 30:
{
            apply_any_160_160_160(rgCache);
            break;
}
        case 40:
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
    for (coord = hx0y0; coord <= hx8y4; ++coord)
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

bool GameState::is_legal_151_157_151_151_157_157_151_157_151()
{
    const auto old3_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    if (is_legal_151_157_151_151_157_157_151_157_154())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_154()
{
    if (board[coord]==e)
    {
        if (is_legal_151_157_151_151_157_157_151_157_157())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_157()
{
    return true;
}

bool GameState::is_legal_166_167_166([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_177(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_169(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_192(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_184(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_207(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_199(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_167([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_166_167_169([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_169;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old20_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_166_167_173(rgCache))
    {
        coord = old20_0;
        return true;
    }
    coord = old20_0;
    if (is_legal_166_167_177(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_173([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_173;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_166_167_169(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_177([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SW[coord]]==b)
    {
        if (is_legal_166_167_181(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_181([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW_direction_SW[coord]]==b)
    {
        if (is_legal_166_167_167(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_184([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_184;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old24_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_166_167_188(rgCache))
    {
        coord = old24_0;
        return true;
    }
    coord = old24_0;
    if (is_legal_166_167_192(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_188([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_188;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_166_167_184(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_192([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SE[coord]]==b)
    {
        if (is_legal_166_167_196(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_196([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE_direction_SE[coord]]==b)
    {
        if (is_legal_166_167_167(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_199([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_199;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old28_0 = coord;
    coord = direction_W[coord];
    if (is_legal_166_167_203(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    if (is_legal_166_167_207(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_203([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_203;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_166_167_199(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_207([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_E[coord]]==b)
    {
        if (is_legal_166_167_211(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_211([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E_direction_E[coord]]==b)
    {
        if (is_legal_166_167_167(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_216([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_227(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_219(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_246(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_238(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_265(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_257(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_217([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_216_217_219([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_219;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old23_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_216_217_223(rgCache))
    {
        coord = old23_0;
        return true;
    }
    coord = old23_0;
    if (is_legal_216_217_227(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_223([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_223;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_216_217_219(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_227([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SW[coord]]==b)
    {
        if (is_legal_216_217_231(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_231([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW_direction_SW[coord]]==b)
    {
        if (is_legal_216_217_235(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_235([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW___gen_direction_SW_direction_SW[coord]]==b)
    {
        if (is_legal_216_217_217(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_238([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_238;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old28_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_216_217_242(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    if (is_legal_216_217_246(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_242([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_242;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_216_217_238(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_246([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SE[coord]]==b)
    {
        if (is_legal_216_217_250(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_250([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE_direction_SE[coord]]==b)
    {
        if (is_legal_216_217_254(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_254([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE___gen_direction_SE_direction_SE[coord]]==b)
    {
        if (is_legal_216_217_217(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_257([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old33_0 = coord;
    coord = direction_W[coord];
    if (is_legal_216_217_261(rgCache))
    {
        coord = old33_0;
        return true;
    }
    coord = old33_0;
    if (is_legal_216_217_265(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_261([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_261;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_216_217_257(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_265([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_E[coord]]==b)
    {
        if (is_legal_216_217_269(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_269([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E_direction_E[coord]]==b)
    {
        if (is_legal_216_217_273(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_273([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E___gen_direction_E_direction_E[coord]]==b)
    {
        if (is_legal_216_217_217(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_36(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_28(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_51(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_43(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_66(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_58(rgCache))
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
    const auto old20_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_25_26_32(rgCache))
    {
        coord = old20_0;
        return true;
    }
    coord = old20_0;
    if (is_legal_25_26_36(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_32([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_32;
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

bool GameState::is_legal_25_26_36([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SW[coord]]==w)
    {
        if (is_legal_25_26_40(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_40([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW_direction_SW[coord]]==w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_43([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_43;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old24_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_25_26_47(rgCache))
    {
        coord = old24_0;
        return true;
    }
    coord = old24_0;
    if (is_legal_25_26_51(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_47([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_47;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_25_26_43(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_51([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SE[coord]]==w)
    {
        if (is_legal_25_26_55(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_55([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE_direction_SE[coord]]==w)
    {
        if (is_legal_25_26_26(rgCache))
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
    const auto old28_0 = coord;
    coord = direction_W[coord];
    if (is_legal_25_26_62(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    if (is_legal_25_26_66(rgCache))
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
    if (board[coord]==w)
    {
        if (is_legal_25_26_58(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_66([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_E[coord]]==w)
    {
        if (is_legal_25_26_70(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_70([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E_direction_E[coord]]==w)
    {
        if (is_legal_25_26_26(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_100([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_100;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_75_76_105(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_105([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_105;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_SE[coord]]==w)
    {
        if (is_legal_75_76_109(rgCache))
        {
            return true;
        }
    }
    if (is_legal_75_76_97(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_109([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE_direction_SE[coord]]==w)
    {
        if (is_legal_75_76_113(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_113([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SE___gen_direction_SE_direction_SE[coord]]==w)
    {
        if (is_legal_75_76_76(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_116([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_116;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old20_0 = coord;
    coord = direction_W[coord];
    if (is_legal_75_76_120(rgCache))
    {
        coord = old20_0;
        return true;
    }
    coord = old20_0;
    if (is_legal_75_76_124(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_120([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_120;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_75_76_116(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_124([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_E[coord]]==w)
    {
        if (is_legal_75_76_128(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_128([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E_direction_E[coord]]==w)
    {
        if (is_legal_75_76_132(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_132([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_E___gen_direction_E_direction_E[coord]]==w)
    {
        if (is_legal_75_76_76(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_75([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_124(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_116(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_86(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_78(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_105(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_97(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_76([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_75_76_78([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_78;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old31_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_75_76_82(rgCache))
    {
        coord = old31_0;
        return true;
    }
    coord = old31_0;
    if (is_legal_75_76_86(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_82([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_82;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_75_76_78(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_86([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_SW[coord]]==w)
    {
        if (is_legal_75_76_90(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_90([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW_direction_SW[coord]]==w)
    {
        if (is_legal_75_76_94(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_94([[maybe_unused]]RgCache& rgCache)
{
    if (board[__gen_direction_SW___gen_direction_SW_direction_SW[coord]]==w)
    {
        if (is_legal_75_76_76(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_97([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_97;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old36_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_75_76_100(rgCache))
    {
        coord = old36_0;
        return true;
    }
    coord = old36_0;
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old101_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    state_13(moves, mr,rgCache);    }
    coord = old101_0;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        state_214(moves, mr,rgCache);
        return;
    }
    state_296(moves, mr,rgCache);
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_14(moves, mr,rgCache);
    }
}

void GameState::state_135([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old229_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_214(moves, mr,rgCache);
    goals[black - 2] = old229_0;
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_16(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old114_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_142(moves, mr,rgCache);
    goals[white - 2] = old114_0;
}

void GameState::state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_214(moves, mr,rgCache);
    goals[black - 2] = old230_0;
}

void GameState::state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old115_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    state_154(moves, mr,rgCache);    }
    coord = old115_0;
}

void GameState::state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_151_157_151_151_157_157_151_157_151())
    {
        state_214(moves, mr,rgCache);
        return;
    }
    state_300(moves, mr,rgCache);
}

void GameState::state_154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_155(moves, mr,rgCache);
    }
}

void GameState::state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_157(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_159([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_169.reset();
    rgCache.state_cache_173.reset();
    rgCache.state_cache_184.reset();
    rgCache.state_cache_188.reset();
    rgCache.state_cache_199.reset();
    rgCache.state_cache_203.reset();
    const auto result_121 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (result_121)
    {
        state_213(moves, mr,rgCache);
        return;
    }
    state_8(moves, mr,rgCache);
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old122_0 = board[coord];
    board[coord] = b;
    state_159(moves, mr,rgCache);
    board[coord] = old122_0;
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_133 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_133)
    {
        state_23(moves, mr,rgCache);
        return;
    }
    state_72(moves, mr,rgCache);
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old143_0 = board[coord];
    board[coord] = w;
    state_18(moves, mr,rgCache);
    board[coord] = old143_0;
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = goals[black - 2];
    goals[black - 2] = 50;
    state_8(moves, mr,rgCache);
    goals[black - 2] = old100_0;
}

void GameState::state_213([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_219.reset();
    rgCache.state_cache_223.reset();
    rgCache.state_cache_238.reset();
    rgCache.state_cache_242.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_261.reset();
    const auto result_144 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_144)
    {
        state_215(moves, mr,rgCache);
        return;
    }
    state_281(moves, mr,rgCache);
}

void GameState::state_214([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_215([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_276(moves, mr,rgCache);
    goals[black - 2] = old146_0;
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_152(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_276([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_214(moves, mr,rgCache);
    goals[white - 2] = old175_0;
}

void GameState::state_281([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_283(moves, mr,rgCache);
    goals[black - 2] = old177_0;
}

void GameState::state_283([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_214(moves, mr,rgCache);
    goals[white - 2] = old178_0;
}

void GameState::state_296([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_300([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_105.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_191 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_191)
    {
        state_140(moves, mr,rgCache);
        return;
    }
    state_74(moves, mr,rgCache);
}

void GameState::state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_135(moves, mr,rgCache);
    goals[white - 2] = old193_0;
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_11(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old208_0 = goals[white - 2];
    goals[white - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[white - 2] = old208_0;
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
            currentState = 40;
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
        if (apply_state_214(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_296(mr,rgCache))
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

bool GameState::apply_state_135([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old229_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old229_0;
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

bool GameState::apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old114_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_142(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old114_0;
    return false;
}

bool GameState::apply_state_142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old230_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 30;
            return true;
    }
    return false;
}

bool GameState::apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_151_157_151_151_157_157_151_157_151())
    {
        if (apply_state_214(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_300(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_155(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_157(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old214_0 = player;
    player = keeper;
    currentState = 30;
    return true;
    player = old214_0;
    return false;
}

bool GameState::apply_state_159([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_169.reset();
    rgCache.state_cache_173.reset();
    rgCache.state_cache_184.reset();
    rgCache.state_cache_188.reset();
    rgCache.state_cache_199.reset();
    rgCache.state_cache_203.reset();
    const auto result_121 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (result_121)
    {
        if (apply_state_213(mr,rgCache))
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

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old211_0 = player;
    player = keeper;
    currentState = 40;
    return true;
    player = old211_0;
    return false;
}

bool GameState::apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old122_0 = board[coord];
    board[coord] = b;
    if (apply_state_159(mr,rgCache))
    {
        return true;
    }
    board[coord] = old122_0;
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_133 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_133)
    {
        if (apply_state_23(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_72(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old143_0 = board[coord];
    board[coord] = w;
    if (apply_state_18(mr,rgCache))
    {
        return true;
    }
    board[coord] = old143_0;
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

bool GameState::apply_state_213([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_219.reset();
    rgCache.state_cache_223.reset();
    rgCache.state_cache_238.reset();
    rgCache.state_cache_242.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_261.reset();
    const auto result_144 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_144)
    {
        if (apply_state_215(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_281(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_214([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old179_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    player = old179_0;
    return false;
}

bool GameState::apply_state_215([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_276(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old146_0;
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_152(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_276([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old175_0;
    return false;
}

bool GameState::apply_state_281([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_283(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old177_0;
    return false;
}

bool GameState::apply_state_283([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old178_0;
    return false;
}

bool GameState::apply_state_296([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old210_0 = player;
    player = white;
    currentState = 1;
    return true;
    player = old210_0;
    return false;
}

bool GameState::apply_state_300([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old213_0 = player;
    player = black;
    currentState = 20;
    return true;
    player = old213_0;
    return false;
}

bool GameState::apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_105.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_191 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_191)
    {
        if (apply_state_140(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_74(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_135(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old193_0;
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

bool GameState::switch_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_160_160_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_160_160_11([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_160_160_214(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_160_160_296(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_160_160_159([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_169.reset();
    rgCache.state_cache_173.reset();
    rgCache.state_cache_184.reset();
    rgCache.state_cache_188.reset();
    rgCache.state_cache_199.reset();
    rgCache.state_cache_203.reset();
    const auto result_14 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (result_14)
    {
        if (apply_any_160_160_213(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_160_160_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_160_160_160([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = b;
    if (apply_any_160_160_159(rgCache))
    {
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::apply_any_160_160_213([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_219.reset();
    rgCache.state_cache_223.reset();
    rgCache.state_cache_238.reset();
    rgCache.state_cache_242.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_261.reset();
    const auto result_16 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_16)
    {
        if (apply_any_160_160_215(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_160_160_281(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_160_160_214([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    if (apply_any_160_160_end(rgCache))
    {
        return true;
    }
    player = old22_0;
    return false;
}

bool GameState::apply_any_160_160_215([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_160_160_276(rgCache))
    {
        return true;
    }
    goals[black - 2] = old18_0;
    return false;
}

bool GameState::apply_any_160_160_276([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_160_160_214(rgCache))
    {
        return true;
    }
    goals[white - 2] = old19_0;
    return false;
}

bool GameState::apply_any_160_160_281([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_160_160_283(rgCache))
    {
        return true;
    }
    goals[black - 2] = old20_0;
    return false;
}

bool GameState::apply_any_160_160_283([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_160_160_214(rgCache))
    {
        return true;
    }
    goals[white - 2] = old21_0;
    return false;
}

bool GameState::apply_any_160_160_296([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = player;
    player = white;
    currentState = 1;
    return true;
    if (apply_any_160_160_10(rgCache))
    {
        return true;
    }
    player = old25_0;
    return false;
}

bool GameState::apply_any_160_160_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_160_160_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_160_160_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_135([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_19_19_214(rgCache))
    {
        return true;
    }
    goals[black - 2] = old25_0;
    return false;
}

bool GameState::apply_any_19_19_140([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_19_19_142(rgCache))
    {
        return true;
    }
    goals[white - 2] = old13_0;
    return false;
}

bool GameState::apply_any_19_19_142([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_19_19_214(rgCache))
    {
        return true;
    }
    goals[black - 2] = old26_0;
    return false;
}

bool GameState::apply_any_19_19_151([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_152([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_151_157_151_151_157_157_151_157_151())
    {
        if (apply_any_19_19_214(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_300(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_14 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_14)
    {
        if (apply_any_19_19_23(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_72(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = board[coord];
    board[coord] = w;
    if (apply_any_19_19_18(rgCache))
    {
        return true;
    }
    board[coord] = old16_0;
    return false;
}

bool GameState::apply_any_19_19_214([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = player;
    player = keeper;
    currentState = 100;
    return true;
    if (apply_any_19_19_end(rgCache))
    {
        return true;
    }
    player = old18_0;
    return false;
}

bool GameState::apply_any_19_19_23([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_19_19_152(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_300([[maybe_unused]]RgCache& rgCache)
{
    const auto old23_0 = player;
    player = black;
    currentState = 20;
    return true;
    if (apply_any_19_19_151(rgCache))
    {
        return true;
    }
    player = old23_0;
    return false;
}

bool GameState::apply_any_19_19_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_105.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_19 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_19)
    {
        if (apply_any_19_19_140(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_74(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_74([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_19_19_135(rgCache))
    {
        return true;
    }
    goals[white - 2] = old21_0;
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
        if (apply_any_begin_begin_214(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_296(rgCache))
    {
        return true;
    }
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

bool GameState::apply_any_begin_begin_214([[maybe_unused]]RgCache& rgCache)
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

bool GameState::apply_any_begin_begin_296([[maybe_unused]]RgCache& rgCache)
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
