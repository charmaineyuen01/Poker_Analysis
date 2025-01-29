//
// Created by charm on 30/10/2023.
//

#ifndef SFML_PROJECT_CARDHANDSCORER_H
#define SFML_PROJECT_CARDHANDSCORER_H

#include "cardHand.h"
#include "SCoreCard.h"

class CardHandScorer{
private:

public:
    //Boolean for flush and straight.
    bool specialStraight(CardHand& user);
    bool flush(CardHand& user);
    bool straight(CardHand& user);
    bool straightFlush(CardHand& user);
    bool royalFlush(CardHand& user);

    //Boolean for duplicates.
    int duplicate(CardHand& user);
    bool fourKind(CardHand& user);
    bool threeKind(CardHand&user);
    bool fullHouse(CardHand& user);
    bool twoPair(CardHand& user);
    bool onePair(CardHand& user);

    ScoreCard analysis(CardHand& user);
};

#endif //SFML_PROJECT_CARDHANDSCORER_H
