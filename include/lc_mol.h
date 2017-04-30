#ifndef LC_MOL_H
#define LC_MOL_H

#include <molecule.h>


class lc_mol : public molecule
{
    public:
        lc_mol(vector loc, vector orient) : molecule(loc,orient);

        virtual ~lc_mol();

        virtual double potential();

    protected:

    private:

};

#endif // LC_MOL_H
