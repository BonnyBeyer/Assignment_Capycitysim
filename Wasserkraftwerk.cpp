#include <stdio.h>
#include <string>
#include "Wasserkraftwerk.h"
#include "Building.h"
#include "ConstructionArea.h"
#include "Material.h"
#include"CapyCitySim.h"

Wasserkraftwerk::Wasserkraftwerk(int l, int w, int *p, ConstructionArea Area, Material *_materials):Building(l,w,p,Area,_materials)
{
    label = to_string(anzahl_b) + ") Wasserkraftwerk";
    price = 1500;
}

Wasserkraftwerk::~Wasserkraftwerk()
{
}