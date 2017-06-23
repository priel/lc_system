#include "mol_sys.h"
#include <time.h>
#include <cstdlib>
#include <random>
#include <math.h>

Mol_Sys::Mol_Sys(double* sys_sizes, int dimensions, Molecule *mols, int max_mol,
                 double std_loc, double std_spin, double *temp_range, int temp_size, int steps)
                 :m_sys_sizes(sys_sizes), m_dimensions(dimensions), m_molecules(mols), m_molecules_size(max_mol),
                  m_gauss_std_loc(std_loc), m_gauss_std_spin(std_spin),
                  m_temp_range(temp_range), m_temp_size(temp_size), m_steps(steps) {}


Mol_Sys::Mol_Sys()
{
    //ctor
}


Mol_Sys::~Mol_Sys()
{
    //dtor
    delete[] m_sys_sizes;
    for (int i = 0; i < m_molecules_size; i++)
    {
        delete m_molecules[i];
    }
    delete[] m_molecules;
    delete[] m_temp_range;
    for (int i = 0; i < m_molecules_size; i++)
    {
        delete[] m_pair_potential[i];
    }
    delete[] m_pair_potential;
}

void Mol_Sys :: init()
{
    ///inputs: none
    /// the function update all the pair_potential and the total potential
    for (int i = 0; i < m_molecules_size; i++)
    {
        for (int j = i; j < )
    }
}

double Mol_Sys :: get_all_pair_potential(int index)
{
    //need implementation
}

void Mol_Sys :: update_sys(Molecule mol_chosen, int index, double* potential)
{
    ///inputs:
    /// Molecule mol_chosen: molecule to update.
    /// int index: the index of the molecule to update.
    /// double* potential: an array of all the new pair potential (size of m_molecules_size)
    ///         potential[index] is undefined and should not use!!
    ///
    /// the function update the system with the new vars.


    ///update the molecule
    m_molecules[index] = mol_chosen;

    ///update the pair potential:

    ///update the column:
    for (int i = 0; i < index; i++)
        m_pair_potential[i][index] = potential[i];

    ///update the rows:
    for (int i = index+1; i < m_molecules_size; i++)
        m_pair_potential[index][i]

    /*///update the total potential of the system:
    m_potential -= m_pair_potential[m_molecules_size-1];
    m_potential += temp_total_pot;*/




}

void Mol_Sys :: monte_carlo(double std_loc, double std_spin)
{
    /** for each step:
        choose molecule randomly
        change location and spin with gauss distribution
        calculate dE
        if dE<0 take the step
        if not take the step with probability of e^-dE/Kb*T */

    int i = 0, j = 0; ///iterators for loop
    int num_mol_chosen; //
    double prob;
    double dE;
    Molecule mol_chosen;
    double * potential;
    double potential_size;
    double temp_total_pot = 0;

    ///initiate the random generators:
    srand(time(0));
    std::default_random_engine loc_gen(time(0));
    std::normal_distribution<double> loc_dist(0.0,std_loc);

    std::default_random_engine spin_gen(time(0));
    std::normal_distribution<double> spin_dist(0.0,std_spin);

    /*std::random_device;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0, 1); */

    for (i = 0; i < m_steps; i++)
    {
        ///choose molecule:
        num_mol_chosen = rand() % m_molecules_size;

        ///change location around gauss dist:
        mol_chosen = m_molecules[num_mol_chosen];
        for (j = 0; j < mol_chosen.m_location.size(); j++)
        {
            ///it's actually multivariate normal distribution where E=loc, std=std given, and no correlation between the axis.
            mol_chosen.m_location[j] += loc_dist(loc_gen);
        }

        for (j = 0; j< mol_chosen.m_spin.size(); j++)
        {
            ///it's actually multivariate normal distribution where E=loc, std=std given, and no correlation between the axis.
            mol_chosen.m_spin[j] += spin_dist(spin_gen);
        }

        /// we now have the location vector and the spin vector suggested, now we have to calculate dE for them
        ///since all changed is this 1 molecule we will:
        /// calculate row of for the potential done by this molecule
        potential = new double[m_molecules_size];
        for ( j = 0; j < m_molecules_size; j++)
        {
            if (j==num_mol_chosen) continue;
            potential[j] = mol_chosen.potential(m_molecules[j]);
            temp_total_pot += potential[j];
        }
        if (temp_total_pot <= m_pair_potential[m_molecules_size-1][num_mol_chosen])
        {
            update_sys(mol_chosen, num_mol_chosen, potential, temp_total_pot);
        }
        else
        {
            prob = ((double) rand() / (RAND_MAX))
            dE = get_all_pair_potential(num_mol_chosen) - temp_total_pot;
            if ( prob < exp(dE/(m_temp_range[m_current_index_temp] * k_B))
            {
                update_sys(mol_chosen, num_mol_chosen, potential, temp_total_pot);
            }
        }
        delete [] potential;
        //no need to delete mol_chosen since it wan't created by new it limited to this scope.
    }
}

