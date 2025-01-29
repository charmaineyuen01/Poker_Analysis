//
// Created by charm on 31/10/2023.
//

#include "scoreCard.h"

ScoreCard::ScoreCard(){}

void ScoreCard::addScore(Scores score)
{
    scores[score]++;
    totalScore[score]++;
}

int ScoreCard::operator[](unsigned int index){
    return scores[index];
}

std::ostream& operator<<(std::ostream& out,  const ScoreCard& score){
    out << "Royal Flush: " << score.totalScore[HIGH_CARD]/score.totalScore[ROYAL_FLUSH] << " : 1\n";
    out << "Straight Flush: " << score.totalScore[HIGH_CARD]/score.totalScore[STRAIGHT_FLUSH] << " : 1\n";
    out << "Four of a Kind: " << score.totalScore[HIGH_CARD]/score.totalScore[FOUR_OF_A_KIND] << " : 1\n";
    out << "Full House: " << score.totalScore[HIGH_CARD]/score.totalScore[FULL_HOUSE] << " : 1\n";
    out << "Flush: " << score.totalScore[HIGH_CARD]/score.totalScore[FLUSH] << " : 1\n";
    out << "Straight: " << score.totalScore[HIGH_CARD]/score.totalScore[STRAIGHT] << " : 1\n";
    out << "Three of a Kind: " << score.totalScore[HIGH_CARD]/score.totalScore[THREE_OK_A_KIND] << " : 1\n";
    out << "Two Pairs: " << score.totalScore[HIGH_CARD]/score.totalScore[TWO_PAIR] << " : 1\n";
    out << "One Pair: " << score.totalScore[HIGH_CARD]/score.totalScore[ONE_PAIR] << " : 1\n";
    out << "High Card: " << score.totalScore[HIGH_CARD]/score.totalScore[HIGH_CARD] << " : 1\n";
    return out;
}

std::string ScoreCard::toString(int value, const ScoreCard& score){
    return std::to_string(score.totalScore[HIGH_CARD]/score.totalScore[value]);
}

bool ScoreCard::royalFlush()
{
    return totalScore[ROYAL_FLUSH] > 0;
}