#ifndef INTERPOLATOR
#define INTERPOLATOR

#include "baseobject.hpp"

class Interpolator : public BaseObject
{
  public:
    const char *getName();

    double linear(int xl, int xr, int x0, int wl, int wr);
};

#endif // INTERPOLATOR
