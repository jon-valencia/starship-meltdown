#include <iostream>
#include "SFML/Graphics.hpp"
#include "../include/healthbar.hpp"

Healthbar::Healthbar(){
    len = 1000;
    wid = 25;
    bar.setSize(sf::Vector2f(len,wid));
    bar.setFillColor(sf::Color::Green);
    bar.setOrigin(-10, -880);

}

sf::RectangleShape Healthbar :: getBar(){
    return this->bar;
}

sf::RectangleShape Healthbar :: updateHealthBar(int x){
    this->len = this->len - x;
    this->bar.setSize(sf::Vector2f(len, wid));
    return this->bar;
}