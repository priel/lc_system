#ifndef COL_MOL_H
#define COL_MOL_H

#include <molecule.h>


class col_mol : public molecule
{
    public:

        col_mol(vector loc, vector orient): molecule(loc,orient);

        virtual ~col_mol();

        virtual double potential();

    protected:

    private:
};

#endif // COL_MOL_H
