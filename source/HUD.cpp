#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../include/HUD.hpp"

HUD::HUD(){
	textFont.loadFromFile("../graphics/CaviarDreams.ttf");
        scoreText.setFont(textFont);
        scoreText.setString("SCORE:");
        scoreText.setCharacterSize(25);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(50,840);
        displayedScore.setFont(textFont);
        displayedScore.setCharacterSize(25);
        displayedScore.setFillColor(sf::Color::White);
        displayedScore.setPosition(scoreText.getPosition().x+100,scoreText.getPosition().y);

	healthText.setFont(textFont);
	healthText.setString("HEALTH:");
	healthText.setCharacterSize(25);
	healthText.setFillColor(sf::Color::White);
	healthText.setPosition(W_WIDTH-220,840);
	displayedHealth.setFont(textFont);
	displayedHealth.setCharacterSize(25);
	displayedHealth.setFillColor(sf::Color::White);
	displayedHealth.setPosition(healthText.getPosition().x+115,healthText.getPosition().y);

	livesText.setFont(textFont);
	livesText.setString("LIVES:");
	livesText.setCharacterSize(25);
	livesText.setFillColor(sf::Color::White);
	livesText.setPosition(W_WIDTH-220,740);
	displayedLives.setFont(textFont);
	displayedLives.setCharacterSize(25);
	displayedLives.setFillColor(sf::Color::White);
	displayedLives.setPosition(livesText.getPosition().x+90,livesText.getPosition().y);

	EndScreen.loadFromFile("../graphics/end_screen.png");
	ESprite.setTexture(EndScreen);
	ESprite.scale(.390625,.390625);
	ESprite.setPosition(0,0);
}
 

void HUD::updateScore(int x){
        std::string score = std::to_string(x);
        displayedScore.setString(score);
}

void HUD::updateHealth(int h){
	std::string Health = std::to_string(h);
	displayedHealth.setString(Health);
}

void HUD::updateLives(int l){
	std::string Lives = std::to_string(l);
	displayedLives.setString(Lives);
}

sf::Text HUD::getDisplayedScore(){
        return displayedScore;
}

sf::Text HUD::getScoreText(){
        return scoreText;
}

sf::Text HUD::getDisplayedHealth(){
	return displayedHealth;
}

sf::Text HUD::getHealthText(){
	return healthText;
}

sf::Text HUD::getDisplayedLives(){
	return displayedLives;
}

sf::Text HUD::getLivesText(){
	return livesText;
}

sf::Sprite HUD::getEndScreen(){
	return ESprite;
}

