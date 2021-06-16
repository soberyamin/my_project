#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include<vector>
using namespace std;

class Flight
{
private:
    string time;
    string model;
    string type;
    int passengers;
    int runway;
    int flight_number;
    int id;

public:
    Flight* next;
    Flight();
    Flight(string, string, string, int, int, int);

    string getTime() const;
    void setTime(const string &value);
    string getModel() const;
    void setModel(const string &value);
    string getType() const;
    void setType(const string &value);
    int getPassengers() const;
    void setPassengers(int value);
    int getRunway() const;
    void setRunway(int value);
    int getFlight_number() const;
    void setFlight_number(int value);
    int getId() const;
    void setId(int value);
};

#endif // FLIGHT_H
