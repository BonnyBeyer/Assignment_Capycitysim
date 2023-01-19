

#include <iostream>
#include <istream>
#include <iterator>
#include <vector>
#include "CapyCitySim.h"
// #include "Building.h"
// #include "ConstructionArea.h"
#include <bits/stdc++.h>

CapyCitySim::CapyCitySim()
{
}

CapyCitySim::~CapyCitySim()
{
}



auto sortRuleLambda = [](Blueprint *A, Blueprint *B) -> bool
{
    
    return A->get_kennzahl() < B->get_kennzahl();
};
void CapyCitySim::add(Blueprint *_blueprints)
{
    cout << "Add blueprint" << endl;

    if (anzahl_bulueprints == 0)
    {
        blueprints[anzahl_bulueprints] = _blueprints;
        anzahl_bulueprints++;
        
    }
    else
    {

        double k1;
        double k2;

        string s1 = "A";
        string s2 = "A";
        for (int i = 0; i < anzahl_bulueprints; i++)
        {

            k1 = blueprints[i]->calculate_kennzahl();
            k2 = _blueprints->calculate_kennzahl();
           

            if (k1 == k2)
            {

                s1 = blueprints[i]->get_AreaBlueprint()->create_id();
                s2 = _blueprints->get_AreaBlueprint()->create_id();
                
                if (s1 == s2)
                {
                   
                    return;
                }
            }
        }

        blueprints[anzahl_bulueprints] = _blueprints;
        anzahl_bulueprints++;

        
    }
}

void CapyCitySim::print()
{
   
    if (anzahl_bulueprints == 0)
    {
        return;
    }

 
    vector <Blueprint*> v (blueprints,blueprints+anzahl_bulueprints);
    sort(begin(v), end(v), sortRuleLambda);
   
    
    for (int i = 0; i < anzahl_bulueprints; i++)
    {
      
        v[i]->print();

        std::cout << endl
                  << endl;
    } 
}


