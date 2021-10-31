
#include <iostream>
#include "SFML/Graphics.hpp"

class Healthbar{
    private :
        sf::RectangleShape bar;
        int len;
        int wid;
        //int healthLen;

    public:
        Healthbar();
        sf::RectangleShape updateHealthBar(int x);
        sf::RectangleShape getBar();
};