#include <iostream>
#include <istream>
#include "Blueprint.h"
// #include "ConstructionArea.h"


Blueprint::Blueprint(int length, int width)
{
    set_length(length);
    set_width(width);
   
    ConstructionArea *AreaBlueprint1 = new ConstructionArea(length, width);

    AreaBlueprint = AreaBlueprint1;

    
}

Blueprint::Blueprint(/* args */)
{
}

Blueprint::~Blueprint()
{
}

void Blueprint::add(Building *_building)
{

    buildings[anzahl_buildings] = _building;
    anzahl_buildings++;
}

void Blueprint::print()
{
    cout<<"______________________Plan_____________________________"<<endl;
    double total;
    double prc;
    AreaBlueprint->print();

    for (int i = 0; i < anzahl_buildings; i++)
    {

        buildings[i]->print_buildings();

        std::cout << endl
                  << endl;
    }

   

    Building::total = 0;
}


Building *Blueprint::get_building(int index)
{

    return buildings[index];
}

int Blueprint::get_total_leistung()
{
    int leistung = 0;

    for (int i = 0; i < anzahl_buildings; i++)
    {

        leistung += buildings[i]->get_leistung();
    }
    leistungplan = leistung;
   
    return leistungplan;
}

int Blueprint::calculate_kennzahl()
{
    get_total_leistung();
    get_total_price();
    double K = 0;
   
    K = leistungplan / (totalpriceplan * length * width);
    kennzahl = K;
    return kennzahl;
}

void Blueprint::set_length(int _length)
{
    length = _length;
}

void Blueprint::set_width(int _width)
{
    width = _width;
}

int Blueprint::get_total_price()
{
   
    double price = 0;

    for (int i = 0; i < anzahl_buildings; i++)
    {

        price += buildings[i]->get_totalprice();
    }
    totalpriceplan = price;
    return totalpriceplan;
}

ConstructionArea *Blueprint::get_AreaBlueprint()
{

    
    return AreaBlueprint;
}

int Blueprint::get_kennzahl(){
    
    return kennzahl;
}


