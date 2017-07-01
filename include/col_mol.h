#ifndef COL_MOL_H
#define COL_MOL_H

#include <molecule.h>


class Col_Mol : public Molecule
{
    public:

        /// when we will want to test different type of the same molecules
        Col_Mol(std::vector<double> loc, std::vector<double> spin): Molecule(loc,spin){};

        Col_Mol();

        virtual ~Col_Mol();

        virtual double potential();

    protected:

    private:
};

#endif // COL_MOL_H
