//UNUSED----------------------------------------
#include "upg_pc.h"
#include <vector>
#include "SFML/Graphics.hpp"

upg_pc::upg_pc(float x1, float y1, float x2, float y2): button(x1, y1, x2, y2) {
}

double upg_pc::get_mtp() { return mtp; }

void upg_pc::perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
	std::vector<int>& l_upg, std::vector<double>& l_price) {

	if (upg_pc::_click(window, get_x1(), get_y1(), get_x2(), get_y2()) == true && l_stat[0] >= l_price[0]) {
		l_stat[0] -= l_price[0];
		l_stat[2] += 1;
		l_upg[2] += 1;
		printf("increased sit-ups per click for %2f sit-ups. Upgrades owned: %d\n", l_price[0], l_upg[2]);
		l_price[0] = cost_og + std::pow(mtp, l_upg[2]);
		
	}
}