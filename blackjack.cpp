#include "blackjack.h"
#include <iostream>

Blackjack::Blackjack(int strat, int decks) {
    strategy = new Strategy(strat);
    shoe = Shoe(time(0), decks);
    player.set_strategy(strategy);
}

void Blackjack::play_round() {
    deal_round();
    bool action;
    if (dealer.hand.total == BLACKJACK) {
        if(player.hands.front().total == BLACKJACK)
            player.calculate_winnings(player.hands.front(), dealer.hand.total);
        player.hands.clear();
        dealer.hand.clear();
        return;
    }
    do {
        action = player.play_round(shoe);
    } while(action);
    for (auto& h: player.hands) {
        if (h.total == BLACKJACK) {
            player.calculate_winnings(h, -1);
        }
    }
    dealer.draw(shoe);
    for (auto& h : player.hands) {
        if (h.bet != 0) {
            player.calculate_winnings(h, dealer.hand.total);
        }
    }
    shoe.check_deck();
    player.hands.clear();
    dealer.hand.clear();
}

void Blackjack::deal_round() {
    player.bet(1000);
    for (int i = 0; i < BEG_HAND_SIZE; i++) {
        dealer.take(shoe);
        player.hit(player.hands.front(), shoe);
    }
    strategy->d = dealer.up();
}

signed long long Blackjack::get_player_bankroll() {
    return player.get_bankroll();
}