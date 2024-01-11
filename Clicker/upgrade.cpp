#include "upgrade.h"

upgrade::upgrade(float x1, float y1, float x2, float y2, 
		int num1, int num2, double mtp, double cost_og, double inc): button(x1, y1, x2, y2) {
	//APPLYING INSTANCE
	this->upg_num = num1;
	this->stat_num = num2;
	this->mtp = mtp;
	this->cost_og = cost_og;
	this->inc = inc;
}

//GETTERS
float upgrade::get_y1() { float y1 = button::get_y1() + upg_num * 108; return y1; }
float upgrade::get_y2() { float y2 = button::get_y2() + upg_num * 108; return y2; }
double upgrade::get_mtp() { return mtp; }

//MAIN FUNCTION
void upgrade::perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
	std::vector<int>& l_upg, std::vector<double>& l_price) {

	if (upgrade::_click(window, get_x1(), get_y1(), get_x2(), get_y2()) == true && 
		l_stat[0] >= l_price[upg_num]) {

		l_stat[0] -= l_price[upg_num];
		l_stat[stat_num] += inc;
		l_upg[upg_num] += 1;

		printf("bought upgrade no. %d for %2f sit-ups. Upgrades owned: %d\n", 
			upg_num, l_price[upg_num], l_upg[upg_num]);

		l_price[upg_num] = cost_og + std::pow(mtp, l_upg[upg_num]);
	}
}