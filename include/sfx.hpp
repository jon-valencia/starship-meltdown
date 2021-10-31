#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"

class SFX{
	private:
		sf::SoundBuffer gunshot;
		sf::SoundBuffer bossgunshot;
		sf::SoundBuffer explosion;
		sf::SoundBuffer bombexplosion;
		sf::SoundBuffer heartTaken;
		sf::SoundBuffer victorySound;

		sf::Sound blaster;
		sf::Sound bossblaster;
		sf::Sound asteroidboom;
		sf::Sound bombboom;
		sf::Sound newLife;
		sf::Sound victory;
		
		sf::Music gameSong;
		sf::Music bossBattle;

	public: 
		SFX();
		void playergun();
		void bossgun();
		void boom();
		void bigboom();
		void gainlife();
		void bossbattleStart();
		void bossbattleEnd();
		void gameStart();
		void winSound();
};
