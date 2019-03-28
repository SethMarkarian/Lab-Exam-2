#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <string>

class HashEntry
{
private:
    std::string element;
    long hash;
public:
    HashEntry();
    HashEntry(std::string _element);
    std::string getElement();
    long getHash();
};

#endif // HASHENTRY_H
