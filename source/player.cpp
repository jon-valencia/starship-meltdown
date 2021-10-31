#include "../include/player.hpp"

Player::Player(){
    score=0;
    Lives=3;
    Health=100;
    textureStarship.loadFromFile("../graphics/blueships1.png");
    spriteStarship.setTexture(textureStarship);
    spriteStarship.setOrigin(0, 0);
    spriteStarship.setPosition(W_WIDTH/2-50, 700);

    HealthBar.setSize(sf::Vector2f(Health*16, 50));
    HealthBar.setFillColor(sf::Color::Green);
    HealthBar.setPosition(0, W_HEIGHT-25);
};

//Returns the Ship/Player Image
sf::Sprite Player::getSprite(){
    return this->spriteStarship;
}

sf::RectangleShape Player::getHealthBar(){
	return this->HealthBar;
}

void Player::TakingDamage(int dmg){
	Health -= dmg;
	HealthBar.setSize(sf::Vector2f(Health*16, W_HEIGHT-30));
	if(Health <= 0){
		HealthBar.setSize(sf::Vector2f(W_WIDTH,50));
	}
}

void Player::addLives(){
	Lives += 1;
}

void Player::setHealth(){
	Health = 100;
}

int Player::getHealth(){
	return Health;
}

void Player::LosingLife(){
	Lives -= 1;
}	

int Player::getLives(){
	return Lives;
}

void Player::addPoints(int points){
	score += points;
}

int Player::getScore(){
	return score;
}

//Moves the Player Right
void Player:: moveRight(){
    spriteStarship.move(SPEED, 0);
    if(spriteStarship.getPosition().x >= W_WIDTH - 50){
	    spriteStarship.move(-SPEED,0);
    }
}

//Moves the Player Left
void Player::moveLeft(){
    spriteStarship.move(-SPEED,0);
    if(spriteStarship.getPosition().x <= -50){
	    spriteStarship.move(SPEED,0);
    }
}

//Moves the Player Up
void Player::moveUp(){
    spriteStarship.move(0,-SPEED);
    if(spriteStarship.getPosition().y <= W_HEIGHT/2-100){
	spriteStarship.move(0,SPEED);
    }
}

//Moves the Player Down
void Player::moveDown(){
    spriteStarship.move(0,SPEED);
    if(spriteStarship.getPosition().y >= W_HEIGHT - 50){
	    spriteStarship.move(0,-SPEED);
    }
}

void Player::reset(){
	spriteStarship.setPosition(W_WIDTH/2-50, 700);
}

/*void Player::shoot(){
	bPtr = new Bullet(spriteStarship.getPosition().x+40, spriteStarship.getPosition().y);
	bVect.push_back(bPtr);

	bPtr->setActive();
}*/


/*void Player::SpawnAst(sf::RenderWindow &window){
 	Asteroid ass[15];
	
	for(int i = 0; i < 15; i++){
		ass[i].sendAsteroid();

		if(Collision::PixelPerfectTest(ass[i].getSprite(), spriteStarship)){
			window.draw(ass[i].getExplodedAsteroid());
			ass[i].reset();
		}
		window.draw(ass[1].getSprite());
	};
}*/

/*void Player::update(sf::RenderWindow &window){
	std::vector<Bullet*>::iterator itr;
	std::vector<Asteroid> ass(15);
	Asteroid a1;

	for(itr = bVect.begin(); itr < bVect.end(); itr++){
		if((*itr)->GetActiveStatus()){
			(*itr)->bulletFired();
			window.draw((*itr)->getbulletPlayer());
		}
	}

	for(int count = 0; count < ass.size(); count++){
		ass[count].sendAsteroid();	
		window.draw(ass[count].getSprite());
	}

}*/
