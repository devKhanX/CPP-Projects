#include <iostream>
#include <iomanip>
#include "BulkOrderInvoice.h"

using namespace std;

BulkOrderInvoice::BulkOrderInvoice(int vid, string name, string type, int qty, double amt)
    : Invoice(amt)
{
    vendorID    = vid;
    vendorName  = name;
    productType = type;
    quantity    = qty;
}

void BulkOrderInvoice::generateBill()
{
    cout << "\n===== VENDOR ORDER INVOICE =====\n";
    cout << "Invoice ID   : " << invoiceID   << endl;
    cout << "Vendor       : " << vendorName  << endl;
    cout << "Vendor ID    : " << vendorID    << endl;
    cout << "Product      : " << productType << endl;
    cout << "Quantity     : " << quantity    << endl;
    cout << "Total Amount : Rs. " << fixed << setprecision(2) << amount << endl;
    cout << "Status       : " << (isPaid ? "PAID" : "UNPAID") << endl;
}
