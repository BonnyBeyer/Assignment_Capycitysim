#include <stdio.h>
#include <string>
#include "Windkraftwerk.h"
#include "Building.h"
#include "ConstructionArea.h"
#include "Material.h"
#include "CapyCitySim.h"

Windkraftwerk::Windkraftwerk(int l, int w, int *p, ConstructionArea* Area) : Building(l, w, p, Area)
{
    label = to_string(anzahl_b) + ") Windkraftwerk (3)";
    price = 2000;

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
                Area->construction_area[i][j] = 2;
              
            }
         
        }

       
    }
    else
    {
        throw std::invalid_argument("building is not possible");
    }
   
}

Windkraftwerk::~Windkraftwerk()
{
}