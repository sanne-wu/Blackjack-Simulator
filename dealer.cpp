#include "dealer.h"

Dealer::Dealer() {}

Card Dealer::up() {
    return hand.get_card(0);
}

void Dealer::take(Shoe& shoe, int n) {
    for (int i = 0; i < n; i++) hand.take(shoe.draw());
}

void Dealer::draw(Shoe& shoe) {
    while(hand.total < HIT_UNTIL) take(shoe, 1);
}