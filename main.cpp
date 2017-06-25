#include <iostream>
#define DEBUG 1
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

        double* sys_size;
        int dimensions = 2, max_mol = 9, temp_size = 5, steps = 10;
        double std_loc = 1, std_spin = 1;
        double temp_range [5] = {10, 8, 6, 4, 3};
        double size_sys [2] = {5,5};
        Molecule mols [9] = new Molecule[];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mols[0] = new Molecule()
            }
        }

    #endif // DEBUG
}
