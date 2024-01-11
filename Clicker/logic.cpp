#include "logic.h"

#include <iostream>

logic::logic() {
	//loading the savefile and recaltulating the variables
	if (load("savefile.txt") == true) {
		l_stat = svf_stat;
		l_upg = svf_upg;
		gametime = svf_time;
		logic::run_prices_recalculation();
	}

	//calculating how many points have been gathered when offline
	logic::add_offline_situps();
}

void logic::add_offline_situps() {
	time_passed = (int)time(0) - gametime;
	int su_acc = (int)l_stat[1] * time_passed;
	l_stat[0] += su_acc;
	std::cout << "when away for " << time_passed << " seconds, you have accumulated " 
		<< su_acc << " situps." << std::endl;
}

void logic::run_prices_recalculation() {
	l_price[0] += std::pow(upg0.get_mtp(), l_upg[0]);
	l_price[1] += std::pow(upg1.get_mtp(), l_upg[1]);
	l_price[2] += std::pow(upg2.get_mtp(), l_upg[2]);
	l_price[3] += std::pow(upg3.get_mtp(), l_upg[3]);
	l_price[4] += std::pow(upg4.get_mtp(), l_upg[4]);
}

//LOGIC IN-LOOP------------------------------------------------
void logic::_logic(sf::RenderWindow* window) {
	//add points per second in real time 
	logic::append_ps();

	//make all the buttons work (everything is a button)
	//character
	sit_up.perform(window, l_stat, l_upg, l_price);
	//upgrades
	upg0.perform(window, l_stat, l_upg, l_price);
	upg1.perform(window, l_stat, l_upg, l_price);
	upg2.perform(window, l_stat, l_upg, l_price);
	upg3.perform(window, l_stat, l_upg, l_price);
	upg4.perform(window, l_stat, l_upg, l_price);
}
//-------------------------------------------------------------

void logic::save() {
	//it's just looking better in the main file
	write("savefile.txt", l_stat, l_upg);
}

void logic::append_ps() {
	Dt_cps = dt_cps.calculate_dt();
	l_stat[0] += l_stat[1] * Dt_cps;
}