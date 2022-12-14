//
// Created by beder on 2022. 12. 14..
//

#ifndef CPP_2022_HUFFMAN_H
#define CPP_2022_HUFFMAN_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Huffman {
    map<char, int> freqs;

    struct node {
        char data;
        int freq;
        struct node *left, *right;

        explicit node(char data = ' ', int freq = 0, node *left = nullptr, node *right = nullptr) : data(data), freq(freq),
                                                                                           left(left), right(right) {}
    };
    struct CompNode{
        bool operator()(node *n1, node *n2){
            return n1->freq > n2->freq;
        }
    };
    priority_queue<node*, vector<node*>, CompNode> pq;
    void createTree();
    void printCodes(node *root, string code);
    void deleteTree(node *root);

public:
    explicit Huffman(const string &filename);
    ~Huffman();
};


#endif //CPP_2022_HUFFMAN_H
