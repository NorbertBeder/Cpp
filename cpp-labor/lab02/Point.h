//
// Created by beder on 2022. 09. 28..
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};
#endif //LAB2_POINT_H
