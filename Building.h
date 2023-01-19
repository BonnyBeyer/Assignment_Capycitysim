#ifndef _BUILDING_H_
#define _BUILDING_H_
#include "ConstructionArea.h"
#include "Material.h"

#include <string>

class Building
{
protected:
    string label;
    double price;
    int length;
    int width;
    int *position;
    Material materials[100];
    int anzahl_of_material = 0;

public:
    static int anzahl_b;
    Building(int l, int w, int *p, ConstructionArea Area, Material *_materials);
    Building();
    ~Building();

    void set_label(string _label);
    void set_price(double _price);
    void set_length(int _length);
    void set_width(int _width);
    void set_row(int _row);
    void set_column(int _column);
    void set_material_value(int i, Material material);

    std::string get_label();
    double get_price();
    int get_length();
    int get_width();
    int get_row();
    int get_column();
    Material get_material_value(int i);

    bool built_posibillity(ConstructionArea Area, int *p, int w, int l);
    std::string tostring();
    std::string string_materials();
    void print_buildings();
    void add_material(Material material);
    double total_price_one_building();
};
#endif
