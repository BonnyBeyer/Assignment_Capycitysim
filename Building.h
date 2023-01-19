#ifndef _BUILDING_H_
#define _BUILDING_H_
#include "map"
#include "ConstructionArea.h"
#include "Holz.h"
#include "Metall.h"
#include "Kunststoff.h"
// #include "Blueprint.h"

#include <string>

class Building
{
protected:
    string label;
    double price;
    int length;
    int width;
    int *position;
    map<Material*, int> materials;
    Holz holz;
    Metall metall;
    Kunststoff kunststoff;

    int leistung;
    double totalprice=0;
    

    // int anzahl_of_material = 0;

public:
     
    static int anzahl_b;
    static double total;
    Building(int l, int w, int *p, ConstructionArea* Area);
    Building();
    ~Building();

    void set_label(string _label);
    void set_price(double _price);
    void set_length(int _length);
    void set_width(int _width);
    void set_row(int _row);
    void set_column(int _column);
    // void set_material_value(int i, Material material);

    void set_leistung(int _leistung);

    std::string get_label();
    double get_price();
    int get_length();
    int get_width();
    int get_row();
    int get_column();

    int get_leistung();
   

    bool built_posibillity(ConstructionArea* Area, int *p, int w, int l);
    std::string tostring();
    std::string string_materials();
    void print_buildings();
    void insert_material(string key);
    double total_price_one_building();

    double get_totalprice();
 
};
#endif


