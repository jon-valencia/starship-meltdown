#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "def.hpp"

class Player{
    private:
        //Player's x and y coordinates
        int x, y;

        //the player's score
        int score;

	int Health;

	int Lives;

        //The player's starting position
        sf::Vector2f ship_position;

        //Player's body
        sf::Sprite spriteStarship;

        //Player's skin
        sf::Texture textureStarship;

	//Player's Health Bar
	sf::RectangleShape HealthBar;
	   
    public:

      	Player();
	sf::Sprite getSprite();
	sf::RectangleShape getHealthBar();

	int getHealth();
	void setHealth();
	void TakingDamage(int dmg);
	void addLives();
	int getLives();
	void LosingLife();
	void addPoints(int points);
	int getScore();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
	void reset();
};
