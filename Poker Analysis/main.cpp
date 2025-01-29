
#include <SFML/Graphics.hpp>

#include "deck.h"
#include "cardHand.h"
#include "cardHandScorer.h"
#include "scoreCard.h"
#include "sfml.h"

int main() {
    //Seed the random.
    srand(time(0));


    ScoreCard score;

    while(!ScoreCard::royalFlush()){
        Deck d;
        CardHand hand;
        CardHandScorer chs;

        d.shuffle();
        for (int i = 0; i < 5; ++i) {
            hand.addCard(d.getCard(d, i * 5));
        }
        score = chs.analysis(hand);
    }
//
//    std::cout << score;

    //sfml
    sf::RenderWindow window({600,850,32}, "Poker Analysis");
    window.setFramerateLimit(60);

    sfml sfml;
    sfml.fillCard();
    sfml.fillText();

    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        for (const auto& card : sfml.cards) {
            window.draw(card);
        }

        for (const auto& text : sfml.texts) {
            window.draw(text);
        }

        window.display();
    }
}