#include "button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//somewhat a higher-abstraction level class, checks if the "click" is in button boundries

button::button(float x1, float y1, float x2, float y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

float button::get_x1() {return x1;}
float button::get_x2() {return x2;}
float button::get_y1() {return y1;}
float button::get_y2() {return y2;}

bool button::_click(sf::RenderWindow* window, float x1, float y1, float x2, float y2) {

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && allowpress == 0 && allowrelease == 0) {
		allowpress = 1;
		return false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && allowpress == 1) {
		mousePos = sf::Mouse::getPosition(*window);
		xcast1 = (float)mousePos.x;
		ycast1 = (float)mousePos.y;
		allowrelease = 1;
		return false;
	}
		//boundry check
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && allowpress == 1 && allowrelease == 1) {
		mousePos = sf::Mouse::getPosition(*window);
		xcast2 = (float)mousePos.x;
		ycast2 = (float)mousePos.y;
		if (xcast1 >= x1 && xcast2 >= x1 &&
			xcast1 <= x2 && xcast2 <= x2 &&
			ycast1 >= y1 && ycast2 >= y1 && 
			ycast1 <= y2 && ycast2 <= y2) {
			allowpress = 0;
			allowrelease = 0;
			return true;
		}
		else {
			allowpress = 0;
			allowrelease = 0;
			return false;
		}
	}
	return false;
}