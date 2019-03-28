#ifndef HASHTAB_H
#define HASHTAB_H

#include "hashentry.h"
#include <iostream>

class HashTab
{
private:
    int size;
    HashEntry * arr;
public:
    HashTab();
    HashTab(HashEntry * _arr);
    void insert(HashEntry he);
    long hash(HashEntry he);
};

#endif // HASHTAB_H
