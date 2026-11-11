#include "reasoner.hpp"

#include <sstream>

namespace reasoner {
size_t GameState::Hasher::operator()(const std::tuple<GameState, uint>& state) const noexcept
{
const auto& [gameState, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.counters) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible);
}

size_t GameState::Hasher::operator()(const std::tuple<GameState, move_representation, uint>& state) const noexcept
{
const auto& [gameState, move, nodeId] = state;
return hash(nodeId) ^ hash(gameState.board) ^ hash(gameState.coord) ^ hash(gameState.counters) ^ hash(gameState.goals) ^ hash(gameState.player) ^ hash(gameState.visible) ^ hash(move);
}

bool GameState::operator==(const GameState& rhs) const
{
return board==rhs.board && coord==rhs.coord && counters==rhs.counters && goals==rhs.goals && player==rhs.player && visible==rhs.visible;
}




std::string GameState::getStateDescription()const
{
    std::stringstream ss;
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx7y0: " << board[rx7y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx7y1: " << board[rx7y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx7y2: " << board[rx7y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx0y7: " << board[rx0y7] << ", " << "rx1y7: " << board[rx1y7] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx7y7: " << board[rx7y7]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "counters = " << "{" << "b: " << counters[b] << ", " << "e: " << counters[e] << ", " << "w: " << counters[w]<< "}" << std::endl;
    ss << "goals = " << "{" << "black: " << goals[black-2] << ", " << "white: " << goals[white-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "black: " << visible[black-2] << ", " << "white: " << visible[white-2]<< "}" << std::endl;
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
        case 640:
{
            state_4(moves, mr.mr,rgCache);
            return;
}
        case 808:
{
            state_793(moves, mr.mr,rgCache);
            return;
}
        case 1155:
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
        case 640:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 808:
{
            apply_state_793(mr.mr,rgCache);
            return;
}
        case 1155:
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
        case 102:
{
            apply_any_121_121_121(rgCache);
            rgCache.reset();
            break;
}
        case 503:
{
            apply_any_1559_1559_1559(rgCache);
            rgCache.reset();
            break;
}
        case 777:
{
            apply_any_7_7_7(rgCache);
            rgCache.reset();
            break;
}
        case 802:
{
            apply_any_770_770_770(rgCache);
            rgCache.reset();
            break;
}
        case 811:
{
            apply_any_796_796_796(rgCache);
            rgCache.reset();
            break;
}
        case 864:
{
            apply_any_910_910_910(rgCache);
            rgCache.reset();
            break;
}
        case 1155:
{
            apply_any_begin_begin_begin(rgCache);
            rgCache.reset();
            break;
}
    }
}

bool GameState::is_legal_1017_1018_1017([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_1017_1018_1019(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1017_1018_1018([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1017_1018_1019([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_1017_1018_1021(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1017_1018_1021([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_1017_1018_1023(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1017_1018_1023([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1023;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1017_1018_1024(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1017_1018_1024([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1017_1018_1018(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1017_1018_1027(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1017_1018_1027([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_1017_1018_1023(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_1064_1065_1064([[maybe_unused]]RgCache& rgCache)
{
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_1064_1065_1066(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1064_1065_1065([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1064_1065_1066([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_1064_1065_1069(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1064_1065_1069([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_1064_1065_1072(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1064_1065_1072([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1072;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1064_1065_1073(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1064_1065_1073([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1064_1065_1065(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1064_1065_1076(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1064_1065_1076([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_1064_1065_1072(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_11_12_100([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_100;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_101(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_101([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_11_12_104(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_104([[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_11_12_100(rgCache))
    {
        coord = old90_0;
        return true;
    }
    coord = old90_0;
    return false;
}

bool GameState::is_legal_11_12_109([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_11_12_111(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_11([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_11_12_109(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_11_12_13(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_11_12_25(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_11_12_40(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_11_12_52(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_11_12_67(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_11_12_82(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_11_12_94(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_111([[maybe_unused]]RgCache& rgCache)
{
    const auto old47_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_11_12_113(rgCache))
    {
        coord = old47_0;
        return true;
    }
    coord = old47_0;
    return false;
}

bool GameState::is_legal_11_12_113([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_113;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_114(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_114([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_11_12_117(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_117([[maybe_unused]]RgCache& rgCache)
{
    const auto old91_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_11_12_113(rgCache))
    {
        coord = old91_0;
        return true;
    }
    coord = old91_0;
    return false;
}

bool GameState::is_legal_11_12_12([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_11_12_13([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_11_12_15(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_15([[maybe_unused]]RgCache& rgCache)
{
    const auto old53_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_11_12_17(rgCache))
    {
        coord = old53_0;
        return true;
    }
    coord = old53_0;
    return false;
}

bool GameState::is_legal_11_12_17([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_18(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_18([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_21(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_21([[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_11_12_17(rgCache))
    {
        coord = old92_0;
        return true;
    }
    coord = old92_0;
    return false;
}

bool GameState::is_legal_11_12_25([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_11_12_28(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_28([[maybe_unused]]RgCache& rgCache)
{
    const auto old59_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_11_12_31(rgCache))
    {
        coord = old59_0;
        return true;
    }
    coord = old59_0;
    return false;
}

bool GameState::is_legal_11_12_31([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_31;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_32(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_32([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_35(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_35([[maybe_unused]]RgCache& rgCache)
{
    const auto old93_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_11_12_31(rgCache))
    {
        coord = old93_0;
        return true;
    }
    coord = old93_0;
    return false;
}

bool GameState::is_legal_11_12_40([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_11_12_42(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_42([[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_11_12_44(rgCache))
    {
        coord = old65_0;
        return true;
    }
    coord = old65_0;
    return false;
}

bool GameState::is_legal_11_12_44([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_44;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_45(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_45([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_48(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_48([[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_11_12_44(rgCache))
    {
        coord = old94_0;
        return true;
    }
    coord = old94_0;
    return false;
}

bool GameState::is_legal_11_12_52([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_11_12_55(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_55([[maybe_unused]]RgCache& rgCache)
{
    const auto old71_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_11_12_58(rgCache))
    {
        coord = old71_0;
        return true;
    }
    coord = old71_0;
    return false;
}

bool GameState::is_legal_11_12_58([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_58;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_59(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_59([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_62(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_62([[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_11_12_58(rgCache))
    {
        coord = old95_0;
        return true;
    }
    coord = old95_0;
    return false;
}

bool GameState::is_legal_11_12_67([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_11_12_70(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_70([[maybe_unused]]RgCache& rgCache)
{
    const auto old77_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_11_12_73(rgCache))
    {
        coord = old77_0;
        return true;
    }
    coord = old77_0;
    return false;
}

bool GameState::is_legal_11_12_73([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_73;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_74(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_74([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_77(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_77([[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_11_12_73(rgCache))
    {
        coord = old96_0;
        return true;
    }
    coord = old96_0;
    return false;
}

bool GameState::is_legal_11_12_82([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_11_12_84(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_84([[maybe_unused]]RgCache& rgCache)
{
    const auto old83_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_11_12_86(rgCache))
    {
        coord = old83_0;
        return true;
    }
    coord = old83_0;
    return false;
}

bool GameState::is_legal_11_12_86([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_86;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_11_12_87(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_87([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_11_12_12(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_11_12_90(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_11_12_90([[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_11_12_86(rgCache))
    {
        coord = old97_0;
        return true;
    }
    coord = old97_0;
    return false;
}

bool GameState::is_legal_11_12_94([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_11_12_97(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_11_12_97([[maybe_unused]]RgCache& rgCache)
{
    const auto old89_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_11_12_100(rgCache))
    {
        coord = old89_0;
        return true;
    }
    coord = old89_0;
    return false;
}

bool GameState::is_legal_1119_1120_1119([[maybe_unused]]RgCache& rgCache)
{
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_1119_1120_1121(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1119_1120_1120([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1119_1120_1121([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_1119_1120_1124(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1119_1120_1124([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_1119_1120_1127(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1119_1120_1127([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1127;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1119_1120_1128(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1119_1120_1128([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1119_1120_1120(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1119_1120_1131(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1119_1120_1131([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_1119_1120_1127(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_1174_1175_1174([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_1174_1175_1176(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1174_1175_1175([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1174_1175_1176([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_1174_1175_1178(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1174_1175_1178([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_1174_1175_1180(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1174_1175_1180([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1180;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1174_1175_1181(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1174_1175_1181([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1174_1175_1175(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1174_1175_1184(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1174_1175_1184([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_1174_1175_1180(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_121([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_132.reset();
    const auto result_123 = is_legal_126_127_126(rgCache);
    rgCache.decDepth();
    if (!result_123)
    {
        if (is_legal_121_771_121_121_771_771_121_771_124(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_140(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_124([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_181.reset();
    const auto result_124 = is_legal_173_174_173(rgCache);
    rgCache.decDepth();
    if (!result_124)
    {
        if (is_legal_121_771_121_121_771_771_121_771_171(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_140([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_142(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_142([[maybe_unused]]RgCache& rgCache)
{
    const auto old127_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_144(rgCache))
    {
        counters[static_cast<Piece>(w)] = old127_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old127_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_143([[maybe_unused]]RgCache& rgCache)
{
    const auto old128_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_121_771_121_121_771_771_121_771_149(rgCache))
    {
        coord = old128_0;
        return true;
    }
    coord = old128_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_144([[maybe_unused]]RgCache& rgCache)
{
    const auto old129_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_145(rgCache))
    {
        counters[b] = old129_0;
        return true;
    }
    counters[b] = old129_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_145([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_143(rgCache))
    {
        board[RbgCoordMap1[coord]] = old130_0;
        return true;
    }
    board[RbgCoordMap1[coord]] = old130_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_149([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_149;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_150([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_153(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_153([[maybe_unused]]RgCache& rgCache)
{
    const auto old134_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_155(rgCache))
    {
        counters[static_cast<Piece>(w)] = old134_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old134_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_154([[maybe_unused]]RgCache& rgCache)
{
    const auto old253_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_121_771_121_121_771_771_121_771_149(rgCache))
    {
        coord = old253_0;
        return true;
    }
    coord = old253_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_155([[maybe_unused]]RgCache& rgCache)
{
    const auto old135_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_156(rgCache))
    {
        counters[b] = old135_0;
        return true;
    }
    counters[b] = old135_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old136_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_154(rgCache))
    {
        board[coord] = old136_0;
        return true;
    }
    board[coord] = old136_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old137_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_121_771_121_121_771_771_121_771_163(rgCache))
    {
        coord = old137_0;
        return true;
    }
    coord = old137_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_124(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_171([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_234.reset();
    const auto result_140 = is_legal_228_229_228(rgCache);
    rgCache.decDepth();
    if (!result_140)
    {
        if (is_legal_121_771_121_121_771_771_121_771_226(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_242(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_190([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_193(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_193([[maybe_unused]]RgCache& rgCache)
{
    const auto old143_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_195(rgCache))
    {
        counters[static_cast<Piece>(w)] = old143_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old143_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_194([[maybe_unused]]RgCache& rgCache)
{
    const auto old144_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_201(rgCache))
    {
        coord = old144_0;
        return true;
    }
    coord = old144_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_195([[maybe_unused]]RgCache& rgCache)
{
    const auto old145_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_196(rgCache))
    {
        counters[b] = old145_0;
        return true;
    }
    counters[b] = old145_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_196([[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_194(rgCache))
    {
        board[direction_up[coord - 1]] = old146_0;
        return true;
    }
    board[direction_up[coord - 1]] = old146_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_202(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_205(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_205([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_205;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old150_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_207(rgCache))
    {
        counters[static_cast<Piece>(w)] = old150_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old150_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_206([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_206;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old254_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_201(rgCache))
    {
        coord = old254_0;
        return true;
    }
    coord = old254_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_207([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_207;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old151_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_208(rgCache))
    {
        counters[b] = old151_0;
        return true;
    }
    counters[b] = old151_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_208([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_208;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old152_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_206(rgCache))
    {
        board[coord] = old152_0;
        return true;
    }
    board[coord] = old152_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_214([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_214;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old153_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_217(rgCache))
    {
        coord = old153_0;
        return true;
    }
    coord = old153_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_217([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_217;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_218(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_218([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_218;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_171(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_226([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_283.reset();
    const auto result_156 = is_legal_275_276_275(rgCache);
    rgCache.decDepth();
    if (!result_156)
    {
        if (is_legal_121_771_121_121_771_771_121_771_273(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_242([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_244(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_244([[maybe_unused]]RgCache& rgCache)
{
    const auto old159_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_246(rgCache))
    {
        counters[static_cast<Piece>(w)] = old159_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old159_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_245([[maybe_unused]]RgCache& rgCache)
{
    const auto old160_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_121_771_121_121_771_771_121_771_251(rgCache))
    {
        coord = old160_0;
        return true;
    }
    coord = old160_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_246([[maybe_unused]]RgCache& rgCache)
{
    const auto old161_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_247(rgCache))
    {
        counters[b] = old161_0;
        return true;
    }
    counters[b] = old161_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_247([[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_245(rgCache))
    {
        board[RbgCoordMap2[coord]] = old162_0;
        return true;
    }
    board[RbgCoordMap2[coord]] = old162_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_251([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_251;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_252(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_252([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_252;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_255(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old166_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_257(rgCache))
    {
        counters[static_cast<Piece>(w)] = old166_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old166_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old255_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_121_771_121_121_771_771_121_771_251(rgCache))
    {
        coord = old255_0;
        return true;
    }
    coord = old255_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_257([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old167_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_258(rgCache))
    {
        counters[b] = old167_0;
        return true;
    }
    counters[b] = old167_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_258([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_258;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old168_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_256(rgCache))
    {
        board[coord] = old168_0;
        return true;
    }
    board[coord] = old168_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_263([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_263;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_121_771_121_121_771_771_121_771_265(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_226(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_273([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_338.reset();
    const auto result_172 = is_legal_330_331_330(rgCache);
    rgCache.decDepth();
    if (!result_172)
    {
        if (is_legal_121_771_121_121_771_771_121_771_328(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_347(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_292([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_295(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_295([[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_297(rgCache))
    {
        counters[static_cast<Piece>(w)] = old175_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old175_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_296([[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_303(rgCache))
    {
        coord = old176_0;
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_297([[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_298(rgCache))
    {
        counters[b] = old177_0;
        return true;
    }
    counters[b] = old177_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_298([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_296(rgCache))
    {
        board[direction_left[coord - 1]] = old178_0;
        return true;
    }
    board[direction_left[coord - 1]] = old178_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_304(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_307(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_307([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_307;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old182_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_309(rgCache))
    {
        counters[static_cast<Piece>(w)] = old182_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old182_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_308([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_308;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old256_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_303(rgCache))
    {
        coord = old256_0;
        return true;
    }
    coord = old256_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_309([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_309;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old183_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_310(rgCache))
    {
        counters[b] = old183_0;
        return true;
    }
    counters[b] = old183_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_310([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_310;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old184_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_308(rgCache))
    {
        board[coord] = old184_0;
        return true;
    }
    board[coord] = old184_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_316([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_316;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old185_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_319(rgCache))
    {
        coord = old185_0;
        return true;
    }
    coord = old185_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_319([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_319;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_320(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_320([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_320;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_273(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_328([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_391.reset();
    const auto result_188 = is_legal_385_386_385(rgCache);
    rgCache.decDepth();
    if (!result_188)
    {
        if (is_legal_121_771_121_121_771_771_121_771_383(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_399(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_347([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_350(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_350([[maybe_unused]]RgCache& rgCache)
{
    const auto old191_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_352(rgCache))
    {
        counters[static_cast<Piece>(w)] = old191_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old191_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_351([[maybe_unused]]RgCache& rgCache)
{
    const auto old192_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_358(rgCache))
    {
        coord = old192_0;
        return true;
    }
    coord = old192_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_352([[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_353(rgCache))
    {
        counters[b] = old193_0;
        return true;
    }
    counters[b] = old193_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_353([[maybe_unused]]RgCache& rgCache)
{
    const auto old194_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_351(rgCache))
    {
        board[direction_right[coord - 1]] = old194_0;
        return true;
    }
    board[direction_right[coord - 1]] = old194_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_358([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_358;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_359(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_359([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_359;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_362(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_362([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_362;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old198_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_364(rgCache))
    {
        counters[static_cast<Piece>(w)] = old198_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old198_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_363([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_363;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old257_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_358(rgCache))
    {
        coord = old257_0;
        return true;
    }
    coord = old257_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_364([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_364;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old199_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_365(rgCache))
    {
        counters[b] = old199_0;
        return true;
    }
    counters[b] = old199_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_365([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_365;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old200_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_363(rgCache))
    {
        board[coord] = old200_0;
        return true;
    }
    board[coord] = old200_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_371([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_371;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old201_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_374(rgCache))
    {
        coord = old201_0;
        return true;
    }
    coord = old201_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_374([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_374;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_375(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_375([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_375;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_328(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_383([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_440.reset();
    const auto result_204 = is_legal_432_433_432(rgCache);
    rgCache.decDepth();
    if (!result_204)
    {
        if (is_legal_121_771_121_121_771_771_121_771_430(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_449(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_399([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_401(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_401([[maybe_unused]]RgCache& rgCache)
{
    const auto old207_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_403(rgCache))
    {
        counters[static_cast<Piece>(w)] = old207_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old207_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_402([[maybe_unused]]RgCache& rgCache)
{
    const auto old208_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_121_771_121_121_771_771_121_771_408(rgCache))
    {
        coord = old208_0;
        return true;
    }
    coord = old208_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_403([[maybe_unused]]RgCache& rgCache)
{
    const auto old209_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_404(rgCache))
    {
        counters[b] = old209_0;
        return true;
    }
    counters[b] = old209_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_404([[maybe_unused]]RgCache& rgCache)
{
    const auto old210_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_402(rgCache))
    {
        board[RbgCoordMap3[coord]] = old210_0;
        return true;
    }
    board[RbgCoordMap3[coord]] = old210_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_408([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_408;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_409(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_409([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_409;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_412(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_412([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_412;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old214_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_414(rgCache))
    {
        counters[static_cast<Piece>(w)] = old214_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old214_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_413([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_413;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old258_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_121_771_121_121_771_771_121_771_408(rgCache))
    {
        coord = old258_0;
        return true;
    }
    coord = old258_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_414([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_414;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old215_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_415(rgCache))
    {
        counters[b] = old215_0;
        return true;
    }
    counters[b] = old215_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_415([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_415;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old216_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_413(rgCache))
    {
        board[coord] = old216_0;
        return true;
    }
    board[coord] = old216_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_420([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_420;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old217_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_121_771_121_121_771_771_121_771_422(rgCache))
    {
        coord = old217_0;
        return true;
    }
    coord = old217_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_422([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_422;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_423(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_423([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_423;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_383(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_430([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_493.reset();
    const auto result_220 = is_legal_487_488_487(rgCache);
    rgCache.decDepth();
    if (!result_220)
    {
        if (is_legal_121_771_121_121_771_771_121_771_534(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_501(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_449([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_452(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_452([[maybe_unused]]RgCache& rgCache)
{
    const auto old223_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_454(rgCache))
    {
        counters[static_cast<Piece>(w)] = old223_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old223_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_453([[maybe_unused]]RgCache& rgCache)
{
    const auto old224_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_460(rgCache))
    {
        coord = old224_0;
        return true;
    }
    coord = old224_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_454([[maybe_unused]]RgCache& rgCache)
{
    const auto old225_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_455(rgCache))
    {
        counters[b] = old225_0;
        return true;
    }
    counters[b] = old225_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_455([[maybe_unused]]RgCache& rgCache)
{
    const auto old226_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_453(rgCache))
    {
        board[direction_down[coord - 1]] = old226_0;
        return true;
    }
    board[direction_down[coord - 1]] = old226_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_460([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_460;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_461(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_461([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_461;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_464(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_464([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_464;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old230_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_466(rgCache))
    {
        counters[static_cast<Piece>(w)] = old230_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old230_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_465([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_465;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old259_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_460(rgCache))
    {
        coord = old259_0;
        return true;
    }
    coord = old259_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_466([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_466;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old231_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_467(rgCache))
    {
        counters[b] = old231_0;
        return true;
    }
    counters[b] = old231_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_467([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_467;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old232_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_465(rgCache))
    {
        board[coord] = old232_0;
        return true;
    }
    board[coord] = old232_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_473([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_473;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old233_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_121_771_121_121_771_771_121_771_476(rgCache))
    {
        coord = old233_0;
        return true;
    }
    coord = old233_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_476([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_476;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_477(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_477([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_477;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_430(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_501([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_503(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_503([[maybe_unused]]RgCache& rgCache)
{
    const auto old238_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_505(rgCache))
    {
        counters[static_cast<Piece>(w)] = old238_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old238_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_504([[maybe_unused]]RgCache& rgCache)
{
    const auto old239_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_121_771_121_121_771_771_121_771_510(rgCache))
    {
        coord = old239_0;
        return true;
    }
    coord = old239_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_505([[maybe_unused]]RgCache& rgCache)
{
    const auto old240_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_506(rgCache))
    {
        counters[b] = old240_0;
        return true;
    }
    counters[b] = old240_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_506([[maybe_unused]]RgCache& rgCache)
{
    const auto old241_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = b;
    if (is_legal_121_771_121_121_771_771_121_771_504(rgCache))
    {
        board[RbgCoordMap4[coord]] = old241_0;
        return true;
    }
    board[RbgCoordMap4[coord]] = old241_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_510([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_510;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_511(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_511([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_511;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_771_121_121_771_771_121_771_514(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_522(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_514([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_514;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old245_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_771_121_121_771_771_121_771_516(rgCache))
    {
        counters[static_cast<Piece>(w)] = old245_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old245_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_515([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_515;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old260_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_121_771_121_121_771_771_121_771_510(rgCache))
    {
        coord = old260_0;
        return true;
    }
    coord = old260_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_516([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_516;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old246_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_771_121_121_771_771_121_771_517(rgCache))
    {
        counters[b] = old246_0;
        return true;
    }
    counters[b] = old246_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_517([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_517;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old247_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_515(rgCache))
    {
        board[coord] = old247_0;
        return true;
    }
    board[coord] = old247_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_522([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_522;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old248_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_121_771_121_121_771_771_121_771_524(rgCache))
    {
        coord = old248_0;
        return true;
    }
    coord = old248_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_524([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_524;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_771_121_121_771_771_121_771_525(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_525([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_771_525;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_121_771_121_121_771_771_121_771_522(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_121_771_121_121_771_771_121_771_534(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_534([[maybe_unused]]RgCache& rgCache)
{
    const auto old251_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_771_121_121_771_771_121_771_7(rgCache))
    {
        board[coord] = old251_0;
        return true;
    }
    board[coord] = old251_0;
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_7([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_557.reset();
    rgCache.state_cache_571.reset();
    rgCache.state_cache_584.reset();
    rgCache.state_cache_598.reset();
    rgCache.state_cache_613.reset();
    rgCache.state_cache_626.reset();
    rgCache.state_cache_640.reset();
    rgCache.state_cache_653.reset();
    rgCache.state_cache_665.reset();
    rgCache.state_cache_679.reset();
    rgCache.state_cache_692.reset();
    rgCache.state_cache_706.reset();
    rgCache.state_cache_721.reset();
    rgCache.state_cache_734.reset();
    rgCache.state_cache_748.reset();
    rgCache.state_cache_761.reset();
    const auto result_252 = is_legal_548_549_548(rgCache);
    rgCache.decDepth();
    if (!result_252)
    {
        if (is_legal_121_771_121_121_771_771_121_771_771(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_771_121_121_771_771_121_771_771([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_121([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_132.reset();
    const auto result_123 = is_legal_126_127_126(rgCache);
    rgCache.decDepth();
    if (!result_123)
    {
        if (is_legal_121_794_121_121_794_794_121_794_124(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_140(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_124([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_181.reset();
    const auto result_124 = is_legal_173_174_173(rgCache);
    rgCache.decDepth();
    if (!result_124)
    {
        if (is_legal_121_794_121_121_794_794_121_794_171(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_140([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_142(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_142([[maybe_unused]]RgCache& rgCache)
{
    const auto old127_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_144(rgCache))
    {
        counters[static_cast<Piece>(w)] = old127_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old127_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_143([[maybe_unused]]RgCache& rgCache)
{
    const auto old128_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_121_794_121_121_794_794_121_794_149(rgCache))
    {
        coord = old128_0;
        return true;
    }
    coord = old128_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_144([[maybe_unused]]RgCache& rgCache)
{
    const auto old129_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_145(rgCache))
    {
        counters[b] = old129_0;
        return true;
    }
    counters[b] = old129_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_145([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_143(rgCache))
    {
        board[RbgCoordMap1[coord]] = old130_0;
        return true;
    }
    board[RbgCoordMap1[coord]] = old130_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_149([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_149;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_150([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_153(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_153([[maybe_unused]]RgCache& rgCache)
{
    const auto old134_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_155(rgCache))
    {
        counters[static_cast<Piece>(w)] = old134_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old134_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_154([[maybe_unused]]RgCache& rgCache)
{
    const auto old253_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_121_794_121_121_794_794_121_794_149(rgCache))
    {
        coord = old253_0;
        return true;
    }
    coord = old253_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_155([[maybe_unused]]RgCache& rgCache)
{
    const auto old135_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_156(rgCache))
    {
        counters[b] = old135_0;
        return true;
    }
    counters[b] = old135_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old136_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_154(rgCache))
    {
        board[coord] = old136_0;
        return true;
    }
    board[coord] = old136_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old137_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_121_794_121_121_794_794_121_794_163(rgCache))
    {
        coord = old137_0;
        return true;
    }
    coord = old137_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_124(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_171([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_234.reset();
    const auto result_140 = is_legal_228_229_228(rgCache);
    rgCache.decDepth();
    if (!result_140)
    {
        if (is_legal_121_794_121_121_794_794_121_794_226(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_242(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_190([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_193(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_193([[maybe_unused]]RgCache& rgCache)
{
    const auto old143_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_195(rgCache))
    {
        counters[static_cast<Piece>(w)] = old143_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old143_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_194([[maybe_unused]]RgCache& rgCache)
{
    const auto old144_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_201(rgCache))
    {
        coord = old144_0;
        return true;
    }
    coord = old144_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_195([[maybe_unused]]RgCache& rgCache)
{
    const auto old145_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_196(rgCache))
    {
        counters[b] = old145_0;
        return true;
    }
    counters[b] = old145_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_196([[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_194(rgCache))
    {
        board[direction_up[coord - 1]] = old146_0;
        return true;
    }
    board[direction_up[coord - 1]] = old146_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_202(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_205(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_205([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_205;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old150_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_207(rgCache))
    {
        counters[static_cast<Piece>(w)] = old150_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old150_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_206([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_206;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old254_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_201(rgCache))
    {
        coord = old254_0;
        return true;
    }
    coord = old254_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_207([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_207;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old151_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_208(rgCache))
    {
        counters[b] = old151_0;
        return true;
    }
    counters[b] = old151_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_208([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_208;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old152_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_206(rgCache))
    {
        board[coord] = old152_0;
        return true;
    }
    board[coord] = old152_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_214([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_214;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old153_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_217(rgCache))
    {
        coord = old153_0;
        return true;
    }
    coord = old153_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_217([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_217;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_218(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_218([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_218;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_171(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_226([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_283.reset();
    const auto result_156 = is_legal_275_276_275(rgCache);
    rgCache.decDepth();
    if (!result_156)
    {
        if (is_legal_121_794_121_121_794_794_121_794_273(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_242([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_244(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_244([[maybe_unused]]RgCache& rgCache)
{
    const auto old159_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_246(rgCache))
    {
        counters[static_cast<Piece>(w)] = old159_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old159_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_245([[maybe_unused]]RgCache& rgCache)
{
    const auto old160_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_121_794_121_121_794_794_121_794_251(rgCache))
    {
        coord = old160_0;
        return true;
    }
    coord = old160_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_246([[maybe_unused]]RgCache& rgCache)
{
    const auto old161_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_247(rgCache))
    {
        counters[b] = old161_0;
        return true;
    }
    counters[b] = old161_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_247([[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_245(rgCache))
    {
        board[RbgCoordMap2[coord]] = old162_0;
        return true;
    }
    board[RbgCoordMap2[coord]] = old162_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_251([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_251;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_252(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_252([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_252;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_255(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old166_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_257(rgCache))
    {
        counters[static_cast<Piece>(w)] = old166_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old166_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old255_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_121_794_121_121_794_794_121_794_251(rgCache))
    {
        coord = old255_0;
        return true;
    }
    coord = old255_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_257([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old167_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_258(rgCache))
    {
        counters[b] = old167_0;
        return true;
    }
    counters[b] = old167_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_258([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_258;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old168_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_256(rgCache))
    {
        board[coord] = old168_0;
        return true;
    }
    board[coord] = old168_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_263([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_263;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_121_794_121_121_794_794_121_794_265(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_226(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_273([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_338.reset();
    const auto result_172 = is_legal_330_331_330(rgCache);
    rgCache.decDepth();
    if (!result_172)
    {
        if (is_legal_121_794_121_121_794_794_121_794_328(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_347(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_292([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_295(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_295([[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_297(rgCache))
    {
        counters[static_cast<Piece>(w)] = old175_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old175_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_296([[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_303(rgCache))
    {
        coord = old176_0;
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_297([[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_298(rgCache))
    {
        counters[b] = old177_0;
        return true;
    }
    counters[b] = old177_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_298([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_296(rgCache))
    {
        board[direction_left[coord - 1]] = old178_0;
        return true;
    }
    board[direction_left[coord - 1]] = old178_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_304(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_307(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_307([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_307;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old182_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_309(rgCache))
    {
        counters[static_cast<Piece>(w)] = old182_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old182_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_308([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_308;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old256_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_303(rgCache))
    {
        coord = old256_0;
        return true;
    }
    coord = old256_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_309([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_309;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old183_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_310(rgCache))
    {
        counters[b] = old183_0;
        return true;
    }
    counters[b] = old183_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_310([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_310;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old184_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_308(rgCache))
    {
        board[coord] = old184_0;
        return true;
    }
    board[coord] = old184_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_316([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_316;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old185_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_319(rgCache))
    {
        coord = old185_0;
        return true;
    }
    coord = old185_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_319([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_319;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_320(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_320([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_320;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_273(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_328([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_391.reset();
    const auto result_188 = is_legal_385_386_385(rgCache);
    rgCache.decDepth();
    if (!result_188)
    {
        if (is_legal_121_794_121_121_794_794_121_794_383(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_399(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_347([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_350(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_350([[maybe_unused]]RgCache& rgCache)
{
    const auto old191_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_352(rgCache))
    {
        counters[static_cast<Piece>(w)] = old191_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old191_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_351([[maybe_unused]]RgCache& rgCache)
{
    const auto old192_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_358(rgCache))
    {
        coord = old192_0;
        return true;
    }
    coord = old192_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_352([[maybe_unused]]RgCache& rgCache)
{
    const auto old193_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_353(rgCache))
    {
        counters[b] = old193_0;
        return true;
    }
    counters[b] = old193_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_353([[maybe_unused]]RgCache& rgCache)
{
    const auto old194_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_351(rgCache))
    {
        board[direction_right[coord - 1]] = old194_0;
        return true;
    }
    board[direction_right[coord - 1]] = old194_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_358([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_358;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_359(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_359([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_359;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_362(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_362([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_362;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old198_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_364(rgCache))
    {
        counters[static_cast<Piece>(w)] = old198_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old198_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_363([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_363;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old257_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_358(rgCache))
    {
        coord = old257_0;
        return true;
    }
    coord = old257_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_364([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_364;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old199_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_365(rgCache))
    {
        counters[b] = old199_0;
        return true;
    }
    counters[b] = old199_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_365([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_365;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old200_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_363(rgCache))
    {
        board[coord] = old200_0;
        return true;
    }
    board[coord] = old200_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_371([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_371;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old201_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_374(rgCache))
    {
        coord = old201_0;
        return true;
    }
    coord = old201_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_374([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_374;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_375(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_375([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_375;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_328(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_383([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_440.reset();
    const auto result_204 = is_legal_432_433_432(rgCache);
    rgCache.decDepth();
    if (!result_204)
    {
        if (is_legal_121_794_121_121_794_794_121_794_430(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_449(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_399([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_401(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_401([[maybe_unused]]RgCache& rgCache)
{
    const auto old207_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_403(rgCache))
    {
        counters[static_cast<Piece>(w)] = old207_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old207_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_402([[maybe_unused]]RgCache& rgCache)
{
    const auto old208_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_121_794_121_121_794_794_121_794_408(rgCache))
    {
        coord = old208_0;
        return true;
    }
    coord = old208_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_403([[maybe_unused]]RgCache& rgCache)
{
    const auto old209_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_404(rgCache))
    {
        counters[b] = old209_0;
        return true;
    }
    counters[b] = old209_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_404([[maybe_unused]]RgCache& rgCache)
{
    const auto old210_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_402(rgCache))
    {
        board[RbgCoordMap3[coord]] = old210_0;
        return true;
    }
    board[RbgCoordMap3[coord]] = old210_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_408([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_408;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_409(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_409([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_409;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_412(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_412([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_412;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old214_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_414(rgCache))
    {
        counters[static_cast<Piece>(w)] = old214_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old214_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_413([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_413;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old258_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_121_794_121_121_794_794_121_794_408(rgCache))
    {
        coord = old258_0;
        return true;
    }
    coord = old258_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_414([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_414;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old215_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_415(rgCache))
    {
        counters[b] = old215_0;
        return true;
    }
    counters[b] = old215_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_415([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_415;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old216_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_413(rgCache))
    {
        board[coord] = old216_0;
        return true;
    }
    board[coord] = old216_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_420([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_420;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old217_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_121_794_121_121_794_794_121_794_422(rgCache))
    {
        coord = old217_0;
        return true;
    }
    coord = old217_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_422([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_422;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_423(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_423([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_423;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_383(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_430([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_493.reset();
    const auto result_220 = is_legal_487_488_487(rgCache);
    rgCache.decDepth();
    if (!result_220)
    {
        if (is_legal_121_794_121_121_794_794_121_794_534(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_501(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_449([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_452(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_452([[maybe_unused]]RgCache& rgCache)
{
    const auto old223_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_454(rgCache))
    {
        counters[static_cast<Piece>(w)] = old223_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old223_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_453([[maybe_unused]]RgCache& rgCache)
{
    const auto old224_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_460(rgCache))
    {
        coord = old224_0;
        return true;
    }
    coord = old224_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_454([[maybe_unused]]RgCache& rgCache)
{
    const auto old225_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_455(rgCache))
    {
        counters[b] = old225_0;
        return true;
    }
    counters[b] = old225_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_455([[maybe_unused]]RgCache& rgCache)
{
    const auto old226_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_453(rgCache))
    {
        board[direction_down[coord - 1]] = old226_0;
        return true;
    }
    board[direction_down[coord - 1]] = old226_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_460([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_460;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_461(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_461([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_461;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_464(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_464([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_464;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old230_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_466(rgCache))
    {
        counters[static_cast<Piece>(w)] = old230_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old230_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_465([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_465;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old259_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_460(rgCache))
    {
        coord = old259_0;
        return true;
    }
    coord = old259_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_466([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_466;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old231_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_467(rgCache))
    {
        counters[b] = old231_0;
        return true;
    }
    counters[b] = old231_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_467([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_467;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old232_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_465(rgCache))
    {
        board[coord] = old232_0;
        return true;
    }
    board[coord] = old232_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_473([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_473;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old233_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_121_794_121_121_794_794_121_794_476(rgCache))
    {
        coord = old233_0;
        return true;
    }
    coord = old233_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_476([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_476;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_477(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_477([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_477;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_430(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_501([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_503(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_503([[maybe_unused]]RgCache& rgCache)
{
    const auto old238_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_505(rgCache))
    {
        counters[static_cast<Piece>(w)] = old238_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old238_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_504([[maybe_unused]]RgCache& rgCache)
{
    const auto old239_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_121_794_121_121_794_794_121_794_510(rgCache))
    {
        coord = old239_0;
        return true;
    }
    coord = old239_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_505([[maybe_unused]]RgCache& rgCache)
{
    const auto old240_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_506(rgCache))
    {
        counters[b] = old240_0;
        return true;
    }
    counters[b] = old240_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_506([[maybe_unused]]RgCache& rgCache)
{
    const auto old241_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = b;
    if (is_legal_121_794_121_121_794_794_121_794_504(rgCache))
    {
        board[RbgCoordMap4[coord]] = old241_0;
        return true;
    }
    board[RbgCoordMap4[coord]] = old241_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_510([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_510;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_511(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_511([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_511;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_121_794_121_121_794_794_121_794_514(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_522(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_514([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_514;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old245_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (is_legal_121_794_121_121_794_794_121_794_516(rgCache))
    {
        counters[static_cast<Piece>(w)] = old245_0;
        return true;
    }
    counters[static_cast<Piece>(w)] = old245_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_515([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_515;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old260_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_121_794_121_121_794_794_121_794_510(rgCache))
    {
        coord = old260_0;
        return true;
    }
    coord = old260_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_516([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_516;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old246_0 = counters[b];
    counters[b] = counters[b]+1;
    if (is_legal_121_794_121_121_794_794_121_794_517(rgCache))
    {
        counters[b] = old246_0;
        return true;
    }
    counters[b] = old246_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_517([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_517;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old247_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_515(rgCache))
    {
        board[coord] = old247_0;
        return true;
    }
    board[coord] = old247_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_522([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_522;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old248_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_121_794_121_121_794_794_121_794_524(rgCache))
    {
        coord = old248_0;
        return true;
    }
    coord = old248_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_524([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_524;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_121_794_121_121_794_794_121_794_525(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_525([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_121_794_525;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_121_794_121_121_794_794_121_794_522(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_121_794_121_121_794_794_121_794_534(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_534([[maybe_unused]]RgCache& rgCache)
{
    const auto old251_0 = board[coord];
    board[coord] = b;
    if (is_legal_121_794_121_121_794_794_121_794_7(rgCache))
    {
        board[coord] = old251_0;
        return true;
    }
    board[coord] = old251_0;
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_7([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_557.reset();
    rgCache.state_cache_571.reset();
    rgCache.state_cache_584.reset();
    rgCache.state_cache_598.reset();
    rgCache.state_cache_613.reset();
    rgCache.state_cache_626.reset();
    rgCache.state_cache_640.reset();
    rgCache.state_cache_653.reset();
    rgCache.state_cache_665.reset();
    rgCache.state_cache_679.reset();
    rgCache.state_cache_692.reset();
    rgCache.state_cache_706.reset();
    rgCache.state_cache_721.reset();
    rgCache.state_cache_734.reset();
    rgCache.state_cache_748.reset();
    rgCache.state_cache_761.reset();
    const auto result_252 = is_legal_548_549_548(rgCache);
    rgCache.decDepth();
    if (result_252)
    {
        if (is_legal_121_794_121_121_794_794_121_794_794(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_121_794_121_121_794_794_121_794_794([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1221_1222_1221([[maybe_unused]]RgCache& rgCache)
{
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_1221_1222_1223(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1221_1222_1222([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1221_1222_1223([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_1221_1222_1226(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1221_1222_1226([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_1221_1222_1229(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1221_1222_1229([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1229;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1221_1222_1230(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1221_1222_1230([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1221_1222_1222(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1221_1222_1233(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1221_1222_1233([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_1221_1222_1229(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_126_127_126([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_126_127_128(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_126_127_127([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_126_127_128([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_126_127_130(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_126_127_130([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_126_127_132(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_126_127_132([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_132;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_126_127_133(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_126_127_133([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_126_127_127(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_126_127_136(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_126_127_136([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_126_127_132(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_1276_1277_1276([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_1276_1277_1278(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1276_1277_1277([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1276_1277_1278([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_1276_1277_1280(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1276_1277_1280([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_1276_1277_1282(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_1276_1277_1282([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1282;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1276_1277_1283(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1276_1277_1283([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1276_1277_1277(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1276_1277_1286(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1276_1277_1286([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_1276_1277_1282(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_1327_1328_1327([[maybe_unused]]RgCache& rgCache)
{
    const auto old4_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_1327_1328_1329(rgCache))
    {
        coord = old4_0;
        return true;
    }    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_1327_1328_1328([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1327_1328_1329([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_1327_1328_1330(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1327_1328_1330([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_806.reset();
    rgCache.state_cache_820.reset();
    rgCache.state_cache_833.reset();
    rgCache.state_cache_847.reset();
    rgCache.state_cache_862.reset();
    rgCache.state_cache_875.reset();
    rgCache.state_cache_889.reset();
    rgCache.state_cache_902.reset();
    const auto result_6 = is_legal_800_801_800(rgCache);
    rgCache.decDepth();
    if (result_6)
    {
        if (is_legal_1327_1328_1328(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1337([[maybe_unused]]RgCache& rgCache)
{
    const auto old76_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_1337_1338_1339(rgCache))
    {
        coord = old76_0;
        return true;
    }    }
    coord = old76_0;
    return false;
}

bool GameState::is_legal_1337_1338_1338([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1337_1338_1339([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_1337_1338_1340(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1340([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_1337_1338_1342(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_1337_1338_1369(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_1337_1338_1411(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_1337_1338_1438(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_1337_1338_1423(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_1337_1338_1381(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_1337_1338_1396(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_1337_1338_1354(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1342([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_1337_1338_1344(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_1337_1338_1452(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1344([[maybe_unused]]RgCache& rgCache)
{
    const auto old78_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_1337_1338_1346(rgCache))
    {
        coord = old78_0;
        return true;
    }
    coord = old78_0;
    return false;
}

bool GameState::is_legal_1337_1338_1346([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1346;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1347(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1347([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1350(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1350([[maybe_unused]]RgCache& rgCache)
{
    const auto old166_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_1337_1338_1346(rgCache))
    {
        coord = old166_0;
        return true;
    }
    coord = old166_0;
    return false;
}

bool GameState::is_legal_1337_1338_1354([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_1337_1338_1357(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_1337_1338_1465(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1357([[maybe_unused]]RgCache& rgCache)
{
    const auto old82_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_1337_1338_1360(rgCache))
    {
        coord = old82_0;
        return true;
    }
    coord = old82_0;
    return false;
}

bool GameState::is_legal_1337_1338_1360([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1360;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1361(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1361([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1364(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1364([[maybe_unused]]RgCache& rgCache)
{
    const auto old167_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_1337_1338_1360(rgCache))
    {
        coord = old167_0;
        return true;
    }
    coord = old167_0;
    return false;
}

bool GameState::is_legal_1337_1338_1369([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_1337_1338_1371(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_1337_1338_1479(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1371([[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_1337_1338_1373(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::is_legal_1337_1338_1373([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1373;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1374(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1374([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1377(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1377([[maybe_unused]]RgCache& rgCache)
{
    const auto old168_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_1337_1338_1373(rgCache))
    {
        coord = old168_0;
        return true;
    }
    coord = old168_0;
    return false;
}

bool GameState::is_legal_1337_1338_1381([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_1337_1338_1384(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_1337_1338_1492(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1384([[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_1337_1338_1387(rgCache))
    {
        coord = old90_0;
        return true;
    }
    coord = old90_0;
    return false;
}

bool GameState::is_legal_1337_1338_1387([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1387;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1388(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1388([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1391(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1391([[maybe_unused]]RgCache& rgCache)
{
    const auto old169_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_1337_1338_1387(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_1337_1338_1396([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_1337_1338_1399(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_1337_1338_1507(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1399([[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_1337_1338_1402(rgCache))
    {
        coord = old94_0;
        return true;
    }
    coord = old94_0;
    return false;
}

bool GameState::is_legal_1337_1338_1402([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1402;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1403(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1403([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1406(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1406([[maybe_unused]]RgCache& rgCache)
{
    const auto old170_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_1337_1338_1402(rgCache))
    {
        coord = old170_0;
        return true;
    }
    coord = old170_0;
    return false;
}

bool GameState::is_legal_1337_1338_1411([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_1337_1338_1413(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_1337_1338_1521(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1413([[maybe_unused]]RgCache& rgCache)
{
    const auto old98_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_1337_1338_1415(rgCache))
    {
        coord = old98_0;
        return true;
    }
    coord = old98_0;
    return false;
}

bool GameState::is_legal_1337_1338_1415([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1415;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1416(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1416([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1419(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1419([[maybe_unused]]RgCache& rgCache)
{
    const auto old171_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_1337_1338_1415(rgCache))
    {
        coord = old171_0;
        return true;
    }
    coord = old171_0;
    return false;
}

bool GameState::is_legal_1337_1338_1423([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_1337_1338_1426(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_1337_1338_1534(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1426([[maybe_unused]]RgCache& rgCache)
{
    const auto old102_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_1337_1338_1429(rgCache))
    {
        coord = old102_0;
        return true;
    }
    coord = old102_0;
    return false;
}

bool GameState::is_legal_1337_1338_1429([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1429;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1430(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1430([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1433(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1433([[maybe_unused]]RgCache& rgCache)
{
    const auto old172_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_1337_1338_1429(rgCache))
    {
        coord = old172_0;
        return true;
    }
    coord = old172_0;
    return false;
}

bool GameState::is_legal_1337_1338_1438([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_1337_1338_1440(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_1337_1338_1548(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1440([[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_1337_1338_1442(rgCache))
    {
        coord = old106_0;
        return true;
    }
    coord = old106_0;
    return false;
}

bool GameState::is_legal_1337_1338_1442([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1442;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1443(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1443([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1446(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1446([[maybe_unused]]RgCache& rgCache)
{
    const auto old173_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_1337_1338_1442(rgCache))
    {
        coord = old173_0;
        return true;
    }
    coord = old173_0;
    return false;
}

bool GameState::is_legal_1337_1338_1452([[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_1337_1338_1454(rgCache))
    {
        coord = old110_0;
        return true;
    }
    coord = old110_0;
    return false;
}

bool GameState::is_legal_1337_1338_1454([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1454;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1455(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1455([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1458(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1458([[maybe_unused]]RgCache& rgCache)
{
    const auto old174_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_1337_1338_1454(rgCache))
    {
        coord = old174_0;
        return true;
    }
    coord = old174_0;
    return false;
}

bool GameState::is_legal_1337_1338_1465([[maybe_unused]]RgCache& rgCache)
{
    const auto old114_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_1337_1338_1468(rgCache))
    {
        coord = old114_0;
        return true;
    }
    coord = old114_0;
    return false;
}

bool GameState::is_legal_1337_1338_1468([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1468;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1469(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1469([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1472(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1472([[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_1337_1338_1468(rgCache))
    {
        coord = old175_0;
        return true;
    }
    coord = old175_0;
    return false;
}

bool GameState::is_legal_1337_1338_1479([[maybe_unused]]RgCache& rgCache)
{
    const auto old118_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_1337_1338_1481(rgCache))
    {
        coord = old118_0;
        return true;
    }
    coord = old118_0;
    return false;
}

bool GameState::is_legal_1337_1338_1481([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1481;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1482(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1482([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1485(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1485([[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_1337_1338_1481(rgCache))
    {
        coord = old176_0;
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::is_legal_1337_1338_1492([[maybe_unused]]RgCache& rgCache)
{
    const auto old122_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_1337_1338_1495(rgCache))
    {
        coord = old122_0;
        return true;
    }
    coord = old122_0;
    return false;
}

bool GameState::is_legal_1337_1338_1495([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1495;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1496(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1496([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1499(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1499([[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_1337_1338_1495(rgCache))
    {
        coord = old177_0;
        return true;
    }
    coord = old177_0;
    return false;
}

bool GameState::is_legal_1337_1338_1507([[maybe_unused]]RgCache& rgCache)
{
    const auto old126_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_1337_1338_1510(rgCache))
    {
        coord = old126_0;
        return true;
    }
    coord = old126_0;
    return false;
}

bool GameState::is_legal_1337_1338_1510([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1510;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1511(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1511([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1514(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1514([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_1337_1338_1510(rgCache))
    {
        coord = old178_0;
        return true;
    }
    coord = old178_0;
    return false;
}

bool GameState::is_legal_1337_1338_1521([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_1337_1338_1523(rgCache))
    {
        coord = old130_0;
        return true;
    }
    coord = old130_0;
    return false;
}

bool GameState::is_legal_1337_1338_1523([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1523;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1524(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1524([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1527(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1527([[maybe_unused]]RgCache& rgCache)
{
    const auto old179_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_1337_1338_1523(rgCache))
    {
        coord = old179_0;
        return true;
    }
    coord = old179_0;
    return false;
}

bool GameState::is_legal_1337_1338_1534([[maybe_unused]]RgCache& rgCache)
{
    const auto old134_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_1337_1338_1537(rgCache))
    {
        coord = old134_0;
        return true;
    }
    coord = old134_0;
    return false;
}

bool GameState::is_legal_1337_1338_1537([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1537;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1538(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1538([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1541(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1541([[maybe_unused]]RgCache& rgCache)
{
    const auto old180_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_1337_1338_1537(rgCache))
    {
        coord = old180_0;
        return true;
    }
    coord = old180_0;
    return false;
}

bool GameState::is_legal_1337_1338_1548([[maybe_unused]]RgCache& rgCache)
{
    const auto old138_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_1337_1338_1550(rgCache))
    {
        coord = old138_0;
        return true;
    }
    coord = old138_0;
    return false;
}

bool GameState::is_legal_1337_1338_1550([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1550;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_1337_1338_1551(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1337_1338_1551([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_1337_1338_1338(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_1337_1338_1554(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_1337_1338_1554([[maybe_unused]]RgCache& rgCache)
{
    const auto old181_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_1337_1338_1550(rgCache))
    {
        coord = old181_0;
        return true;
    }
    coord = old181_0;
    return false;
}

bool GameState::is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1559()
{
    if ((counters[w]>counters[b])==1)
    {
        if (is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1579())
        {
            return true;
        }
    }
    if ((counters[w]<counters[b])==1)
    {
        if (is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1579())
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1579())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1579()
{
    return true;
}

bool GameState::is_legal_1582_1583_1582([[maybe_unused]]RgCache& rgCache)
{
    const auto old4_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_1582_1583_1611(rgCache))
    {
        coord = old4_0;
        return true;
    }    }
    coord = old4_0;
    if (!is_legal_538_539_538(rgCache))
    {
        if (is_legal_1582_1583_1583(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1582_1583_1583([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1582_1583_1611([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_1582_1583_1612(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1582_1583_1612([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_113.reset();
    rgCache.state_cache_17.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_44.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_73.reset();
    rgCache.state_cache_86.reset();
    const auto result_6 = is_legal_11_12_11(rgCache);
    rgCache.decDepth();
    if (result_6)
    {
        if (is_legal_1582_1583_1583(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1584_1585_1584([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_121_771_149.reset();
    rgCache.state_cache_121_771_161.reset();
    rgCache.state_cache_121_771_163.reset();
    rgCache.state_cache_121_771_164.reset();
    rgCache.state_cache_121_771_201.reset();
    rgCache.state_cache_121_771_202.reset();
    rgCache.state_cache_121_771_205.reset();
    rgCache.state_cache_121_771_206.reset();
    rgCache.state_cache_121_771_207.reset();
    rgCache.state_cache_121_771_208.reset();
    rgCache.state_cache_121_771_214.reset();
    rgCache.state_cache_121_771_217.reset();
    rgCache.state_cache_121_771_218.reset();
    rgCache.state_cache_121_771_251.reset();
    rgCache.state_cache_121_771_252.reset();
    rgCache.state_cache_121_771_255.reset();
    rgCache.state_cache_121_771_256.reset();
    rgCache.state_cache_121_771_257.reset();
    rgCache.state_cache_121_771_258.reset();
    rgCache.state_cache_121_771_263.reset();
    rgCache.state_cache_121_771_265.reset();
    rgCache.state_cache_121_771_266.reset();
    rgCache.state_cache_121_771_303.reset();
    rgCache.state_cache_121_771_304.reset();
    rgCache.state_cache_121_771_307.reset();
    rgCache.state_cache_121_771_308.reset();
    rgCache.state_cache_121_771_309.reset();
    rgCache.state_cache_121_771_310.reset();
    rgCache.state_cache_121_771_316.reset();
    rgCache.state_cache_121_771_319.reset();
    rgCache.state_cache_121_771_320.reset();
    rgCache.state_cache_121_771_358.reset();
    rgCache.state_cache_121_771_359.reset();
    rgCache.state_cache_121_771_362.reset();
    rgCache.state_cache_121_771_363.reset();
    rgCache.state_cache_121_771_364.reset();
    rgCache.state_cache_121_771_365.reset();
    rgCache.state_cache_121_771_371.reset();
    rgCache.state_cache_121_771_374.reset();
    rgCache.state_cache_121_771_375.reset();
    rgCache.state_cache_121_771_408.reset();
    rgCache.state_cache_121_771_409.reset();
    rgCache.state_cache_121_771_412.reset();
    rgCache.state_cache_121_771_413.reset();
    rgCache.state_cache_121_771_414.reset();
    rgCache.state_cache_121_771_415.reset();
    rgCache.state_cache_121_771_420.reset();
    rgCache.state_cache_121_771_422.reset();
    rgCache.state_cache_121_771_423.reset();
    rgCache.state_cache_121_771_460.reset();
    rgCache.state_cache_121_771_461.reset();
    rgCache.state_cache_121_771_464.reset();
    rgCache.state_cache_121_771_465.reset();
    rgCache.state_cache_121_771_466.reset();
    rgCache.state_cache_121_771_467.reset();
    rgCache.state_cache_121_771_473.reset();
    rgCache.state_cache_121_771_476.reset();
    rgCache.state_cache_121_771_477.reset();
    rgCache.state_cache_121_771_510.reset();
    rgCache.state_cache_121_771_511.reset();
    rgCache.state_cache_121_771_514.reset();
    rgCache.state_cache_121_771_515.reset();
    rgCache.state_cache_121_771_516.reset();
    rgCache.state_cache_121_771_517.reset();
    rgCache.state_cache_121_771_522.reset();
    rgCache.state_cache_121_771_524.reset();
    rgCache.state_cache_121_771_525.reset();
    const auto result_2 = is_legal_121_771_121_121_771_771_121_771_121(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_1584_1585_1585(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_121_794_149.reset();
    rgCache.state_cache_121_794_161.reset();
    rgCache.state_cache_121_794_163.reset();
    rgCache.state_cache_121_794_164.reset();
    rgCache.state_cache_121_794_201.reset();
    rgCache.state_cache_121_794_202.reset();
    rgCache.state_cache_121_794_205.reset();
    rgCache.state_cache_121_794_206.reset();
    rgCache.state_cache_121_794_207.reset();
    rgCache.state_cache_121_794_208.reset();
    rgCache.state_cache_121_794_214.reset();
    rgCache.state_cache_121_794_217.reset();
    rgCache.state_cache_121_794_218.reset();
    rgCache.state_cache_121_794_251.reset();
    rgCache.state_cache_121_794_252.reset();
    rgCache.state_cache_121_794_255.reset();
    rgCache.state_cache_121_794_256.reset();
    rgCache.state_cache_121_794_257.reset();
    rgCache.state_cache_121_794_258.reset();
    rgCache.state_cache_121_794_263.reset();
    rgCache.state_cache_121_794_265.reset();
    rgCache.state_cache_121_794_266.reset();
    rgCache.state_cache_121_794_303.reset();
    rgCache.state_cache_121_794_304.reset();
    rgCache.state_cache_121_794_307.reset();
    rgCache.state_cache_121_794_308.reset();
    rgCache.state_cache_121_794_309.reset();
    rgCache.state_cache_121_794_310.reset();
    rgCache.state_cache_121_794_316.reset();
    rgCache.state_cache_121_794_319.reset();
    rgCache.state_cache_121_794_320.reset();
    rgCache.state_cache_121_794_358.reset();
    rgCache.state_cache_121_794_359.reset();
    rgCache.state_cache_121_794_362.reset();
    rgCache.state_cache_121_794_363.reset();
    rgCache.state_cache_121_794_364.reset();
    rgCache.state_cache_121_794_365.reset();
    rgCache.state_cache_121_794_371.reset();
    rgCache.state_cache_121_794_374.reset();
    rgCache.state_cache_121_794_375.reset();
    rgCache.state_cache_121_794_408.reset();
    rgCache.state_cache_121_794_409.reset();
    rgCache.state_cache_121_794_412.reset();
    rgCache.state_cache_121_794_413.reset();
    rgCache.state_cache_121_794_414.reset();
    rgCache.state_cache_121_794_415.reset();
    rgCache.state_cache_121_794_420.reset();
    rgCache.state_cache_121_794_422.reset();
    rgCache.state_cache_121_794_423.reset();
    rgCache.state_cache_121_794_460.reset();
    rgCache.state_cache_121_794_461.reset();
    rgCache.state_cache_121_794_464.reset();
    rgCache.state_cache_121_794_465.reset();
    rgCache.state_cache_121_794_466.reset();
    rgCache.state_cache_121_794_467.reset();
    rgCache.state_cache_121_794_473.reset();
    rgCache.state_cache_121_794_476.reset();
    rgCache.state_cache_121_794_477.reset();
    rgCache.state_cache_121_794_510.reset();
    rgCache.state_cache_121_794_511.reset();
    rgCache.state_cache_121_794_514.reset();
    rgCache.state_cache_121_794_515.reset();
    rgCache.state_cache_121_794_516.reset();
    rgCache.state_cache_121_794_517.reset();
    rgCache.state_cache_121_794_522.reset();
    rgCache.state_cache_121_794_524.reset();
    rgCache.state_cache_121_794_525.reset();
    const auto result_3 = is_legal_121_794_121_121_794_794_121_794_121(rgCache);
    rgCache.decDepth();
    if (result_3)
    {
        if (is_legal_1584_1585_1585(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1584_1585_1585([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1588_1589_1588([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1327_1328_1327(rgCache))
    {
        if (is_legal_1588_1589_1589(rgCache))
        {
            return true;
        }
    }
    const auto old5_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_1588_1589_1618(rgCache))
    {
        coord = old5_0;
        return true;
    }    }
    coord = old5_0;
    return false;
}

bool GameState::is_legal_1588_1589_1589([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_1588_1589_1618([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_1588_1589_1619(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1588_1589_1619([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_806.reset();
    rgCache.state_cache_820.reset();
    rgCache.state_cache_833.reset();
    rgCache.state_cache_847.reset();
    rgCache.state_cache_862.reset();
    rgCache.state_cache_875.reset();
    rgCache.state_cache_889.reset();
    rgCache.state_cache_902.reset();
    const auto result_7 = is_legal_800_801_800(rgCache);
    rgCache.decDepth();
    if (result_7)
    {
        if (is_legal_1588_1589_1589(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1590_1591_1590([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_910_1560_1002.reset();
    rgCache.state_cache_910_1560_1003.reset();
    rgCache.state_cache_910_1560_1006.reset();
    rgCache.state_cache_910_1560_1007.reset();
    rgCache.state_cache_910_1560_1040.reset();
    rgCache.state_cache_910_1560_1041.reset();
    rgCache.state_cache_910_1560_1044.reset();
    rgCache.state_cache_910_1560_1045.reset();
    rgCache.state_cache_910_1560_1046.reset();
    rgCache.state_cache_910_1560_1047.reset();
    rgCache.state_cache_910_1560_1052.reset();
    rgCache.state_cache_910_1560_1054.reset();
    rgCache.state_cache_910_1560_1055.reset();
    rgCache.state_cache_910_1560_1092.reset();
    rgCache.state_cache_910_1560_1093.reset();
    rgCache.state_cache_910_1560_1096.reset();
    rgCache.state_cache_910_1560_1097.reset();
    rgCache.state_cache_910_1560_1098.reset();
    rgCache.state_cache_910_1560_1099.reset();
    rgCache.state_cache_910_1560_1105.reset();
    rgCache.state_cache_910_1560_1108.reset();
    rgCache.state_cache_910_1560_1109.reset();
    rgCache.state_cache_910_1560_1147.reset();
    rgCache.state_cache_910_1560_1148.reset();
    rgCache.state_cache_910_1560_1151.reset();
    rgCache.state_cache_910_1560_1152.reset();
    rgCache.state_cache_910_1560_1153.reset();
    rgCache.state_cache_910_1560_1154.reset();
    rgCache.state_cache_910_1560_1160.reset();
    rgCache.state_cache_910_1560_1163.reset();
    rgCache.state_cache_910_1560_1164.reset();
    rgCache.state_cache_910_1560_1197.reset();
    rgCache.state_cache_910_1560_1198.reset();
    rgCache.state_cache_910_1560_1201.reset();
    rgCache.state_cache_910_1560_1202.reset();
    rgCache.state_cache_910_1560_1203.reset();
    rgCache.state_cache_910_1560_1204.reset();
    rgCache.state_cache_910_1560_1209.reset();
    rgCache.state_cache_910_1560_1211.reset();
    rgCache.state_cache_910_1560_1212.reset();
    rgCache.state_cache_910_1560_1249.reset();
    rgCache.state_cache_910_1560_1250.reset();
    rgCache.state_cache_910_1560_1253.reset();
    rgCache.state_cache_910_1560_1254.reset();
    rgCache.state_cache_910_1560_1255.reset();
    rgCache.state_cache_910_1560_1256.reset();
    rgCache.state_cache_910_1560_1262.reset();
    rgCache.state_cache_910_1560_1265.reset();
    rgCache.state_cache_910_1560_1266.reset();
    rgCache.state_cache_910_1560_1299.reset();
    rgCache.state_cache_910_1560_1300.reset();
    rgCache.state_cache_910_1560_1303.reset();
    rgCache.state_cache_910_1560_1304.reset();
    rgCache.state_cache_910_1560_1305.reset();
    rgCache.state_cache_910_1560_1306.reset();
    rgCache.state_cache_910_1560_1311.reset();
    rgCache.state_cache_910_1560_1313.reset();
    rgCache.state_cache_910_1560_1314.reset();
    rgCache.state_cache_910_1560_938.reset();
    rgCache.state_cache_910_1560_950.reset();
    rgCache.state_cache_910_1560_952.reset();
    rgCache.state_cache_910_1560_953.reset();
    rgCache.state_cache_910_1560_991.reset();
    rgCache.state_cache_910_1560_994.reset();
    rgCache.state_cache_910_1560_995.reset();
    rgCache.state_cache_910_1560_996.reset();
    rgCache.state_cache_910_1560_997.reset();
    const auto result_2 = is_legal_910_1560_910_910_1560_1560_910_1560_910(rgCache);
    rgCache.decDepth();
    if (result_2)
    {
        if (is_legal_1590_1591_1591(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_910_5_1002.reset();
    rgCache.state_cache_910_5_1003.reset();
    rgCache.state_cache_910_5_1006.reset();
    rgCache.state_cache_910_5_1007.reset();
    rgCache.state_cache_910_5_1040.reset();
    rgCache.state_cache_910_5_1041.reset();
    rgCache.state_cache_910_5_1044.reset();
    rgCache.state_cache_910_5_1045.reset();
    rgCache.state_cache_910_5_1046.reset();
    rgCache.state_cache_910_5_1047.reset();
    rgCache.state_cache_910_5_1052.reset();
    rgCache.state_cache_910_5_1054.reset();
    rgCache.state_cache_910_5_1055.reset();
    rgCache.state_cache_910_5_1092.reset();
    rgCache.state_cache_910_5_1093.reset();
    rgCache.state_cache_910_5_1096.reset();
    rgCache.state_cache_910_5_1097.reset();
    rgCache.state_cache_910_5_1098.reset();
    rgCache.state_cache_910_5_1099.reset();
    rgCache.state_cache_910_5_1105.reset();
    rgCache.state_cache_910_5_1108.reset();
    rgCache.state_cache_910_5_1109.reset();
    rgCache.state_cache_910_5_1147.reset();
    rgCache.state_cache_910_5_1148.reset();
    rgCache.state_cache_910_5_1151.reset();
    rgCache.state_cache_910_5_1152.reset();
    rgCache.state_cache_910_5_1153.reset();
    rgCache.state_cache_910_5_1154.reset();
    rgCache.state_cache_910_5_1160.reset();
    rgCache.state_cache_910_5_1163.reset();
    rgCache.state_cache_910_5_1164.reset();
    rgCache.state_cache_910_5_1197.reset();
    rgCache.state_cache_910_5_1198.reset();
    rgCache.state_cache_910_5_1201.reset();
    rgCache.state_cache_910_5_1202.reset();
    rgCache.state_cache_910_5_1203.reset();
    rgCache.state_cache_910_5_1204.reset();
    rgCache.state_cache_910_5_1209.reset();
    rgCache.state_cache_910_5_1211.reset();
    rgCache.state_cache_910_5_1212.reset();
    rgCache.state_cache_910_5_1249.reset();
    rgCache.state_cache_910_5_1250.reset();
    rgCache.state_cache_910_5_1253.reset();
    rgCache.state_cache_910_5_1254.reset();
    rgCache.state_cache_910_5_1255.reset();
    rgCache.state_cache_910_5_1256.reset();
    rgCache.state_cache_910_5_1262.reset();
    rgCache.state_cache_910_5_1265.reset();
    rgCache.state_cache_910_5_1266.reset();
    rgCache.state_cache_910_5_1299.reset();
    rgCache.state_cache_910_5_1300.reset();
    rgCache.state_cache_910_5_1303.reset();
    rgCache.state_cache_910_5_1304.reset();
    rgCache.state_cache_910_5_1305.reset();
    rgCache.state_cache_910_5_1306.reset();
    rgCache.state_cache_910_5_1311.reset();
    rgCache.state_cache_910_5_1313.reset();
    rgCache.state_cache_910_5_1314.reset();
    rgCache.state_cache_910_5_938.reset();
    rgCache.state_cache_910_5_950.reset();
    rgCache.state_cache_910_5_952.reset();
    rgCache.state_cache_910_5_953.reset();
    rgCache.state_cache_910_5_991.reset();
    rgCache.state_cache_910_5_994.reset();
    rgCache.state_cache_910_5_995.reset();
    rgCache.state_cache_910_5_996.reset();
    rgCache.state_cache_910_5_997.reset();
    const auto result_3 = is_legal_910_5_910_910_5_5_910_5_910(rgCache);
    rgCache.decDepth();
    if (result_3)
    {
        if (is_legal_1590_1591_1591(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_1590_1591_1591([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_173_174_173([[maybe_unused]]RgCache& rgCache)
{
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_173_174_175(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_173_174_174([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_173_174_175([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_173_174_178(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_173_174_178([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_173_174_181(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_173_174_181([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_181;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_173_174_182(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_173_174_182([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_173_174_174(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_173_174_185(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_173_174_185([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_173_174_181(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_228_229_228([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_228_229_230(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_228_229_229([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_228_229_230([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_228_229_232(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_228_229_232([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_228_229_234(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_228_229_234([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_234;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_228_229_235(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_228_229_235([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_228_229_229(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_228_229_238(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_228_229_238([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_228_229_234(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_275_276_275([[maybe_unused]]RgCache& rgCache)
{
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_275_276_277(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_275_276_276([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_275_276_277([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_275_276_280(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_275_276_280([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_275_276_283(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_275_276_283([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_283;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_275_276_284(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_275_276_284([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_275_276_276(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_275_276_287(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_275_276_287([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_275_276_283(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_330_331_330([[maybe_unused]]RgCache& rgCache)
{
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_330_331_332(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_330_331_331([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_330_331_332([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_330_331_335(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_330_331_335([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_330_331_338(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_330_331_338([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_338;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_330_331_339(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_330_331_339([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_330_331_331(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_330_331_342(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_330_331_342([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_330_331_338(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_385_386_385([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_385_386_387(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_385_386_386([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_385_386_387([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_385_386_389(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_385_386_389([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_385_386_391(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_385_386_391([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_391;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_385_386_392(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_385_386_392([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_385_386_386(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_385_386_395(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_385_386_395([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_385_386_391(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_432_433_432([[maybe_unused]]RgCache& rgCache)
{
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_432_433_434(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_432_433_433([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_432_433_434([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_432_433_437(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_432_433_437([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_432_433_440(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_432_433_440([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_440;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_432_433_441(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_432_433_441([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_432_433_433(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_432_433_444(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_432_433_444([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_432_433_440(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_487_488_487([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_487_488_489(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_487_488_488([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_487_488_489([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_487_488_491(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_487_488_491([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_487_488_493(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_487_488_493([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_493;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_487_488_494(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_487_488_494([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_487_488_488(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_487_488_497(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_487_488_497([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_487_488_493(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_538_539_538([[maybe_unused]]RgCache& rgCache)
{
    const auto old4_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_538_539_540(rgCache))
    {
        coord = old4_0;
        return true;
    }    }
    coord = old4_0;
    return false;
}

bool GameState::is_legal_538_539_539([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_538_539_540([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_538_539_541(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_538_539_541([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_113.reset();
    rgCache.state_cache_17.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_44.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_73.reset();
    rgCache.state_cache_86.reset();
    const auto result_6 = is_legal_11_12_11(rgCache);
    rgCache.decDepth();
    if (result_6)
    {
        if (is_legal_538_539_539(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_548([[maybe_unused]]RgCache& rgCache)
{
    const auto old76_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    if (is_legal_548_549_550(rgCache))
    {
        coord = old76_0;
        return true;
    }    }
    coord = old76_0;
    return false;
}

bool GameState::is_legal_548_549_549([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_548_549_550([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (is_legal_548_549_551(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_551([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_548_549_553(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_548_549_580(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_548_549_622(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_548_549_649(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_548_549_634(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_548_549_592(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_548_549_607(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_548_549_565(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_553([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (is_legal_548_549_555(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_548_549_663(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_555([[maybe_unused]]RgCache& rgCache)
{
    const auto old78_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_548_549_557(rgCache))
    {
        coord = old78_0;
        return true;
    }
    coord = old78_0;
    return false;
}

bool GameState::is_legal_548_549_557([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_557;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_558(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_558([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_561(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_561([[maybe_unused]]RgCache& rgCache)
{
    const auto old166_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_548_549_557(rgCache))
    {
        coord = old166_0;
        return true;
    }
    coord = old166_0;
    return false;
}

bool GameState::is_legal_548_549_565([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==w)
    {
        if (is_legal_548_549_568(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_548_549_676(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_568([[maybe_unused]]RgCache& rgCache)
{
    const auto old82_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_548_549_571(rgCache))
    {
        coord = old82_0;
        return true;
    }
    coord = old82_0;
    return false;
}

bool GameState::is_legal_548_549_571([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_571;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_572(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_572([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_575(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_575([[maybe_unused]]RgCache& rgCache)
{
    const auto old167_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_548_549_571(rgCache))
    {
        coord = old167_0;
        return true;
    }
    coord = old167_0;
    return false;
}

bool GameState::is_legal_548_549_580([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (is_legal_548_549_582(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_548_549_690(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_582([[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_548_549_584(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::is_legal_548_549_584([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_584;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_585(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_585([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_588(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_588([[maybe_unused]]RgCache& rgCache)
{
    const auto old168_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_548_549_584(rgCache))
    {
        coord = old168_0;
        return true;
    }
    coord = old168_0;
    return false;
}

bool GameState::is_legal_548_549_592([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==w)
    {
        if (is_legal_548_549_595(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_548_549_703(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_595([[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_548_549_598(rgCache))
    {
        coord = old90_0;
        return true;
    }
    coord = old90_0;
    return false;
}

bool GameState::is_legal_548_549_598([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_598;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_599(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_599([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_602(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_602([[maybe_unused]]RgCache& rgCache)
{
    const auto old169_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_548_549_598(rgCache))
    {
        coord = old169_0;
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::is_legal_548_549_607([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==w)
    {
        if (is_legal_548_549_610(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_548_549_718(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_610([[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_548_549_613(rgCache))
    {
        coord = old94_0;
        return true;
    }
    coord = old94_0;
    return false;
}

bool GameState::is_legal_548_549_613([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_613;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_614(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_614([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_617(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_617([[maybe_unused]]RgCache& rgCache)
{
    const auto old170_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_548_549_613(rgCache))
    {
        coord = old170_0;
        return true;
    }
    coord = old170_0;
    return false;
}

bool GameState::is_legal_548_549_622([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (is_legal_548_549_624(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_548_549_732(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_624([[maybe_unused]]RgCache& rgCache)
{
    const auto old98_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_548_549_626(rgCache))
    {
        coord = old98_0;
        return true;
    }
    coord = old98_0;
    return false;
}

bool GameState::is_legal_548_549_626([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_626;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_627(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_627([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_630(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_630([[maybe_unused]]RgCache& rgCache)
{
    const auto old171_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_548_549_626(rgCache))
    {
        coord = old171_0;
        return true;
    }
    coord = old171_0;
    return false;
}

bool GameState::is_legal_548_549_634([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==w)
    {
        if (is_legal_548_549_637(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_548_549_745(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_637([[maybe_unused]]RgCache& rgCache)
{
    const auto old102_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_548_549_640(rgCache))
    {
        coord = old102_0;
        return true;
    }
    coord = old102_0;
    return false;
}

bool GameState::is_legal_548_549_640([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_640;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_641(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_641([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_644(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_644([[maybe_unused]]RgCache& rgCache)
{
    const auto old172_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_548_549_640(rgCache))
    {
        coord = old172_0;
        return true;
    }
    coord = old172_0;
    return false;
}

bool GameState::is_legal_548_549_649([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (is_legal_548_549_651(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_548_549_759(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_651([[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_548_549_653(rgCache))
    {
        coord = old106_0;
        return true;
    }
    coord = old106_0;
    return false;
}

bool GameState::is_legal_548_549_653([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_653;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_654(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_654([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_548_549_657(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_657([[maybe_unused]]RgCache& rgCache)
{
    const auto old173_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_548_549_653(rgCache))
    {
        coord = old173_0;
        return true;
    }
    coord = old173_0;
    return false;
}

bool GameState::is_legal_548_549_663([[maybe_unused]]RgCache& rgCache)
{
    const auto old110_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_548_549_665(rgCache))
    {
        coord = old110_0;
        return true;
    }
    coord = old110_0;
    return false;
}

bool GameState::is_legal_548_549_665([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_665;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_666(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_666([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_669(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_669([[maybe_unused]]RgCache& rgCache)
{
    const auto old174_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_548_549_665(rgCache))
    {
        coord = old174_0;
        return true;
    }
    coord = old174_0;
    return false;
}

bool GameState::is_legal_548_549_676([[maybe_unused]]RgCache& rgCache)
{
    const auto old114_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_548_549_679(rgCache))
    {
        coord = old114_0;
        return true;
    }
    coord = old114_0;
    return false;
}

bool GameState::is_legal_548_549_679([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_679;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_680(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_680([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_683(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_683([[maybe_unused]]RgCache& rgCache)
{
    const auto old175_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_548_549_679(rgCache))
    {
        coord = old175_0;
        return true;
    }
    coord = old175_0;
    return false;
}

bool GameState::is_legal_548_549_690([[maybe_unused]]RgCache& rgCache)
{
    const auto old118_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_548_549_692(rgCache))
    {
        coord = old118_0;
        return true;
    }
    coord = old118_0;
    return false;
}

bool GameState::is_legal_548_549_692([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_692;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_693(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_693([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_696(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_696([[maybe_unused]]RgCache& rgCache)
{
    const auto old176_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_548_549_692(rgCache))
    {
        coord = old176_0;
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::is_legal_548_549_703([[maybe_unused]]RgCache& rgCache)
{
    const auto old122_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_548_549_706(rgCache))
    {
        coord = old122_0;
        return true;
    }
    coord = old122_0;
    return false;
}

bool GameState::is_legal_548_549_706([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_706;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_707(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_707([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_710(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_710([[maybe_unused]]RgCache& rgCache)
{
    const auto old177_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_548_549_706(rgCache))
    {
        coord = old177_0;
        return true;
    }
    coord = old177_0;
    return false;
}

bool GameState::is_legal_548_549_718([[maybe_unused]]RgCache& rgCache)
{
    const auto old126_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_548_549_721(rgCache))
    {
        coord = old126_0;
        return true;
    }
    coord = old126_0;
    return false;
}

bool GameState::is_legal_548_549_721([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_721;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_722(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_722([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_725(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_725([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_548_549_721(rgCache))
    {
        coord = old178_0;
        return true;
    }
    coord = old178_0;
    return false;
}

bool GameState::is_legal_548_549_732([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_548_549_734(rgCache))
    {
        coord = old130_0;
        return true;
    }
    coord = old130_0;
    return false;
}

bool GameState::is_legal_548_549_734([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_734;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_735(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_735([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_738(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_738([[maybe_unused]]RgCache& rgCache)
{
    const auto old179_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_548_549_734(rgCache))
    {
        coord = old179_0;
        return true;
    }
    coord = old179_0;
    return false;
}

bool GameState::is_legal_548_549_745([[maybe_unused]]RgCache& rgCache)
{
    const auto old134_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_548_549_748(rgCache))
    {
        coord = old134_0;
        return true;
    }
    coord = old134_0;
    return false;
}

bool GameState::is_legal_548_549_748([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_748;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_749(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_749([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_752(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_752([[maybe_unused]]RgCache& rgCache)
{
    const auto old180_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_548_549_748(rgCache))
    {
        coord = old180_0;
        return true;
    }
    coord = old180_0;
    return false;
}

bool GameState::is_legal_548_549_759([[maybe_unused]]RgCache& rgCache)
{
    const auto old138_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_548_549_761(rgCache))
    {
        coord = old138_0;
        return true;
    }
    coord = old138_0;
    return false;
}

bool GameState::is_legal_548_549_761([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_761;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_548_549_762(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_548_549_762([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_548_549_549(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_548_549_765(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_548_549_765([[maybe_unused]]RgCache& rgCache)
{
    const auto old181_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_548_549_761(rgCache))
    {
        coord = old181_0;
        return true;
    }
    coord = old181_0;
    return false;
}

bool GameState::is_legal_770_790_770_770_790_790_770_790_770()
{
    if ((counters[w]>counters[b])==1)
    {
        if (is_legal_770_790_770_770_790_790_770_790_790())
        {
            return true;
        }
    }
    if ((counters[w]<counters[b])==1)
    {
        if (is_legal_770_790_770_770_790_790_770_790_790())
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (is_legal_770_790_770_770_790_790_770_790_790())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_770_790_770_770_790_790_770_790_790()
{
    return true;
}

bool GameState::is_legal_800_801_800([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_800_801_802(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_800_801_814(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_800_801_829(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_800_801_841(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_800_801_856(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_800_801_871(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_800_801_883(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_800_801_898(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_801([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_800_801_802([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_800_801_804(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_804([[maybe_unused]]RgCache& rgCache)
{
    const auto old44_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_800_801_806(rgCache))
    {
        coord = old44_0;
        return true;
    }
    coord = old44_0;
    return false;
}

bool GameState::is_legal_800_801_806([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_806;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_807(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_807([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_810(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_810([[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_800_801_806(rgCache))
    {
        coord = old90_0;
        return true;
    }
    coord = old90_0;
    return false;
}

bool GameState::is_legal_800_801_814([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_800_801_817(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_817([[maybe_unused]]RgCache& rgCache)
{
    const auto old50_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_800_801_820(rgCache))
    {
        coord = old50_0;
        return true;
    }
    coord = old50_0;
    return false;
}

bool GameState::is_legal_800_801_820([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_820;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_821(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_821([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_824(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_824([[maybe_unused]]RgCache& rgCache)
{
    const auto old91_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_800_801_820(rgCache))
    {
        coord = old91_0;
        return true;
    }
    coord = old91_0;
    return false;
}

bool GameState::is_legal_800_801_829([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_800_801_831(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_831([[maybe_unused]]RgCache& rgCache)
{
    const auto old56_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_800_801_833(rgCache))
    {
        coord = old56_0;
        return true;
    }
    coord = old56_0;
    return false;
}

bool GameState::is_legal_800_801_833([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_833;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_834(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_834([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_837(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_837([[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_800_801_833(rgCache))
    {
        coord = old92_0;
        return true;
    }
    coord = old92_0;
    return false;
}

bool GameState::is_legal_800_801_841([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_800_801_844(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_844([[maybe_unused]]RgCache& rgCache)
{
    const auto old62_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_800_801_847(rgCache))
    {
        coord = old62_0;
        return true;
    }
    coord = old62_0;
    return false;
}

bool GameState::is_legal_800_801_847([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_847;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_848(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_848([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_851(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_851([[maybe_unused]]RgCache& rgCache)
{
    const auto old93_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_800_801_847(rgCache))
    {
        coord = old93_0;
        return true;
    }
    coord = old93_0;
    return false;
}

bool GameState::is_legal_800_801_856([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_800_801_859(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_859([[maybe_unused]]RgCache& rgCache)
{
    const auto old68_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_800_801_862(rgCache))
    {
        coord = old68_0;
        return true;
    }
    coord = old68_0;
    return false;
}

bool GameState::is_legal_800_801_862([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_862;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_863(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_863([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_866(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_866([[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_800_801_862(rgCache))
    {
        coord = old94_0;
        return true;
    }
    coord = old94_0;
    return false;
}

bool GameState::is_legal_800_801_871([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_800_801_873(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_873([[maybe_unused]]RgCache& rgCache)
{
    const auto old74_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_800_801_875(rgCache))
    {
        coord = old74_0;
        return true;
    }
    coord = old74_0;
    return false;
}

bool GameState::is_legal_800_801_875([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_875;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_876(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_876([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_879(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_879([[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_800_801_875(rgCache))
    {
        coord = old95_0;
        return true;
    }
    coord = old95_0;
    return false;
}

bool GameState::is_legal_800_801_883([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_800_801_886(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_886([[maybe_unused]]RgCache& rgCache)
{
    const auto old80_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_800_801_889(rgCache))
    {
        coord = old80_0;
        return true;
    }
    coord = old80_0;
    return false;
}

bool GameState::is_legal_800_801_889([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_889;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_890(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_890([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_893(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_893([[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_800_801_889(rgCache))
    {
        coord = old96_0;
        return true;
    }
    coord = old96_0;
    return false;
}

bool GameState::is_legal_800_801_898([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_800_801_900(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_900([[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_800_801_902(rgCache))
    {
        coord = old86_0;
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::is_legal_800_801_902([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_902;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_800_801_903(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_800_801_903([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_800_801_801(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_800_801_906(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_800_801_906([[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_800_801_902(rgCache))
    {
        coord = old97_0;
        return true;
    }
    coord = old97_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1002([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1002;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_991(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1003([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1003;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old124_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1006(rgCache))
    {
        coord = old124_0;
        return true;
    }
    coord = old124_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1006([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1006;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1007(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1007([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1007;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_960(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1015([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1072.reset();
    const auto result_127 = is_legal_1064_1065_1064(rgCache);
    rgCache.decDepth();
    if (!result_127)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1062(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1081(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1031([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1033(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1033([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1035(rgCache))
    {
        counters[static_cast<Piece>(b)] = old130_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old130_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1034([[maybe_unused]]RgCache& rgCache)
{
    const auto old131_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1040(rgCache))
    {
        coord = old131_0;
        return true;
    }
    coord = old131_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1035([[maybe_unused]]RgCache& rgCache)
{
    const auto old132_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1036(rgCache))
    {
        counters[w] = old132_0;
        return true;
    }
    counters[w] = old132_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1036([[maybe_unused]]RgCache& rgCache)
{
    const auto old133_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1034(rgCache))
    {
        board[RbgCoordMap2[coord]] = old133_0;
        return true;
    }
    board[RbgCoordMap2[coord]] = old133_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1040([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1040;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1041(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1041([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1041;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1044(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1044([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1044;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old137_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1046(rgCache))
    {
        counters[static_cast<Piece>(b)] = old137_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old137_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1045([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1045;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old253_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1040(rgCache))
    {
        coord = old253_0;
        return true;
    }
    coord = old253_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1046([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1046;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old138_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1047(rgCache))
    {
        counters[w] = old138_0;
        return true;
    }
    counters[w] = old138_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1047([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1047;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old139_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1045(rgCache))
    {
        board[coord] = old139_0;
        return true;
    }
    board[coord] = old139_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1052([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1052;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old140_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1054(rgCache))
    {
        coord = old140_0;
        return true;
    }
    coord = old140_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1054([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1054;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1055(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1055([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1055;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1015(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1062([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1127.reset();
    const auto result_143 = is_legal_1119_1120_1119(rgCache);
    rgCache.decDepth();
    if (!result_143)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1117(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1136(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1081([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1084(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1084([[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1086(rgCache))
    {
        counters[static_cast<Piece>(b)] = old146_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old146_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1085([[maybe_unused]]RgCache& rgCache)
{
    const auto old147_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1092(rgCache))
    {
        coord = old147_0;
        return true;
    }
    coord = old147_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1086([[maybe_unused]]RgCache& rgCache)
{
    const auto old148_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1087(rgCache))
    {
        counters[w] = old148_0;
        return true;
    }
    counters[w] = old148_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1087([[maybe_unused]]RgCache& rgCache)
{
    const auto old149_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1085(rgCache))
    {
        board[direction_left[coord - 1]] = old149_0;
        return true;
    }
    board[direction_left[coord - 1]] = old149_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1092([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1092;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1093(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1093([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1093;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1096(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1096([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1096;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old153_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1098(rgCache))
    {
        counters[static_cast<Piece>(b)] = old153_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old153_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1097([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1097;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old254_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1092(rgCache))
    {
        coord = old254_0;
        return true;
    }
    coord = old254_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1098([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1098;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old154_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1099(rgCache))
    {
        counters[w] = old154_0;
        return true;
    }
    counters[w] = old154_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1099([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1099;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old155_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1097(rgCache))
    {
        board[coord] = old155_0;
        return true;
    }
    board[coord] = old155_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1105([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1105;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old156_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1108(rgCache))
    {
        coord = old156_0;
        return true;
    }
    coord = old156_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1108([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1108;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1109(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1109([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1109;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1062(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1117([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1180.reset();
    const auto result_159 = is_legal_1174_1175_1174(rgCache);
    rgCache.decDepth();
    if (!result_159)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1172(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1136([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1139(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1139([[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1141(rgCache))
    {
        counters[static_cast<Piece>(b)] = old162_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old162_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1140([[maybe_unused]]RgCache& rgCache)
{
    const auto old163_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1147(rgCache))
    {
        coord = old163_0;
        return true;
    }
    coord = old163_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1141([[maybe_unused]]RgCache& rgCache)
{
    const auto old164_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1142(rgCache))
    {
        counters[w] = old164_0;
        return true;
    }
    counters[w] = old164_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1142([[maybe_unused]]RgCache& rgCache)
{
    const auto old165_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1140(rgCache))
    {
        board[direction_right[coord - 1]] = old165_0;
        return true;
    }
    board[direction_right[coord - 1]] = old165_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1147([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1147;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1148(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1148([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1148;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1151([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1151;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1153(rgCache))
    {
        counters[static_cast<Piece>(b)] = old169_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old169_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1152([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1152;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old255_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1147(rgCache))
    {
        coord = old255_0;
        return true;
    }
    coord = old255_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1153([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1153;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old170_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1154(rgCache))
    {
        counters[w] = old170_0;
        return true;
    }
    counters[w] = old170_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1154([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1154;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old171_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1152(rgCache))
    {
        board[coord] = old171_0;
        return true;
    }
    board[coord] = old171_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1160([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1160;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old172_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1163(rgCache))
    {
        coord = old172_0;
        return true;
    }
    coord = old172_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1117(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1172([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1229.reset();
    const auto result_175 = is_legal_1221_1222_1221(rgCache);
    rgCache.decDepth();
    if (!result_175)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1219(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1238(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1188([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1190([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1192(rgCache))
    {
        counters[static_cast<Piece>(b)] = old178_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old178_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1191([[maybe_unused]]RgCache& rgCache)
{
    const auto old179_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1197(rgCache))
    {
        coord = old179_0;
        return true;
    }
    coord = old179_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1192([[maybe_unused]]RgCache& rgCache)
{
    const auto old180_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1193(rgCache))
    {
        counters[w] = old180_0;
        return true;
    }
    counters[w] = old180_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1193([[maybe_unused]]RgCache& rgCache)
{
    const auto old181_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1191(rgCache))
    {
        board[RbgCoordMap3[coord]] = old181_0;
        return true;
    }
    board[RbgCoordMap3[coord]] = old181_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1197([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1197;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1198(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1198([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1198;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1201(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old185_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1203(rgCache))
    {
        counters[static_cast<Piece>(b)] = old185_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old185_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old256_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1197(rgCache))
    {
        coord = old256_0;
        return true;
    }
    coord = old256_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1203([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1203;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old186_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1204(rgCache))
    {
        counters[w] = old186_0;
        return true;
    }
    counters[w] = old186_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1204([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1204;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old187_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1202(rgCache))
    {
        board[coord] = old187_0;
        return true;
    }
    board[coord] = old187_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1209([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1209;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old188_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1211(rgCache))
    {
        coord = old188_0;
        return true;
    }
    coord = old188_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1211([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1211;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1212(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1212([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1212;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1172(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1219([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1282.reset();
    const auto result_191 = is_legal_1276_1277_1276(rgCache);
    rgCache.decDepth();
    if (!result_191)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1323(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1290(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1238([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1241(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1241([[maybe_unused]]RgCache& rgCache)
{
    const auto old194_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1243(rgCache))
    {
        counters[static_cast<Piece>(b)] = old194_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old194_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1242([[maybe_unused]]RgCache& rgCache)
{
    const auto old195_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1249(rgCache))
    {
        coord = old195_0;
        return true;
    }
    coord = old195_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1243([[maybe_unused]]RgCache& rgCache)
{
    const auto old196_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1244(rgCache))
    {
        counters[w] = old196_0;
        return true;
    }
    counters[w] = old196_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1244([[maybe_unused]]RgCache& rgCache)
{
    const auto old197_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1242(rgCache))
    {
        board[direction_down[coord - 1]] = old197_0;
        return true;
    }
    board[direction_down[coord - 1]] = old197_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1249([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1249;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1250(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1250([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1250;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1253(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1253([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1253;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old201_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1255(rgCache))
    {
        counters[static_cast<Piece>(b)] = old201_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old201_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1254([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1254;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old257_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1249(rgCache))
    {
        coord = old257_0;
        return true;
    }
    coord = old257_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old202_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1256(rgCache))
    {
        counters[w] = old202_0;
        return true;
    }
    counters[w] = old202_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old203_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1254(rgCache))
    {
        board[coord] = old203_0;
        return true;
    }
    board[coord] = old203_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1262([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1262;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old204_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1265(rgCache))
    {
        coord = old204_0;
        return true;
    }
    coord = old204_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1219(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1290([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1292([[maybe_unused]]RgCache& rgCache)
{
    const auto old209_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1294(rgCache))
    {
        counters[static_cast<Piece>(b)] = old209_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old209_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1293([[maybe_unused]]RgCache& rgCache)
{
    const auto old210_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1299(rgCache))
    {
        coord = old210_0;
        return true;
    }
    coord = old210_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1294([[maybe_unused]]RgCache& rgCache)
{
    const auto old211_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1295(rgCache))
    {
        counters[w] = old211_0;
        return true;
    }
    counters[w] = old211_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1295([[maybe_unused]]RgCache& rgCache)
{
    const auto old212_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1293(rgCache))
    {
        board[RbgCoordMap4[coord]] = old212_0;
        return true;
    }
    board[RbgCoordMap4[coord]] = old212_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1299([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1299;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1300(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1300([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1300;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1303(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old216_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1305(rgCache))
    {
        counters[static_cast<Piece>(b)] = old216_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old216_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old258_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1299(rgCache))
    {
        coord = old258_0;
        return true;
    }
    coord = old258_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1305([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1305;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old217_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1306(rgCache))
    {
        counters[w] = old217_0;
        return true;
    }
    counters[w] = old217_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1306([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1306;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old218_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1304(rgCache))
    {
        board[coord] = old218_0;
        return true;
    }
    board[coord] = old218_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1311([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1311;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old219_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1313(rgCache))
    {
        coord = old219_0;
        return true;
    }
    coord = old219_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1313([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1313;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1314(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1314([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_1314;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1323(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1323([[maybe_unused]]RgCache& rgCache)
{
    const auto old222_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_796(rgCache))
    {
        board[coord] = old222_0;
        return true;
    }
    board[coord] = old222_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_1560([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_796([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1346.reset();
    rgCache.state_cache_1360.reset();
    rgCache.state_cache_1373.reset();
    rgCache.state_cache_1387.reset();
    rgCache.state_cache_1402.reset();
    rgCache.state_cache_1415.reset();
    rgCache.state_cache_1429.reset();
    rgCache.state_cache_1442.reset();
    rgCache.state_cache_1454.reset();
    rgCache.state_cache_1468.reset();
    rgCache.state_cache_1481.reset();
    rgCache.state_cache_1495.reset();
    rgCache.state_cache_1510.reset();
    rgCache.state_cache_1523.reset();
    rgCache.state_cache_1537.reset();
    rgCache.state_cache_1550.reset();
    const auto result_223 = is_legal_1337_1338_1337(rgCache);
    rgCache.decDepth();
    if (!result_223)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1560(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_910([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_921.reset();
    const auto result_224 = is_legal_915_916_915(rgCache);
    rgCache.decDepth();
    if (!result_224)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_913(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_929(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_913([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_970.reset();
    const auto result_225 = is_legal_962_963_962(rgCache);
    rgCache.decDepth();
    if (!result_225)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_960(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_979(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_929([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_931(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_931([[maybe_unused]]RgCache& rgCache)
{
    const auto old228_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_933(rgCache))
    {
        counters[static_cast<Piece>(b)] = old228_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old228_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_932([[maybe_unused]]RgCache& rgCache)
{
    const auto old229_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_938(rgCache))
    {
        coord = old229_0;
        return true;
    }
    coord = old229_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_933([[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_934(rgCache))
    {
        counters[w] = old230_0;
        return true;
    }
    counters[w] = old230_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_934([[maybe_unused]]RgCache& rgCache)
{
    const auto old231_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_932(rgCache))
    {
        board[RbgCoordMap1[coord]] = old231_0;
        return true;
    }
    board[RbgCoordMap1[coord]] = old231_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_938([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_938;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_939(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_939([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_942(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_942([[maybe_unused]]RgCache& rgCache)
{
    const auto old235_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_944(rgCache))
    {
        counters[static_cast<Piece>(b)] = old235_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old235_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_943([[maybe_unused]]RgCache& rgCache)
{
    const auto old259_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_938(rgCache))
    {
        coord = old259_0;
        return true;
    }
    coord = old259_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_944([[maybe_unused]]RgCache& rgCache)
{
    const auto old236_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_945(rgCache))
    {
        counters[w] = old236_0;
        return true;
    }
    counters[w] = old236_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_945([[maybe_unused]]RgCache& rgCache)
{
    const auto old237_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_943(rgCache))
    {
        board[coord] = old237_0;
        return true;
    }
    board[coord] = old237_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_950([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_950;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old238_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_952(rgCache))
    {
        coord = old238_0;
        return true;
    }
    coord = old238_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_952([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_952;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_953(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_953([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_953;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_913(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_960([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1031(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_1023.reset();
    const auto result_241 = is_legal_1017_1018_1017(rgCache);
    rgCache.decDepth();
    if (!result_241)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1015(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_979([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_982(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_982([[maybe_unused]]RgCache& rgCache)
{
    const auto old244_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_984(rgCache))
    {
        counters[static_cast<Piece>(b)] = old244_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old244_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_983([[maybe_unused]]RgCache& rgCache)
{
    const auto old260_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1002(rgCache))
    {
        coord = old260_0;
        return true;
    }
    coord = old260_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_984([[maybe_unused]]RgCache& rgCache)
{
    const auto old245_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_985(rgCache))
    {
        counters[w] = old245_0;
        return true;
    }
    counters[w] = old245_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_985([[maybe_unused]]RgCache& rgCache)
{
    const auto old246_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_983(rgCache))
    {
        board[direction_up[coord - 1]] = old246_0;
        return true;
    }
    board[direction_up[coord - 1]] = old246_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_991([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_991;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_910_1560_910_910_1560_1560_910_1560_994(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_994([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_994;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old249_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_996(rgCache))
    {
        counters[static_cast<Piece>(b)] = old249_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old249_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_995([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_995;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old250_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_910_1560_910_910_1560_1560_910_1560_1002(rgCache))
    {
        coord = old250_0;
        return true;
    }
    coord = old250_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_996([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_996;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old251_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_997(rgCache))
    {
        counters[w] = old251_0;
        return true;
    }
    counters[w] = old251_0;
    return false;
}

bool GameState::is_legal_910_1560_910_910_1560_1560_910_1560_997([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_1560_997;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old252_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_1560_910_910_1560_1560_910_1560_995(rgCache))
    {
        board[coord] = old252_0;
        return true;
    }
    board[coord] = old252_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1002([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1002;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_991(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1003([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1003;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old124_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1006(rgCache))
    {
        coord = old124_0;
        return true;
    }
    coord = old124_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1006([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1006;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1007(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1007([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1007;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_960(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1015([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1072.reset();
    const auto result_127 = is_legal_1064_1065_1064(rgCache);
    rgCache.decDepth();
    if (!result_127)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1062(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1081(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1031([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1033(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1033([[maybe_unused]]RgCache& rgCache)
{
    const auto old130_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1035(rgCache))
    {
        counters[static_cast<Piece>(b)] = old130_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old130_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1034([[maybe_unused]]RgCache& rgCache)
{
    const auto old131_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1040(rgCache))
    {
        coord = old131_0;
        return true;
    }
    coord = old131_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1035([[maybe_unused]]RgCache& rgCache)
{
    const auto old132_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1036(rgCache))
    {
        counters[w] = old132_0;
        return true;
    }
    counters[w] = old132_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1036([[maybe_unused]]RgCache& rgCache)
{
    const auto old133_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1034(rgCache))
    {
        board[RbgCoordMap2[coord]] = old133_0;
        return true;
    }
    board[RbgCoordMap2[coord]] = old133_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1040([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1040;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1041(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1041([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1041;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1044(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1044([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1044;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old137_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1046(rgCache))
    {
        counters[static_cast<Piece>(b)] = old137_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old137_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1045([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1045;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old253_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1040(rgCache))
    {
        coord = old253_0;
        return true;
    }
    coord = old253_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1046([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1046;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old138_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1047(rgCache))
    {
        counters[w] = old138_0;
        return true;
    }
    counters[w] = old138_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1047([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1047;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old139_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1045(rgCache))
    {
        board[coord] = old139_0;
        return true;
    }
    board[coord] = old139_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1052([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1052;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old140_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1054(rgCache))
    {
        coord = old140_0;
        return true;
    }
    coord = old140_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1054([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1054;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1055(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1055([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1055;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1015(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1062([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1127.reset();
    const auto result_143 = is_legal_1119_1120_1119(rgCache);
    rgCache.decDepth();
    if (!result_143)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1117(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1136(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1081([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_left[coord - 1]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1084(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1084([[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1086(rgCache))
    {
        counters[static_cast<Piece>(b)] = old146_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old146_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1085([[maybe_unused]]RgCache& rgCache)
{
    const auto old147_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1092(rgCache))
    {
        coord = old147_0;
        return true;
    }
    coord = old147_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1086([[maybe_unused]]RgCache& rgCache)
{
    const auto old148_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1087(rgCache))
    {
        counters[w] = old148_0;
        return true;
    }
    counters[w] = old148_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1087([[maybe_unused]]RgCache& rgCache)
{
    const auto old149_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1085(rgCache))
    {
        board[direction_left[coord - 1]] = old149_0;
        return true;
    }
    board[direction_left[coord - 1]] = old149_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1092([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1092;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1093(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1093([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1093;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1096(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1096([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1096;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old153_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1098(rgCache))
    {
        counters[static_cast<Piece>(b)] = old153_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old153_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1097([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1097;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old254_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1092(rgCache))
    {
        coord = old254_0;
        return true;
    }
    coord = old254_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1098([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1098;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old154_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1099(rgCache))
    {
        counters[w] = old154_0;
        return true;
    }
    counters[w] = old154_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1099([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1099;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old155_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1097(rgCache))
    {
        board[coord] = old155_0;
        return true;
    }
    board[coord] = old155_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1105([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1105;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old156_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1108(rgCache))
    {
        coord = old156_0;
        return true;
    }
    coord = old156_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1108([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1108;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1109(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1109([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1109;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1062(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1117([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1180.reset();
    const auto result_159 = is_legal_1174_1175_1174(rgCache);
    rgCache.decDepth();
    if (!result_159)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1172(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1136([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_right[coord - 1]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1139(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1139([[maybe_unused]]RgCache& rgCache)
{
    const auto old162_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1141(rgCache))
    {
        counters[static_cast<Piece>(b)] = old162_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old162_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1140([[maybe_unused]]RgCache& rgCache)
{
    const auto old163_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1147(rgCache))
    {
        coord = old163_0;
        return true;
    }
    coord = old163_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1141([[maybe_unused]]RgCache& rgCache)
{
    const auto old164_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1142(rgCache))
    {
        counters[w] = old164_0;
        return true;
    }
    counters[w] = old164_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1142([[maybe_unused]]RgCache& rgCache)
{
    const auto old165_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1140(rgCache))
    {
        board[direction_right[coord - 1]] = old165_0;
        return true;
    }
    board[direction_right[coord - 1]] = old165_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1147([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1147;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1148(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1148([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1148;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1151([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1151;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1153(rgCache))
    {
        counters[static_cast<Piece>(b)] = old169_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old169_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1152([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1152;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old255_0 = coord;
    coord = direction_right[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1147(rgCache))
    {
        coord = old255_0;
        return true;
    }
    coord = old255_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1153([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1153;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old170_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1154(rgCache))
    {
        counters[w] = old170_0;
        return true;
    }
    counters[w] = old170_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1154([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1154;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old171_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1152(rgCache))
    {
        board[coord] = old171_0;
        return true;
    }
    board[coord] = old171_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1160([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1160;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old172_0 = coord;
    coord = direction_left[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1163(rgCache))
    {
        coord = old172_0;
        return true;
    }
    coord = old172_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1117(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1172([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1229.reset();
    const auto result_175 = is_legal_1221_1222_1221(rgCache);
    rgCache.decDepth();
    if (!result_175)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1219(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1238(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1188([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1190([[maybe_unused]]RgCache& rgCache)
{
    const auto old178_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1192(rgCache))
    {
        counters[static_cast<Piece>(b)] = old178_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old178_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1191([[maybe_unused]]RgCache& rgCache)
{
    const auto old179_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1197(rgCache))
    {
        coord = old179_0;
        return true;
    }
    coord = old179_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1192([[maybe_unused]]RgCache& rgCache)
{
    const auto old180_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1193(rgCache))
    {
        counters[w] = old180_0;
        return true;
    }
    counters[w] = old180_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1193([[maybe_unused]]RgCache& rgCache)
{
    const auto old181_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1191(rgCache))
    {
        board[RbgCoordMap3[coord]] = old181_0;
        return true;
    }
    board[RbgCoordMap3[coord]] = old181_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1197([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1197;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1198(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1198([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1198;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1201(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old185_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1203(rgCache))
    {
        counters[static_cast<Piece>(b)] = old185_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old185_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old256_0 = coord;
    coord = RbgCoordMap3[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1197(rgCache))
    {
        coord = old256_0;
        return true;
    }
    coord = old256_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1203([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1203;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old186_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1204(rgCache))
    {
        counters[w] = old186_0;
        return true;
    }
    counters[w] = old186_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1204([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1204;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old187_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1202(rgCache))
    {
        board[coord] = old187_0;
        return true;
    }
    board[coord] = old187_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1209([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1209;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old188_0 = coord;
    coord = RbgCoordMap2[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1211(rgCache))
    {
        coord = old188_0;
        return true;
    }
    coord = old188_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1211([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1211;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1212(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1212([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1212;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1172(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1219([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1282.reset();
    const auto result_191 = is_legal_1276_1277_1276(rgCache);
    rgCache.decDepth();
    if (!result_191)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1323(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1290(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1238([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_down[coord - 1]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1241(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1241([[maybe_unused]]RgCache& rgCache)
{
    const auto old194_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1243(rgCache))
    {
        counters[static_cast<Piece>(b)] = old194_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old194_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1242([[maybe_unused]]RgCache& rgCache)
{
    const auto old195_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1249(rgCache))
    {
        coord = old195_0;
        return true;
    }
    coord = old195_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1243([[maybe_unused]]RgCache& rgCache)
{
    const auto old196_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1244(rgCache))
    {
        counters[w] = old196_0;
        return true;
    }
    counters[w] = old196_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1244([[maybe_unused]]RgCache& rgCache)
{
    const auto old197_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1242(rgCache))
    {
        board[direction_down[coord - 1]] = old197_0;
        return true;
    }
    board[direction_down[coord - 1]] = old197_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1249([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1249;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1250(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1250([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1250;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1253(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1253([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1253;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old201_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1255(rgCache))
    {
        counters[static_cast<Piece>(b)] = old201_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old201_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1254([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1254;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old257_0 = coord;
    coord = direction_down[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1249(rgCache))
    {
        coord = old257_0;
        return true;
    }
    coord = old257_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old202_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1256(rgCache))
    {
        counters[w] = old202_0;
        return true;
    }
    counters[w] = old202_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old203_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1254(rgCache))
    {
        board[coord] = old203_0;
        return true;
    }
    board[coord] = old203_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1262([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1262;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old204_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1265(rgCache))
    {
        coord = old204_0;
        return true;
    }
    coord = old204_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1219(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1290([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1292([[maybe_unused]]RgCache& rgCache)
{
    const auto old209_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1294(rgCache))
    {
        counters[static_cast<Piece>(b)] = old209_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old209_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1293([[maybe_unused]]RgCache& rgCache)
{
    const auto old210_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1299(rgCache))
    {
        coord = old210_0;
        return true;
    }
    coord = old210_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1294([[maybe_unused]]RgCache& rgCache)
{
    const auto old211_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1295(rgCache))
    {
        counters[w] = old211_0;
        return true;
    }
    counters[w] = old211_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1295([[maybe_unused]]RgCache& rgCache)
{
    const auto old212_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1293(rgCache))
    {
        board[RbgCoordMap4[coord]] = old212_0;
        return true;
    }
    board[RbgCoordMap4[coord]] = old212_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1299([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1299;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1300(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1300([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1300;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1303(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old216_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_1305(rgCache))
    {
        counters[static_cast<Piece>(b)] = old216_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old216_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old258_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1299(rgCache))
    {
        coord = old258_0;
        return true;
    }
    coord = old258_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1305([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1305;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old217_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_1306(rgCache))
    {
        counters[w] = old217_0;
        return true;
    }
    counters[w] = old217_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1306([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1306;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old218_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_1304(rgCache))
    {
        board[coord] = old218_0;
        return true;
    }
    board[coord] = old218_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1311([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1311;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old219_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_910_5_910_910_5_5_910_5_1313(rgCache))
    {
        coord = old219_0;
        return true;
    }
    coord = old219_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1313([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1313;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1314(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1314([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_1314;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1323(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_1323([[maybe_unused]]RgCache& rgCache)
{
    const auto old222_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_796(rgCache))
    {
        board[coord] = old222_0;
        return true;
    }
    board[coord] = old222_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_5([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_796([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_1346.reset();
    rgCache.state_cache_1360.reset();
    rgCache.state_cache_1373.reset();
    rgCache.state_cache_1387.reset();
    rgCache.state_cache_1402.reset();
    rgCache.state_cache_1415.reset();
    rgCache.state_cache_1429.reset();
    rgCache.state_cache_1442.reset();
    rgCache.state_cache_1454.reset();
    rgCache.state_cache_1468.reset();
    rgCache.state_cache_1481.reset();
    rgCache.state_cache_1495.reset();
    rgCache.state_cache_1510.reset();
    rgCache.state_cache_1523.reset();
    rgCache.state_cache_1537.reset();
    rgCache.state_cache_1550.reset();
    const auto result_223 = is_legal_1337_1338_1337(rgCache);
    rgCache.decDepth();
    if (result_223)
    {
        if (is_legal_910_5_910_910_5_5_910_5_5(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_910([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_921.reset();
    const auto result_224 = is_legal_915_916_915(rgCache);
    rgCache.decDepth();
    if (!result_224)
    {
        if (is_legal_910_5_910_910_5_5_910_5_913(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_929(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_913([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_970.reset();
    const auto result_225 = is_legal_962_963_962(rgCache);
    rgCache.decDepth();
    if (!result_225)
    {
        if (is_legal_910_5_910_910_5_5_910_5_960(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_979(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_929([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_931(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_931([[maybe_unused]]RgCache& rgCache)
{
    const auto old228_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_933(rgCache))
    {
        counters[static_cast<Piece>(b)] = old228_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old228_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_932([[maybe_unused]]RgCache& rgCache)
{
    const auto old229_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_910_5_910_910_5_5_910_5_938(rgCache))
    {
        coord = old229_0;
        return true;
    }
    coord = old229_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_933([[maybe_unused]]RgCache& rgCache)
{
    const auto old230_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_934(rgCache))
    {
        counters[w] = old230_0;
        return true;
    }
    counters[w] = old230_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_934([[maybe_unused]]RgCache& rgCache)
{
    const auto old231_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_932(rgCache))
    {
        board[RbgCoordMap1[coord]] = old231_0;
        return true;
    }
    board[RbgCoordMap1[coord]] = old231_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_938([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_938;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_939(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_939([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_942(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_942([[maybe_unused]]RgCache& rgCache)
{
    const auto old235_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_944(rgCache))
    {
        counters[static_cast<Piece>(b)] = old235_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old235_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_943([[maybe_unused]]RgCache& rgCache)
{
    const auto old259_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_910_5_910_910_5_5_910_5_938(rgCache))
    {
        coord = old259_0;
        return true;
    }
    coord = old259_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_944([[maybe_unused]]RgCache& rgCache)
{
    const auto old236_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_945(rgCache))
    {
        counters[w] = old236_0;
        return true;
    }
    counters[w] = old236_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_945([[maybe_unused]]RgCache& rgCache)
{
    const auto old237_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_943(rgCache))
    {
        board[coord] = old237_0;
        return true;
    }
    board[coord] = old237_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_950([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_950;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old238_0 = coord;
    coord = RbgCoordMap4[coord];
    if (is_legal_910_5_910_910_5_5_910_5_952(rgCache))
    {
        coord = old238_0;
        return true;
    }
    coord = old238_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_952([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_952;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_953(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_953([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_953;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (is_legal_910_5_910_910_5_5_910_5_913(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_960([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap2[coord]!=null)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1031(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_1023.reset();
    const auto result_241 = is_legal_1017_1018_1017(rgCache);
    rgCache.decDepth();
    if (!result_241)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1015(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_979([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_982(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_982([[maybe_unused]]RgCache& rgCache)
{
    const auto old244_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_984(rgCache))
    {
        counters[static_cast<Piece>(b)] = old244_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old244_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_983([[maybe_unused]]RgCache& rgCache)
{
    const auto old260_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1002(rgCache))
    {
        coord = old260_0;
        return true;
    }
    coord = old260_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_984([[maybe_unused]]RgCache& rgCache)
{
    const auto old245_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_985(rgCache))
    {
        counters[w] = old245_0;
        return true;
    }
    counters[w] = old245_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_985([[maybe_unused]]RgCache& rgCache)
{
    const auto old246_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = w;
    if (is_legal_910_5_910_910_5_5_910_5_983(rgCache))
    {
        board[direction_up[coord - 1]] = old246_0;
        return true;
    }
    board[direction_up[coord - 1]] = old246_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_991([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_991;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (is_legal_910_5_910_910_5_5_910_5_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_910_5_910_910_5_5_910_5_994(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_994([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_994;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old249_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (is_legal_910_5_910_910_5_5_910_5_996(rgCache))
    {
        counters[static_cast<Piece>(b)] = old249_0;
        return true;
    }
    counters[static_cast<Piece>(b)] = old249_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_995([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_995;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old250_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_910_5_910_910_5_5_910_5_1002(rgCache))
    {
        coord = old250_0;
        return true;
    }
    coord = old250_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_996([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_996;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old251_0 = counters[w];
    counters[w] = counters[w]+1;
    if (is_legal_910_5_910_910_5_5_910_5_997(rgCache))
    {
        counters[w] = old251_0;
        return true;
    }
    counters[w] = old251_0;
    return false;
}

bool GameState::is_legal_910_5_910_910_5_5_910_5_997([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_910_5_997;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old252_0 = board[coord];
    board[coord] = w;
    if (is_legal_910_5_910_910_5_5_910_5_995(rgCache))
    {
        board[coord] = old252_0;
        return true;
    }
    board[coord] = old252_0;
    return false;
}

bool GameState::is_legal_915_916_915([[maybe_unused]]RgCache& rgCache)
{
    if (RbgCoordMap1[coord]!=null)
    {
        if (is_legal_915_916_917(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_915_916_916([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_915_916_917([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (is_legal_915_916_919(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_915_916_919([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (is_legal_915_916_921(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_915_916_921([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_921;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_915_916_922(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_915_916_922([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_915_916_916(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_915_916_925(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_915_916_925([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = RbgCoordMap1[coord];
    if (is_legal_915_916_921(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

bool GameState::is_legal_962_963_962([[maybe_unused]]RgCache& rgCache)
{
    if (direction_up[coord - 1]!=null)
    {
        if (is_legal_962_963_964(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_962_963_963([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::is_legal_962_963_964([[maybe_unused]]RgCache& rgCache)
{
    if (board[direction_up[coord - 1]]==b)
    {
        if (is_legal_962_963_967(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_962_963_967([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (is_legal_962_963_970(rgCache))
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_962_963_970([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_970;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (is_legal_962_963_971(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_962_963_971([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (is_legal_962_963_963(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (is_legal_962_963_974(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::is_legal_962_963_974([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = coord;
    coord = direction_up[coord - 1];
    if (is_legal_962_963_970(rgCache))
    {
        coord = old13_0;
        return true;
    }
    coord = old13_0;
    return false;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_123(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_1002([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1002;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_991(moves, mr,rgCache);
    }
}

void GameState::state_1003([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1003;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1159_0 = coord;
    coord = direction_down[coord - 1];
    state_1006(moves, mr,rgCache);
    coord = old1159_0;
}

void GameState::state_1006([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1006;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1007(moves, mr,rgCache);
    }
}

void GameState::state_1007([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1007;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_1003(moves, mr,rgCache);
        return;
    }
    if (board[coord]==e)
    {
        state_960(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1015([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1015;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1072.reset();
    const auto result_1163 = is_legal_1064_1065_1064(rgCache);
    rgCache.decDepth();
    if (!result_1163)
    {
        state_1062(moves, mr,rgCache);
    }
    if (direction_left[coord - 1]!=null)
    {
        state_1081(moves, mr,rgCache);
    }
}

void GameState::state_1031([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1031;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==b)
    {
        state_1033(moves, mr,rgCache);
    }
}

void GameState::state_1033([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1033;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1173_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1035(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1173_0;
}

void GameState::state_1034([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1034;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1174_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    state_1040(moves, mr,rgCache);
    coord = old1174_0;
}

void GameState::state_1035([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1035;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1175_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1036(moves, mr,rgCache);
    counters[w] = old1175_0;
}

void GameState::state_1036([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1036;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1176_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = w;
    state_1034(moves, mr,rgCache);
    board[RbgCoordMap2[coord]] = old1176_0;
}

void GameState::state_1040([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1040;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1041(moves, mr,rgCache);
    }
}

void GameState::state_1041([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1041;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1044(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1052(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1044([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1044;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1180_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1046(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1180_0;
}

void GameState::state_1045([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1045;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2380_0 = coord;
    coord = RbgCoordMap2[coord];
    state_1040(moves, mr,rgCache);
    coord = old2380_0;
}

void GameState::state_1046([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1046;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1181_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1047(moves, mr,rgCache);
    counters[w] = old1181_0;
}

void GameState::state_1047([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1047;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1182_0 = board[coord];
    board[coord] = w;
    state_1045(moves, mr,rgCache);
    board[coord] = old1182_0;
}

void GameState::state_1052([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1052;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1183_0 = coord;
    coord = RbgCoordMap3[coord];
    state_1054(moves, mr,rgCache);
    coord = old1183_0;
}

void GameState::state_1054([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1054;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1055(moves, mr,rgCache);
    }
}

void GameState::state_1055([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1055;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1015(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1052(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1062([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1062;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1127.reset();
    const auto result_1186 = is_legal_1119_1120_1119(rgCache);
    rgCache.decDepth();
    if (!result_1186)
    {
        state_1117(moves, mr,rgCache);
    }
    if (direction_right[coord - 1]!=null)
    {
        state_1136(moves, mr,rgCache);
    }
}

void GameState::state_1081([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1081;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==b)
    {
        state_1084(moves, mr,rgCache);
    }
}

void GameState::state_1084([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1084;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1195_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1086(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1195_0;
}

void GameState::state_1085([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1085;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1196_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    state_1092(moves, mr,rgCache);
    coord = old1196_0;
}

void GameState::state_1086([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1086;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1197_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1087(moves, mr,rgCache);
    counters[w] = old1197_0;
}

void GameState::state_1087([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1087;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1198_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = w;
    state_1085(moves, mr,rgCache);
    board[direction_left[coord - 1]] = old1198_0;
}

void GameState::state_1092([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1092;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1093(moves, mr,rgCache);
    }
}

void GameState::state_1093([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1093;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1096(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1105(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1096([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1096;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1203_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1098(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1203_0;
}

void GameState::state_1097([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1097;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2382_0 = coord;
    coord = direction_left[coord - 1];
    state_1092(moves, mr,rgCache);
    coord = old2382_0;
}

void GameState::state_1098([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1098;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1204_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1099(moves, mr,rgCache);
    counters[w] = old1204_0;
}

void GameState::state_1099([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1099;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1206_0 = board[coord];
    board[coord] = w;
    state_1097(moves, mr,rgCache);
    board[coord] = old1206_0;
}

void GameState::state_1105([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1105;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1207_0 = coord;
    coord = direction_right[coord - 1];
    state_1108(moves, mr,rgCache);
    coord = old1207_0;
}

void GameState::state_1108([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1108;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1109(moves, mr,rgCache);
    }
}

void GameState::state_1109([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1109;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1062(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1105(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1117([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1117;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1180.reset();
    const auto result_1211 = is_legal_1174_1175_1174(rgCache);
    rgCache.decDepth();
    if (!result_1211)
    {
        state_1172(moves, mr,rgCache);
    }
    if (RbgCoordMap3[coord]!=null)
    {
        state_1188(moves, mr,rgCache);
    }
}

void GameState::state_1136([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1136;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==b)
    {
        state_1139(moves, mr,rgCache);
    }
}

void GameState::state_1139([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1139;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1221_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1141(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1221_0;
}

void GameState::state_1140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1140;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1223_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    state_1147(moves, mr,rgCache);
    coord = old1223_0;
}

void GameState::state_1141([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1141;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1224_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1142(moves, mr,rgCache);
    counters[w] = old1224_0;
}

void GameState::state_1142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1142;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1225_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = w;
    state_1140(moves, mr,rgCache);
    board[direction_right[coord - 1]] = old1225_0;
}

void GameState::state_1147([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1147;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1148(moves, mr,rgCache);
    }
}

void GameState::state_1148([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1148;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1151(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1160(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1151([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1151;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1230_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1153(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1230_0;
}

void GameState::state_1152([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1152;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2385_0 = coord;
    coord = direction_right[coord - 1];
    state_1147(moves, mr,rgCache);
    coord = old2385_0;
}

void GameState::state_1153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1153;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1231_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1154(moves, mr,rgCache);
    counters[w] = old1231_0;
}

void GameState::state_1154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1154;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1232_0 = board[coord];
    board[coord] = w;
    state_1152(moves, mr,rgCache);
    board[coord] = old1232_0;
}

void GameState::state_1160([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1160;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1233_0 = coord;
    coord = direction_left[coord - 1];
    state_1163(moves, mr,rgCache);
    coord = old1233_0;
}

void GameState::state_1163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1163;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1164(moves, mr,rgCache);
    }
}

void GameState::state_1164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1164;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1117(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1160(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1172([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1172;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1229.reset();
    const auto result_1236 = is_legal_1221_1222_1221(rgCache);
    rgCache.decDepth();
    if (!result_1236)
    {
        state_1219(moves, mr,rgCache);
    }
    if (direction_down[coord - 1]!=null)
    {
        state_1238(moves, mr,rgCache);
    }
}

void GameState::state_1188([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1188;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==b)
    {
        state_1190(moves, mr,rgCache);
    }
}

void GameState::state_1190([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1190;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1245_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1192(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1245_0;
}

void GameState::state_1191([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1191;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1246_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    state_1197(moves, mr,rgCache);
    coord = old1246_0;
}

void GameState::state_1192([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1192;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1247_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1193(moves, mr,rgCache);
    counters[w] = old1247_0;
}

void GameState::state_1193([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1193;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1248_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = w;
    state_1191(moves, mr,rgCache);
    board[RbgCoordMap3[coord]] = old1248_0;
}

void GameState::state_1197([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1197;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1198(moves, mr,rgCache);
    }
}

void GameState::state_1198([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1198;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1201(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1209(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1201([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1201;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1252_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1203(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1252_0;
}

void GameState::state_1202([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1202;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2387_0 = coord;
    coord = RbgCoordMap3[coord];
    state_1197(moves, mr,rgCache);
    coord = old2387_0;
}

void GameState::state_1203([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1203;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1253_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1204(moves, mr,rgCache);
    counters[w] = old1253_0;
}

void GameState::state_1204([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1204;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1254_0 = board[coord];
    board[coord] = w;
    state_1202(moves, mr,rgCache);
    board[coord] = old1254_0;
}

void GameState::state_1209([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1209;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1255_0 = coord;
    coord = RbgCoordMap2[coord];
    state_1211(moves, mr,rgCache);
    coord = old1255_0;
}

void GameState::state_121([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_132.reset();
    const auto result_1256 = is_legal_126_127_126(rgCache);
    rgCache.decDepth();
    if (!result_1256)
    {
        state_124(moves, mr,rgCache);
    }
    if (RbgCoordMap1[coord]!=null)
    {
        state_140(moves, mr,rgCache);
    }
}

void GameState::state_1211([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1211;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1212(moves, mr,rgCache);
    }
}

void GameState::state_1212([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1212;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1172(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1209(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1219([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1219;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1282.reset();
    const auto result_1259 = is_legal_1276_1277_1276(rgCache);
    rgCache.decDepth();
    if (!result_1259)
    {
        state_1274(moves, mr,rgCache);
    }
    if (RbgCoordMap4[coord]!=null)
    {
        state_1290(moves, mr,rgCache);
    }
}

void GameState::state_122([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1584_1585_1584(rgCache))
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1596(moves, mr,rgCache);
}

void GameState::state_123([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 65;
    rgCache.state_cache_1562 = false;
    state_122(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_1238([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1238;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==b)
    {
        state_1241(moves, mr,rgCache);
    }
}

void GameState::state_124([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_124;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_181.reset();
    const auto result_1528 = is_legal_173_174_173(rgCache);
    rgCache.decDepth();
    if (!result_1528)
    {
        state_171(moves, mr,rgCache);
    }
    if (direction_up[coord - 1]!=null)
    {
        state_190(moves, mr,rgCache);
    }
}

void GameState::state_1241([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1241;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1530_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1243(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1530_0;
}

void GameState::state_1242([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1242;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1531_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    state_1249(moves, mr,rgCache);
    coord = old1531_0;
}

void GameState::state_1243([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1243;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1532_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1244(moves, mr,rgCache);
    counters[w] = old1532_0;
}

void GameState::state_1244([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1244;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1533_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = w;
    state_1242(moves, mr,rgCache);
    board[direction_down[coord - 1]] = old1533_0;
}

void GameState::state_1249([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1249;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1250(moves, mr,rgCache);
    }
}

void GameState::state_1250([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1250;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1253(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1262(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1253([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1253;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1537_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1255(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1537_0;
}

void GameState::state_1254([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1254;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2405_0 = coord;
    coord = direction_down[coord - 1];
    state_1249(moves, mr,rgCache);
    coord = old2405_0;
}

void GameState::state_1255([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1255;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1538_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1256(moves, mr,rgCache);
    counters[w] = old1538_0;
}

void GameState::state_1256([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1256;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1539_0 = board[coord];
    board[coord] = w;
    state_1254(moves, mr,rgCache);
    board[coord] = old1539_0;
}

void GameState::state_1262([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1262;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1540_0 = coord;
    coord = direction_up[coord - 1];
    state_1265(moves, mr,rgCache);
    coord = old1540_0;
}

void GameState::state_1265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1265;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1266(moves, mr,rgCache);
    }
}

void GameState::state_1266([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1266;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1219(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1262(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1274([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1274;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1543_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    state_1322(moves, mr,rgCache);
    counters[static_cast<Piece>(e)] = old1543_0;
}

void GameState::state_1290([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1290;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==b)
    {
        state_1292(moves, mr,rgCache);
    }
}

void GameState::state_1292([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1292;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1554_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1294(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1554_0;
}

void GameState::state_1293([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1293;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1555_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    state_1299(moves, mr,rgCache);
    coord = old1555_0;
}

void GameState::state_1294([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1294;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1556_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1295(moves, mr,rgCache);
    counters[w] = old1556_0;
}

void GameState::state_1295([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1295;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1557_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = w;
    state_1293(moves, mr,rgCache);
    board[RbgCoordMap4[coord]] = old1557_0;
}

void GameState::state_1299([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1299;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1300(moves, mr,rgCache);
    }
}

void GameState::state_1300([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1300;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        state_1303(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1311(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1303([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1303;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1563_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_1305(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old1563_0;
}

void GameState::state_1304([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1304;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2407_0 = coord;
    coord = RbgCoordMap4[coord];
    state_1299(moves, mr,rgCache);
    coord = old2407_0;
}

void GameState::state_1305([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1305;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1564_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1306(moves, mr,rgCache);
    counters[w] = old1564_0;
}

void GameState::state_1306([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1306;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1565_0 = board[coord];
    board[coord] = w;
    state_1304(moves, mr,rgCache);
    board[coord] = old1565_0;
}

void GameState::state_1311([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1311;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1566_0 = coord;
    coord = RbgCoordMap1[coord];
    state_1313(moves, mr,rgCache);
    coord = old1566_0;
}

void GameState::state_1313([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1313;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_1314(moves, mr,rgCache);
    }
}

void GameState::state_1314([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1314;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_1274(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_1311(moves, mr,rgCache);
        return;
    }
}

void GameState::state_1322([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1322;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1570_0 = counters[w];
    counters[w] = counters[w]+1;
    state_1323(moves, mr,rgCache);
    counters[w] = old1570_0;
}

void GameState::state_1323([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1323;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1571_0 = board[coord];
    board[coord] = w;
    state_796(moves, mr,rgCache);
    board[coord] = old1571_0;
}

void GameState::state_1326([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_1334(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_1333([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1334([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 66;
    state_1333(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_140([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        state_142(moves, mr,rgCache);
    }
}

void GameState::state_142([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1608_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_144(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1608_0;
}

void GameState::state_143([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1611_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    state_149(moves, mr,rgCache);
    coord = old1611_0;
}

void GameState::state_144([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1614_0 = counters[b];
    counters[b] = counters[b]+1;
    state_145(moves, mr,rgCache);
    counters[b] = old1614_0;
}

void GameState::state_145([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1623_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = b;
    state_143(moves, mr,rgCache);
    board[RbgCoordMap1[coord]] = old1623_0;
}

void GameState::state_149([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_149;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_150(moves, mr,rgCache);
    }
}

void GameState::state_150([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        state_153(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_161(moves, mr,rgCache);
        return;
    }
}

void GameState::state_153([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1648_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_155(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1648_0;
}

void GameState::state_154([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2421_0 = coord;
    coord = RbgCoordMap1[coord];
    state_149(moves, mr,rgCache);
    coord = old2421_0;
}

void GameState::state_155([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1654_0 = counters[b];
    counters[b] = counters[b]+1;
    state_156(moves, mr,rgCache);
    counters[b] = old1654_0;
}

void GameState::state_1558([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1558;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    mr[0] = 0 + coord;
    state_1561(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_1559([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]<counters[b])==1)
    {
        state_1567(moves, mr,rgCache);
    }
    if (counters[w]==counters[b])
    {
        state_1571(moves, mr,rgCache);
    }
    if ((counters[w]>counters[b])==1)
    {
        state_774(moves, mr,rgCache);
    }
}

void GameState::state_156([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1666_0 = board[coord];
    board[coord] = b;
    state_154(moves, mr,rgCache);
    board[coord] = old1666_0;
}

void GameState::state_1560([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1559())
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1608(moves, mr,rgCache);
}

void GameState::state_1561([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 67;
    rgCache.state_cache_1562 = false;
    state_1560(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_1562([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return;
    }
    cache = true;
    moves.emplace_back(mr);
}

void GameState::state_1567([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1665_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_1562(moves, mr,rgCache);
    goals[black - 2] = old1665_0;
}

void GameState::state_1571([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1667_0 = goals[black - 2];
    goals[black - 2] = 50;
    state_1573(moves, mr,rgCache);
    goals[black - 2] = old1667_0;
}

void GameState::state_1573([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1668_0 = goals[white - 2];
    goals[white - 2] = 50;
    state_1562(moves, mr,rgCache);
    goals[white - 2] = old1668_0;
}

void GameState::state_1594([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1596([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1600([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1602([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1604([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_1608([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_161([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_161;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1674_0 = coord;
    coord = RbgCoordMap4[coord];
    state_163(moves, mr,rgCache);
    coord = old1674_0;
}

void GameState::state_163([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_163;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_164(moves, mr,rgCache);
    }
}

void GameState::state_164([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_164;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_124(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_161(moves, mr,rgCache);
        return;
    }
}

void GameState::state_171([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_171;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_234.reset();
    const auto result_1678 = is_legal_228_229_228(rgCache);
    rgCache.decDepth();
    if (!result_1678)
    {
        state_226(moves, mr,rgCache);
    }
    if (RbgCoordMap2[coord]!=null)
    {
        state_242(moves, mr,rgCache);
    }
}

void GameState::state_190([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_190;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==w)
    {
        state_193(moves, mr,rgCache);
    }
}

void GameState::state_193([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_193;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1689_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_195(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1689_0;
}

void GameState::state_194([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_194;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1690_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    state_201(moves, mr,rgCache);
    coord = old1690_0;
}

void GameState::state_195([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_195;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1691_0 = counters[b];
    counters[b] = counters[b]+1;
    state_196(moves, mr,rgCache);
    counters[b] = old1691_0;
}

void GameState::state_196([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_196;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1692_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = b;
    state_194(moves, mr,rgCache);
    board[direction_up[coord - 1]] = old1692_0;
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    mr[0] = 0 + coord;
    state_6(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_201([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_201;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_202(moves, mr,rgCache);
    }
}

void GameState::state_202([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_202;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_205(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_214(moves, mr,rgCache);
        return;
    }
}

void GameState::state_205([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_205;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1697_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_207(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1697_0;
}

void GameState::state_206([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_206;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2428_0 = coord;
    coord = direction_up[coord - 1];
    state_201(moves, mr,rgCache);
    coord = old2428_0;
}

void GameState::state_207([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_207;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1698_0 = counters[b];
    counters[b] = counters[b]+1;
    state_208(moves, mr,rgCache);
    counters[b] = old1698_0;
}

void GameState::state_208([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_208;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1699_0 = board[coord];
    board[coord] = b;
    state_206(moves, mr,rgCache);
    board[coord] = old1699_0;
}

void GameState::state_214([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_214;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1700_0 = coord;
    coord = direction_down[coord - 1];
    state_217(moves, mr,rgCache);
    coord = old1700_0;
}

void GameState::state_217([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_217;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_218(moves, mr,rgCache);
    }
}

void GameState::state_218([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_218;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_171(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_214(moves, mr,rgCache);
        return;
    }
}

void GameState::state_226([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_226;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_283.reset();
    const auto result_1703 = is_legal_275_276_275(rgCache);
    rgCache.decDepth();
    if (!result_1703)
    {
        state_273(moves, mr,rgCache);
    }
    if (direction_left[coord - 1]!=null)
    {
        state_292(moves, mr,rgCache);
    }
}

void GameState::state_242([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_242;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==w)
    {
        state_244(moves, mr,rgCache);
    }
}

void GameState::state_244([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_244;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1712_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_246(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1712_0;
}

void GameState::state_245([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_245;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1713_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    state_251(moves, mr,rgCache);
    coord = old1713_0;
}

void GameState::state_246([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_246;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1714_0 = counters[b];
    counters[b] = counters[b]+1;
    state_247(moves, mr,rgCache);
    counters[b] = old1714_0;
}

void GameState::state_247([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_247;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1715_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = b;
    state_245(moves, mr,rgCache);
    board[RbgCoordMap2[coord]] = old1715_0;
}

void GameState::state_251([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_251;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_252(moves, mr,rgCache);
    }
}

void GameState::state_252([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_252;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_255(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_263(moves, mr,rgCache);
        return;
    }
}

void GameState::state_255([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_255;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1720_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_257(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1720_0;
}

void GameState::state_256([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_256;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2430_0 = coord;
    coord = RbgCoordMap2[coord];
    state_251(moves, mr,rgCache);
    coord = old2430_0;
}

void GameState::state_257([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_257;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1721_0 = counters[b];
    counters[b] = counters[b]+1;
    state_258(moves, mr,rgCache);
    counters[b] = old1721_0;
}

void GameState::state_258([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_258;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1722_0 = board[coord];
    board[coord] = b;
    state_256(moves, mr,rgCache);
    board[coord] = old1722_0;
}

void GameState::state_263([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_263;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1723_0 = coord;
    coord = RbgCoordMap3[coord];
    state_265(moves, mr,rgCache);
    coord = old1723_0;
}

void GameState::state_265([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_265;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_266(moves, mr,rgCache);
    }
}

void GameState::state_266([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_266;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_226(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_263(moves, mr,rgCache);
        return;
    }
}

void GameState::state_273([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_273;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_338.reset();
    const auto result_1727 = is_legal_330_331_330(rgCache);
    rgCache.decDepth();
    if (!result_1727)
    {
        state_328(moves, mr,rgCache);
    }
    if (direction_right[coord - 1]!=null)
    {
        state_347(moves, mr,rgCache);
    }
}

void GameState::state_292([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_292;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==w)
    {
        state_295(moves, mr,rgCache);
    }
}

void GameState::state_295([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_295;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1737_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_297(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1737_0;
}

void GameState::state_296([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_296;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1738_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    state_303(moves, mr,rgCache);
    coord = old1738_0;
}

void GameState::state_297([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_297;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1739_0 = counters[b];
    counters[b] = counters[b]+1;
    state_298(moves, mr,rgCache);
    counters[b] = old1739_0;
}

void GameState::state_298([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_298;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1740_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = b;
    state_296(moves, mr,rgCache);
    board[direction_left[coord - 1]] = old1740_0;
}

void GameState::state_303([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_303;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_304(moves, mr,rgCache);
    }
}

void GameState::state_304([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_304;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_307(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_316(moves, mr,rgCache);
        return;
    }
}

void GameState::state_307([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_307;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1744_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_309(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1744_0;
}

void GameState::state_308([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_308;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2432_0 = coord;
    coord = direction_left[coord - 1];
    state_303(moves, mr,rgCache);
    coord = old2432_0;
}

void GameState::state_309([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_309;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1745_0 = counters[b];
    counters[b] = counters[b]+1;
    state_310(moves, mr,rgCache);
    counters[b] = old1745_0;
}

void GameState::state_310([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_310;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1747_0 = board[coord];
    board[coord] = b;
    state_308(moves, mr,rgCache);
    board[coord] = old1747_0;
}

void GameState::state_316([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_316;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1748_0 = coord;
    coord = direction_right[coord - 1];
    state_319(moves, mr,rgCache);
    coord = old1748_0;
}

void GameState::state_319([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_319;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_320(moves, mr,rgCache);
    }
}

void GameState::state_320([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_320;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_273(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_316(moves, mr,rgCache);
        return;
    }
}

void GameState::state_328([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_328;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_391.reset();
    const auto result_1752 = is_legal_385_386_385(rgCache);
    rgCache.decDepth();
    if (!result_1752)
    {
        state_383(moves, mr,rgCache);
    }
    if (RbgCoordMap3[coord]!=null)
    {
        state_399(moves, mr,rgCache);
    }
}

void GameState::state_347([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_347;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==w)
    {
        state_350(moves, mr,rgCache);
    }
}

void GameState::state_350([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_350;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1762_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_352(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1762_0;
}

void GameState::state_351([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_351;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1763_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    state_358(moves, mr,rgCache);
    coord = old1763_0;
}

void GameState::state_352([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_352;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1764_0 = counters[b];
    counters[b] = counters[b]+1;
    state_353(moves, mr,rgCache);
    counters[b] = old1764_0;
}

void GameState::state_353([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_353;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1765_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = b;
    state_351(moves, mr,rgCache);
    board[direction_right[coord - 1]] = old1765_0;
}

void GameState::state_358([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_358;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_359(moves, mr,rgCache);
    }
}

void GameState::state_359([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_359;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_362(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_371(moves, mr,rgCache);
        return;
    }
}

void GameState::state_362([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_362;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1769_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_364(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1769_0;
}

void GameState::state_363([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_363;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2435_0 = coord;
    coord = direction_right[coord - 1];
    state_358(moves, mr,rgCache);
    coord = old2435_0;
}

void GameState::state_364([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_364;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1770_0 = counters[b];
    counters[b] = counters[b]+1;
    state_365(moves, mr,rgCache);
    counters[b] = old1770_0;
}

void GameState::state_365([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_365;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1771_0 = board[coord];
    board[coord] = b;
    state_363(moves, mr,rgCache);
    board[coord] = old1771_0;
}

void GameState::state_371([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_371;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1772_0 = coord;
    coord = direction_left[coord - 1];
    state_374(moves, mr,rgCache);
    coord = old1772_0;
}

void GameState::state_374([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_374;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_375(moves, mr,rgCache);
    }
}

void GameState::state_375([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_375;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_328(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_371(moves, mr,rgCache);
        return;
    }
}

void GameState::state_383([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_383;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_440.reset();
    const auto result_1775 = is_legal_432_433_432(rgCache);
    rgCache.decDepth();
    if (!result_1775)
    {
        state_430(moves, mr,rgCache);
    }
    if (direction_down[coord - 1]!=null)
    {
        state_449(moves, mr,rgCache);
    }
}

void GameState::state_399([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_399;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==w)
    {
        state_401(moves, mr,rgCache);
    }
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_538_539_538(rgCache))
    {
        state_537(moves, mr,rgCache);
    }
    const auto old1784_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_8(moves, mr,rgCache);    }
    coord = old1784_0;
}

void GameState::state_401([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_401;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1787_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_403(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1787_0;
}

void GameState::state_402([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_402;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1788_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    state_408(moves, mr,rgCache);
    coord = old1788_0;
}

void GameState::state_403([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_403;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1789_0 = counters[b];
    counters[b] = counters[b]+1;
    state_404(moves, mr,rgCache);
    counters[b] = old1789_0;
}

void GameState::state_404([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_404;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1790_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = b;
    state_402(moves, mr,rgCache);
    board[RbgCoordMap3[coord]] = old1790_0;
}

void GameState::state_408([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_408;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_409(moves, mr,rgCache);
    }
}

void GameState::state_409([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_409;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_412(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_420(moves, mr,rgCache);
        return;
    }
}

void GameState::state_412([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_412;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1795_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_414(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1795_0;
}

void GameState::state_413([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_413;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2437_0 = coord;
    coord = RbgCoordMap3[coord];
    state_408(moves, mr,rgCache);
    coord = old2437_0;
}

void GameState::state_414([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_414;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1796_0 = counters[b];
    counters[b] = counters[b]+1;
    state_415(moves, mr,rgCache);
    counters[b] = old1796_0;
}

void GameState::state_415([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_415;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1797_0 = board[coord];
    board[coord] = b;
    state_413(moves, mr,rgCache);
    board[coord] = old1797_0;
}

void GameState::state_420([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_420;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1799_0 = coord;
    coord = RbgCoordMap2[coord];
    state_422(moves, mr,rgCache);
    coord = old1799_0;
}

void GameState::state_422([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_422;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_423(moves, mr,rgCache);
    }
}

void GameState::state_423([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_423;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_383(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_420(moves, mr,rgCache);
        return;
    }
}

void GameState::state_430([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_430;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_493.reset();
    const auto result_1802 = is_legal_487_488_487(rgCache);
    rgCache.decDepth();
    if (!result_1802)
    {
        state_485(moves, mr,rgCache);
    }
    if (RbgCoordMap4[coord]!=null)
    {
        state_501(moves, mr,rgCache);
    }
}

void GameState::state_449([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_449;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==w)
    {
        state_452(moves, mr,rgCache);
    }
}

void GameState::state_452([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_452;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1813_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_454(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1813_0;
}

void GameState::state_453([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_453;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1814_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    state_460(moves, mr,rgCache);
    coord = old1814_0;
}

void GameState::state_454([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_454;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1815_0 = counters[b];
    counters[b] = counters[b]+1;
    state_455(moves, mr,rgCache);
    counters[b] = old1815_0;
}

void GameState::state_455([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_455;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1816_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = b;
    state_453(moves, mr,rgCache);
    board[direction_down[coord - 1]] = old1816_0;
}

void GameState::state_460([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_460;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_461(moves, mr,rgCache);
    }
}

void GameState::state_461([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_461;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_464(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_473(moves, mr,rgCache);
        return;
    }
}

void GameState::state_464([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_464;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1821_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_466(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1821_0;
}

void GameState::state_465([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_465;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2440_0 = coord;
    coord = direction_down[coord - 1];
    state_460(moves, mr,rgCache);
    coord = old2440_0;
}

void GameState::state_466([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_466;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1822_0 = counters[b];
    counters[b] = counters[b]+1;
    state_467(moves, mr,rgCache);
    counters[b] = old1822_0;
}

void GameState::state_467([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_467;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1823_0 = board[coord];
    board[coord] = b;
    state_465(moves, mr,rgCache);
    board[coord] = old1823_0;
}

void GameState::state_473([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_473;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1824_0 = coord;
    coord = direction_up[coord - 1];
    state_476(moves, mr,rgCache);
    coord = old1824_0;
}

void GameState::state_476([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_476;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_477(moves, mr,rgCache);
    }
}

void GameState::state_477([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_477;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_430(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_473(moves, mr,rgCache);
        return;
    }
}

void GameState::state_485([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_485;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1827_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    state_533(moves, mr,rgCache);
    counters[static_cast<Piece>(e)] = old1827_0;
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1582_1583_1582(rgCache))
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1594(moves, mr,rgCache);
}

void GameState::state_501([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_501;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==w)
    {
        state_503(moves, mr,rgCache);
    }
}

void GameState::state_503([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_503;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1836_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_505(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1836_0;
}

void GameState::state_504([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_504;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1837_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    state_510(moves, mr,rgCache);
    coord = old1837_0;
}

void GameState::state_505([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_505;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1838_0 = counters[b];
    counters[b] = counters[b]+1;
    state_506(moves, mr,rgCache);
    counters[b] = old1838_0;
}

void GameState::state_506([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_506;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1839_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = b;
    state_504(moves, mr,rgCache);
    board[RbgCoordMap4[coord]] = old1839_0;
}

void GameState::state_510([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_510;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_511(moves, mr,rgCache);
    }
}

void GameState::state_511([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_511;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_514(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_522(moves, mr,rgCache);
        return;
    }
}

void GameState::state_514([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_514;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1843_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    state_516(moves, mr,rgCache);
    counters[static_cast<Piece>(w)] = old1843_0;
}

void GameState::state_515([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_515;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2442_0 = coord;
    coord = RbgCoordMap4[coord];
    state_510(moves, mr,rgCache);
    coord = old2442_0;
}

void GameState::state_516([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_516;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1844_0 = counters[b];
    counters[b] = counters[b]+1;
    state_517(moves, mr,rgCache);
    counters[b] = old1844_0;
}

void GameState::state_517([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_517;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1845_0 = board[coord];
    board[coord] = b;
    state_515(moves, mr,rgCache);
    board[coord] = old1845_0;
}

void GameState::state_522([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_522;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1847_0 = coord;
    coord = RbgCoordMap1[coord];
    state_524(moves, mr,rgCache);
    coord = old1847_0;
}

void GameState::state_524([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_524;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_525(moves, mr,rgCache);
    }
}

void GameState::state_525([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_525;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_485(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_522(moves, mr,rgCache);
        return;
    }
}

void GameState::state_533([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_533;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1850_0 = counters[b];
    counters[b] = counters[b]+1;
    state_534(moves, mr,rgCache);
    counters[b] = old1850_0;
}

void GameState::state_534([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_534;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old1851_0 = board[coord];
    board[coord] = b;
    state_7(moves, mr,rgCache);
    board[coord] = old1851_0;
}

void GameState::state_537([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_545(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_544([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_545([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 68;
    state_544(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_546([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_557.reset();
    rgCache.state_cache_571.reset();
    rgCache.state_cache_584.reset();
    rgCache.state_cache_598.reset();
    rgCache.state_cache_613.reset();
    rgCache.state_cache_626.reset();
    rgCache.state_cache_640.reset();
    rgCache.state_cache_653.reset();
    rgCache.state_cache_665.reset();
    rgCache.state_cache_679.reset();
    rgCache.state_cache_692.reset();
    rgCache.state_cache_706.reset();
    rgCache.state_cache_721.reset();
    rgCache.state_cache_734.reset();
    rgCache.state_cache_748.reset();
    rgCache.state_cache_761.reset();
    const auto result_2551 = is_legal_548_549_548(rgCache);
    rgCache.decDepth();
    if (!result_2551)
    {
        state_772(moves, mr,rgCache);
        return;
    }
    state_795(moves, mr,rgCache);
}

void GameState::state_6([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 69;
    rgCache.state_cache_1562 = false;
    state_5(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_7;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    mr[0] = 0 + coord;
    state_546(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_770([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]>counters[b])==1)
    {
        state_774(moves, mr,rgCache);
    }
    if ((counters[w]<counters[b])==1)
    {
        state_1567(moves, mr,rgCache);
    }
    if (counters[w]==counters[b])
    {
        state_1571(moves, mr,rgCache);
    }
}

void GameState::state_771([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_770_790_770_770_790_790_770_790_770())
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1600(moves, mr,rgCache);
}

void GameState::state_772([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 72;
    rgCache.state_cache_1562 = false;
    state_771(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_774([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2496_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_1562(moves, mr,rgCache);
    goals[white - 2] = old2496_0;
}

void GameState::state_793([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1327_1328_1327(rgCache))
    {
        state_1326(moves, mr,rgCache);
    }
    const auto old1940_0 = coord;
    for (coord = rx0y0; coord <= rx7y7; ++coord)
    {
    state_797(moves, mr,rgCache);    }
    coord = old1940_0;
}

void GameState::state_794([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1588_1589_1588(rgCache))
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1602(moves, mr,rgCache);
}

void GameState::state_795([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 71;
    rgCache.state_cache_1562 = false;
    state_794(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_796([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_796;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1346.reset();
    rgCache.state_cache_1360.reset();
    rgCache.state_cache_1373.reset();
    rgCache.state_cache_1387.reset();
    rgCache.state_cache_1402.reset();
    rgCache.state_cache_1415.reset();
    rgCache.state_cache_1429.reset();
    rgCache.state_cache_1442.reset();
    rgCache.state_cache_1454.reset();
    rgCache.state_cache_1468.reset();
    rgCache.state_cache_1481.reset();
    rgCache.state_cache_1495.reset();
    rgCache.state_cache_1510.reset();
    rgCache.state_cache_1523.reset();
    rgCache.state_cache_1537.reset();
    rgCache.state_cache_1550.reset();
    const auto result_1942 = is_legal_1337_1338_1337(rgCache);
    rgCache.decDepth();
    if (!result_1942)
    {
        state_1558(moves, mr,rgCache);
        return;
    }
    state_2(moves, mr,rgCache);
}

void GameState::state_797([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_798(moves, mr,rgCache);
    }
}

void GameState::state_798([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_806.reset();
    rgCache.state_cache_820.reset();
    rgCache.state_cache_833.reset();
    rgCache.state_cache_847.reset();
    rgCache.state_cache_862.reset();
    rgCache.state_cache_875.reset();
    rgCache.state_cache_889.reset();
    rgCache.state_cache_902.reset();
    const auto result_1944 = is_legal_800_801_800(rgCache);
    rgCache.decDepth();
    if (result_1944)
    {
        state_799(moves, mr,rgCache);
    }
}

void GameState::state_799([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_912(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_8([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_9(moves, mr,rgCache);
    }
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_113.reset();
    rgCache.state_cache_17.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_44.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_73.reset();
    rgCache.state_cache_86.reset();
    const auto result_1997 = is_legal_11_12_11(rgCache);
    rgCache.decDepth();
    if (result_1997)
    {
        state_10(moves, mr,rgCache);
    }
}

void GameState::state_910([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_921.reset();
    const auto result_2002 = is_legal_915_916_915(rgCache);
    rgCache.decDepth();
    if (!result_2002)
    {
        state_913(moves, mr,rgCache);
    }
    if (RbgCoordMap1[coord]!=null)
    {
        state_929(moves, mr,rgCache);
    }
}

void GameState::state_911([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1590_1591_1590(rgCache))
    {
        state_1562(moves, mr,rgCache);
        return;
    }
    state_1604(moves, mr,rgCache);
}

void GameState::state_912([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 70;
    rgCache.state_cache_1562 = false;
    state_911(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_913([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_913;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_970.reset();
    const auto result_2264 = is_legal_962_963_962(rgCache);
    rgCache.decDepth();
    if (!result_2264)
    {
        state_960(moves, mr,rgCache);
    }
    if (direction_up[coord - 1]!=null)
    {
        state_979(moves, mr,rgCache);
    }
}

void GameState::state_929([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        state_931(moves, mr,rgCache);
    }
}

void GameState::state_931([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2273_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_933(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old2273_0;
}

void GameState::state_932([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2274_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    state_938(moves, mr,rgCache);
    coord = old2274_0;
}

void GameState::state_933([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2275_0 = counters[w];
    counters[w] = counters[w]+1;
    state_934(moves, mr,rgCache);
    counters[w] = old2275_0;
}

void GameState::state_934([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2276_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = w;
    state_932(moves, mr,rgCache);
    board[RbgCoordMap1[coord]] = old2276_0;
}

void GameState::state_938([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_938;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_939(moves, mr,rgCache);
    }
}

void GameState::state_939([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        state_942(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_950(moves, mr,rgCache);
        return;
    }
}

void GameState::state_942([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2281_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_944(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old2281_0;
}

void GameState::state_943([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2487_0 = coord;
    coord = RbgCoordMap1[coord];
    state_938(moves, mr,rgCache);
    coord = old2487_0;
}

void GameState::state_944([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2282_0 = counters[w];
    counters[w] = counters[w]+1;
    state_945(moves, mr,rgCache);
    counters[w] = old2282_0;
}

void GameState::state_945([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2283_0 = board[coord];
    board[coord] = w;
    state_943(moves, mr,rgCache);
    board[coord] = old2283_0;
}

void GameState::state_950([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_950;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2284_0 = coord;
    coord = RbgCoordMap4[coord];
    state_952(moves, mr,rgCache);
    coord = old2284_0;
}

void GameState::state_952([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_952;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_953(moves, mr,rgCache);
    }
}

void GameState::state_953([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_953;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_913(moves, mr,rgCache);
        return;
    }
    if (board[coord]==w)
    {
        state_950(moves, mr,rgCache);
        return;
    }
}

void GameState::state_960([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_960;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (RbgCoordMap2[coord]!=null)
    {
        state_1031(moves, mr,rgCache);
    }
    rgCache.incDepth();
    rgCache.state_cache_1023.reset();
    const auto result_2288 = is_legal_1017_1018_1017(rgCache);
    rgCache.decDepth();
    if (!result_2288)
    {
        state_1015(moves, mr,rgCache);
    }
}

void GameState::state_979([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_979;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==b)
    {
        state_982(moves, mr,rgCache);
    }
}

void GameState::state_982([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_982;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2298_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_984(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old2298_0;
}

void GameState::state_983([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_983;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2489_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    state_1002(moves, mr,rgCache);
    coord = old2489_0;
}

void GameState::state_984([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_984;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2299_0 = counters[w];
    counters[w] = counters[w]+1;
    state_985(moves, mr,rgCache);
    counters[w] = old2299_0;
}

void GameState::state_985([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_985;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2300_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = w;
    state_983(moves, mr,rgCache);
    board[direction_up[coord - 1]] = old2300_0;
}

void GameState::state_991([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_991;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        state_1003(moves, mr,rgCache);
        return;
    }
    if (board[coord]==b)
    {
        state_994(moves, mr,rgCache);
        return;
    }
}

void GameState::state_994([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_994;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2303_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    state_996(moves, mr,rgCache);
    counters[static_cast<Piece>(b)] = old2303_0;
}

void GameState::state_995([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_995;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2304_0 = coord;
    coord = direction_up[coord - 1];
    state_1002(moves, mr,rgCache);
    coord = old2304_0;
}

void GameState::state_996([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_996;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2305_0 = counters[w];
    counters[w] = counters[w]+1;
    state_997(moves, mr,rgCache);
    counters[w] = old2305_0;
}

void GameState::state_997([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_997;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    const auto old2306_0 = board[coord];
    board[coord] = w;
    state_995(moves, mr,rgCache);
    board[coord] = old2306_0;
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
    if (mr[0] == 0 + coord)
    {
        if (apply_state_123(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1002([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1002;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_991(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1003([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1003;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1159_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_state_1006(mr,rgCache))
    {
        return true;
    }
    coord = old1159_0;
    return false;
}

bool GameState::apply_state_1006([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1006;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1007(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1007([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1007;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_1003(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==e)
    {
        if (apply_state_960(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1015([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1015;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1072.reset();
    const auto result_1163 = is_legal_1064_1065_1064(rgCache);
    rgCache.decDepth();
    if (!result_1163)
    {
        if (apply_state_1062(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (apply_state_1081(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1031([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1031;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (apply_state_1033(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1033([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1033;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1173_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1035(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1173_0;
    return false;
}

bool GameState::apply_state_1034([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1034;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1174_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (apply_state_1040(mr,rgCache))
    {
        return true;
    }
    coord = old1174_0;
    return false;
}

bool GameState::apply_state_1035([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1035;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1175_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1036(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1175_0;
    return false;
}

bool GameState::apply_state_1036([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1036;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1176_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = w;
    if (apply_state_1034(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap2[coord]] = old1176_0;
    return false;
}

bool GameState::apply_state_1040([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1040;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1041(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1041([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1041;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1044(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1052(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1044([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1044;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1180_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1046(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1180_0;
    return false;
}

bool GameState::apply_state_1045([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1045;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2380_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_state_1040(mr,rgCache))
    {
        return true;
    }
    coord = old2380_0;
    return false;
}

bool GameState::apply_state_1046([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1046;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1181_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1047(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1181_0;
    return false;
}

bool GameState::apply_state_1047([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1047;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1182_0 = board[coord];
    board[coord] = w;
    if (apply_state_1045(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1182_0;
    return false;
}

bool GameState::apply_state_1052([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1052;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1183_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_state_1054(mr,rgCache))
    {
        return true;
    }
    coord = old1183_0;
    return false;
}

bool GameState::apply_state_1054([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1054;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1055(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1055([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1055;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1015(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1052(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1062([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1062;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1127.reset();
    const auto result_1186 = is_legal_1119_1120_1119(rgCache);
    rgCache.decDepth();
    if (!result_1186)
    {
        if (apply_state_1117(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (apply_state_1136(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1081([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1081;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==b)
    {
        if (apply_state_1084(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1084([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1084;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1195_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1086(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1195_0;
    return false;
}

bool GameState::apply_state_1085([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1085;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1196_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (apply_state_1092(mr,rgCache))
    {
        return true;
    }
    coord = old1196_0;
    return false;
}

bool GameState::apply_state_1086([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1086;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1197_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1087(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1197_0;
    return false;
}

bool GameState::apply_state_1087([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1087;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1198_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = w;
    if (apply_state_1085(mr,rgCache))
    {
        return true;
    }
    board[direction_left[coord - 1]] = old1198_0;
    return false;
}

bool GameState::apply_state_1092([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1092;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1093(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1093([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1093;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1096(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1105(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1096([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1096;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1203_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1098(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1203_0;
    return false;
}

bool GameState::apply_state_1097([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1097;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2382_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_state_1092(mr,rgCache))
    {
        return true;
    }
    coord = old2382_0;
    return false;
}

bool GameState::apply_state_1098([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1098;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1204_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1099(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1204_0;
    return false;
}

bool GameState::apply_state_1099([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1099;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1206_0 = board[coord];
    board[coord] = w;
    if (apply_state_1097(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1206_0;
    return false;
}

bool GameState::apply_state_1105([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1105;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1207_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_state_1108(mr,rgCache))
    {
        return true;
    }
    coord = old1207_0;
    return false;
}

bool GameState::apply_state_1108([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1108;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1109(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1109([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1109;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1062(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1105(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1117([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1117;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1180.reset();
    const auto result_1211 = is_legal_1174_1175_1174(rgCache);
    rgCache.decDepth();
    if (!result_1211)
    {
        if (apply_state_1172(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (apply_state_1188(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1136([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1136;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==b)
    {
        if (apply_state_1139(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1139([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1139;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1221_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1141(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1221_0;
    return false;
}

bool GameState::apply_state_1140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1140;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1223_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (apply_state_1147(mr,rgCache))
    {
        return true;
    }
    coord = old1223_0;
    return false;
}

bool GameState::apply_state_1141([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1141;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1224_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1142(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1224_0;
    return false;
}

bool GameState::apply_state_1142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1142;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1225_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = w;
    if (apply_state_1140(mr,rgCache))
    {
        return true;
    }
    board[direction_right[coord - 1]] = old1225_0;
    return false;
}

bool GameState::apply_state_1147([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1147;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1148(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1148([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1148;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1151(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1160(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1151([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1151;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1230_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1153(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1230_0;
    return false;
}

bool GameState::apply_state_1152([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1152;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2385_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_state_1147(mr,rgCache))
    {
        return true;
    }
    coord = old2385_0;
    return false;
}

bool GameState::apply_state_1153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1153;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1231_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1154(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1231_0;
    return false;
}

bool GameState::apply_state_1154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1154;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1232_0 = board[coord];
    board[coord] = w;
    if (apply_state_1152(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1232_0;
    return false;
}

bool GameState::apply_state_1160([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1160;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1233_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_state_1163(mr,rgCache))
    {
        return true;
    }
    coord = old1233_0;
    return false;
}

bool GameState::apply_state_1163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1164(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1117(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1160(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1172([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1172;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1229.reset();
    const auto result_1236 = is_legal_1221_1222_1221(rgCache);
    rgCache.decDepth();
    if (!result_1236)
    {
        if (apply_state_1219(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (apply_state_1238(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1188([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1188;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (apply_state_1190(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1190([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1245_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1192(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1245_0;
    return false;
}

bool GameState::apply_state_1191([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1191;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1246_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (apply_state_1197(mr,rgCache))
    {
        return true;
    }
    coord = old1246_0;
    return false;
}

bool GameState::apply_state_1192([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1192;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1247_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1193(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1247_0;
    return false;
}

bool GameState::apply_state_1193([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1193;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1248_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = w;
    if (apply_state_1191(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap3[coord]] = old1248_0;
    return false;
}

bool GameState::apply_state_1197([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1197;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1198(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1198([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1198;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1201(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1209(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1201([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1252_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1203(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1252_0;
    return false;
}

bool GameState::apply_state_1202([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2387_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_state_1197(mr,rgCache))
    {
        return true;
    }
    coord = old2387_0;
    return false;
}

bool GameState::apply_state_1203([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1203;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1253_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1204(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1253_0;
    return false;
}

bool GameState::apply_state_1204([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1204;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1254_0 = board[coord];
    board[coord] = w;
    if (apply_state_1202(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1254_0;
    return false;
}

bool GameState::apply_state_1209([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1209;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1255_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_state_1211(mr,rgCache))
    {
        return true;
    }
    coord = old1255_0;
    return false;
}

bool GameState::apply_state_121([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_132.reset();
    const auto result_1256 = is_legal_126_127_126(rgCache);
    rgCache.decDepth();
    if (!result_1256)
    {
        if (apply_state_124(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (apply_state_140(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1211([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1211;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1212(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1212([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1212;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1172(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1209(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1219([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1219;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1282.reset();
    const auto result_1259 = is_legal_1276_1277_1276(rgCache);
    rgCache.decDepth();
    if (!result_1259)
    {
        if (apply_state_1274(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (apply_state_1290(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_122([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1584_1585_1584(rgCache))
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1596(mr,rgCache))
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
            case 65:
{
                return apply_state_122(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_123([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_0(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 65)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_122(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1238([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1238;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==b)
    {
        if (apply_state_1241(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_124([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_124;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_181.reset();
    const auto result_1528 = is_legal_173_174_173(rgCache);
    rgCache.decDepth();
    if (!result_1528)
    {
        if (apply_state_171(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (apply_state_190(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1241([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1241;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1530_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1243(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1530_0;
    return false;
}

bool GameState::apply_state_1242([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1242;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1531_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (apply_state_1249(mr,rgCache))
    {
        return true;
    }
    coord = old1531_0;
    return false;
}

bool GameState::apply_state_1243([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1243;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1532_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1244(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1532_0;
    return false;
}

bool GameState::apply_state_1244([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1244;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1533_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = w;
    if (apply_state_1242(mr,rgCache))
    {
        return true;
    }
    board[direction_down[coord - 1]] = old1533_0;
    return false;
}

bool GameState::apply_state_1249([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1249;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1250(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1250([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1250;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1253(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1262(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1253([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1253;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1537_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1255(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1537_0;
    return false;
}

bool GameState::apply_state_1254([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1254;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2405_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_state_1249(mr,rgCache))
    {
        return true;
    }
    coord = old2405_0;
    return false;
}

bool GameState::apply_state_1255([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1538_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1256(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1538_0;
    return false;
}

bool GameState::apply_state_1256([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1539_0 = board[coord];
    board[coord] = w;
    if (apply_state_1254(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1539_0;
    return false;
}

bool GameState::apply_state_1262([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1262;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1540_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_state_1265(mr,rgCache))
    {
        return true;
    }
    coord = old1540_0;
    return false;
}

bool GameState::apply_state_1265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1266(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1266([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1219(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1262(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1274([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1274;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1543_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    if (apply_state_1322(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(e)] = old1543_0;
    return false;
}

bool GameState::apply_state_1290([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1290;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (apply_state_1292(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1292([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1292;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1554_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1294(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1554_0;
    return false;
}

bool GameState::apply_state_1293([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1293;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1555_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (apply_state_1299(mr,rgCache))
    {
        return true;
    }
    coord = old1555_0;
    return false;
}

bool GameState::apply_state_1294([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1294;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1556_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1295(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1556_0;
    return false;
}

bool GameState::apply_state_1295([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1295;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1557_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = w;
    if (apply_state_1293(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap4[coord]] = old1557_0;
    return false;
}

bool GameState::apply_state_1299([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1299;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1300(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1300([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1300;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_state_1303(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1311(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1303([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1563_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_1305(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old1563_0;
    return false;
}

bool GameState::apply_state_1304([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2407_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_state_1299(mr,rgCache))
    {
        return true;
    }
    coord = old2407_0;
    return false;
}

bool GameState::apply_state_1305([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1305;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1564_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1306(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1564_0;
    return false;
}

bool GameState::apply_state_1306([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1306;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1565_0 = board[coord];
    board[coord] = w;
    if (apply_state_1304(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1565_0;
    return false;
}

bool GameState::apply_state_1311([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1311;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1566_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_state_1313(mr,rgCache))
    {
        return true;
    }
    coord = old1566_0;
    return false;
}

bool GameState::apply_state_1313([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1313;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_1314(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1314([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1314;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_1274(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_1311(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_1322([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1322;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1570_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_1323(mr,rgCache))
    {
        return true;
    }
    counters[w] = old1570_0;
    return false;
}

bool GameState::apply_state_1323([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1323;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1571_0 = board[coord];
    board[coord] = w;
    if (apply_state_796(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1571_0;
    return false;
}

bool GameState::apply_state_1326([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_1334(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1333([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2319_0 = player;
    player = keeper;
    currentState = 811;
    return true;
    player = old2319_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 66:
{
                player = keeper;
                currentState = 811;
                return true;
}
        }
    }
    return false;
}

bool GameState::apply_state_1334([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_1(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 66)
    {
        if (apply_state_1333(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_140([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (apply_state_142(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_142([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1608_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_144(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1608_0;
    return false;
}

bool GameState::apply_state_143([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1611_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (apply_state_149(mr,rgCache))
    {
        return true;
    }
    coord = old1611_0;
    return false;
}

bool GameState::apply_state_144([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1614_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_145(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1614_0;
    return false;
}

bool GameState::apply_state_145([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1623_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = b;
    if (apply_state_143(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap1[coord]] = old1623_0;
    return false;
}

bool GameState::apply_state_149([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_149;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
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
    if (board[coord]==w)
    {
        if (apply_state_153(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_161(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_153([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1648_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_155(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1648_0;
    return false;
}

bool GameState::apply_state_154([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2421_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_state_149(mr,rgCache))
    {
        return true;
    }
    coord = old2421_0;
    return false;
}

bool GameState::apply_state_155([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1654_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_156(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1654_0;
    return false;
}

bool GameState::apply_state_1558([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1558;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (mr[0] == 0 + coord)
    {
        if (apply_state_1561(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1559([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]<counters[b])==1)
    {
        if (apply_state_1567(mr,rgCache))
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (apply_state_1571(mr,rgCache))
        {
            return true;
        }
    }
    if ((counters[w]>counters[b])==1)
    {
        if (apply_state_774(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_156([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1666_0 = board[coord];
    board[coord] = b;
    if (apply_state_154(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1666_0;
    return false;
}

bool GameState::apply_state_1560([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1559())
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1608(mr,rgCache))
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
            case 67:
{
                return apply_state_1560(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_1561([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_2(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 67)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_1560(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_1562([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old1669_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    player = old1669_0;
    return false;
}

bool GameState::apply_state_1567([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1665_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_state_1562(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old1665_0;
    return false;
}

bool GameState::apply_state_1571([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1667_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_state_1573(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old1667_0;
    return false;
}

bool GameState::apply_state_1573([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old1668_0 = goals[white - 2];
    goals[white - 2] = 50;
    if (apply_state_1562(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old1668_0;
    return false;
}

bool GameState::apply_state_1594([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2309_0 = player;
    player = black;
    currentState = 640;
    return true;
    player = old2309_0;
    return false;
}

bool GameState::apply_state_1596([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2311_0 = player;
    player = keeper;
    currentState = 102;
    return true;
    player = old2311_0;
    return false;
}

bool GameState::apply_state_1600([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2314_0 = player;
    player = keeper;
    currentState = 802;
    return true;
    player = old2314_0;
    return false;
}

bool GameState::apply_state_1602([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2316_0 = player;
    player = white;
    currentState = 808;
    return true;
    player = old2316_0;
    return false;
}

bool GameState::apply_state_1604([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2318_0 = player;
    player = keeper;
    currentState = 864;
    return true;
    player = old2318_0;
    return false;
}

bool GameState::apply_state_1608([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2321_0 = player;
    player = keeper;
    currentState = 503;
    return true;
    player = old2321_0;
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
    const auto old1674_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_state_163(mr,rgCache))
    {
        return true;
    }
    coord = old1674_0;
    return false;
}

bool GameState::apply_state_163([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_164(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_164([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_124(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_161(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_171([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_171;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_234.reset();
    const auto result_1678 = is_legal_228_229_228(rgCache);
    rgCache.decDepth();
    if (!result_1678)
    {
        if (apply_state_226(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (apply_state_242(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_190([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==w)
    {
        if (apply_state_193(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_193([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_193;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1689_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_195(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1689_0;
    return false;
}

bool GameState::apply_state_194([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_194;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1690_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (apply_state_201(mr,rgCache))
    {
        return true;
    }
    coord = old1690_0;
    return false;
}

bool GameState::apply_state_195([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_195;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1691_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_196(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1691_0;
    return false;
}

bool GameState::apply_state_196([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_196;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1692_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = b;
    if (apply_state_194(mr,rgCache))
    {
        return true;
    }
    board[direction_up[coord - 1]] = old1692_0;
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (mr[0] == 0 + coord)
    {
        if (apply_state_6(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_201([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_202(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_202([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_205(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_214(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_205([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_205;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1697_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_207(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1697_0;
    return false;
}

bool GameState::apply_state_206([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_206;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2428_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_state_201(mr,rgCache))
    {
        return true;
    }
    coord = old2428_0;
    return false;
}

bool GameState::apply_state_207([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_207;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1698_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_208(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1698_0;
    return false;
}

bool GameState::apply_state_208([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_208;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1699_0 = board[coord];
    board[coord] = b;
    if (apply_state_206(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1699_0;
    return false;
}

bool GameState::apply_state_214([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_214;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1700_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_state_217(mr,rgCache))
    {
        return true;
    }
    coord = old1700_0;
    return false;
}

bool GameState::apply_state_217([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_217;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_218(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_218([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_218;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_171(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_214(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_226([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_226;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_283.reset();
    const auto result_1703 = is_legal_275_276_275(rgCache);
    rgCache.decDepth();
    if (!result_1703)
    {
        if (apply_state_273(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (apply_state_292(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_242([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_242;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (apply_state_244(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_244([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_244;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1712_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_246(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1712_0;
    return false;
}

bool GameState::apply_state_245([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_245;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1713_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (apply_state_251(mr,rgCache))
    {
        return true;
    }
    coord = old1713_0;
    return false;
}

bool GameState::apply_state_246([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_246;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1714_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_247(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1714_0;
    return false;
}

bool GameState::apply_state_247([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_247;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1715_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = b;
    if (apply_state_245(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap2[coord]] = old1715_0;
    return false;
}

bool GameState::apply_state_251([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_251;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_252(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_252([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_252;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_255(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_263(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_255([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1720_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_257(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1720_0;
    return false;
}

bool GameState::apply_state_256([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2430_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_state_251(mr,rgCache))
    {
        return true;
    }
    coord = old2430_0;
    return false;
}

bool GameState::apply_state_257([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1721_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_258(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1721_0;
    return false;
}

bool GameState::apply_state_258([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_258;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1722_0 = board[coord];
    board[coord] = b;
    if (apply_state_256(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1722_0;
    return false;
}

bool GameState::apply_state_263([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_263;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1723_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_state_265(mr,rgCache))
    {
        return true;
    }
    coord = old1723_0;
    return false;
}

bool GameState::apply_state_265([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_266(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_266([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_226(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_263(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_273([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_273;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_338.reset();
    const auto result_1727 = is_legal_330_331_330(rgCache);
    rgCache.decDepth();
    if (!result_1727)
    {
        if (apply_state_328(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (apply_state_347(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_292([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_292;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==w)
    {
        if (apply_state_295(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_295([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_295;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1737_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_297(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1737_0;
    return false;
}

bool GameState::apply_state_296([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_296;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1738_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (apply_state_303(mr,rgCache))
    {
        return true;
    }
    coord = old1738_0;
    return false;
}

bool GameState::apply_state_297([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_297;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1739_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_298(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1739_0;
    return false;
}

bool GameState::apply_state_298([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_298;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1740_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = b;
    if (apply_state_296(mr,rgCache))
    {
        return true;
    }
    board[direction_left[coord - 1]] = old1740_0;
    return false;
}

bool GameState::apply_state_303([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_304(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_304([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_307(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_316(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_307([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_307;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1744_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_309(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1744_0;
    return false;
}

bool GameState::apply_state_308([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_308;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2432_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_state_303(mr,rgCache))
    {
        return true;
    }
    coord = old2432_0;
    return false;
}

bool GameState::apply_state_309([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_309;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1745_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_310(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1745_0;
    return false;
}

bool GameState::apply_state_310([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_310;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1747_0 = board[coord];
    board[coord] = b;
    if (apply_state_308(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1747_0;
    return false;
}

bool GameState::apply_state_316([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_316;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1748_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_state_319(mr,rgCache))
    {
        return true;
    }
    coord = old1748_0;
    return false;
}

bool GameState::apply_state_319([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_319;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_320(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_320([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_320;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_273(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_316(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_328([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_328;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_391.reset();
    const auto result_1752 = is_legal_385_386_385(rgCache);
    rgCache.decDepth();
    if (!result_1752)
    {
        if (apply_state_383(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (apply_state_399(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_347([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_347;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==w)
    {
        if (apply_state_350(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_350([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_350;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1762_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_352(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1762_0;
    return false;
}

bool GameState::apply_state_351([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_351;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1763_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (apply_state_358(mr,rgCache))
    {
        return true;
    }
    coord = old1763_0;
    return false;
}

bool GameState::apply_state_352([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_352;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1764_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_353(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1764_0;
    return false;
}

bool GameState::apply_state_353([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_353;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1765_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = b;
    if (apply_state_351(mr,rgCache))
    {
        return true;
    }
    board[direction_right[coord - 1]] = old1765_0;
    return false;
}

bool GameState::apply_state_358([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_358;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_359(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_359([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_359;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_362(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_371(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_362([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_362;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1769_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_364(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1769_0;
    return false;
}

bool GameState::apply_state_363([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_363;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2435_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_state_358(mr,rgCache))
    {
        return true;
    }
    coord = old2435_0;
    return false;
}

bool GameState::apply_state_364([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_364;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1770_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_365(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1770_0;
    return false;
}

bool GameState::apply_state_365([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_365;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1771_0 = board[coord];
    board[coord] = b;
    if (apply_state_363(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1771_0;
    return false;
}

bool GameState::apply_state_371([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_371;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1772_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_state_374(mr,rgCache))
    {
        return true;
    }
    coord = old1772_0;
    return false;
}

bool GameState::apply_state_374([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_374;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_375(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_375([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_375;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_328(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_371(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_383([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_383;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_440.reset();
    const auto result_1775 = is_legal_432_433_432(rgCache);
    rgCache.decDepth();
    if (!result_1775)
    {
        if (apply_state_430(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (apply_state_449(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_399([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_399;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (apply_state_401(mr,rgCache))
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
                case 65:
{
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    return apply_state_122(mr,rgCache);
}
                default:
                    player = keeper;
                    currentState = 777;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_3(mr ,rgCache);
    return false;
}

bool GameState::apply_state_401([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_401;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1787_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_403(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1787_0;
    return false;
}

bool GameState::apply_state_402([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_402;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1788_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (apply_state_408(mr,rgCache))
    {
        return true;
    }
    coord = old1788_0;
    return false;
}

bool GameState::apply_state_403([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_403;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1789_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_404(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1789_0;
    return false;
}

bool GameState::apply_state_404([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_404;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1790_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = b;
    if (apply_state_402(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap3[coord]] = old1790_0;
    return false;
}

bool GameState::apply_state_408([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_408;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_409(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_409([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_409;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_412(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_420(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_412([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_412;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1795_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_414(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1795_0;
    return false;
}

bool GameState::apply_state_413([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_413;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2437_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_state_408(mr,rgCache))
    {
        return true;
    }
    coord = old2437_0;
    return false;
}

bool GameState::apply_state_414([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_414;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1796_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_415(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1796_0;
    return false;
}

bool GameState::apply_state_415([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_415;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1797_0 = board[coord];
    board[coord] = b;
    if (apply_state_413(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1797_0;
    return false;
}

bool GameState::apply_state_420([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_420;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1799_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_state_422(mr,rgCache))
    {
        return true;
    }
    coord = old1799_0;
    return false;
}

bool GameState::apply_state_422([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_422;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_423(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_423([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_423;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_383(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_420(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_430([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_430;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_493.reset();
    const auto result_1802 = is_legal_487_488_487(rgCache);
    rgCache.decDepth();
    if (!result_1802)
    {
        if (apply_state_485(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (apply_state_501(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_449([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_449;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==w)
    {
        if (apply_state_452(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_452([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_452;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1813_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_454(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1813_0;
    return false;
}

bool GameState::apply_state_453([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_453;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1814_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (apply_state_460(mr,rgCache))
    {
        return true;
    }
    coord = old1814_0;
    return false;
}

bool GameState::apply_state_454([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_454;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1815_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_455(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1815_0;
    return false;
}

bool GameState::apply_state_455([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_455;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1816_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = b;
    if (apply_state_453(mr,rgCache))
    {
        return true;
    }
    board[direction_down[coord - 1]] = old1816_0;
    return false;
}

bool GameState::apply_state_460([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_460;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_461(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_461([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_461;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_464(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_473(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_464([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_464;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1821_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_466(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1821_0;
    return false;
}

bool GameState::apply_state_465([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_465;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2440_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_state_460(mr,rgCache))
    {
        return true;
    }
    coord = old2440_0;
    return false;
}

bool GameState::apply_state_466([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_466;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1822_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_467(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1822_0;
    return false;
}

bool GameState::apply_state_467([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_467;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1823_0 = board[coord];
    board[coord] = b;
    if (apply_state_465(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1823_0;
    return false;
}

bool GameState::apply_state_473([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_473;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1824_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_state_476(mr,rgCache))
    {
        return true;
    }
    coord = old1824_0;
    return false;
}

bool GameState::apply_state_476([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_476;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_477(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_477([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_477;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_430(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_473(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_485([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_485;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1827_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    if (apply_state_533(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(e)] = old1827_0;
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1582_1583_1582(rgCache))
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1594(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_501([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_501;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (apply_state_503(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_503([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_503;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1836_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_505(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1836_0;
    return false;
}

bool GameState::apply_state_504([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_504;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1837_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (apply_state_510(mr,rgCache))
    {
        return true;
    }
    coord = old1837_0;
    return false;
}

bool GameState::apply_state_505([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_505;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1838_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_506(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1838_0;
    return false;
}

bool GameState::apply_state_506([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_506;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1839_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = b;
    if (apply_state_504(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap4[coord]] = old1839_0;
    return false;
}

bool GameState::apply_state_510([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_510;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_511(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_511([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_511;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_514(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_522(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_514([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_514;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1843_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_state_516(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old1843_0;
    return false;
}

bool GameState::apply_state_515([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_515;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2442_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_state_510(mr,rgCache))
    {
        return true;
    }
    coord = old2442_0;
    return false;
}

bool GameState::apply_state_516([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_516;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1844_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_517(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1844_0;
    return false;
}

bool GameState::apply_state_517([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_517;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1845_0 = board[coord];
    board[coord] = b;
    if (apply_state_515(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1845_0;
    return false;
}

bool GameState::apply_state_522([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_522;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1847_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_state_524(mr,rgCache))
    {
        return true;
    }
    coord = old1847_0;
    return false;
}

bool GameState::apply_state_524([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_524;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_525(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_525([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_525;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_485(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_522(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_533([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_533;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1850_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_state_534(mr,rgCache))
    {
        return true;
    }
    counters[b] = old1850_0;
    return false;
}

bool GameState::apply_state_534([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_534;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old1851_0 = board[coord];
    board[coord] = b;
    if (apply_state_7(mr,rgCache))
    {
        return true;
    }
    board[coord] = old1851_0;
    return false;
}

bool GameState::apply_state_537([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_545(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_544([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2312_0 = player;
    player = keeper;
    currentState = 777;
    return true;
    player = old2312_0;
    return false;
}

bool GameState::switch_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 68:
{
                player = keeper;
                currentState = 777;
                return true;
}
        }
    }
    return false;
}

bool GameState::apply_state_545([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_4(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 68)
    {
        if (apply_state_544(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        case 72:
{
            return apply_state_771(mr,rgCache);
}
        default:
            return apply_state_794(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_546([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_5(mr ,rgCache);
    return false;
}

bool GameState::switch_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 69:
{
                return apply_state_5(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_6([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_6(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 69)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_5(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            return apply_state_546(mr,rgCache);
    }
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_7;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    return switch_7(mr ,rgCache);
    return false;
}

bool GameState::apply_state_770([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]>counters[b])==1)
    {
        if (apply_state_774(mr,rgCache))
        {
            return true;
        }
    }
    if ((counters[w]<counters[b])==1)
    {
        if (apply_state_1567(mr,rgCache))
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (apply_state_1571(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_771([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_770_790_770_770_790_790_770_790_770())
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1600(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_772([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 72)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_771(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_774([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2496_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_1562(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old2496_0;
    return false;
}

bool GameState::switch_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                case 70:
{
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    return apply_state_911(mr,rgCache);
}
                default:
                    player = keeper;
                    currentState = 811;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_793([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_8(mr ,rgCache);
    return false;
}

bool GameState::apply_state_794([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1588_1589_1588(rgCache))
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1602(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_795([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 71)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_794(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::switch_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            switch (mr[rgCache.currentMrId++])
            {
                case 69:
{
                    return apply_state_5(mr,rgCache);
}
                default:
                    return apply_state_1560(mr,rgCache);
            }
            break;
    }
    return false;
}

bool GameState::apply_state_796([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_796;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    return switch_9(mr ,rgCache);
    return false;
}

bool GameState::apply_state_797([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_798(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_798([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_806.reset();
    rgCache.state_cache_820.reset();
    rgCache.state_cache_833.reset();
    rgCache.state_cache_847.reset();
    rgCache.state_cache_862.reset();
    rgCache.state_cache_875.reset();
    rgCache.state_cache_889.reset();
    rgCache.state_cache_902.reset();
    const auto result_1944 = is_legal_800_801_800(rgCache);
    rgCache.decDepth();
    if (result_1944)
    {
        if (apply_state_799(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_799([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_912(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_8([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_9(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_100.reset();
    rgCache.state_cache_113.reset();
    rgCache.state_cache_17.reset();
    rgCache.state_cache_31.reset();
    rgCache.state_cache_44.reset();
    rgCache.state_cache_58.reset();
    rgCache.state_cache_73.reset();
    rgCache.state_cache_86.reset();
    const auto result_1997 = is_legal_11_12_11(rgCache);
    rgCache.decDepth();
    if (result_1997)
    {
        if (apply_state_10(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_910([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_921.reset();
    const auto result_2002 = is_legal_915_916_915(rgCache);
    rgCache.decDepth();
    if (!result_2002)
    {
        if (apply_state_913(mr,rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (apply_state_929(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_911([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1590_1591_1590(rgCache))
    {
        if (apply_state_1562(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_1604(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::switch_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        switch (mr[rgCache.currentMrId++])
        {
            case 70:
{
                return apply_state_911(mr,rgCache);
}
        }
    }
    return false;
}

bool GameState::apply_state_912([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (switch_10(mr ,rgCache))
    {
        return true;
    }
    if (mr[1] == 70)
    {
        rgCache.state_cache_1562 = false;
        if (apply_state_911(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_913([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_913;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_970.reset();
    const auto result_2264 = is_legal_962_963_962(rgCache);
    rgCache.decDepth();
    if (!result_2264)
    {
        if (apply_state_960(mr,rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (apply_state_979(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_929([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (apply_state_931(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_931([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2273_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_933(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old2273_0;
    return false;
}

bool GameState::apply_state_932([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2274_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (apply_state_938(mr,rgCache))
    {
        return true;
    }
    coord = old2274_0;
    return false;
}

bool GameState::apply_state_933([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2275_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_934(mr,rgCache))
    {
        return true;
    }
    counters[w] = old2275_0;
    return false;
}

bool GameState::apply_state_934([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2276_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = w;
    if (apply_state_932(mr,rgCache))
    {
        return true;
    }
    board[RbgCoordMap1[coord]] = old2276_0;
    return false;
}

bool GameState::apply_state_938([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_938;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_939(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_939([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_942(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_950(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_942([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2281_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_944(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old2281_0;
    return false;
}

bool GameState::apply_state_943([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2487_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_state_938(mr,rgCache))
    {
        return true;
    }
    coord = old2487_0;
    return false;
}

bool GameState::apply_state_944([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2282_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_945(mr,rgCache))
    {
        return true;
    }
    counters[w] = old2282_0;
    return false;
}

bool GameState::apply_state_945([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old2283_0 = board[coord];
    board[coord] = w;
    if (apply_state_943(mr,rgCache))
    {
        return true;
    }
    board[coord] = old2283_0;
    return false;
}

bool GameState::apply_state_950([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_950;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2284_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_state_952(mr,rgCache))
    {
        return true;
    }
    coord = old2284_0;
    return false;
}

bool GameState::apply_state_952([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_952;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_953(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_953([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_953;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_913(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==w)
    {
        if (apply_state_950(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_960([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_960;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (RbgCoordMap2[coord]!=null)
    {
        if (apply_state_1031(mr,rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_1023.reset();
    const auto result_2288 = is_legal_1017_1018_1017(rgCache);
    rgCache.decDepth();
    if (!result_2288)
    {
        if (apply_state_1015(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_979([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_979;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==b)
    {
        if (apply_state_982(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_982([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_982;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2298_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_984(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old2298_0;
    return false;
}

bool GameState::apply_state_983([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_983;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2489_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (apply_state_1002(mr,rgCache))
    {
        return true;
    }
    coord = old2489_0;
    return false;
}

bool GameState::apply_state_984([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_984;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2299_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_985(mr,rgCache))
    {
        return true;
    }
    counters[w] = old2299_0;
    return false;
}

bool GameState::apply_state_985([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_985;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2300_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = w;
    if (apply_state_983(mr,rgCache))
    {
        return true;
    }
    board[direction_up[coord - 1]] = old2300_0;
    return false;
}

bool GameState::apply_state_991([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_991;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_state_1003(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (board[coord]==b)
    {
        if (apply_state_994(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    return false;
}

bool GameState::apply_state_994([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_994;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2303_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_state_996(mr,rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old2303_0;
    return false;
}

bool GameState::apply_state_995([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_995;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2304_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_state_1002(mr,rgCache))
    {
        return true;
    }
    coord = old2304_0;
    return false;
}

bool GameState::apply_state_996([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_996;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2305_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_state_997(mr,rgCache))
    {
        return true;
    }
    counters[w] = old2305_0;
    return false;
}

bool GameState::apply_state_997([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_997;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old2306_0 = board[coord];
    board[coord] = w;
    if (apply_state_995(mr,rgCache))
    {
        return true;
    }
    board[coord] = old2306_0;
    return false;
}

bool GameState::switch_11([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
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
    return switch_11(mr ,rgCache);
    return false;
}

bool GameState::apply_state_end([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return false;
}

bool GameState::apply_any_121_121_121([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_132.reset();
    const auto result_135 = is_legal_126_127_126(rgCache);
    rgCache.decDepth();
    if (!result_135)
    {
        if (apply_any_121_121_124(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (apply_any_121_121_140(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_124([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_124;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_181.reset();
    const auto result_136 = is_legal_173_174_173(rgCache);
    rgCache.decDepth();
    if (!result_136)
    {
        if (apply_any_121_121_171(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (apply_any_121_121_190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_140([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==w)
    {
        if (apply_any_121_121_142(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_142([[maybe_unused]]RgCache& rgCache)
{
    const auto old139_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_144(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old139_0;
    return false;
}

bool GameState::apply_any_121_121_143([[maybe_unused]]RgCache& rgCache)
{
    const auto old140_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (apply_any_121_121_149(rgCache))
    {
        return true;
    }
    coord = old140_0;
    return false;
}

bool GameState::apply_any_121_121_144([[maybe_unused]]RgCache& rgCache)
{
    const auto old141_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_145(rgCache))
    {
        return true;
    }
    counters[b] = old141_0;
    return false;
}

bool GameState::apply_any_121_121_145([[maybe_unused]]RgCache& rgCache)
{
    const auto old142_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = b;
    if (apply_any_121_121_143(rgCache))
    {
        return true;
    }
    board[RbgCoordMap1[coord]] = old142_0;
    return false;
}

bool GameState::apply_any_121_121_149([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_149;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_150(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_150([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (apply_any_121_121_153(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_153([[maybe_unused]]RgCache& rgCache)
{
    const auto old146_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_155(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old146_0;
    return false;
}

bool GameState::apply_any_121_121_154([[maybe_unused]]RgCache& rgCache)
{
    const auto old271_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_any_121_121_149(rgCache))
    {
        return true;
    }
    coord = old271_0;
    return false;
}

bool GameState::apply_any_121_121_155([[maybe_unused]]RgCache& rgCache)
{
    const auto old147_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_156(rgCache))
    {
        return true;
    }
    counters[b] = old147_0;
    return false;
}

bool GameState::apply_any_121_121_156([[maybe_unused]]RgCache& rgCache)
{
    const auto old148_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_154(rgCache))
    {
        return true;
    }
    board[coord] = old148_0;
    return false;
}

bool GameState::apply_any_121_121_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old149_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_121_121_end(rgCache))
    {
        return true;
    }
    player = old149_0;
    return false;
}

bool GameState::apply_any_121_121_1600([[maybe_unused]]RgCache& rgCache)
{
    const auto old268_0 = player;
    player = keeper;
    currentState = 802;
    return true;
    if (apply_any_121_121_770(rgCache))
    {
        return true;
    }
    player = old268_0;
    return false;
}

bool GameState::apply_any_121_121_1602([[maybe_unused]]RgCache& rgCache)
{
    const auto old270_0 = player;
    player = white;
    currentState = 808;
    return true;
    if (apply_any_121_121_793(rgCache))
    {
        return true;
    }
    player = old270_0;
    return false;
}

bool GameState::apply_any_121_121_161([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_161;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old150_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_any_121_121_163(rgCache))
    {
        return true;
    }
    coord = old150_0;
    return false;
}

bool GameState::apply_any_121_121_163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_124(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_161(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_171([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_171;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_234.reset();
    const auto result_153 = is_legal_228_229_228(rgCache);
    rgCache.decDepth();
    if (!result_153)
    {
        if (apply_any_121_121_226(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap2[coord]!=null)
    {
        if (apply_any_121_121_242(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_190([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==w)
    {
        if (apply_any_121_121_193(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_193([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_193;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old156_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_195(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old156_0;
    return false;
}

bool GameState::apply_any_121_121_194([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_194;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old157_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (apply_any_121_121_201(rgCache))
    {
        return true;
    }
    coord = old157_0;
    return false;
}

bool GameState::apply_any_121_121_195([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_195;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old158_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_196(rgCache))
    {
        return true;
    }
    counters[b] = old158_0;
    return false;
}

bool GameState::apply_any_121_121_196([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_196;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old159_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = b;
    if (apply_any_121_121_194(rgCache))
    {
        return true;
    }
    board[direction_up[coord - 1]] = old159_0;
    return false;
}

bool GameState::apply_any_121_121_201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_202(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_205(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_205([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_205;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old163_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_207(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old163_0;
    return false;
}

bool GameState::apply_any_121_121_206([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_206;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old272_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_any_121_121_201(rgCache))
    {
        return true;
    }
    coord = old272_0;
    return false;
}

bool GameState::apply_any_121_121_207([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_207;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old164_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_208(rgCache))
    {
        return true;
    }
    counters[b] = old164_0;
    return false;
}

bool GameState::apply_any_121_121_208([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_208;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old165_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_206(rgCache))
    {
        return true;
    }
    board[coord] = old165_0;
    return false;
}

bool GameState::apply_any_121_121_214([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_214;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old166_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_any_121_121_217(rgCache))
    {
        return true;
    }
    coord = old166_0;
    return false;
}

bool GameState::apply_any_121_121_217([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_217;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_218(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_218([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_218;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_171(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_214(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_226([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_226;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_283.reset();
    const auto result_169 = is_legal_275_276_275(rgCache);
    rgCache.decDepth();
    if (!result_169)
    {
        if (apply_any_121_121_273(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (apply_any_121_121_292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_242([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_242;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==w)
    {
        if (apply_any_121_121_244(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_244([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_244;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old172_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_246(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old172_0;
    return false;
}

bool GameState::apply_any_121_121_245([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_245;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old173_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (apply_any_121_121_251(rgCache))
    {
        return true;
    }
    coord = old173_0;
    return false;
}

bool GameState::apply_any_121_121_246([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_246;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old174_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_247(rgCache))
    {
        return true;
    }
    counters[b] = old174_0;
    return false;
}

bool GameState::apply_any_121_121_247([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_247;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old175_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = b;
    if (apply_any_121_121_245(rgCache))
    {
        return true;
    }
    board[RbgCoordMap2[coord]] = old175_0;
    return false;
}

bool GameState::apply_any_121_121_251([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_251;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_252(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_252([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_252;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_255(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old179_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_257(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old179_0;
    return false;
}

bool GameState::apply_any_121_121_256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old273_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_any_121_121_251(rgCache))
    {
        return true;
    }
    coord = old273_0;
    return false;
}

bool GameState::apply_any_121_121_257([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_257;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old180_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_258(rgCache))
    {
        return true;
    }
    counters[b] = old180_0;
    return false;
}

bool GameState::apply_any_121_121_258([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_258;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old181_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_256(rgCache))
    {
        return true;
    }
    board[coord] = old181_0;
    return false;
}

bool GameState::apply_any_121_121_263([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_263;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old182_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_any_121_121_265(rgCache))
    {
        return true;
    }
    coord = old182_0;
    return false;
}

bool GameState::apply_any_121_121_265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_226(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_263(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_273([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_273;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_338.reset();
    const auto result_185 = is_legal_330_331_330(rgCache);
    rgCache.decDepth();
    if (!result_185)
    {
        if (apply_any_121_121_328(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (apply_any_121_121_347(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_292([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_292;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==w)
    {
        if (apply_any_121_121_295(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_295([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_295;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old188_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_297(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old188_0;
    return false;
}

bool GameState::apply_any_121_121_296([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_296;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old189_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (apply_any_121_121_303(rgCache))
    {
        return true;
    }
    coord = old189_0;
    return false;
}

bool GameState::apply_any_121_121_297([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_297;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old190_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_298(rgCache))
    {
        return true;
    }
    counters[b] = old190_0;
    return false;
}

bool GameState::apply_any_121_121_298([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_298;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old191_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = b;
    if (apply_any_121_121_296(rgCache))
    {
        return true;
    }
    board[direction_left[coord - 1]] = old191_0;
    return false;
}

bool GameState::apply_any_121_121_303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_304(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_307(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_307([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_307;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old195_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_309(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old195_0;
    return false;
}

bool GameState::apply_any_121_121_308([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_308;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old274_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_any_121_121_303(rgCache))
    {
        return true;
    }
    coord = old274_0;
    return false;
}

bool GameState::apply_any_121_121_309([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_309;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old196_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_310(rgCache))
    {
        return true;
    }
    counters[b] = old196_0;
    return false;
}

bool GameState::apply_any_121_121_310([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_310;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old197_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_308(rgCache))
    {
        return true;
    }
    board[coord] = old197_0;
    return false;
}

bool GameState::apply_any_121_121_316([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_316;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old198_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_any_121_121_319(rgCache))
    {
        return true;
    }
    coord = old198_0;
    return false;
}

bool GameState::apply_any_121_121_319([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_319;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_320(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_320([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_320;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_273(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_316(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_328([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_328;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_391.reset();
    const auto result_201 = is_legal_385_386_385(rgCache);
    rgCache.decDepth();
    if (!result_201)
    {
        if (apply_any_121_121_383(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (apply_any_121_121_399(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_347([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_347;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==w)
    {
        if (apply_any_121_121_350(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_350([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_350;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old204_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_352(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old204_0;
    return false;
}

bool GameState::apply_any_121_121_351([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_351;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old205_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (apply_any_121_121_358(rgCache))
    {
        return true;
    }
    coord = old205_0;
    return false;
}

bool GameState::apply_any_121_121_352([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_352;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old206_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_353(rgCache))
    {
        return true;
    }
    counters[b] = old206_0;
    return false;
}

bool GameState::apply_any_121_121_353([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_353;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old207_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = b;
    if (apply_any_121_121_351(rgCache))
    {
        return true;
    }
    board[direction_right[coord - 1]] = old207_0;
    return false;
}

bool GameState::apply_any_121_121_358([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_358;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_359(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_359([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_359;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_362(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_362([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_362;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old211_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_364(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old211_0;
    return false;
}

bool GameState::apply_any_121_121_363([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_363;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old275_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_any_121_121_358(rgCache))
    {
        return true;
    }
    coord = old275_0;
    return false;
}

bool GameState::apply_any_121_121_364([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_364;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old212_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_365(rgCache))
    {
        return true;
    }
    counters[b] = old212_0;
    return false;
}

bool GameState::apply_any_121_121_365([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_365;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old213_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_363(rgCache))
    {
        return true;
    }
    board[coord] = old213_0;
    return false;
}

bool GameState::apply_any_121_121_371([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_371;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old214_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_any_121_121_374(rgCache))
    {
        return true;
    }
    coord = old214_0;
    return false;
}

bool GameState::apply_any_121_121_374([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_374;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_375(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_375([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_375;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_328(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_371(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_383([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_383;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_440.reset();
    const auto result_217 = is_legal_432_433_432(rgCache);
    rgCache.decDepth();
    if (!result_217)
    {
        if (apply_any_121_121_430(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (apply_any_121_121_449(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_399([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_399;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==w)
    {
        if (apply_any_121_121_401(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_401([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_401;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old220_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_403(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old220_0;
    return false;
}

bool GameState::apply_any_121_121_402([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_402;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old221_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (apply_any_121_121_408(rgCache))
    {
        return true;
    }
    coord = old221_0;
    return false;
}

bool GameState::apply_any_121_121_403([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_403;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old222_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_404(rgCache))
    {
        return true;
    }
    counters[b] = old222_0;
    return false;
}

bool GameState::apply_any_121_121_404([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_404;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old223_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = b;
    if (apply_any_121_121_402(rgCache))
    {
        return true;
    }
    board[RbgCoordMap3[coord]] = old223_0;
    return false;
}

bool GameState::apply_any_121_121_408([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_408;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_409(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_409([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_409;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_412(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_412([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_412;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old227_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_414(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old227_0;
    return false;
}

bool GameState::apply_any_121_121_413([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_413;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old276_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_any_121_121_408(rgCache))
    {
        return true;
    }
    coord = old276_0;
    return false;
}

bool GameState::apply_any_121_121_414([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_414;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old228_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_415(rgCache))
    {
        return true;
    }
    counters[b] = old228_0;
    return false;
}

bool GameState::apply_any_121_121_415([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_415;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old229_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_413(rgCache))
    {
        return true;
    }
    board[coord] = old229_0;
    return false;
}

bool GameState::apply_any_121_121_420([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_420;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old230_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_any_121_121_422(rgCache))
    {
        return true;
    }
    coord = old230_0;
    return false;
}

bool GameState::apply_any_121_121_422([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_422;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_423(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_423([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_423;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_383(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_420(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_430([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_430;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_493.reset();
    const auto result_233 = is_legal_487_488_487(rgCache);
    rgCache.decDepth();
    if (!result_233)
    {
        if (apply_any_121_121_485(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (apply_any_121_121_501(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_449([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_449;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==w)
    {
        if (apply_any_121_121_452(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_452([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_452;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old236_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_454(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old236_0;
    return false;
}

bool GameState::apply_any_121_121_453([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_453;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old237_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (apply_any_121_121_460(rgCache))
    {
        return true;
    }
    coord = old237_0;
    return false;
}

bool GameState::apply_any_121_121_454([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_454;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old238_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_455(rgCache))
    {
        return true;
    }
    counters[b] = old238_0;
    return false;
}

bool GameState::apply_any_121_121_455([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_455;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old239_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = b;
    if (apply_any_121_121_453(rgCache))
    {
        return true;
    }
    board[direction_down[coord - 1]] = old239_0;
    return false;
}

bool GameState::apply_any_121_121_460([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_460;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_461(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_461([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_461;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_464(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_464([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_464;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old243_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_466(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old243_0;
    return false;
}

bool GameState::apply_any_121_121_465([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_465;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old277_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_any_121_121_460(rgCache))
    {
        return true;
    }
    coord = old277_0;
    return false;
}

bool GameState::apply_any_121_121_466([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_466;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old244_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_467(rgCache))
    {
        return true;
    }
    counters[b] = old244_0;
    return false;
}

bool GameState::apply_any_121_121_467([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_467;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old245_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_465(rgCache))
    {
        return true;
    }
    board[coord] = old245_0;
    return false;
}

bool GameState::apply_any_121_121_473([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_473;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old246_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_any_121_121_476(rgCache))
    {
        return true;
    }
    coord = old246_0;
    return false;
}

bool GameState::apply_any_121_121_476([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_476;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_477(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_477([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_477;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_430(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_473(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_485([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_485;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old249_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    if (apply_any_121_121_533(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(e)] = old249_0;
    return false;
}

bool GameState::apply_any_121_121_501([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_501;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==w)
    {
        if (apply_any_121_121_503(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_503([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_503;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old252_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_505(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old252_0;
    return false;
}

bool GameState::apply_any_121_121_504([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_504;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old253_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (apply_any_121_121_510(rgCache))
    {
        return true;
    }
    coord = old253_0;
    return false;
}

bool GameState::apply_any_121_121_505([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_505;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old254_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_506(rgCache))
    {
        return true;
    }
    counters[b] = old254_0;
    return false;
}

bool GameState::apply_any_121_121_506([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_506;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old255_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = b;
    if (apply_any_121_121_504(rgCache))
    {
        return true;
    }
    board[RbgCoordMap4[coord]] = old255_0;
    return false;
}

bool GameState::apply_any_121_121_510([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_510;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_511(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_511([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_511;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_121_121_514(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_522(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_514([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_514;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old259_0 = counters[static_cast<Piece>(w)];
    counters[static_cast<Piece>(w)] = counters[static_cast<Piece>(w)]-1;
    if (apply_any_121_121_516(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(w)] = old259_0;
    return false;
}

bool GameState::apply_any_121_121_515([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_515;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old278_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_any_121_121_510(rgCache))
    {
        return true;
    }
    coord = old278_0;
    return false;
}

bool GameState::apply_any_121_121_516([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_516;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old260_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_517(rgCache))
    {
        return true;
    }
    counters[b] = old260_0;
    return false;
}

bool GameState::apply_any_121_121_517([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_517;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old261_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_515(rgCache))
    {
        return true;
    }
    board[coord] = old261_0;
    return false;
}

bool GameState::apply_any_121_121_522([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_522;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old262_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_any_121_121_524(rgCache))
    {
        return true;
    }
    coord = old262_0;
    return false;
}

bool GameState::apply_any_121_121_524([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_524;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_121_121_525(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_121_121_525([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_525;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_121_121_485(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_121_121_522(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_121_121_533([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_533;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old265_0 = counters[b];
    counters[b] = counters[b]+1;
    if (apply_any_121_121_534(rgCache))
    {
        return true;
    }
    counters[b] = old265_0;
    return false;
}

bool GameState::apply_any_121_121_534([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_534;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old266_0 = board[coord];
    board[coord] = b;
    if (apply_any_121_121_7(rgCache))
    {
        return true;
    }
    board[coord] = old266_0;
    return false;
}

bool GameState::apply_any_121_121_546([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_557.reset();
    rgCache.state_cache_571.reset();
    rgCache.state_cache_584.reset();
    rgCache.state_cache_598.reset();
    rgCache.state_cache_613.reset();
    rgCache.state_cache_626.reset();
    rgCache.state_cache_640.reset();
    rgCache.state_cache_653.reset();
    rgCache.state_cache_665.reset();
    rgCache.state_cache_679.reset();
    rgCache.state_cache_692.reset();
    rgCache.state_cache_706.reset();
    rgCache.state_cache_721.reset();
    rgCache.state_cache_734.reset();
    rgCache.state_cache_748.reset();
    rgCache.state_cache_761.reset();
    const auto result_292 = is_legal_548_549_548(rgCache);
    rgCache.decDepth();
    if (!result_292)
    {
        if (apply_any_121_121_772(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_121_121_795(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_7([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_7;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_121_121_546(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_770([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_121_121_771([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_770_790_770_770_790_790_770_790_770())
    {
        if (apply_any_121_121_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_121_121_1600(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_772([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_121_121_771(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_793([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_121_121_794([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1588_1589_1588(rgCache))
    {
        if (apply_any_121_121_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_121_121_1602(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_795([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_121_121_794(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_121_121_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_1559_1559_1559([[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]<counters[b])==1)
    {
        if (apply_any_1559_1559_1567(rgCache))
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (apply_any_1559_1559_1571(rgCache))
        {
            return true;
        }
    }
    if ((counters[w]>counters[b])==1)
    {
        if (apply_any_1559_1559_774(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_1559_1559_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old12_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_1559_1559_end(rgCache))
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_1559_1559_1567([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_1559_1559_1562(rgCache))
    {
        return true;
    }
    goals[black - 2] = old9_0;
    return false;
}

bool GameState::apply_any_1559_1559_1571([[maybe_unused]]RgCache& rgCache)
{
    const auto old10_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_any_1559_1559_1573(rgCache))
    {
        return true;
    }
    goals[black - 2] = old10_0;
    return false;
}

bool GameState::apply_any_1559_1559_1573([[maybe_unused]]RgCache& rgCache)
{
    const auto old11_0 = goals[white - 2];
    goals[white - 2] = 50;
    if (apply_any_1559_1559_1562(rgCache))
    {
        return true;
    }
    goals[white - 2] = old11_0;
    return false;
}

bool GameState::apply_any_1559_1559_774([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_1559_1559_1562(rgCache))
    {
        return true;
    }
    goals[white - 2] = old13_0;
    return false;
}

bool GameState::apply_any_1559_1559_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_7_7_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old12_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_7_7_end(rgCache))
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_7_7_1600([[maybe_unused]]RgCache& rgCache)
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 802;
    return true;
    if (apply_any_7_7_770(rgCache))
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_7_7_1602([[maybe_unused]]RgCache& rgCache)
{
    const auto old16_0 = player;
    player = white;
    currentState = 808;
    return true;
    if (apply_any_7_7_793(rgCache))
    {
        return true;
    }
    player = old16_0;
    return false;
}

bool GameState::apply_any_7_7_546([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_557.reset();
    rgCache.state_cache_571.reset();
    rgCache.state_cache_584.reset();
    rgCache.state_cache_598.reset();
    rgCache.state_cache_613.reset();
    rgCache.state_cache_626.reset();
    rgCache.state_cache_640.reset();
    rgCache.state_cache_653.reset();
    rgCache.state_cache_665.reset();
    rgCache.state_cache_679.reset();
    rgCache.state_cache_692.reset();
    rgCache.state_cache_706.reset();
    rgCache.state_cache_721.reset();
    rgCache.state_cache_734.reset();
    rgCache.state_cache_748.reset();
    rgCache.state_cache_761.reset();
    const auto result_22 = is_legal_548_549_548(rgCache);
    rgCache.decDepth();
    if (!result_22)
    {
        if (apply_any_7_7_772(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_7_7_795(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_7([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_7;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_7_7_546(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_770([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_7_7_771([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_770_790_770_770_790_790_770_790_770())
    {
        if (apply_any_7_7_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_7_7_1600(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_772([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_7_7_771(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_793([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_7_7_794([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1588_1589_1588(rgCache))
    {
        if (apply_any_7_7_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_7_7_1602(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_795([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_7_7_794(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_7_7_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_770_770_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old10_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_770_770_end(rgCache))
    {
        return true;
    }
    player = old10_0;
    return false;
}

bool GameState::apply_any_770_770_1567([[maybe_unused]]RgCache& rgCache)
{
    const auto old7_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_770_770_1562(rgCache))
    {
        return true;
    }
    goals[black - 2] = old7_0;
    return false;
}

bool GameState::apply_any_770_770_1571([[maybe_unused]]RgCache& rgCache)
{
    const auto old8_0 = goals[black - 2];
    goals[black - 2] = 50;
    if (apply_any_770_770_1573(rgCache))
    {
        return true;
    }
    goals[black - 2] = old8_0;
    return false;
}

bool GameState::apply_any_770_770_1573([[maybe_unused]]RgCache& rgCache)
{
    const auto old9_0 = goals[white - 2];
    goals[white - 2] = 50;
    if (apply_any_770_770_1562(rgCache))
    {
        return true;
    }
    goals[white - 2] = old9_0;
    return false;
}

bool GameState::apply_any_770_770_770([[maybe_unused]]RgCache& rgCache)
{
    if ((counters[w]>counters[b])==1)
    {
        if (apply_any_770_770_774(rgCache))
        {
            return true;
        }
    }
    if ((counters[w]<counters[b])==1)
    {
        if (apply_any_770_770_1567(rgCache))
        {
            return true;
        }
    }
    if (counters[w]==counters[b])
    {
        if (apply_any_770_770_1571(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_770_770_774([[maybe_unused]]RgCache& rgCache)
{
    const auto old12_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_770_770_1562(rgCache))
    {
        return true;
    }
    goals[white - 2] = old12_0;
    return false;
}

bool GameState::apply_any_770_770_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_796_796_1558([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1558;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_796_796_1561(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_1559([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_796_796_1560([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1559())
    {
        if (apply_any_796_796_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_796_796_1608(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_1561([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_796_796_1560(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old15_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_796_796_end(rgCache))
    {
        return true;
    }
    player = old15_0;
    return false;
}

bool GameState::apply_any_796_796_1594([[maybe_unused]]RgCache& rgCache)
{
    const auto old21_0 = player;
    player = black;
    currentState = 640;
    return true;
    if (apply_any_796_796_4(rgCache))
    {
        return true;
    }
    player = old21_0;
    return false;
}

bool GameState::apply_any_796_796_1608([[maybe_unused]]RgCache& rgCache)
{
    const auto old23_0 = player;
    player = keeper;
    currentState = 503;
    return true;
    if (apply_any_796_796_1559(rgCache))
    {
        return true;
    }
    player = old23_0;
    return false;
}

bool GameState::apply_any_796_796_2([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_796_796_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_796_796_5([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1582_1583_1582(rgCache))
    {
        if (apply_any_796_796_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_796_796_1594(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_796_796_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_796([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_796;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1346.reset();
    rgCache.state_cache_1360.reset();
    rgCache.state_cache_1373.reset();
    rgCache.state_cache_1387.reset();
    rgCache.state_cache_1402.reset();
    rgCache.state_cache_1415.reset();
    rgCache.state_cache_1429.reset();
    rgCache.state_cache_1442.reset();
    rgCache.state_cache_1454.reset();
    rgCache.state_cache_1468.reset();
    rgCache.state_cache_1481.reset();
    rgCache.state_cache_1495.reset();
    rgCache.state_cache_1510.reset();
    rgCache.state_cache_1523.reset();
    rgCache.state_cache_1537.reset();
    rgCache.state_cache_1550.reset();
    const auto result_19 = is_legal_1337_1338_1337(rgCache);
    rgCache.decDepth();
    if (!result_19)
    {
        if (apply_any_796_796_1558(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_796_796_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_796_796_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_910_910_1002([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1002;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_991(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1003([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1003;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old137_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_any_910_910_1006(rgCache))
    {
        return true;
    }
    coord = old137_0;
    return false;
}

bool GameState::apply_any_910_910_1006([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1006;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1007(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1007([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1007;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_910_910_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==e)
    {
        if (apply_any_910_910_960(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1015([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1015;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1072.reset();
    const auto result_140 = is_legal_1064_1065_1064(rgCache);
    rgCache.decDepth();
    if (!result_140)
    {
        if (apply_any_910_910_1062(rgCache))
        {
            return true;
        }
    }
    if (direction_left[coord - 1]!=null)
    {
        if (apply_any_910_910_1081(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1031([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1031;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap2[coord]]==b)
    {
        if (apply_any_910_910_1033(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1033([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1033;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old143_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1035(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old143_0;
    return false;
}

bool GameState::apply_any_910_910_1034([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1034;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old144_0 = coord;
    coord = __gen_RbgCoordMap2_RbgCoordMap2[coord];
    if (apply_any_910_910_1040(rgCache))
    {
        return true;
    }
    coord = old144_0;
    return false;
}

bool GameState::apply_any_910_910_1035([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1035;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old145_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1036(rgCache))
    {
        return true;
    }
    counters[w] = old145_0;
    return false;
}

bool GameState::apply_any_910_910_1036([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1036;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old146_0 = board[RbgCoordMap2[coord]];
    board[RbgCoordMap2[coord]] = w;
    if (apply_any_910_910_1034(rgCache))
    {
        return true;
    }
    board[RbgCoordMap2[coord]] = old146_0;
    return false;
}

bool GameState::apply_any_910_910_1040([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1040;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1041(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1041([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1041;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1044(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1044([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1044;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old150_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1046(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old150_0;
    return false;
}

bool GameState::apply_any_910_910_1045([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1045;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old278_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_any_910_910_1040(rgCache))
    {
        return true;
    }
    coord = old278_0;
    return false;
}

bool GameState::apply_any_910_910_1046([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1046;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old151_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1047(rgCache))
    {
        return true;
    }
    counters[w] = old151_0;
    return false;
}

bool GameState::apply_any_910_910_1047([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1047;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old152_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1045(rgCache))
    {
        return true;
    }
    board[coord] = old152_0;
    return false;
}

bool GameState::apply_any_910_910_1052([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1052;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old153_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_any_910_910_1054(rgCache))
    {
        return true;
    }
    coord = old153_0;
    return false;
}

bool GameState::apply_any_910_910_1054([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1054;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1055(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1055([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1055;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1015(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1052(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1062([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1062;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1127.reset();
    const auto result_156 = is_legal_1119_1120_1119(rgCache);
    rgCache.decDepth();
    if (!result_156)
    {
        if (apply_any_910_910_1117(rgCache))
        {
            return true;
        }
    }
    if (direction_right[coord - 1]!=null)
    {
        if (apply_any_910_910_1136(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1081([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1081;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_left[coord - 1]]==b)
    {
        if (apply_any_910_910_1084(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1084([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1084;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old159_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1086(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old159_0;
    return false;
}

bool GameState::apply_any_910_910_1085([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1085;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old160_0 = coord;
    coord = __gen_direction_left_direction_left[coord - 1];
    if (apply_any_910_910_1092(rgCache))
    {
        return true;
    }
    coord = old160_0;
    return false;
}

bool GameState::apply_any_910_910_1086([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1086;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old161_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1087(rgCache))
    {
        return true;
    }
    counters[w] = old161_0;
    return false;
}

bool GameState::apply_any_910_910_1087([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1087;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old162_0 = board[direction_left[coord - 1]];
    board[direction_left[coord - 1]] = w;
    if (apply_any_910_910_1085(rgCache))
    {
        return true;
    }
    board[direction_left[coord - 1]] = old162_0;
    return false;
}

bool GameState::apply_any_910_910_1092([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1092;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1093(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1093([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1093;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1096(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1096([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1096;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old166_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1098(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old166_0;
    return false;
}

bool GameState::apply_any_910_910_1097([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1097;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old279_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_any_910_910_1092(rgCache))
    {
        return true;
    }
    coord = old279_0;
    return false;
}

bool GameState::apply_any_910_910_1098([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1098;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old167_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1099(rgCache))
    {
        return true;
    }
    counters[w] = old167_0;
    return false;
}

bool GameState::apply_any_910_910_1099([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1099;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old168_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1097(rgCache))
    {
        return true;
    }
    board[coord] = old168_0;
    return false;
}

bool GameState::apply_any_910_910_1105([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1105;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old169_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_any_910_910_1108(rgCache))
    {
        return true;
    }
    coord = old169_0;
    return false;
}

bool GameState::apply_any_910_910_1108([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1108;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1109(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1109([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1109;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1062(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1105(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1117([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1117;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1180.reset();
    const auto result_172 = is_legal_1174_1175_1174(rgCache);
    rgCache.decDepth();
    if (!result_172)
    {
        if (apply_any_910_910_1172(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap3[coord]!=null)
    {
        if (apply_any_910_910_1188(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1136([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1136;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_right[coord - 1]]==b)
    {
        if (apply_any_910_910_1139(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1139([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1139;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old175_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1141(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old175_0;
    return false;
}

bool GameState::apply_any_910_910_1140([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1140;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old176_0 = coord;
    coord = __gen_direction_right_direction_right[coord - 1];
    if (apply_any_910_910_1147(rgCache))
    {
        return true;
    }
    coord = old176_0;
    return false;
}

bool GameState::apply_any_910_910_1141([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1141;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old177_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1142(rgCache))
    {
        return true;
    }
    counters[w] = old177_0;
    return false;
}

bool GameState::apply_any_910_910_1142([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1142;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old178_0 = board[direction_right[coord - 1]];
    board[direction_right[coord - 1]] = w;
    if (apply_any_910_910_1140(rgCache))
    {
        return true;
    }
    board[direction_right[coord - 1]] = old178_0;
    return false;
}

bool GameState::apply_any_910_910_1147([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1147;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1148(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1148([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1148;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1151(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1151([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1151;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old182_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1153(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old182_0;
    return false;
}

bool GameState::apply_any_910_910_1152([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1152;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old280_0 = coord;
    coord = direction_right[coord - 1];
    if (apply_any_910_910_1147(rgCache))
    {
        return true;
    }
    coord = old280_0;
    return false;
}

bool GameState::apply_any_910_910_1153([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1153;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old183_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1154(rgCache))
    {
        return true;
    }
    counters[w] = old183_0;
    return false;
}

bool GameState::apply_any_910_910_1154([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1154;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old184_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1152(rgCache))
    {
        return true;
    }
    board[coord] = old184_0;
    return false;
}

bool GameState::apply_any_910_910_1160([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1160;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old185_0 = coord;
    coord = direction_left[coord - 1];
    if (apply_any_910_910_1163(rgCache))
    {
        return true;
    }
    coord = old185_0;
    return false;
}

bool GameState::apply_any_910_910_1163([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1163;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1164(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1164([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1164;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1117(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1160(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1172([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1172;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1229.reset();
    const auto result_188 = is_legal_1221_1222_1221(rgCache);
    rgCache.decDepth();
    if (!result_188)
    {
        if (apply_any_910_910_1219(rgCache))
        {
            return true;
        }
    }
    if (direction_down[coord - 1]!=null)
    {
        if (apply_any_910_910_1238(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1188([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1188;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap3[coord]]==b)
    {
        if (apply_any_910_910_1190(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1190([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1190;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old191_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1192(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old191_0;
    return false;
}

bool GameState::apply_any_910_910_1191([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1191;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old192_0 = coord;
    coord = __gen_RbgCoordMap3_RbgCoordMap3[coord];
    if (apply_any_910_910_1197(rgCache))
    {
        return true;
    }
    coord = old192_0;
    return false;
}

bool GameState::apply_any_910_910_1192([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1192;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old193_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1193(rgCache))
    {
        return true;
    }
    counters[w] = old193_0;
    return false;
}

bool GameState::apply_any_910_910_1193([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1193;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old194_0 = board[RbgCoordMap3[coord]];
    board[RbgCoordMap3[coord]] = w;
    if (apply_any_910_910_1191(rgCache))
    {
        return true;
    }
    board[RbgCoordMap3[coord]] = old194_0;
    return false;
}

bool GameState::apply_any_910_910_1197([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1197;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1198(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1198([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1198;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1201(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1201([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1201;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old198_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1203(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old198_0;
    return false;
}

bool GameState::apply_any_910_910_1202([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1202;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old281_0 = coord;
    coord = RbgCoordMap3[coord];
    if (apply_any_910_910_1197(rgCache))
    {
        return true;
    }
    coord = old281_0;
    return false;
}

bool GameState::apply_any_910_910_1203([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1203;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old199_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1204(rgCache))
    {
        return true;
    }
    counters[w] = old199_0;
    return false;
}

bool GameState::apply_any_910_910_1204([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1204;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old200_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1202(rgCache))
    {
        return true;
    }
    board[coord] = old200_0;
    return false;
}

bool GameState::apply_any_910_910_1209([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1209;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old201_0 = coord;
    coord = RbgCoordMap2[coord];
    if (apply_any_910_910_1211(rgCache))
    {
        return true;
    }
    coord = old201_0;
    return false;
}

bool GameState::apply_any_910_910_1211([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1211;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1212(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1212([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1212;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1172(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1209(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1219([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1219;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1282.reset();
    const auto result_204 = is_legal_1276_1277_1276(rgCache);
    rgCache.decDepth();
    if (!result_204)
    {
        if (apply_any_910_910_1274(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap4[coord]!=null)
    {
        if (apply_any_910_910_1290(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1238([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1238;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_down[coord - 1]]==b)
    {
        if (apply_any_910_910_1241(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1241([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1241;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old207_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1243(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old207_0;
    return false;
}

bool GameState::apply_any_910_910_1242([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1242;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old208_0 = coord;
    coord = __gen_direction_down_direction_down[coord - 1];
    if (apply_any_910_910_1249(rgCache))
    {
        return true;
    }
    coord = old208_0;
    return false;
}

bool GameState::apply_any_910_910_1243([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1243;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old209_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1244(rgCache))
    {
        return true;
    }
    counters[w] = old209_0;
    return false;
}

bool GameState::apply_any_910_910_1244([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1244;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old210_0 = board[direction_down[coord - 1]];
    board[direction_down[coord - 1]] = w;
    if (apply_any_910_910_1242(rgCache))
    {
        return true;
    }
    board[direction_down[coord - 1]] = old210_0;
    return false;
}

bool GameState::apply_any_910_910_1249([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1249;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1250(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1250([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1250;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1253(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1253([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1253;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old214_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1255(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old214_0;
    return false;
}

bool GameState::apply_any_910_910_1254([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1254;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old282_0 = coord;
    coord = direction_down[coord - 1];
    if (apply_any_910_910_1249(rgCache))
    {
        return true;
    }
    coord = old282_0;
    return false;
}

bool GameState::apply_any_910_910_1255([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1255;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old215_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1256(rgCache))
    {
        return true;
    }
    counters[w] = old215_0;
    return false;
}

bool GameState::apply_any_910_910_1256([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1256;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old216_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1254(rgCache))
    {
        return true;
    }
    board[coord] = old216_0;
    return false;
}

bool GameState::apply_any_910_910_1262([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1262;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old217_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_any_910_910_1265(rgCache))
    {
        return true;
    }
    coord = old217_0;
    return false;
}

bool GameState::apply_any_910_910_1265([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1265;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1266(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1266([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1266;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1219(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1262(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1274([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1274;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old220_0 = counters[static_cast<Piece>(e)];
    counters[static_cast<Piece>(e)] = counters[static_cast<Piece>(e)]-1;
    if (apply_any_910_910_1322(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(e)] = old220_0;
    return false;
}

bool GameState::apply_any_910_910_1290([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1290;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[RbgCoordMap4[coord]]==b)
    {
        if (apply_any_910_910_1292(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1292([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1292;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old223_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1294(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old223_0;
    return false;
}

bool GameState::apply_any_910_910_1293([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1293;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old224_0 = coord;
    coord = __gen_RbgCoordMap4_RbgCoordMap4[coord];
    if (apply_any_910_910_1299(rgCache))
    {
        return true;
    }
    coord = old224_0;
    return false;
}

bool GameState::apply_any_910_910_1294([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1294;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old225_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1295(rgCache))
    {
        return true;
    }
    counters[w] = old225_0;
    return false;
}

bool GameState::apply_any_910_910_1295([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1295;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old226_0 = board[RbgCoordMap4[coord]];
    board[RbgCoordMap4[coord]] = w;
    if (apply_any_910_910_1293(rgCache))
    {
        return true;
    }
    board[RbgCoordMap4[coord]] = old226_0;
    return false;
}

bool GameState::apply_any_910_910_1299([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1299;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1300(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1300([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1300;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==b)
    {
        if (apply_any_910_910_1303(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1303([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1303;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old230_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_1305(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old230_0;
    return false;
}

bool GameState::apply_any_910_910_1304([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1304;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old283_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_any_910_910_1299(rgCache))
    {
        return true;
    }
    coord = old283_0;
    return false;
}

bool GameState::apply_any_910_910_1305([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1305;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old231_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1306(rgCache))
    {
        return true;
    }
    counters[w] = old231_0;
    return false;
}

bool GameState::apply_any_910_910_1306([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1306;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old232_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_1304(rgCache))
    {
        return true;
    }
    board[coord] = old232_0;
    return false;
}

bool GameState::apply_any_910_910_1311([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1311;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old233_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_any_910_910_1313(rgCache))
    {
        return true;
    }
    coord = old233_0;
    return false;
}

bool GameState::apply_any_910_910_1313([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1313;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_1314(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_1314([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1314;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_1274(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_1311(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_1322([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1322;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old236_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_1323(rgCache))
    {
        return true;
    }
    counters[w] = old236_0;
    return false;
}

bool GameState::apply_any_910_910_1323([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1323;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old237_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_796(rgCache))
    {
        return true;
    }
    board[coord] = old237_0;
    return false;
}

bool GameState::apply_any_910_910_1558([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1558;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_910_910_1561(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_1559([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_910_910_1560([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1559_1579_1559_1559_1579_1579_1559_1579_1559())
    {
        if (apply_any_910_910_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_910_910_1608(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_1561([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_910_910_1560(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old240_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_910_910_end(rgCache))
    {
        return true;
    }
    player = old240_0;
    return false;
}

bool GameState::apply_any_910_910_1594([[maybe_unused]]RgCache& rgCache)
{
    const auto old275_0 = player;
    player = black;
    currentState = 640;
    return true;
    if (apply_any_910_910_4(rgCache))
    {
        return true;
    }
    player = old275_0;
    return false;
}

bool GameState::apply_any_910_910_1608([[maybe_unused]]RgCache& rgCache)
{
    const auto old277_0 = player;
    player = keeper;
    currentState = 503;
    return true;
    if (apply_any_910_910_1559(rgCache))
    {
        return true;
    }
    player = old277_0;
    return false;
}

bool GameState::apply_any_910_910_2([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (apply_any_910_910_6(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_4([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_910_910_5([[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_1582_1583_1582(rgCache))
    {
        if (apply_any_910_910_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_910_910_1594(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_6([[maybe_unused]]RgCache& rgCache)
{
    if (apply_any_910_910_5(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_796([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_796;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_1346.reset();
    rgCache.state_cache_1360.reset();
    rgCache.state_cache_1373.reset();
    rgCache.state_cache_1387.reset();
    rgCache.state_cache_1402.reset();
    rgCache.state_cache_1415.reset();
    rgCache.state_cache_1429.reset();
    rgCache.state_cache_1442.reset();
    rgCache.state_cache_1454.reset();
    rgCache.state_cache_1468.reset();
    rgCache.state_cache_1481.reset();
    rgCache.state_cache_1495.reset();
    rgCache.state_cache_1510.reset();
    rgCache.state_cache_1523.reset();
    rgCache.state_cache_1537.reset();
    rgCache.state_cache_1550.reset();
    const auto result_244 = is_legal_1337_1338_1337(rgCache);
    rgCache.decDepth();
    if (!result_244)
    {
        if (apply_any_910_910_1558(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_910_910_2(rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_910_910_910([[maybe_unused]]RgCache& rgCache)
{
    rgCache.incDepth();
    rgCache.state_cache_921.reset();
    const auto result_245 = is_legal_915_916_915(rgCache);
    rgCache.decDepth();
    if (!result_245)
    {
        if (apply_any_910_910_913(rgCache))
        {
            return true;
        }
    }
    if (RbgCoordMap1[coord]!=null)
    {
        if (apply_any_910_910_929(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_913([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_913;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    rgCache.incDepth();
    rgCache.state_cache_970.reset();
    const auto result_246 = is_legal_962_963_962(rgCache);
    rgCache.decDepth();
    if (!result_246)
    {
        if (apply_any_910_910_960(rgCache))
        {
            return true;
        }
    }
    if (direction_up[coord - 1]!=null)
    {
        if (apply_any_910_910_979(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_929([[maybe_unused]]RgCache& rgCache)
{
    if (board[RbgCoordMap1[coord]]==b)
    {
        if (apply_any_910_910_931(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_931([[maybe_unused]]RgCache& rgCache)
{
    const auto old249_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_933(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old249_0;
    return false;
}

bool GameState::apply_any_910_910_932([[maybe_unused]]RgCache& rgCache)
{
    const auto old250_0 = coord;
    coord = __gen_RbgCoordMap1_RbgCoordMap1[coord];
    if (apply_any_910_910_938(rgCache))
    {
        return true;
    }
    coord = old250_0;
    return false;
}

bool GameState::apply_any_910_910_933([[maybe_unused]]RgCache& rgCache)
{
    const auto old251_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_934(rgCache))
    {
        return true;
    }
    counters[w] = old251_0;
    return false;
}

bool GameState::apply_any_910_910_934([[maybe_unused]]RgCache& rgCache)
{
    const auto old252_0 = board[RbgCoordMap1[coord]];
    board[RbgCoordMap1[coord]] = w;
    if (apply_any_910_910_932(rgCache))
    {
        return true;
    }
    board[RbgCoordMap1[coord]] = old252_0;
    return false;
}

bool GameState::apply_any_910_910_938([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_938;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_939(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_939([[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_any_910_910_942(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_942([[maybe_unused]]RgCache& rgCache)
{
    const auto old256_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_944(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old256_0;
    return false;
}

bool GameState::apply_any_910_910_943([[maybe_unused]]RgCache& rgCache)
{
    const auto old284_0 = coord;
    coord = RbgCoordMap1[coord];
    if (apply_any_910_910_938(rgCache))
    {
        return true;
    }
    coord = old284_0;
    return false;
}

bool GameState::apply_any_910_910_944([[maybe_unused]]RgCache& rgCache)
{
    const auto old257_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_945(rgCache))
    {
        return true;
    }
    counters[w] = old257_0;
    return false;
}

bool GameState::apply_any_910_910_945([[maybe_unused]]RgCache& rgCache)
{
    const auto old258_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_943(rgCache))
    {
        return true;
    }
    board[coord] = old258_0;
    return false;
}

bool GameState::apply_any_910_910_950([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_950;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old259_0 = coord;
    coord = RbgCoordMap4[coord];
    if (apply_any_910_910_952(rgCache))
    {
        return true;
    }
    coord = old259_0;
    return false;
}

bool GameState::apply_any_910_910_952([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_952;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_any_910_910_953(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_953([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_953;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_any_910_910_913(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==w)
    {
        if (apply_any_910_910_950(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_960([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_960;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (RbgCoordMap2[coord]!=null)
    {
        if (apply_any_910_910_1031(rgCache))
        {
            return true;
        }
    }
    rgCache.incDepth();
    rgCache.state_cache_1023.reset();
    const auto result_262 = is_legal_1017_1018_1017(rgCache);
    rgCache.decDepth();
    if (!result_262)
    {
        if (apply_any_910_910_1015(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_979([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_979;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[direction_up[coord - 1]]==b)
    {
        if (apply_any_910_910_982(rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_910_910_982([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_982;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old265_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_984(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old265_0;
    return false;
}

bool GameState::apply_any_910_910_983([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_983;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old285_0 = coord;
    coord = __gen_direction_up_direction_up[coord - 1];
    if (apply_any_910_910_1002(rgCache))
    {
        return true;
    }
    coord = old285_0;
    return false;
}

bool GameState::apply_any_910_910_984([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_984;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old266_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_985(rgCache))
    {
        return true;
    }
    counters[w] = old266_0;
    return false;
}

bool GameState::apply_any_910_910_985([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_985;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old267_0 = board[direction_up[coord - 1]];
    board[direction_up[coord - 1]] = w;
    if (apply_any_910_910_983(rgCache))
    {
        return true;
    }
    board[direction_up[coord - 1]] = old267_0;
    return false;
}

bool GameState::apply_any_910_910_991([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_991;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==w)
    {
        if (apply_any_910_910_1003(rgCache))
        {
            return true;
        }
        return false;
    }
    if (board[coord]==b)
    {
        if (apply_any_910_910_994(rgCache))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool GameState::apply_any_910_910_994([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_994;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old270_0 = counters[static_cast<Piece>(b)];
    counters[static_cast<Piece>(b)] = counters[static_cast<Piece>(b)]-1;
    if (apply_any_910_910_996(rgCache))
    {
        return true;
    }
    counters[static_cast<Piece>(b)] = old270_0;
    return false;
}

bool GameState::apply_any_910_910_995([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_995;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old271_0 = coord;
    coord = direction_up[coord - 1];
    if (apply_any_910_910_1002(rgCache))
    {
        return true;
    }
    coord = old271_0;
    return false;
}

bool GameState::apply_any_910_910_996([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_996;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old272_0 = counters[w];
    counters[w] = counters[w]+1;
    if (apply_any_910_910_997(rgCache))
    {
        return true;
    }
    counters[w] = old272_0;
    return false;
}

bool GameState::apply_any_910_910_997([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_997;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    const auto old273_0 = board[coord];
    board[coord] = w;
    if (apply_any_910_910_995(rgCache))
    {
        return true;
    }
    board[coord] = old273_0;
    return false;
}

bool GameState::apply_any_910_910_end([[maybe_unused]]RgCache& rgCache)
{
    return true;
}

bool GameState::apply_any_begin_begin_1562([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_1562;
    if (cache)
    {
        return false;
    }
    cache = true;
    const auto old8_0 = player;
    player = keeper;
    currentState = 1156;
    return true;
    if (apply_any_begin_begin_end(rgCache))
    {
        return true;
    }
    player = old8_0;
    return false;
}

bool GameState::apply_any_begin_begin_1594([[maybe_unused]]RgCache& rgCache)
{
    const auto old13_0 = player;
    player = black;
    currentState = 640;
    return true;
    if (apply_any_begin_begin_4(rgCache))
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_begin_begin_2([[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_2;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
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
    if (!is_legal_1582_1583_1582(rgCache))
    {
        if (apply_any_begin_begin_1562(rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_1594(rgCache))
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
