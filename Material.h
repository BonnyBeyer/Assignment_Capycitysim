#ifndef _MYHEADER_H_
#define _MYHEADER_H_
#include <string>

class Material
{
protected:
    double material_price;
    std::string material_name;

public:
    int id = 0;
    Material();
    ~Material();
    std::string get_material_name();
    double get_material_price();
    bool operator <(const Material& rhs) const;

};
#endif 