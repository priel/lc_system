#ifndef LC_MOL_H
#define LC_MOL_H

#include <molecule.h>


class lc_mol : public molecule
{
    public:
        lc_mol(std::vector<double> loc, std::vector<double> spin, double depth, double length): molecule(loc,spin,depth,length){};

        virtual ~lc_mol();

        virtual double potential();

    protected:

    private:

};

#endif // LC_MOL_H
