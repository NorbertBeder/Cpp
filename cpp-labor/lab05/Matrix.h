//
// Created by beder on 2022. 10. 19..
//

#ifndef CPP_2022_MATRIX_H
#define CPP_2022_MATRIX_H


#include <iostream>
#include <stdexcept>

using namespace std;
class Matrix {
public:
    Matrix( int mRows = 10, int mCols =10);

    Matrix(const Matrix& what);


    ~Matrix();

    void fillMatrix(double value);

    void randomMatrix(int a, int b);

    void printMatrix(ostream& os = cout) const;

    bool isSquare() const;

    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}

    friend Matrix operator+(const Matrix& x, const Matrix& y);

private:
    double ** mElements;
    int mRows;
    int mCols;
};



#endif //CPP_2022_MATRIX_H
