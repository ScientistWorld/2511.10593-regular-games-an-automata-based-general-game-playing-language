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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "coord_temp = " << coord_temp << std::endl;
    ss << "counters = " << "{" << "e: " << counters[e] << ", " << "r: " << counters[r] << ", " << "y: " << counters[y] << ", " << "null: " << counters[null]<< "}" << std::endl;
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
        case 2:
{
            state_10(moves, mr.mr,rgCache);
            return;
}
        case 60:
{
            state_148(moves, mr.mr,rgCache);
            return;
}
        case 371:
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
        case 60:
{
            apply_state_148(mr.mr,rgCache);
            return;
}
        case 371:
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
        case 73:
{
            apply_any_154_154_154(rgCache);
            rgCache.reset();
            break;
}
        case 115:
{
            apply_any_16_16_16(rgCache);
            rgCache.reset();
            break;
}
        case 371:
{
            apply_any_begin_begin_begin(rgCache);
            rgCache.reset();
            break;
}
    }
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_10()
{
    if (is_legal_10_17_10_10_17_17_10_17_14())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_13()
{
    if (board[coord]==e)
    {
        if (is_legal_10_17_10_10_17_17_10_17_15())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_14()
{
    const auto old8_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (is_legal_10_17_10_10_17_17_10_17_13())
    {
        coord = old8_0;
        return true;
    }    }
    coord = old8_0;
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_15()
{
    if (is_legal_10_17_10_10_17_17_10_17_18())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_17()
{
    return true;
}

bool GameState::is_legal_10_17_10_10_17_17_10_17_18()
{
    if (is_legal_10_17_10_10_17_17_10_17_17())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_148()
{
    if (is_legal_148_155_148_148_155_155_148_155_152())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_151()
{
    if (board[coord]==e)
    {
        if (is_legal_148_155_148_148_155_155_148_155_153())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_152()
{
    const auto old8_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (is_legal_148_155_148_148_155_155_148_155_151())
    {
        coord = old8_0;
        return true;
    }    }
    coord = old8_0;
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_153()
{
    if (is_legal_148_155_148_148_155_155_148_155_156())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_155()
{
    return true;
}

bool GameState::is_legal_148_155_148_148_155_155_148_155_156()
{
    if (is_legal_148_155_148_148_155_155_148_155_155())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_11([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_12([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_154([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_158(rgCache))
    {
        return true;
    }
    if (is_legal_154_11_154_154_11_11_154_11_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_157([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_154_11_154_154_11_11_154_11_162(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_158([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_157(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_159([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_11_159;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old24_0 = coord;
    coord = direction_down[coord];
    if (is_legal_154_11_154_154_11_11_154_11_161(rgCache))
    {
        coord = old24_0;
        return true;
    }
    coord = old24_0;
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_160([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_158(rgCache))
    {
        return true;
    }
    if (is_legal_154_11_154_154_11_11_154_11_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_11_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_154_11_154_154_11_11_154_11_160(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_162([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (is_legal_154_11_154_154_11_11_154_11_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_163([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (is_legal_154_11_154_154_11_11_154_11_165(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_164([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_165([[maybe_unused]]RgCache& rgCache)
{
    const auto old31_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_154_11_154_154_11_11_154_11_265(rgCache))
    {
        counters[board[coord]] = old31_0;
        return true;
    }
    counters[board[coord]] = old31_0;
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_264([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_265([[maybe_unused]]RgCache& rgCache)
{
    const auto old33_0 = counters[y];
    counters[y] = counters[y]+1;
    if (is_legal_154_11_154_154_11_11_154_11_266(rgCache))
    {
        counters[y] = old33_0;
        return true;
    }
    counters[y] = old33_0;
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_266([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_268(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_267([[maybe_unused]]RgCache& rgCache)
{
    const auto old35_0 = board[coord];
    board[coord] = y;
    if (is_legal_154_11_154_154_11_11_154_11_264(rgCache))
    {
        board[coord] = old35_0;
        return true;
    }
    board[coord] = old35_0;
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_268([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_267(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_8([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_11_154_154_11_11_154_11_9([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_11_154_154_11_11_154_11_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_154([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_158(rgCache))
    {
        return true;
    }
    if (is_legal_154_277_154_154_277_277_154_277_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_157([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_154_277_154_154_277_277_154_277_162(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_158([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_157(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_159([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_277_159;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old21_0 = coord;
    coord = direction_down[coord];
    if (is_legal_154_277_154_154_277_277_154_277_161(rgCache))
    {
        coord = old21_0;
        return true;
    }
    coord = old21_0;
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_160([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_158(rgCache))
    {
        return true;
    }
    if (is_legal_154_277_154_154_277_277_154_277_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_154_277_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_154_277_154_154_277_277_154_277_160(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_162([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (is_legal_154_277_154_154_277_277_154_277_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_163([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_166_167_166())
    {
        if (is_legal_154_277_154_154_277_277_154_277_269(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_269([[maybe_unused]]RgCache& rgCache)
{
    const auto old27_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    if (is_legal_154_277_154_154_277_277_154_277_271(rgCache))
    {
        goals[yellow - 2] = old27_0;
        return true;
    }
    goals[yellow - 2] = old27_0;
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_270([[maybe_unused]]RgCache& rgCache)
{
    const auto old28_0 = goals[red - 2];
    goals[red - 2] = 0;
    if (is_legal_154_277_154_154_277_277_154_277_274(rgCache))
    {
        goals[red - 2] = old28_0;
        return true;
    }
    goals[red - 2] = old28_0;
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_271([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_272(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_272([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_270(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_273([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_278(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_274([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_275(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_275([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_273(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_277([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_154_277_154_154_277_277_154_277_278([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_154_277_154_154_277_277_154_277_277(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_166()
{
    const auto old98_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_166_167_169())
    {
        coord = old98_0;
        return true;
    }
    coord = old98_0;
    const auto old99_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_166_167_182())
    {
        coord = old99_0;
        return true;
    }
    coord = old99_0;
    const auto old100_0 = coord;
    coord = direction_left[coord];
    if (is_legal_166_167_196())
    {
        coord = old100_0;
        return true;
    }
    coord = old100_0;
    const auto old101_0 = coord;
    coord = direction_right[coord];
    if (is_legal_166_167_212())
    {
        coord = old101_0;
        return true;
    }
    coord = old101_0;
    const auto old102_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_166_167_227())
    {
        coord = old102_0;
        return true;
    }
    coord = old102_0;
    const auto old103_0 = coord;
    coord = direction_down[coord];
    if (is_legal_166_167_241())
    {
        coord = old103_0;
        return true;
    }
    coord = old103_0;
    const auto old104_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_166_167_252())
    {
        coord = old104_0;
        return true;
    }
    coord = old104_0;
    return false;
}

bool GameState::is_legal_166_167_167()
{
    return true;
}

bool GameState::is_legal_166_167_168()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_170())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_169()
{
    if (is_legal_166_167_168())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_170()
{
    const auto old107_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_166_167_172())
    {
        coord = old107_0;
        return true;
    }
    coord = old107_0;
    return false;
}

bool GameState::is_legal_166_167_171()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_173())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_172()
{
    if (is_legal_166_167_171())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_173()
{
    const auto old110_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_166_167_176())
    {
        coord = old110_0;
        return true;
    }
    coord = old110_0;
    const auto old111_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_166_167_179())
    {
        coord = old111_0;
        return true;
    }
    coord = old111_0;
    return false;
}

bool GameState::is_legal_166_167_174()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_175()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_177())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_176()
{
    if (is_legal_166_167_175())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_177()
{
    if (is_legal_166_167_174())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_178()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_180())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_179()
{
    if (is_legal_166_167_178())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_180()
{
    if (is_legal_166_167_174())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_181()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_183())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_182()
{
    if (is_legal_166_167_181())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_183()
{
    const auto old121_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_166_167_185())
    {
        coord = old121_0;
        return true;
    }
    coord = old121_0;
    return false;
}

bool GameState::is_legal_166_167_184()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_186())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_185()
{
    if (is_legal_166_167_184())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_186()
{
    const auto old124_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_166_167_189())
    {
        coord = old124_0;
        return true;
    }
    coord = old124_0;
    const auto old125_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_166_167_192())
    {
        coord = old125_0;
        return true;
    }
    coord = old125_0;
    return false;
}

bool GameState::is_legal_166_167_187()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_188()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_190())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_189()
{
    if (is_legal_166_167_188())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_190()
{
    if (is_legal_166_167_187())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_191()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_193())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_192()
{
    if (is_legal_166_167_191())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_193()
{
    if (is_legal_166_167_187())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_194()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_197())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_195()
{
    if (is_legal_166_167_194())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_196()
{
    if (is_legal_166_167_195())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_197()
{
    const auto old136_0 = coord;
    coord = direction_left[coord];
    if (is_legal_166_167_200())
    {
        coord = old136_0;
        return true;
    }
    coord = old136_0;
    return false;
}

bool GameState::is_legal_166_167_198()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_201())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_199()
{
    if (is_legal_166_167_198())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_200()
{
    if (is_legal_166_167_199())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_201()
{
    const auto old140_0 = coord;
    coord = direction_left[coord];
    if (is_legal_166_167_205())
    {
        coord = old140_0;
        return true;
    }
    coord = old140_0;
    const auto old141_0 = coord;
    coord = RbgCoordMap5[coord];
    if (is_legal_166_167_208())
    {
        coord = old141_0;
        return true;
    }
    coord = old141_0;
    return false;
}

bool GameState::is_legal_166_167_202()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_203()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_206())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_204()
{
    if (is_legal_166_167_203())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_205()
{
    if (is_legal_166_167_204())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_206()
{
    if (is_legal_166_167_202())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_207()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_209())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_208()
{
    if (is_legal_166_167_207())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_209()
{
    if (is_legal_166_167_202())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_210()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_213())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_211()
{
    if (is_legal_166_167_210())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_212()
{
    if (is_legal_166_167_211())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_213()
{
    const auto old153_0 = coord;
    coord = direction_right[coord];
    if (is_legal_166_167_216())
    {
        coord = old153_0;
        return true;
    }
    coord = old153_0;
    return false;
}

bool GameState::is_legal_166_167_214()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_217())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_215()
{
    if (is_legal_166_167_214())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_216()
{
    if (is_legal_166_167_215())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_217()
{
    const auto old157_0 = coord;
    coord = direction_right[coord];
    if (is_legal_166_167_221())
    {
        coord = old157_0;
        return true;
    }
    coord = old157_0;
    const auto old158_0 = coord;
    coord = RbgCoordMap6[coord];
    if (is_legal_166_167_224())
    {
        coord = old158_0;
        return true;
    }
    coord = old158_0;
    return false;
}

bool GameState::is_legal_166_167_218()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_219()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_222())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_220()
{
    if (is_legal_166_167_219())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_221()
{
    if (is_legal_166_167_220())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_222()
{
    if (is_legal_166_167_218())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_223()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_225())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_224()
{
    if (is_legal_166_167_223())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_225()
{
    if (is_legal_166_167_218())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_226()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_228())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_227()
{
    if (is_legal_166_167_226())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_228()
{
    const auto old169_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_166_167_230())
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_166_167_229()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_231())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_230()
{
    if (is_legal_166_167_229())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_231()
{
    const auto old172_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_166_167_234())
    {
        coord = old172_0;
        return true;
    }
    coord = old172_0;
    const auto old173_0 = coord;
    coord = RbgCoordMap8[coord];
    if (is_legal_166_167_237())
    {
        coord = old173_0;
        return true;
    }
    coord = old173_0;
    return false;
}

bool GameState::is_legal_166_167_232()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_233()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_235())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_234()
{
    if (is_legal_166_167_233())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_235()
{
    if (is_legal_166_167_232())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_236()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_238())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_237()
{
    if (is_legal_166_167_236())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_238()
{
    if (is_legal_166_167_232())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_239()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_242())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_240()
{
    if (is_legal_166_167_239())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_241()
{
    if (is_legal_166_167_240())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_242()
{
    const auto old184_0 = coord;
    coord = direction_down[coord];
    if (is_legal_166_167_245())
    {
        coord = old184_0;
        return true;
    }
    coord = old184_0;
    return false;
}

bool GameState::is_legal_166_167_243()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_246())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_244()
{
    if (is_legal_166_167_243())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_245()
{
    if (is_legal_166_167_244())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_246()
{
    const auto old188_0 = coord;
    coord = direction_down[coord];
    if (is_legal_166_167_249())
    {
        coord = old188_0;
        return true;
    }
    coord = old188_0;
    return false;
}

bool GameState::is_legal_166_167_247()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_250())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_248()
{
    if (is_legal_166_167_247())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_249()
{
    if (is_legal_166_167_248())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_250()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_251()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_253())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_252()
{
    if (is_legal_166_167_251())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_253()
{
    const auto old195_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_166_167_255())
    {
        coord = old195_0;
        return true;
    }
    coord = old195_0;
    return false;
}

bool GameState::is_legal_166_167_254()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_256())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_255()
{
    if (is_legal_166_167_254())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_256()
{
    const auto old198_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_166_167_259())
    {
        coord = old198_0;
        return true;
    }
    coord = old198_0;
    const auto old199_0 = coord;
    coord = RbgCoordMap10[coord];
    if (is_legal_166_167_262())
    {
        coord = old199_0;
        return true;
    }
    coord = old199_0;
    return false;
}

bool GameState::is_legal_166_167_257()
{
    if (is_legal_166_167_167())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_258()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_260())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_259()
{
    if (is_legal_166_167_258())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_260()
{
    if (is_legal_166_167_257())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_261()
{
    if (board[coord]==y)
    {
        if (is_legal_166_167_263())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_166_167_262()
{
    if (is_legal_166_167_261())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_166_167_263()
{
    if (is_legal_166_167_257())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_137([[maybe_unused]]RgCache& rgCache)
{
    const auto old17_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (is_legal_16_145_16_16_145_145_16_145_139(rgCache))
    {
        goals[red - 2] = old17_0;
        return true;
    }
    goals[red - 2] = old17_0;
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_138([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    if (is_legal_16_145_16_16_145_145_16_145_142(rgCache))
    {
        goals[yellow - 2] = old18_0;
        return true;
    }
    goals[yellow - 2] = old18_0;
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_139([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_140(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_140([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_138(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_141([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_146(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_142([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_143([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_141(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_145([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_146([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_145(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_16([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_20(rgCache))
    {
        return true;
    }
    if (is_legal_16_145_16_16_145_145_16_145_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_19([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_16_145_16_16_145_145_16_145_24(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_19(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_21([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_145_21;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old29_0 = coord;
    coord = direction_down[coord];
    if (is_legal_16_145_16_16_145_145_16_145_23(rgCache))
    {
        coord = old29_0;
        return true;
    }
    coord = old29_0;
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_145_16_16_145_145_16_145_20(rgCache))
    {
        return true;
    }
    if (is_legal_16_145_16_16_145_145_16_145_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_23([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_145_23;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_16_145_16_16_145_145_16_145_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_24([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (is_legal_16_145_16_16_145_145_16_145_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_145_16_16_145_145_16_145_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_34_35_34())
    {
        if (is_legal_16_145_16_16_145_145_16_145_137(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_132([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_32(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_133([[maybe_unused]]RgCache& rgCache)
{
    const auto old18_0 = counters[r];
    counters[r] = counters[r]+1;
    if (is_legal_16_149_16_16_149_149_16_149_134(rgCache))
    {
        counters[r] = old18_0;
        return true;
    }
    counters[r] = old18_0;
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_134([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_136(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_135([[maybe_unused]]RgCache& rgCache)
{
    const auto old20_0 = board[coord];
    board[coord] = r;
    if (is_legal_16_149_16_16_149_149_16_149_132(rgCache))
    {
        board[coord] = old20_0;
        return true;
    }
    board[coord] = old20_0;
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_136([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_135(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_149([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_150([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_149(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_16([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_20(rgCache))
    {
        return true;
    }
    if (is_legal_16_149_16_16_149_149_16_149_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_19([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_16_149_16_16_149_149_16_149_24(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_20([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_19(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_21([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_149_21;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old27_0 = coord;
    coord = direction_down[coord];
    if (is_legal_16_149_16_16_149_149_16_149_23(rgCache))
    {
        coord = old27_0;
        return true;
    }
    coord = old27_0;
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_22([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_20(rgCache))
    {
        return true;
    }
    if (is_legal_16_149_16_16_149_149_16_149_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_23([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_16_149_23;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (is_legal_16_149_16_16_149_149_16_149_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_24([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (is_legal_16_149_16_16_149_149_16_149_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_25([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_34_35_34())
    {
        if (is_legal_16_149_16_16_149_149_16_149_33(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_32([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_16_149_16_16_149_149_16_149_150(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_16_149_16_16_149_149_16_149_33([[maybe_unused]]RgCache& rgCache)
{
    const auto old34_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (is_legal_16_149_16_16_149_149_16_149_133(rgCache))
    {
        counters[board[coord]] = old34_0;
        return true;
    }
    counters[board[coord]] = old34_0;
    return false;
}

bool GameState::is_legal_26_27_26()
{
    const auto old6_0 = coord;
    coord = direction_down[coord];
    if (is_legal_26_27_30())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_26_27_27()
{
    return true;
}

bool GameState::is_legal_26_27_28()
{
    if (board[coord]==e)
    {
        if (is_legal_26_27_31())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_26_27_29()
{
    if (is_legal_26_27_28())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_27_30()
{
    if (is_legal_26_27_29())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_26_27_31()
{
    if (is_legal_26_27_27())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_280_281_280([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_16_145_21.reset();
    rgCache.state_cache_16_145_23.reset();
    const auto result_2 = is_legal_16_145_16_16_145_145_16_145_16(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_280_281_281(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_16_149_21.reset();
    rgCache.state_cache_16_149_23.reset();
    const auto result_3 = is_legal_16_149_16_16_149_149_16_149_16(rgCache);
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
    rgCache.state_cache_154_11_159.reset();
    rgCache.state_cache_154_11_161.reset();
    const auto result_2 = is_legal_154_11_154_154_11_11_154_11_154(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_282_283_283(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_154_277_159.reset();
    rgCache.state_cache_154_277_161.reset();
    const auto result_3 = is_legal_154_277_154_154_277_277_154_277_154(rgCache);
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

bool GameState::is_legal_34_35_100()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_101()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_103())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_102()
{
    if (is_legal_34_35_101())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_103()
{
    if (is_legal_34_35_100())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_104()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_106())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_105()
{
    if (is_legal_34_35_104())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_106()
{
    if (is_legal_34_35_100())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_107()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_110())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_108()
{
    if (is_legal_34_35_107())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_109()
{
    if (is_legal_34_35_108())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_110()
{
    const auto old108_0 = coord;
    coord = direction_down[coord];
    if (is_legal_34_35_113())
    {
        coord = old108_0;
        return true;
    }
    coord = old108_0;
    return false;
}

bool GameState::is_legal_34_35_111()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_114())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_112()
{
    if (is_legal_34_35_111())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_113()
{
    if (is_legal_34_35_112())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_114()
{
    const auto old112_0 = coord;
    coord = direction_down[coord];
    if (is_legal_34_35_117())
    {
        coord = old112_0;
        return true;
    }
    coord = old112_0;
    return false;
}

bool GameState::is_legal_34_35_115()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_118())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_116()
{
    if (is_legal_34_35_115())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_117()
{
    if (is_legal_34_35_116())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_118()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_119()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_121())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_120()
{
    if (is_legal_34_35_119())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_121()
{
    const auto old119_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_34_35_123())
    {
        coord = old119_0;
        return true;
    }
    coord = old119_0;
    return false;
}

bool GameState::is_legal_34_35_122()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_124())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_123()
{
    if (is_legal_34_35_122())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_124()
{
    const auto old122_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_34_35_127())
    {
        coord = old122_0;
        return true;
    }
    coord = old122_0;
    const auto old123_0 = coord;
    coord = RbgCoordMap10[coord];
    if (is_legal_34_35_130())
    {
        coord = old123_0;
        return true;
    }
    coord = old123_0;
    return false;
}

bool GameState::is_legal_34_35_125()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_126()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_128())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_127()
{
    if (is_legal_34_35_126())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_128()
{
    if (is_legal_34_35_125())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_129()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_131())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_130()
{
    if (is_legal_34_35_129())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_131()
{
    if (is_legal_34_35_125())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_34()
{
    const auto old131_0 = coord;
    coord = direction_down[coord];
    if (is_legal_34_35_109())
    {
        coord = old131_0;
        return true;
    }
    coord = old131_0;
    const auto old132_0 = coord;
    coord = RbgCoordMap9[coord];
    if (is_legal_34_35_120())
    {
        coord = old132_0;
        return true;
    }
    coord = old132_0;
    const auto old133_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_34_35_37())
    {
        coord = old133_0;
        return true;
    }
    coord = old133_0;
    const auto old134_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_34_35_50())
    {
        coord = old134_0;
        return true;
    }
    coord = old134_0;
    const auto old135_0 = coord;
    coord = direction_left[coord];
    if (is_legal_34_35_64())
    {
        coord = old135_0;
        return true;
    }
    coord = old135_0;
    const auto old136_0 = coord;
    coord = direction_right[coord];
    if (is_legal_34_35_80())
    {
        coord = old136_0;
        return true;
    }
    coord = old136_0;
    const auto old137_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_34_35_95())
    {
        coord = old137_0;
        return true;
    }
    coord = old137_0;
    return false;
}

bool GameState::is_legal_34_35_35()
{
    return true;
}

bool GameState::is_legal_34_35_36()
{
    if (board[coord]==r)
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
    const auto old140_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_34_35_40())
    {
        coord = old140_0;
        return true;
    }
    coord = old140_0;
    return false;
}

bool GameState::is_legal_34_35_39()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_41())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_40()
{
    if (is_legal_34_35_39())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_41()
{
    const auto old143_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_34_35_44())
    {
        coord = old143_0;
        return true;
    }
    coord = old143_0;
    const auto old144_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_34_35_47())
    {
        coord = old144_0;
        return true;
    }
    coord = old144_0;
    return false;
}

bool GameState::is_legal_34_35_42()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_43()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_45())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_44()
{
    if (is_legal_34_35_43())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_45()
{
    if (is_legal_34_35_42())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_46()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_48())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_47()
{
    if (is_legal_34_35_46())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_48()
{
    if (is_legal_34_35_42())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_49()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_51())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_50()
{
    if (is_legal_34_35_49())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_51()
{
    const auto old154_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_34_35_53())
    {
        coord = old154_0;
        return true;
    }
    coord = old154_0;
    return false;
}

bool GameState::is_legal_34_35_52()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_54())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_53()
{
    if (is_legal_34_35_52())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_54()
{
    const auto old157_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_34_35_57())
    {
        coord = old157_0;
        return true;
    }
    coord = old157_0;
    const auto old158_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_34_35_60())
    {
        coord = old158_0;
        return true;
    }
    coord = old158_0;
    return false;
}

bool GameState::is_legal_34_35_55()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_56()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_58())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_57()
{
    if (is_legal_34_35_56())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_58()
{
    if (is_legal_34_35_55())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_59()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_61())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_60()
{
    if (is_legal_34_35_59())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_61()
{
    if (is_legal_34_35_55())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_62()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_65())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_63()
{
    if (is_legal_34_35_62())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_64()
{
    if (is_legal_34_35_63())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_65()
{
    const auto old169_0 = coord;
    coord = direction_left[coord];
    if (is_legal_34_35_68())
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_34_35_66()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_69())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_67()
{
    if (is_legal_34_35_66())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_68()
{
    if (is_legal_34_35_67())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_69()
{
    const auto old173_0 = coord;
    coord = direction_left[coord];
    if (is_legal_34_35_73())
    {
        coord = old173_0;
        return true;
    }
    coord = old173_0;
    const auto old174_0 = coord;
    coord = RbgCoordMap5[coord];
    if (is_legal_34_35_76())
    {
        coord = old174_0;
        return true;
    }
    coord = old174_0;
    return false;
}

bool GameState::is_legal_34_35_70()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_71()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_74())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_72()
{
    if (is_legal_34_35_71())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_73()
{
    if (is_legal_34_35_72())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_74()
{
    if (is_legal_34_35_70())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_75()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_77())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_76()
{
    if (is_legal_34_35_75())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_77()
{
    if (is_legal_34_35_70())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_78()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_81())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_79()
{
    if (is_legal_34_35_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_80()
{
    if (is_legal_34_35_79())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_81()
{
    const auto old186_0 = coord;
    coord = direction_right[coord];
    if (is_legal_34_35_84())
    {
        coord = old186_0;
        return true;
    }
    coord = old186_0;
    return false;
}

bool GameState::is_legal_34_35_82()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_85())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_83()
{
    if (is_legal_34_35_82())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_84()
{
    if (is_legal_34_35_83())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_85()
{
    const auto old190_0 = coord;
    coord = direction_right[coord];
    if (is_legal_34_35_89())
    {
        coord = old190_0;
        return true;
    }
    coord = old190_0;
    const auto old191_0 = coord;
    coord = RbgCoordMap6[coord];
    if (is_legal_34_35_92())
    {
        coord = old191_0;
        return true;
    }
    coord = old191_0;
    return false;
}

bool GameState::is_legal_34_35_86()
{
    if (is_legal_34_35_35())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_87()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_90())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_88()
{
    if (is_legal_34_35_87())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_89()
{
    if (is_legal_34_35_88())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_90()
{
    if (is_legal_34_35_86())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_91()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_93())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_92()
{
    if (is_legal_34_35_91())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_93()
{
    if (is_legal_34_35_86())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_94()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_96())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_95()
{
    if (is_legal_34_35_94())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_96()
{
    const auto old202_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_34_35_98())
    {
        coord = old202_0;
        return true;
    }
    coord = old202_0;
    return false;
}

bool GameState::is_legal_34_35_97()
{
    if (board[coord]==r)
    {
        if (is_legal_34_35_99())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_34_35_98()
{
    if (is_legal_34_35_97())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_34_35_99()
{
    const auto old205_0 = coord;
    coord = RbgCoordMap7[coord];
    if (is_legal_34_35_102())
    {
        coord = old205_0;
        return true;
    }
    coord = old205_0;
    const auto old206_0 = coord;
    coord = RbgCoordMap8[coord];
    if (is_legal_34_35_105())
    {
        coord = old206_0;
        return true;
    }
    coord = old206_0;
    return false;
}

void GameState::state_1([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old372_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    state_5(moves, mr,rgCache);
    goals[yellow - 2] = old372_0;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_14(moves, mr,rgCache);
}

void GameState::state_11([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_17_10_10_17_17_10_17_10())
    {
        state_284(moves, mr,rgCache);
        return;
    }
    state_285(moves, mr,rgCache);
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
        state_15(moves, mr,rgCache);
    }
}

void GameState::state_132([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_32(moves, mr,rgCache);
}

void GameState::state_133([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old415_0 = counters[r];
    counters[r] = counters[r]+1;
    state_134(moves, mr,rgCache);
    counters[r] = old415_0;
}

void GameState::state_134([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_136(moves, mr,rgCache);
}

void GameState::state_135([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old417_0 = board[coord];
    board[coord] = r;
    state_132(moves, mr,rgCache);
    board[coord] = old417_0;
}

void GameState::state_136([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_135(moves, mr,rgCache);
}

void GameState::state_137([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old419_0 = goals[red - 2];
    goals[red - 2] = 100;
    state_139(moves, mr,rgCache);
    goals[red - 2] = old419_0;
}

void GameState::state_138([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old420_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    state_142(moves, mr,rgCache);
    goals[yellow - 2] = old420_0;
}

void GameState::state_139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_140(moves, mr,rgCache);
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old422_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    state_13(moves, mr,rgCache);    }
    coord = old422_0;
}

void GameState::state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_138(moves, mr,rgCache);
}

void GameState::state_141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_146(moves, mr,rgCache);
}

void GameState::state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_143(moves, mr,rgCache);
}

void GameState::state_143([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_141(moves, mr,rgCache);
}

void GameState::state_145([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_146([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_145(moves, mr,rgCache);
}

void GameState::state_148([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_152(moves, mr,rgCache);
}

void GameState::state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_148_155_148_148_155_155_148_155_148())
    {
        state_288(moves, mr,rgCache);
        return;
    }
    state_289(moves, mr,rgCache);
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_18(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_149(moves, mr,rgCache);
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
    const auto old439_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    state_151(moves, mr,rgCache);    }
    coord = old439_0;
}

void GameState::state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_156(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_158(moves, mr,rgCache);
    state_159(moves, mr,rgCache);
}

void GameState::state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_282_283_282(rgCache))
    {
        state_290(moves, mr,rgCache);
        return;
    }
    state_291(moves, mr,rgCache);
}

void GameState::state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(44);
    state_155(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_157([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_162(moves, mr,rgCache);
    }
}

void GameState::state_158([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_158;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_157(moves, mr,rgCache);
}

void GameState::state_159([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_159;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old484_0 = coord;
    coord = direction_down[coord];
    state_161(moves, mr,rgCache);
    coord = old484_0;
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_20(moves, mr,rgCache);
    state_21(moves, mr,rgCache);
}

void GameState::state_160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_158(moves, mr,rgCache);
    state_159(moves, mr,rgCache);
}

void GameState::state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_161;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_160(moves, mr,rgCache);
}

void GameState::state_162([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        state_163(moves, mr,rgCache);
    }
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        state_165(moves, mr,rgCache);
        return;
    }
    state_269(moves, mr,rgCache);
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_9(moves, mr,rgCache);
}

void GameState::state_165([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old494_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_265(moves, mr,rgCache);
    counters[board[coord]] = old494_0;
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_280_281_280(rgCache))
    {
        state_286(moves, mr,rgCache);
        return;
    }
    state_287(moves, mr,rgCache);
}

void GameState::state_18([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(45);
    state_17(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_24(moves, mr,rgCache);
    }
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(1 + coord);
    state_3(moves, mr,rgCache);
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
    auto& cache = rgCache.state_cache_21;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old587_0 = coord;
    coord = direction_down[coord];
    state_23(moves, mr,rgCache);
    coord = old587_0;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_20(moves, mr,rgCache);
    state_21(moves, mr,rgCache);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_23;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    state_22(moves, mr,rgCache);
}

void GameState::state_24([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        state_25(moves, mr,rgCache);
    }
}

void GameState::state_25([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_34_35_34())
    {
        state_137(moves, mr,rgCache);
        return;
    }
    state_33(moves, mr,rgCache);
}

void GameState::state_264([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_164(moves, mr,rgCache);
}

void GameState::state_265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old653_0 = counters[y];
    counters[y] = counters[y]+1;
    state_266(moves, mr,rgCache);
    counters[y] = old653_0;
}

void GameState::state_266([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_268(moves, mr,rgCache);
}

void GameState::state_267([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old655_0 = board[coord];
    board[coord] = y;
    state_264(moves, mr,rgCache);
    board[coord] = old655_0;
}

void GameState::state_268([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_267(moves, mr,rgCache);
}

void GameState::state_269([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old657_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    state_271(moves, mr,rgCache);
    goals[yellow - 2] = old657_0;
}

void GameState::state_270([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old658_0 = goals[red - 2];
    goals[red - 2] = 0;
    state_274(moves, mr,rgCache);
    goals[red - 2] = old658_0;
}

void GameState::state_271([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_272(moves, mr,rgCache);
}

void GameState::state_272([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_270(moves, mr,rgCache);
}

void GameState::state_273([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_278(moves, mr,rgCache);
}

void GameState::state_274([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_275(moves, mr,rgCache);
}

void GameState::state_275([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_273(moves, mr,rgCache);
}

void GameState::state_277([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_278([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_277(moves, mr,rgCache);
}

void GameState::state_284([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_285([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_286([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_287([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_288([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_289([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_291([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_3([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr.emplace_back(46);
    state_1(moves, mr,rgCache);
    mr.pop_back();
}

void GameState::state_32([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    state_150(moves, mr,rgCache);
}

void GameState::state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old677_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    state_133(moves, mr,rgCache);
    counters[board[coord]] = old677_0;
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
    mr.emplace_back(47);
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
    const auto old759_0 = goals[red - 2];
    goals[red - 2] = 50;
    state_2(moves, mr,rgCache);
    goals[red - 2] = old759_0;
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old372_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    if (apply_state_5(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old372_0;
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
                    return apply_state_17(mr,rgCache);
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
    if (is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_state_284(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_285(mr,rgCache))
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
        if (apply_state_15(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_132([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_32(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_133([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old415_0 = counters[r];
    counters[r] = counters[r]+1;
    if (apply_state_134(mr,rgCache))
    {
        return true;
    }
    counters[r] = old415_0;
    return false;
}

bool GameState::apply_state_134([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_136(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_135([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old417_0 = board[coord];
    board[coord] = r;
    if (apply_state_132(mr,rgCache))
    {
        return true;
    }
    board[coord] = old417_0;
    return false;
}

bool GameState::apply_state_136([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_135(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_137([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old419_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_state_139(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old419_0;
    return false;
}

bool GameState::apply_state_138([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old420_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    if (apply_state_142(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old420_0;
    return false;
}

bool GameState::apply_state_139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_140(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old422_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (apply_state_13(mr,rgCache))
    {
        return true;
    }    }
    coord = old422_0;
    return false;
}

bool GameState::apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_138(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_146(mr,rgCache))
    {
        return true;
    }
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

bool GameState::apply_state_145([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old427_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old427_0;
    return false;
}

bool GameState::apply_state_146([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_145(mr,rgCache))
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
                    coord = mr[rgCache.currentMrId - 2] - 1;
                    return apply_state_155(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_148([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_148_155_148_148_155_155_148_155_148())
    {
        if (apply_state_288(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_289(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_18(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_150([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_149(mr,rgCache))
    {
        return true;
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

bool GameState::apply_state_152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old439_0 = coord;
    for (const auto& coordIt : {rx0y0,rx1y0,rx2y0,rx3y0,rx4y0,rx5y0,rx6y0})
    {
    coord = coordIt;
    if (apply_state_151(mr,rgCache))
    {
        return true;
    }    }
    coord = old439_0;
    return false;
}

bool GameState::apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 1 + coord)
    {
        rgCache.currentMrId++;
        if (apply_state_156(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_158(mr,rgCache))
    {
        return true;
    }
    if (apply_state_159(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_282_283_282(rgCache))
    {
        if (apply_state_290(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_291(mr,rgCache))
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
            case 44:
{
                return apply_state_155(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_3(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 44)
    {
        rgCache.currentMrId++;
        if (apply_state_155(mr,rgCache))
        {
            return true;
        }
        rgCache.currentMrId--;
    }
    return false;
}

bool GameState::apply_state_157([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_162(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_158([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_158;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_157(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_159([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_159;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old484_0 = coord;
    coord = direction_down[coord];
    if (apply_state_161(mr,rgCache))
    {
        return true;
    }
    coord = old484_0;
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }
    if (apply_state_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_158(mr,rgCache))
    {
        return true;
    }
    if (apply_state_159(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_161([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_160(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_162([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (apply_state_163(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (apply_state_165(mr,rgCache))
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
    const auto old494_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_265(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old494_0;
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_280_281_280(rgCache))
    {
        if (apply_state_286(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_287(mr,rgCache))
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
            case 45:
{
                return apply_state_17(mr,rgCache);
}
        }
    }
    rgCache.currentMrId = tmpcurrentMrId;
    return false;
}

bool GameState::apply_state_18([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_4(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 45)
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

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_24(mr,rgCache))
        {
            return true;
        }
    }
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
    auto& cache = rgCache.state_cache_21;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old587_0 = coord;
    coord = direction_down[coord];
    if (apply_state_23(mr,rgCache))
    {
        return true;
    }
    coord = old587_0;
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }
    if (apply_state_21(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_23;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_24([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (apply_state_25(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_25([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_34_35_34())
    {
        if (apply_state_137(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_33(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_264([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_164(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old653_0 = counters[y];
    counters[y] = counters[y]+1;
    if (apply_state_266(mr,rgCache))
    {
        return true;
    }
    counters[y] = old653_0;
    return false;
}

bool GameState::apply_state_266([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_268(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_267([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old655_0 = board[coord];
    board[coord] = y;
    if (apply_state_264(mr,rgCache))
    {
        return true;
    }
    board[coord] = old655_0;
    return false;
}

bool GameState::apply_state_268([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_267(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_269([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old657_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    if (apply_state_271(mr,rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old657_0;
    return false;
}

bool GameState::apply_state_270([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old658_0 = goals[red - 2];
    goals[red - 2] = 0;
    if (apply_state_274(mr,rgCache))
    {
        return true;
    }
    goals[red - 2] = old658_0;
    return false;
}

bool GameState::apply_state_271([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_272(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_272([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_270(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_273([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_278(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_274([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_275(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_275([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_273(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_277([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old664_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old664_0;
    return false;
}

bool GameState::apply_state_278([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_277(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_284([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old761_0 = player;
    player = red;
    currentState = 2;
    return true;
    player = old761_0;
    return false;
}

bool GameState::apply_state_285([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old763_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old763_0;
    return false;
}

bool GameState::apply_state_286([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old765_0 = player;
    player = keeper;
    currentState = 115;
    return true;
    player = old765_0;
    return false;
}

bool GameState::apply_state_287([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old767_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old767_0;
    return false;
}

bool GameState::apply_state_288([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old769_0 = player;
    player = yellow;
    currentState = 60;
    return true;
    player = old769_0;
    return false;
}

bool GameState::apply_state_289([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old771_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old771_0;
    return false;
}

bool GameState::apply_state_290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old773_0 = player;
    player = keeper;
    currentState = 73;
    return true;
    player = old773_0;
    return false;
}

bool GameState::apply_state_291([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old775_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    player = old775_0;
    return false;
}

bool GameState::switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 46:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 43:
{
                            if (mr.size() >rgCache.currentMrId)
                            {
                                switch (mr[rgCache.currentMrId++])
                                {
                                    case 47:
{
                                        if (mr.size() >rgCache.currentMrId)
                                        {
                                            switch (mr[rgCache.currentMrId++])
                                            {
                                                case 1 ... 43:
{
                                                    if (mr.size() >rgCache.currentMrId)
                                                    {
                                                        switch (mr[rgCache.currentMrId++])
                                                        {
                                                            case 0:
{
                                                                goals[yellow - 2] = 50;
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
    if (switch_5(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 46)
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

bool GameState::apply_state_32([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (apply_state_150(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old677_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_state_133(mr,rgCache))
    {
        return true;
    }
    counters[board[coord]] = old677_0;
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

bool GameState::switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const uint tmpcurrentMrId = rgCache.currentMrId;
    if (mr.size()>rgCache.currentMrId)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 47:
{
                if (mr.size() >rgCache.currentMrId)
                {
                    switch (mr[rgCache.currentMrId++])
                    {
                        case 1 ... 43:
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
    if (switch_6(mr ,rgCache))
    {
        return true;
    }
    if (mr.size() > rgCache.currentMrId && mr[rgCache.currentMrId] == 47)
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

bool GameState::switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
                                                    goals[red - 2] = 50;
                                                    goals[yellow - 2] = 50;
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
    return switch_7(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_154_154_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_154_154_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_any_154_154_284(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_154_154_285(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_12([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_11(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_154([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_158(rgCache))
    {
        return true;
    }
    if (apply_any_154_154_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_157([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_any_154_154_162(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_154_154_158([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_158;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_154_154_157(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_159([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_159;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old37_0 = coord;
    coord = direction_down[coord];
    if (apply_any_154_154_161(rgCache))
    {
        return true;
    }
    coord = old37_0;
    return false;
}

bool GameState::apply_any_154_154_160([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_158(rgCache))
    {
        return true;
    }
    if (apply_any_154_154_159(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_154_154_160(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_162([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (apply_any_154_154_163(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_154_154_163([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_166_167_166())
    {
        if (apply_any_154_154_165(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_154_154_269(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_164([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_9(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_165([[maybe_unused]]RgCache& rgCache)
{
    const auto old45_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_154_154_265(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old45_0;
    return false;
}

bool GameState::apply_any_154_154_264([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_164(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_265([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = counters[y];
    counters[y] = counters[y]+1;
    if (apply_any_154_154_266(rgCache))
    {
        return true;
    }
    counters[y] = old47_0;
    return false;
}

bool GameState::apply_any_154_154_266([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_268(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_267([[maybe_unused]]RgCache& rgCache)
{
    const auto old49_0 = board[coord];
    board[coord] = y;
    if (apply_any_154_154_264(rgCache))
    {
        return true;
    }
    board[coord] = old49_0;
    return false;
}

bool GameState::apply_any_154_154_268([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_267(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_269([[maybe_unused]]RgCache& rgCache)
{
    const auto old51_0 = goals[yellow - 2];
    goals[yellow - 2] = 100;
    if (apply_any_154_154_271(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old51_0;
    return false;
}

bool GameState::apply_any_154_154_270([[maybe_unused]]RgCache& rgCache)
{
    const auto old52_0 = goals[red - 2];
    goals[red - 2] = 0;
    if (apply_any_154_154_274(rgCache))
    {
        return true;
    }
    goals[red - 2] = old52_0;
    return false;
}

bool GameState::apply_any_154_154_271([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_272(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_272([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_270(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_273([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_278(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_274([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_275(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_275([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_273(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_277([[maybe_unused]]RgCache& rgCache)
{
    const auto old58_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    if (apply_any_154_154_end(rgCache))
    {
        return true;
    }
    player = old58_0;
    return false;
}

bool GameState::apply_any_154_154_278([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_277(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_284([[maybe_unused]]RgCache& rgCache)
{
    const auto old63_0 = player;
    player = red;
    currentState = 2;
    return true;
    if (apply_any_154_154_10(rgCache))
    {
        return true;
    }
    player = old63_0;
    return false;
}

bool GameState::apply_any_154_154_285([[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    if (apply_any_154_154_end(rgCache))
    {
        return true;
    }
    player = old65_0;
    return false;
}

bool GameState::apply_any_154_154_8([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_12(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_9([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_154_154_8(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_154_154_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_16_16_132([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_32(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_133([[maybe_unused]]RgCache& rgCache)
{
    const auto old31_0 = counters[r];
    counters[r] = counters[r]+1;
    if (apply_any_16_16_134(rgCache))
    {
        return true;
    }
    counters[r] = old31_0;
    return false;
}

bool GameState::apply_any_16_16_134([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_136(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_135([[maybe_unused]]RgCache& rgCache)
{
    const auto old33_0 = board[coord];
    board[coord] = r;
    if (apply_any_16_16_132(rgCache))
    {
        return true;
    }
    board[coord] = old33_0;
    return false;
}

bool GameState::apply_any_16_16_136([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_135(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_137([[maybe_unused]]RgCache& rgCache)
{
    const auto old35_0 = goals[red - 2];
    goals[red - 2] = 100;
    if (apply_any_16_16_139(rgCache))
    {
        return true;
    }
    goals[red - 2] = old35_0;
    return false;
}

bool GameState::apply_any_16_16_138([[maybe_unused]]RgCache& rgCache)
{
    const auto old36_0 = goals[yellow - 2];
    goals[yellow - 2] = 0;
    if (apply_any_16_16_142(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old36_0;
    return false;
}

bool GameState::apply_any_16_16_139([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_140(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_140([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_138(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_141([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_146(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_142([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_143(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_143([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_141(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_145([[maybe_unused]]RgCache& rgCache)
{
    const auto old42_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    if (apply_any_16_16_end(rgCache))
    {
        return true;
    }
    player = old42_0;
    return false;
}

bool GameState::apply_any_16_16_146([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_145(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_148([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_16_16_149([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_148_155_148_148_155_155_148_155_148())
    {
        if (apply_any_16_16_288(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_16_16_289(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_150([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_149(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_16([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_20(rgCache))
    {
        return true;
    }
    if (apply_any_16_16_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_19([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_any_16_16_24(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_16_16_20([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_20;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_16_16_19(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_21([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_21;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old49_0 = coord;
    coord = direction_down[coord];
    if (apply_any_16_16_23(rgCache))
    {
        return true;
    }
    coord = old49_0;
    return false;
}

bool GameState::apply_any_16_16_22([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_20(rgCache))
    {
        return true;
    }
    if (apply_any_16_16_21(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_23([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_23;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_16_16_22(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_24([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_26_27_26())
    {
        if (apply_any_16_16_25(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_16_16_25([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_34_35_34())
    {
        if (apply_any_16_16_137(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_16_16_33(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_288([[maybe_unused]]RgCache& rgCache)
{
    const auto old59_0 = player;
    player = yellow;
    currentState = 60;
    return true;
    if (apply_any_16_16_148(rgCache))
    {
        return true;
    }
    player = old59_0;
    return false;
}

bool GameState::apply_any_16_16_289([[maybe_unused]]RgCache& rgCache)
{
    const auto old61_0 = player;
    player = keeper;
    currentState = 372;
    return true;
    if (apply_any_16_16_end(rgCache))
    {
        return true;
    }
    player = old61_0;
    return false;
}

bool GameState::apply_any_16_16_32([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_16_16_150(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_16_16_33([[maybe_unused]]RgCache& rgCache)
{
    const auto old57_0 = counters[board[coord]];
    counters[board[coord]] = counters[board[coord]]-1;
    if (apply_any_16_16_133(rgCache))
    {
        return true;
    }
    counters[board[coord]] = old57_0;
    return false;
}

bool GameState::apply_any_16_16_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_1([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = goals[yellow - 2];
    goals[yellow - 2] = 50;
    if (apply_any_begin_begin_5(rgCache))
    {
        return true;
    }
    goals[yellow - 2] = old14_0;
    return false;
}

bool GameState::apply_any_begin_begin_10([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_11([[maybe_unused]]RgCache& rgCache)
{
    if (is_legal_10_17_10_10_17_17_10_17_10())
    {
        if (apply_any_begin_begin_284(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_285(rgCache))
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

bool GameState::apply_any_begin_begin_284([[maybe_unused]]RgCache& rgCache)
{
    const auto old24_0 = player;
    player = red;
    currentState = 2;
    return true;
    if (apply_any_begin_begin_10(rgCache))
    {
        return true;
    }
    player = old24_0;
    return false;
}

bool GameState::apply_any_begin_begin_285([[maybe_unused]]RgCache& rgCache)
{
    const auto old26_0 = player;
    player = keeper;
    currentState = 372;
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
    const auto old22_0 = goals[red - 2];
    goals[red - 2] = 50;
    if (apply_any_begin_begin_2(rgCache))
    {
        return true;
    }
    goals[red - 2] = old22_0;
    return false;
}

bool GameState::apply_any_begin_begin_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

}  // namespace reasoner
