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
    ss << "board = " << "{" << "null: " << board[null] << ", " << "rx0y0: " << board[rx0y0] << ", " << "rx1y0: " << board[rx1y0] << ", " << "rx2y0: " << board[rx2y0] << ", " << "rx3y0: " << board[rx3y0] << ", " << "rx4y0: " << board[rx4y0] << ", " << "rx5y0: " << board[rx5y0] << ", " << "rx6y0: " << board[rx6y0] << ", " << "rx0y1: " << board[rx0y1] << ", " << "rx1y1: " << board[rx1y1] << ", " << "rx2y1: " << board[rx2y1] << ", " << "rx3y1: " << board[rx3y1] << ", " << "rx4y1: " << board[rx4y1] << ", " << "rx5y1: " << board[rx5y1] << ", " << "rx6y1: " << board[rx6y1] << ", " << "rx0y2: " << board[rx0y2] << ", " << "rx1y2: " << board[rx1y2] << ", " << "rx2y2: " << board[rx2y2] << ", " << "rx3y2: " << board[rx3y2] << ", " << "rx4y2: " << board[rx4y2] << ", " << "rx5y2: " << board[rx5y2] << ", " << "rx6y2: " << board[rx6y2] << ", " << "rx0y3: " << board[rx0y3] << ", " << "rx1y3: " << board[rx1y3] << ", " << "rx2y3: " << board[rx2y3] << ", " << "rx3y3: " << board[rx3y3] << ", " << "rx4y3: " << board[rx4y3] << ", " << "rx5y3: " << board[rx5y3] << ", " << "rx6y3: " << board[rx6y3] << ", " << "rx0y4: " << board[rx0y4] << ", " << "rx1y4: " << board[rx1y4] << ", " << "rx2y4: " << board[rx2y4] << ", " << "rx3y4: " << board[rx3y4] << ", " << "rx4y4: " << board[rx4y4] << ", " << "rx5y4: " << board[rx5y4] << ", " << "rx6y4: " << board[rx6y4] << ", " << "rx0y5: " << board[rx0y5] << ", " << "rx1y5: " << board[rx1y5] << ", " << "rx2y5: " << board[rx2y5] << ", " << "rx3y5: " << board[rx3y5] << ", " << "rx4y5: " << board[rx4y5] << ", " << "rx5y5: " << board[rx5y5] << ", " << "rx6y5: " << board[rx6y5] << ", " << "rx0y6: " << board[rx0y6] << ", " << "rx1y6: " << board[rx1y6] << ", " << "rx2y6: " << board[rx2y6] << ", " << "rx3y6: " << board[rx3y6] << ", " << "rx4y6: " << board[rx4y6] << ", " << "rx5y6: " << board[rx5y6] << ", " << "rx6y6: " << board[rx6y6]<< "}" << std::endl;
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
        case 17:
{
            state_4(moves, mr.mr,rgCache);
            return;
}
        case 29:
{
            state_53(moves, mr.mr,rgCache);
            return;
}
        case 55:
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
        case 17:
{
            apply_state_4(mr.mr,rgCache);
            return;
}
        case 29:
{
            apply_state_53(mr.mr,rgCache);
            return;
}
        case 55:
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
        case 12:
{
            apply_any_26_26_26();
            break;
}
        case 49:
{
            apply_any_75_75_75();
            break;
}
        case 55:
{
            apply_any_begin_begin_begin();
            break;
}
    }
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_12()
{
    const auto old9_0 = board[coord];
    board[coord] = e;
    if (is_legal_4_27_4_4_27_27_4_27_16())
    {
        board[coord] = old9_0;
        return true;
    }
    board[coord] = old9_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_13()
{
    if (is_legal_4_27_4_4_27_27_4_27_12())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_14()
{
    if (board[direction_up[coord]]==e)
    {
        if (is_legal_4_27_4_4_27_27_4_27_27())
        {
            return true;
        }
    }
    const auto old12_0 = coord;
    coord = __gen_direction_left_direction_up[coord];
    if (is_legal_4_27_4_4_27_27_4_27_22())
    {
        coord = old12_0;
        return true;
    }
    coord = old12_0;
    const auto old18_0 = coord;
    coord = __gen_direction_right_direction_up[coord];
    if (is_legal_4_27_4_4_27_27_4_27_22())
    {
        coord = old18_0;
        return true;
    }
    coord = old18_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_16()
{
    if (direction_up[coord]!=null)
    {
        if (is_legal_4_27_4_4_27_27_4_27_14())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_19()
{
    if (board[coord]!=static_cast<Piece>(w))
    {
        if (is_legal_4_27_4_4_27_27_4_27_27())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_22()
{
    if (coord!=null)
    {
        if (is_legal_4_27_4_4_27_27_4_27_19())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_27()
{
    return true;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_4()
{
    const auto old15_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    if (is_legal_4_27_4_4_27_27_4_27_7())
    {
        coord = old15_0;
        return true;
    }    }
    coord = old15_0;
    return false;
}

bool GameState::is_legal_4_27_4_4_27_27_4_27_7()
{
    if (board[coord]==w)
    {
        if (is_legal_4_27_4_4_27_27_4_27_13())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_53()
{
    const auto old9_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    if (is_legal_53_76_53_53_76_76_53_76_56())
    {
        coord = old9_0;
        return true;
    }    }
    coord = old9_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_56()
{
    if (board[coord]==b)
    {
        if (is_legal_53_76_53_53_76_76_53_76_62())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_61()
{
    const auto old11_0 = board[coord];
    board[coord] = e;
    if (is_legal_53_76_53_53_76_76_53_76_65())
    {
        board[coord] = old11_0;
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_62()
{
    if (is_legal_53_76_53_53_76_76_53_76_61())
    {
        return true;
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_63()
{
    if (board[direction_down[coord]]==e)
    {
        if (is_legal_53_76_53_53_76_76_53_76_76())
        {
            return true;
        }
    }
    const auto old14_0 = coord;
    coord = __gen_direction_left_direction_down[coord];
    if (is_legal_53_76_53_53_76_76_53_76_71())
    {
        coord = old14_0;
        return true;
    }
    coord = old14_0;
    const auto old18_0 = coord;
    coord = __gen_direction_right_direction_down[coord];
    if (is_legal_53_76_53_53_76_76_53_76_71())
    {
        coord = old18_0;
        return true;
    }
    coord = old18_0;
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_65()
{
    if (direction_down[coord]!=null)
    {
        if (is_legal_53_76_53_53_76_76_53_76_63())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_68()
{
    if (board[coord]!=static_cast<Piece>(b))
    {
        if (is_legal_53_76_53_53_76_76_53_76_76())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_71()
{
    if (coord!=null)
    {
        if (is_legal_53_76_53_53_76_76_53_76_68())
        {
            return true;
        }
    }
    return false;
}

bool GameState::is_legal_53_76_53_53_76_76_53_76_76()
{
    return true;
}

void GameState::state_10([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    rgCache.state_cache_22.reset();
    rgCache.state_cache_17.reset();
    state_12(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_100([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_106([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_110([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_12([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old57_0 = board[coord];
    board[coord] = e;
    state_9(moves, mr,rgCache);
    board[coord] = old57_0;
}

void GameState::state_14([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_17(moves, mr,rgCache);
    }
    const auto old59_0 = coord;
    coord = direction_left[coord];
    state_22(moves, mr,rgCache);
    coord = old59_0;
    const auto old114_0 = coord;
    coord = direction_right[coord];
    state_22(moves, mr,rgCache);
    coord = old114_0;
}

void GameState::state_16([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_14(moves, mr,rgCache);
    }
}

void GameState::state_17([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    mr[1] = 0 + coord;
    state_27(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_19([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]!=static_cast<Piece>(w))
    {
        state_17(moves, mr,rgCache);
    }
}

void GameState::state_2([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    state_5(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_22([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_22;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_19(moves, mr,rgCache);
    }
}

void GameState::state_26([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old64_0 = goals[white - 2];
    goals[white - 2] = 100;
    state_30(moves, mr,rgCache);
    goals[white - 2] = old64_0;
}

void GameState::state_27([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_30([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = goals[black - 2];
    goals[black - 2] = 0;
    state_33(moves, mr,rgCache);
    goals[black - 2] = old65_0;
}

void GameState::state_33([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_up[coord]==null)
    {
        state_100(moves, mr,rgCache);
        return;
    }
    state_43(moves, mr,rgCache);
}

void GameState::state_35([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_53_76_53_53_76_76_53_76_53())
    {
        state_100(moves, mr,rgCache);
        return;
    }
    state_110(moves, mr,rgCache);
}

void GameState::state_4([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old66_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    state_7(moves, mr,rgCache);    }
    coord = old66_0;
}

void GameState::state_43([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old67_0 = board[coord];
    board[coord] = w;
    state_35(moves, mr,rgCache);
    board[coord] = old67_0;
}

void GameState::state_5([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_4_27_4_4_27_27_4_27_4())
    {
        state_100(moves, mr,rgCache);
        return;
    }
    state_106(moves, mr,rgCache);
}

void GameState::state_53([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old76_0 = coord;
    for (coord = rx0y0; coord <= rx6y6; ++coord)
    {
    state_56(moves, mr,rgCache);    }
    coord = old76_0;
}

void GameState::state_56([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        state_59(moves, mr,rgCache);
    }
}

void GameState::state_58([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = coord;
    coord = direction_down[coord];
    state_65(moves, mr,rgCache);
    coord = old86_0;
}

void GameState::state_59([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    mr[0] = 0 + coord;
    rgCache.state_cache_71.reset();
    rgCache.state_cache_66.reset();
    state_61(moves, mr,rgCache);
    mr[0] = unusedTag;
}

void GameState::state_61([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old88_0 = board[coord];
    board[coord] = e;
    state_58(moves, mr,rgCache);
    board[coord] = old88_0;
}

void GameState::state_63([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        state_66(moves, mr,rgCache);
    }
    const auto old90_0 = coord;
    coord = direction_left[coord];
    state_71(moves, mr,rgCache);
    coord = old90_0;
    const auto old117_0 = coord;
    coord = direction_right[coord];
    state_71(moves, mr,rgCache);
    coord = old117_0;
}

void GameState::state_65([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        state_63(moves, mr,rgCache);
    }
}

void GameState::state_66([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_66;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    mr[1] = 0 + coord;
    state_76(moves, mr,rgCache);
    mr[1] = unusedTag;
}

void GameState::state_68([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]!=static_cast<Piece>(b))
    {
        state_66(moves, mr,rgCache);
    }
}

void GameState::state_7([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        state_10(moves, mr,rgCache);
    }
}

void GameState::state_71([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_71;
    if (cache.test(coord))
    {
        return;
    }
    cache.set(coord);
    if (coord!=null)
    {
        state_68(moves, mr,rgCache);
    }
}

void GameState::state_75([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old95_0 = goals[black - 2];
    goals[black - 2] = 100;
    state_79(moves, mr,rgCache);
    goals[black - 2] = old95_0;
}

void GameState::state_76([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    moves.emplace_back(mr);
}

void GameState::state_79([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = goals[white - 2];
    goals[white - 2] = 0;
    state_82(moves, mr,rgCache);
    goals[white - 2] = old96_0;
}

void GameState::state_82([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_down[coord]==null)
    {
        state_100(moves, mr,rgCache);
        return;
    }
    state_92(moves, mr,rgCache);
}

void GameState::state_9([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = coord;
    coord = direction_up[coord];
    state_16(moves, mr,rgCache);
    coord = old97_0;
}

void GameState::state_92([[maybe_unused]] std::vector<Move>& moves, [[maybe_unused]] move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old98_0 = board[coord];
    board[coord] = b;
    state_2(moves, mr,rgCache);
    board[coord] = old98_0;
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
        rgCache.state_cache_22.reset();
        rgCache.state_cache_17.reset();
        if (apply_state_12(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_100([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old99_0 = player;
    player = keeper;
    currentState = 56;
    return true;
    player = old99_0;
    return false;
}

bool GameState::apply_state_106([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old102_0 = player;
    player = white;
    currentState = 17;
    return true;
    player = old102_0;
    return false;
}

bool GameState::apply_state_110([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old105_0 = player;
    player = black;
    currentState = 29;
    return true;
    player = old105_0;
    return false;
}

bool GameState::apply_state_12([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old57_0 = board[coord];
    board[coord] = e;
    if (apply_state_9(mr,rgCache))
    {
        return true;
    }
    board[coord] = old57_0;
    return false;
}

bool GameState::apply_state_14([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
    }
    const auto old59_0 = coord;
    coord = direction_left[coord];
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    coord = old59_0;
    const auto old114_0 = coord;
    coord = direction_right[coord];
    if (apply_state_22(mr,rgCache))
    {
        return true;
    }
    coord = old114_0;
    return false;
}

bool GameState::apply_state_16([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_14(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_17([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_17;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (mr[1] == 0 + coord)
    {
        if (apply_state_27(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_19([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]!=static_cast<Piece>(w))
    {
        if (apply_state_17(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_2([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        if (apply_state_5(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_22([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_22;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_19(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_26([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old64_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_state_30(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old64_0;
    return false;
}

bool GameState::apply_state_27([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old103_0 = player;
    player = keeper;
    currentState = 12;
    return true;
    player = old103_0;
    return false;
}

bool GameState::apply_state_30([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old65_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_state_33(mr,rgCache))
    {
        return true;
    }
    goals[black - 2] = old65_0;
    return false;
}

bool GameState::apply_state_33([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_up[coord]==null)
    {
        if (apply_state_100(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_43(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_35([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_53_76_53_53_76_76_53_76_53())
    {
        if (apply_state_100(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_110(mr,rgCache))
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
            switch (mr[rgCache.currentMrId++])
            {
                default:
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    board[coord] = e;
                    coord = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 12;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_4([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_0(mr ,rgCache);
    return false;
}

bool GameState::apply_state_43([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old67_0 = board[coord];
    board[coord] = w;
    if (apply_state_35(mr,rgCache))
    {
        return true;
    }
    board[coord] = old67_0;
    return false;
}

bool GameState::apply_state_5([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (!is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_state_100(mr,rgCache))
        {
            return true;
        }
        return false;
    }
    if (apply_state_106(mr,rgCache))
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
                    coord = mr[rgCache.currentMrId - 2] - 0;
                    board[coord] = e;
                    coord = mr[rgCache.currentMrId - 1] - 0;
                    player = keeper;
                    currentState = 49;
                    return true;
            }
            break;
    }
    return false;
}

bool GameState::apply_state_53([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_1(mr ,rgCache);
    return false;
}

bool GameState::apply_state_56([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==b)
    {
        if (apply_state_59(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_58([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old86_0 = coord;
    coord = direction_down[coord];
    if (apply_state_65(mr,rgCache))
    {
        return true;
    }
    coord = old86_0;
    return false;
}

bool GameState::apply_state_59([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (mr[0] == 0 + coord)
    {
        rgCache.state_cache_71.reset();
        rgCache.state_cache_66.reset();
        if (apply_state_61(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_61([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old88_0 = board[coord];
    board[coord] = e;
    if (apply_state_58(mr,rgCache))
    {
        return true;
    }
    board[coord] = old88_0;
    return false;
}

bool GameState::apply_state_63([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==e)
    {
        if (apply_state_66(mr,rgCache))
        {
            return true;
        }
    }
    const auto old90_0 = coord;
    coord = direction_left[coord];
    if (apply_state_71(mr,rgCache))
    {
        return true;
    }
    coord = old90_0;
    const auto old117_0 = coord;
    coord = direction_right[coord];
    if (apply_state_71(mr,rgCache))
    {
        return true;
    }
    coord = old117_0;
    return false;
}

bool GameState::apply_state_65([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (coord!=null)
    {
        if (apply_state_63(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_66([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_66;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (mr[1] == 0 + coord)
    {
        if (apply_state_76(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_68([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]!=static_cast<Piece>(b))
    {
        if (apply_state_66(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_7([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (board[coord]==w)
    {
        if (apply_state_10(mr,rgCache))
        {
            return true;
        }
    }
    return false;
}

bool GameState::apply_state_71([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    auto& cache = rgCache.state_cache_71;
    if (cache.test(coord))
    {
        return false;
    }
    cache.set(coord);
    if (coord!=null)
    {
        if (apply_state_68(mr,rgCache))
        {
            return true;
        }
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
                goals[black - 2] = 100;
                goals[white - 2] = 0;
                board[coord] = b;
                return apply_state_5(mr,rgCache);
        }
    }
    if ( mr[rgCache.currentMrId]!=unusedTag)
    {
        return false;
    }
    goals[black - 2] = 100;
    goals[white - 2] = 0;
    player = keeper;
    currentState = 56;
    return true;
    return false;
}

bool GameState::apply_state_75([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    return switch_2(mr ,rgCache);
    return false;
}

bool GameState::apply_state_76([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old106_0 = player;
    player = keeper;
    currentState = 49;
    return true;
    player = old106_0;
    return false;
}

bool GameState::apply_state_79([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old96_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_state_82(mr,rgCache))
    {
        return true;
    }
    goals[white - 2] = old96_0;
    return false;
}

bool GameState::apply_state_82([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    if (direction_down[coord]==null)
    {
        if (apply_state_100(mr,rgCache))
        {
            return true;
        }
        return false;;
    }
    if (apply_state_92(mr,rgCache))
    {
        return true;
    }
    return false;
}

bool GameState::apply_state_9([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old97_0 = coord;
    coord = direction_up[coord];
    if (apply_state_16(mr,rgCache))
    {
        return true;
    }
    coord = old97_0;
    return false;
}

bool GameState::apply_state_92([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    const auto old98_0 = board[coord];
    board[coord] = b;
    if (apply_state_2(mr,rgCache))
    {
        return true;
    }
    board[coord] = old98_0;
    return false;
}

bool GameState::switch_3([[maybe_unused]]const move_representation& mr, [[maybe_unused]]RgCache& rgCache)
{
    switch (mr[rgCache.currentMrId++])
    {
        default:
            return apply_state_5(mr,rgCache);
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

bool GameState::apply_any_26_26_100()
{
    const auto old12_0 = player;
    player = keeper;
    currentState = 56;
    return true;
    if (apply_any_26_26_end())
    {
        return true;
    }
    player = old12_0;
    return false;
}

bool GameState::apply_any_26_26_110()
{
    const auto old14_0 = player;
    player = black;
    currentState = 29;
    return true;
    if (apply_any_26_26_53())
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_26_26_26()
{
    const auto old9_0 = goals[white - 2];
    goals[white - 2] = 100;
    if (apply_any_26_26_30())
    {
        return true;
    }
    goals[white - 2] = old9_0;
    return false;
}

bool GameState::apply_any_26_26_30()
{
    const auto old10_0 = goals[black - 2];
    goals[black - 2] = 0;
    if (apply_any_26_26_33())
    {
        return true;
    }
    goals[black - 2] = old10_0;
    return false;
}

bool GameState::apply_any_26_26_33()
{
    if (direction_up[coord]==null)
    {
        if (apply_any_26_26_100())
        {
            return true;
        }
        return false;
    }
    if (apply_any_26_26_43())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_35()
{
    if (!is_legal_53_76_53_53_76_76_53_76_53())
    {
        if (apply_any_26_26_100())
        {
            return true;
        }
        return false;
    }
    if (apply_any_26_26_110())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_26_26_43()
{
    const auto old11_0 = board[coord];
    board[coord] = w;
    if (apply_any_26_26_35())
    {
        return true;
    }
    board[coord] = old11_0;
    return false;
}

bool GameState::apply_any_26_26_53()
{
    return true;
}

bool GameState::apply_any_26_26_end()
{
    return true;
}

bool GameState::apply_any_75_75_100()
{
    const auto old14_0 = player;
    player = keeper;
    currentState = 56;
    return true;
    if (apply_any_75_75_end())
    {
        return true;
    }
    player = old14_0;
    return false;
}

bool GameState::apply_any_75_75_106()
{
    const auto old16_0 = player;
    player = white;
    currentState = 17;
    return true;
    if (apply_any_75_75_4())
    {
        return true;
    }
    player = old16_0;
    return false;
}

bool GameState::apply_any_75_75_2()
{
    if (apply_any_75_75_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_4()
{
    return true;
}

bool GameState::apply_any_75_75_5()
{
    if (!is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_any_75_75_100())
        {
            return true;
        }
        return false;
    }
    if (apply_any_75_75_106())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_75()
{
    const auto old11_0 = goals[black - 2];
    goals[black - 2] = 100;
    if (apply_any_75_75_79())
    {
        return true;
    }
    goals[black - 2] = old11_0;
    return false;
}

bool GameState::apply_any_75_75_79()
{
    const auto old12_0 = goals[white - 2];
    goals[white - 2] = 0;
    if (apply_any_75_75_82())
    {
        return true;
    }
    goals[white - 2] = old12_0;
    return false;
}

bool GameState::apply_any_75_75_82()
{
    if (direction_down[coord]==null)
    {
        if (apply_any_75_75_100())
        {
            return true;
        }
        return false;
    }
    if (apply_any_75_75_92())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_75_75_92()
{
    const auto old13_0 = board[coord];
    board[coord] = b;
    if (apply_any_75_75_2())
    {
        return true;
    }
    board[coord] = old13_0;
    return false;
}

bool GameState::apply_any_75_75_end()
{
    return true;
}

bool GameState::apply_any_begin_begin_100()
{
    const auto old8_0 = player;
    player = keeper;
    currentState = 56;
    return true;
    if (apply_any_begin_begin_end())
    {
        return true;
    }
    player = old8_0;
    return false;
}

bool GameState::apply_any_begin_begin_106()
{
    const auto old11_0 = player;
    player = white;
    currentState = 17;
    return true;
    if (apply_any_begin_begin_4())
    {
        return true;
    }
    player = old11_0;
    return false;
}

bool GameState::apply_any_begin_begin_2()
{
    if (apply_any_begin_begin_5())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_4()
{
    return true;
}

bool GameState::apply_any_begin_begin_5()
{
    if (!is_legal_4_27_4_4_27_27_4_27_4())
    {
        if (apply_any_begin_begin_100())
        {
            return true;
        }
        return false;
    }
    if (apply_any_begin_begin_106())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_begin()
{
    if (apply_any_begin_begin_2())
    {
        return true;
    }
    return false;
}

bool GameState::apply_any_begin_begin_end()
{
    return true;
}

}  // namespace reasoner
