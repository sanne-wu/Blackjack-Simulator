#ifndef PLAYER_H
#define PLAYER_H

#include "shoe.h"
#include "constants.h"
#include "strategy.h"

class Player {
    public:
        Player(signed long long bankroll = 10000);
        bool play_round(Shoe&);
        void hit(Hand&, Shoe&);
        void split(Hand&, Shoe&);
        void dble(Hand&, Shoe&);
        void stand(Hand&);
        void bet(unsigned);
        void check_surrender();
        void set_count(int);
        void set_strategy(Strategy*);
        void calculate_winnings(Hand&, int);
        signed long long get_bankroll() { return bankroll; }
        std::vector<Hand> hands;
    private:
        signed long long bankroll;
        Strategy* strategy; 
        void surrender();
};

#endif