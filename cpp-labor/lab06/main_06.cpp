#include <iostream>

#include "Polynomial.h"
int main() {
    double polyn[] = {3, 2, 1};
    Polynomial polynomial(2, polyn);
    cout << polynomial.evaluate(2);
    return 0;
}