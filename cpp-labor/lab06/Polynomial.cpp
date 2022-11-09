//
// Created by beder on 2022. 10. 27..
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree+1;
    this->coefficients = new double [capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double [capacity];
    for (int i = 0; i < capacity; ++i) {
        coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = new double [capacity];
    for (int i = 0; i < capacity; ++i) {
        coefficients[i] = that.coefficients[i];
    }
    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete [] coefficients;
}

int Polynomial::degree() const {
    return this->capacity-1;
}

double Polynomial::evaluate(double x) const {
    double horner = coefficients[0];
    for (int i = 0; i < capacity; ++i) {
        horner = (horner * x) + coefficients[i];
    }
    return horner;
}

Polynomial Polynomial::derivative() const {
    int temp = capacity;
    Polynomial derPoly(capacity-1, coefficients);

    for (int i = 0; i < capacity; ++i) {
        derPoly.coefficients[i] = coefficients[i] * temp;
        temp--;
    }
    return derPoly;
}

double Polynomial::operator[](int index) const {
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial minusPoly(a.capacity, a.coefficients);
    for (int i = 0; i < a.capacity; ++i) {
        minusPoly.coefficients[i] = -a.coefficients[i];
    }
    return minusPoly;
}