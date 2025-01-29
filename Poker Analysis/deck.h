//
// Created by charm on 24/10/2023.
//

#ifndef SFML_PROJECT_DECK_H
#define SFML_PROJECT_DECK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "card.h"

class Deck {
private:
    std::vector<Card> list;

public:
    Deck(); // this is the constructor
    const Card &operator[](unsigned int index);
    void shuffle(); // puts cards in random order
    friend std::ostream &operator<<(std::ostream &out, const Deck &deck); // prints all the cards to the console
    Card getCard(const Deck &deck, int value);
};


#endif //SFML_PROJECT_DECK_H
