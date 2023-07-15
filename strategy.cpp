#include "strategy.h"

Strategy::Strategy(int strat) : count(0) {}

Strategy::Action Strategy::decode_split(Hand& h) {
    if (h.size() == 2 && value(h.get_card(0)) == value(h.get_card(1))) {
        if (split[value(h.get_card(0)) - 1][value(d) - 1] == "Y") {
            return Action::SPLT;
        }
    }
    return Action::CONT;
}
Strategy::Action Strategy::decode_soft(Hand& h) {
    std::string act = soft[h.total - 13][value(d) - 1];
    if (act == "D" || act == "H") {
        if ((act == "D") && h.actionable == -1) return Action::DBL;
        return Action::HIT;
    }
    else {
        if ((act == "d") && h.actionable == -1) return Action::DBL;
        return Action::STND;
    }
}
Strategy::Action Strategy::decode_hard(Hand& h) {
    std::string act = hard[std::min(17, std::max(8, h.total)) - 8][value(d) - 1];
    if (act == "D" || act == "H") {
        if ((act == "D") && h.actionable == -1) return Action::DBL;
        return Action::HIT;
    }
    return Action::STND;
}
Strategy::Action Strategy::decode_surrender(Hand& h) {
    if (h.actionable == -1 && h.total >= 14 && h.total <= 17) {
        std::string act = soft[h.total - 14][value(d) - 1];
        if (act == "Y") return Action::SUR;
    }
    return Action::CONT;
}