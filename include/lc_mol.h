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


class Molecule
{
    double someBulshit;
    virutal double Potential(const Molecule & mol);
}

class LC :: Molecule
{
    virtual double Potential(const Molecule & mol)
    {
        if(typeid(mol) ==typeid(LC))
            return 1;// for the example
        return 3;
    }

}
class Col : Molecule
{
    virtual double Potential(Molecule mol)
    {
        if (typeid(mol) == typeid(Col))
            return 2;
        return 3;
    }
}

    int Main(string[] args)
    {
        Molecule mol1 = new Col();
        Molecule mol2 = new LC();

        double my_potential = mol1.Potential(mol2);
        printf ("%f",my_potential);
    }
