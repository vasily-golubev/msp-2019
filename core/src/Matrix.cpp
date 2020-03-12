#include "../matrix.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Matrix:: Matrix object
 *
 */
Matrix::Matrix() {
  for (int i = 0; i < MAXLEN; i++)
    for (int j = 0; j < MAXLEN; j++)
      this->data[i][j] = 0;
}


/**
 * @brief Store the init_val in the matrix.
 *
 * @param init_val the value to be stored
 * @param diagonal if true, only the main diagonal will be changed.
 */
void Matrix::initValues(double initVal, bool diagonal) {
  for (int i = 0; i < MAXLEN; i++) {
    for (int j = 0; j < MAXLEN; j++) {
      if (diagonal == true && i == j) {
        this->data[i][j] = initVal;
      }

      if (diagonal == false) {
        this->data[i][j] = initVal;
      }
    }
  }
}


/**
 * @brief Display the matrix data.
 *
 */
void Matrix::displayMatrix() {
  for (int i = 0; i < MAXLEN; i++) {
    for (int j = 0; j < MAXLEN; j++)
      cout << this->data[i][j] << " ";
    cout << endl;
  }
}


/**
 * @brief Overload the "+" operator, define the addition of two matrices.
 *
 * @param m2
 * @return Matrix
 */
Matrix Matrix::operator+ (const Matrix& m2) const {
  Matrix mSum = Matrix();
  for (int i = 0; i < MAXLEN; i++)
    for (int j = 0; j < MAXLEN; j++)
      mSum.data[i][j] = this->data[i][j] +
                          m2.data[i][j];
  return mSum;
}
