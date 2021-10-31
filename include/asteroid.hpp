#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Asteroid{
    private:
        //the amount of damage dealt on contact
        int damage;

	float posX, posY;

	bool isActive;

        //The Asteroid skin
        sf::Texture textureAsteroid;
	sf::Texture explodedAsteroid;

        //The asteroid body
        sf::Sprite spriteAsteroid;
	sf::Sprite explodedSprite;



    public:
        Asteroid();
        sf::Sprite getSprite();
	sf::Sprite getExplodedAsteroid();
        void sendAsteroid();
	void setActive();
	void reset();
	bool getActiveStatus();
};
