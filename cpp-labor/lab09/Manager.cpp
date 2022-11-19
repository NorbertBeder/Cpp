//
// Created by beder on 2022. 11. 16..
//

#include <algorithm>
#include "Manager.h"


const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, MANAGER_MUNKAKOR) {
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    int id = alkalmazott->getId();
    beosztottak.erase(remove_if(beosztottak.begin(), beosztottak.end(), [&id](const Alkalmazott* wantedAlkalmazott){
        return id == wantedAlkalmazott->getId();
    }), beosztottak.end());
}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
    os << "\n\tBeosztottjai: \n\t   ";
    for(Alkalmazott *alkalmazott : beosztottak){
        alkalmazott->print(os);
        os << "\n\t   ";
    }
}

unsigned int Manager::beosztottakSzama() {
    return beosztottak.size();
}

