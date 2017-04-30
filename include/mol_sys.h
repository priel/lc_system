#ifndef MOL_SYS_H
#define MOL_SYS_H

#include <molecule.h>

class mol_sys
{
    public:
        /** Default constructor */
        mol_sys(int tot_mol);
        /** Default destructor */
        ~mol_sys();
        /** Copy constructor
         *  \param other Object to copy from
         */
        mol_sys(const mol_sys& other);

        molecule *molecules;
        unsigned int max_molecule;

        double sys_potential; // hold the current system total potential
        double **pair_potential; // have all the pairs of potential for example pair_potential[0][1] has the potential between molecule 0 and 1.

        double *temp_range; //hold the range of temperature we want to check (Starting from 0 to max_temp -1;
        unsigned int max_temp;
        int current_index_temp;

        unsigned int steps; // number of steps to do in each temperature


    protected:

    private:
};

#endif // MOL_SYS_H
