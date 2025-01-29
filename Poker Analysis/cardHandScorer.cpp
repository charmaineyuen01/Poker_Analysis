//
// Created by charm on 30/10/2023.
//

#include "cardHandScorer.h"

//Boolean for flush and straight.
bool CardHandScorer::specialStraight(CardHand& user){
    if(user[0].getRank() == ACE && user[1].getRank() == TEN && user[2].getRank() == JACK && user[3].getRank() == QUEEN && user[4].getRank() == KING)
        return true;
    else
        return false;
}

bool CardHandScorer::flush(CardHand& user){
    if(user[0].getSuit() == user[1].getSuit() && user[1].getSuit() == user[2].getSuit() && user[2].getSuit() == user[3].getSuit() && user[3].getSuit() == user[4].getSuit())
          return true;
    else
        return false;
}

bool CardHandScorer::straight(CardHand& user){
    bool temp = true;
    int i = 0;
    while (temp && i < 4) {
        if(user[i].getRank() == (user[i+1].getRank() - 1)){
            i++;
            temp = true;
        }
        else if(specialStraight(user)){
            temp = true;
            break;
        }
        else{
            temp = false;
            break;
        }
    }
    return temp;
}

bool CardHandScorer::straightFlush(CardHand& user){
    if(flush(user) && straight(user))
        return true;
    else
        return false;
}

bool CardHandScorer::royalFlush(CardHand& user){
    if(flush(user) && specialStraight(user))
        return true;
    else
        return false;
}

//Boolean for duplicates.
int CardHandScorer::duplicate(CardHand& user){
    int count = 1;
    int temp = 1;
    //
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 5; ++j) {
            if(user[i].getRank() == user[j].getRank()){
                count++;
                i++;
            }
            else{
                if(temp < count)
                    temp = count;
                count = 1;
                break;
            }
        }
    }
    if(temp > count)
        return temp;
    else
        return count;
}

bool CardHandScorer::fourKind(CardHand& user){
    if(duplicate(user) == 4)
        return true;
    else
        return false;
}

bool CardHandScorer::threeKind(CardHand& user){
    if(duplicate(user) >= 3)
        return true;
    else
        return false;
}

bool CardHandScorer::fullHouse(CardHand& user){
    if(threeKind(user)){
        if(user[0].getRank() == user[1].getRank() && user[0].getRank() != user[2].getRank())
            return true;
        else if(user[3].getRank() == user[4].getRank() && user[3].getRank() != user[2].getRank())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool CardHandScorer::twoPair(CardHand& user){
    int count = 1;
    int temp = 1;
    //
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 5; ++j) {
            if(user[i].getRank() == user[j].getRank()){
                count++;
                if(temp < count)
                    temp = 2;
                i = i + 2;
            }
            else{
                break;
            }
        }
    }
    if(temp == count && count == 2)
        return true;
    else
        return false;
}

bool CardHandScorer::onePair(CardHand& user){
    if(duplicate(user) >= 2)
        return true;
    else
        return false;
}

ScoreCard CardHandScorer::analysis(CardHand& user) {
    user.sortRank();
    ScoreCard s;
    if(royalFlush(user)){
        s.addScore(ROYAL_FLUSH);
        s.addScore(STRAIGHT_FLUSH);
        s.addScore(FLUSH);
        s.addScore(STRAIGHT);
    }
    else if(straightFlush(user)){
        s.addScore(STRAIGHT_FLUSH);
        s.addScore(FLUSH);
        s.addScore(STRAIGHT);
    }
    else if (flush(user))
        s.addScore(FLUSH);
    else if(straight(user))
        s.addScore(STRAIGHT);
    //
    if(fourKind(user)){
        s.addScore(FOUR_OF_A_KIND);
        s.addScore(THREE_OK_A_KIND);
        s.addScore(TWO_PAIR);
        s.addScore(ONE_PAIR);
    }
    else if(fullHouse(user)){
        s.addScore(FULL_HOUSE);
        s.addScore(THREE_OK_A_KIND);
        s.addScore(ONE_PAIR);
    }
    else if(threeKind(user))
        s.addScore(THREE_OK_A_KIND);
    else if(twoPair(user)){
        s.addScore(TWO_PAIR);
        s.addScore(ONE_PAIR);
    }
    else if(onePair(user))
        s.addScore(ONE_PAIR);
    s.addScore(HIGH_CARD);
    return s;
}