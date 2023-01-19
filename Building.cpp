#include <stdio.h>
#include <iostream>
// #include "CapyCitySim.cpp"
//  #include "ConstructionArea.h"
//  #include "Material.h"
#include "Building.h"

int Building::anzahl_b = 0;

Building::Building(int l, int w, int *p, ConstructionArea Area, Material *_materials)
{ // cout << "in constructor!!!"<<endl;
    bool possibility = built_posibillity(Area, p, w, l);

    // cout << "Possibility: " << possibility << endl;
    if (possibility == true)
    {
        anzahl_b++;
        length = l;
        width = w;
        position = p;
        // cout << "before loop";
        for (int i = p[0]; i < length + p[0]; i++)
        {
            for (int j = p[1]; j < width + p[1]; j++)
            {
                Area.construction_area[i][j] = anzahl_b;
                // cout << Area.construction_area[i][j];
            }
            // cout << endl;
        }

        for (int i = 0; i < sizeof(_materials); i++)
        {
            materials[i] = _materials[i];
        }
        anzahl_of_material = sizeof(_materials);
        // cout << Area.construction_area<<endl;
    }
    else
    {
        throw std::invalid_argument("building is not possible");
    }
}

Building::Building()
{
}

Building::~Building()
{
}

bool Building::built_posibillity(ConstructionArea Area, int *p, int w, int l)
{
    // cout << "posibility" << endl;

    bool x = true;
    for (int i = p[0]; i < p[0] + l; i++)
    {
        // cout << "value of i " << i << endl;
        for (int j = p[1]; j < p[1] + w; j++)
        {
            // cout << "value of j " << j << endl;
            // cout << Area.construction_area[i][j] << endl;
            // if (Area.get_construction_area_value(i,j) == 0)
            //     x = true;
            // else
            // {
            //     x = false;
            //     return x;
            // }
            if (Area.construction_area[i][j] == 0)
                x = true;
            else
            {
                x = false;
                return x;
            }
        }
    }

    return x;
}

string Building::tostring()
{
    int x = position[1];
    return "Label: " + label +
           "Price: " + to_string(price) +
           " Length: " + to_string(length) +
           " Width: " + to_string(width) +
           " Position: " + to_string(position[0]) +
           " and " + to_string(x) +
           "Materials: " + string_materials();
}

string Building::string_materials()
{
    string s = " ";
    string name = " ";
    for (int i = 0; i < anzahl_of_material; i++)
    {

        name = materials[i].get_material_name();
        s += " " + name;
    }
    return s;
}

double Building::total_price_one_building()
{

    double prc;
    for (int i = 0; i < anzahl_of_material; i++)
    {

        prc += materials[i].get_material_price();
    }
    prc += price;
    return prc;
}

void Building::print_buildings()
{
    cout << "Label: " << label << endl
         << "Basic Price: " << price << endl
         << "Total Price: " << total_price_one_building() << endl
         << "Length: " << length << endl
         << "Width: " << width << endl
         << "Position: " << position[0]
         << " and " << position[1] << endl
         << "Materials: " + string_materials() << endl;
}

// setter
void Building::set_label(string _label)
{
    label = _label;
}
void Building::set_price(double _price)
{
    price = _price;
}
void Building::set_length(int _length)
{
    length = _length;
}
void Building::set_width(int _width)
{
    width = _width;
}
void Building::set_row(int _row)
{
    position[0] = _row;
}
void Building::set_column(int _column)
{

    position[1] = _column;
}
void Building::set_material_value(int i, Material material)
{
    materials[i] = material;
}

// getter
int Building::get_length()
{
    return length;
}
int Building::get_width()
{
    return width;
}
int Building::get_row()
{
    // cout << "position" << endl;
    int row = position[0];

    // cout << "row" << endl;
    return row;
}
int Building::get_column()
{
    // cout << "position" << endl;
    int column = position[1];

    // cout << "column" << endl;
    return column;
}

string Building::get_label()
{
    return label;
}
double Building::get_price()
{
    return price;
}
Material Building::get_material_value(int i)
{

    Material m = materials[i];
    return m;
}

void Building::add_material(Material material)
{
    materials[anzahl_of_material] = material;
    anzahl_of_material++;
}