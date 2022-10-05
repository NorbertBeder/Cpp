//
// Created by beder on 2022. 10. 05..
//

#include "List.h"
#include <iostream>

List::List() {
    std::cout << "Constructor" << std::endl;
    this->first = nullptr;
}

List::~List() {
    std::cout << "Destructor" << std::endl;
//    Node *act = this->first;
//    while (act != nullptr){
//        Node *temp = act;
//        act = act->next;
//        delete temp;

    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
        --this->nodeCounter;
    }
}

void List::insertFirst(int d) {
//    Node *temp = new Node(d, first);
//    first = temp;
    this->first = new Node(d, first);
    ++this->nodeCounter;
}

void List::print() const {
    std::cout << "[";
    for (Node *ptr = this->first; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << " ";
    }
    std::cout << "]" << std::endl;
}

bool List::exists(int d) const {
    Node *temp = first;
    while (temp != nullptr) {
        if (temp->value == d) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    if (this->nodeCounter == 0) {
        return true;
    }
    return false;
}

int List::removeFirst() {
    if (this->nodeCounter == 0) {
        throw std::invalid_argument("The list is empty - can't remove first.");
    }
    Node *temp = first;
    int n = temp->value;
    this->first = this->first->next;

    delete temp;
    --this->nodeCounter;
    return n;
}

void List::remove(int d, List::DeleteFlag df) {
    Node *node = first, *current, *previous;
    if (df == DeleteFlag::EQUAL) {
        while (node->value != d) {
            node = node->next;
        }
        delete node;
    }
}
