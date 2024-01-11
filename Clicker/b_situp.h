#pragma once
#include "button.h"
#include "DeltaTime.h"

class b_situp :
    public button
{
private:
    DeltaTime dt_st;
    double Dt_st;

    sf::Clock timer;
    sf::Time wait_time = sf::seconds(2);
public:
    b_situp(float x1, float y1, float x2, float y2);

    void perform(sf::RenderWindow* window, std::vector<double>& l_stat,
        std::vector<int>& l_upg, std::vector<double>& l_price) override;

private:
    void stamina_regen(std::vector<double>& l_stat);
};

