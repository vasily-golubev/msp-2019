#ifndef ACOUSTIC_NODE
#define ACOUSTIC_NODE

#include "../core/vector.hpp"

class AcousticNode : public BaseObject
{
public:
  AcousticNode() {}
  ~AcousticNode() {}
  const char *getName();
private:
  Vector v;
  float p;
};
#endif // ACOUSTIC_NODE
