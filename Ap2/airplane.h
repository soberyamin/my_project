#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
using namespace std;

class Airplane
{
    int runwayNumber;
    string name;
public:
    Airplane(int runwayNumber, string name);
    int getRunwayNumber() const;
    void setRunwayNumber(int value);
    string getName() const;
    void setName(const string &value);
};

#endif // AIRPLANE_H
