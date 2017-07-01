#ifndef LC_MOL_H
#define LC_MOL_H

#include <molecule.h>


class LC_Mol : public Molecule
{
    public:
        LC_Mol();

        LC_Mol(std::vector<double> loc, std::vector<double> spin): Molecule(loc,spin){};

        virtual ~LC_Mol();

        virtual double potential();

    protected:

    private:

};

#endif // LC_MOL_H
