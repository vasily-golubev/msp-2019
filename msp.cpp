#include <iostream>

#include "./core/basesaver.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "This program calculates wave propagation in acoustic media." << endl;
  BaseSaver bs1;
  cout << bs1.getName() << endl;
  bs1.save();
  return 0;
}
