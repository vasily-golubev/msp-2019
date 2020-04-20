#include "../solver.hpp"
#include "../omega.hpp"

using namespace std;

Solver::Solver(RectGrid &rg) {
    this->grid = rg;
};

void Solver::stepX() {
    for (int i = 0; i < this->grid.getNy(); i++) {
        for (int j = 0; j < this->grid.getNx(); j++) {
            double rho, c;
            rho = 1;
            c = 1;
            AcousticNode& n = this->grid.getAcousticNode(i, j);
            Vector u = n.getVector();
            Matrix om = Omega(rho, c).OmegaX();
        }
    }
}

void Solver::stepY() {
    for (int i = 0; i < this->grid.getNx(); i++)
    {
        for (int j = 0; j < this->grid.getNy(); j++)
        {
            double rho, c;
            rho = 1;
            c = 1;
            AcousticNode &n = this->grid.getAcousticNode(i, j);
            Vector u = n.getVector();
            Matrix om = Omega(rho, c).OmegaY();
        }
    }
}

void Solver::step() {
    this->stepX();
    this->stepY();
}

