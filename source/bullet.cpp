#include "../include/bullet.hpp"
#include "../include/asteroid.hpp"
#include "../include/boss.hpp"

Bullet::Bullet(float x, float y){

	this->damage = 10;
	posX = x;
	posY = y;
	isActive = false;

	bulletTexture.loadFromFile("../graphics/bullet.png");
	bulletPlayer.setTexture(bulletTexture);
	bulletPlayer.setScale(0.1,0.1);
	bulletPlayer.setOrigin(0, 0);
	bulletPlayer.setPosition(x, y);

	bulletBoss.setTexture(bulletTexture);
	bulletBoss.setScale(.25,.25);
	bulletBoss.setOrigin(0, 0);
	bulletBoss.setPosition(x, y);
};

void Bullet::setPos(float x, float y){
	bulletPlayer.setPosition(x, y);
}

void Bullet::setPosBoss(float x, float y){
	bulletBoss.setPosition(x, y);
}

float Bullet::getPos(){
	bulletPlayer.getPosition();
}

sf::Sprite Bullet::getbulletPlayer(){
	return this->bulletPlayer;
}

sf::Sprite Bullet::getbulletBoss(){
	return this->bulletBoss;
}

void Bullet::setActive(){
	isActive = true;
}

void Bullet::Deactive(){
	isActive = false;
}

void Bullet::bulletFired(){
	bulletPlayer.move(0, -2*SPEED);
	if(bulletPlayer.getPosition().y <= -100){
		isActive = false;
		return;
	}
}

void Bullet::bossbulletFired(){
	bulletBoss.move(0,2*SPEED);
	if(bulletBoss.getPosition().y >= 1800){
		isActive = false;
		return;
	}
}

bool Bullet::GetActiveStatus(){
	return isActive;
}




