//
// Created by beder on 2022. 09. 28..
//

#include "Util.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

int distSq(const Point &a, const Point &b) {
    return (a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY());
}

bool isSquare(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    int dist1 = distSq(p1, p2);
    int dist2 = distSq(p1, p3);
    int dist3 = distSq(p1, p4);

    if (dist1 == 0 || dist2 == 0 || dist3 == 0)
        return false;

    if (dist1 == dist2 && 2 * dist1 == dist3
        && 2 * distSq(p2, p4) == distSq(p2, p3)) {
        return true;
    }

    if (dist2 == dist3 && 2 * dist2 == dist1
        && 2 * distSq(p3, p2) == distSq(p3, p4)) {
        return true;
    }
    if (dist1 == dist3 && 2 * dist1 == dist2
        && 2 * distSq(p2, p3) == distSq(p2, p4)) {
        return true;
    }

    return false;
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    srand(time(nullptr));

    for (int i = 0; i < numPoints; ++i) {
        points[i] = {rand() % 2001, rand() % 2001};
    }
    return points;
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    Point p1, p2;
    Point fin_p1, fin_p2;
    double finalDist = INT_MAX;
    for (int i = 0; i < numPoints; ++i) {
        p1 = {points[i].getX(), points[i].getY()};
        for (int j = i + 1; j < numPoints; ++j) {
            p2 = {points[j].getX(), points[j].getY()};
            double tempDist = distance(p1, p2);
            p1.print();
            p2.print();
            cout << "-distance- " << tempDist << endl << endl;
            if (tempDist < finalDist) {
                finalDist = tempDist;
                fin_p1 = p1;
                fin_p2 = p2;
            }
        }
    }
    cout << endl;
    return make_pair(fin_p1, fin_p2);
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    Point p1, p2;
    Point fin_p1, fin_p2;
    double finalDist = 0;
    for (int i = 0; i < numPoints; ++i) {
        p1 = {points[i].getX(), points[i].getY()};
        for (int j = i + 1; j < numPoints; ++j) {
            p2 = {points[j].getX(), points[j].getY()};
            double tempDist = distance(p1, p2);
            if (tempDist > finalDist) {
                finalDist = tempDist;
                fin_p1 = p1;
                fin_p2 = p2;
            }
        }
    }
    return make_pair(fin_p1, fin_p2);
}

bool compare(Point p1, Point p2) {
    return p1.getX() < p2.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, compare);
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    Point *farPoints = new Point[10];
    Point p1 = {0, 0}, p2;
    double distances[10];
    for (int i = 0; i < 10; ++i) {
        p2 = {points[i].getX(), points[i].getY()};
        farPoints[i] = points[i];
        distances[i] = distance(p1, p2);
    }

    int auxHelp;


    for (int i = 10; i < numPoints; ++i) {
        p2 = {points[i].getX(), points[i].getY()};
        double tempDistance = distance(p1, p2);
        double auxDist = INT_MAX;
        for (int j = 0; j < 10; ++j) {
            if(distances[j] < auxDist){
                auxDist = distances[j];
                auxHelp = j;
            }
        }
        if(tempDistance > auxDist){
            farPoints[auxHelp] =  points[i];
            distances[auxHelp] = tempDistance;
        }
    }

    return farPoints;
}

void deletePoints(Point *points) {
    delete[] points;
}



