#include <iostream>
#include <iomanip>
#include "DeliveryBoy.h"

DeliveryBoy::DeliveryBoy(string n, string p, string a, double s, string area)
    : Employee(n, p, a, s)
{
    assignedArea = area;
    deliveryCount = 0;
}

DeliveryBoy::DeliveryBoy(int id, const string& n, const string& p, const string& a,
                          double s, const string& area, int dc)
    : Employee(id, n, p, a, s), assignedArea(area), deliveryCount(dc) {}

string DeliveryBoy::getArea() const
{
    return assignedArea;
}
short int DeliveryBoy::getDeliveryCount() const
{
    return deliveryCount;
}

void DeliveryBoy::assignArea(const string& area)
{
    assignedArea = area;
}
void DeliveryBoy::increaseDelivery()
{
    deliveryCount++;
}

void DeliveryBoy::display() const
{
    using namespace std;
    cout << left
         << setw(6)  << employeeID
         << setw(15) << name
         << setw(15) << phone
         << setw(20) << address
         << setw(15) << assignedArea
         << setw(10) << fixed << setprecision(2) << salary
         << setw(10) << deliveryCount << endl;
}

DeliveryBoy::~DeliveryBoy() {}
