#include <stdio.h>
#include <string>
#include "Solarpanel.h"
#include "Building.cpp"
//#include "ConstructionArea.cpp"
#include "Material.h"
//#include "CapyCitySim.cpp"

Solarpanel::Solarpanel(int l, int w, int *p, ConstructionArea* Area):Building(l,w,p,Area)
{
    label = to_string(anzahl_b)+") Solarpanel (1)";
    price = 1000;

    bool possibility = built_posibillity(Area, p, w, l);

    if (possibility == true)
    {
        
        length = l;
        width = w;
        position = p;
      
        for (int i = p[0]; i < length + p[0]; i++)
        {
            for (int j = p[1]; j < width + p[1]; j++)
            {
                Area->construction_area[i][j] = 1;
              
            }
         
        }

       
    }
    else
    {
        throw std::invalid_argument("building is not possible");
    }

    
}

Solarpanel::~Solarpanel()
{
}