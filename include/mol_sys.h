#ifndef MOL_SYS_H
#define MOL_SYS_H

#include <molecule.h>

class Mol_Sys
{
    public:

        /** the default constructor will do everything by itself.
        will create a Gaussian distribution where the STD and expected is given. **/

        Mol_Sys();

        /** this is some kind of custom constructor where all the parameters are pre-defined.**/
        Mol_Sys(double* sys_sizes, int dimensions, Molecule *mols, int max_mol,
                double std_loc, double std_spin, double *temp_range, int temp_size, int steps);

        /** the destructor will delete all the data here and all the molecules. */
        ~Mol_Sys();

        double* m_sys_sizes; ///array in the length of dimensions which determine the x,y,(z) of the system.
        int m_dimensions;

        Molecule *m_molecules;
        int m_molecules_size;

        double m_potential; /// hold the current system total potential

        double **m_pair_potential; /// have all the pairs of potential for example pair_potential[0][1] has the potential between molecule 0 and 1.
                                   ///the last column has the sum potential of this
        /** example of potentials as a matrix:
            0   1   2   3
        0  N/A 2.0 1.0 2.1
        1  N/A N/A 2.1 1.2
        2  N/A N/A N/A 1.0
        3  5.1 5.3 4.1 4.3  //this hold the sum of all potentials of regarding (summing this will have 2*total molecule size)
        */
        /// We could have saved more memory by defining only the triangle, however it left that way for simplicity of the code.

        double m_gauss_std_loc; ///hold the std to use in monte carlo for the location.
        double m_gauss_std_spin; ///hold the std to use in monte carlo for the spin.


        double *m_temp_range; ///hold the range of temperature we want to check (Starting from 0 to max_temp -1;
        int m_temp_size;
        int m_current_index_temp;

        int m_steps; /// number of steps to do in each temperature



        /** the public functions: */
        void init();

        void start_cooling();

        void monte_carlo(double std_loc, double std_spin);

        void update_sys(Molecule mol_chosen, int index, double* potential, double temp_total_pot);

    protected:

    private:
};

#endif // MOL_SYS_H
