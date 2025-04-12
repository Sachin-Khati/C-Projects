#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ParkingSystem
{
private:
    int capacity;
    int occupied;

public:
    ParkingSystem(int cap)
    { // constructor
        capacity = cap;
        occupied = 0;
    }

    bool parkCar()
    {
        if (occupied < capacity)
        {
            occupied++;
            cout << "Car parked successfully." << endl;
            return true;
        }
        else
        {
            cout << "Parking lot is full. Cannot park car." << endl;
            return false;
        }
    }

    void removeCar()
    {
        if (occupied > 0)
        {
            occupied--;
            cout << "Car removed from parking lot." << endl;
        }
        else
        {
            cout << "Parking lot is already empty." << endl;
        }
    }

    void displayAvailableSpaces()
    {
        int available = capacity - occupied;
        cout << "Available parking spaces: " << available << endl;
    }
};

int main()
{
    // Creating a parking lot with capacity of 10 cars
    ParkingSystem parkingLot(10);

    int choice;
    do
    {
        cout << "\nCar Parking System" << endl;
        cout << "1. Park Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. Display Available Spaces" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            parkingLot.parkCar();
            break;
        case 2:
            parkingLot.removeCar();
            break;
        case 3:
            parkingLot.displayAvailableSpaces();
            break;
        case 4:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
