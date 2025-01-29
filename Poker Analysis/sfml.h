//
// Created by charm on 2/11/2023.
//

#ifndef SFML_PROJECT_SFML_H
#define SFML_PROJECT_SFML_H

#include <SFML/Graphics.hpp>
#include "card.h"
#include "image.h"
#include "scoreCard.h"

class sfml : public sf::Drawable{
public:
    sfml();
    sfml(sf::Font& font);
    sfml(Rank rank, Suit suit, sf::Vector2f position);
    sfml(sf::Texture& image, Rank rank, Suit suit, sf::Vector2f position);
    sf::Text text(std::string string, std::string prob, sf::Vector2f postion, const sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::vector<sfml> cards;
    std::vector<sf::Text> texts;
    void fillCard();
    void fillText();

private:
    sf::Sprite sprite;
    sf::Font font;
    ScoreCard score;
};


#endif //SFML_PROJECT_SFML_H
