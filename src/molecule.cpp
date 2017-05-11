#include "molecule.h"
//
molecule::molecule(std::vector<double> loc, std::vector<double> spin, double depth, double length)
                    : m_location(loc), m_spin(spin), m_d(depth), m_l(length){}

molecule::~molecule()
{

}
/**
molecule& molecule::operator= (const molecule & other)
{
    if (this != &other) // protect against invalid self-assignment
    {
            m_location = other.m_location;
            m_spin = other.m_spin;
            m_l = other.m_l;
            m_d = other.m_d;
    }
    // by convention, always return *this
    return *this;
} */ //not sure we need this.

virtual double molecule::potential(molecule mol)
{
    return 2.0;
}
