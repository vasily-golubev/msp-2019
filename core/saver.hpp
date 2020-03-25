#ifndef SAVER
#define SAVER

#include <fstream>

#include "basesaver.hpp"
#include "../structured/rectgrid.hpp"

class Saver: public BaseSaver
{
  public:
    const char *getName();

    void save(RectGrid& grid);
};

#endif // SAVER
