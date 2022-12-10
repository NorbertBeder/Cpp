//
// Created by beder on 2022. 12. 07..
//

#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return this->data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    unordered_set<string> set;
    for (auto &item: this->data) {
        set.insert(item.first);
    }
    return set.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int counter = 0;
    for (auto &item: this->data) {
        if (item.first == county) {
            counter++;
        }
    }
    return counter;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> settlements;
    for (auto &s: data) {
        if (s.first == county) {
            settlements.emplace_back(s.second);
        }
    }
    return settlements;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    Settlement settlement;
    for (auto &s : data){
        if (s.first == county && s.second.getName() == name){
            settlement.setCounty(s.first);
            settlement.setPopulation(s.second.getPopulation());
            settlement.setName(s.second.getName());
        }
    }
    if (settlement.getName().empty()){
        cout << "Not found" << endl;
    }
    return settlement;
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {

    // a density-hez nem kellene ismerjuk a helyseg nagysagat is kilometerben? mert az nelkul nem tudom mit kellene itt es a minimumnal csinalni
    return Settlement();
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    return Settlement();
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> settlements;
    for (auto &s: data) {
        if (s.second.getName() == name) {
            settlements.emplace_back(s.second);
        }
    }
    return settlements;
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

