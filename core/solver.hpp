#ifndef SOLVER
#define SOLVER

#include "baseobject.hpp"
#include "../structured/rectgrid.hpp"
#include <iostream>

using namespace std;

class Solver: public BaseObject
{
    private:
        RectGrid grid;
    public:
        Solver(RectGrid &rg);
        void step();
        void stepX();
        void stepY();
};

#endif // SOLVER