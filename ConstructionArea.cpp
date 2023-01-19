#include <iostream>
#include <istream>
#include "ConstructionArea.h"

ConstructionArea::~ConstructionArea()
{
}

// ConstructionArea::ConstructionArea()
// {
// }

ConstructionArea::ConstructionArea(int length, int width)
{
    // int construction_area[length][width];
    set_length(length);
    set_width(width);

    construction_area = new int *[length];

    // cout << "before loop" << endl;
    // cout << construction_area << endl;

    for (int k = 0; k < length; ++k)
    {
        construction_area[k] = new int[width];
    }

    /*LET'S INITIALIZE CELL VALUES TO= 0*/
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            construction_area[i][j] = 0;
            // cout << construction_area[i][j];
        }
        // cout << endl;
    }

    // cout << "after loop" << endl;
    // cout << construction_area << endl;
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
    // int construction_area[length][width];

    construction_area = new int *[length];

    // cout << "before loop" << endl;
    // cout << construction_area << endl;

    for (int k = 0; k < length; ++k)
    {
        construction_area[k] = new int[width];
    }

    /*LET'S INITIALIZE CELL VALUES TO= 0*/
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            construction_area[i][j] = 0;
            // cout << construction_area[i][j];
        }
        // cout << endl;
    }

    // cout << "after loop" << endl;
    // cout << construction_area << endl;
}

// void ConstructionArea::set_construction_area_value(int n,int i,int j){
//     construction_area[i][j]=n;
// }

//getter
// int** ConstructionArea::get_construction_area()
// {
//     int **construction_area_copy;
//     for (int i = 0; i < length; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             construction_area_copy[i][j] = construction_area[i][j];
//         }
//     }
//     return construction_area_copy;
// }
int ConstructionArea::get_length()
{
    return length;
}
int ConstructionArea::get_width()
{
    return width;
}
// int ConstructionArea::get_construction_area_value(int i,int j){
//     int x=0;
//     x =construction_area[i][j];
//     return x;
// }


void ConstructionArea::print()
{
    // cout << "in the print of ca" << endl;
    // cout << construction_area << endl;
    // cout << "l: " << length << endl;
    // cout << "w: " << width << endl;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // cout <<*( *(construction_area + i) + j);
            cout << construction_area[i][j];
        }
        cout << endl;
    }
}


bool ConstructionArea::removable(int l, int w)
{
    // cout << "removable" << endl;

    bool x = true;
    for (int i = l; i < length; i++)
    {
        // cout << "value of i " << i << endl;
        for (int j = w; j < width; j++)
        {
            // cout << "value of j " << j << endl;
            // cout << construction_area[i][j] << endl;
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