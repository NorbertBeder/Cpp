#include <iostream>
#include "myifstream.h"
#include "Huffman.h"

using namespace std;

int main() {
//    myifstream f("be.txt");
//    if (!f){
//        cout << "File not found." << endl;
//        exit(1);
//    }
//    for( int i=0; i <f.filesize(); ++i){
//        cout << f[i];
//    }
//    cout << endl;

    Huffman huffman("Huffman.txt");
    return 0;
}