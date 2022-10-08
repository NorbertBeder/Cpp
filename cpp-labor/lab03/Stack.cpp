//
// Created by beder on 2022. 10. 08..
//

#include "Stack.h"

void Stack::push(int e) {
    this->stack.insertFirst(e);
}

int Stack::pop() {
    int removedNum = this->stack.removeFirst();
    return removedNum;
}

bool Stack::isEmpty() const {
    return this->stack.empty();
}

void Stack::print() {
    this->stack.print();
}


