//
// Created by charm on 17/10/2023.
//

#ifndef PROJECT12_FRIENDFUNCTION_CARD_H
#define PROJECT12_FRIENDFUNCTION_CARD_H

#include <iostream>
#include "rank.h"
#include "suit.h"

class Card {
private:
    Rank rank;
    Suit suit;
    std::string rankToString() const;
    std::string  suitToString() const;

public:
    Card();
    Card(Rank rank, Suit suit);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    friend bool operator<(const Card& card1, const Card& card2);
    const Rank& getRank() const;
    const Suit& getSuit() const;
};

#endif //PROJECT12_FRIENDFUNCTION_CARD_H
