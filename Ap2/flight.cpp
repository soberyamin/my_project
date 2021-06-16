#include "flight.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> ids;

bool isUniqueId(int id) {
    for(unsigned long long int i = 0; i < ids.size(); i++) {
        if(id == ids[i]) {
            return false;
        }
    }
    return true;
}

string Flight::getTime() const
{
    return time;
}

void Flight::setTime(const string &value)
{
    time = value;
}

string Flight::getModel() const
{
    return model;
}

void Flight::setModel(const string &value)
{
    model = value;
}

string Flight::getType() const
{
    return type;
}

void Flight::setType(const string &value)
{
    type = value;
}

int Flight::getPassengers() const
{
    return passengers;
}

void Flight::setPassengers(int value)
{
    passengers = value;
}

int Flight::getRunway() const
{
    return runway;
}

void Flight::setRunway(int value)
{
    runway = value;
}

int Flight::getFlight_number() const
{
    return flight_number;
}

void Flight::setFlight_number(int value)
{
    flight_number = value;
}

int Flight::getId() const
{
    return id;
}

void Flight::setId(int value)
{
    id = value;
}

Flight::Flight()
{
    srand(time_t(NULL));
    string time;
    string model;
    string type;
    int passengers;
    int flight_number;
    int id;

    cout << "Enter Flight time: (HH:MM) " ;
    cin >> time;
    cout << "Enter Flight Model: " ;
    cin >> model;
    cout << "Enter Flight : (in/out) " ;
    cin >> type;
    cout << "Enter Flight passenger count: " ;
    cin >> passengers;
    cout << "Enter Flight number: ";
    cin >> flight_number;
    cout << "Enter Flight id: ";
    cin >> id;

    while(!isUniqueId(id)) {
        cout << "Id " << id << " is not unique please try again...: ";
        cin >> id;
    }
    this->next = nullptr;
    setTime(time);
    setModel(model);
    setType(type);
    setPassengers(passengers);
    setFlight_number(flight_number);
    setId(id);
}

Flight::Flight(string time, string model, string type, int passengers, int flightNumber, int id)
{
    this->next = nullptr;
    setTime(time);
    setModel(model);
    setType(type);
    setPassengers(passengers);
    setFlight_number(flightNumber);
    setId(id);
}
