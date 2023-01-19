#ifndef _WINDKRAFTWERK_H_
#define _WINDKRAFTWERK_H_
#include "Building.h"


class Windkraftwerk: public Building
{
private:
    /* data */
public:
    Windkraftwerk(int l, int w, int *p, ConstructionArea Area);
    ~Windkraftwerk();
};
#endif

