#ifndef SCALE_HPP_INCLUDED
#define SCALE_HPP_INCLUDED
#include "rectgrid.hpp"
#include <cmath>
class Scale
{
public:
    scale()
    {

    }
    void scalegrid(RectGrid origin, float dx, float dy, unsigned long nx, unsigned long ny, float ox, float oy);
    RectGrid get_grid()
    {
        return newRG;
    }
private:
    RectGrid newRG;
};

#endif // SCALE_HPP_INCLUDED
