//
// Created by beder on 2022. 10. 19..
//

#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
    os << endl;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
            delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::randomMatrix(int a, int b) {

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> distribution(a, b);


    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = distribution(mt);
        }
    }
}

bool Matrix::isSquare() const {
    return mCols == mRows;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    try{
        if(x.getCols() != y.getCols() || x.getRows() != y.getRows()){
            throw out_of_range("Exception");
        }
    } catch(out_of_range) {
        cout << "Matrices don't have the same dimensions." << endl;
    }
    Matrix m(x.getRows(), x.getCols());
    for (int i = 0; i < x.getRows(); ++i) {
        for (int j = 0; j < x.getCols(); ++j) {
            m.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return m;
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double* [what.mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double [what.mCols];
    }
}
