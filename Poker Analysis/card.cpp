//
// Created by charm on 17/10/2023.
//

#include "card.h"

Card::Card(){}

Card::Card(Rank rank, Suit suit): rank(rank), suit(suit){}

std::string Card::rankToString() const{
    switch(rank){
        case ACE: return "Ace";
        case TWO: return "Two";
        case THREE: return "Three";
        case FOUR: return "Four";
        case FIVE: return "Five";
        case SIX: return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE: return "Nine";
        case TEN: return "Ten";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
    }
}

std::string Card::suitToString() const{
    switch(suit){
        case CLUB: return "Club";
        case DIAMOND: return "Diamond";
        case HEART: return "Heart";
        case SPADE: return "Spade";
    }
}

bool operator<(const Card& card1, const Card& card2){
    return card1.rank < card2.rank;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
    out << card.rankToString() << " of " << card.suitToString() << ".\n";
    return out;
}

const Rank& Card::getRank() const{
    return rank;
}

const Suit& Card::getSuit() const{
    return suit;
}