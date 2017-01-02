//
// Created by LoveStu on 2017/1/2.
//

#include "polynomial.h"
#include <new>
#include <cassert>
#include <iostream>

Polynomial::Polynomial(int maxSize)
    : mySize(maxSize)
{
    myVar = new(std::nothrow) double[mySize];
    assert(myVar != 0);
    myCoe = new(std::nothrow) int[mySize];
    assert(myCoe != 0);
}

Polynomial::~Polynomial()
{
    delete[] myVar;
    delete[] myCoe;
}

void Polynomial::read(std::istream &in)
{
    std::cout << "Please input the variables:\n";
    for (int i = 0; i != mySize; ++i)
        in >> myVar[i];
    std::cout << "Please input the coefficients:\n";
    for (int i = 0; i != mySize; ++i)
        in >> myCoe[i];
}

std::istream & operator>>(std::istream &in, Polynomial &pol)
{
    pol.read(in);
    return in;
}

void Polynomial::display(std::ostream &out) const
{
    out << "The polynomial is:\n";
    out << myVar[0];
    if (myCoe[0] == 0)
        ;
    else if (myCoe[0] == 1)
        out << "x";
    else
        out << "x^" << myCoe[0];
    int i = 1;
    while (i != mySize)
    {
        out << (myVar[i] > 0 ? "+" : "") << myVar[i] << "x";
        if (myCoe[i] != 1)
            out << "^" << myCoe[i];
        else
            ;
        ++i;
    }
}

std::ostream & operator<<(std::ostream &out, const Polynomial &pol)
{
    pol.display(out);
    return out;
}

Polynomial::Polynomial(const Polynomial &pol)
    : mySize(pol.mySize)
{
    myVar = new(std::nothrow) double[mySize];
    myCoe = new(std::nothrow) int[mySize];

    if (myVar != 0 && myCoe != 0)
    {
        for (int i = 0; i != mySize; ++i)
        {
            myVar[i] = pol.myVar[i];
            myCoe[i] = pol.myCoe[i];
        }
    }
    else
    {
        std::cerr << "*** Invalid Allocate! ***" << std::endl;
        exit(1);
    }
}

Polynomial& Polynomial::operator=(const Polynomial &rhs)
{
    if (this != &rhs)
    {
        if (mySize != rhs.mySize)
        {
            delete[] myVar;
            delete[] myCoe;

            mySize = rhs.mySize;
            myVar = new(std::nothrow) double[mySize];
            myCoe = new(std::nothrow) int[mySize];
            if (myVar == 0 || myCoe == 0)
            {
                std::cerr << "*** Invalid Allocate! ***" << std::endl;
                exit(1);
            }
        }
        for (int i = 0; i != mySize; ++i)
        {
            myVar[i] = rhs.myVar[i];
            myCoe[i] = rhs.myCoe[i];
        }
    }
    return *this;
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs)
{
    int size = lhs.mySize + rhs.mySize;
    Polynomial pol(size);
    int i = 0, j = 0, k = 0;
    while (i != lhs.mySize && j != rhs.mySize)
    {
        if (lhs.myCoe[i] < rhs.myCoe[j])
        {
            pol.myCoe[k] = lhs.myCoe[i];
            pol.myVar[k] = lhs.myVar[i];
            ++i;
            ++k;
        }
        else if (lhs.myCoe[i] > rhs.myCoe[j])
        {
            pol.myCoe[k] = rhs.myCoe[j];
            pol.myVar[k] = rhs.myVar[j];
            ++j;
            ++k;
        }
        else
        {
            pol.myCoe[k] = lhs.myCoe[i];
            pol.myVar[k] = lhs.myVar[i] + rhs.myVar[j];
            ++i;
            ++j;
            ++k;
        }
    }
    if (i == lhs.mySize)
        for (; j != rhs.mySize; ++j)
        {
            pol.myVar[k] = rhs.myVar[j];
            pol.myCoe[k] = rhs.myCoe[j];
            ++k;
        }
    if (j == rhs.mySize)
        for (; i != rhs.mySize; ++i)
        {
            pol.myVar[k] = lhs.myVar[i];
            pol.myCoe[k] = lhs.myCoe[i];
            ++k;
        }

    if (size== k)
        return pol;
    else
    {
        Polynomial res(k);
        for (int i = 0; i != k; ++i)
        {
            res.myVar[i] = pol.myVar[i];
            res.myCoe[i] = pol.myCoe[i];
        }
        return res;
    }
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs)
{
    assert(lhs.mySize <= rhs.mySize);
    Polynomial result(rhs.mySize);
    for (int i = 0; i != rhs.mySize; ++i)
    {
        result.myVar[i] = lhs.myVar[0] * rhs.myVar[i];
        result.myCoe[i] = lhs.myCoe[0] + rhs.myCoe[i];
    }
    for (int i = 1; i != lhs.mySize; ++i)
    {
        Polynomial temp(rhs.mySize);
        for (int j = 0; j != rhs.mySize; ++j)
        {
            temp.myVar[j] = lhs.myVar[i] * rhs.myVar[j];
            temp.myCoe[j] = lhs.myCoe[i] + rhs.myCoe[j];
        }
        result = result + temp;
    }
    return result;
}