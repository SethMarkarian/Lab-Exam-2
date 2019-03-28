#ifndef ZORSE_H
#define ZORSE_H

#include "zebra.h"
#include "horse.h"

class Zorse : public Zebra, public Horse
{
public:
    Zorse();
};

#endif // ZORSE_H
