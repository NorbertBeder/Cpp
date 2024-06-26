//
// Created by beder on 2022. 12. 07..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICS_H
#define CPP_2022_SETTLEMENTSTATISTICS_H

#include <string>
#include <vector>
#include "Settlement.h"

using namespace std;

struct SettlementStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector <Settlement> findSettlementsByCounty(const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const = 0;

    virtual Settlement maxPopulationDensity() const = 0;

    virtual Settlement minPopulationDensity() const = 0;

    virtual vector <Settlement> findSettlementsByName(const string &name) = 0;
};

#endif //CPP_2022_SETTLEMENTSTATISTICS_H
