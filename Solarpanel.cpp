#include <stdio.h>
#include <string>
#include "Solarpanel.h"
#include "Building.cpp"
//#include "ConstructionArea.cpp"
#include "Material.h"
//#include "CapyCitySim.cpp"

Solarpanel::Solarpanel(int l, int w, int *p, ConstructionArea Area):Building(l,w,p,Area)
{
    label = to_string(anzahl_b)+") Solarpanel";
    price = 1000;

    
}

Solarpanel::~Solarpanel()
{
}