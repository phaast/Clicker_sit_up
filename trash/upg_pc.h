//UNUSED----------------------------------------
#pragma once
#include "button.h"
class upg_pc :
    public button
{
private:
    double cost_og = 10, mtp = 1.1;
public:
    //34x31 *2 +23 in y axis every button
    //float x1 = 926, y1 = 76, x2 = 994, y2 = 156;
    upg_pc(float x1, float y1, float x2, float y2);

    double get_mtp();

    void perform(sf::RenderWindow* window, std::vector<double>& l_stat, 
        std::vector<int>& l_upg, std::vector<double>& l_price) override;
};

