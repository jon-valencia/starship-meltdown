#include "../include/asteroid.hpp"



Asteroid::Asteroid(){
    this->damage = 10;
    this->posX = (rand() % W_WIDTH);
    this->posY = (rand() % 200)*-1;
	isActive = false;

    textureAsteroid.loadFromFile("../graphics/8-bit_Asteroid.png");
    spriteAsteroid.setTexture(textureAsteroid);
    spriteAsteroid.setRotation(rand() % 180);
    spriteAsteroid.setOrigin(0, 0);
    spriteAsteroid.setPosition(posX, posY);
    explodedAsteroid.loadFromFile("../graphics/exploded_10.png");
    explodedSprite.setTexture(explodedAsteroid);
    explodedSprite.setScale(1.25,1.25);
    explodedSprite.setRotation(spriteAsteroid.getRotation());
};

sf::Sprite Asteroid :: getSprite(){
    return this->spriteAsteroid;
}

sf::Sprite Asteroid::getExplodedAsteroid(){
	return this->explodedSprite;
}

void Asteroid::sendAsteroid(){
    spriteAsteroid.move(.5, (rand() % SPEED + 1));
    if(spriteAsteroid.getPosition().y >= 1200){
	spriteAsteroid.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
    }
    explodedSprite.setPosition(spriteAsteroid.getPosition());
}

void Asteroid::setActive(){
	isActive = true;
}

void Asteroid::reset(){
	spriteAsteroid.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
}

bool Asteroid::getActiveStatus(){
	return isActive;
}
