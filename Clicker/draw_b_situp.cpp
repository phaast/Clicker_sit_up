#include "draw_b_situp.h"
#include "SFML/Graphics.hpp"

draw_b_situp::draw_b_situp(sf::Texture* texture, sf::Vector2u imageCount) {
	this->imageCount = imageCount;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / imageCount.x;
	uvRect.height = texture->getSize().y / imageCount.y;
}

void draw_b_situp::perform(sf::RenderWindow* window, int row, std::vector<double>& l_stat) {
	currentImage.y = row;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && l_stat[4] >= 1) {
		mousePos = sf::Mouse::getPosition(*window);
		xcast = (float)mousePos.x;
		ycast = (float)mousePos.y;
		if (xcast >= x1 && xcast <= x2 &&
			ycast >= y1 && ycast <= y2) {
			currentImage.x = 1;
		}
		else {
			currentImage.x = 0;
		}
	}
	else {
		currentImage.x = 0;
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}