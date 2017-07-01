#include <iostream>
#include <mol_sys.h>
#include <molecule.h>
#include <defined.h>

using namespace std;

int main(int argc, char* argv[])
{
    #if DEBUG != 1
        if (argc < 2) {
            // Tell the user how to run the program
            std::cerr << "Usage: " << argv[0] << " <config_file> where the config should contain the configuration for the running system." << std::endl;
            return 1;
        }
        std::cout << argv[0] << "says hello, " << argv[1] << "!" << std::endl;
        return 0;
    #else
        /// here we just want to do some basic configuration for debug.
        /// lets try with simple 3x3 2d.

        /* Mol_Sys(double* sys_sizes, int dimensions, Molecule *mols, int max_mol,
                double std_loc, double std_spin, double *temp_range, int temp_size, int steps); */

        int dimensions = 2, max_mol = 9, temp_size = 5, steps = 10;
        double std_loc = 1, std_spin = 1;

        double* sys_size = new double [dimensions];
        double* temp_range = new double [temp_size];

        sys_size[0] = 5;
        sys_size[1] = 5;

        temp_range[0] = 10;
        temp_range[1] = 8;
        temp_range[2] = 7;
        temp_range[3] = 5;
        temp_range[4] = 2;

        // allocate max_mol molecules and call default constructor on all of them.
        Molecule *mols = new Molecule[max_mol];

        std::vector <double> loc(dimensions);
        std::vector <double> spin(dimensions);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                loc[0] = i;
                loc[1] = j;
                //spin is initialized to zero.
                mols[3*i + j].m_location=loc;
                mols[3*i + j].m_spin=spin;
            }
        }

        Mol_Sys * lc_system = new Mol_Sys(sys_size,dimensions,mols,max_mol,std_loc,std_spin,temp_range,temp_size,steps);
        lc_system->init();
        lc_system->start_cooling();
        delete lc_system;

    #endif // DEBUG
}
/// after a bit of investigation, better use only vectors and not arrays.
/// should convert all arrays into vectors.
