//
// Created by charm on 26/10/2023.
//

#include "cardHand.h"

CardHand::CardHand(){}

void CardHand::addCard(const Card& card)
{
    user.push_back(card);
}

Card CardHand::getCardHand(const CardHand& chand, int value){
    Card card;
    card = chand.user[value];
    return card;
}

const Card& CardHand::operator[](unsigned int index){
    return user[index];
}

std::ostream& operator<<(std::ostream& out,  const CardHand& chand){
    for (const Card& card : chand.user) {
        out << card;
    }
    return out;
}

//sort Rank
void CardHand::sortRank(){
    std::sort(user.begin(), user.end());
}