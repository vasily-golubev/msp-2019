#include "../Vector.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Vector:: Vector object
 * 
 */
Vector::Vector()
{
  for (int i = 0; i < MAXLEN; i++)
    this->vector[i] = 0;
}

/**
 * @brief Store the init_val in the vector. 
 * 
 * @param init_val the value to be stored
 */
void Vector::initValues(double initVal)
{
  for (int i = 0; i < MAXLEN; i++)
    this->vector[i] = initVal;
}

/**
 * @brief Display the vector data.
 * 
 */
void Vector::displayVector()
{
  for (int i = 0; i < MAXLEN; i++)
    cout << this->vector[i] << endl;
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
    vSum.vector[i] = this->vector[i]+
                     v2.vector[i];
  return vSum;
}