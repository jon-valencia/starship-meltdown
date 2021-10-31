#pragma once
#include "SFML/Graphics.hpp"
#include "def.hpp"


class Menu{
public:
	//constructor
	Menu(float width, float height);
	
	//destructor
	~Menu();
	
	//make window
	void draw(sf::RenderWindow &window);
	
	//movement buttons
	void MoveUp();
	void MoveDown();
	int GetPressedItem(){
		return selectedItemIndex;
	}

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];	
};
