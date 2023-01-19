#include <iostream>
#include <istream>

enum Typ
{
    empty,
    shop,
    mall,
    house
};

using namespace std;

class Building
{                 // The class
public:           // Access specifier
    Typ building; // Attribute
    int length;   // Attribute
    int width;
    int *position; // Attribute

    Building() {}

    Building(Typ b, int l, int w, int *p, ConstructionArea Area)
    { // Constructor with parameters

        // cout << "Const Area: " << endl;
        // Area.print();
        bool possibility = built_posibillity(Area, p, w, l);

        // cout << "Possibility: " << possibility << endl;
        if (possibility == true)
        {
            building = b;
            length = l;
            width = w;
            position = p;
            // cout << "before loop";
            for (int i = p[0]; i < length + p[0]; i++)
            {
                for (int j = p[1]; j < width + p[1]; j++)
                {
                    Area.construction_area[i][j] = b;
                    // cout << Area.construction_area[i][j];
                }
                // cout << endl;
            }
        }
        else
        {
            throw std::invalid_argument("building is not possible");
        }
    }

    void set_b(Typ b, int l, int w, int *p, ConstructionArea Area)
    {
        bool possibility = built_posibillity(Area, p, w, l);
        // cout << "Const Area: " << endl;
        // Area.print();

        // cout << "Possibility: " << possibility << endl;
        if (possibility == true)
        {
            building = b;
            length = l;
            width = w;
            position = p;
            int x = p[0];
            // cout << "before loop";
            for (int i = x; i < length + p[0]; i++)
            {
                for (int j = p[1]; j < width + p[1]; j++)
                {
                    Area.construction_area[i][j] = b;
                    // cout << Area.construction_area[i][j];
                }
                // cout << endl;
            }
        }
        else
        {
            cout << "building is not possible" << endl;
            __throw_invalid_argument;
        }
    }

    void delet(ConstructionArea Area)
    {
        building = static_cast<Typ>(0);
        length = 0;
        width = 0;
        position = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Area.construction_area[i][j] = 0;
            }
        }
    }
    void set_Typ(Typ b)
    {
        building = b;
    }
    Typ get_Typ()
    {
        return building;
    }
    int get_length()
    {
        return length;
    }
    int get_width()
    {
        return width;
    }
    int get_position_row()
    {
        // cout << "position" << endl;
        int row = position[0];

        // cout << "row" << endl;
        return row;
    }
    int get_position_column()
    {
        // cout << "position" << endl;
        int column = position[1];

        // cout << "column" << endl;
        return column;
    }

    bool built_posibillity(ConstructionArea Area, int *p, int w, int l)
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

    string tostring()
    {
        int x = position[1];
        return "Typ: " + to_string(building) +
               " Length: " + to_string(length) +
               " Width: " + to_string(width) +
               " Position: " + to_string(position[0]) +
               " and " + to_string(x);
    }

    void print_buildings()
    {
        cout << "Typ: " << building << endl
             << " Length: " << length << endl
             << " Width: " << width << endl
             << " Position: " << position[0] << endl
             << " and " << position[1] << endl;
    }
};