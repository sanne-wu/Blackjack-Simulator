#include "shoe.h"

int value(Card c) {
    return std::min((int)c + 1, 10);
};

Shoe::Shoe(unsigned seed, int decks) : decks(decks), seed(seed) {
    cut_card = decks * DECK_SIZE;
    top_card = 0;
    for (int i = 0; i < (decks + 1)*DECK_SIZE; i++) {
        shoe.push_back((Card) (i%NUM_P_SUIT));
    }
    shuffle_shoe();
}

Card Shoe::draw() {
    return shoe[top_card++];
}

bool Shoe::check_deck() {
    if(top_card >= cut_card) {
        shuffle_shoe();
        top_card = 0;
        return true;
    }
    return false;
}

void Shoe::shuffle_shoe() {
    shuffle(shoe.begin(), shoe.end(), std::default_random_engine(seed));
}

Hand::Hand(int bet) : total(0), bet(bet), soft(false), actionable(-1), state(0) {}

Hand::Hand(Card c) : total(value(c)), bet(0), soft(false), actionable(-1), state(0) {
    cards.push_back(c);
}

Card Hand::get_card(int i) {
    return cards.at(i);
}

void Hand::take(Card c) {
    cards.push_back(c);
    if (soft || c == Card::ACE) find_total();
    else total += value(c);
    if (bj() || bust()) actionable = 0;
}

void Hand::find_total() {
    if (soft) {
        if (total + value(cards.back()) > BLACKJACK) {
            soft = false;
            total -= (ACE_ALT - value(Card::ACE));
        }
        else {
            total += value(cards.back());
        }
    }
    else {
        if (total + ACE_ALT <= BLACKJACK) {
            soft = true;
            total += ACE_ALT;
        }
        else {
            total += value(cards.back());
        }
    }
}

bool Hand::bust() { return total > BLACKJACK; }

bool Hand::bj() { return total == BLACKJACK; }

int Hand::size() { return cards.size(); }

void Hand::clear() { 
    cards.clear();
    total = 0;
}