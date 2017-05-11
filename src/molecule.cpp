#include "molecule.h"


Molecule::Molecule(std::vector<double> loc, std::vector<double> spin)
                    : m_location(loc), m_spin(spin){}
Molecule::Molecule(){}

Molecule::~Molecule(){}

double Molecule::potential(Molecule mol)
{
    return 2.0;
}
