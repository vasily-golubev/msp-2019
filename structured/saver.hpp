#ifndef SAVER
#define SAVER

#include <fstream>

#include "../core/basesaver.hpp"
#include "rectgrid.hpp"

class Saver: public BaseSaver
{
  public:
    const char *getName();

    Saver(){ period = 1; };
    Saver(int period) { this->period = period; }
    void save(RectGrid& grid, int number);
    void setPeriod(int period) { this->period = period; }
  private:
    int period;
    string numberToString(int x);
};

#endif // SAVER
