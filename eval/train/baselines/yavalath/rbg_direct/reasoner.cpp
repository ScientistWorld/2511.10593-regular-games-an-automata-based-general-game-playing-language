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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "hx0y0: " << board[hx0y0] << ", " << "hx1y0: " << board[hx1y0] << ", " << "hx2y0: " << board[hx2y0] << ", " << "hx3y0: " << board[hx3y0] << ", " << "hx4y0: " << board[hx4y0] << ", " << "hx0y1: " << board[hx0y1] << ", " << "hx1y1: " << board[hx1y1] << ", " << "hx2y1: " << board[hx2y1] << ", " << "hx3y1: " << board[hx3y1] << ", " << "hx4y1: " << board[hx4y1] << ", " << "hx5y1: " << board[hx5y1] << ", " << "hx0y2: " << board[hx0y2] << ", " << "hx1y2: " << board[hx1y2] << ", " << "hx2y2: " << board[hx2y2] << ", " << "hx3y2: " << board[hx3y2] << ", " << "hx4y2: " << board[hx4y2] << ", " << "hx5y2: " << board[hx5y2] << ", " << "hx6y2: " << board[hx6y2] << ", " << "hx0y3: " << board[hx0y3] << ", " << "hx1y3: " << board[hx1y3] << ", " << "hx2y3: " << board[hx2y3] << ", " << "hx3y3: " << board[hx3y3] << ", " << "hx4y3: " << board[hx4y3] << ", " << "hx5y3: " << board[hx5y3] << ", " << "hx6y3: " << board[hx6y3] << ", " << "hx7y3: " << board[hx7y3] << ", " << "hx0y4: " << board[hx0y4] << ", " << "hx1y4: " << board[hx1y4] << ", " << "hx2y4: " << board[hx2y4] << ", " << "hx3y4: " << board[hx3y4] << ", " << "hx4y4: " << board[hx4y4] << ", " << "hx5y4: " << board[hx5y4] << ", " << "hx6y4: " << board[hx6y4] << ", " << "hx7y4: " << board[hx7y4] << ", " << "hx8y4: " << board[hx8y4] << ", " << "hx0y5: " << board[hx0y5] << ", " << "hx1y5: " << board[hx1y5] << ", " << "hx2y5: " << board[hx2y5] << ", " << "hx3y5: " << board[hx3y5] << ", " << "hx4y5: " << board[hx4y5] << ", " << "hx5y5: " << board[hx5y5] << ", " << "hx6y5: " << board[hx6y5] << ", " << "hx7y5: " << board[hx7y5] << ", " << "hx0y6: " << board[hx0y6] << ", " << "hx1y6: " << board[hx1y6] << ", " << "hx2y6: " << board[hx2y6] << ", " << "hx3y6: " << board[hx3y6] << ", " << "hx4y6: " << board[hx4y6] << ", " << "hx5y6: " << board[hx5y6] << ", " << "hx6y6: " << board[hx6y6] << ", " << "hx0y7: " << board[hx0y7] << ", " << "hx1y7: " << board[hx1y7] << ", " << "hx2y7: " << board[hx2y7] << ", " << "hx3y7: " << board[hx3y7] << ", " << "hx4y7: " << board[hx4y7] << ", " << "hx5y7: " << board[hx5y7] << ", " << "hx0y8: " << board[hx0y8] << ", " << "hx1y8: " << board[hx1y8] << ", " << "hx2y8: " << board[hx2y8] << ", " << "hx3y8: " << board[hx3y8] << ", " << "hx4y8: " << board[hx4y8]<< "}" << std::endl;
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
        case 2:
{
            state_10(moves, mr.mr,rgCache);
            return;
}
        case 63:
{
            state_151(moves, mr.mr,rgCache);
            return;
}
        case 381:
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
        case 2:
{
            apply_state_10(mr.mr,rgCache);
            return;
}
        case 63:
{
            apply_state_151(mr.mr,rgCache);
            return;
}
        case 381:
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
        case 61:
{
            apply_any_15_15_15(rgCache);
            break;
}
        case 73:
{
            apply_any_156_156_156(rgCache);
            break;
}
        case 381:
{
            apply_any_begin_begin_begin(rgCache);
            break;
}
    }
}

