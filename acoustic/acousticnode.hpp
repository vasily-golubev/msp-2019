#ifndef ACOUSTIC_NODE
#define ACOUSTIC_NODE

#include "../core/vector.hpp"

class AcousticNode : public BaseObject
{
  public:
    AcousticNode()
    {
      this->u = Vector();
      // todo: rewrite the init values
      this->u.initValues(2);
    }
    double setPressure(double p) {
      return p;
    }
    double pressure() {
      return 1;
    }
    
    Vector& getVector() {
      return this->u;
    }
    ~AcousticNode() {}
    const char *getName();
  private:
    Vector u;


};

#endif // ACOUSTIC_NODE
