#include "Matrix.h"

int main() {
    Matrix m1(2, 3), m2(2, 3);
    m1.fillMatrix(10);
    m1.printMatrix();

    m2.randomMatrix(10, 20);
    m2.printMatrix();

    if (m1.isSquare()) {
        cout << "The entered array is a square matrix." << endl;
    } else {
        cout << "The entered array is NOT a square matrix." << endl;
    }

    cout << "Matrix m3 = m1 + m2: " << endl;
    Matrix m3 = (m1 + m2);
    m3.printMatrix();


    return 0;
}