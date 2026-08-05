#include "Invoice.h"

short int Invoice::nextInvoiceID = 8001;

Invoice::Invoice(double amt)
{
    invoiceID = nextInvoiceID++;
    amount = amt;
    isPaid = false;
}

short int Invoice::getInvoiceID()
{
    return invoiceID;
}
double Invoice::getAmount()
{
    return amount;
}
bool Invoice::getStatus()
{
    return isPaid;
}
void Invoice::markPaid()
{
    isPaid = true;
}

Invoice::~Invoice() {}
