#ifndef COL_MOL_H
#define COL_MOL_H

#include <molecule.h>


class col_mol : public molecule
{
    public:

        col_mol(std::vector<double> loc, std::vector<double> spin, double depth, double length): molecule(loc,spin,depth,length){};

        virtual ~col_mol();

        virtual double potential();

    protected:

    private:
};

#endif // COL_MOL_H
