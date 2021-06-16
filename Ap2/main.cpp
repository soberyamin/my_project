#include <iostream>
#include <vector>
#include "airport.h"
#include <iomanip>

using namespace std;


// Menu Function Prototype

void menu();
void addFlight();
void searchFlight();
void deleteFlight();
void sortFlightByDate();
void showFlights();
void exitApp();


// Global Variables

Airport airport;

int main()
{
    menu();
    return 0;
}

void menu() {
    int cmd = 0;

    while(1){
        cout << "---Isfahan Air---\n";
        cout << "1. Add Air Plane\n";
        cout << "2. Add Flight\n";
        cout << "3. Search Flight\n";
        cout << "4. Delete Flight\n";
        cout << "5. Sort Flight by Date\n";
        cout << "6. Show Flights\n";
        cout << "7. Add runway\n";
        cout << "8. Show planes\n";
        cout << "9. Show Airplanes\n";
        cout << "10. Exit\n";
        cout << ">>> ";
        cin >> cmd;
        cin.sync();

        switch (cmd) {
        case 1:
            airport.addAirPlane();
            break;
        case 2:
            addFlight();
            break;
        case 3:
            searchFlight();
            break;
        case 4:
            deleteFlight();
            break;
        case 5:
            sortFlightByDate();
            break;
        case 6:
            showFlights();
            break;
        case 7:
            airport.addRunway();
            break;
        case 8:
            airport.printRunways();
            cout << endl;
            system("pause");
            break;
        case 9:
            airport.listPlanes();
            cout << endl;
            system("pause");
            break;
        case 10:
            exitApp();
            break;
        default:
            break;
        }
        system("cls");
    }
}


void addFlight()
{
    Flight* f = new Flight();
    airport.insert(f);
}

void searchFlight()
{
    int cmd = 0;
    cout << "Search by:\n1. ID\n2. Number\n";
    cin >> cmd;
    int n = 0;
    Flight *f;
    if(cmd == 1) {
        cout << "Enter ID: ";
        cin >> n;
         f = airport.searchById(n);
    }
    else if(cmd == 2) {
        cout << "Enter Number: ";
        cin >> n;
        f = airport.searchByNumber(n);
    }
    else {
        return;
    }
    if(f != nullptr) {
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
             << setw(10)
             << "Type"
             << left
             << setw(10)
             << "Model"
             << left
             << setw(10)
             << "Runway"
             << endl;
        cout
                << left
                << setw(10)
                << f->getId()
                << left
                << setw(10)
                << f->getFlight_number()
                << left
                << setw(10)
                << f->getTime()
                << left
                << setw(10)
                << f->getType()
                << left
                << setw(10)
                << f->getModel()
                << left
                << setw(10)
                << f->getRunway()
                << endl;
    }

    system("pause");
    system("cls");

}

void deleteFlight()
{
    int number = 0;
    cout << "Enter the flight number : ";
    cin >> number;
    airport.deleteFlight(number);
}

void sortFlightByDate()
{
    airport.sort();
}
void showFlights()
{
    int rn = 0;
    cout << "Enter the runway Number: - (0 for all) - ";
    cin >> rn;

    airport.print(rn);
    cout << endl;
    system("pause");
    system("cls");
}
void exitApp()
{
    exit(0);
}
