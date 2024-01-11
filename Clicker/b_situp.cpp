#include "b_situp.h"
#include "DeltaTime.h"
#include <iostream>

b_situp::b_situp(float x1, float y1, float x2, float y2) : button(x1, y1, x2, y2) {
}

void b_situp::stamina_regen(std::vector<double>& l_stat) {
	Dt_st = dt_st.calculate_dt();
	if (Dt_st < 2) {
		l_stat[4] += l_stat[5] * Dt_st;
	}
	if (l_stat[4] > l_stat[3]) {
		l_stat[4] = l_stat[3];
	}
	//std::cout << l_stat[5] << " " << Dt_st << " " << l_stat[5] * Dt_st << std::endl;
}

void b_situp::perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
	std::vector<int>& l_upg, std::vector<double>& l_price) {

		if (b_situp::_click(window, get_x1(), get_y1(), get_x2(), get_y2()) == true) {

			//clock reset with each click
			//after cooldown time passes, start the regen

			timer.restart();

			if (l_stat[4] >= 1) {//stamina
				l_stat[0] += l_stat[2];
				l_stat[4] -= 1;

				std::cout << "Sit-ups increased to: " << l_stat[0] << std::endl;
				std::cout << "Stamina: " << l_stat[4] << std::endl;
			}
		}

		if (timer.getElapsedTime() >= wait_time && l_stat[4]<l_stat[3]) {
			b_situp::stamina_regen(l_stat);
		}
}
