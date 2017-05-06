#ifndef MOLECULE_H
#define MOLECULE_H
#include <vector>

class molecule
{
    public:

        molecule(std::vector<double> loc, std::vector<double> orient);

        /** Default destructor
         the destructor will always delete the vectors */
        virtual ~molecule();

        virtual double potential();

        std::vector<double> m_location;

        std::vector<double> m_orientation;


    protected:

    private:
};

#endif // MOLECULE_H
