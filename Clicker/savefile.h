#pragma once
#include <string>
#include <vector>

class savefile
{
private:
	std::string line, fname;

public:
	std::vector<double> svf_stat;
	std::vector<int> svf_upg;
	int svf_time;

private:
	int get_int(std::string line);
	double get_double(std::string line);

public:
	bool load(std::string fname);
	void write(std::string fname,
			   std::vector<double>& svf_stat,
			   std::vector<int>& svf_upg);
};