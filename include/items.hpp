#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Items{
    private:
        //the amount of damage dealt on contact
        int damage;

	float posX, posY;

	bool isActive;

        //The Asteroid skin
        sf::Texture textureBomb;
	sf::Texture textureHeart;
	sf::Texture textureExplodedBomb;

        //The asteroid body
        sf::Sprite Bomb;
	sf::Sprite Heart;
	sf::Sprite BombExplosion;



    public:
        Items();
        sf::Sprite getBomb();
	sf::Sprite getHeart();
	sf::Sprite getBombExplosion();
        void sendBomb();
	void sendHeart();
	void resetBomb();
	void resetHeart();
};
