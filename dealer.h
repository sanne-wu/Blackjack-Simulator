#ifndef DEALER_H
#define DEALER_H

#include "shoe.h"
#include "constants.h"

class Dealer {
    public:
        Dealer();
        Card up();
        void take(Shoe&, int n=1);
        void draw(Shoe&);
        Hand hand;
};
#endif