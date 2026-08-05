#include <iostream>
#include <cstdlib>
#include "Utils.h"

using namespace std;

void clearScreen()
{
    system("cls");
}

void pressEnter()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void showAlerts(vector<Customer>& customers, vector<Order>& orders, Inventory& inv)
{
    int overdue = 0, empties = 0, pending = 0;

    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i].getBalance()      > 0) overdue++;
        if (customers[i].getEmptyBottles() > 3) empties++;
    }
    for (int i = 0; i < (int)orders.size(); i++)
        if (orders[i].getStatus() == "PENDING") pending++;

    if (overdue > 0) cout << "[!] " << overdue << " customers have overdue balances\n";
    if (empties > 0) cout << "[!] " << empties << " customers holding 4+ empty bottles\n";
    if (inv.getStock19L() < 10) cout << "[!] 19L stock is LOW (" << inv.getStock19L() << " left)\n";
    if (pending > 0) cout << "[!] " << pending << " orders pending delivery\n";
}

int readInt(string prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    cin.ignore();
    return value;
}

double readDouble(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;
    cin.ignore();
    return value;
}
