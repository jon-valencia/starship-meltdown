#pragma once
#include "SFML/Audio.hpp"

class Music{
public:
	//constructor
        Music();

        //destructor
        ~Music();

	void play();
	void setLoop();
	
private:
	sf::Music music;
};
