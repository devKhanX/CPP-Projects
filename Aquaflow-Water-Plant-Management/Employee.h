#include <iostream>
#include <iomanip>
#include "Employee.h"

short int Employee::nextEmployeeID = 3001;

Employee::Employee(string n, string p, string a, double s)
    : Person(n, p, a)
{
    employeeID = nextEmployeeID++;
    salary = s;
}

Employee::Employee(int id, const string& n, const string& p, const string& a, double s)
    : Person(n, p, a), employeeID(id), salary(s) {}

short int Employee::getEmployeeID() const
{
    return employeeID;
}
double Employee::getSalary() const
{
    return salary;
}
void Employee::setSalary(double s)
{
    salary = s;
}

void Employee::display() const
{
    using namespace std;
    cout << left
         << setw(6)  << employeeID
         << setw(15) << name
         << setw(15) << phone
         << setw(10) << fixed << setprecision(2) << salary << endl;
}

Employee::~Employee() {}
