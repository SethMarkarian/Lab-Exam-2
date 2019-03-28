#include "hashtab.h"

HashTab::HashTab()
{
    arr = new HashEntry[13];
    size = 0;
}

HashTab::HashTab(HashEntry * _arr)
{
    arr = _arr;
}

void HashTab::insert(HashEntry he)
{
    long pos = hash(he); //get hash from method
    if(size < 13) { //see if size is less than 13
        while(arr[(int) pos].getElement() != "EMPTY") { // see if empty element
            pos++;
            if(pos == 13) { //checks to see if it reaches the end
                pos = 0;
            }
        }
        arr[(int) pos] = he; //inserts into position

    }

    std::cout << "An insertion is about to be made at position " << pos << std::endl;;


}

long HashTab::hash(HashEntry he){
     std::string key = he.getElement();
     long hsh = 17;
     for (unsigned int i = 0; i < key.length(); i++) {
         hsh = 31*hsh + int(key.at(i));
     }
     return hsh % 13;
}
