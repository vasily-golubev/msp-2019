#ifndef VECTOR
#define VECTOR

#include "baseobject.hpp"

// default vector size to be used
#define MAXLEN 3

class Vector : public BaseObject
{
public:
  double data[MAXLEN];

  Vector();
  void displayVector();
  void initValues(double);
  Vector operator+(const Vector &) const;
};

#endif
