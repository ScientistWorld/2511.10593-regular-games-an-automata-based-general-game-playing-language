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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "hx0y0: " << board[hx0y0] << ", " << "hx0y1: " << board[hx0y1] << ", " << "hx1y1: " << board[hx1y1] << ", " << "hx0y2: " << board[hx0y2] << ", " << "hx1y2: " << board[hx1y2] << ", " << "hx2y2: " << board[hx2y2] << ", " << "hx0y3: " << board[hx0y3] << ", " << "hx1y3: " << board[hx1y3] << ", " << "hx2y3: " << board[hx2y3] << ", " << "hx3y3: " << board[hx3y3] << ", " << "hx0y4: " << board[hx0y4] << ", " << "hx1y4: " << board[hx1y4] << ", " << "hx2y4: " << board[hx2y4] << ", " << "hx3y4: " << board[hx3y4] << ", " << "hx4y4: " << board[hx4y4] << ", " << "hx0y5: " << board[hx0y5] << ", " << "hx1y5: " << board[hx1y5] << ", " << "hx2y5: " << board[hx2y5] << ", " << "hx3y5: " << board[hx3y5] << ", " << "hx4y5: " << board[hx4y5] << ", " << "hx5y5: " << board[hx5y5] << ", " << "hx0y6: " << board[hx0y6] << ", " << "hx1y6: " << board[hx1y6] << ", " << "hx2y6: " << board[hx2y6] << ", " << "hx3y6: " << board[hx3y6] << ", " << "hx4y6: " << board[hx4y6] << ", " << "hx5y6: " << board[hx5y6] << ", " << "hx6y6: " << board[hx6y6] << ", " << "hx0y7: " << board[hx0y7] << ", " << "hx1y7: " << board[hx1y7] << ", " << "hx2y7: " << board[hx2y7] << ", " << "hx3y7: " << board[hx3y7] << ", " << "hx4y7: " << board[hx4y7] << ", " << "hx5y7: " << board[hx5y7] << ", " << "hx6y7: " << board[hx6y7] << ", " << "hx7y7: " << board[hx7y7] << ", " << "hx0y8: " << board[hx0y8] << ", " << "hx1y8: " << board[hx1y8] << ", " << "hx2y8: " << board[hx2y8] << ", " << "hx3y8: " << board[hx3y8] << ", " << "hx4y8: " << board[hx4y8] << ", " << "hx5y8: " << board[hx5y8] << ", " << "hx6y8: " << board[hx6y8] << ", " << "hx7y8: " << board[hx7y8] << ", " << "hx8y8: " << board[hx8y8] << ", " << "hx0y9: " << board[hx0y9] << ", " << "hx1y9: " << board[hx1y9] << ", " << "hx2y9: " << board[hx2y9] << ", " << "hx3y9: " << board[hx3y9] << ", " << "hx4y9: " << board[hx4y9] << ", " << "hx5y9: " << board[hx5y9] << ", " << "hx6y9: " << board[hx6y9] << ", " << "hx7y9: " << board[hx7y9] << ", " << "hx0y10: " << board[hx0y10] << ", " << "hx1y10: " << board[hx1y10] << ", " << "hx2y10: " << board[hx2y10] << ", " << "hx3y10: " << board[hx3y10] << ", " << "hx4y10: " << board[hx4y10] << ", " << "hx5y10: " << board[hx5y10] << ", " << "hx6y10: " << board[hx6y10] << ", " << "hx0y11: " << board[hx0y11] << ", " << "hx1y11: " << board[hx1y11] << ", " << "hx2y11: " << board[hx2y11] << ", " << "hx3y11: " << board[hx3y11] << ", " << "hx4y11: " << board[hx4y11] << ", " << "hx5y11: " << board[hx5y11] << ", " << "hx0y12: " << board[hx0y12] << ", " << "hx1y12: " << board[hx1y12] << ", " << "hx2y12: " << board[hx2y12] << ", " << "hx3y12: " << board[hx3y12] << ", " << "hx4y12: " << board[hx4y12] << ", " << "hx0y13: " << board[hx0y13] << ", " << "hx1y13: " << board[hx1y13] << ", " << "hx2y13: " << board[hx2y13] << ", " << "hx3y13: " << board[hx3y13] << ", " << "hx0y14: " << board[hx0y14] << ", " << "hx1y14: " << board[hx1y14] << ", " << "hx2y14: " << board[hx2y14] << ", " << "hx0y15: " << board[hx0y15] << ", " << "hx1y15: " << board[hx1y15] << ", " << "hx0y16: " << board[hx0y16]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
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
        case 30:
{
            state_4(moves, mr.mr,rgCache);
            return;
}
        case 40:
{
            state_81(moves, mr.mr,rgCache);
            return;
}
        case 56:
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
        case 30:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 40:
{
            apply_state_81(mr.mr,rgCache);
            return;
}
        case 56:
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
        case 7:
{
            apply_any_13_13_13(rgCache);
            rgCache.reset();
            break;
}
        case 51:
{
            apply_any_90_90_90(rgCache);
            rgCache.reset();
            break;
}
        case 56:
{
            apply_any_begin_begin_begin(rgCache);
            rgCache.reset();
            break;
}
    }
}

