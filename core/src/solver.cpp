#include "../solver.hpp"

using namespace std;

Solver::Solver(RectGrid &rg) : grid(rg) {
    //this->grid = rg; // Impossible!
};

void Solver::stepX() {
    for (int i = 0; i < this->grid.getNy(); i++) {
        for (int j = 0; j < this->grid.getNx(); j++) {
            AcousticNode& n = this->grid.getAcousticNode(i, j);
        }
    }
}

void Solver::stepY() {}

void Solver::step() {
    this->stepX();
    this->stepY();
}

