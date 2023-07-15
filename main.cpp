#include "blackjack.h"
#include "strategy.h"

#include <iostream>
#include <fstream>

const unsigned long long N = 100000;
const int iters = 1000;

int main() {
    std::ofstream output;
    output.open("output.csv");
    output << "endbank" << std::endl;
    for (int i = 0; i < iters; i++) {
        Blackjack bj = Blackjack(-1, 6);
        signed long long beg_bank = bj.get_player_bankroll();
        for (unsigned long long i = 0; i < N; i++) {
            bj.play_round();
        }
        output << bj.get_player_bankroll()/(1.0*N)/beg_bank << std::endl;
    }
}