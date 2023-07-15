#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "shoe.h"
#include "player.h"
#include "dealer.h"
#include "constants.h"
#include <ctime>

const int BEG_HAND_SIZE = 2;

class Blackjack {
    public:
        Blackjack(int strat=-1, int decks=6);
        ~Blackjack() { delete strategy; }
        void play_round();
        void add_player(Player);
        signed long long get_player_bankroll();

    private:
        void deal_round();
        Strategy* strategy;
        Dealer dealer;
        Player player;
        Shoe shoe;
};

#endif