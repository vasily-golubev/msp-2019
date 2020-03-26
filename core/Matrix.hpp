#ifndef MATRIX
#define MATRIX

#include "baseobject.hpp"
#include <iostream>
#include "Vector.hpp"
using namespace std;

// default matrix size to be used
#define MAXLEN 3

class Matrix: public BaseObject
{
  public:
    const char *getName();

    double data[MAXLEN][MAXLEN];

    Matrix();
    void displayMatrix();
    void initValues(double, bool=false);
    Matrix operator+(const Matrix &) const;
    Matrix operator*(const Matrix &) const;
    Vector operator*(const Vector &) const;
};

ostream &operator<<(ostream &os, const Matrix &m);

#endif // MATRIX
