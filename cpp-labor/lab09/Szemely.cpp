//
// Created by beder on 2022. 11. 16..
//

#include "Szemely.h"

Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) {
    this->vezetkNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
}

void Szemely::print(ostream &os) const {
    os << vezetkNev << " " << keresztNev << " " << szuletesiEv;
}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}