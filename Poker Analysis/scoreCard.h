//
// Created by charm on 31/10/2023.
//

#ifndef SFML_PROJECT_SCORECARD_H
#define SFML_PROJECT_SCORECARD_H

#include "scores.h"
#include <iostream>

class ScoreCard {
private:
    int scores[10] = {0};
    inline static int totalScore[10] = {0};

public:
    ScoreCard();
    void addScore(Scores score);
    static bool royalFlush();
    int operator[](unsigned int index);
    friend std::ostream& operator<<(std::ostream& out,  const ScoreCard& score);
    std::string toString(int value, const ScoreCard& score);
};


#endif //SFML_PROJECT_SCORECARD_H
