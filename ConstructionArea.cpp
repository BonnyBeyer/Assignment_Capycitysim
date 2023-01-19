#include <iostream>
#include <istream>
#include "ConstructionArea.h"

ConstructionArea::~ConstructionArea()
{
}

ConstructionArea::ConstructionArea(){

}


ConstructionArea::ConstructionArea(int length, int width)
{
   
    set_length(length);
    set_width(width);

    construction_area = new int *[length];

   

    for (int k = 0; k < length; ++k)
    {
        construction_area[k] = new int[width];
    }

   
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            construction_area[i][j] = 0;
            
        }
       
    }

    
}


// setter
void ConstructionArea::set_length(int _length)
{
    length = _length;
}

void ConstructionArea::set_width(int _width)
{
    width = _width;
}

void ConstructionArea::set_construction_area(int length, int width)
{
    

    construction_area = new int *[length];

    

    for (int k = 0; k < length; ++k)
    {
        construction_area[k] = new int[width];
    }

    
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            construction_area[i][j] = 0;
            
        }
       
    }

   
}


int ConstructionArea::get_length()
{
    return length;
}
int ConstructionArea::get_width()
{
    return width;
}



void ConstructionArea::print()
{
    

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
            cout << construction_area[i][j];
        }
        cout << endl;
    }
}


bool ConstructionArea::removable(int l, int w)
{
    

    bool x = true;
    for (int i = l; i < length; i++)
    {
        
        for (int j = w; j < width; j++)
        {
            
            if (construction_area[i][j] == 0)
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
string ConstructionArea::create_id()
{
    string id = " ";

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            id += to_string(construction_area[i][j]);
        }
    }
    return id;
}