#include <iostream>
#include <iomanip>
#include "Vendor.h"

short int Vendor::nextVendorID = 2001;

Vendor::Vendor(string n, string p, string a, string shop, string ar)
    : Person(n, p, a)
{
    vendorID = nextVendorID++;
    shopName = shop;
    area = ar;
}

Vendor::Vendor(int id, const string& n, const string& p, const string& a,
               const string& shop, const string& ar)
    : Person(n, p, a), vendorID(id), shopName(shop), area(ar) {}

short int Vendor::getID() const
{
    return vendorID;
}
string Vendor::getShopName() const
{
    return shopName;
}
string Vendor::getArea() const
{
    return area;
}

void Vendor::display() const
{
    using namespace std;
    cout << left
         << setw(6)  << vendorID
         << setw(15) << name
         << setw(15) << phone
         << setw(20) << address
         << setw(15) << shopName
         << setw(15) << area << endl;
}
