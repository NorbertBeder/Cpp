//
// Created by beder on 2022. 11. 20..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H

#include "Manager.h"

class Ceg {
    vector<Alkalmazott*> worker;

public:
    void addWorker(Alkalmazott* alkalmazott);
    void removeWorker(Alkalmazott* alkalmazott);
    void addToManager(Manager* manager, Alkalmazott* alkalmazott);
    void removeFromManager(Manager* manager, Alkalmazott* alkalmazott);\
    virtual void print(ostream &os) const;
    virtual void printManager(ostream &os) const;

};

#endif //CPP_2022_CEG_H
