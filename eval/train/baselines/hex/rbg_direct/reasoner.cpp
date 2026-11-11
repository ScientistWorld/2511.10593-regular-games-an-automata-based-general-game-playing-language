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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "hx0y0: " << board[hx0y0] << ", " << "hx0y1: " << board[hx0y1] << ", " << "hx1y1: " << board[hx1y1] << ", " << "hx0y2: " << board[hx0y2] << ", " << "hx1y2: " << board[hx1y2] << ", " << "hx2y2: " << board[hx2y2] << ", " << "hx0y3: " << board[hx0y3] << ", " << "hx1y3: " << board[hx1y3] << ", " << "hx2y3: " << board[hx2y3] << ", " << "hx3y3: " << board[hx3y3] << ", " << "hx0y4: " << board[hx0y4] << ", " << "hx1y4: " << board[hx1y4] << ", " << "hx2y4: " << board[hx2y4] << ", " << "hx3y4: " << board[hx3y4] << ", " << "hx4y4: " << board[hx4y4] << ", " << "hx0y5: " << board[hx0y5] << ", " << "hx1y5: " << board[hx1y5] << ", " << "hx2y5: " << board[hx2y5] << ", " << "hx3y5: " << board[hx3y5] << ", " << "hx4y5: " << board[hx4y5] << ", " << "hx5y5: " << board[hx5y5] << ", " << "hx0y6: " << board[hx0y6] << ", " << "hx1y6: " << board[hx1y6] << ", " << "hx2y6: " << board[hx2y6] << ", " << "hx3y6: " << board[hx3y6] << ", " << "hx4y6: " << board[hx4y6] << ", " << "hx5y6: " << board[hx5y6] << ", " << "hx6y6: " << board[hx6y6] << ", " << "hx0y7: " << board[hx0y7] << ", " << "hx1y7: " << board[hx1y7] << ", " << "hx2y7: " << board[hx2y7] << ", " << "hx3y7: " << board[hx3y7] << ", " << "hx4y7: " << board[hx4y7] << ", " << "hx5y7: " << board[hx5y7] << ", " << "hx6y7: " << board[hx6y7] << ", " << "hx7y7: " << board[hx7y7] << ", " << "hx0y8: " << board[hx0y8] << ", " << "hx1y8: " << board[hx1y8] << ", " << "hx2y8: " << board[hx2y8] << ", " << "hx3y8: " << board[hx3y8] << ", " << "hx4y8: " << board[hx4y8] << ", " << "hx5y8: " << board[hx5y8] << ", " << "hx6y8: " << board[hx6y8] << ", " << "hx7y8: " << board[hx7y8] << ", " << "hx8y8: " << board[hx8y8] << ", " << "hx0y9: " << board[hx0y9] << ", " << "hx1y9: " << board[hx1y9] << ", " << "hx2y9: " << board[hx2y9] << ", " << "hx3y9: " << board[hx3y9] << ", " << "hx4y9: " << board[hx4y9] << ", " << "hx5y9: " << board[hx5y9] << ", " << "hx6y9: " << board[hx6y9] << ", " << "hx7y9: " << board[hx7y9] << ", " << "hx8y9: " << board[hx8y9] << ", " << "hx9y9: " << board[hx9y9] << ", " << "hx0y10: " << board[hx0y10] << ", " << "hx1y10: " << board[hx1y10] << ", " << "hx2y10: " << board[hx2y10] << ", " << "hx3y10: " << board[hx3y10] << ", " << "hx4y10: " << board[hx4y10] << ", " << "hx5y10: " << board[hx5y10] << ", " << "hx6y10: " << board[hx6y10] << ", " << "hx7y10: " << board[hx7y10] << ", " << "hx8y10: " << board[hx8y10] << ", " << "hx9y10: " << board[hx9y10] << ", " << "hx10y10: " << board[hx10y10] << ", " << "hx0y11: " << board[hx0y11] << ", " << "hx1y11: " << board[hx1y11] << ", " << "hx2y11: " << board[hx2y11] << ", " << "hx3y11: " << board[hx3y11] << ", " << "hx4y11: " << board[hx4y11] << ", " << "hx5y11: " << board[hx5y11] << ", " << "hx6y11: " << board[hx6y11] << ", " << "hx7y11: " << board[hx7y11] << ", " << "hx8y11: " << board[hx8y11] << ", " << "hx9y11: " << board[hx9y11] << ", " << "hx0y12: " << board[hx0y12] << ", " << "hx1y12: " << board[hx1y12] << ", " << "hx2y12: " << board[hx2y12] << ", " << "hx3y12: " << board[hx3y12] << ", " << "hx4y12: " << board[hx4y12] << ", " << "hx5y12: " << board[hx5y12] << ", " << "hx6y12: " << board[hx6y12] << ", " << "hx7y12: " << board[hx7y12] << ", " << "hx8y12: " << board[hx8y12] << ", " << "hx0y13: " << board[hx0y13] << ", " << "hx1y13: " << board[hx1y13] << ", " << "hx2y13: " << board[hx2y13] << ", " << "hx3y13: " << board[hx3y13] << ", " << "hx4y13: " << board[hx4y13] << ", " << "hx5y13: " << board[hx5y13] << ", " << "hx6y13: " << board[hx6y13] << ", " << "hx7y13: " << board[hx7y13] << ", " << "hx0y14: " << board[hx0y14] << ", " << "hx1y14: " << board[hx1y14] << ", " << "hx2y14: " << board[hx2y14] << ", " << "hx3y14: " << board[hx3y14] << ", " << "hx4y14: " << board[hx4y14] << ", " << "hx5y14: " << board[hx5y14] << ", " << "hx6y14: " << board[hx6y14] << ", " << "hx0y15: " << board[hx0y15] << ", " << "hx1y15: " << board[hx1y15] << ", " << "hx2y15: " << board[hx2y15] << ", " << "hx3y15: " << board[hx3y15] << ", " << "hx4y15: " << board[hx4y15] << ", " << "hx5y15: " << board[hx5y15] << ", " << "hx0y16: " << board[hx0y16] << ", " << "hx1y16: " << board[hx1y16] << ", " << "hx2y16: " << board[hx2y16] << ", " << "hx3y16: " << board[hx3y16] << ", " << "hx4y16: " << board[hx4y16] << ", " << "hx0y17: " << board[hx0y17] << ", " << "hx1y17: " << board[hx1y17] << ", " << "hx2y17: " << board[hx2y17] << ", " << "hx3y17: " << board[hx3y17] << ", " << "hx0y18: " << board[hx0y18] << ", " << "hx1y18: " << board[hx1y18] << ", " << "hx2y18: " << board[hx2y18] << ", " << "hx0y19: " << board[hx0y19] << ", " << "hx1y19: " << board[hx1y19] << ", " << "hx0y20: " << board[hx0y20]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
    ss << "counters = " << "{" << "b: " << counters[b] << ", " << "e: " << counters[e] << ", " << "r: " << counters[r] << ", " << "null: " << counters[null]<< "}" << std::endl;
    ss << "goals = " << "{" << "red: " << goals[red-2] << ", " << "blue: " << goals[blue-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "red: " << visible[red-2] << ", " << "blue: " << visible[blue-2]<< "}" << std::endl;
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
        case 152:
{
            state_81(moves, mr.mr,rgCache);
            return;
}
        case 102:
{
            state_4(moves, mr.mr,rgCache);
            return;
}
        case 227:
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
        case 152:
{
            apply_state_81(mr.mr,rgCache);
            return;
}
        case 102:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 227:
{
            apply_state_begin(mr.mr,rgCache);
            return;
}
    }
}

