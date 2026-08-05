#include <iostream>
#include <iomanip>
#include "Order.h"

int Order::nextOrderID = 5001;

Order::Order(int bID, string bName, string t, int qty, double price, string d)
{
    orderID = nextOrderID++;
    buyerID = bID;
    buyerName = bName;
    type = t;
    status = "PENDING";
    quantity = qty;
    pricePerUnit = price;
    date = d;
}

Order::Order(int oid, int bID, const string& bName, const string& t,
             const string& st, int qty, double price, const string& d)
    : orderID(oid), buyerID(bID), buyerName(bName),
      type(t), status(st), quantity(qty),
      pricePerUnit(price), date(d) {}

short int Order::getOrderID() const
{
    return orderID;
}
short int Order::getBuyerID() const
{
    return buyerID;
}
string Order::getBuyerName() const
{
    return buyerName;
}
string Order::getType() const
{
    return type;
}
string Order::getStatus() const
{
    return status;
}
int Order::getQuantity() const
{
    return quantity;
}
double Order::getPricePerUnit() const
{
    return pricePerUnit;
}
string Order::getDate() const
{
    return date;
}

double Order::getTotal() const
{
    return quantity * pricePerUnit;
}

void Order::setStatus(string s)
{
    status = s;
}
void Order::setQuantity(int q)
{
    quantity = q;
}

bool Order::operator<(const Order& o)
{
    return date < o.date;
}
bool Order::operator==(const Order& o)
{
    return orderID == o.orderID;
}

void Order::display() const
{
    using namespace std;
    cout << left
         << setw(6)  << orderID
         << setw(15) << buyerName
         << setw(8)  << buyerID
         << setw(8)  << type
         << setw(6)  << quantity
         << setw(10) << fixed << setprecision(2) << pricePerUnit
         << setw(10) << getTotal()
         << setw(12) << status
         << setw(12) << date << endl;
}
