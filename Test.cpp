#include <iostream>
#include <istream>
#include <stdexcept>
#include "Holz.cpp"
#include "Metall.cpp"
#include "Kunststoff.cpp"
#include "Solarpanel.cpp"
#include "Windkraftwerk.cpp"
#include "Wasserkraftwerk.cpp"
#include "ConstructionArea.cpp"
#include "CapyCitySim.cpp"

using namespace std;

int main()
{
    Material _materials[100];
    cout << "How long is the building area?" << endl;
    int length = 0;
    cin >> length;

    cout << "How wide is the building area?" << endl;
    int width = 0;
    cin >> width;

    ConstructionArea Area = ConstructionArea(length, width);
    CapyCitySim CCS = CapyCitySim();
    Area.set_length(length);
    Area.set_width(width);

    // printarr(*Area.construction_area, Area.length, Area.width);

    // Building buildings[20];

    // int n = -1;
    bool while_loop = true;
    while (while_loop)
    {
        cout << "1)Place a building" << endl
             << "2)delete part of building area" << endl
             << "3)Print plan" << endl
             << "4)exit" << endl;
        int menu_choice = 0;
        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
        {
            // n++;

            cout << "Please enter building length:" << endl;
            int l;
            cin >> l;
            cout << "Please enter building width:" << endl;
            int w;
            cin >> w;
            cout << "Please enter the row oft the buildings upper left corner:" << endl;
            int r;
            cin >> r;
            cout << "Please enter the column oft the buildings upper left corner:" << endl;
            int c;
            cin >> c;
            int p[] = {r, c};
            bool b1 = true;
            while (b1)
            {
                cout << "How much of one material do you want to add? " << endl;
                int amount = 0;
                cin >> amount;

                cout << "Which material do you want to add? (1) Holz, (2) Metall, (3) Kunststoff" << endl;
                int m = 0;
                cin >> m;
                if (m != 1 && m != 2 && m != 3)
                {
                    cout << "choose a valid typ from 1 to 3"<<endl;
                    bool b2 = true;
                    while (b2)
                    {
                        cin >> m;
                        if (m == 1 || m == 2 || m == 3)
                            b2 = false;
                    }
                }
                if (m == 1)
                {
                    Holz material = Holz();
                    for (int i = 0; i < amount; i++)
                    {
                        _materials[i] = material;
                    }
                }
                if (m == 2)
                {
                    Metall material = Metall();
                    for (int i = 0; i < amount; i++)
                    {
                        _materials[i] = material;
                    }
                }
                if (m == 3)
                {
                    Kunststoff material = Kunststoff();
                    for (int i = 0; i < amount; i++)
                    {
                        _materials[i] = material;
                    }
                }

                cout << "Do you want to add another material? (1) yes (2) no "<<endl;
                int input;
                cin >> input;
                if (input != 1)
                {
                    b1 = false;
                }
            }
            bool b = true;
            int x = 0;
            while (b)
            {
                cout << "Please enter building typ (choose between (1)Solarpark, (2)Windkraftwerk, (3)Wasserkraftwerk):" << endl;
                cin >> x;
                if (x != 1 && x != 2 && x != 3)
                {
                    cout << "choose a valid typ from 1 to 3"<<endl;
                       
                }else  b = false;
            }
            try
            {
                if (x == 1)
                {
                    Solarpanel building = Solarpanel(l, w, p, Area, _materials);
                    CCS.add(building);
                }
                if (x == 2)
                {
                    Windkraftwerk building = Windkraftwerk(l, w, p, Area, _materials);
                    CCS.add(building);
                }
                if (x == 3)
                {
                    Wasserkraftwerk building = Wasserkraftwerk(l, w, p, Area, _materials);
                    CCS.add(building);
                }
            }
            catch (const invalid_argument iaex)
            {
                cout << endl
                     << "Building at that area is not possible!" << endl;
            };
            continue;
        }

        case 2:
        {
            cout << "How long is the building area now?";
            int length_new;
            cin >> length_new;

            cout << "How wide is the building area now?";
            double width_new;
            cin >> width_new;

            // ConstructionArea Area = ConstructionArea(length, width);
            if (Area.removable(length_new, width_new) && length >= length_new && width >= width_new)
            {
                Area.set_length(length_new);
                Area.set_width(width_new);
            }
            else  cout << "Not possible!" << endl;
            
            break;
        }
        case 3:
        {
            Area.print();
            // cout << buildings[0].tostring();
            if (Building::anzahl_b>0){
                      CCS.print();
            }
      
            break;
        }

        case 4:
        {
            while_loop = false;
            break;
        }

        default:
        {
            cout << "Please enter a correct choice between 1-4!" << endl;
        }
        }
    }
}
