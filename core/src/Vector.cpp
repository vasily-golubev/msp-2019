#include "../vector.hpp"
#include <iostream>
using namespace std;


const char *Vector::getName() {
  return "Vector";
}
/**
 * @brief Construct a new Vector:: Vector object
 *
 */
Vector::Vector()
{
  for (int i = 0; i < MAXLEN; i++)
    this->data[i] = 0;
}

/**
 * @brief Store the init_val in the vector.
 *
 * @param init_val the value to be stored
 */
void Vector::initValues(double initVal)
{
  for (int i = 0; i < MAXLEN; i++)
    this->data[i] = initVal;
}

/**
 * @brief Display the vector data.
 *
 */
void Vector::displayVector()
{
  for (int i = 0; i < MAXLEN; i++)
    cout << this->data[i] << endl;
}

/**
 * @brief Overload the "+" operator, define the addition of two matrices.
 *
 * @param m2
 * @return Vector
 */
Vector Vector::operator+(const Vector &v2) const
{
  Vector vSum = Vector();
  for (int i = 0; i < MAXLEN; i++)
    vSum.data[i] = this->data[i]+
                     v2.data[i];
  return vSum;
}
