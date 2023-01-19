// #ifndef _CAPYCITYSIM_H_
// #define _CAPYCITYSIM_H_
// #include "Building.h"

// class CapyCitySim
// {
// private:
//     Building *buildings[100];
//     double totalprice = 0;

// public:
//     int anzahl_buildings = 0;
//     static double total;
//     CapyCitySim(Building buildings);
//     CapyCitySim();
//     ~CapyCitySim();

//     void add(Building *_building);
//     void print();
//     int get_total_price();
//     Building *get_building(int index);
//     void place_building(ConstructionArea Area);
//     double total_price_all();
// };
// #endif

#ifndef _CAPYCITYSIM_H_
#define _CAPYCITYSIM_H_
// #include "ConstructionArea.h"
#include "Blueprint.h"
// #include "Blueprint.h"

class CapyCitySim
{
private:
    
    Blueprint *blueprints[100];

public:

    int anzahl_bulueprints = 0;
   
    CapyCitySim();
    ~CapyCitySim();

    void add(Blueprint *_blueprints);
    void print();
   
};
#endif