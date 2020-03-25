#ifndef ACOUSTIC_NODE
#define ACOUSTIC_NODE

#include "../core/vector.hpp"

class AcousticNode : public BaseObject
{
  public:
    AcousticNode()
    {
        p = 0;
    }
    ~AcousticNode() {}
    const char *getName();
    float pressure() {
      return p;
    }
    void setPressure(float p){
        this->p = p;
    }
  private:
    Vector v;
    float p;
};

#endif // ACOUSTIC_NODE