void GameState::applyAnyMove([[maybe_unused]]RgCache& rgCache)
{
    rgCache.reset();
    switch (currentState)
    {
        case 162:
{
            apply_any_86_86_86(rgCache);
            rgCache.reset();
            break;
}
        case 192:
{
            apply_any_9_9_9(rgCache);
            rgCache.reset();
            break;
}
        case 227:
{
            apply_any_begin_begin_begin(rgCache);
            rgCache.reset();
            break;
}
    }
}

bool GameState::is_legal_118_119_118()
{
    const auto old4_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_118_119_121())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_118_119_119()
{
    return true;
}

bool GameState::is_legal_118_119_120()
{
    if (is_legal_118_119_119())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_118_119_121()
{
    if (coord!=null)
    {
        if (is_legal_118_119_120())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_123_124_123([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_125(rgCache))
    {
        return true;
    }
    if (is_legal_123_124_126(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_124([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_123_124_125([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_145_146_145())
    {
        if (is_legal_123_124_144(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_123_124_126([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_126;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old25_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_123_124_131(rgCache))
    {
        coord = old25_0;
        return true;
    }
    coord = old25_0;
    const auto old26_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_123_124_133(rgCache))
    {
        coord = old26_0;
        return true;
    }
    coord = old26_0;
    const auto old27_0 = coord;
    coord = direction_E[coord];
    if (is_legal_123_124_135(rgCache))
    {
        coord = old27_0;
        return true;
    }
    coord = old27_0;
    const auto old28_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_123_124_137(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    const auto old29_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_123_124_139(rgCache))
    {
        coord = old29_0;
        return true;
    }
    coord = old29_0;
    const auto old30_0 = coord;
    coord = direction_W[coord];
    if (is_legal_123_124_141(rgCache))
    {
        coord = old30_0;
        return true;
    }
    coord = old30_0;
    return false;
}

bool GameState::is_legal_123_124_127([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_125(rgCache))
    {
        return true;
    }
    if (is_legal_123_124_126(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_128([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_123_124_142(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_123_124_129([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_129;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_128(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_130([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_131([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_131;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_130(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_132([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_133([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_133;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_132(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_134([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_135([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_135;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_134(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_136([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_137([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_137;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_136(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_138([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_139([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_139;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_138(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_140([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_129(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_141([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_141;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_123_124_140(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_142([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_127(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_143([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_124(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_123_124_144([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_123_124_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_145_146_145()
{
    const auto old4_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_145_146_148())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_145_146_146()
{
    return true;
}

bool GameState::is_legal_145_146_147()
{
    if (is_legal_145_146_146())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_145_146_148()
{
    if (coord!=null)
    {
        if (is_legal_145_146_147())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_158_159_158([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_9(rgCache))
    {
        if (is_legal_158_159_159(rgCache))
        {
            return true;
        }
    }
    if (is_legal_9_82_9_9_82_82_9_82_9(rgCache))
    {
        if (is_legal_158_159_159(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_158_159_159([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_160_161_160([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_86(rgCache))
    {
        if (is_legal_160_161_161(rgCache))
        {
            return true;
        }
    }
    if (is_legal_86_5_86_86_5_5_86_5_86(rgCache))
    {
        if (is_legal_160_161_161(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_160_161_161([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_19_20_19([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_21(rgCache))
    {
        return true;
    }
    if (is_legal_19_20_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_20([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_19_20_21([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_41_42_41())
    {
        if (is_legal_19_20_40(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_19_20_22([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_22;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old25_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_19_20_27(rgCache))
    {
        coord = old25_0;
        return true;
    }
    coord = old25_0;
    const auto old26_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_19_20_29(rgCache))
    {
        coord = old26_0;
        return true;
    }
    coord = old26_0;
    const auto old27_0 = coord;
    coord = direction_E[coord];
    if (is_legal_19_20_31(rgCache))
    {
        coord = old27_0;
        return true;
    }
    coord = old27_0;
    const auto old28_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_19_20_33(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    const auto old29_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_19_20_35(rgCache))
    {
        coord = old29_0;
        return true;
    }
    coord = old29_0;
    const auto old30_0 = coord;
    coord = direction_W[coord];
    if (is_legal_19_20_37(rgCache))
    {
        coord = old30_0;
        return true;
    }
    coord = old30_0;
    return false;
}

bool GameState::is_legal_19_20_23([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_21(rgCache))
    {
        return true;
    }
    if (is_legal_19_20_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_24([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==r)
    {
        if (is_legal_19_20_38(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_19_20_25([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_25;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_24(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_26([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_27([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_27;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_26(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_28([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_29([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_29;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_28(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_30([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_31([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_31;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_30(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_32([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_33([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_33;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_32(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_34([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_35([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_35;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_34(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_36([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_25(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_37([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_37;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_19_20_36(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_38([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_23(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_39([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_20(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_19_20_40([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_19_20_39(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_42_41()
{
    const auto old4_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_41_42_44())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_41_42_42()
{
    return true;
}

bool GameState::is_legal_41_42_43()
{
    if (is_legal_41_42_42())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_41_42_44()
{
    if (coord!=null)
    {
        if (is_legal_41_42_43())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_46_47_46([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_48(rgCache))
    {
        return true;
    }
    if (is_legal_46_47_49(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_47([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_46_47_48([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_68_69_68())
    {
        if (is_legal_46_47_67(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_46_47_49([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_49;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old25_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_46_47_54(rgCache))
    {
        coord = old25_0;
        return true;
    }
    coord = old25_0;
    const auto old26_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_46_47_56(rgCache))
    {
        coord = old26_0;
        return true;
    }
    coord = old26_0;
    const auto old27_0 = coord;
    coord = direction_E[coord];
    if (is_legal_46_47_58(rgCache))
    {
        coord = old27_0;
        return true;
    }
    coord = old27_0;
    const auto old28_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_46_47_60(rgCache))
    {
        coord = old28_0;
        return true;
    }
    coord = old28_0;
    const auto old29_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_46_47_62(rgCache))
    {
        coord = old29_0;
        return true;
    }
    coord = old29_0;
    const auto old30_0 = coord;
    coord = direction_W[coord];
    if (is_legal_46_47_64(rgCache))
    {
        coord = old30_0;
        return true;
    }
    coord = old30_0;
    return false;
}

bool GameState::is_legal_46_47_50([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_48(rgCache))
    {
        return true;
    }
    if (is_legal_46_47_49(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_51([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==r)
    {
        if (is_legal_46_47_65(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_46_47_52([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_52;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_51(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_53([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_54([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_54;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_53(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_55([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_56([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_56;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_55(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_57([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_58([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_58;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_57(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_59([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_60([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_60;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_59(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_61([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_62([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_62;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_61(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_63([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_52(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_64([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_64;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_46_47_63(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_65([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_50(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_66([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_47(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_46_47_67([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_46_47_66(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_10()
{
    return true;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_11()
{
    if (is_legal_4_10_4_4_10_10_4_10_10())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_4()
{
    const auto old6_0 = coord;
    for (coord = hx0y0; coord <= hx9y9; ++coord)
    {
    if (is_legal_4_10_4_4_10_10_4_10_7())
    {
        coord = old6_0;
        return true;
    }    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_7()
{
    if (board[coord]==e)
    {
        if (is_legal_4_10_4_4_10_10_4_10_8())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_8()
{
    if (is_legal_4_10_4_4_10_10_4_10_11())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_68_69_68()
{
    const auto old4_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_68_69_71())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_68_69_69()
{
    return true;
}

bool GameState::is_legal_68_69_70()
{
    if (is_legal_68_69_69())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_68_69_71()
{
    if (coord!=null)
    {
        if (is_legal_68_69_70())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_81()
{
    const auto old5_0 = coord;
    for (coord = hx0y0; coord <= hx9y9; ++coord)
    {
    if (is_legal_81_87_81_81_87_87_81_87_84())
    {
        coord = old5_0;
        return true;
    }    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_84()
{
    if (board[coord]==e)
    {
        if (is_legal_81_87_81_81_87_87_81_87_85())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_85()
{
    if (is_legal_81_87_81_81_87_87_81_87_88())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_87()
{
    return true;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_88()
{
    if (is_legal_81_87_81_81_87_87_81_87_87())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_149([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_13 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (is_legal_86_155_86_86_155_155_86_155_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_150([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    if (is_legal_86_155_86_86_155_155_86_155_152(rgCache))
    {
        goals[blue - 2] = old14_0;
        return true;
    }
    goals[blue - 2] = old14_0;
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_151([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_156(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_152([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_153(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_153([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_151(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_155([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_156([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_155(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_86([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_86_155_86_86_155_155_86_155_90(rgCache))
    {
        counters[board[coord]] = old19_0;
        return true;
    }
    counters[board[coord]] = old19_0;
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_89([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_102.reset();
    rgCache.state_cache_104.reset();
    rgCache.state_cache_106.reset();
    rgCache.state_cache_108.reset();
    rgCache.state_cache_110.reset();
    rgCache.state_cache_112.reset();
    rgCache.state_cache_114.reset();
    rgCache.state_cache_99.reset();
    const auto result_20 = is_legal_96_97_96(rgCache);
    rgCache.decDepth();
    if (result_20)
    {
        if (is_legal_86_155_86_86_155_155_86_155_149(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_90([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_86_155_86_86_155_155_86_155_91(rgCache))
    {
        counters[b] = old21_0;
        return true;
    }
    counters[b] = old21_0;
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_91([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_93(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_92([[maybe_unused]]RgCache& rgCache)
{
    const auto old23_0 = board[coord];
    board[coord] = b;
    if (is_legal_86_155_86_86_155_155_86_155_89(rgCache))
    {
        board[coord] = old23_0;
        return true;
    }
    board[coord] = old23_0;
    return false;
}

bool GameState::is_legal_86_155_86_86_155_155_86_155_93([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_155_86_86_155_155_86_155_92(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_122([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_94(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_2([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_3([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_5([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_6([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_86([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_86_5_86_86_5_5_86_5_90(rgCache))
    {
        counters[board[coord]] = old17_0;
        return true;
    }
    counters[board[coord]] = old17_0;
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_89([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_18 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (!result_18)
    {
        if (is_legal_86_5_86_86_5_5_86_5_122(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_102.reset();
    rgCache.state_cache_104.reset();
    rgCache.state_cache_106.reset();
    rgCache.state_cache_108.reset();
    rgCache.state_cache_110.reset();
    rgCache.state_cache_112.reset();
    rgCache.state_cache_114.reset();
    rgCache.state_cache_99.reset();
    const auto result_19 = is_legal_96_97_96(rgCache);
    rgCache.decDepth();
    if (!result_19)
    {
        if (is_legal_86_5_86_86_5_5_86_5_95(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_90([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_86_5_86_86_5_5_86_5_91(rgCache))
    {
        counters[b] = old20_0;
        return true;
    }
    counters[b] = old20_0;
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_91([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_93(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_92([[maybe_unused]]RgCache& rgCache)
{
    const auto old22_0 = board[coord];
    board[coord] = b;
    if (is_legal_86_5_86_86_5_5_86_5_89(rgCache))
    {
        board[coord] = old22_0;
        return true;
    }
    board[coord] = old22_0;
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_93([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_92(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_94([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_3(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_95([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_94(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_100([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_98(rgCache))
    {
        return true;
    }
    if (is_legal_96_97_99(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_101([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_96_97_115(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_96_97_102([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_102;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_101(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_103([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_104([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_104;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_103(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_105([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_106([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_106;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_105(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_107([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_108([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_108;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_107(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_109([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_110([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_110;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_109(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_111([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_112([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_112;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_111(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_113([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_102(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_114([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_114;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_96_97_113(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_115([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_100(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_116([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_97(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_117([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_116(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_96([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_96_97_98(rgCache))
    {
        return true;
    }
    if (is_legal_96_97_99(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_96_97_97([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_96_97_98([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_118_119_118())
    {
        if (is_legal_96_97_117(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_96_97_99([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_99;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old44_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_96_97_104(rgCache))
    {
        coord = old44_0;
        return true;
    }
    coord = old44_0;
    const auto old45_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_96_97_106(rgCache))
    {
        coord = old45_0;
        return true;
    }
    coord = old45_0;
    const auto old46_0 = coord;
    coord = direction_E[coord];
    if (is_legal_96_97_108(rgCache))
    {
        coord = old46_0;
        return true;
    }
    coord = old46_0;
    const auto old47_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_96_97_110(rgCache))
    {
        coord = old47_0;
        return true;
    }
    coord = old47_0;
    const auto old48_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_96_97_112(rgCache))
    {
        coord = old48_0;
        return true;
    }
    coord = old48_0;
    const auto old49_0 = coord;
    coord = direction_W[coord];
    if (is_legal_96_97_114(rgCache))
    {
        coord = old49_0;
        return true;
    }
    coord = old49_0;
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_12([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_22.reset();
    rgCache.state_cache_25.reset();
    rgCache.state_cache_27.reset();
    rgCache.state_cache_29.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_33.reset();
    rgCache.state_cache_35.reset();
    rgCache.state_cache_37.reset();
    const auto result_13 = is_legal_19_20_19(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (is_legal_9_78_9_9_78_78_9_78_72(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_13([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = counters[r];
    counters[r] = counters[r]+1;
    if (is_legal_9_78_9_9_78_78_9_78_14(rgCache))
    {
        counters[r] = old14_0;
        return true;
    }
    counters[r] = old14_0;
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_14([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_16(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = board[coord];
    board[coord] = r;
    if (is_legal_9_78_9_9_78_78_9_78_12(rgCache))
    {
        board[coord] = old16_0;
        return true;
    }
    board[coord] = old16_0;
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_16([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_15(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_18 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (result_18)
    {
        if (is_legal_9_78_9_9_78_78_9_78_73(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_73([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (is_legal_9_78_9_9_78_78_9_78_75(rgCache))
    {
        goals[red - 2] = old19_0;
        return true;
    }
    goals[red - 2] = old19_0;
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_74([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_79(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_75([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_76([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_74(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_78([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_79([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_78_9_9_78_78_9_78_78(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_78_9_9_78_78_9_78_9([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_9_78_9_9_78_78_9_78_13(rgCache))
    {
        counters[board[coord]] = old24_0;
        return true;
    }
    counters[board[coord]] = old24_0;
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_12([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_22.reset();
    rgCache.state_cache_25.reset();
    rgCache.state_cache_27.reset();
    rgCache.state_cache_29.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_33.reset();
    rgCache.state_cache_35.reset();
    rgCache.state_cache_37.reset();
    const auto result_11 = is_legal_19_20_19(rgCache);
    rgCache.decDepth();
    if (!result_11)
    {
        if (is_legal_9_82_9_9_82_82_9_82_18(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_12 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (!result_12)
    {
        if (is_legal_9_82_9_9_82_82_9_82_45(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_13([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = counters[r];
    counters[r] = counters[r]+1;
    if (is_legal_9_82_9_9_82_82_9_82_14(rgCache))
    {
        counters[r] = old13_0;
        return true;
    }
    counters[r] = old13_0;
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_14([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_16(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = r;
    if (is_legal_9_82_9_9_82_82_9_82_12(rgCache))
    {
        board[coord] = old15_0;
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_16([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_15(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_17([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_83(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_18([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_17(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_45([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_17(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_82([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_83([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_82(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_9([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_9_82_9_9_82_82_9_82_13(rgCache))
    {
        counters[board[coord]] = old21_0;
        return true;
    }
    counters[board[coord]] = old21_0;
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_158_159_158(rgCache))
    {
        state_164(moves, mr,rgCache);
        return;
    }
    state_165(moves, mr,rgCache);
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 0;
    state_10(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_250 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (!result_250)
    {
        state_45(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_22.reset();
    rgCache.state_cache_25.reset();
    rgCache.state_cache_27.reset();
    rgCache.state_cache_29.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_33.reset();
    rgCache.state_cache_35.reset();
    rgCache.state_cache_37.reset();
    const auto result_249 = is_legal_19_20_19(rgCache);
    rgCache.decDepth();
    if (!result_249)
    {
        state_18(moves, mr,rgCache);
        return;
    }
    state_72(moves, mr,rgCache);
}

void GameState::state_122([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_94(moves, mr,rgCache);
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old268_0 = counters[r];
    counters[r] = counters[r]+1;
    state_14(moves, mr,rgCache);
    counters[r] = old268_0;
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_16(moves, mr,rgCache);
}

void GameState::state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_288 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (result_288)
    {
        state_150(moves, mr,rgCache);
    }
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old289_0 = board[coord];
    board[coord] = r;
    state_12(moves, mr,rgCache);
    board[coord] = old289_0;
}

void GameState::state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old290_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    state_152(moves, mr,rgCache);
    goals[blue - 2] = old290_0;
}

void GameState::state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_156(moves, mr,rgCache);
}

void GameState::state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_153(moves, mr,rgCache);
}

void GameState::state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_151(moves, mr,rgCache);
}

void GameState::state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_155(moves, mr,rgCache);
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_15(moves, mr,rgCache);
}

void GameState::state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_167([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_168([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_169([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache)
    {
        return;
    }
    cache = true;
    state_83(moves, mr,rgCache);
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_17(moves, mr,rgCache);
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_6(moves, mr,rgCache);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_2(moves, mr,rgCache);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old333_0 = coord;
    for (coord = hx0y0; coord <= hx9y9; ++coord)
    {
    state_7(moves, mr,rgCache);    }
    coord = old333_0;
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_17(moves, mr,rgCache);
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_10_4_4_10_10_4_10_4())
    {
        state_162(moves, mr,rgCache);
        return;
    }
    state_163(moves, mr,rgCache);
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_5(moves, mr,rgCache);
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_8(moves, mr,rgCache);
    }
}

void GameState::state_72([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_376 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (result_376)
    {
        state_73(moves, mr,rgCache);
    }
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old377_0 = goals[red - 2];
    goals[red - 2] = 100;
    state_75(moves, mr,rgCache);
    goals[red - 2] = old377_0;
}

void GameState::state_74([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_79(moves, mr,rgCache);
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_76(moves, mr,rgCache);
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_74(moves, mr,rgCache);
}

void GameState::state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_78(moves, mr,rgCache);
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 1 + coord;
    state_11(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old385_0 = coord;
    for (coord = hx0y0; coord <= hx9y9; ++coord)
    {
    state_84(moves, mr,rgCache);    }
    coord = old385_0;
}

void GameState::state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_81_87_81_81_87_87_81_87_81())
    {
        state_166(moves, mr,rgCache);
        return;
    }
    state_167(moves, mr,rgCache);
}

void GameState::state_83([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_82(moves, mr,rgCache);
}

void GameState::state_84([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_85(moves, mr,rgCache);
    }
}

void GameState::state_85([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 1 + coord;
    state_88(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old393_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_90(moves, mr,rgCache);
    counters[board[coord]] = old393_0;
}

void GameState::state_87([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_160_161_160(rgCache))
    {
        state_168(moves, mr,rgCache);
        return;
    }
    state_169(moves, mr,rgCache);
}

void GameState::state_88([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 123;
    state_87(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_89([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_420 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (!result_420)
    {
        state_122(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_102.reset();
    rgCache.state_cache_104.reset();
    rgCache.state_cache_106.reset();
    rgCache.state_cache_108.reset();
    rgCache.state_cache_110.reset();
    rgCache.state_cache_112.reset();
    rgCache.state_cache_114.reset();
    rgCache.state_cache_99.reset();
    const auto result_421 = is_legal_96_97_96(rgCache);
    rgCache.decDepth();
    if (result_421)
    {
        state_149(moves, mr,rgCache);
        return;
    }
    state_95(moves, mr,rgCache);
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old423_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_13(moves, mr,rgCache);
    counters[board[coord]] = old423_0;
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old424_0 = counters[b];
    counters[b] = counters[b]+1;
    state_91(moves, mr,rgCache);
    counters[b] = old424_0;
}

void GameState::state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_93(moves, mr,rgCache);
}

void GameState::state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old426_0 = board[coord];
    board[coord] = b;
    state_89(moves, mr,rgCache);
    board[coord] = old426_0;
}

void GameState::state_93([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_92(moves, mr,rgCache);
}

void GameState::state_94([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_94;
    if (cache)
    {
        return;
    }
    cache = true;
    state_3(moves, mr,rgCache);
}

void GameState::state_95([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_94(moves, mr,rgCache);
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
    if (is_legal_158_159_158(rgCache))
    {
        if (apply_state_164(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_165(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 0:
{
                return apply_state_10(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_0(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 0)
    {
        if (apply_state_10(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_250 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (!result_250)
    {
        if (apply_state_45(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_22.reset();
    rgCache.state_cache_25.reset();
    rgCache.state_cache_27.reset();
    rgCache.state_cache_29.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_33.reset();
    rgCache.state_cache_35.reset();
    rgCache.state_cache_37.reset();
    const auto result_249 = is_legal_19_20_19(rgCache);
    rgCache.decDepth();
    if (!result_249)
    {
        if (apply_state_18(mr,rgCache))
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

bool GameState::apply_state_122([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_94(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old268_0 = counters[r];
    counters[r] = counters[r]+1;
    if (apply_state_14(mr,rgCache))
    {
        return true;
    }
    counters[r] = old268_0;
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_16(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_288 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (result_288)
    {
        if (apply_state_150(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old289_0 = board[coord];
    board[coord] = r;
    if (apply_state_12(mr,rgCache))
    {
        return true;
    }
    board[coord] = old289_0;
    return false;
}

bool GameState::apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old290_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    if (apply_state_152(mr,rgCache))
    {
        return true;
    }
    goals[blue - 2] = old290_0;
    return false;
}

bool GameState::apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_156(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_153(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_151(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old294_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old294_0;
    return false;
}

bool GameState::apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_155(mr,rgCache))
    {
        return true;
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

bool GameState::apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old464_0 = player;
    player = red;
    currentState = 102;
    return true;
    player = old464_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old466_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old466_0;
    return false;
}

bool GameState::apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old468_0 = player;
    player = keeper;
    currentState = 192;
    return true;
    player = old468_0;
    return false;
}

bool GameState::apply_state_165([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old470_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old470_0;
    return false;
}

bool GameState::apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old472_0 = player;
    player = blue;
    currentState = 152;
    return true;
    player = old472_0;
    return false;
}

bool GameState::apply_state_167([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old474_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old474_0;
    return false;
}

bool GameState::apply_state_168([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old476_0 = player;
    player = keeper;
    currentState = 162;
    return true;
    player = old476_0;
    return false;
}

bool GameState::apply_state_169([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old478_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old478_0;
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (apply_state_83(mr,rgCache))
    {
        return true;
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

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_6(mr,rgCache))
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

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_10(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_17(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_state_162(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_163(mr,rgCache))
    {
        return true;
    }
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

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_8(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_72([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_376 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (result_376)
    {
        if (apply_state_73(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old377_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_state_75(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old377_0;
    return false;
}

bool GameState::apply_state_74([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_79(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_76(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_74(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old381_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    player = old381_0;
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
    if (mr[0] == 1 + coord)
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
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_87(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_81_87_81_81_87_87_81_87_81())
    {
        if (apply_state_166(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_167(mr,rgCache))
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
    if (board[coord]==e)
    {
        if (apply_state_85(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_85([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 1 + coord)
    {
        if (apply_state_88(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old393_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_90(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old393_0;
    return false;
}

bool GameState::apply_state_87([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_160_161_160(rgCache))
    {
        if (apply_state_168(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_169(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 123:
{
                return apply_state_87(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_88([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_3(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 123)
    {
        if (apply_state_87(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_89([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_420 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (!result_420)
    {
        if (apply_state_122(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_102.reset();
    rgCache.state_cache_104.reset();
    rgCache.state_cache_106.reset();
    rgCache.state_cache_108.reset();
    rgCache.state_cache_110.reset();
    rgCache.state_cache_112.reset();
    rgCache.state_cache_114.reset();
    rgCache.state_cache_99.reset();
    const auto result_421 = is_legal_96_97_96(rgCache);
    rgCache.decDepth();
    if (result_421)
    {
        if (apply_state_149(mr,rgCache))
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

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old423_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_13(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old423_0;
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old424_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_91(mr,rgCache))
    {
        return true;
    }
    counters[b] = old424_0;
    return false;
}

bool GameState::apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_93(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old426_0 = board[coord];
    board[coord] = b;
    if (apply_state_89(mr,rgCache))
    {
        return true;
    }
    board[coord] = old426_0;
    return false;
}

bool GameState::apply_state_93([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_92(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_94([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_94;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (apply_state_3(mr,rgCache))
    {
        return true;
    }
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

bool GameState::apply_any_86_86_122([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_94(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_149([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_25 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (result_25)
    {
        if (apply_any_86_86_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_86_86_150([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    if (apply_any_86_86_152(rgCache))
    {
        return true;
    }
    goals[blue - 2] = old26_0;
    return false;
}

bool GameState::apply_any_86_86_151([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_156(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_152([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_153(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_153([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_151(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_155([[maybe_unused]]RgCache& rgCache)
{
    const auto old30_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    if (apply_any_86_86_end(rgCache))
    {
        return true;
    }
    player = old30_0;
    return false;
}

bool GameState::apply_any_86_86_156([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_155(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old46_0 = player;
    player = red;
    currentState = 102;
    return true;
    if (apply_any_86_86_4(rgCache))
    {
        return true;
    }
    player = old46_0;
    return false;
}

bool GameState::apply_any_86_86_163([[maybe_unused]]RgCache& rgCache)
{
    const auto old48_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    if (apply_any_86_86_end(rgCache))
    {
        return true;
    }
    player = old48_0;
    return false;
}

bool GameState::apply_any_86_86_2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_3([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_86_86_5([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_any_86_86_162(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_86_86_163(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_86([[maybe_unused]]RgCache& rgCache)
{
    const auto old35_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_86_86_90(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old35_0;
    return false;
}

bool GameState::apply_any_86_86_89([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_126.reset();
    rgCache.state_cache_129.reset();
    rgCache.state_cache_131.reset();
    rgCache.state_cache_133.reset();
    rgCache.state_cache_135.reset();
    rgCache.state_cache_137.reset();
    rgCache.state_cache_139.reset();
    rgCache.state_cache_141.reset();
    const auto result_36 = is_legal_123_124_123(rgCache);
    rgCache.decDepth();
    if (!result_36)
    {
        if (apply_any_86_86_122(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_102.reset();
    rgCache.state_cache_104.reset();
    rgCache.state_cache_106.reset();
    rgCache.state_cache_108.reset();
    rgCache.state_cache_110.reset();
    rgCache.state_cache_112.reset();
    rgCache.state_cache_114.reset();
    rgCache.state_cache_99.reset();
    const auto result_37 = is_legal_96_97_96(rgCache);
    rgCache.decDepth();
    if (result_37)
    {
        if (apply_any_86_86_149(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_86_86_95(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_90([[maybe_unused]]RgCache& rgCache)
{
    const auto old39_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_86_86_91(rgCache))
    {
        return true;
    }
    counters[b] = old39_0;
    return false;
}

bool GameState::apply_any_86_86_91([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_93(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_92([[maybe_unused]]RgCache& rgCache)
{
    const auto old41_0 = board[coord];
    board[coord] = b;
    if (apply_any_86_86_89(rgCache))
    {
        return true;
    }
    board[coord] = old41_0;
    return false;
}

bool GameState::apply_any_86_86_93([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_92(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_94([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_94;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (apply_any_86_86_3(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_95([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_86_86_94(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_86_86_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_9_9_12([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_23 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (!result_23)
    {
        if (apply_any_9_9_45(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_22.reset();
    rgCache.state_cache_25.reset();
    rgCache.state_cache_27.reset();
    rgCache.state_cache_29.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_33.reset();
    rgCache.state_cache_35.reset();
    rgCache.state_cache_37.reset();
    const auto result_22 = is_legal_19_20_19(rgCache);
    rgCache.decDepth();
    if (!result_22)
    {
        if (apply_any_9_9_18(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_9_9_72(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_13([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = counters[r];
    counters[r] = counters[r]+1;
    if (apply_any_9_9_14(rgCache))
    {
        return true;
    }
    counters[r] = old25_0;
    return false;
}

bool GameState::apply_any_9_9_14([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_16(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old27_0 = board[coord];
    board[coord] = r;
    if (apply_any_9_9_12(rgCache))
    {
        return true;
    }
    board[coord] = old27_0;
    return false;
}

bool GameState::apply_any_9_9_16([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_15(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_166([[maybe_unused]]RgCache& rgCache)
{
    const auto old42_0 = player;
    player = blue;
    currentState = 152;
    return true;
    if (apply_any_9_9_81(rgCache))
    {
        return true;
    }
    player = old42_0;
    return false;
}

bool GameState::apply_any_9_9_167([[maybe_unused]]RgCache& rgCache)
{
    const auto old44_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    if (apply_any_9_9_end(rgCache))
    {
        return true;
    }
    player = old44_0;
    return false;
}

bool GameState::apply_any_9_9_17([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (apply_any_9_9_83(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_18([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_17(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_45([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_17(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_49.reset();
    rgCache.state_cache_52.reset();
    rgCache.state_cache_54.reset();
    rgCache.state_cache_56.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_60.reset();
    rgCache.state_cache_62.reset();
    rgCache.state_cache_64.reset();
    const auto result_32 = is_legal_46_47_46(rgCache);
    rgCache.decDepth();
    if (result_32)
    {
        if (apply_any_9_9_73(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_9_9_73([[maybe_unused]]RgCache& rgCache)
{
    const auto old33_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_any_9_9_75(rgCache))
    {
        return true;
    }
    goals[red - 2] = old33_0;
    return false;
}

bool GameState::apply_any_9_9_74([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_79(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_75([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_76(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_76([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_74(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_78([[maybe_unused]]RgCache& rgCache)
{
    const auto old37_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    if (apply_any_9_9_end(rgCache))
    {
        return true;
    }
    player = old37_0;
    return false;
}

bool GameState::apply_any_9_9_79([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_78(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_81([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_9_9_82([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_81_87_81_81_87_87_81_87_81())
    {
        if (apply_any_9_9_166(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_9_9_167(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_83([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_9_9_82(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_9_9_9([[maybe_unused]]RgCache& rgCache)
{
    const auto old40_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_9_9_13(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old40_0;
    return false;
}

bool GameState::apply_any_9_9_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = player;
    player = red;
    currentState = 102;
    return true;
    if (apply_any_begin_begin_4(rgCache))
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_begin_begin_163([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 228;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_5([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_any_begin_begin_162(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_163(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_begin_begin_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

}  // namespace reasoner
