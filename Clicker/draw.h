#pragma once
#include "draw_b_situp.h"
#include "SFML/Graphics.hpp"
#include <string>

class draw
{
private:
	//textures
	sf::Texture b_situp_tx, background_tx;
	sf::RectangleShape b_situp_rect{ sf::Vector2f(204.0f, 384.0f) };
	draw_b_situp b_situp{ &b_situp_tx, sf::Vector2u(2, 1) };
	sf::RectangleShape background_rect{ sf::Vector2f(1024.0f, 640.0f) };

	//fonts, texts
	sf::Font font;
	sf::Text text_situps, text_stamina, text_upg0_x, text_upg0_p, 
		text_upg1_x, text_upg1_p, text_upg2_x, text_upg2_p, 
		text_upg3_x, text_upg3_p, text_upg4_x, text_upg4_p;
	std::string conv, conv2;
public:
	draw();

	void Draw(sf::RenderWindow& window, std::vector<double>& l_stat,
		std::vector<int>& l_upg, std::vector<double>& l_price);
};

