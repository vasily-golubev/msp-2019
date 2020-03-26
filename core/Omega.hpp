#ifndef OMEGA
#define OMEGA

#include "baseobject.hpp"
#include "matrix.hpp"

// default matrix size to be used
#define MAXLEN 3

class Omega: public Matrix {
  public:
    double rho, c;
    const char *getName();
    Omega(double rho, double c);
    Matrix OmegaX();
    Matrix OmegaY();
    Matrix OmegaY_Inv();
    Matrix OmegaX_Inv();
};

#endif // OMEGA
