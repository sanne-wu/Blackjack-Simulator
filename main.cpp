#include "blackjack.h"
#include "strategy.h"

#include <iostream>

const unsigned long long N = 100000;

int main() {
    Blackjack bj = Blackjack(-1, 2);
    for (unsigned long long i = 0; i < N; i++) {
        bj.play_round();
    }
    std::cout << bj.get_player_bankroll()/(1.0*N) << std::endl;
}