#ifndef _BLUEPRINT_H_
#define _BLUEPRINT_H_
#include "Building.h"
using namespace std;

class Blueprint
{
private:
    Building *buildings[100];
    double totalprice = 0;

    double totalpriceplan = 1;
    int leistungplan = 1;
    int kennzahl;

    int length = 1;
    int width = 1;

    ConstructionArea* AreaBlueprint;

public:
    // int **construction_area;

    Blueprint(/* args */);
    Blueprint(int length, int width);
    ~Blueprint();

    int anzahl_buildings = 0;
    static double total;

    void add(Building *_building);
    void print();
    // int get_total_price();
    Building *get_building(int index);
    // void place_building(ConstructionArea Area);
    // double total_price_all();

    int get_total_price();
    int get_total_leistung();
    int calculate_kennzahl();
    // string create_id();

    void set_length(int _length);
    void set_width(int _width);

    ConstructionArea* get_AreaBlueprint();

    int get_kennzahl();


   
   
};
#endif
