#pragma once
#include <SFML/Graphics.hpp>
class DeltaTime
{
private:
	sf::Time const timestep = sf::milliseconds(50);
	sf::Clock clock;
public:
	double calculate_dt();
};

