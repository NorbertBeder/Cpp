//
// Created by beder on 2022. 10. 08..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"

class Stack {
private:
    List stack;
public:
    void push(int e);
    int pop();
    bool isEmpty() const;
    void print();
};


#endif //CPP_2022_STACK_H
