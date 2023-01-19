#include <iostream>
#include <istream>
#include "CapyCitySim.h"
#include "ConstructionArea.h"



CapyCitySim::CapyCitySim()
{
}

CapyCitySim::~CapyCitySim()
{
}


void CapyCitySim::add(Building *_building)
{
    
    buildings[anzahl_buildings] = _building;
    anzahl_buildings++;
  
}


void CapyCitySim::print()
{
    double total;
    double prc;

    for (int i = 0; i < Building::anzahl_b; i++)
    {
        
        buildings[i]->print_buildings();
      
        std::cout << endl
                  << endl;
       
    }

    Building::total=0;
    
}


int CapyCitySim::get_total_price()
{
    return totalprice;
}
Building *CapyCitySim::get_building(int index)
{
   
    return buildings[index];
}

