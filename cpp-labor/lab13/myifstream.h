//
// Created by beder on 2022. 12. 14..
//

#ifndef CPP_2022_MYIFSTREAM_H
#define CPP_2022_MYIFSTREAM_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class myifstream : public ifstream {

public:
    myifstream(const string &filename);

    int filesize();

    char operator[](int index);
};


#endif //CPP_2022_MYIFSTREAM_H
