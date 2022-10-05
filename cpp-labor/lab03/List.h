//
// Created by beder on 2022. 10. 05..
//

#ifndef CPP_2022_LIST_H
#define CPP_2022_LIST_H

//
// Created by beder on 2022. 10. 05..
//

class List {
public:
    List();

    ~List();

    bool exists(int d) const;

    int size() const;

    bool empty() const;

    void insertFirst(int d);

    int removeFirst();

    enum class DeleteFlag {
        LESS, EQUAL, GREATER
    };

    void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);

/* prints the contents of this list */
    void print() const;

/* forbid copying of lists */
    List(const List &) = delete;

    List &operator=(const List &) = delete;

private:
/* number of nodes in the list */
    int nodeCounter{0};

/* a list node */
    struct Node {
        int value; // the node value
        Node *next; // pointer to the next node, nullptr in the last node
        Node(int v, Node *n) : value(v), next(n) {
        }
    };

    Node *first; // pointer to the first node
};

#endif //CPP_2022_LIST_H