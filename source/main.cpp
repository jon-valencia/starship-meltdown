#include "../include/def.hpp"
#include "../include/HUD.hpp"
#include "../include/background.hpp"
#include "../include/boss.hpp"
#include "../include/player.hpp"
#include "../include/asteroid.hpp"
#include "../include/bullet.hpp"
#include "../include/collision.hpp"
#include "../include/items.hpp"
#include "../include/menu.hpp"
#include "../include/music.hpp"
#include "../include/sfx.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

int main(){
	
	//player
    	Player star_ship;
    	Background background;
    	HUD playerHUD;

	//boss
	Boss boss;
	
	//asteroids
    	std::vector<Asteroid> ass(15);
    	
	//players bullets
	std::vector<Bullet*> bVect;
   	Bullet *bPtr;

	//boss' bullets
	std::vector<Bullet*> bossV;
	Bullet *bossPtr;

	//interactable items
	std::vector<Items> bomb(2);
	std::vector<Items> heart(1);

	//counting
	int asteroidsHit = 0;
	int bombsHit = 0;
	int hitbyAsteroid = 0;
	int hitbyBomb = 0;
	int heartsTaken = 0;
	int shotsFired = 0;
	
	//game sounds
	SFX sfx;
		//song begins
		sfx.gameStart();
		
    	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "STARSHIP MELTDOWN");
	Menu menu(window.getSize().x, window.getSize().y);
  	window.setFramerateLimit(60);
	
    	sf::Event event;
    	sf::Clock g_clock, b_clock, p_clock;

	while(window.isOpen()){
		
		while(window.pollEvent(event)){
			switch(event.type){
			case sf::Event::KeyReleased:
				switch(event.key.code){
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch(menu.GetPressedItem()){
					case 0:
					std::cout << "Play button pressed" << std::endl;
    
	while(window.isOpen()){ 	  
		
		sf::Time gameClock = g_clock.getElapsedTime();
		window.clear();

	//player controls, normal WASD movement, Mouse Click to shoot
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			window.close();
		}	
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			star_ship.moveUp();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			star_ship.moveLeft();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			star_ship.moveDown();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			star_ship.moveRight();
		}
		//setting firerate cap to 400 rpm
		sf::Time playerCD = p_clock.getElapsedTime();
		while(window.pollEvent(event)){
			if(event.type == sf::Event::MouseButtonPressed && playerCD.asSeconds() >= 0.15){
				sfx.playergun();
				bPtr = new Bullet(star_ship.getSprite().getPosition().x+40, star_ship.getSprite().getPosition().y);
				bVect.push_back(bPtr);
				bPtr->setActive();
				p_clock.restart();
				shotsFired++;
			}	
		}
		
        window.clear();
	background.backMove();	
	playerHUD.updateScore(star_ship.getScore());
	playerHUD.updateHealth(star_ship.getHealth());
	playerHUD.updateLives(star_ship.getLives());
	window.draw(background.getSprite2());
	window.draw(background.getSprite());
        window.draw(star_ship.getSprite());
	
	//drawing the asteroids and adding collision conditions
	for(int i = 0; i < ass.size(); i++){
		ass[i].sendAsteroid();

		if(Collision::PixelPerfectTest(ass[i].getSprite(), star_ship.getSprite())){
			sfx.boom(); //plays explosion if player takes damage
			star_ship.TakingDamage(10); //loss of health if player collides with asteroid
			if(star_ship.getHealth() <= 0){ //losing lives if statement
				star_ship.LosingLife();
				star_ship.setHealth();
				playerHUD.updateHealth(star_ship.getHealth());
				playerHUD.updateLives(star_ship.getLives());
				star_ship.reset();	
			}	
			
			window.draw(ass[i].getExplodedAsteroid());
			ass[i].reset();
			hitbyAsteroid++;
		}
		window.draw(ass[i].getSprite());
	}

	//drawing the powerups to the screen
	for(int i = 0; i < bomb.size(); i++){
		bomb[i].sendBomb();

		if(Collision::PixelPerfectTest(bomb[i].getBomb(), star_ship.getSprite())){
			star_ship.TakingDamage(100);
			if(star_ship.getHealth() <= 0){
				sfx.bigboom();
				window.draw(bomb[i].getBombExplosion());
				bomb[i].resetBomb();
				star_ship.LosingLife();
				star_ship.setHealth();
				playerHUD.updateHealth(star_ship.getHealth());
				playerHUD.updateLives(star_ship.getLives());
				star_ship.reset();
			}
			hitbyBomb++;
		}
		window.draw(bomb[i].getBomb());
	}
	
	for(int i = 0; i < heart.size(); i++){
		heart[i].sendHeart();
		//Player can only retrieve heart for extra lives if they have less than 3 lives left
		if(star_ship.getLives() < 3){
			if(Collision::PixelPerfectTest(heart[i].getHeart(), star_ship.getSprite())){
				sfx.gainlife();
				star_ship.addLives();
				heart[i].resetHeart();
				heartsTaken++;
			}
		}
		window.draw(heart[i].getHeart());
	}

	//creating the bullets for the player
	std::vector<Bullet*>::iterator itr;
	for(itr = bVect.begin(); itr < bVect.end(); itr++){
		if((*itr)->GetActiveStatus()){
			(*itr)->bulletFired();
			window.draw((*itr)->getbulletPlayer());
			for(int i = 0; i < ass.size(); i++){
				//collision conditions for the bullets
				if(Collision::PixelPerfectTest((*itr)->getbulletPlayer(), ass[i].getSprite())){
					sfx.boom();
					star_ship.addPoints(10);
					playerHUD.updateScore(star_ship.getScore());
					window.draw(ass[i].getExplodedAsteroid()); //exploding asteroid
					ass[i].reset();
					(*itr)->Deactive();
					asteroidsHit++;
				}
			}
			for(int i = 0; i < bomb.size(); i++){
				//what happens when you shoot a falling bomb
				if(Collision::PixelPerfectTest((*itr)->getbulletPlayer(), bomb[i].getBomb())){
					sfx.bigboom();
					window.draw(bomb[i].getBombExplosion());
					for(int x = 0; x < ass.size(); x++){
						//The bomb's explosion can take out any asteroids within it's radius
						if(Collision::PixelPerfectTest(bomb[i].getBombExplosion(), ass[x].getSprite())){
							star_ship.addPoints(10);
							playerHUD.updateScore(star_ship.getScore());
							ass[x].reset();
							asteroidsHit++;
						}
						bomb[i].resetBomb();
					}
					(*itr)->Deactive();
					bombsHit++;
				}
			}
			//Takes 200 shots to kill the boss
			if(Collision::PixelPerfectTest((*itr)->getbulletPlayer(), boss.getShip())){
				(*itr)->Deactive();
				boss.TakingDamage(5);
				if(boss.getHealth() <= 0){
					//sfx.bossbattleEnd();
					sfx.winSound();
					window.close();
					std::cout<< "<-------------------------------->" << std::endl;
					std::cout<< "\tYou won the game" << std::endl;
					std::cout<< "\tEnding score: " << star_ship.getScore() << std::endl;
					std::cout<< "\tShots fired: " << shotsFired << std::endl;
					std::cout<< "\tAsteroids hit: " << asteroidsHit << std::endl;
					std::cout<< "\tBombs hit: " << bombsHit << std::endl;
					std::cout<< "\tBombs hti by: " << hitbyBomb << std::endl;
					std::cout<< "\tHearts taken: " << heartsTaken << std::endl;
					std::cout<< "\tTotal game time: " << gameClock.asSeconds() << " seconds" << std::endl;
					std::cout<< "<-------------------------------->" << std::endl;
				}
			}
		}
	}
	
	//how to spawn the boss 	
	//boss spawns once the user hits 2500 score
	//bossSpawn variable created because boss can take score below 2500
	int bossSpawn;	
	if(star_ship.getScore() >= 2500 || bossSpawn == 1){
		//sfx.bossbattlestart();

		//boss will shoot every second
		sf::Time FireCD = b_clock.getElapsedTime();
		
		//check timer 
		//std::cout << FireCD.asSeconds() << std::endl;
		
		if(FireCD.asSeconds() >= 1){	
			sfx.bossgun();
			bossPtr = new Bullet(boss.getShip().getPosition().x+200.25, boss.getShip().getPosition().y+60);
			bossV.push_back(bossPtr);
			bossPtr->setActive();
			b_clock.restart();
		}
		//creating bullets for the boss
		std::vector<Bullet*>::iterator itrBoss;
		for(itrBoss = bossV.begin(); itrBoss < bossV.end(); itrBoss++){
			if((*itrBoss)->GetActiveStatus()){
				//The boss takes away half of the players health if they are shot
				if(Collision::PixelPerfectTest((*itrBoss)->getbulletBoss(), star_ship.getSprite())){
					star_ship.addPoints(-50);
					star_ship.TakingDamage(50);
					playerHUD.updateScore(star_ship.getScore());
					playerHUD.updateHealth(star_ship.getHealth());
					(*itrBoss)->Deactive();
					if(star_ship.getHealth() <= 0){ //losing lives if statement
						star_ship.LosingLife();
						star_ship.setHealth();
						playerHUD.updateHealth(star_ship.getHealth());
						playerHUD.updateLives(star_ship.getLives());
						star_ship.reset();	
					}	
				}
				//The boss can destroy asteroids to take away points from the player
				for(int i = 0; i < ass.size(); i++){
					if(Collision::PixelPerfectTest((*itrBoss)->getbulletBoss(), ass[i].getSprite())){
						star_ship.addPoints(-10);
				        	playerHUD.updateScore(star_ship.getScore());
				 		ass[i].reset();
					}
				}		
				(*itrBoss)->bossbulletFired();	
				window.draw((*itrBoss)->getbulletBoss());
			}
		}
		boss.movement();				
		window.draw(boss.getShip());
		window.draw(boss.getBar());
		window.draw(boss.getHealthBar());
		bossSpawn = 1;
	}

	window.draw(star_ship.getHealthBar());
	window.draw(playerHUD.getDisplayedScore());
	window.draw(playerHUD.getScoreText());
	window.draw(playerHUD.getDisplayedHealth());
	window.draw(playerHUD.getHealthText());	
	window.draw(playerHUD.getDisplayedLives());
	window.draw(playerHUD.getLivesText());
	
	//if player loses the game
	if(star_ship.getLives() <= 0){
		window.close();
		std::cout<< "<-------------------------------->" << std::endl;
		std::cout<< "\tYou lost the game" << std::endl;
		std::cout<< "\tEnding score: " << star_ship.getScore() << std::endl;
		std::cout<< "\tShots fired: " << shotsFired << std::endl;
		std::cout<< "\tAsteroids hit: " << asteroidsHit << std::endl;
		std::cout<< "\tBombs hit: " << bombsHit << std::endl;
		std::cout<< "\tBombs hti by: " << hitbyBomb << std::endl;
		std::cout<< "\tHearts taken: " << heartsTaken << std::endl;
		std::cout<< "\tYou survived for: " << gameClock.asSeconds() << " seconds" << std::endl;
		std::cout<< "<-------------------------------->" << std::endl;
	}

        window.display();
    }
						break;
					case 1:
					std::cout<< "Game controls button pressed" <<std::endl;
					std::cout<< "W to move up, A to move left, S to move down, D to move right" <<std::endl; 
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
			break;

			case sf::Event::Closed:
				window.close();
				break;
	 		}
    		}
    		window.clear();
		window.draw(background.getSprite2());
    		window.draw(background.getSprite());
		window.draw(star_ship.getSprite());
    		menu.draw(window);
    		window.display();
    	}
}

