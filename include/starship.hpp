#include "SFML/Graphics.hpp"
#include <iostream>

class Starship{
    private:
        sf::Texture starshipTexture;
        int score;
        sf::Sprite starshipSprite;
        sf::RectangleShape starshipShape;
        float x_dir, y_dir;

    public:
        Starship();
        sf::Sprite getSprite();
        //getTexture();
};