bool GameState::is_legal_10_16_10_10_16_16_10_16_10()
{
    const auto old5_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
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

bool GameState::is_legal_151_157_151_151_157_157_151_157_151()
{
    const auto old5_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    if (is_legal_151_157_151_151_157_157_151_157_154())
    {
        coord = old5_0;
        return true;
    }    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_154()
{
    if (board[coord]==e)
    {
        if (is_legal_151_157_151_151_157_157_151_157_155())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_155()
{
    if (is_legal_151_157_151_151_157_157_151_157_158())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_157()
{
    return true;
}

bool GameState::is_legal_151_157_151_151_157_157_151_157_158()
{
    if (is_legal_151_157_151_151_157_157_151_157_157())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_11([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_12([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_156_11_156_156_11_11_156_11_160(rgCache))
    {
        counters[board[coord]] = old13_0;
        return true;
    }
    counters[board[coord]] = old13_0;
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_159([[maybe_unused]]RgCache& rgCache)
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
    if (!result_14)
    {
        if (is_legal_156_11_156_156_11_11_156_11_165(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_160([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_156_11_156_156_11_11_156_11_161(rgCache))
    {
        counters[b] = old15_0;
        return true;
    }
    counters[b] = old15_0;
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_161([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_163(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = board[coord];
    board[coord] = b;
    if (is_legal_156_11_156_156_11_11_156_11_159(rgCache))
    {
        board[coord] = old17_0;
        return true;
    }
    board[coord] = old17_0;
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_163([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_164([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_165([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_8([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_11_156_156_11_11_156_11_9([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_156_289_156_156_289_289_156_289_160(rgCache))
    {
        counters[board[coord]] = old24_0;
        return true;
    }
    counters[board[coord]] = old24_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_159([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_169.reset();
    rgCache.state_cache_173.reset();
    rgCache.state_cache_184.reset();
    rgCache.state_cache_188.reset();
    rgCache.state_cache_199.reset();
    rgCache.state_cache_203.reset();
    const auto result_25 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (result_25)
    {
        if (is_legal_156_289_156_156_289_289_156_289_213(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_160([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_156_289_156_156_289_289_156_289_161(rgCache))
    {
        counters[b] = old26_0;
        return true;
    }
    counters[b] = old26_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_161([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_163(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old28_0 = board[coord];
    board[coord] = b;
    if (is_legal_156_289_156_156_289_289_156_289_159(rgCache))
    {
        board[coord] = old28_0;
        return true;
    }
    board[coord] = old28_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_163([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_213([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_219.reset();
    rgCache.state_cache_223.reset();
    rgCache.state_cache_238.reset();
    rgCache.state_cache_242.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_261.reset();
    const auto result_30 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_30)
    {
        if (is_legal_156_289_156_156_289_289_156_289_215(rgCache))
        {
            return true;
        }
        return false;
    }
    if (is_legal_156_289_156_156_289_289_156_289_281(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_214([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_290(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_215([[maybe_unused]]RgCache& rgCache)
{
    const auto old33_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_156_289_156_156_289_289_156_289_276(rgCache))
    {
        goals[black - 2] = old33_0;
        return true;
    }
    goals[black - 2] = old33_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_275([[maybe_unused]]RgCache& rgCache)
{
    const auto old34_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_156_289_156_156_289_289_156_289_279(rgCache))
    {
        goals[white - 2] = old34_0;
        return true;
    }
    goals[white - 2] = old34_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_276([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_277(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_277([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_275(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_278([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_214(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_279([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_280(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_280([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_278(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_281([[maybe_unused]]RgCache& rgCache)
{
    const auto old40_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_156_289_156_156_289_289_156_289_283(rgCache))
    {
        goals[black - 2] = old40_0;
        return true;
    }
    goals[black - 2] = old40_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_282([[maybe_unused]]RgCache& rgCache)
{
    const auto old41_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_156_289_156_156_289_289_156_289_286(rgCache))
    {
        goals[white - 2] = old41_0;
        return true;
    }
    goals[white - 2] = old41_0;
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_283([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_284(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_284([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_282(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_285([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_214(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_286([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_287(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_287([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_285(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_289([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_156_289_156_156_289_289_156_289_290([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_289_156_156_289_289_156_289_289(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_134([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (is_legal_15_148_15_15_148_148_15_148_138(rgCache))
    {
        goals[black - 2] = old24_0;
        return true;
    }
    goals[black - 2] = old24_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_135([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_136(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_136([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_134(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_137([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_73(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_138([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_139(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_139([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_137(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_140([[maybe_unused]]RgCache& rgCache)
{
    const auto old30_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (is_legal_15_148_15_15_148_148_15_148_142(rgCache))
    {
        goals[white - 2] = old30_0;
        return true;
    }
    goals[white - 2] = old30_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old31_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (is_legal_15_148_15_15_148_148_15_148_145(rgCache))
    {
        goals[black - 2] = old31_0;
        return true;
    }
    goals[black - 2] = old31_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_142([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_143([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_141(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_144([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_73(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_145([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_146(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_146([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_144(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_148([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_149([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_148(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old38_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_15_148_15_15_148_148_15_148_19(rgCache))
    {
        counters[board[coord]] = old38_0;
        return true;
    }
    counters[board[coord]] = old38_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_39 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (result_39)
    {
        if (is_legal_15_148_15_15_148_148_15_148_72(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old40_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_15_148_15_15_148_148_15_148_20(rgCache))
    {
        counters[w] = old40_0;
        return true;
    }
    counters[w] = old40_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old42_0 = board[coord];
    board[coord] = w;
    if (is_legal_15_148_15_15_148_148_15_148_18(rgCache))
    {
        board[coord] = old42_0;
        return true;
    }
    board[coord] = old42_0;
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_44 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_44)
    {
        if (is_legal_15_148_15_15_148_148_15_148_140(rgCache))
        {
            return true;
        }
        return false;
    }
    if (is_legal_15_148_15_15_148_148_15_148_74(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_73([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_149(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_148_15_15_148_148_15_148_74([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (is_legal_15_148_15_15_148_148_15_148_135(rgCache))
    {
        goals[white - 2] = old47_0;
        return true;
    }
    goals[white - 2] = old47_0;
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_15_152_15_15_152_152_15_152_19(rgCache))
    {
        counters[board[coord]] = old10_0;
        return true;
    }
    counters[board[coord]] = old10_0;
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_152([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_153([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_152_15_15_152_152_15_152_152(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_12 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_12)
    {
        if (is_legal_15_152_15_15_152_152_15_152_24(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_15_152_15_15_152_152_15_152_20(rgCache))
    {
        counters[w] = old13_0;
        return true;
    }
    counters[w] = old13_0;
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_152_15_15_152_152_15_152_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = w;
    if (is_legal_15_152_15_15_152_152_15_152_18(rgCache))
    {
        board[coord] = old15_0;
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_152_15_15_152_152_15_152_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_23([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_152_15_15_152_152_15_152_153(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_15_152_15_15_152_152_15_152_24([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_152_15_15_152_152_15_152_23(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_166([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_168(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_169(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_183(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_184(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_198(rgCache))
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

bool GameState::is_legal_166_167_168([[maybe_unused]]RgCache& rgCache)
{
    const auto old53_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_166_167_177(rgCache))
    {
        coord = old53_0;
        return true;
    }
    coord = old53_0;
    return false;
}

bool GameState::is_legal_166_167_169([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_169;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old54_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_166_167_173(rgCache))
    {
        coord = old54_0;
        return true;
    }
    coord = old54_0;
    return false;
}

bool GameState::is_legal_166_167_170([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_168(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_169(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_171([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_174(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_172([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_171(rgCache))
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
    if (is_legal_166_167_172(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_174([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_170(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_175([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_178(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_176([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_175(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_177([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_176(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_178([[maybe_unused]]RgCache& rgCache)
{
    const auto old64_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_166_167_181(rgCache))
    {
        coord = old64_0;
        return true;
    }
    coord = old64_0;
    return false;
}

bool GameState::is_legal_166_167_179([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_182(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_180([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_179(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_181([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_180(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_182([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_183([[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_166_167_192(rgCache))
    {
        coord = old69_0;
        return true;
    }
    coord = old69_0;
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
    const auto old70_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_166_167_188(rgCache))
    {
        coord = old70_0;
        return true;
    }
    coord = old70_0;
    return false;
}

bool GameState::is_legal_166_167_185([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_183(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_184(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_186([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_189(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_187([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_186(rgCache))
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
    if (is_legal_166_167_187(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_189([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_185(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_190([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_193(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_191([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_190(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_192([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_191(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_193([[maybe_unused]]RgCache& rgCache)
{
    const auto old80_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_166_167_196(rgCache))
    {
        coord = old80_0;
        return true;
    }
    coord = old80_0;
    return false;
}

bool GameState::is_legal_166_167_194([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_197(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_195([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_194(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_196([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_195(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_197([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_198([[maybe_unused]]RgCache& rgCache)
{
    const auto old85_0 = coord;
    coord = direction_E[coord];
    if (is_legal_166_167_207(rgCache))
    {
        coord = old85_0;
        return true;
    }
    coord = old85_0;
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
    const auto old86_0 = coord;
    coord = direction_W[coord];
    if (is_legal_166_167_203(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::is_legal_166_167_200([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_198(rgCache))
    {
        return true;
    }
    if (is_legal_166_167_199(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_201([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_204(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_202([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_201(rgCache))
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
    if (is_legal_166_167_202(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_204([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_200(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_205([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_208(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_206([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_205(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_207([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_206(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_208([[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = coord;
    coord = direction_E[coord];
    if (is_legal_166_167_211(rgCache))
    {
        coord = old96_0;
        return true;
    }
    coord = old96_0;
    return false;
}

bool GameState::is_legal_166_167_209([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_166_167_212(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_210([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_209(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_211([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_210(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_212([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_216([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_218(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_219(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_237(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_238(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_256(rgCache))
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

bool GameState::is_legal_216_217_218([[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_216_217_227(rgCache))
    {
        coord = old65_0;
        return true;
    }
    coord = old65_0;
    return false;
}

bool GameState::is_legal_216_217_219([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_219;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old66_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_216_217_223(rgCache))
    {
        coord = old66_0;
        return true;
    }
    coord = old66_0;
    return false;
}

bool GameState::is_legal_216_217_220([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_218(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_219(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_221([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_224(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_222([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_221(rgCache))
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
    if (is_legal_216_217_222(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_224([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_220(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_225([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_228(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_226([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_225(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_227([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_226(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_228([[maybe_unused]]RgCache& rgCache)
{
    const auto old76_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_216_217_231(rgCache))
    {
        coord = old76_0;
        return true;
    }
    coord = old76_0;
    return false;
}

bool GameState::is_legal_216_217_229([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_232(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_230([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_229(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_231([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_230(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_232([[maybe_unused]]RgCache& rgCache)
{
    const auto old80_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_216_217_235(rgCache))
    {
        coord = old80_0;
        return true;
    }
    coord = old80_0;
    return false;
}

bool GameState::is_legal_216_217_233([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_236(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_234([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_233(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_235([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_234(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_236([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_217(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_237([[maybe_unused]]RgCache& rgCache)
{
    const auto old85_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_216_217_246(rgCache))
    {
        coord = old85_0;
        return true;
    }
    coord = old85_0;
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
    const auto old86_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_216_217_242(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::is_legal_216_217_239([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_237(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_238(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_240([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_243(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_241([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_240(rgCache))
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
    if (is_legal_216_217_241(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_243([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_239(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_244([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_247(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_245([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_244(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_246([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_245(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_247([[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_216_217_250(rgCache))
    {
        coord = old96_0;
        return true;
    }
    coord = old96_0;
    return false;
}

bool GameState::is_legal_216_217_248([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_251(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_249([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_248(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_250([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_249(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_251([[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_216_217_254(rgCache))
    {
        coord = old100_0;
        return true;
    }
    coord = old100_0;
    return false;
}

bool GameState::is_legal_216_217_252([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_255(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_253([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_252(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_254([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_253(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_255([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_217(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_256([[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = coord;
    coord = direction_E[coord];
    if (is_legal_216_217_265(rgCache))
    {
        coord = old105_0;
        return true;
    }
    coord = old105_0;
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
    const auto old106_0 = coord;
    coord = direction_W[coord];
    if (is_legal_216_217_261(rgCache))
    {
        coord = old106_0;
        return true;
    }
    coord = old106_0;
    return false;
}

bool GameState::is_legal_216_217_258([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_256(rgCache))
    {
        return true;
    }
    if (is_legal_216_217_257(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_259([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_262(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_260([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_259(rgCache))
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
    if (is_legal_216_217_260(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_262([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_258(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_263([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_264([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_263(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_265([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_264(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_266([[maybe_unused]]RgCache& rgCache)
{
    const auto old116_0 = coord;
    coord = direction_E[coord];
    if (is_legal_216_217_269(rgCache))
    {
        coord = old116_0;
        return true;
    }
    coord = old116_0;
    return false;
}

bool GameState::is_legal_216_217_267([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_270(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_268([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_267(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_269([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_268(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_270([[maybe_unused]]RgCache& rgCache)
{
    const auto old120_0 = coord;
    coord = direction_E[coord];
    if (is_legal_216_217_273(rgCache))
    {
        coord = old120_0;
        return true;
    }
    coord = old120_0;
    return false;
}

bool GameState::is_legal_216_217_271([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_216_217_274(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_216_217_272([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_271(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_273([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_272(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_216_217_274([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_216_217_217(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_27(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_28(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_42(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_43(rgCache))
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
    return false;
}

bool GameState::is_legal_25_26_26([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_25_26_27([[maybe_unused]]RgCache& rgCache)
{
    const auto old53_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_25_26_36(rgCache))
    {
        coord = old53_0;
        return true;
    }
    coord = old53_0;
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
    const auto old54_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_25_26_32(rgCache))
    {
        coord = old54_0;
        return true;
    }
    coord = old54_0;
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
        if (is_legal_25_26_33(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_31([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_30(rgCache))
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
    if (is_legal_25_26_31(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_33([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_29(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_34([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_37(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_35([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_34(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_36([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_35(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_37([[maybe_unused]]RgCache& rgCache)
{
    const auto old64_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_25_26_40(rgCache))
    {
        coord = old64_0;
        return true;
    }
    coord = old64_0;
    return false;
}

bool GameState::is_legal_25_26_38([[maybe_unused]]RgCache& rgCache)
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

bool GameState::is_legal_25_26_39([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_38(rgCache))
    {
        return true;
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
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_42([[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_25_26_51(rgCache))
    {
        coord = old69_0;
        return true;
    }
    coord = old69_0;
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
    const auto old70_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_25_26_47(rgCache))
    {
        coord = old70_0;
        return true;
    }
    coord = old70_0;
    return false;
}

bool GameState::is_legal_25_26_44([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_42(rgCache))
    {
        return true;
    }
    if (is_legal_25_26_43(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_45([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_48(rgCache))
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
    auto& cache = rgCache.state_cache_47;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_25_26_46(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_48([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_44(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_49([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_52(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_50([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_49(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_51([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_50(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_52([[maybe_unused]]RgCache& rgCache)
{
    const auto old80_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_25_26_55(rgCache))
    {
        coord = old80_0;
        return true;
    }
    coord = old80_0;
    return false;
}

bool GameState::is_legal_25_26_53([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_56(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_54([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_53(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_55([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_54(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_56([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_57([[maybe_unused]]RgCache& rgCache)
{
    const auto old85_0 = coord;
    coord = direction_E[coord];
    if (is_legal_25_26_66(rgCache))
    {
        coord = old85_0;
        return true;
    }
    coord = old85_0;
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
    const auto old86_0 = coord;
    coord = direction_W[coord];
    if (is_legal_25_26_62(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
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
    if (board[coord]==w)
    {
        if (is_legal_25_26_67(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_65([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_64(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_66([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_65(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_67([[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = coord;
    coord = direction_E[coord];
    if (is_legal_25_26_70(rgCache))
    {
        coord = old96_0;
        return true;
    }
    coord = old96_0;
    return false;
}

bool GameState::is_legal_25_26_68([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_25_26_71(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_25_26_69([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_68(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_70([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_69(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_25_26_71([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_25_26_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_292_293_292([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_15_148_15_15_148_148_15_148_15(rgCache))
    {
        if (is_legal_292_293_293(rgCache))
        {
            return true;
        }
    }
    if (is_legal_15_152_15_15_152_152_15_152_15(rgCache))
    {
        if (is_legal_292_293_293(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_292_293_293([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_294_295_294([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_156_11_156_156_11_11_156_11_156(rgCache))
    {
        if (is_legal_294_295_295(rgCache))
        {
            return true;
        }
    }
    if (is_legal_156_289_156_156_289_289_156_289_156(rgCache))
    {
        if (is_legal_294_295_295(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_294_295_295([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_75_76_100([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_99(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_101([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_101;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_75_76_100(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_102([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_98(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_103([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_106(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_104([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_103(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_105([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_104(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_106([[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_75_76_109(rgCache))
    {
        coord = old65_0;
        return true;
    }
    coord = old65_0;
    return false;
}

bool GameState::is_legal_75_76_107([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_110(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_108([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_107(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_109([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_108(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_110([[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_75_76_113(rgCache))
    {
        coord = old69_0;
        return true;
    }
    coord = old69_0;
    return false;
}

bool GameState::is_legal_75_76_111([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_114(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_112([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_111(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_113([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_112(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_114([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_115([[maybe_unused]]RgCache& rgCache)
{
    const auto old74_0 = coord;
    coord = direction_E[coord];
    if (is_legal_75_76_124(rgCache))
    {
        coord = old74_0;
        return true;
    }
    coord = old74_0;
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
    const auto old75_0 = coord;
    coord = direction_W[coord];
    if (is_legal_75_76_120(rgCache))
    {
        coord = old75_0;
        return true;
    }
    coord = old75_0;
    return false;
}

bool GameState::is_legal_75_76_117([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_115(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_116(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_118([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_121(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_119([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_118(rgCache))
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
    if (is_legal_75_76_119(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_121([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_117(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_122([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_125(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_123([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_122(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_124([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_123(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_125([[maybe_unused]]RgCache& rgCache)
{
    const auto old85_0 = coord;
    coord = direction_E[coord];
    if (is_legal_75_76_128(rgCache))
    {
        coord = old85_0;
        return true;
    }
    coord = old85_0;
    return false;
}

bool GameState::is_legal_75_76_126([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_129(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_127([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_126(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_128([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_127(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_129([[maybe_unused]]RgCache& rgCache)
{
    const auto old89_0 = coord;
    coord = direction_E[coord];
    if (is_legal_75_76_132(rgCache))
    {
        coord = old89_0;
        return true;
    }
    coord = old89_0;
    return false;
}

bool GameState::is_legal_75_76_130([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_133(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_131([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_130(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_132([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_131(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_133([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_75([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_115(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_116(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_77(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_78(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_96(rgCache))
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

bool GameState::is_legal_75_76_77([[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_75_76_86(rgCache))
    {
        coord = old100_0;
        return true;
    }
    coord = old100_0;
    return false;
}

bool GameState::is_legal_75_76_78([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_78;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old101_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_75_76_82(rgCache))
    {
        coord = old101_0;
        return true;
    }
    coord = old101_0;
    return false;
}

bool GameState::is_legal_75_76_79([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_77(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_78(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_80([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_83(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_81([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_80(rgCache))
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
    if (is_legal_75_76_81(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_83([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_79(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_84([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_87(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_85([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_84(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_86([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_85(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_87([[maybe_unused]]RgCache& rgCache)
{
    const auto old111_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_75_76_90(rgCache))
    {
        coord = old111_0;
        return true;
    }
    coord = old111_0;
    return false;
}

bool GameState::is_legal_75_76_88([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_91(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_89([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_88(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_90([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_89(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_91([[maybe_unused]]RgCache& rgCache)
{
    const auto old115_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_75_76_94(rgCache))
    {
        coord = old115_0;
        return true;
    }
    coord = old115_0;
    return false;
}

bool GameState::is_legal_75_76_92([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_95(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_75_76_93([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_92(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_94([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_93(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_95([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_96([[maybe_unused]]RgCache& rgCache)
{
    const auto old120_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_75_76_105(rgCache))
    {
        coord = old120_0;
        return true;
    }
    coord = old120_0;
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
    const auto old121_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_75_76_101(rgCache))
    {
        coord = old121_0;
        return true;
    }
    coord = old121_0;
    return false;
}

bool GameState::is_legal_75_76_98([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_75_76_96(rgCache))
    {
        return true;
    }
    if (is_legal_75_76_97(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_75_76_99([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_75_76_102(rgCache))
        {
            return true;
        }
    }
    return false;
}

void GameState::state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old382_0 = goals[black - 2];
    goals[black - 2] = 50;
    state_5(moves, mr,rgCache);
    goals[black - 2] = old382_0;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old383_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    state_13(moves, mr,rgCache);    }
    coord = old383_0;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        state_296(moves, mr,rgCache);
        return;
    }
    state_297(moves, mr,rgCache);
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

void GameState::state_134([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old425_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_138(moves, mr,rgCache);
    goals[black - 2] = old425_0;
}

void GameState::state_135([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_136(moves, mr,rgCache);
}

void GameState::state_136([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_134(moves, mr,rgCache);
}

void GameState::state_137([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_73(moves, mr,rgCache);
}

void GameState::state_138([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_139(moves, mr,rgCache);
}

void GameState::state_139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_137(moves, mr,rgCache);
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_17(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old432_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_142(moves, mr,rgCache);
    goals[white - 2] = old432_0;
}

void GameState::state_141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old433_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_145(moves, mr,rgCache);
    goals[black - 2] = old433_0;
}

void GameState::state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_143(moves, mr,rgCache);
}

void GameState::state_143([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_141(moves, mr,rgCache);
}

void GameState::state_144([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_73(moves, mr,rgCache);
}

void GameState::state_145([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_146(moves, mr,rgCache);
}

void GameState::state_146([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_144(moves, mr,rgCache);
}

void GameState::state_148([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_148(moves, mr,rgCache);
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old441_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_19(moves, mr,rgCache);
    counters[board[coord]] = old441_0;
}

void GameState::state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old443_0 = coord;
    for (coord = hx0y0; coord <= hx8y4; ++coord)
    {
    state_154(moves, mr,rgCache);    }
    coord = old443_0;
}

void GameState::state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_151_157_151_151_157_157_151_157_151())
    {
        state_300(moves, mr,rgCache);
        return;
    }
    state_301(moves, mr,rgCache);
}

void GameState::state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(63);
    state_152(moves, mr,rgCache);
    mr.pop_back();
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
    mr.emplace_back(1 + coord);
    state_158(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old451_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_160(moves, mr,rgCache);
    counters[board[coord]] = old451_0;
}

void GameState::state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_294_295_294(rgCache))
    {
        state_302(moves, mr,rgCache);
        return;
    }
    state_303(moves, mr,rgCache);
}

void GameState::state_158([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(64);
    state_157(moves, mr,rgCache);
    mr.pop_back();
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
    const auto result_488 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (!result_488)
    {
        state_165(moves, mr,rgCache);
        return;
    }
    state_213(moves, mr,rgCache);
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_292_293_292(rgCache))
    {
        state_298(moves, mr,rgCache);
        return;
    }
    state_299(moves, mr,rgCache);
}

void GameState::state_160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old523_0 = counters[b];
    counters[b] = counters[b]+1;
    state_161(moves, mr,rgCache);
    counters[b] = old523_0;
}

void GameState::state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_163(moves, mr,rgCache);
}

void GameState::state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old525_0 = board[coord];
    board[coord] = b;
    state_159(moves, mr,rgCache);
    board[coord] = old525_0;
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_162(moves, mr,rgCache);
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_9(moves, mr,rgCache);
}

void GameState::state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_164(moves, mr,rgCache);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(65);
    state_16(moves, mr,rgCache);
    mr.pop_back();
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
    const auto result_549 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_549)
    {
        state_24(moves, mr,rgCache);
        return;
    }
    state_72(moves, mr,rgCache);
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
    const auto old586_0 = board[coord];
    board[coord] = w;
    state_18(moves, mr,rgCache);
    board[coord] = old586_0;
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
    const auto result_590 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_590)
    {
        state_215(moves, mr,rgCache);
        return;
    }
    state_281(moves, mr,rgCache);
}

void GameState::state_214([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_290(moves, mr,rgCache);
}

void GameState::state_215([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old593_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_276(moves, mr,rgCache);
    goals[black - 2] = old593_0;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_21(moves, mr,rgCache);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_153(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_23(moves, mr,rgCache);
}

void GameState::state_275([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old670_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_279(moves, mr,rgCache);
    goals[white - 2] = old670_0;
}

void GameState::state_276([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_277(moves, mr,rgCache);
}

void GameState::state_277([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_275(moves, mr,rgCache);
}

void GameState::state_278([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_214(moves, mr,rgCache);
}

void GameState::state_279([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_280(moves, mr,rgCache);
}

void GameState::state_280([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_278(moves, mr,rgCache);
}

void GameState::state_281([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old677_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_283(moves, mr,rgCache);
    goals[black - 2] = old677_0;
}

void GameState::state_282([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old678_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_286(moves, mr,rgCache);
    goals[white - 2] = old678_0;
}

void GameState::state_283([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_284(moves, mr,rgCache);
}

void GameState::state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_282(moves, mr,rgCache);
}

void GameState::state_285([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_214(moves, mr,rgCache);
}

void GameState::state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_287(moves, mr,rgCache);
}

void GameState::state_287([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_285(moves, mr,rgCache);
}

void GameState::state_289([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_289(moves, mr,rgCache);
}

void GameState::state_296([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_297([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_298([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_299([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(66);
    state_1(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_300([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_301([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_302([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_303([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
    mr.emplace_back(67);
    state_4(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_741 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_741)
    {
        state_140(moves, mr,rgCache);
        return;
    }
    state_74(moves, mr,rgCache);
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_149(moves, mr,rgCache);
}

void GameState::state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old744_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_135(moves, mr,rgCache);
    goals[white - 2] = old744_0;
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
    const auto old778_0 = goals[white - 2];
    goals[white - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[white - 2] = old778_0;
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old382_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_state_5(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old382_0;
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
        if (apply_state_296(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_297(mr,rgCache))
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

bool GameState::apply_state_134([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old425_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_138(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old425_0;
    return false;
}

bool GameState::apply_state_135([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_136(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_136([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_134(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_137([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_73(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_138([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_139(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_137(mr,rgCache))
    {
        return true;
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

bool GameState::apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old432_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_142(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old432_0;
    return false;
}

bool GameState::apply_state_141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old433_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_145(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old433_0;
    return false;
}

bool GameState::apply_state_142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_143(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_143([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_141(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_144([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_73(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_145([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_146(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_146([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_144(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_148([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old439_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old439_0;
    return false;
}

bool GameState::apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_148(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old441_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_19(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old441_0;
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
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_157(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_151_157_151_151_157_157_151_157_151())
    {
        if (apply_state_300(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_301(mr,rgCache))
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
            case 63:
{
                return apply_state_152(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_3(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 63)
    {
        rgCache.currentMrId++;
        if (apply_state_152(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
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
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_158(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old451_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_160(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old451_0;
    return false;
}

bool GameState::apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_294_295_294(rgCache))
    {
        if (apply_state_302(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_303(mr,rgCache))
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
            case 64:
{
                return apply_state_157(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_158([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_4(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 64)
    {
        rgCache.currentMrId++;
        if (apply_state_157(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
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
    const auto result_488 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (!result_488)
    {
        if (apply_state_165(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_213(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_292_293_292(rgCache))
    {
        if (apply_state_298(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_299(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old523_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_161(mr,rgCache))
    {
        return true;
    }
    counters[b] = old523_0;
    return false;
}

bool GameState::apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_163(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old525_0 = board[coord];
    board[coord] = b;
    if (apply_state_159(mr,rgCache))
    {
        return true;
    }
    board[coord] = old525_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_162(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_164(mr,rgCache))
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
            case 65:
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
    if (switch_5(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 65)
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

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_549 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_549)
    {
        if (apply_state_24(mr,rgCache))
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
    const auto old586_0 = board[coord];
    board[coord] = w;
    if (apply_state_18(mr,rgCache))
    {
        return true;
    }
    board[coord] = old586_0;
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
    const auto result_590 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_590)
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
    if (apply_state_290(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_215([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old593_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_276(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old593_0;
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
        if (apply_state_153(mr,rgCache))
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

bool GameState::apply_state_275([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old670_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_279(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old670_0;
    return false;
}

bool GameState::apply_state_276([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_277(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_277([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_275(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_278([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_279([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_280(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_280([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_278(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_281([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old677_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_283(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old677_0;
    return false;
}

bool GameState::apply_state_282([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old678_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_286(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old678_0;
    return false;
}

bool GameState::apply_state_283([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_284(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_282(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_285([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_214(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_287(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_287([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_285(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_289([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old684_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old684_0;
    return false;
}

bool GameState::apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_289(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_296([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old780_0 = player;
    player = white;
    currentState = 2;
    return true;
    player = old780_0;
    return false;
}

bool GameState::apply_state_297([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old782_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old782_0;
    return false;
}

bool GameState::apply_state_298([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old784_0 = player;
    player = keeper;
    currentState = 61;
    return true;
    player = old784_0;
    return false;
}

bool GameState::apply_state_299([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old786_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old786_0;
    return false;
}

bool GameState::switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 66:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 62:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 67:
{
                                        if (mr.size() >rgCache.currentMrId)
                                        {
                                            switch (mr[rgCache.currentMrId++])
                                            {
                                                case 1 ... 62:
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
    if (switch_6(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 66)
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

bool GameState::apply_state_300([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old788_0 = player;
    player = black;
    currentState = 63;
    return true;
    player = old788_0;
    return false;
}

bool GameState::apply_state_301([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old790_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old790_0;
    return false;
}

bool GameState::apply_state_302([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old792_0 = player;
    player = keeper;
    currentState = 73;
    return true;
    player = old792_0;
    return false;
}

bool GameState::apply_state_303([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old794_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    player = old794_0;
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

bool GameState::switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 67:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 62:
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
    if (switch_7(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 67)
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

bool GameState::apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_741 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_741)
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

bool GameState::apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_149(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old744_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_135(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old744_0;
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

bool GameState::switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
    return switch_8(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_15_15_134([[maybe_unused]]RgCache& rgCache)
{
    const auto old32_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_15_15_138(rgCache))
    {
        return true;
    }
    goals[black - 2] = old32_0;
    return false;
}

bool GameState::apply_any_15_15_135([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_136(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_136([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_134(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_137([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_73(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_138([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_139(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_139([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_137(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_140([[maybe_unused]]RgCache& rgCache)
{
    const auto old38_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_15_15_142(rgCache))
    {
        return true;
    }
    goals[white - 2] = old38_0;
    return false;
}

bool GameState::apply_any_15_15_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old39_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_15_15_145(rgCache))
    {
        return true;
    }
    goals[black - 2] = old39_0;
    return false;
}

bool GameState::apply_any_15_15_142([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_143([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_141(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_144([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_73(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_145([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_146(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_146([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_144(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_148([[maybe_unused]]RgCache& rgCache)
{
    const auto old45_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    if (apply_any_15_15_end(rgCache))
    {
        return true;
    }
    player = old45_0;
    return false;
}

bool GameState::apply_any_15_15_149([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_148(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_15_15_19(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old47_0;
    return false;
}

bool GameState::apply_any_15_15_151([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_15_15_152([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_151_157_151_151_157_157_151_157_151())
    {
        if (apply_any_15_15_300(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_15_15_301(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_153([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_152(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_18([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_28.reset();
    rgCache.state_cache_32.reset();
    rgCache.state_cache_43.reset();
    rgCache.state_cache_47.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_62.reset();
    const auto result_49 = is_legal_25_26_25(rgCache);
    rgCache.decDepth();
    if (!result_49)
    {
        if (apply_any_15_15_24(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_15_15_72(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_19([[maybe_unused]]RgCache& rgCache)
{
    const auto old51_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_15_15_20(rgCache))
    {
        return true;
    }
    counters[w] = old51_0;
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
    const auto old53_0 = board[coord];
    board[coord] = w;
    if (apply_any_15_15_18(rgCache))
    {
        return true;
    }
    board[coord] = old53_0;
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
    if (apply_any_15_15_153(rgCache))
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

bool GameState::apply_any_15_15_300([[maybe_unused]]RgCache& rgCache)
{
    const auto old62_0 = player;
    player = black;
    currentState = 63;
    return true;
    if (apply_any_15_15_151(rgCache))
    {
        return true;
    }
    player = old62_0;
    return false;
}

bool GameState::apply_any_15_15_301([[maybe_unused]]RgCache& rgCache)
{
    const auto old64_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    if (apply_any_15_15_end(rgCache))
    {
        return true;
    }
    player = old64_0;
    return false;
}

bool GameState::apply_any_15_15_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    rgCache.state_cache_116.reset();
    rgCache.state_cache_120.reset();
    rgCache.state_cache_78.reset();
    rgCache.state_cache_82.reset();
    rgCache.state_cache_97.reset();
    const auto result_57 = is_legal_75_76_75(rgCache);
    rgCache.decDepth();
    if (!result_57)
    {
        if (apply_any_15_15_140(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_15_15_74(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_73([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_15_15_149(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_15_15_74([[maybe_unused]]RgCache& rgCache)
{
    const auto old60_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_15_15_135(rgCache))
    {
        return true;
    }
    goals[white - 2] = old60_0;
    return false;
}

bool GameState::apply_any_15_15_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_156_156_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_156_156_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_16_10_10_16_16_10_16_10())
    {
        if (apply_any_156_156_296(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_156_156_297(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_12([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old35_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_156_156_160(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old35_0;
    return false;
}

bool GameState::apply_any_156_156_159([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_169.reset();
    rgCache.state_cache_173.reset();
    rgCache.state_cache_184.reset();
    rgCache.state_cache_188.reset();
    rgCache.state_cache_199.reset();
    rgCache.state_cache_203.reset();
    const auto result_36 = is_legal_166_167_166(rgCache);
    rgCache.decDepth();
    if (!result_36)
    {
        if (apply_any_156_156_165(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_156_156_213(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_160([[maybe_unused]]RgCache& rgCache)
{
    const auto old38_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_156_156_161(rgCache))
    {
        return true;
    }
    counters[b] = old38_0;
    return false;
}

bool GameState::apply_any_156_156_161([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_163(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old40_0 = board[coord];
    board[coord] = b;
    if (apply_any_156_156_159(rgCache))
    {
        return true;
    }
    board[coord] = old40_0;
    return false;
}

bool GameState::apply_any_156_156_163([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_164([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_165([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_213([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_219.reset();
    rgCache.state_cache_223.reset();
    rgCache.state_cache_238.reset();
    rgCache.state_cache_242.reset();
    rgCache.state_cache_257.reset();
    rgCache.state_cache_261.reset();
    const auto result_44 = is_legal_216_217_216(rgCache);
    rgCache.decDepth();
    if (result_44)
    {
        if (apply_any_156_156_215(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_156_156_281(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_214([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_290(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_215([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_156_156_276(rgCache))
    {
        return true;
    }
    goals[black - 2] = old47_0;
    return false;
}

bool GameState::apply_any_156_156_275([[maybe_unused]]RgCache& rgCache)
{
    const auto old48_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_156_156_279(rgCache))
    {
        return true;
    }
    goals[white - 2] = old48_0;
    return false;
}

bool GameState::apply_any_156_156_276([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_277(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_277([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_275(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_278([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_214(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_279([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_280(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_280([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_278(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_281([[maybe_unused]]RgCache& rgCache)
{
    const auto old54_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_156_156_283(rgCache))
    {
        return true;
    }
    goals[black - 2] = old54_0;
    return false;
}

bool GameState::apply_any_156_156_282([[maybe_unused]]RgCache& rgCache)
{
    const auto old55_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_156_156_286(rgCache))
    {
        return true;
    }
    goals[white - 2] = old55_0;
    return false;
}

bool GameState::apply_any_156_156_283([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_284(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_284([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_282(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_285([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_214(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_286([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_287(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_287([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_285(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_289([[maybe_unused]]RgCache& rgCache)
{
    const auto old61_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    if (apply_any_156_156_end(rgCache))
    {
        return true;
    }
    player = old61_0;
    return false;
}

bool GameState::apply_any_156_156_290([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_289(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_296([[maybe_unused]]RgCache& rgCache)
{
    const auto old66_0 = player;
    player = white;
    currentState = 2;
    return true;
    if (apply_any_156_156_10(rgCache))
    {
        return true;
    }
    player = old66_0;
    return false;
}

bool GameState::apply_any_156_156_297([[maybe_unused]]RgCache& rgCache)
{
    const auto old68_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    if (apply_any_156_156_end(rgCache))
    {
        return true;
    }
    player = old68_0;
    return false;
}

bool GameState::apply_any_156_156_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_9([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_156_156_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_156_156_end([[maybe_unused]]RgCache& rgCache)
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
        if (apply_any_begin_begin_296(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_297(rgCache))
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

bool GameState::apply_any_begin_begin_296([[maybe_unused]]RgCache& rgCache)
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

bool GameState::apply_any_begin_begin_297([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = player;
    player = keeper;
    currentState = 382;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old26_0;
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
