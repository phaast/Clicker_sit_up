#include "DeltaTime.h"

double DeltaTime::calculate_dt() {
	//taken from reddit
	// https://www.reddit.com/r/gamedev/comments/4c2ekd/what_is_the_best_way_to_work_out_delta_time/

	double fpDt;
	sf::Time dt = clock.restart(); // restarting clock 
	// returns elapsed time
	sf::Time accumulated_dt;
	accumulated_dt += dt; // sf::Time overloads arithmatic operators

	if (accumulated_dt >= timestep) {
		fpDt = accumulated_dt.asSeconds();
		accumulated_dt -= timestep;
	}
	else {
		fpDt = dt.asSeconds(); // if your state methods use floating point parameters.
	}

	return fpDt;
}
