#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include <vector>

class Bullet{

	private:
		int damage;

		float posX, posY;
		bool isActive;

		sf::Texture bulletTexture;
		sf::Sprite bulletPlayer, bulletBoss;
	public:

		Bullet(float x, float y);
		void setPos(float x, float y);
		void setPosBoss(float x, float y);
		float getPos();
		sf::Sprite getbulletPlayer(), getbulletBoss();
		void setActive();
		void Deactive();
		void bulletFired();
		void bossbulletFired();
		bool GetActiveStatus();
		

};
