#include <reasoner.hpp>
#include <chrono>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
int main() {
    reasoner::RgCache cache;
    auto settle = [&](reasoner::GameState& s) {
        while (!s.isTerminal() && s.getCurrentPlayer() == reasoner::keeper) s.applyAnyMove(cache);
    };
    reasoner::GameState initial;
    settle(initial);
    std::vector<reasoner::GameState> states{initial};
    std::unordered_set<std::string> seen{initial.getStateDescription()};
    std::vector<reasoner::Move> moves;
    size_t processed=0, edges=0, terminals=0;
    auto start=std::chrono::steady_clock::now();
    while (processed < states.size() && states.size() < 50000 &&
        std::chrono::steady_clock::now()-start < std::chrono::seconds(20)) {
        auto s=states[processed++];
        if(s.isTerminal()) { ++terminals; continue; }
        s.getAllMoves(moves, cache);
        for(auto m:moves) {
            auto next=s; next.applyMove(m, cache); settle(next); ++edges;
            if(seen.insert(next.getStateDescription()).second) states.push_back(next);
        }
    }
    std::cout << "{\"states\":" << states.size() << ",\"processed\":" << processed
        << ",\"transitions\":" << edges << ",\"terminal_states\":" << terminals
        << ",\"complete\":" << (processed==states.size()?"true":"false") << "}\n";
}
