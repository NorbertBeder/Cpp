//
// Created by beder on 2022. 12. 14..
//

#include "myifstream.h"

myifstream::myifstream(const string &filename) : ifstream(filename){

}

int myifstream::filesize() {
    int position = tellg();
    seekg(0, ios::end);
    int length = tellg();
    seekg(position, ios::beg);
    return length;
}

char myifstream::operator[](int index) {
    seekg(index, ios::beg);

    return get();
}
