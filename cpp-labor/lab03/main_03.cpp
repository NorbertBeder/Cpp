#include <iostream>
#include "List.h"

int main() {
    List list;
    for (int i = 0; i < 14; ++i) {
        list.insertFirst(i);
        list.print();
    }
    if (list.exists(7)) {
        std::cout << "Contains the number." << std::endl;
    } else {
        std::cout << "Does not contain the number." << std::endl;
    }
    std::cout << "List size: " << list.size() << std::endl;
    if (list.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }
    std::cout << "Deleted the first: " << list.removeFirst() << std::endl;
    list.print();

    list.remove(12,List::DeleteFlag::EQUAL);
    list.print();
    return 0;
}
