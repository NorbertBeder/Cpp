//
// Created by beder on 2022. 12. 14..
//

#include "Huffman.h"

Huffman::Huffman(const string &filename) {
    ifstream ifs(filename);
    if(!ifs){
        cout << "File not opened." << endl;
        exit(1);
    }
    int c;
    while ((c = ifs.get()) != -1){
        freqs[c]++;
    }
    for(auto it : freqs){
        cout << it.first << ":" << it.second << endl;
    }
    createTree();
    cout << "Total freq : " <<pq.top()->freq << endl;
}


void Huffman::createTree() {
    for (auto &it : freqs){
        pq.push(new node(it.first, it.second));
    }
    while (pq.size() > 1){
        node *n1 = pq.top();
        pq.pop();
        node *n2 = pq.top();
        pq.pop();

        node *n3 = new node(' ', n1->freq + n2->freq, n1, n2);
        pq.push(n3);
    }
}

void Huffman::deleteTree(Huffman::node *root) {
    if(root == nullptr){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

Huffman::~Huffman() {
    node *n = pq.top();
    deleteTree(n);
}

void Huffman::printCodes(Huffman::node *root, string code) {

}





