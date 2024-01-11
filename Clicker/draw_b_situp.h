#pragma once
#include "SFML/Graphics.hpp"

class draw_b_situp 
{
private:
    sf::Vector2u currentImage;
    sf::Vector2u imageCount;

    float x1 = 140, x2 = 344, y1 = 160, y2 = 544;
    float xcast, ycast;
    sf::Vector2i mousePos;
public:
    sf::IntRect uvRect;
public:
    draw_b_situp(sf::Texture* texture, sf::Vector2u imageCount);

    void perform(sf::RenderWindow* window, int row, std::vector<double>& l_stat);
};

