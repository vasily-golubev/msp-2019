#ifndef VECTOR
#define VECTOR

#include "baseobject.hpp"
#include <iostream>

using namespace std;
// default vector size to be used
#define MAXLEN 3

class Vector : public BaseObject
{
  public:
    const char *getName();

    double data[MAXLEN];

    Vector();
    void displayVector();
    void initValues(double);
    Vector operator+(const Vector &) const;
};
ostream &operator<<(ostream &os, const Vector &m);

#endif // VECTOR
