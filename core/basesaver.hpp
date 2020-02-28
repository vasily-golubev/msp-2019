#ifndef BASE_SAVER
#define BASE_SAVER

#include <iostream>

#include "baseobject.hpp"

using namespace std;

class BaseSaver : public BaseObject
{
public:
  BaseSaver() {}
  ~BaseSaver() {}
  const char *getName();

  void save() { cout << "Saving results ..." << endl; }
};

#endif // BASE_SAVER
