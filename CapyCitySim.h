#ifndef _CAPYCITYSIM_H_
#define _CAPYCITYSIM_H_
#include "Building.h"

class CapyCitySim
{
private:
    Building buildings[100];
    double totalprice=0;

public:
    int anzahl_buildings = 0;
    CapyCitySim(Building *buildings);
    CapyCitySim();
    ~CapyCitySim();

    void add(Building _building);
    void print();
    int get_total_price();
};
#endif
