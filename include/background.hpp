#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"

class Background{
    private:
	int speed, dir;
        sf::Texture textureBackground;
        sf::Sprite spriteBackground, sbg2;


    public:
    Background();
    sf::Sprite getSprite();
    sf::Sprite getSprite2();
    void setSpeed(int s);
    int getSpeed();
    void setDir(int d);
    int getDir();
    void backMove();
    void menuBack();
    void menuMove();
};
