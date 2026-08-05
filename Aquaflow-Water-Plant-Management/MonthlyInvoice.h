#include <iostream>
#include <iomanip>
#include "MonthlyInvoice.h"

using namespace std;

MonthlyInvoice::MonthlyInvoice(int cid, string name, int bottles, double amt)
    : Invoice(amt)
{
    customerID   = cid;
    customerName = name;
    totalBottles = bottles;
}

void MonthlyInvoice::generateBill()
{
    cout << "\n===== MONTHLY CUSTOMER INVOICE =====\n";
    cout << "Invoice ID    : " << invoiceID    << endl;
    cout << "Customer      : " << customerName << endl;
    cout << "Customer ID   : " << customerID   << endl;
    cout << "Total Bottles : " << totalBottles << endl;
    cout << "Amount Due    : Rs. " << fixed << setprecision(2) << amount << endl;
    cout << "Status        : " << (isPaid ? "PAID" : "UNPAID") << endl;
}
