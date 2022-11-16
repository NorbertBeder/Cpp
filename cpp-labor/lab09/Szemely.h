//
// Created by beder on 2022. 11. 16..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H

#include <iostream>
#include <string>

using namespace std;

class Szemely {
protected:
    string vezetkNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv);

    virtual void print(ostream &os) const;
};

ostream &operator<<(ostream &os, const Szemely &szemely);

#endif //CPP_2022_SZEMELY_H
