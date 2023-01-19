#ifndef _SOLARPENAL_H_
#define _SOLARPENAL_H_
#include "Building.h"


class Solarpanel: public Building
{
private:
    /* data */
public:
    Solarpanel(int l, int w, int *p, ConstructionArea* Area);
    ~Solarpanel();
};
#endif

