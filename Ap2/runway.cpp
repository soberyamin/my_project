#include "runway.h"

int Runway::getCapacity() const
{
    return capacity;
}

void Runway::setCapacity(int value)
{
    capacity = value;
}

int Runway::getNumber() const
{
    return number;
}

void Runway::setNumber(int value)
{
    number = value;
}


Runway::Runway()
{

}
