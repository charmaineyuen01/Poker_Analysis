//
// Created by charm on 2/11/2023.
//

#ifndef SFML_PROJECT_IMAGE_H
#define SFML_PROJECT_IMAGE_H

#include <SFML/Graphics.hpp>

class image {
private:
    static sf::Texture texture;
    static void loadTexture();

public:
    static sf::Texture& getImage();
};


#endif //SFML_PROJECT_IMAGE_H
