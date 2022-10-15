//
// Created by beder on 2022. 10. 12..
//

#ifndef CPP_2022_POINTSET_H
#define CPP_2022_POINTSET_H
#include "Point.h"
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
class PointSet{
    vector<Point> points;

    int n;

    vector<double> distances;

    void computeDistances();

    static bool compareByX(Point a, Point b);
    static bool compareByY(Point a, Point b);
public:

    PointSet( int n = 100 );

    double maxDistance() const;

    double minDistance() const;

    int numDistances() const;

    void printPoints() const;

    void printDistances() const;

    void sortPointsX();

    void sortPointsY();

    void sortDistances();

    int numDistinctDistances();
};



#endif //CPP_2022_POINTSET_H
