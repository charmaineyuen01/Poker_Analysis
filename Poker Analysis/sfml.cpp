//
// Created by charm on 2/11/2023.
//

#include "sfml.h"

sfml::sfml() {
    font.loadFromFile("arial.ttf");
}

sfml::sfml(sf::Font& font){
    this->font = font;
}

sfml::sfml(Rank rank, Suit suit, sf::Vector2f position) : sfml(image::getImage(), rank, suit, position){}

sfml::sfml(sf::Texture& image, Rank rank, Suit suit, sf::Vector2f position){
    sf::IntRect intRect;
    intRect.width = image.getSize().x / 13;
    intRect.height = image.getSize().y / 4;
    intRect.left = intRect.width * rank;
    intRect.top = intRect.height * suit;
    sprite.setTexture(image);
    sprite.setTextureRect(intRect);
    sprite.setPosition(position);
}

sf::Text sfml::text(std::string string, std::string prob, sf::Vector2f position, const sf::Font& font){
    sf::Text word;
    word.setFont(font);
    word.setCharacterSize(24);
    word.setFillColor(sf::Color::Red);
    word.setPosition(position);
    word.setString(string + prob + " : 1");
    return word;
}

void sfml::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(sprite);
    for (const auto& text : texts) {
        window.draw(text);
    }
}

void sfml::fillCard(){
    //ROYAL_FLUSH
    cards.push_back(sfml(TEN, SPADE, {10, 20}));
    cards.push_back(sfml(JACK, SPADE, {70, 20}));
    cards.push_back(sfml(QUEEN, SPADE, {130, 20}));
    cards.push_back(sfml(KING, SPADE, {190, 20}));
    cards.push_back(sfml(ACE, SPADE, {250, 20}));
    //STRAIGHT_FLUSH
    cards.push_back(sfml(TWO, SPADE, {10, 100}));
    cards.push_back(sfml(THREE, SPADE, {70, 100}));
    cards.push_back(sfml(FOUR, SPADE, {130, 100}));
    cards.push_back(sfml(FIVE, SPADE, {190, 100}));
    cards.push_back(sfml(SIX, SPADE, {250, 100}));
    //FOUR_OF_A_KIND
    cards.push_back(sfml(SEVEN, SPADE, {10, 180}));
    cards.push_back(sfml(SEVEN, HEART, {70, 180}));
    cards.push_back(sfml(SEVEN, DIAMOND, {130, 180}));
    cards.push_back(sfml(SEVEN, CLUB, {190, 180}));
    cards.push_back(sfml(ACE, SPADE, {250, 180}));
    //FULL_HOUSE
    cards.push_back(sfml(SEVEN, SPADE, {10, 260}));
    cards.push_back(sfml(SEVEN, HEART, {70, 260}));
    cards.push_back(sfml(SEVEN, DIAMOND, {130, 260}));
    cards.push_back(sfml(ACE, SPADE, {190, 260}));
    cards.push_back(sfml(ACE, HEART, {250, 260}));
    //FLUSH
    cards.push_back(sfml(SEVEN, SPADE, {10, 340}));
    cards.push_back(sfml(ACE, SPADE, {70, 340}));
    cards.push_back(sfml(KING, SPADE, {130, 340}));
    cards.push_back(sfml(THREE, SPADE, {190, 340}));
    cards.push_back(sfml(FIVE, SPADE, {250, 340}));
    //STRAIGHT
    cards.push_back(sfml(THREE, SPADE, {10, 420}));
    cards.push_back(sfml(FOUR, HEART, {70, 420}));
    cards.push_back(sfml(FIVE, DIAMOND, {130, 420}));
    cards.push_back(sfml(SIX, CLUB, {190, 420}));
    cards.push_back(sfml(SEVEN, SPADE, {250, 420}));
    //THREE_OK_A_KIND
    cards.push_back(sfml(TWO, SPADE, {10, 500}));
    cards.push_back(sfml(ACE, HEART, {70, 500}));
    cards.push_back(sfml(SEVEN, SPADE, {130, 500}));
    cards.push_back(sfml(SEVEN, HEART, {190, 500}));
    cards.push_back(sfml(SEVEN, DIAMOND, {250, 500}));
    //TWO_PAIR
    cards.push_back(sfml(FIVE, DIAMOND, {10, 580}));
    cards.push_back(sfml(ACE, HEART, {70, 580}));
    cards.push_back(sfml(ACE, SPADE, {130, 580}));
    cards.push_back(sfml(SEVEN, HEART, {190, 580}));
    cards.push_back(sfml(SEVEN, SPADE, {250, 580}));
    //ONE_PAIR
    cards.push_back(sfml(SIX, CLUB, {10, 660}));
    cards.push_back(sfml(ACE, HEART, {70, 660}));
    cards.push_back(sfml(TWO, DIAMOND, {130, 660}));
    cards.push_back(sfml(SEVEN, HEART, {190, 660}));
    cards.push_back(sfml(SEVEN, SPADE, {250, 660}));
    //HIGH_CARD
    cards.push_back(sfml(SEVEN, SPADE, {10, 740}));
    cards.push_back(sfml(TWO, HEART, {70, 740}));
    cards.push_back(sfml(FIVE, CLUB, {130, 740}));
    cards.push_back(sfml(KING, SPADE, {190, 740}));
    cards.push_back(sfml(TEN, DIAMOND, {250, 740}));
}

void sfml::fillText(){
    texts.push_back(text("Royal Flush: ", score.toString(ROYAL_FLUSH, score), {310, 30}, font));
    texts.push_back(text("Straight Flush: ", score.toString(STRAIGHT_FLUSH, score), {310, 110}, font));
    texts.push_back(text("Four of a Kind: ", score.toString(FOUR_OF_A_KIND, score), {310, 190}, font));
    texts.push_back(text("Full House: ", score.toString(FULL_HOUSE, score), {310, 270}, font));
    texts.push_back(text("Flush: ", score.toString(FLUSH, score), {310, 350}, font));
    texts.push_back(text("Straight: ",  score.toString(STRAIGHT, score), {310, 430}, font));
    texts.push_back(text("Three of a Kind: ", score.toString(THREE_OK_A_KIND, score), {310, 510}, font));
    texts.push_back(text("Two Pairs: ", score.toString(TWO_PAIR, score), {310, 590}, font));
    texts.push_back(text("One Pair: ", score.toString(ONE_PAIR, score), {310, 670}, font));
    texts.push_back(text("High Card: ", score.toString(HIGH_CARD, score), {310, 750}, font));
}