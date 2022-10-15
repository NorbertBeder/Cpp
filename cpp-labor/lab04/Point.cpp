//
// Created by beder on 2022. 10. 12..
//

#include "Point.h"

Point::Point(int x, int y) {
    if(x >= 0 && x <= M && y >= 0 && y <= M){
        this->x = x;
        this->y = y;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow((this->x - point.x), 2) + pow((this->y - point.y), 2));
}

