//
// Created by beder on 2022. 11. 16..
//

#include "Alkalmazott.h"

int Alkalmazott::alkalmazottId{0};

Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Szemely(vezetekNev,
                  keresztNev,
                  szuletesiEv) {
    this->munkakor = munkakor;
    this->id = ++alkalmazottId;
}

void Alkalmazott::print(ostream &os) const {
    os << this->id << " ";
    Szemely::print(os);
    os << " " << munkakor;
}

int Alkalmazott::getId() {
    return this->id;
}
