#include <stdio.h>
#include <string>
#include "Windkraftwerk.h"
#include "Building.h"
#include "ConstructionArea.h"
#include "Material.h"
#include "CapyCitySim.h"

Windkraftwerk::Windkraftwerk(int l, int w, int *p, ConstructionArea Area) : Building(l, w, p, Area)
{
    label = to_string(anzahl_b) + ") Windkraftwerk";
    price = 2000;
}

Windkraftwerk::~Windkraftwerk()
{
}