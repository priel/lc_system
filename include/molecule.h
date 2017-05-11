#ifndef MOLECULE_H
#define MOLECULE_H
#include <vector>

class Molecule
{
    public:

        Molecule();

        Molecule(std::vector<double> loc, std::vector<double> spin);


        /** Default destructor
         the destructor will always delete the vectors */
        virtual ~Molecule();

        virtual double potential(Molecule mol);

        std::vector<double> m_location;
        std::vector<double> m_spin;


    protected:

    private:
};

#endif // MOLECULE_H
