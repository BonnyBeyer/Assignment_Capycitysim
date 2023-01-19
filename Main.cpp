#include <iostream>
#include <istream>
#include <stdexcept>
#include "ConstructionArea.cpp"
#include "Building.cpp"


using namespace std;



int main()
{

    cout << "How long is the building area?" << endl;
    int length = 0;
    cin >> length;

    cout << "How wide is the building area?" << endl;
    int width = 0;
    cin >> width;

    ConstructionArea Area = ConstructionArea(length, width);
    Area.setLength(length);
    Area.setWidth(width);
    
    // printarr(*Area.construction_area, Area.length, Area.width);

    Building buildings[20];

    int n = -1;
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
            n++;
            cout << "Please enter building typ (choose between (1)shop, (2)mall, (3)house):" << endl;
            Typ b;
            int x;
            cin >> x;
            if (x == 1 || x == 2 || x == 3)
            {
                b = static_cast<Typ>(x);
            }
            else
            {
                cout << "choose a valid typ";
                continue;
            }

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
            try
            {
                buildings[n] = Building(b, l, w, p, Area);
            }
            catch (const invalid_argument  iaex)
            {
                cout << endl
                     << "Building at that area is not possible!" << endl;
                n--;
               
            }
            

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
                Area.setLength(length_new);
                Area.setWidth(width_new);
            }
            else
            {

                int desicion = 0;
                bool wrong_answer = true;

                while (wrong_answer)
                {
                    cout << "Warning! buildings will be cut off or deleted" << endl;
                    cout << "Do you want to proceed? " << endl
                         << " 1)yes" << endl
                         << "2) no" << endl;
                    cin >> desicion;
                    if (desicion == 1)
                    {
                        Area.setLength(length_new);
                        Area.setWidth(width_new);
                        wrong_answer = false;
                    }
                    if (desicion == 2)
                    {
                        wrong_answer = false;
                    }
                }
            }

            break;
        }
            
        case 3:
        {
            Area.print();
            //cout << buildings[0].tostring();
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

