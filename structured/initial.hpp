#ifndef INITIAL
#define INITIAL

#include <cmath>

#include "../core/baseobject.hpp"
#include "rectgrid.hpp"

class Initial : public BaseObject
{
  public:
    static void init(RectGrid& grid, unsigned long x0, unsigned long y0, unsigned long radius, float pressure){
        unsigned long Nx = grid.getNx();
        unsigned long Ny = grid.getNy();
        int dx = grid.getDx();
        int dy = grid.getDy();
        for(unsigned long x = 0; x < Nx; x++){
            for(unsigned long y = 0; y < Ny; y++){
                double d = sqrt(dx * dx * (x0 - x) * (x0 - x) +
                                dy * dy * (y0 - y) * (y0 - y));
                if(d > radius){
                    continue;
                }
                grid.getAcousticNode(x, y).setPressure(pressure * exp(-d / radius));
            }
        }
    }

    const char *getName();
};

#endif // INITIAL
