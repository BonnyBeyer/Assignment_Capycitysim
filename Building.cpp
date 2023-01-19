#include <stdio.h>
#include <iostream>
#include "map"
// #include "CapyCitySim.cpp"
//  #include "ConstructionArea.h"
//  #include "Material.h"
#include "Building.h"

int Building::anzahl_b = 0;
double Building::total = 0;

Building::Building(int l, int w, int *p, ConstructionArea* Area)
{ 
   

    Holz *holz = new Holz();

    

    Metall *metall = new Metall();

    

    Kunststoff *kunststoff = new Kunststoff();

    leistung=l*w*200000;


}

Building::Building()
{
}

Building::~Building()
{
}

bool Building::built_posibillity(ConstructionArea* Area, int *p, int w, int l)
{
    

    bool x = true;
    for (int i = p[0]; i < p[0] + l; i++)
    {
        
        for (int j = p[1]; j < p[1] + w; j++)
        {
            
            if (Area->construction_area[i][j] == 0)
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
     string s = "\n";

    return s;
}

double Building::total_price_one_building()
{

    double prc;
    double price_m;
    
    map<Material *, int>::iterator itr;

    Material *material;
    int count = 0;
    for (itr = materials.begin(); itr != materials.end(); ++itr)
    {
        material = itr->first;
        count = itr->second;
        //cout << "material in loop: " <<material <<endl;
        price_m += material->get_material_price() * count;
    }

    prc = price_m + price;
    return prc;
}

void Building::print_buildings()
{
    // double prc=0;
    // prc+=this->total_price_one_building();
    double ttt = this->total_price_one_building();
    // std::cout << "In print_building() " << endl;
    std::cout << "Label: " << this->get_label() << endl
              << "Basic Price: " << this->get_price() << endl
            //   << "Total Price: " << prc<< endl
            //   << "Total Price: " <<this->total_price_one_building() << endl
              << "Length: " << this->get_length() << endl
              << "Width: " << this->get_width() << endl
              << "Position: " << this->get_row()
              << " and " << this->get_column() << endl;
    //   << "Materials: " + this->string_materials() << endl

    map<Material *, int>::iterator itr;
    Material *material;
    int count = 0;
    for (itr = materials.begin(); itr != materials.end(); ++itr)
    {
        material = itr->first;
        count = itr->second;
        cout << material->get_material_name() << ": " << count << endl;
    }
    cout << "Total Price Building: " <<this->total_price_one_building() << endl;
    for (itr = materials.begin(); itr != materials.end(); ++itr)
    {
        material = itr->first;
        count = itr->second;
        // cout << material->get_material_name() << ": " << count << endl;
    }
    total += this->total_price_one_building();
    std::cout << "Total so far: " << total << endl;
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

    
    int row = position[0];

    return row;
}
int Building::get_column()
{
   
    int column = position[1];

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


void Building::insert_material(string key)
{

    if (key == "Metall")
    {
        materials[&metall]++;
    }
    if (key == "Kunststoff")
    {
        materials[&kunststoff]++;
    }
    if (key == "Holz")
    {
        materials[&holz]++;
    }
}

void Building::set_leistung(int _leistung)
{
    leistung = _leistung;
}

int Building::get_leistung()
{
    return leistung;
}

double Building::get_totalprice()
{

    map<Material *, int>::iterator itr;
    Material *material;
    int count = 0;

    for (itr = materials.begin(); itr != materials.end(); ++itr)
    {
        material = itr->first;
        count = itr->second;
    }

    totalprice=this->total_price_one_building();
    return totalprice;
}

