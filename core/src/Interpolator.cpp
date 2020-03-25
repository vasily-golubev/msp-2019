#include "../Interpolator.hpp"

const char *Interpolator::getName() {
  return "Interpolator";
}

double Interpolator::linear(int xl, int xr, int x0, int wl, int wr)
{
    double a = (wr - wl) / (xr - xl);
    double b = wr - a * xr;
    return x0 * a + b;
}
