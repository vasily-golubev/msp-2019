#ifndef RECT_GRID
#define RECT_GRID

#include <iostream>

#include "../core/baseobject.hpp"

using namespace std;

class RectGrid : public BaseObject
{
public:
  RectGrid() : dx(0), dy(0), nx(0), ny(0), ox(0), oy(0) {}
  ~RectGrid() {}
  const char *getName();
  float getDx() const { return dx; }
  float getDy() const { return dy; }
  unsigned long getNx() const { return nx; }
  unsigned long getNy() const { return ny; }
  void stepX() {}
  void stepY() {}
private:
  float dx;
  float dy;
  unsigned long nx;
  unsigned long ny;
  float ox;
  float oy;
};

#endif // RECT_GRID
