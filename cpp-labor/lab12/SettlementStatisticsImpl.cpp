//
// Created by beder on 2022. 12. 07..
//

#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return this->data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    unordered_set<string> set;
    for(auto &item : this->data){
        set.insert(item.first);
    }
    return set.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int counter = 0;
    for(auto &item : this->data){
        if(item.first == county){
            counter++;
        }
    }
    return counter;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    return vector<Settlement>();
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    return Settlement();
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    return Settlement();
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    return Settlement();
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    return vector<Settlement>();
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &fileName) {
    ifstream input(fileName);
    if (!input) {
        cerr << "File not found!" << endl;
        exit(1);
    }
    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream ss(line);
        string name, county;
        int population;
        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> population;
        this->data.insert({county, Settlement(name, county, population)});
    }
}

