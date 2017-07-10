#include "molecule.h"


Molecule::Molecule(std::vector<double> loc, std::vector<double> spin, Mol_Type mol_type)
                    : m_location(loc), m_spin(spin), m_mol_type(mol_type){}
Molecule::Molecule(){m_mol_type = lc;}  //default molecule is lc

Molecule::~Molecule(){}

double Molecule::potential(const Molecule * mol, const Model * model)
{

    //this is the most performance sensitive. try to be as minimal as possible
    //try to do as much as possible in compile time.
    std::vector <double> r;
    std::vector <double> nr;
    double norm, sigma0, chi, alpha, ;
    r.reserve(DIMENSIONS);
    r[0] = m_location[0] - mol->m_location[0];
    r[1] = m_location[1] - mol->m_location[1];
    #if DIMENSIONS == 3
    r[2] = m_location[2] - mol->m_location[2];
    #endif // DIMENSIONS
    nr.reserve(DIMENSIONS);
    #if DIMENSIONS == 2
    norm = sqrt(r[0]*r[0] + r[1]*r[1]);
    #elif DIMENSIONS == 3
    norm = sqrt(r[0]*r[0] + r[1]*r[1] + r[2]*r[2]);
    #endif // DIMENSIONS
    nr[0] = r[0] / norm;
    nr[1] = r[1] / norm;
    #if DIMENSIONS == 3
    nr[2] = r[2] / norm;
    #endif // DIMENSIONS

    if ((m_mol_type == 0) && (mol.m_mol_type == 0)) // both are LC
    {

    }

    Ugb = self._calculateGBPotential(type1, spin1, type2, spin2, r, nr)

        R = self._calculateR(type1, spin1, type2 ,spin2, r, nr)
        {
            if type1 == 0:
            if type2 == 0:
                sigma0 = self.sigma_00
                chi = self.chi_00
                alpha = self.alpha_00
            else:
                sigma0 = self.sigma_01
                chi = self.chi_01
                alpha = self.alpha_01
        else:
            if type2 == 0:
                sigma0 = self.sigma_01
                chi = self.chi_01
                alpha = 1/self.alpha_01 ## i <--> j equivalent to alpha <--> 1/alpha
            else:
                sigma0 = self.sigma_11
                chi = self.chi_11
                alpha = self.alpha_11

        first = (((alpha * dot(spin1, nr) + (1/alpha) * dot(spin2, nr)) ** 2) /
                 (1.0 + chi * dot(spin1, spin2)))
                second = (((alpha * dot(spin1, nr) - (1/alpha) * dot(spin2, nr)) ** 2) /
                  (1.0 - chi * dot(spin1, spin2)))
            sigma = sigma0 / sqrt(1.0 - chi / 2.0 * (first + second))

            return (sigma0 / (linalg.norm(r) - sigma + sigma0))
        }


        epsilon = self._calculateEpsilon(type1, spin1, type2 ,spin2, nr)
            {
        if type1 == 0:
            if type2 == 0:
                epsilon0 = self.epsilon0_0
                chi = self.chi_00
                alpha_tag = self.alpha_tag_00
                chi_tag = self.chi_tag_00
            else:
                epsilon0 = (self.epsilon0_0 * self.epsilon0_1)**0.5
                chi = self.chi_01
                alpha_tag = self.alpha_tag_01 # symmetric under i <--> j
                chi_tag = self.chi_tag_01
        else:
            if type2 == 0:
                epsilon0 = (self.epsilon0_0 * self.epsilon0_1) ** 0.5
                chi = self.chi_01
                alpha_tag = self.alpha_tag_01
                chi_tag = self.chi_tag_01
            else:
                epsilon0 = self.epsilon0_1
                chi = self.chi_11
                alpha_tag = self.alpha_tag_11
                chi_tag = self.chi_tag_11

        epsilon_ni =  1.0 / sqrt(1.0 - (chi ** 2) * (dot(spin1, spin2) ** 2))

        # calculate epsilon_miu
        first = (((alpha_tag * dot(spin1, nr) + (1/alpha_tag) * dot(spin2, nr)) ** 2) /
                 (1.0 + chi_tag * dot(spin1, spin2)))
        second = (((alpha_tag * dot(spin1, nr) - (1/alpha_tag) * dot(spin2, nr)) ** 2) /
                  (1.0 - chi_tag * dot(spin1, spin2)))
        epsilon_miu =  1.0 - chi_tag / 2.0 * (first + second)


        return (epsilon0 * (epsilon_ni ** self.ni) * (epsilon_miu ** self.miu))
            }

        res = (4 * epsilon * (R ** 12 - R ** 6))

        */

    return 2.0;
}

