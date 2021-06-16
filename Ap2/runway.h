#ifndef RUNWAY_H
#define RUNWAY_H
#include <string>
#include <vector>
using namespace std;

class Runway
{
    int capacity;

    int number;

public:
    vector<std::string> times;
    Runway();
    int getCapacity() const;
    void setCapacity(int value);
    int getNumber() const;
    void setNumber(int value);
};

#endif // RUNWAY_H
