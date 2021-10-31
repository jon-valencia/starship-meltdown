#include <iostream>
#include "../include/starship.hpp"

Starship::Starship(){
    this->x_dir = -400;
    this->y_dir = -200;
    starshipTexture.loadFromFile("../graphics/blueships1.png");
    starshipSprite.setTexture(starshipTexture);
    starshipSprite.setOrigin(x_dir, y_dir);

};

sf::Sprite Starship:: getSprite(){
        return this->starshipSprite;
}