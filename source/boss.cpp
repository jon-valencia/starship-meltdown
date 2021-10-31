#include "../include/boss.hpp"

Boss::Boss(){
	
	//values
	this->speed = SPEED;
	this->dir = DIRECT;
	
	//the ship
	BigBoss.loadFromFile("../graphics/boss_ship.png");
	ship.setTexture(BigBoss);
	ship.scale(.5,.4);
	ship.setOrigin(sf::Vector2f(0, 0));
	ship.setPosition(sf::Vector2f(W_WIDTH/2-224.25, 0));

	//health bar
	Bar.setSize(sf::Vector2f(448.5,20));
	Bar.setFillColor(sf::Color::Green);
	HealthBar.setSize(sf::Vector2f(448.5,20));
	HealthBar.setFillColor(sf::Color::Transparent);
	HealthBar.setOutlineColor(sf::Color::White);
	HealthBar.setOutlineThickness(5);
};

sf::Sprite Boss::getShip(){
	return this->ship;
}

sf::RectangleShape Boss::getBar(){
	return this->Bar;
}

sf::RectangleShape Boss::getHealthBar(){
	return this->HealthBar;
}

void Boss::setSpeed(int s){
	speed = s;
}

int Boss::getSpeed(){
	return speed;
}

void Boss::setDir(int d){
	dir = d;
}

int Boss::getDir(){
	return dir;
}

void Boss::movement(){
	ship.move(dir*speed/2,0);
	if(ship.getPosition().x>=W_WIDTH-224.25){
		dir = -DIRECT;
	}
	if(ship.getPosition().x<=-224.25){
		dir = DIRECT;
	}
	HealthBar.setPosition(ship.getPosition().x, ship.getPosition().y+5);
		Bar.setPosition(HealthBar.getPosition());
}
	
	
