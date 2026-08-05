#include <iostream>
#include <iomanip>
#include "ProfitAnalysis.h"

using namespace std;

void ProfitAnalysis::generateReport(vector<Order>& orders, Inventory& inv)
{
    double revenue19L  = 0;
    double revenue500  = 0;
    double revenue1500 = 0;
    double costTotal   = 0;

    for (int i = 0; i < (int)orders.size(); i++)
    {
        if (orders[i].getStatus() != "DELIVERED") continue;
        string type = orders[i].getType();
        int    qty  = orders[i].getQuantity();
        double total= orders[i].getTotal();

        if      (type == "19L")
        {
            revenue19L  += total; costTotal += qty * inv.getCost19L();
        }
        else if (type == "500ML")
        {
            revenue500  += total; costTotal += qty * inv.getCost500ml();
        }
        else if (type == "1500ML")
        {
            revenue1500 += total; costTotal += qty * inv.getCost1500ml();
        }
    }

    double totalRevenue = revenue19L + revenue500 + revenue1500;
    double netProfit    = totalRevenue - costTotal;

    cout << "\n========== PROFIT REPORT ==========\n";
    cout << fixed << setprecision(2);
    cout << "Revenue from 19L Bottles : Rs. " << revenue19L  << endl;
    cout << "Revenue from 500ml Packs : Rs. " << revenue500  << endl;
    cout << "Revenue from 1.5L Packs  : Rs. " << revenue1500 << endl;
    cout << "----------------------------------\n";
    cout << "Total Revenue            : Rs. " << totalRevenue << endl;
    cout << "Total Production Cost    : Rs. " << costTotal    << endl;
    cout << "----------------------------------\n";
    cout << "Net Profit               : Rs. " << netProfit    << endl;
}

double ProfitAnalysis::revenueByType(vector<Order>& orders, string type)
{
    double total = 0;
    for (int i = 0; i < (int)orders.size(); i++)
        if (orders[i].getStatus() == "DELIVERED" && orders[i].getType() == type)
            total += orders[i].getTotal();
    return total;
}
