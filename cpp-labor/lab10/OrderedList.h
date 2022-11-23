//
// Created by beder on 2022. 11. 23..
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>
using namespace std;

template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;


template <class T, class LessComp = less<T>, class Equal = equal_to<T> >

class OrderedList{
private:
    struct Node{
        T value;
        Node* next;
        explicit Node(T value, Node* next = nullptr) : value(value), next(next){}
    };
    Node* first{nullptr};
    int numElements{0}; // nem kell ezert konstruktor es destruktor
    friend class Iterator<T, LessComp, Equal>;

public:
    ~OrderedList();
    void listElements(ostream& os = cout);
    void insert(const T& what);
    bool isEmpty();
    void remove(const T& what);
};

template< class T, class LessComp, class Equal >
class Iterator{
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &list) : list(list), act(list.first) {}
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    auto aux = act->value;
    act = act->next;
    return aux;
}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    return act != nullptr;
}


template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listElements(ostream &os) {
    Node* node = first;
    while (node != nullptr){
        os << node->value << " ";
        node = node->next;
    }
    os << endl;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &what) {
    Node* newNode = new Node(what);
    Node* actualNode = first;
    Node* prevNode = nullptr;
    while (actualNode != nullptr && LessComp()(actualNode->value, what)){
        prevNode = actualNode;
        actualNode = actualNode->next;
    }
    if(prevNode == nullptr){ // ures lista/listafej ele
        newNode->next = first;
        first = newNode;
        ++numElements;
        return;
    }
    prevNode->next = newNode;
    newNode->next = actualNode;
    ++numElements;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &what) {
    Node* actNode = first;
    Node* prevNode = nullptr;
    while (actNode != nullptr && !(Equal()(actNode->value, what))){
        prevNode = actNode;
        actNode = actNode->next;
    }
    if(prevNode == nullptr){
        return;
    }
    delete prevNode->next;
    prevNode->next->next = actNode;
    --numElements;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while (first != nullptr){
        Node* node = first;
        first = first->next;
        delete node;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return first == nullptr;
}




#endif //CPP_2022_ORDEREDLIST_H
