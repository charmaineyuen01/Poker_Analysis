//
// Created by charm on 24/10/2023.
//

#include "deck.h"

Deck::Deck(){
  for (int i = CLUB; i <= SPADE; ++i) {
      for (int j = ACE; j <= KING; ++j) {
          list.emplace_back(static_cast<Rank>(j), static_cast<Suit>(i));
       }
  }
}

const Card& Deck::operator[](unsigned int index){
    return list[index];
}

void Deck::shuffle(){
    for (int i = 0; i < 52; ++i) {
         std::swap(list[i], list[rand()%52]);
    }
}

std::ostream& operator<<(std::ostream& out,  const Deck& deck){
    for (const Card& card : deck.list) {
        out << card;
    }
    return out;
}

Card Deck::getCard(const Deck& deck, int value){
    Card card;
    card = deck.list[value];
    return card;
}