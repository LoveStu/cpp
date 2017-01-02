//
// Created by LoveStu on 2017/1/2.
//
#include <iostream>
#ifndef NEW_POL_POLYNOMIAL_H
#define NEW_POL_POLYNOMIAL_H

class Polynomial
{
    friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);
    friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);
public:
    Polynomial(int maxSize = 10);
    Polynomial(const Polynomial &pol);
    Polynomial &operator=(const Polynomial &rhs);

    ~Polynomial();
    void display(std::ostream &out) const;
    void read(std::istream &in);

private:
    double *myVar;      //系数
    int    *myCoe;      //阶数
    int     mySize;     //一共几项
};

std::istream & operator>>(std::istream &in, Polynomial &pol);
std::ostream & operator<<(std::ostream &out, const Polynomial &pol);
Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);
Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);
#endif //NEW_POL_POLYNOMIAL_H
