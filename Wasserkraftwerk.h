#ifndef _WASSERKRAFTWERK_H_
#define _WASSERKRAFTWERK_H_
#include "Building.h"



class Wasserkraftwerk: public Building
{
private:
    /* data */
public:
    Wasserkraftwerk(int l, int w, int *p, ConstructionArea Area, Material *_materials);
    ~Wasserkraftwerk();
};
#endif

