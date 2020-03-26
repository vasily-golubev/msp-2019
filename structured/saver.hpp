#ifndef SAVER
#define SAVER

#include <fstream>

#include "../core/basesaver.hpp"
#include "rectgrid.hpp"

class Saver: public BaseSaver
{
  public:
    const char *getName();

    Saver(){};
    void save(RectGrid& grid);
};

#endif // SAVER
