#include <iostream>
#include "Stack.h"

int main() {
    List list;
    for (int i = 0; i < 15; ++i) {
        list.insertFirst(i);
    }
    std::cout << "List: ";
    list.print();

    int containsNum = 7;
    if (list.exists(containsNum)) {
        std::cout << "Contains the number: " << containsNum << std::endl;
    } else {
        std::cout << "Does not contain the number: " << containsNum << std::endl;
    }

    std::cout << "List size: " << list.size() << std::endl;

    if (list.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    std::cout << "Deleted the first number: " << list.removeFirst() << std::endl;
    list.print();

    int removeNumber = 8;
    std::cout << "Deleted the specified number : " << std::endl;
    list.remove(removeNumber, List::DeleteFlag::LESS);
    list.print();

    std::cout << std::endl << std::endl;
    Stack stack;
    for (int i = 0; i < 10; ++i) {
        stack.push(i);
    }
    std::cout << "Stack: ";
    stack.print();

    if(stack.isEmpty()){
        std::cout << "The stack is empty." << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl;
    }

    std::cout << "Removed first element: "<< stack.pop() << std::endl;
    stack.print();
    std::cout << std::endl;

    return 0;
}
