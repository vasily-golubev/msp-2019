#include <iostream>

#include "./core/basesaver.hpp"

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
  //BaseSaver bs1;
  //cout << bs1.getName() << endl;
  //bs1.save();
  cout << "Program finished." << endl;
  return 0;
}
