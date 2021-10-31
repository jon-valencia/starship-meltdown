#include <iostream>
#include "../include/music.hpp"

using namespace std;

Music::Music(){
	if(!music.openFromFile("../sounds/OrbitBeat130.wav")){
		cout << "Error" << endl;
	}
	music.play();
	music.setLoop(true);
}

Music::~Music(){
}
