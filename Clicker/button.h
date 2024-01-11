#pragma once
#include <SFML/Graphics.hpp>

class button
{
private:
	float xcast1, ycast1, ycast2, xcast2;
	sf::Vector2i mousePos;
	int allowpress = 0, allowrelease = 0;
	float x1, y1, x2, y2;

public:

	button(float x1, float y1, float x2, float y2);
	virtual float get_x1(), get_x2(), get_y1(), get_y2();

	bool _click(sf::RenderWindow* window, float x1, float y1, float x2, float y2);

	//ABSTRAKCJA!?!?!?!?!??!
	virtual void perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
		std::vector<int>& l_upg, std::vector<double>& l_price) = 0;
};

