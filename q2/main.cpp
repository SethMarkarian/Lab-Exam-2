#include <iostream>
#include "hashentry.h"
#include "hashtab.h"

using namespace std;

// Copy and paste this function into your HashTab class.
// long hash(HashEntry he){
//     std::string key = he.get_element();
//     long hsh = 17;
//     for (unsigned int i = 0; i < key.length(); i++) {
//         hsh = 31*hsh + int(key.at(i));
//     }
//     return hsh % 13;
// }

int main()
{
    // Uncomment this code when you are ready to demonstrate/test.
     HashEntry he1("Piano"), he2("Forte"), he3("Piano");
     HashTab h1;
     h1.insert(he1);
     h1.insert(he2);
     h1.insert(he3);
    return 0;
}
