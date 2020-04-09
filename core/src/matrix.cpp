#include "../matrix.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Get class name.
 *
 * @return const char* 
 */
const char *Matrix::getName() {
  return "Matrix";
}

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

/**
 * @brief Overload the << operator to display the matrix
 *
 * @param os
 * @param m Matrix
 * @return ostream&
 */
ostream& operator<<(ostream &os, const Matrix& m) {
  for (int i = 0; i < MAXLEN; i++){
    for (int j = 0; j < MAXLEN; j++)
      os << m.data[i][j] << " ";
    os << endl;
  }
  return os;
}

/**
 * @brief Overload the * operator, matrix multiplicatin.
 *
 * @param m2
 * @return Matrix
 */
Matrix Matrix::operator*(const Matrix &m2) const {
  Matrix m;

  for (int k=0; k<MAXLEN; k++)
    for (int i=0; i<MAXLEN; i++)
      for (int j=0; j<MAXLEN; j++)
        m.data[k][i] += this->data[k][j] * m2.data[j][i];

  return m;
}

/**
 * @brief Overload the * operator, matrix by vector.
 *
 * @param v1
 * @return Vector
 */
Vector Matrix::operator*(const Vector &v1) const {
  Vector v;

  for (int k = 0; k < MAXLEN; k++)
    for (int j = 0; j < MAXLEN; j++)
      v.data[k] += this->data[k][j] * v1.data[j];

  return v;
}
