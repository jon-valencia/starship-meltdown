#include <iostream>
#include "SFML/Graphics.hpp"
#include "def.hpp"
#include <string>

class HUD{
    private:
	
	sf::Font textFont;
	sf::Text scoreText;
        sf::Text displayedScore;
	sf::Text healthText;
	sf::Text displayedHealth;
	sf::Text livesText;
	sf::Text displayedLives;

        std::string score;
	std::string Health;

	sf::Texture EndScreen;
	sf::Sprite ESprite;

    public:
        HUD();
        void updateScore(int x);
	void updateHealth(int h);
	void updateLives(int l);
        sf::Text getDisplayedScore();
        sf::Text getScoreText();
	sf::Text getDisplayedHealth();
	sf::Text getHealthText();
	sf::Text getDisplayedLives();
	sf::Text getLivesText();
	sf::Sprite getEndScreen();
};
