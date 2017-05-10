#ifndef MOLECULE_H
#define MOLECULE_H
#include <vector>

class molecule
{
    public:

        molecule(std::vector<double> loc, std::vector<double> spin, double depth, double length );

        /** Default destructor
         the destructor will always delete the vectors */
        virtual ~molecule();

        virtual double potential(molecule mol);

        /** overloading assignment operator */
        //molecule & operator= (const molecule & other);

        std::vector<double> m_location;
        std::vector<double> m_spin;

        double m_d;
        double m_l;


    protected:

    private:
};

#endif // MOLECULE_H
