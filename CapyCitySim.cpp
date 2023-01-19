#include <iostream>
#include <istream>
#include "CapyCitySim.h"


CapyCitySim::CapyCitySim(Building *_buildings)
{
    for (int i = 0; i < sizeof(_buildings); i++)
    {
        buildings[i] = _buildings[i];
    }
}

CapyCitySim::CapyCitySim()
{
}

CapyCitySim::~CapyCitySim()
{
}

// int CapyCitySim::get_anzahl_buildings(){
//     return anzahl_buildings;
// }

void CapyCitySim::add(Building _building)
{
    buildings[anzahl_buildings] = _building;
    anzahl_buildings++;
    totalprice+=_building.total_price_one_building();
}

void CapyCitySim::print()
{

   for (int i = 0; i < Building::anzahl_b; i++)
    {
        buildings[i].print_buildings();
        cout<< endl << endl; 
    }
     cout << "TotalPrice of all buildings:"<<totalprice<<endl;
}
 int CapyCitySim::get_total_price(){
    return totalprice;
 }

