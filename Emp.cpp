#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Employee
{
    string name;
    int age;
    string department;
    double salary;
};
void addEmployee(vector<Employee> &employees)
{
    Employee newEmployee;

    cout << "Enter employee name: ";
    cin.ignore(); // to clear the input buffer
    getline(cin, newEmployee.name);

    cout << "Enter employee age: ";
    cin >> newEmployee.age;

    cout << "Enter employee department: ";
    cin.ignore(); // Clear buffer again before taking a string input
    getline(cin, newEmployee.department);

    cout << "Enter employee salary: ";
    cin >> newEmployee.salary;

    employees.push_back(newEmployee);
    cout << "Employee added successfully!" << endl;
}
void displayEmployees(const vector<Employee> &employees)
{
    cout << "\nEmployee List:\n";

    for (const auto &e : employees)
    {
        cout << "Name: " << e.name << endl;
        cout << "Age: " << e.age << endl;
        cout << "Department: " << e.department << endl;
        cout << "Salary: $" << e.salary << endl;
        cout << "-------------------------" << endl;
    }
}

int main()
{
    vector<Employee> employees;
    int choice;

    do
    {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            displayEmployees(employees);
            break;
        case 3:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
        }
    } while (choice != 3);

    return 0;
}