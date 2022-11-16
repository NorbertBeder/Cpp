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
    const int id = alkalmazott->getId();

}

