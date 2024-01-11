#pragma once
#include "button.h"
class upgrade :
    public button
{
private:
    //BUTTON SIZE: 68x62 
    //EVERY NEXT BUTTON'S Y AXIS CO-ORDRDS SHOULD BE INCREMENTED BY 108px
    //1ST UPGRADE LOCATION : x1 = 926, y1 = 76, x2 = 994, y2 = 156

    double cost_og, inc; // ORIGINAL PRICE OF AN UPGRADE; STAT INCREMENT VALUE 
    int upg_num, stat_num; // STORE THE PLACEMENT IN VECTOR LISTS
    double mtp; // MULTIPLIER PER UPGRADE PURCHASE

public:

    upgrade(float x1, float y1, float x2, float y2, 
        int num1, int num2, double mtp, double cost_og, double inc);

    //GETTERS WHICH ARE USEFUL
    float get_y1() override, get_y2() override;
    double get_mtp();

    //MAIN FUNCTION
    void perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
        std::vector<int>& l_upg, std::vector<double>& l_price) override;
};

