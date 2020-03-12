#ifndef MATRIX
#define MATRIX

#include "baseobject.hpp"

// default matrix size to be used
#define MAXLEN 3

class Matrix: public BaseObject
{
  public:
    double data[MAXLEN][MAXLEN];

    Matrix();
    void displayMatrix();
    void initValues(double, bool=false);
    Matrix operator+(const Matrix&) const;
};

#endif
