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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx7y3: " << board[rx7y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx7y4: " << board[rx7y4] << ", " << "rx8y4: " << board[rx8y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx7y5: " << board[rx7y5] << ", " << "rx8y5: " << board[rx8y5] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6] << ", " << "rx7y6: " << board[rx7y6] << ", " << "rx2y7: " << board[rx2y7] << ", " << "rx3y7: " << board[rx3y7] << ", " << "rx4y7: " << board[rx4y7] << ", " << "rx5y7: " << board[rx5y7] << ", " << "rx6y7: " << board[rx6y7] << ", " << "rx3y8: " << board[rx3y8] << ", " << "rx4y8: " << board[rx4y8] << ", " << "rx5y8: " << board[rx5y8] << ", " << "rx4y9: " << board[rx4y9]<< "}" << std::endl;
    ss << "coord = " << coord << std::endl;
    ss << "goals = " << "{" << "foxPlayer: " << goals[foxPlayer-2] << ", " << "houndPlayer: " << goals[houndPlayer-2]<< "}" << std::endl;
    ss << "player = " << player << std::endl;
    ss << "visible = " << "{" << "foxPlayer: " << visible[foxPlayer-2] << ", " << "houndPlayer: " << visible[houndPlayer-2]<< "}" << std::endl;
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
        case 24:
{
            state_5(moves, mr.mr,rgCache);
            return;
}
        case 14:
{
            state_27(moves, mr.mr,rgCache);
            return;
}
        case 31:
{
            state_70(moves, mr.mr,rgCache);
            return;
}
        case 49:
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
        case 24:
{
            apply_state_5(mr.mr,rgCache);
            return;
}
        case 14:
{
            apply_state_27(mr.mr,rgCache);
            return;
}
        case 31:
{
            apply_state_70(mr.mr,rgCache);
            return;
}
        case 49:
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
        case 1:
{
            apply_any_10_10_10();
            break;
}
        case 7:
{
            apply_any_17_17_17();
            break;
}
        case 23:
{
            apply_any_45_45_45();
            break;
}
        case 47:
{
            apply_any_91_91_91();
            break;
}
        case 49:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_17()
{
    const auto old3_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (is_legal_17_28_17_17_28_28_17_28_20())
    {
        coord = old3_0;
        return true;
    }    }
    coord = old3_0;
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_20()
{
    if (board[coord]==f)
    {
        if (is_legal_17_28_17_17_28_28_17_28_28())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_17_28_17_17_28_28_17_28_28()
{
    return true;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_27()
{
    const auto old3_0 = coord;
    coord = direction_upRight[coord];
    if (is_legal_27_42_27_27_42_42_27_42_30())
    {
        coord = old3_0;
        return true;
    }
    coord = old3_0;
    const auto old4_0 = coord;
    coord = direction_downLeft[coord];
    if (is_legal_27_42_27_27_42_42_27_42_30())
    {
        coord = old4_0;
        return true;
    }
    coord = old4_0;
    const auto old5_0 = coord;
    coord = direction_upLeft[coord];
    if (is_legal_27_42_27_27_42_42_27_42_30())
    {
        coord = old5_0;
        return true;
    }
    coord = old5_0;
    const auto old6_0 = coord;
    coord = direction_downRight[coord];
    if (is_legal_27_42_27_27_42_42_27_42_30())
    {
        coord = old6_0;
        return true;
    }
    coord = old6_0;
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_30()
{
    if (board[coord]==e)
    {
        if (is_legal_27_42_27_27_42_42_27_42_42())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_27_42_27_27_42_42_27_42_42()
{
    return true;
}

bool GameState::is_legal_58_59_58()
{
    if (direction_downLeft[coord]!=null)
    {
        if (is_legal_58_59_59())
        {
            return true;
        }
    }
    if (direction_downRight[coord]!=null)
    {
        if (is_legal_58_59_59())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_58_59_59()
{
    return true;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_70()
{
    const auto old7_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (is_legal_70_88_70_70_88_88_70_88_73())
    {
        coord = old7_0;
        return true;
    }    }
    coord = old7_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_73()
{
    if (board[coord]==h)
    {
        if (is_legal_70_88_70_70_88_88_70_88_79())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_75()
{
    const auto old9_0 = coord;
    coord = direction_upLeft[coord];
    if (is_legal_70_88_70_70_88_88_70_88_80())
    {
        coord = old9_0;
        return true;
    }
    coord = old9_0;
    const auto old10_0 = coord;
    coord = direction_upRight[coord];
    if (is_legal_70_88_70_70_88_88_70_88_80())
    {
        coord = old10_0;
        return true;
    }
    coord = old10_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_78()
{
    const auto old11_0 = board[coord];
    board[coord] = e;
    if (is_legal_70_88_70_70_88_88_70_88_75())
    {
        board[coord] = old11_0;
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_79()
{
    if (is_legal_70_88_70_70_88_88_70_88_78())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_80()
{
    if (board[coord]==e)
    {
        if (is_legal_70_88_70_70_88_88_70_88_88())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_70_88_70_70_88_88_70_88_88()
{
    return true;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old50_0 = board[coord];
    board[coord] = f;
    state_15(moves, mr,rgCache);
    board[coord] = old50_0;
}

void GameState::state_104([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_107([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_109([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_113([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_15([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_17_28_17_17_28_28_17_28_17())
    {
        state_104(moves, mr,rgCache);
        return;
    }
    state_107(moves, mr,rgCache);
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old51_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    state_20(moves, mr,rgCache);    }
    coord = old51_0;
}

void GameState::state_20([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==f)
    {
        state_23(moves, mr,rgCache);
    }
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_27_42_27_27_42_42_27_42_27())
    {
        state_104(moves, mr,rgCache);
        return;
    }
    state_109(moves, mr,rgCache);
}

void GameState::state_23([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old55_0 = board[coord];
    board[coord] = e;
    state_22(moves, mr,rgCache);
    board[coord] = old55_0;
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old56_0 = coord;
    coord = direction_upRight[coord];
    state_30(moves, mr,rgCache);
    coord = old56_0;
    const auto old57_0 = coord;
    coord = direction_downLeft[coord];
    state_30(moves, mr,rgCache);
    coord = old57_0;
    const auto old58_0 = coord;
    coord = direction_upLeft[coord];
    state_30(moves, mr,rgCache);
    coord = old58_0;
    const auto old59_0 = coord;
    coord = direction_downRight[coord];
    state_30(moves, mr,rgCache);
    coord = old59_0;
}

void GameState::state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_30;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_40(moves, mr,rgCache);
    }
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_7(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_40([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_42(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_42([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_44([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old68_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    state_50(moves, mr,rgCache);
    goals[foxPlayer - 2] = old68_0;
}

void GameState::state_45([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = board[coord];
    board[coord] = f;
    state_44(moves, mr,rgCache);
    board[coord] = old69_0;
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old71_0 = coord;
    for (const auto& coordIt : {rx0y4,rx1y3,rx2y2,rx3y1,rx4y0})
    {
    coord = coordIt;
    state_4(moves, mr,rgCache);    }
    coord = old71_0;
}

void GameState::state_50([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old70_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    state_53(moves, mr,rgCache);
    goals[houndPlayer - 2] = old70_0;
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_58_59_58())
    {
        state_104(moves, mr,rgCache);
        return;
    }
    state_55(moves, mr,rgCache);
}

void GameState::state_55([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_70_88_70_70_88_88_70_88_70())
    {
        state_104(moves, mr,rgCache);
        return;
    }
    state_113(moves, mr,rgCache);
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_70([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old75_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    state_73(moves, mr,rgCache);    }
    coord = old75_0;
}

void GameState::state_73([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==h)
    {
        state_76(moves, mr,rgCache);
    }
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old84_0 = coord;
    coord = direction_upLeft[coord];
    state_80(moves, mr,rgCache);
    coord = old84_0;
    const auto old85_0 = coord;
    coord = direction_upRight[coord];
    state_80(moves, mr,rgCache);
    coord = old85_0;
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    rgCache.state_cache_80.reset();
    state_78(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_78([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old87_0 = board[coord];
    board[coord] = e;
    state_75(moves, mr,rgCache);
    board[coord] = old87_0;
}

void GameState::state_80([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_80;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        state_86(moves, mr,rgCache);
    }
}

void GameState::state_86([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[1] = 0 + coord;
    state_88(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_88([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_90([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    state_96(moves, mr,rgCache);
    goals[foxPlayer - 2] = old90_0;
}

void GameState::state_91([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old91_0 = board[coord];
    board[coord] = h;
    state_90(moves, mr,rgCache);
    board[coord] = old91_0;
}

void GameState::state_96([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    state_15(moves, mr,rgCache);
    goals[houndPlayer - 2] = old92_0;
}

void GameState::state_begin([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_end([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
}

bool GameState::apply_state_10([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old50_0 = board[coord];
    board[coord] = f;
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }
    board[coord] = old50_0;
    return false;
}

bool GameState::apply_state_104([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old94_0 = player;
    player = keeper;
    currentState = 50;
    return true;
    player = old94_0;
    return false;
}

bool GameState::apply_state_107([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = player;
    player = keeper;
    currentState = 7;
    return true;
    player = old97_0;
    return false;
}

bool GameState::apply_state_109([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old99_0 = player;
    player = foxPlayer;
    currentState = 14;
    return true;
    player = old99_0;
    return false;
}

bool GameState::apply_state_113([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old102_0 = player;
    player = houndPlayer;
    currentState = 31;
    return true;
    player = old102_0;
    return false;
}

bool GameState::apply_state_15([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_state_104(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_107(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old51_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (apply_state_20(mr,rgCache))
    {
        return true;
    }    }
    coord = old51_0;
    return false;
}

bool GameState::apply_state_20([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==f)
    {
        if (apply_state_23(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_27_42_27_27_42_42_27_42_27())
    {
        if (apply_state_104(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_109(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_23([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old55_0 = board[coord];
    board[coord] = e;
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    board[coord] = old55_0;
    return false;
}

bool GameState::switch_0([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 23;
            return true;
    }
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_30;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_40(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_7(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_40([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_42(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_42([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old100_0 = player;
    player = keeper;
    currentState = 23;
    return true;
    player = old100_0;
    return false;
}

bool GameState::apply_state_44([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old68_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_state_50(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old68_0;
    return false;
}

bool GameState::apply_state_45([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old69_0 = board[coord];
    board[coord] = f;
    if (apply_state_44(mr,rgCache))
    {
        return true;
    }
    board[coord] = old69_0;
    return false;
}

bool GameState::switch_1([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            coord = mr[rgCache.currentMrId - 1] - 0;
            player = keeper;
            currentState = 1;
            return true;
    }
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_50([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old70_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (apply_state_53(mr,rgCache))
    {
        return true;
    }
    goals[houndPlayer - 2] = old70_0;
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_58_59_58())
    {
        if (apply_state_104(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_55(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_55([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_70_88_70_70_88_88_70_88_70())
    {
        if (apply_state_104(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_113(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = player;
    player = keeper;
    currentState = 1;
    return true;
    player = old95_0;
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
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    board[coord] = e;
                    coord = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 47;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_70([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_73([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==h)
    {
        if (apply_state_76(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old84_0 = coord;
    coord = direction_upLeft[coord];
    if (apply_state_80(mr,rgCache))
    {
        return true;
    }
    coord = old84_0;
    const auto old85_0 = coord;
    coord = direction_upRight[coord];
    if (apply_state_80(mr,rgCache))
    {
        return true;
    }
    coord = old85_0;
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        rgCache.state_cache_80.reset();
        if (apply_state_78(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_78([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old87_0 = board[coord];
    board[coord] = e;
    if (apply_state_75(mr,rgCache))
    {
        return true;
    }
    board[coord] = old87_0;
    return false;
}

bool GameState::apply_state_80([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_80;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (board[coord]==e)
    {
        if (apply_state_86(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_86([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[1] == 0 + coord)
    {
        if (apply_state_88(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_88([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old103_0 = player;
    player = keeper;
    currentState = 47;
    return true;
    player = old103_0;
    return false;
}

bool GameState::apply_state_90([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old90_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    if (apply_state_96(mr,rgCache))
    {
        return true;
    }
    goals[foxPlayer - 2] = old90_0;
    return false;
}

bool GameState::apply_state_91([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old91_0 = board[coord];
    board[coord] = h;
    if (apply_state_90(mr,rgCache))
    {
        return true;
    }
    board[coord] = old91_0;
    return false;
}

bool GameState::apply_state_96([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old92_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_state_15(mr,rgCache))
    {
        return true;
    }
    goals[houndPlayer - 2] = old92_0;
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    player = foxPlayer;
    currentState = 24;
    return true;
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

bool GameState::apply_any_10_10_10()
{
    const auto old6_0 = board[coord];
    board[coord] = f;
    if (apply_any_10_10_15())
    {
        return true;
    }
    board[coord] = old6_0;
    return false;
}

bool GameState::apply_any_10_10_104()
{
    const auto old7_0 = player;
    player = keeper;
    currentState = 50;
    return true;
    if (apply_any_10_10_end())
    {
        return true;
    }
    player = old7_0;
    return false;
}

bool GameState::apply_any_10_10_107()
{
    const auto old9_0 = player;
    player = keeper;
    currentState = 7;
    return true;
    if (apply_any_10_10_17())
    {
        return true;
    }
    player = old9_0;
    return false;
}

bool GameState::apply_any_10_10_15()
{
    if (!is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_any_10_10_104())
        {
            return true;
        }
        return false;
    }
    if (apply_any_10_10_107())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_10_10_17()
{
    return true;
}

bool GameState::apply_any_10_10_end()
{
    return true;
}

bool GameState::apply_any_17_17_104()
{
    const auto old11_0 = player;
    player = keeper;
    currentState = 50;
    return true;
    if (apply_any_17_17_end())
    {
        return true;
    }
    player = old11_0;
    return false;
}

bool GameState::apply_any_17_17_109()
{
    const auto old13_0 = player;
    player = foxPlayer;
    currentState = 14;
    return true;
    if (apply_any_17_17_27())
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_17_17_17()
{
    const auto old8_0 = coord;
    for (coord = rx0y4; coord <= rx8y5; ++coord)
    {
    if (apply_any_17_17_20())
    {
        return true;
    }    }
    coord = old8_0;
    return false;
}

bool GameState::apply_any_17_17_20()
{
    if (board[coord]==f)
    {
        if (apply_any_17_17_23())
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_any_17_17_22()
{
    if (!is_legal_27_42_27_27_42_42_27_42_27())
    {
        if (apply_any_17_17_104())
        {
            return true;
        }
        return false;
    }
    if (apply_any_17_17_109())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_17_17_23()
{
    const auto old10_0 = board[coord];
    board[coord] = e;
    if (apply_any_17_17_22())
    {
        return true;
    }
    board[coord] = old10_0;
    return false;
}

bool GameState::apply_any_17_17_27()
{
    return true;
}

bool GameState::apply_any_17_17_end()
{
    return true;
}

bool GameState::apply_any_45_45_104()
{
    const auto old13_0 = player;
    player = keeper;
    currentState = 50;
    return true;
    if (apply_any_45_45_end())
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_45_45_113()
{
    const auto old15_0 = player;
    player = houndPlayer;
    currentState = 31;
    return true;
    if (apply_any_45_45_70())
    {
        return true;
    }
    player = old15_0;
    return false;
}

bool GameState::apply_any_45_45_44()
{
    const auto old9_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 100;
    if (apply_any_45_45_50())
    {
        return true;
    }
    goals[foxPlayer - 2] = old9_0;
    return false;
}

bool GameState::apply_any_45_45_45()
{
    const auto old10_0 = board[coord];
    board[coord] = f;
    if (apply_any_45_45_44())
    {
        return true;
    }
    board[coord] = old10_0;
    return false;
}

bool GameState::apply_any_45_45_50()
{
    const auto old11_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 0;
    if (apply_any_45_45_53())
    {
        return true;
    }
    goals[houndPlayer - 2] = old11_0;
    return false;
}

bool GameState::apply_any_45_45_53()
{
    if (!is_legal_58_59_58())
    {
        if (apply_any_45_45_104())
        {
            return true;
        }
        return false;
    }
    if (apply_any_45_45_55())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_45_45_55()
{
    if (!is_legal_70_88_70_70_88_88_70_88_70())
    {
        if (apply_any_45_45_104())
        {
            return true;
        }
        return false;
    }
    if (apply_any_45_45_113())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_45_45_70()
{
    return true;
}

bool GameState::apply_any_45_45_end()
{
    return true;
}

bool GameState::apply_any_91_91_104()
{
    const auto old11_0 = player;
    player = keeper;
    currentState = 50;
    return true;
    if (apply_any_91_91_end())
    {
        return true;
    }
    player = old11_0;
    return false;
}

bool GameState::apply_any_91_91_107()
{
    const auto old13_0 = player;
    player = keeper;
    currentState = 7;
    return true;
    if (apply_any_91_91_17())
    {
        return true;
    }
    player = old13_0;
    return false;
}

bool GameState::apply_any_91_91_15()
{
    if (!is_legal_17_28_17_17_28_28_17_28_17())
    {
        if (apply_any_91_91_104())
        {
            return true;
        }
        return false;
    }
    if (apply_any_91_91_107())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_91_91_17()
{
    return true;
}

bool GameState::apply_any_91_91_90()
{
    const auto old8_0 = goals[foxPlayer - 2];
    goals[foxPlayer - 2] = 0;
    if (apply_any_91_91_96())
    {
        return true;
    }
    goals[foxPlayer - 2] = old8_0;
    return false;
}

bool GameState::apply_any_91_91_91()
{
    const auto old9_0 = board[coord];
    board[coord] = h;
    if (apply_any_91_91_90())
    {
        return true;
    }
    board[coord] = old9_0;
    return false;
}

bool GameState::apply_any_91_91_96()
{
    const auto old10_0 = goals[houndPlayer - 2];
    goals[houndPlayer - 2] = 100;
    if (apply_any_91_91_15())
    {
        return true;
    }
    goals[houndPlayer - 2] = old10_0;
    return false;
}

bool GameState::apply_any_91_91_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_5()
{
    return true;
}

bool GameState::apply_any_begin_begin_begin()
{
    const auto old2_0 = player;
    player = foxPlayer;
    currentState = 24;
    return true;
    if (apply_any_begin_begin_5())
    {
        return true;
    }
    player = old2_0;
    return false;
}

}  // namespace reasoner
