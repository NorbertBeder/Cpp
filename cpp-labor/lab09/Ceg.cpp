//
// Created by beder on 2022. 11. 20..
//

#include "Ceg.h"
#include <algorithm>

void Ceg::addWorker(Alkalmazott* alkalmazott) {
    worker.emplace_back(alkalmazott);
}

void Ceg::removeWorker(Alkalmazott *alkalmazott) {
    int id = alkalmazott->getId();
    worker.erase(remove_if(worker.begin(), worker.end(), [&id](Alkalmazott* wantedAlkalmazott){
        return id == wantedAlkalmazott->getId();
    }), worker.end());


}

void Ceg::addToManager(Manager* manager, Alkalmazott* alkalmazott) {
    if(find(worker.begin(), worker.end(), alkalmazott) != worker.end()){
        manager->addAlkalmazott(alkalmazott);
    }
}

void Ceg::removeFromManager(Manager *manager, Alkalmazott *alkalmazott) {
    if(find(worker.begin(), worker.end(), alkalmazott) != worker.end()){
        manager->deleteAlkalmazott(alkalmazott);
    }
}

void Ceg::print(ostream &os) const {
    for(const auto *alkalmazott : worker){
        os << *alkalmazott << endl;
    }
}

void Ceg::printManager(ostream &os) const {
    for(const auto *alkalmazott : worker){
        if(dynamic_cast<const Manager* >(alkalmazott)) {
            os << *alkalmazott << endl;
        }
    }
}





