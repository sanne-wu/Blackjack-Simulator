#ifndef STRATEGY_H
#define STRATEGY_H

#include "shoe.h"
#include <string>
#include "constants.h"

struct Strategy {
    enum class Action { HIT, STND, DBL, SPLT, SUR, INS, CONT };
    std::vector<std::vector<std::string>> split = {
        {"Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y"}, //A,A
        {"N", "N", "N", "N", "Y", "Y", "Y", "N", "N", "N"}, //2,2
        {"N", "N", "N", "N", "Y", "Y", "Y", "N", "N", "N"}, //3,3
        {"N", "Y", "Y", "Y", "Y", "Y", "Y", "N", "N", "N"}, //4,4
        {"N", "N", "N", "N", "N", "N", "N", "N", "N", "N"}, //5,5
        {"N", "Y", "Y", "Y", "Y", "Y", "N", "N", "N", "N"}, //6,6
        {"N", "Y", "Y", "Y", "Y", "Y", "Y", "N", "N", "N"}, //7,7
        {"Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y"}, //8,8
        {"N", "Y", "Y", "Y", "Y", "Y", "N", "Y", "Y", "N"}, //9,9
        {"N", "N", "N", "N", "N", "N", "N", "N", "N", "N"}, //T,T
    };
    std::vector<std::vector<std::string>> soft = {
        {"H", "H", "H", "H", "D", "D", "H", "H", "H", "H"}, //A,2 (13)
        {"H", "H", "H", "H", "D", "D", "H", "H", "H", "H"}, //A,3 (14)
        {"H", "H", "H", "D", "D", "D", "H", "H", "H", "H"}, //A,4 (15)
        {"H", "H", "H", "D", "D", "D", "H", "H", "H", "H"}, //A,5 (16)
        {"H", "H", "D", "D", "D", "D", "H", "H", "H", "H"}, //A,6 (17)
        {"H", "d", "d", "d", "d", "d", "S", "S", "H", "H"}, //A,7 (18)
        {"H", "S", "S", "S", "S", "d", "S", "S", "S", "S"}, //A,8 (19)
        {"S", "S", "S", "S", "S", "S", "S", "S", "S", "S"}, //A,9 (20)
    };
    std::vector<std::vector<std::string>> hard = {
        {"H", "H", "H", "H", "H", "H", "H", "H", "H", "H"}, //8
        {"H", "H", "D", "D", "D", "D", "H", "H", "H", "H"}, //9
        {"H", "D", "D", "D", "D", "D", "D", "D", "D", "H"}, //10
        {"D", "D", "D", "D", "D", "D", "D", "D", "D", "D"}, //11
        {"H", "H", "H", "S", "S", "S", "H", "H", "H", "H"}, //12
        {"H", "S", "S", "S", "S", "S", "H", "H", "H", "H"}, //13
        {"H", "S", "S", "S", "S", "S", "H", "H", "H", "H"}, //14
        {"H", "S", "S", "S", "S", "S", "H", "H", "H", "H"}, //15
        {"H", "S", "S", "S", "S", "S", "H", "H", "H", "H"}, //16
        {"S", "S", "S", "S", "S", "S", "S", "S", "S", "S"}, //17
    };
    std::vector<std::vector<std::string>> surrender = {
        {"N", "N", "N", "N", "N", "N", "N", "N", "N", "N"}, //14,14
        {"N", "N", "N", "N", "N", "N", "N", "Y", "N", "N"}, //15,15
        {"N", "N", "N", "N", "N", "N", "Y", "Y", "Y", "N"}, //16,16
        {"N", "N", "N", "N", "N", "N", "N", "N", "N", "N"} //17,17
    };
    Action decode_split(Hand&);
    Action decode_soft(Hand&);
    Action decode_hard(Hand&);
    Action decode_surrender(Hand&);
    int count;
    Card d;
    Strategy(int strat = -1);
};

#endif