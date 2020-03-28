#include <iostream>

#include "./core/basesaver.hpp"
#include "./core/matrix.hpp"
#include "./core/omega.hpp"
#include "./core/vector.hpp"
#include "./core/interpolator.hpp"

#include "./structured/saver.hpp"
#include "./structured/rectgrid.hpp"
#include "./structured/initial.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Please, specify the name of the config file as: ./msp my_task.cfg" << endl;
    return 2;
  }
  cout << "This program calculates wave propagation in acoustic media." << endl;
  // Config cfg(argv[1]);
  // Solver solver(cfg);
  // Saver saver(cfg);
  unsigned long steps = 101; // Bring from cfg like stoul(cfg.get("steps"));
  for (unsigned long i = 0; i < steps; i++) {
    cout << "Step: " << i << endl;
    //saver.save();
    //solver->step();
  }
  Interpolator s1;
  cout << s1.linear(10, 20, 15, 40, 80) << endl;
  //BaseSaver bs1;
  //cout << bs1.getName() << endl;
  //bs1.save();
  Matrix m1;
  Vector v1;

  // SAVING TEST
  RectGrid rg1;
  rg1.setNx(1000);
  rg1.setNy(1200);
  rg1.setDx(1);
  rg1.setDy(1);
  rg1.allocateMemory();
  for(int i = 0; i < rg1.getNx(); i++){
      for(int j = 0; j < rg1.getNy(); j++){
          rg1.getAcousticNode(i, j).setPressure(i*j);
      }
  }
  Initial::init(rg1, 500, 500, 400, 1500000);
  Initial::init(rg1, 100, 100, 200, 700000);
  Saver saver_rg;
  saver_rg.save(rg1);

  cout << "Program finished." << endl;
  return 0;
}
