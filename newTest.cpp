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
#include "Blueprint.cpp"
#include "CapyCitySim.cpp"

using namespace std;


int main()
{
    CapyCitySim CCS = CapyCitySim();
    bool mainmenueloop = true;
    while (mainmenueloop)
    {
        cout << "1)new blueprint" << endl
             << "2)print all plans" << endl
             << "3)exit" << endl;

        int main_menu = 0;
        cin >> main_menu;

        switch (main_menu)
        {
        case 1:
        {
          
            Material _materials[100];
            cout << "How long is the building area?" << endl;
            int length = 0;
            cin >> length;

            cout << "How wide is the building area?" << endl;
            int width = 0;
            cin >> width;

            Blueprint *B1 = new Blueprint(length, width);
            ConstructionArea *Area = B1->get_AreaBlueprint();

           
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
                    // questions to create building
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
                    cout << "Please enter building typ (choose between (1)Solarpark, (2)Windkraftwerk, (3)Wasserkraftwerk):" << endl;
                    int x;
                    cin >> x;
                    if (x != 1 && x != 2 && x != 3)
                    {
                        cout << "choose a valid typ from 1 to 3" << endl;
                        cin >> x;
                    }

                    // creating building
                    try
                    {
                        if (x == 1)
                        {
                            Solarpanel *building = new Solarpanel(l, w, p, Area);
                            B1->add(building);
                        }
                        if (x == 2)
                        {
                            Windkraftwerk *building = new Windkraftwerk(l, w, p, Area);
                            B1->add(building);
                        }
                        if (x == 3)
                        {
                            Wasserkraftwerk *building = new Wasserkraftwerk(l, w, p, Area);
                            B1->add(building);
                        }
                    }
                    catch (const invalid_argument iaex)
                    {
                        cout << endl
                             << "Building at that area is not possible!" << endl;
                    }

                    // material

                    bool b = true;
                    while (b)
                    {
                        cout << "How much of one material do you want to add? " << endl;
                        int amount = 0;
                        cin >> amount;

                        cout << "Which material do you want to add? (1) Holz, (2) Metall, (3) Kunststoff" << endl;
                        int m = 0;
                        cin >> m;

                        if (m != 1 && m != 2 && m != 3)
                        {
                            cout << "choose a valid typ from 1 to 3" << endl;
                            cin >> m;
                        }

                        if (m == 1)
                        {

                            for (int i = 0; i < amount; i++)
                            {

                                B1->get_building(B1->anzahl_buildings - 1)->insert_material("Holz");
                            }
                        }
                        if (m == 2)
                        {

                            for (int i = 0; i < amount; i++)
                            {
                                B1->get_building(B1->anzahl_buildings - 1)->insert_material("Metall");
                            }
                        }
                        if (m == 3)
                        {

                            for (int i = 0; i < amount; i++)
                            {
                                B1->get_building(B1->anzahl_buildings - 1)->insert_material("Kunststoff");
                            }
                        }
                        cout << "Do you want to add another material? (1) yes (2) no " << endl;
                        int input;
                        cin >> input;
                        if (input != 1)
                        {
                            b = false;
                        }
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
                    if (Area->removable(length_new, width_new) && length >= length_new && width >= width_new)
                    {
                        Area->set_length(length_new);
                        Area->set_width(width_new);
                    }
                    else
                        cout << "Not possible!" << endl;

                    break;
                }
                case 3:
                {
                    // Area->print();
                    
                    if (B1->anzahl_buildings > 0)
                    {
                        // Area->print();
                        B1->print();
                    }else{
                        cout<<"nothing to print"<<endl;
                    }

                    break;
                }

                case 4:
                {
                    CCS.add(B1);
                    while_loop = false;
                    break;
                }

                default:
                {
                    cout << "Please enter a correct choice between 1-4!" << endl;
                }
                }
            }

            break;
        }

        case 2:
            // print all plans
            CCS.print();
            break;
        case 3:
            // exit
            mainmenueloop = false;
            break;

        default:
            break;
        }
    }
}