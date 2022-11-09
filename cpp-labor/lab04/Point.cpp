//
// Created by beder on 2022. 10. 12..
//

#include "Point.h"
int Point::counter{1};

Point::Point(int x, int y) {
    if(x >= 0 && x <= M && y >= 0 && y <= M){
        this->x = x;
        this->y = y;
        counter++;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}


int Point::getCounter() {
    return counter;
}


double Point::distanceTo(const Point &point) const {
    return sqrt(pow((this->x - point.x), 2) + pow((this->y - point.y), 2));
}


Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
    counter++;
}

Point::~Point() {
    this->x = 0;
    this->y = 0;
    counter--;
}
