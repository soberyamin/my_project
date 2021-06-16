#include "airport.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;


bool isInVector(string s, vector<string> vec) {
    for(unsigned long long int j = 0; j < vec.size(); j++) {
        if(s == vec[j]) {
            return true;
        }
    }
    return false;
}

int Airport::getNumberOfFlights() const
{
    return numberOfFlights;
}

void Airport::setNumberOfFlights(int value)
{
    numberOfFlights = value;
}

void Airport::addAirPlane()
{
    string model = "";
    int size = 0;
    cout << "Enter the Model's name: ";
    cin >> model;
    cout << "Enter the plane size: ";
    cin >> size;
    Airplane plane(size, model);
    airplanes.push_back(plane);

}

void Airport::addRunway()
{
    int number = 0;
    cout << "Enter runway number: ";
    cin >> number;
    for(unsigned long long int i = 0; i < runways.size(); i++) {
        if(number == runways[i].getNumber()){
            cout << "runway already exist.\n";
            return;
        }
    }
    int capacity = 0;
    cout << "Enter the runway capacity: ";
    cin >> capacity;
    Runway r;
    r.setNumber(number);
    r.setCapacity(capacity);

    runways.push_back(r);
}

void Airport::printRunways()
{
    cout << "Number\t\tCapacity\n";
    for(unsigned long long int i = 0; i < runways.size(); i++) {
        cout << runways[i].getNumber() << "\t\t" << runways[i].getCapacity() << endl;
    }
}

Flight *Airport::searchById(int id)
{
    Flight* p = first;

    while(p->getId() != id) {
        p = p->next;
        if(p == nullptr) {
            cout << "Id is not valid.\n";
            return nullptr;
        }
    }
    return p;
}

Flight *Airport::searchByNumber(int number)
{
    Flight* p = first;

    while(p->getFlight_number() != number) {
        p = p->next;
        if(p == nullptr) {
            cout << "Id is not valid.\n";
            return nullptr;
        }
    }
    return p;
}

Flight *Airport::isInFlightList(Flight *first, Flight *f)
{
    if(first != nullptr){
        Flight* p = first;

        while(p->next != nullptr) {
            if(p->getFlight_number() == f->getFlight_number()) {
                return p;
            }
            p = p->next;
        }

        return nullptr;
    }
    return nullptr;
}

Airport::Airport()
{
    this->numberOfFlights = 0;
}

void Airport::insert(Flight* f)
{
    Flight* p = first;
    int rwm = 0; // f runway minimum capacity
    bool capacityFound = false;
    bool added = false;
    Flight* temp = isInFlightList(first, f);

    if(temp == nullptr) {
        for(unsigned long long int i = 0; i < airplanes.size(); i++) {
            if(f->getModel() == airplanes[i].getName()) {
                rwm = airplanes[i].getRunwayNumber();
                break;
            }
        }
        do {
            for(unsigned long long int i = 0; i < runways.size(); i++) {
                if(runways[i].getCapacity() >= rwm) {
                    capacityFound = true;
                    if(!isInVector(f->getTime(), runways[i].times)) {
                        f->setRunway(runways[i].getNumber());
                        runways[i].times.push_back(f->getTime());
                        added = true;
                        break;
                    }
                }
            }
            if(capacityFound && !added) {
                std::string t = f->getTime();

                int m = ((t[3] - '0') * 10) + (t[4] - '0');
                int h = ((t[0] - '0') * 10) + (t[1] - '0');
                h = h + floor((m + 30) / 60.0);
                m = (m + 30)%60;
                t = to_string(h) + ':' + to_string(m);

                f->setTime(t);
            }
            if(!capacityFound) {
                cout << "There are no runways for your plane.\n";
                return;
            }
        }while (!added);
    }
    else {
        f->setRunway(temp->getRunway());
    }

    if(first == nullptr) {
        first = f;
        first->next = nullptr;
    }
    else {

        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = f;
    }
    numberOfFlights++;
    return;
}

void Airport::deleteFlight(int number)
{

    if(first->getFlight_number() == number) {
       Flight* p = first;
       first = first->next;
       delete p;
    }
    else {
        Flight* p = first;
        Flight* h = first->next;

        while(h->getFlight_number() != number) {
            p = p->next;
            h = h->next;
            if(h == nullptr) {
                cout << "Number is not valid to delete.\n";
                return;
            }
        }
        p->next = h->next;
        h->next = nullptr;
        delete h;
    }
}

void Airport::sort()
{
    Flight temp("","","",0,0,0);
    if(numberOfFlights) {
       Flight *current = first;

       while(current != nullptr){
           Flight *j = current->next;

           while(j != nullptr) {
               if(current->getTime() > j->getTime()) {
                   temp = *current;
                   *current = *j;
                   *j = temp;
               }
               j = j->next;
           }
           current = current->next;
       }
    }
}

void Airport::print(int runway)
{
    cout << left
         << setw(10)
         << "id"
         << left
         << setw(10)
         << "Flight NO."
         << left
         << setw(10)
         << "Time"
         << left
         << setw(5)
         << "Type"
         << left
         << setw(5)
         << "Model"
         << left
         << setw(10)
         << "Runway"
         << endl;

    this->sort();
    Flight* p = first;
    if(runway == 0) {
        while(p != nullptr) {
            cout
                    << left
                    << setw(10)
                    << p->getId()
                    << left
                    << setw(10)
                    << p->getFlight_number()
                    << left
                    << setw(10)
                    << p->getTime()
                    << left
                    << setw(5)
                    << p->getType()
                    << left
                    << setw(5)
                    << p->getModel()
                    << left
                    << setw(10)
                    << p->getRunway()
                    << endl;
            p = p->next;
        }

    }

    else {
        while(p != nullptr && p->getRunway() == runway) {
            cout
                    << left
                    << setw(10)
                    << p->getId()
                    << left
                    << setw(5)
                    << p->getFlight_number()
                    << left
                    << setw(8)
                    << p->getTime()
                    << left
                    << setw(5)
                    << p->getType()
                    << left
                    << setw(5)
                    << p->getModel()
                    << left
                    << setw(10)
                    << p->getRunway()
                    << endl;
            p = p->next;
        }

    }
}

void Airport::listPlanes()
{
    cout << "Name\t\tMin Runway\n";
    for(unsigned long long int i = 0; i < airplanes.size(); i++) {
        cout << airplanes[i].getName() << "\t\t" << airplanes[i].getRunwayNumber() << endl;
    }
}

