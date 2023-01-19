#include <stdio.h>
#include "Material.h"
#include <string>

Material::Material()
{
}

Material::~Material()
{
}

std::string Material::get_material_name()
{

    
    return material_name;
}

double Material::get_material_price()
{
    return material_price;
}

bool Material::operator<(const Material &rhs) const
{
    return id < rhs.id;
}