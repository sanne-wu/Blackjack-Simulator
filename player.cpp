#include "player.h"
#include <iostream>

Player::Player(signed long long bankroll) : bankroll(bankroll), strategy(NULL) {}

bool Player::play_round(Shoe& shoe) {
    int res = false;
    for (auto& h : hands) {
        if (h.actionable) {
            if (strategy->decode_surrender(h) == Strategy::Action::SUR) {
                surrender();
                break;
            }
            else if (strategy->decode_split(h) == Strategy::Action::SPLT) {
                split(h, shoe);
                res = true;
                break;
            }
            else {
                Strategy::Action act;
                if (h.soft) act = strategy->decode_soft(h);
                else act = strategy->decode_hard(h);
                if (act == Strategy::Action::DBL) {
                    dble(h, shoe);
                    res = true;
                }

                else if (act == Strategy::Action::HIT) {
                    hit(h, shoe);
                    res = true;
                }
                else {
                    stand(h);
                }
            }
        }
        if (h.actionable == -1) h.actionable = 1;
    }
    return res;
}

void Player::hit(Hand& h, Shoe& shoe) {
    h.take(shoe.draw());
}

void Player::split(Hand& h, Shoe& shoe) {
    Hand temp = Hand(h.get_card(1));
    temp.bet = h.bet /= 2;
    temp.total = h.total /= 2;
    h.cards.pop_back();

    if (h.get_card(0) == Card::ACE) {
        h.actionable = false;
        temp.actionable = false;
        hit(h, shoe);
        hit(temp, shoe);
    }
    hands.push_back(temp);
}

void Player::dble(Hand& h, Shoe& shoe) {
    bankroll -= h.bet;
    h.bet *= 2;
    hit(h, shoe);
    h.actionable = false;
}

void Player::stand(Hand& h) {
    h.actionable = false;
}

void Player::bet(unsigned amount) {
    hands.push_back(Hand(amount));
    bankroll -= amount;
}

void Player::surrender() {
    bankroll += hands.front().bet/2;
    hands.pop_back();
}

void Player::set_strategy(Strategy* s) { strategy = s; }

void Player::calculate_winnings(Hand& h, int dealer_total) {
    if (h.bet == 0 || h.total > BLACKJACK) return;
    if (h.total == dealer_total) bankroll += h.bet;
    else if (h.total == BLACKJACK) {
        bankroll += (1 + BLACKJACK_PAYOUT)*h.bet;
        h.bet = 0;
    }
    else if (dealer_total > BLACKJACK || h.total > dealer_total) bankroll += 2*h.bet;
}
