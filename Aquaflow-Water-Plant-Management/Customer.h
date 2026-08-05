#include <iostream>
#include <iomanip>
#include "Customer.h"

short int Customer::nextCustomerID = 1001;

Customer::Customer(string n, string p, string a, string pl, int bottles)
    : Person(n, p, a)
{
    customerID = nextCustomerID++;
    plan = pl;
    bottlesPerDelivery = bottles;
    isActive = true;
    emptyBottlesHeld = 0;
    balance = 0.0;
}

Customer::Customer(int id, const string& n, const string& p, const string& a,
                    const string& pl, int bottles, int empties, double bal)
    : Person(n, p, a),
      customerID(id), plan(pl),
      bottlesPerDelivery(bottles), isActive(true),
      emptyBottlesHeld(empties), balance(bal) {}

short int Customer::getID() const
{
    return customerID;
}
string Customer::getPlan() const
{
    return plan;
}
short int Customer::getBottlesPerDelivery() const
{
    return bottlesPerDelivery;
}
bool Customer::getStatus() const
{
    return isActive;
}
short int Customer::getEmptyBottles() const
{
    return emptyBottlesHeld;
}
double Customer::getBalance() const
{
    return balance;
}

void Customer::addBalance(double b)
{
    balance += b;
}
void Customer::payBalance(double b)
{
    balance -= b;
}
void Customer::addEmptyBottles(int b)
{
    emptyBottlesHeld += b;
}
void Customer::removeEmptyBottles(int b)
{
    emptyBottlesHeld -= b;
}
void Customer::setActive(bool s)
{
    isActive = s;
}

void Customer::display() const
{
    using namespace std;
    cout << left
         << setw(6)  << customerID
         << setw(15) << name
         << setw(15) << phone
         << setw(20) << address
         << setw(10) << plan
         << setw(8)  << bottlesPerDelivery
         << setw(8)  << emptyBottlesHeld
         << setw(10) << (isActive ? "Active" : "Inactive")
         << setw(10) << fixed << setprecision(2) << balance << endl;
}
