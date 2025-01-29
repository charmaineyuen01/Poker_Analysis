//
// Created by charm on 2/11/2023.
//

#include "image.h"
sf::Texture image::texture;

void image::loadTexture(){
    texture.loadFromFile("Deck.png");
}

sf::Texture& image::getImage(){
    loadTexture();
    return texture;
}
