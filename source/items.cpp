#include "../include/items.hpp"



Items::Items(){
    this->damage = 10;
    this->posX = (rand() % W_WIDTH);
    this->posY = (rand() % 200)*-1;
	isActive = false;

    textureBomb.loadFromFile("../graphics/atomic-bomb.png");
    textureHeart.loadFromFile("../graphics/heart.png");
    textureExplodedBomb.loadFromFile("../graphics/exploded.png");
    Bomb.setTexture(textureBomb);
    Bomb.setOrigin(0, 0);
    Bomb.setPosition(posX, posY);
    Bomb.setScale(.1,.15);
    Bomb.setRotation(rand() % 180);
    BombExplosion.setTexture(textureExplodedBomb);
    BombExplosion.setOrigin(0,0);
    BombExplosion.setScale(10,10);
    //BombExplosion.setRotation(Bomb.getRotation());
    Heart.setTexture(textureHeart);
    Heart.setOrigin(0, 0);
    Heart.setPosition(posX, posY);
};

sf::Sprite Items::getBomb(){
    return this->Bomb;
}

sf::Sprite Items::getHeart(){
	return this->Heart;
}

sf::Sprite Items::getBombExplosion(){
	return this->BombExplosion;
}

void Items::sendBomb(){
    Bomb.move(.5, (rand() % SPEED*2 + 1));
    if(Bomb.getPosition().y >= 1200){
	Bomb.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
    }

    BombExplosion.setPosition(Bomb.getPosition().x-400, Bomb.getPosition().y-400);
}

void Items::sendHeart(){
    Heart.move(.5, (rand() % SPEED/2 + 1));
    if(Heart.getPosition().y >= 1200){
	Heart.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
    }
}

void Items::resetBomb(){
	Bomb.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
}

void Items::resetHeart(){
	Heart.setPosition((rand() % W_WIDTH), (rand() % 200)*-1);
}

