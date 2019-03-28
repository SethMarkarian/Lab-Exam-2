#include "hashentry.h"

HashEntry::HashEntry()
{
    //help tell the difference between empty and non-empty HashEntry
    element = "EMPTY";
}

HashEntry::HashEntry(std::string _element)
{
    //non-empty HashEntry
    element = _element;
}

long HashEntry::getHash()
{
    return hash;
}

std::string HashEntry::getElement()
{
    return element;
}
