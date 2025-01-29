//
// Created by charm on 26/10/2023.
//

#ifndef SFML_PROJECT_CARDHAND_H
#define SFML_PROJECT_CARDHAND_H

#include "deck.h"
#include <algorithm>
class CardHand {
private:
    std::vector<Card> user;

public:
    CardHand();
    void addCard(const Card& card);
    Card getCardHand(const CardHand &chand, int value);
    void sortRank();

    const Card& operator[](unsigned int index);
    friend std::ostream& operator<<(std::ostream& out,  const CardHand& chand);
};


#endif //SFML_PROJECT_CARDHAND_H
