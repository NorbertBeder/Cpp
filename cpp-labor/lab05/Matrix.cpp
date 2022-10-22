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

Matrix::Matrix(const Matrix &what) : mRows(what.mRows), mCols(what.mCols) {
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) : mRows(what.mRows), mCols(what.mCols) {
    mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
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
    Matrix m(x.getRows(), x.getCols());
    m.fillMatrix(0);
    try {
        if (x.getCols() != y.getCols() || x.getRows() != y.getRows()) {
            throw out_of_range("Matrices don't have the same dimensions.");
        }
        for (int i = 0; i < x.getRows(); ++i) {
            for (int j = 0; j < x.getCols(); ++j) {
                m.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    return m;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix m(x.getRows(), y.getCols());
    m.fillMatrix(0);
    try {
        if (x.getCols() != y.getRows()) {
            throw out_of_range("e");
        }
        for (int i = 0; i < x.getRows(); ++i) {
            for (int j = 0; j < y.getCols(); ++j) {
                for (int k = 0; k < x.getCols(); ++k) {
                    m.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
                }
            }
        }
    } catch (out_of_range &e) {
        cout << "Matrices don't have the proper dimensions." << endl;
    }
    return m;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this == &mat) {
        return *this;
    }
    try {
        if (mRows!= mat.mRows || mCols != mat.mCols) {
            throw out_of_range("Matrices don't have the same dimensions.");
        }
        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = new double *[mRows];
        for (int i = 0; i < mRows; ++i) {
            mElements[i] = new double[mCols];
        }
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
    } catch (out_of_range &e) {
        cout << e.what()<< endl;
    }
        return *this;
    }

Matrix &Matrix::operator=(Matrix &&mat)  noexcept {
    if (this != &mat) {
        delete[] mElements;
        mElements = mat.mElements;
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
    }
    return *this;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

double *Matrix::operator[](int index) {
    return mElements[index];
}





