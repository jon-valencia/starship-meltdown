#include "../include/background.hpp"

Background::Background(){
    this->speed = SPEED;
    this->dir = DIRECT;

    textureBackground.loadFromFile("../graphics/Nebula_Red.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(1,.23);
    sbg2.setTexture(textureBackground);
    sbg2.setScale(1,.23);
    sbg2.setPosition(0,W_HEIGHT);
}

sf::Sprite Background::getSprite(){
    return this->spriteBackground;
}

sf::Sprite Background::getSprite2(){
    return this->sbg2;
}

void Background::setSpeed(int s){
	speed = s;
}

int Background::getSpeed(){
	return speed;
}

void Background::setDir(int d){
	dir = d;
}

int Background::getDir(){
	return dir;
}

void Background::backMove(){
	spriteBackground.move(0,DIRECT*-15);
	sbg2.move(0,DIRECT*-15);
	if(spriteBackground.getPosition().y<-W_HEIGHT){
		spriteBackground.setPosition(0,W_HEIGHT);
	}
	if(sbg2.getPosition().y<-W_HEIGHT){
		sbg2.setPosition(0,W_HEIGHT);
	}

}
