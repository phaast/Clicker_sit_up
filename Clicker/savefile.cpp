#include "savefile.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


//-file processing-//

// returns integer from the specific line in the save file
// probably useless
// (inspo from https://www.javatpoint.com/how-to-split-strings-in-cpp)
int savefile::get_int(std::string line) {
	std::string T;
	std::stringstream X(line);
	std::getline(X, T, '=');
	T.clear();
	std::getline(X, T);

	return std::stoi(T);
}

// same for the double
double savefile::get_double(std::string line) {
	std::string T;
	std::stringstream X(line);
	std::getline(X, T, '=');
	T.clear();
	std::getline(X, T);

	return std::stod(T);
}


// reading main game parameters before launch
//sprobowac napisac z insertem, moze nie bedzie
//potrzeba wywolywania wektora jako funkcje
bool savefile::load(std::string fname) {
	std::ifstream savefile(fname);
	if (savefile) {
		std::cout << "save file opened successfully." << std::endl;

		std::string cur_line;
		std::getline(savefile, cur_line);
		svf_time = savefile::get_int(cur_line);
		for (int i = 0; i < 6; i++) {
			std::getline(savefile, cur_line);
			svf_stat.insert(svf_stat.end(), savefile::get_double(cur_line));
			}
		for (int i = 0; i < 5; i++) {
			std::getline(savefile, cur_line);
			svf_upg.insert(svf_upg.end(), savefile::get_int(cur_line));
		}

		savefile.close();
		std::cout << "save file loaded." << std::endl;

		return true;
	}
	else { //if there is no file
		std::cout << "there was an error with reading the file."
			<< std::endl;

		return false;
	}
}


// is going to happen before closing the game window
void savefile::write(std::string fname, 
					 std::vector<double>& svf_stat, 
					 std::vector<int>& svf_upg) {

	std::ofstream savefile(fname);
	//chyba zamienimy czas na hex
	savefile << "gametime=" << time(0) << std::endl;
	savefile << "situps=" << svf_stat[0] << std::endl;
	savefile << "situps_ps=" << svf_stat[1] << std::endl;
	savefile << "situps_pc=" << svf_stat[2] << std::endl;
	savefile << "max_stamina=" << svf_stat[3] << std::endl;
	savefile << "curr_stamina=" << svf_stat[4] << std::endl;
	savefile << "stamina_ps=" << svf_stat[5] << std::endl;
	savefile << "item1=" << svf_upg[0] << std::endl; //increase situps_pc
	savefile << "item2=" << svf_upg[1] << std::endl; //increase stamina regen
	savefile << "item3=" << svf_upg[2] << std::endl; //increase stamina capacity
	savefile << "item4=" << svf_upg[3] << std::endl; //increase situps_ps
	savefile << "item5=" << svf_upg[4] << std::endl; //increase situps_ps+
	savefile.close();

	std::cout << "save file written" << std::endl;
}