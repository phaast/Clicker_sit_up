#pragma once
#include <vector>
#include "DeltaTime.h"
#include "savefile.h"
#include "upgrade.h"
#include "b_situp.h"

class logic: public savefile
{
public:
	std::vector<double> l_stat = { 0, 0, 1, 20, 20, 3 };
	std::vector<int> l_upg = { 0, 0, 0, 0, 0 };
	std::vector<double> l_price = { 10, 200, 500, 1000, 5000 };

private:
	int gametime = 0;
	int time_passed;
	double Dt_cps;
	DeltaTime dt_cps;

	//sure there's a better idea
	b_situp sit_up{ 140, 160, 344, 544 };
	upgrade upg0{ 926, 76, 994, 156,
		0, 2, 1.01, 10, 1 };
	upgrade upg1{ 926, 76, 994, 156,
		1, 3, 1.15, 200, 1 };
	upgrade upg2{ 926, 76, 994, 156,
		2, 5, 1.3, 1000, 0.5 };
	upgrade upg3{ 926, 76, 994, 156,
		3, 1, 1.3, 2000, 5 };
	upgrade upg4{ 926, 76, 994, 156,
		4, 1, 1.3, 5000, 20 };

public:
	logic();
	void _logic(sf::RenderWindow* window);
	void save();

private:
	void run_prices_recalculation();
	void add_offline_situps();
	void append_ps();


};

