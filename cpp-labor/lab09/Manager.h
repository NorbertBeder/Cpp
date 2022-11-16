//
// Created by beder on 2022. 11. 16..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <vector>
#include "Alkalmazott.h"

class Manager : public Alkalmazott{
private:
    vector <Alkalmazott*> beosztottak;
    static const string MANAGER_MUNKAKOR;

public:
    Manager(const string& vezetekNev, const string& keresztNev, int szuletesiEv, const string& munkakor);
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(Alkalmazott* alkalmazott);
};

#endif //CPP_2022_MANAGER_H
