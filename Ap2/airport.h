#ifndef AIRPORT_H
#define AIRPORT_H

#include"flight.h"
#include<vector>
#include"airplane.h"
#include "runway.h"


class Airport
{

private:
    Flight * first;
    int numberOfFlights;

public:
    Airport();
    vector<Airplane> airplanes;
    vector<Runway> runways;
    void insert(Flight *f);
    void deleteFlight(int number);
    void sort();
    void print(int runway);
    int getNumberOfFlights() const;
    void setNumberOfFlights(int value);
    void addAirPlane();
    void addRunway();
    void listPlanes();
    void printRunways();
    Flight *searchById(int id);
    Flight *searchByNumber(int number);

    static Flight *isInFlightList(Flight *first, Flight*);


};

#endif // AIRPORT_H


