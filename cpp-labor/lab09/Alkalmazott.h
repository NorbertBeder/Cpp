//
// Created by beder on 2022. 11. 16..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {
protected:
    string munkakor;
    static int alkalmazottId;
    int id;
public:
    Alkalmazott(const string& vezetekNev, const string& keresztNev, int szuletesiEv, const string& munkakor);

    virtual void print(ostream &os) const;

    int getId();
};

#endif //CPP_2022_ALKALMAZOTT_H
