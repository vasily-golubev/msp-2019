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
	    if(i > 0 && i < grid.getNx() - 1)
	    {
            	AcousticNode &n_1 = this->grid.getAcousticNode(i - 1,j);
		AcousticNode &n1 = this->grid.getAcousticNode(i + 1,j);
		Vector u = n.getVector();
                Vector u_1 = n_1.getVector();
		Vector u1 = n1.getVector();
		Vector w_1 =u_1 * Omega(rho,c).OmegaX_Inv(); 
		Vector w =u * Omega(rho,c).OmegaX_Inv();
		Vector w1 =u1 * Omega(rho,c).OmegaX_Inv();
            }
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
            if(j > 0 && j < grid.getNy() - 1)
	    {
            	AcousticNode &n_1 = this->grid.getAcousticNode(i,j - 1);
		AcousticNode &n1 = this->grid.getAcousticNode(i,j + 1);
		Vector u = n.getVector();
                Vector u_1 = n_1.getVector();
		Vector u1 = n1.getVector();
		Vector w_1 =u_1 * Omega(rho,c).OmegaY_Inv(); 
		Vector w =u * Omega(rho,c).OmegaY_Inv();
		Vector w1 =u1 * Omega(rho,c).OmegaY_Inv();
            }
        }
    }
}

void Solver::step() {
    this->stepX();
    this->stepY();
}

