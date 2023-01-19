
#include<stdio.h>
#include "Holz.h"
#include "Material.cpp"

Holz::Holz(/* args */)
{
    Material::material_price =100;
    Material::material_name ="Holz";
    Material::id=1;
}

Holz::~Holz()
{
}