bool GameState::is_legal_126_124_124([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_126_124_126([[maybe_unused]]RgCache& rgCache)
{
    const auto old3_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old3_0;
        return true;
    }
    coord = old3_0;
    const auto old4_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    const auto old5_0 = coord;
    coord = direction_E[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    const auto old6_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    const auto old7_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old7_0;
        return true;
    }
    coord = old7_0;
    const auto old8_0 = coord;
    coord = direction_W[coord];
    if (is_legal_126_124_128(rgCache))
    {
        coord = old8_0;
        return true;
    }
    coord = old8_0;
    if (direction_SW[coord]==null)
    {
        if (is_legal_126_124_124(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_126_124_128([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_128;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_126_124_126(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_158_159_158([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_9_82_9_9_82_82_9_82_9(rgCache))
    {
        if (is_legal_158_159_159(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = board[coord];
    board[coord] = r;
    if (is_legal_158_159_172(rgCache))
    {
        board[coord] = old5_0;
        return true;
    }
    board[coord] = old5_0;
    return false;
}

bool GameState::is_legal_158_159_159([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_158_159_172([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_6 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (result_6)
    {
        if (is_legal_158_159_173(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_158_159_173([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_7 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (result_7)
    {
        if (is_legal_158_159_159(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_160_161_160([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_86_5_86_86_5_5_86_5_86(rgCache))
    {
        if (is_legal_160_161_161(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = board[coord];
    board[coord] = b;
    if (is_legal_160_161_175(rgCache))
    {
        board[coord] = old5_0;
        return true;
    }
    board[coord] = old5_0;
    return false;
}

bool GameState::is_legal_160_161_161([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_160_161_175([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_7 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (result_7)
    {
        if (is_legal_160_161_176(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_160_161_176([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_6 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (result_6)
    {
        if (is_legal_160_161_161(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_177_20_177([[maybe_unused]]RgCache& rgCache)
{
    const auto old3_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old3_0;
        return true;
    }
    coord = old3_0;
    const auto old4_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    const auto old5_0 = coord;
    coord = direction_E[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    const auto old6_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    const auto old7_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old7_0;
        return true;
    }
    coord = old7_0;
    const auto old8_0 = coord;
    coord = direction_W[coord];
    if (is_legal_177_20_24(rgCache))
    {
        coord = old8_0;
        return true;
    }
    coord = old8_0;
    if (direction_NW[coord]==null)
    {
        if (is_legal_177_20_20(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_177_20_20([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_177_20_24([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_24;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==r)
    {
        if (is_legal_177_20_177(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_178_47_178([[maybe_unused]]RgCache& rgCache)
{
    const auto old3_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old3_0;
        return true;
    }
    coord = old3_0;
    const auto old4_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    const auto old5_0 = coord;
    coord = direction_E[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    const auto old6_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    const auto old7_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old7_0;
        return true;
    }
    coord = old7_0;
    const auto old8_0 = coord;
    coord = direction_W[coord];
    if (is_legal_178_47_51(rgCache))
    {
        coord = old8_0;
        return true;
    }
    coord = old8_0;
    if (direction_SE[coord]==null)
    {
        if (is_legal_178_47_47(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_178_47_47([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_178_47_51([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_51;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==r)
    {
        if (is_legal_178_47_178(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_179_97_101([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_101;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_179_97_179(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_179_97_179([[maybe_unused]]RgCache& rgCache)
{
    const auto old4_0 = coord;
    coord = direction_NW[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    const auto old5_0 = coord;
    coord = direction_NE[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    const auto old6_0 = coord;
    coord = direction_E[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    const auto old7_0 = coord;
    coord = direction_SE[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old7_0;
        return true;
    }
    coord = old7_0;
    const auto old8_0 = coord;
    coord = direction_SW[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old8_0;
        return true;
    }
    coord = old8_0;
    const auto old9_0 = coord;
    coord = direction_W[coord];
    if (is_legal_179_97_101(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    if (direction_NE[coord]==null)
    {
        if (is_legal_179_97_97(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_179_97_97([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_10()
{
    return true;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_4()
{
    const auto old3_0 = coord;
    for (coord = hx0y0; coord <= hx8y8; ++coord)
    {
    if (is_legal_4_10_4_4_10_10_4_10_7())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_4_10_4_4_10_10_4_10_7()
{
    if (board[coord]==e)
    {
        if (is_legal_4_10_4_4_10_10_4_10_10())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_81()
{
    const auto old3_0 = coord;
    for (coord = hx0y0; coord <= hx8y8; ++coord)
    {
    if (is_legal_81_87_81_81_87_87_81_87_84())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_84()
{
    if (board[coord]==e)
    {
        if (is_legal_81_87_81_81_87_87_81_87_87())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_81_87_81_81_87_87_81_87_87()
{
    return true;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_5([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_86([[maybe_unused]]RgCache& rgCache)
{
    const auto old5_0 = board[coord];
    board[coord] = b;
    if (is_legal_86_5_86_86_5_5_86_5_89(rgCache))
    {
        board[coord] = old5_0;
        return true;
    }
    board[coord] = old5_0;
    return false;
}

bool GameState::is_legal_86_5_86_86_5_5_86_5_89([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_3 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (!result_3)
    {
        if (is_legal_86_5_86_86_5_5_86_5_5(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_4 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (!result_4)
    {
        if (is_legal_86_5_86_86_5_5_86_5_5(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_12([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_3 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (!result_3)
    {
        if (is_legal_9_82_9_9_82_82_9_82_82(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_4 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (!result_4)
    {
        if (is_legal_9_82_9_9_82_82_9_82_82(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_82([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_9_82_9_9_82_82_9_82_9([[maybe_unused]]RgCache& rgCache)
{
    const auto old5_0 = board[coord];
    board[coord] = r;
    if (is_legal_9_82_9_9_82_82_9_82_12(rgCache))
    {
        board[coord] = old5_0;
        return true;
    }
    board[coord] = old5_0;
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_158_159_158(rgCache))
    {
        state_151(moves, mr,rgCache);
        return;
    }
    state_164(moves, mr,rgCache);
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_58 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (!result_58)
    {
        state_17(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_59 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (!result_59)
    {
        state_17(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_60 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (result_60)
    {
        state_72(moves, mr,rgCache);
    }
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = board[coord];
    board[coord] = r;
    state_12(moves, mr,rgCache);
    board[coord] = old69_0;
}

void GameState::state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_68 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (result_68)
    {
        state_150(moves, mr,rgCache);
    }
}

void GameState::state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old70_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    state_151(moves, mr,rgCache);
    goals[blue - 2] = old70_0;
}

void GameState::state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_166([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_168([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
    if (!is_legal_81_87_81_81_87_87_81_87_81())
    {
        state_151(moves, mr,rgCache);
        return;
    }
    state_166(moves, mr,rgCache);
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache)
    {
        return;
    }
    cache = true;
    if (!is_legal_4_10_4_4_10_10_4_10_4())
    {
        state_151(moves, mr,rgCache);
        return;
    }
    state_162(moves, mr,rgCache);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old81_0 = coord;
    for (coord = hx0y0; coord <= hx8y8; ++coord)
    {
    state_7(moves, mr,rgCache);    }
    coord = old81_0;
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
    rgCache.state_cache_51.reset();
    const auto result_92 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (result_92)
    {
        state_73(moves, mr,rgCache);
    }
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old138_0 = goals[red - 2];
    goals[red - 2] = 100;
    state_151(moves, mr,rgCache);
    goals[red - 2] = old138_0;
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_10(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_81([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = coord;
    for (coord = hx0y0; coord <= hx8y8; ++coord)
    {
    state_84(moves, mr,rgCache);    }
    coord = old94_0;
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
    mr[0] = 0 + coord;
    state_87(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_87([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_160_161_160(rgCache))
    {
        state_151(moves, mr,rgCache);
        return;
    }
    state_168(moves, mr,rgCache);
}

void GameState::state_89([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_102 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (!result_102)
    {
        state_2(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_103 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (result_103)
    {
        state_149(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_104 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (!result_104)
    {
        state_2(moves, mr,rgCache);
    }
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = board[coord];
    board[coord] = b;
    state_89(moves, mr,rgCache);
    board[coord] = old105_0;
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
    if (!is_legal_158_159_158(rgCache))
    {
        if (apply_state_151(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_164(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_58 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (!result_58)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_59 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (!result_59)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_60 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (result_60)
    {
        if (apply_state_72(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = board[coord];
    board[coord] = r;
    if (apply_state_12(mr,rgCache))
    {
        return true;
    }
    board[coord] = old69_0;
    return false;
}

bool GameState::apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_68 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (result_68)
    {
        if (apply_state_150(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old70_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    if (apply_state_151(mr,rgCache))
    {
        return true;
    }
    goals[blue - 2] = old70_0;
    return false;
}

bool GameState::apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old71_0 = player;
    player = keeper;
    currentState = 57;
    return true;
    player = old71_0;
    return false;
}

bool GameState::apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old117_0 = player;
    player = red;
    currentState = 30;
    return true;
    player = old117_0;
    return false;
}

bool GameState::apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old119_0 = player;
    player = keeper;
    currentState = 7;
    return true;
    player = old119_0;
    return false;
}

bool GameState::apply_state_166([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old121_0 = player;
    player = blue;
    currentState = 40;
    return true;
    player = old121_0;
    return false;
}

bool GameState::apply_state_168([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old123_0 = player;
    player = keeper;
    currentState = 51;
    return true;
    player = old123_0;
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
    if (!is_legal_81_87_81_81_87_87_81_87_81())
    {
        if (apply_state_151(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_166(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (!is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_state_151(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_162(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            return apply_state_10(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
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
    rgCache.state_cache_51.reset();
    const auto result_92 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (result_92)
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
    const auto old138_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_state_151(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old138_0;
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_10(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            return apply_state_87(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_81([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
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
    if (mr[0] == 0 + coord)
    {
        if (apply_state_87(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_87([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_160_161_160(rgCache))
    {
        if (apply_state_151(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_168(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_89([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_102 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (!result_102)
    {
        if (apply_state_2(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_103 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (result_103)
    {
        if (apply_state_149(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_104 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (!result_104)
    {
        if (apply_state_2(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = board[coord];
    board[coord] = b;
    if (apply_state_89(mr,rgCache))
    {
        return true;
    }
    board[coord] = old105_0;
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

bool GameState::apply_any_13_13_12([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_9 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (!result_9)
    {
        if (apply_any_13_13_17(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_10 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (!result_10)
    {
        if (apply_any_13_13_17(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_24.reset();
    const auto result_11 = is_legal_177_20_177(rgCache);
    rgCache.decDepth();
    if (result_11)
    {
        if (apply_any_13_13_72(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_13_13_13([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = board[coord];
    board[coord] = r;
    if (apply_any_13_13_12(rgCache))
    {
        return true;
    }
    board[coord] = old12_0;
    return false;
}

bool GameState::apply_any_13_13_151([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = player;
    player = keeper;
    currentState = 57;
    return true;
    if (apply_any_13_13_end(rgCache))
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_13_13_166([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = player;
    player = blue;
    currentState = 40;
    return true;
    if (apply_any_13_13_81(rgCache))
    {
        return true;
    }
    player = old16_0;
    return false;
}

bool GameState::apply_any_13_13_17([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (!is_legal_81_87_81_81_87_87_81_87_81())
    {
        if (apply_any_13_13_151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_13_13_166(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_13_13_72([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_51.reset();
    const auto result_14 = is_legal_178_47_178(rgCache);
    rgCache.decDepth();
    if (result_14)
    {
        if (apply_any_13_13_73(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_13_13_73([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_any_13_13_151(rgCache))
    {
        return true;
    }
    goals[red - 2] = old18_0;
    return false;
}

bool GameState::apply_any_13_13_81([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_13_13_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_90_90_149([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_9 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (result_9)
    {
        if (apply_any_90_90_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_90_90_150([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = goals[blue - 2];
    goals[blue - 2] = 100;
    if (apply_any_90_90_151(rgCache))
    {
        return true;
    }
    goals[blue - 2] = old10_0;
    return false;
}

bool GameState::apply_any_90_90_151([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = player;
    player = keeper;
    currentState = 57;
    return true;
    if (apply_any_90_90_end(rgCache))
    {
        return true;
    }
    player = old11_0;
    return false;
}

bool GameState::apply_any_90_90_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = player;
    player = red;
    currentState = 30;
    return true;
    if (apply_any_90_90_4(rgCache))
    {
        return true;
    }
    player = old17_0;
    return false;
}

bool GameState::apply_any_90_90_2([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (!is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_any_90_90_151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_90_90_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_90_90_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_90_90_89([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_128.reset();
    const auto result_12 = is_legal_126_124_126(rgCache);
    rgCache.decDepth();
    if (!result_12)
    {
        if (apply_any_90_90_2(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_13 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (result_13)
    {
        if (apply_any_90_90_149(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_101.reset();
    const auto result_14 = is_legal_179_97_179(rgCache);
    rgCache.decDepth();
    if (!result_14)
    {
        if (apply_any_90_90_2(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_90_90_90([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = board[coord];
    board[coord] = b;
    if (apply_any_90_90_89(rgCache))
    {
        return true;
    }
    board[coord] = old15_0;
    return false;
}

bool GameState::apply_any_90_90_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_151([[maybe_unused]]RgCache& rgCache)
{
    const auto old6_0 = player;
    player = keeper;
    currentState = 57;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old6_0;
    return false;
}

bool GameState::apply_any_begin_begin_162([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = player;
    player = red;
    currentState = 30;
    return true;
    if (apply_any_begin_begin_4(rgCache))
    {
        return true;
    }
    player = old9_0;
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache)
    {
        return false;
    }
    cache = true;
    if (!is_legal_4_10_4_4_10_10_4_10_4())
    {
        if (apply_any_begin_begin_151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_162(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
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
