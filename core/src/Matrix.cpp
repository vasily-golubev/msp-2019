#include "../Matrix.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Matrix:: Matrix object
 * 
 */
Matrix::Matrix() {
  for (int i = 0; i < MAXLEN; i++)
    for (int j = 0; j < MAXLEN; j++)
      this->matrix[i][j] = 0;
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
        this->matrix[i][j] = initVal;
      }

      if (diagonal == false) {
        this->matrix[i][j] = initVal;
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
      cout << this->matrix[i][j] << " ";
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
      mSum.matrix[i][j] = this->matrix[i][j] +
                          m2.matrix[i][j];
  return mSum;
}
