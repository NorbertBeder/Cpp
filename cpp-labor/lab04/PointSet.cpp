//
// Created by beder on 2022. 10. 12..
//

#include <iostream>
#include "PointSet.h"



PointSet::PointSet(int n) {

    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<> distribution(0, M);

    this->n = n;
    this->points.reserve(n);
    this->distances.reserve((n * (n - 1)) / 2);

    while(points.size() < n){
        Point p = {distribution(gen), distribution(gen)};
        points.emplace_back(p);
    }

    computeDistances();

    cout << endl;
}


void PointSet::computeDistances() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.emplace_back(points.at(i).distanceTo(points.at(j)));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return (int)distances.size();
}

void PointSet::printPoints() const {
    for(Point point : points){
        cout << "[" << point.getX() << ", " << point.getY() << "] ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for(double d : distances){
        cout << d << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), compareByX);
}

bool PointSet::compareByX(Point a, Point b) {
    return a.getX() < b.getX();
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), compareByY);
}

bool PointSet::compareByY(Point a, Point b) {
    return a.getY() < b.getY();
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    auto uniquePoints = unique(distances.begin(), distances.end());
    distances.erase(uniquePoints, distances.end());
    return (int)distances.size();
}
