#include "molecule.h"


Molecule::Molecule(std::vector<double> loc, std::vector<double> spin)
                    : m_location(loc), m_spin(spin){}
Molecule::Molecule(){}

Molecule::~Molecule(){}

double Molecule::potential(const Molecule & mol)
{
    if (typeid(mol) == type)
    return 2.0;
}

