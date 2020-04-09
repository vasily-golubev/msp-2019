#include <iostream>
#include "../omega.hpp"

using namespace std;
/**
 * @brief Get class name.
 *
 * @return const char*
 */
const char *Omega::getName() {
    return "Omega";
}

/**
 * @brief Construct a new Omega:: Omega object
 *
 * @param rho
 * @param c
 */
Omega::Omega(double rho, double c) {
    this->rho = rho;
    this->c   = c;
}

/**
 * @brief Calculate OmegaX
 *
 * @return Matrix
 */
Matrix Omega::OmegaX() {
    this->initValues(0);

    this->data[0][1] = -1/(rho*c);
    this->data[0][2] = 1/(rho*c);
    this->data[1][0] = 1;
    this->data[2][1] = 1;
    this->data[2][2] = 1;

    return *this;
}

/**
 * @brief Calculate OmegaY
 *
 * @return Matrix
 */
Matrix Omega::OmegaY() {
    this->initValues(0);

    this->data[0][0] = 1;
    this->data[1][1] = -1/(rho*c);
    this->data[1][2] = 1/(rho*c);
    this->data[2][1] = 1;
    this->data[2][2] = 1;

    return *this;
}

/**
 * @brief Inverse OmegaY matrix.
 *
 * @return Matrix
 */
Matrix Omega::OmegaY_Inv() {
    this->initValues(0);

    this->data[0][0] = 1;
    this->data[1][1] = -(rho*c)/2;
    this->data[1][2] = 0.5;
    this->data[2][1] = (rho*c)/2;
    this->data[2][2] = 0.5;

    return *this;
}

/**
 * @brief Inverse OmegaX matrix.
 *
 * @return Matrix
 */
Matrix Omega::OmegaX_Inv() {
    this->initValues(0);

    this->data[0][1] = 1;
    this->data[1][0] = -(rho * c) / 2;
    this->data[1][2] = 0.5;
    this->data[2][0] = (rho * c) / 2;
    this->data[2][2] = 0.5;

    return *this;
}
