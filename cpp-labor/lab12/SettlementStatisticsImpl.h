//
// Created by beder on 2022. 12. 07..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H

#include <vector>
#include <map>
#include "Settlement.h"
#include "SettlementStatistics.h"
#include <fstream>
#include <sstream>
#include <unordered_set>

class SettlementStatisticsImpl : public SettlementStatistics{
    multimap<string, Settlement> data;
public:
    SettlementStatisticsImpl(const string &fileName);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector <Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulationDensity() const override;

    Settlement minPopulationDensity() const override;

    vector <Settlement> findSettlementsByName(const string &name) override;
};

#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H
