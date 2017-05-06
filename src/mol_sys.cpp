#include "mol_sys.h"

mol_sys::mol_sys(double* sys_sizes, int dimensions, molecule *mols, int max_mol,
                double *temp_range, int temp_size, int steps):

mol_sys::mol_sys()
{
    //ctor
}

mol_sys::~mol_sys()
{
    //dtor
}
void monte_carlo()
{
        /**for each step:
        choose molecule randomly
        change location and spin with gauss distribution
        calculate dE
        if dE<0 take the stpe
        if not take the step with probability of e^-dE/Kb*T */

        srand(time(NULL));
        int i=0;
        for (i=0;i<m_steps;i++)
        {
            //choose molecule:
            mol_chosen = rand() % molecule_sys.;
        }
}

