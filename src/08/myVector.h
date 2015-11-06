#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
#include <iostream>
#include <random>
#include <math.h>
#include <chrono>

using namespace std;

class MyVector{
    static int  _nDim;
    static bool _bDim;

    vector<double> _data;

public:

    static void nDim(int);
    static int  nDim();
    MyVector();
    
    
    double& operator[](int);
    double operator[](int) const;

    MyVector operator+(const MyVector&) const;
    MyVector operator-(const MyVector&) const;
    MyVector operator*(double) const;
    MyVector operator/(double) const;

    MyVector& operator+=(const MyVector&);
    MyVector& operator-=(const MyVector&);
    MyVector& operator*=(double);

    double module() const;
    double mmodule() const;
    MyVector unit() const;

    void initGauss();
    void reinitial();
    
    friend MyVector operator*(double, const MyVector&);
    friend ostream& operator<<(ostream&, const MyVector&);
};


#endif
