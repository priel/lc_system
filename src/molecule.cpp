#include "molecule.h"

molecule::molecule(vector loc, vector orient) : m_location(loc), m_orientation(orient)
{}

molecule::~molecule()
{
    delete m_location;
    delete m_orientation;
}
