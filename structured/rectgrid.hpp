#ifndef RECT_GRID
#define RECT_GRID

#include <iostream>

#include "../core/baseobject.hpp"
#include "../acoustic/acousticnode.hpp"

using namespace std;

class RectGrid : public BaseObject
{
public:
  RectGrid() : dx(0), dy(0), nx(0), ny(0), ox(0), oy(0) {
    data = NULL;
  }
  ~RectGrid() {
    if (data) {
      for (int i = 0; i < ny; i++)
        delete [] data[i];
      delete [] data;
    }
  }
  void allocateMemory() {
    data = new AcousticNode*[ny];
    for (int i = 0; i < ny; i++)
      data[i] = new AcousticNode[nx];
  }
  const char *getName();
  float getDx() const { return dx; }
  float getDy() const { return dy; }
  unsigned long getNx() const { return nx; }
  unsigned long getNy() const { return ny; }
  void stepX() {}
  void stepY() {}
  void setNx(unsigned long n) { nx = n; }
  void setNy(unsigned long n) { ny = n; }
private:
  float dx;
  float dy;
  unsigned long nx;
  unsigned long ny;
  float ox;
  float oy;
  AcousticNode **data;
};

#endif // RECT_GRID
