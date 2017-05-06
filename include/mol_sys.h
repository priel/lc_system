#ifndef MOL_SYS_H
#define MOL_SYS_H

#include <molecule.h>

class mol_sys
{
    public:

        /** the default constructor will do everything by itself.
        will create a Gaussian distribution where the STD and expected is given. **/

        mol_sys();

        /** this is some kind of custom constructor where all the parameters are pre-defined.**/
        mol_sys(double* sys_sizes, int dimensions, molecule *mols, int max_mol,
                double *temp_range, int temp_size, int steps);

        /** the destructor will delete all the data here and all the molecules. */
        ~mol_sys();

        double* m_size; //array in the length of dimensions which determine the x,y,(z) of the system.
        int m_dimensions;

        molecule *m_molecules;
        int m_max_molecule;

        double m_potential; // hold the current system total potential

        double **m_pair_potential; // have all the pairs of potential for example pair_potential[0][1] has the potential between molecule 0 and 1.

        double *m_temp_range; //hold the range of temperature we want to check (Starting from 0 to max_temp -1;
        int m_temp_size;
        int m_current_index_temp;

        int m_steps; // number of steps to do in each temperature



        /** the public functions: */
        void init();

        void start_cooling();

        void monte_carlo();

    protected:

    private:
};

#endif // MOL_SYS_H
