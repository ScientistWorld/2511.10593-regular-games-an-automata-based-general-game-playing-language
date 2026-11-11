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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "goals = " << "{" << "red: " << goals[red-2] << ", " << "yellow: " << goals[yellow-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "red: " << visible[red-2] << ", " << "yellow: " << visible[yellow-2]<< "}" << std::endl;
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
        case 14:
{
            state_14(moves, mr.mr,rgCache);
            return;
}
        case 21:
{
            state_152(moves, mr.mr,rgCache);
            return;
}
        case 89:
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
        case 14:
{
            apply_state_14(mr.mr,rgCache);
            return;
}
        case 21:
{
            apply_state_152(mr.mr,rgCache);
            return;
}
        case 89:
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
        case 30:
{
            apply_any_157_157_157(rgCache);
            rgCache.reset();
            break;
}
        case 45:
{
            apply_any_19_19_19(rgCache);
            rgCache.reset();
            break;
}
        case 89:
{
            apply_any_begin_begin_begin(rgCache);
            rgCache.reset();
            break;
}
    }
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_10()
{
    const auto old4_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (is_legal_10_17_10_10_17_17_10_17_13())
    {
        coord = old4_0;
        return true;
    }    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_13()
{
    if (board[coord]==e)
    {
        if (is_legal_10_17_10_10_17_17_10_17_17())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_17()
{
    return true;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_148()
{
    const auto old4_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (is_legal_148_155_148_148_155_155_148_155_151())
    {
        coord = old4_0;
        return true;
    }    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_151()
{
    if (board[coord]==e)
    {
        if (is_legal_148_155_148_148_155_155_148_155_155())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_155()
{
    return true;
}

bool GameState::is_legal_154_11_157_154_11_11_154_11_11([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_154_11_157_154_11_11_154_11_157([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_11_157;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_154_11_157_154_11_11_292(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = coord;
    coord = direction_down[coord];
    if (is_legal_154_11_157_154_11_11_154_11_157(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_154_11_157_154_11_11_154_11_163([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (is_legal_154_11_157_154_11_11_154_11_11(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_11_157_154_11_11_292([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (is_legal_154_11_157_154_11_11_154_11_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_277_157_154_277_277_154_277_157([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_277_157;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_154_277_157_154_277_277_293(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = coord;
    coord = direction_down[coord];
    if (is_legal_154_277_157_154_277_277_154_277_157(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_154_277_157_154_277_277_154_277_163([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_166())
    {
        if (is_legal_154_277_157_154_277_277_154_277_277(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_277_157_154_277_277_154_277_277([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_154_277_157_154_277_277_293([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (is_legal_154_277_157_154_277_277_154_277_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_166()
{
    if (board[RbgCoordMap1[coord]]==y)
    {
        if (is_legal_166_167_171())
        {
            return true;
        }
    }
    if (board[RbgCoordMap3[coord]]==y)
    {
        if (is_legal_166_167_184())
        {
            return true;
        }
    }
    if (board[direction_left[coord]]==y)
    {
        if (is_legal_166_167_200())
        {
            return true;
        }
    }
    if (board[direction_right[coord]]==y)
    {
        if (is_legal_166_167_216())
        {
            return true;
        }
    }
    if (board[RbgCoordMap7[coord]]==y)
    {
        if (is_legal_166_167_229())
        {
            return true;
        }
    }
    if (board[direction_down[coord]]==y)
    {
        if (is_legal_166_167_245())
        {
            return true;
        }
    }
    if (board[RbgCoordMap9[coord]]==y)
    {
        if (is_legal_166_167_254())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_167()
{
    return true;
}

bool GameState::is_legal_166_167_171()
{
    if (board[__gen_RbgCoordMap1_RbgCoordMap1[coord]]==y)
    {
        if (is_legal_166_167_173())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_173()
{
    if (board[__gen_RbgCoordMap1___gen_RbgCoordMap1_RbgCoordMap1[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap1_RbgCoordMap1[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_184()
{
    if (board[__gen_RbgCoordMap3_RbgCoordMap3[coord]]==y)
    {
        if (is_legal_166_167_186())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_186()
{
    if (board[__gen_RbgCoordMap3___gen_RbgCoordMap3_RbgCoordMap3[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap3_RbgCoordMap3[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_200()
{
    if (board[__gen_direction_left_direction_left[coord]]==y)
    {
        if (is_legal_166_167_201())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_201()
{
    if (board[__gen_direction_left___gen_direction_left_direction_left[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap5___gen_direction_left_direction_left[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_216()
{
    if (board[__gen_direction_right_direction_right[coord]]==y)
    {
        if (is_legal_166_167_217())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_217()
{
    if (board[__gen_direction_right___gen_direction_right_direction_right[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap6___gen_direction_right_direction_right[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_229()
{
    if (board[__gen_RbgCoordMap7_RbgCoordMap7[coord]]==y)
    {
        if (is_legal_166_167_231())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_231()
{
    if (board[__gen_RbgCoordMap7___gen_RbgCoordMap7_RbgCoordMap7[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap8___gen_RbgCoordMap7_RbgCoordMap7[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_245()
{
    if (board[__gen_direction_down_direction_down[coord]]==y)
    {
        if (is_legal_166_167_249())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_249()
{
    if (board[__gen_direction_down___gen_direction_down_direction_down[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_254()
{
    if (board[__gen_RbgCoordMap9_RbgCoordMap9[coord]]==y)
    {
        if (is_legal_166_167_256())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_256()
{
    if (board[__gen_RbgCoordMap9___gen_RbgCoordMap9_RbgCoordMap9[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap10___gen_RbgCoordMap9_RbgCoordMap9[coord]]==y)
    {
        if (is_legal_166_167_167())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_145_19_16_145_145_16_145_145([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_16_145_19_16_145_145_16_145_19([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_145_19;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_16_145_19_16_145_145_295(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = coord;
    coord = direction_down[coord];
    if (is_legal_16_145_19_16_145_145_16_145_19(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_16_145_19_16_145_145_16_145_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_34_35_34())
    {
        if (is_legal_16_145_19_16_145_145_16_145_145(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_145_19_16_145_145_295([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (is_legal_16_145_19_16_145_145_16_145_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_19_16_149_149_16_149_149([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_16_149_19_16_149_149_16_149_19([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_149_19;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_16_149_19_16_149_149_296(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = coord;
    coord = direction_down[coord];
    if (is_legal_16_149_19_16_149_149_16_149_19(rgCache))
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_16_149_19_16_149_149_16_149_25([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        if (is_legal_16_149_19_16_149_149_16_149_149(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_19_16_149_149_296([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (is_legal_16_149_19_16_149_149_16_149_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_280_281_280([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_16_145_19.reset();
    const auto result_2 = is_legal_16_145_19_16_145_145_16_145_19(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_280_281_281(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_16_149_19.reset();
    const auto result_3 = is_legal_16_149_19_16_149_149_16_149_19(rgCache);
    rgCache.decDepth();
    if (result_3)
    {
        if (is_legal_280_281_281(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_280_281_281([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_282_283_282([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_154_11_157.reset();
    const auto result_2 = is_legal_154_11_157_154_11_11_154_11_157(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_282_283_283(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_154_277_157.reset();
    const auto result_3 = is_legal_154_277_157_154_277_277_154_277_157(rgCache);
    rgCache.decDepth();
    if (result_3)
    {
        if (is_legal_282_283_283(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_282_283_283([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_34_35_113()
{
    if (board[__gen_direction_down_direction_down[coord]]==r)
    {
        if (is_legal_34_35_117())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_117()
{
    if (board[__gen_direction_down___gen_direction_down_direction_down[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_122()
{
    if (board[__gen_RbgCoordMap9_RbgCoordMap9[coord]]==r)
    {
        if (is_legal_34_35_124())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_124()
{
    if (board[__gen_RbgCoordMap9___gen_RbgCoordMap9_RbgCoordMap9[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap10___gen_RbgCoordMap9_RbgCoordMap9[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_34()
{
    if (board[direction_down[coord]]==r)
    {
        if (is_legal_34_35_113())
        {
            return true;
        }
    }
    if (board[RbgCoordMap9[coord]]==r)
    {
        if (is_legal_34_35_122())
        {
            return true;
        }
    }
    if (board[RbgCoordMap1[coord]]==r)
    {
        if (is_legal_34_35_39())
        {
            return true;
        }
    }
    if (board[RbgCoordMap3[coord]]==r)
    {
        if (is_legal_34_35_52())
        {
            return true;
        }
    }
    if (board[direction_left[coord]]==r)
    {
        if (is_legal_34_35_68())
        {
            return true;
        }
    }
    if (board[direction_right[coord]]==r)
    {
        if (is_legal_34_35_84())
        {
            return true;
        }
    }
    if (board[RbgCoordMap7[coord]]==r)
    {
        if (is_legal_34_35_97())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_35()
{
    return true;
}

bool GameState::is_legal_34_35_39()
{
    if (board[__gen_RbgCoordMap1_RbgCoordMap1[coord]]==r)
    {
        if (is_legal_34_35_41())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_41()
{
    if (board[__gen_RbgCoordMap1___gen_RbgCoordMap1_RbgCoordMap1[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap2___gen_RbgCoordMap1_RbgCoordMap1[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_52()
{
    if (board[__gen_RbgCoordMap3_RbgCoordMap3[coord]]==r)
    {
        if (is_legal_34_35_54())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_54()
{
    if (board[__gen_RbgCoordMap3___gen_RbgCoordMap3_RbgCoordMap3[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap4___gen_RbgCoordMap3_RbgCoordMap3[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_68()
{
    if (board[__gen_direction_left_direction_left[coord]]==r)
    {
        if (is_legal_34_35_69())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_69()
{
    if (board[__gen_direction_left___gen_direction_left_direction_left[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap5___gen_direction_left_direction_left[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_84()
{
    if (board[__gen_direction_right_direction_right[coord]]==r)
    {
        if (is_legal_34_35_85())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_85()
{
    if (board[__gen_direction_right___gen_direction_right_direction_right[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap6___gen_direction_right_direction_right[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_97()
{
    if (board[__gen_RbgCoordMap7_RbgCoordMap7[coord]]==r)
    {
        if (is_legal_34_35_99())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_99()
{
    if (board[__gen_RbgCoordMap7___gen_RbgCoordMap7_RbgCoordMap7[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    if (board[__gen_RbgCoordMap8___gen_RbgCoordMap7_RbgCoordMap7[coord]]==r)
    {
        if (is_legal_34_35_35())
        {
            return true;
        }
    }
    return false;
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_17_10_10_17_17_10_17_10())
    {
        state_141(moves, mr,rgCache);
        return;
    }
    state_284(moves, mr,rgCache);
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 0;
    state_11(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_13([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_15(moves, mr,rgCache);
    }
}

void GameState::state_133([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = board[coord];
    board[coord] = r;
    state_32(moves, mr,rgCache);
    board[coord] = old104_0;
}

void GameState::state_137([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = goals[red - 2];
    goals[red - 2] = 100;
    state_139(moves, mr,rgCache);
    goals[red - 2] = old105_0;
}

void GameState::state_139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    state_141(moves, mr,rgCache);
    goals[yellow - 2] = old106_0;
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old107_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    state_13(moves, mr,rgCache);    }
    coord = old107_0;
}

void GameState::state_141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 1 + coord;
    state_17(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_153(moves, mr,rgCache);
    }
}

void GameState::state_152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old113_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    state_151(moves, mr,rgCache);    }
    coord = old113_0;
}

void GameState::state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 1 + coord;
    state_155(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_282_283_282(rgCache))
    {
        state_141(moves, mr,rgCache);
        return;
    }
    state_290(moves, mr,rgCache);
}

void GameState::state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_157;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_294(moves, mr,rgCache);
    }
    const auto old122_0 = coord;
    coord = direction_down[coord];
    state_157(moves, mr,rgCache);
    coord = old122_0;
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        state_265(moves, mr,rgCache);
        return;
    }
    state_269(moves, mr,rgCache);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_280_281_280(rgCache))
    {
        state_141(moves, mr,rgCache);
        return;
    }
    state_286(moves, mr,rgCache);
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_19;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_297(moves, mr,rgCache);
    }
    const auto old144_0 = coord;
    coord = direction_down[coord];
    state_19(moves, mr,rgCache);
    coord = old144_0;
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    state_8(moves, mr,rgCache);
    goals[yellow - 2] = old90_0;
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        state_133(moves, mr,rgCache);
        return;
    }
    state_137(moves, mr,rgCache);
}

void GameState::state_265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = board[coord];
    board[coord] = y;
    state_8(moves, mr,rgCache);
    board[coord] = old162_0;
}

void GameState::state_269([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old163_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    state_271(moves, mr,rgCache);
    goals[yellow - 2] = old163_0;
}

void GameState::state_271([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old202_0 = goals[red - 2];
    goals[red - 2] = 0;
    state_141(moves, mr,rgCache);
    goals[red - 2] = old202_0;
}

void GameState::state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_288([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_294([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        state_163(moves, mr,rgCache);
    }
}

void GameState::state_297([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        state_25(moves, mr,rgCache);
    }
}

void GameState::state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_148_155_148_148_155_155_148_155_148())
    {
        state_141(moves, mr,rgCache);
        return;
    }
    state_288(moves, mr,rgCache);
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 1 + coord;
    state_12(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old187_0 = goals[red - 2];
    goals[red - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[red - 2] = old187_0;
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_state_141(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_284(mr,rgCache))
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
                return apply_state_11(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_0(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 0)
    {
        if (apply_state_11(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_13([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_15(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_133([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old104_0 = board[coord];
    board[coord] = r;
    if (apply_state_32(mr,rgCache))
    {
        return true;
    }
    board[coord] = old104_0;
    return false;
}

bool GameState::apply_state_137([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_state_139(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old105_0;
    return false;
}

bool GameState::apply_state_139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    if (apply_state_141(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old106_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 1;
            return apply_state_17(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old108_0 = player;
    player = keeper;
    currentState = 90;
    return true;
    player = old108_0;
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 1 + coord)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_153(mr,rgCache))
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
            coord = mr[rgCache.currentMrId - 1] - 1;
            return apply_state_155(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 1 + coord)
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
    if (!is_legal_282_283_282(rgCache))
    {
        if (apply_state_141(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_290(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_157;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_294(mr,rgCache))
        {
            return true;
        }
    }
    const auto old122_0 = coord;
    coord = direction_down[coord];
    if (apply_state_157(mr,rgCache))
    {
        return true;
    }
    coord = old122_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (apply_state_265(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_269(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_280_281_280(rgCache))
    {
        if (apply_state_141(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_286(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_19;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_297(mr,rgCache))
        {
            return true;
        }
    }
    const auto old144_0 = coord;
    coord = direction_down[coord];
    if (apply_state_19(mr,rgCache))
    {
        return true;
    }
    coord = old144_0;
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old90_0;
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        if (apply_state_133(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_137(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = board[coord];
    board[coord] = y;
    if (apply_state_8(mr,rgCache))
    {
        return true;
    }
    board[coord] = old162_0;
    return false;
}

bool GameState::apply_state_269([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old163_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    if (apply_state_271(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old163_0;
    return false;
}

bool GameState::apply_state_271([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old202_0 = goals[red - 2];
    goals[red - 2] = 0;
    if (apply_state_141(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old202_0;
    return false;
}

bool GameState::apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old189_0 = player;
    player = red;
    currentState = 14;
    return true;
    player = old189_0;
    return false;
}

bool GameState::apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old191_0 = player;
    player = keeper;
    currentState = 45;
    return true;
    player = old191_0;
    return false;
}

bool GameState::apply_state_288([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = player;
    player = yellow;
    currentState = 21;
    return true;
    player = old193_0;
    return false;
}

bool GameState::apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old195_0 = player;
    player = keeper;
    currentState = 30;
    return true;
    player = old195_0;
    return false;
}

bool GameState::apply_state_294([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (apply_state_163(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_297([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (apply_state_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_148_155_148_148_155_155_148_155_148())
    {
        if (apply_state_141(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_288(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 1 + coord)
    {
        if (apply_state_12(mr,rgCache))
        {
            return true;
        }
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
                    goals[red - 2] = 50;
                    goals[yellow - 2] = 50;
                    return apply_state_11(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_begin([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_157_157_11([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_any_157_157_141(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_157_157_284(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_157_157_12([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_157_157_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_157_157_14([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_157_157_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 90;
    return true;
    if (apply_any_157_157_end(rgCache))
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_157_157_157([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_157;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_157_157_294(rgCache))
        {
            return true;
        }
    }
    const auto old16_0 = coord;
    coord = direction_down[coord];
    if (apply_any_157_157_157(rgCache))
    {
        return true;
    }
    coord = old16_0;
    return false;
}

bool GameState::apply_any_157_157_163([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (apply_any_157_157_265(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_157_157_269(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_157_157_265([[maybe_unused]]RgCache& rgCache)
{
    const auto old19_0 = board[coord];
    board[coord] = y;
    if (apply_any_157_157_8(rgCache))
    {
        return true;
    }
    board[coord] = old19_0;
    return false;
}

bool GameState::apply_any_157_157_269([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    if (apply_any_157_157_271(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old20_0;
    return false;
}

bool GameState::apply_any_157_157_271([[maybe_unused]]RgCache& rgCache)
{
    const auto old25_0 = goals[red - 2];
    goals[red - 2] = 0;
    if (apply_any_157_157_141(rgCache))
    {
        return true;
    }
    goals[red - 2] = old25_0;
    return false;
}

bool GameState::apply_any_157_157_284([[maybe_unused]]RgCache& rgCache)
{
    const auto old23_0 = player;
    player = red;
    currentState = 14;
    return true;
    if (apply_any_157_157_14(rgCache))
    {
        return true;
    }
    player = old23_0;
    return false;
}

bool GameState::apply_any_157_157_294([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (apply_any_157_157_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_157_157_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_157_157_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_157_157_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_133([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = board[coord];
    board[coord] = r;
    if (apply_any_19_19_32(rgCache))
    {
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::apply_any_19_19_137([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_any_19_19_139(rgCache))
    {
        return true;
    }
    goals[red - 2] = old12_0;
    return false;
}

bool GameState::apply_any_19_19_139([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    if (apply_any_19_19_141(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old13_0;
    return false;
}

bool GameState::apply_any_19_19_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 90;
    return true;
    if (apply_any_19_19_end(rgCache))
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_19_19_152([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_19_19_19([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_19;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_19_19_297(rgCache))
        {
            return true;
        }
    }
    const auto old16_0 = coord;
    coord = direction_down[coord];
    if (apply_any_19_19_19(rgCache))
    {
        return true;
    }
    coord = old16_0;
    return false;
}

bool GameState::apply_any_19_19_25([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        if (apply_any_19_19_133(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_137(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_288([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = player;
    player = yellow;
    currentState = 21;
    return true;
    if (apply_any_19_19_152(rgCache))
    {
        return true;
    }
    player = old20_0;
    return false;
}

bool GameState::apply_any_19_19_297([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord]]!=e)
    {
        if (apply_any_19_19_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_19_19_32([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_148_155_148_148_155_155_148_155_148())
    {
        if (apply_any_19_19_141(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_19_19_288(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_19_19_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_any_begin_begin_141(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_284(rgCache))
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

bool GameState::apply_any_begin_begin_14([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_141([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = player;
    player = keeper;
    currentState = 90;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old11_0;
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    if (apply_any_begin_begin_8(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old9_0;
    return false;
}

bool GameState::apply_any_begin_begin_284([[maybe_unused]]RgCache& rgCache)
{
    const auto old15_0 = player;
    player = red;
    currentState = 14;
    return true;
    if (apply_any_begin_begin_14(rgCache))
    {
        return true;
    }
    player = old15_0;
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
    const auto old13_0 = goals[red - 2];
    goals[red - 2] = 50;
    if (apply_any_begin_begin_2(rgCache))
    {
        return true;
    }
    goals[red - 2] = old13_0;
    return false;
}

bool GameState::apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

}  // namespace reasoner
