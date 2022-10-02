//
// Created by beder on 2022. 09. 28..
//

#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>


#include "Point.h"

using namespace std;

double distance(const Point& a, const Point& b);

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);

int distSq(const Point& p, const Point& q);

Point* createArray(int numPoints);

pair<Point, Point> closestPoints(Point* points, int numPoints);

pair<Point, Point> farthestPoints(Point* points, int numPoints);

bool compare(Point p1, Point p2);

void sortPoints(Point* points, int numPoints);

Point* farthestPointsFromOrigin(Point* points, int numPoints);

void deletePoints(Point* points);






#endif //LAB2_UTIL_H
