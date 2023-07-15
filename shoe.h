#ifndef SHOE_H
#define SHOE_H

#include <vector>
#include <algorithm>
#include <random>
#include "constants.h"
#include <iostream>

enum Card { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

int value(Card);

class Shoe {
    public:
        Shoe(unsigned seed=0, int decks = 6);
        bool check_deck();
        Card draw();
        void print_shoe() {
            for (auto c : shoe) {
                std::cout << value(c) << " " << (int) c << ", ";
            }
            std::cout << std::endl;
            std::cout << "cut " << cut_card << std::endl;
            std::cout << "top " << top_card << std::endl;
            std::cout << decks << " total cards " << shoe.size() << std::endl;
        }

    private:
        int top_card;
        int cut_card;
        int decks;
        unsigned seed;
        std::vector<Card> shoe;
        void shuffle_shoe();
};

struct Hand {
    public:
        Hand(int bet = 0);
        Hand(Card);
        std::vector<Card> cards;
        int total;
        unsigned bet;
        bool soft;
        int actionable;
        int state;

        Card get_card(int);
        void take(Card);
        bool bust();
        bool bj();
        int size();

        void clear();

        void print() {
            for (auto c : cards) std::cout << (int) c << " ";
            std::cout << std::endl;
        }
    private:
        void find_total();
};

#endif