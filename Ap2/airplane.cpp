#include "airplane.h"
#include <iostream>
using namespace std;

int Airplane::getRunwayNumber() const
{
    return runwayNumber;
}

void Airplane::setRunwayNumber(int value)
{
    runwayNumber = value;
}

string Airplane::getName() const
{
    return name;
}

void Airplane::setName(const string &value)
{
    name = value;
}

Airplane::Airplane(int runwayNumber, string name)
{
    this->runwayNumber = runwayNumber;
    this->name = name;
}
