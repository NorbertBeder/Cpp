#include <iostream>

#include "Alkalmazott.h"

int main() {
    Szemely szemely("Nagy", "Janos", 2001);
    cout << szemely << endl;
    Alkalmazott alkalmazott("Kiss", "Erno", 1996, "alkalmazott");
    Alkalmazott alkalmazott1("Beder", "Norbert", 2002, "alkamazott");
    cout << alkalmazott << endl;
    cout << alkalmazott1;


    return 0;
}