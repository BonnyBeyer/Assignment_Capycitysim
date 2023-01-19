#include <iostream>
#include <istream>

using namespace std;
class ConstructionArea
{
public:
    int length = 1;
    int width = 1;
    int **construction_area;

    ConstructionArea()
    {
    }

    ConstructionArea(int length, int width)
    {
        // int construction_area[length][width];

        construction_area = new int *[length];

        //cout << "before loop" << endl;
        //cout << construction_area << endl;

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
                //cout << construction_area[i][j];
            }
           // cout << endl;
        }

        //cout << "after loop" << endl;
        //cout << construction_area << endl;
    }
    int **getCostructionArea()
    {
        int **construction_area_copy;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                construction_area_copy[i][j] = construction_area[i][j];
            }
        }
        return construction_area_copy;
    }

    void print()
    {
        //cout << "in the print of ca" << endl;
        //cout << construction_area << endl;
       // cout << "l: " << length << endl;
        //cout << "w: " << width << endl;

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

    void setLength(int l)
    {
        length = l;
    }

    void setWidth(int w)
    {
        width = w;
    }
    bool removable(int l, int w)
    {
        //cout << "removable" << endl;

        bool x = true;
        for (int i = l; i < length; i++)
        {
            //cout << "value of i " << i << endl;
            for (int j = w; j < width; j++)
            {
                //cout << "value of j " << j << endl;
                //cout << construction_area[i][j] << endl;
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
};

