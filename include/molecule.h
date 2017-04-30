#ifndef MOLECULE_H
#define MOLECULE_H


class molecule
{
    public:

        molecule(vector loc, vector orient);

        /** Default destructor
         the destructor will always delete the vectors */
        virtual ~molecule();

        virtual double potential();

        vector m_location;

        vector m_orientation;


    protected:

    private:
};

#endif // MOLECULE_H
