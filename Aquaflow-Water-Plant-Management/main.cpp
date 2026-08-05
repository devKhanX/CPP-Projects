#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Customer.h"
#include "Vendor.h"
#include "Employee.h"
#include "DeliveryBoy.h"
#include "Order.h"
#include "InsufficientStockException.h"
#include "Inventory.h"
#include "Invoice.h"
#include "MonthlyInvoice.h"
#include "BulkOrderInvoice.h"
#include "ProfitAnalysis.h"
#include "FileManager.h"
#include "Utils.h"

using namespace std;

int main()
{
    vector<Customer>    customers;
    vector<Vendor>      vendors;
    vector<Order>       orders;
    vector<DeliveryBoy> staff;
    Inventory           inventory;

    FileManager::loadCustomers(customers);
    FileManager::loadVendors(vendors);
    FileManager::loadOrders(orders);
    FileManager::loadStaff(staff);
    FileManager::loadInventory(inventory);

    int choice;

    do
    {
        clearScreen();
        showAlerts(customers, orders, inventory);

        cout << "\n===== AQUAFLOW WATER PLANT MANAGEMENT =====\n";
        cout << "1. Customer Management\n";
        cout << "2. Vendor Management\n";
        cout << "3. Order Management\n";
        cout << "4. Inventory Management\n";
        cout << "5. Invoices & Billing\n";
        cout << "6. Profit & Reports\n";
        cout << "7. Delivery Staff\n";
        cout << "8. Save & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            int ch;
            do {
                clearScreen();
                cout << "\n--- Customer Menu ---\n";
                cout << "1. Add Customer\n";
                cout << "2. View All Customers\n";
                cout << "3. View Active Customers\n";
                cout << "4. Deactivate Customer\n";
                cout << "5. Record Payment\n";
                cout << "6. Back\n";
                ch = readInt("Choice: ");

                if (ch == 1)
                {
                    string name, phone, address, plan;
                    int bottles;
                    cout << "Name: ";    getline(cin, name);
                    cout << "Phone: ";   getline(cin, phone);
                    cout << "Address: "; getline(cin, address);
                    cout << "Plan (DAILY/WEEKLY/CUSTOM): "; getline(cin, plan);
                    bottles = readInt("Bottles per delivery: ");
                    customers.emplace_back(name, phone, address, plan, bottles);
                    cout << "Customer added! ID: " << customers.back().getID() << "\n";
                    pressEnter();
                }
                else if (ch == 2 || ch == 3)
                {
                    cout << left
                         << setw(6)  << "ID"
                         << setw(15) << "Name"
                         << setw(15) << "Phone"
                         << setw(20) << "Address"
                         << setw(10) << "Plan"
                         << setw(8)  << "Bottles"
                         << setw(8)  << "Empty"
                         << setw(10) << "Status"
                         << setw(10) << "Balance"
                         << endl;
                    cout << string(102, '-') << endl;
                    for (const auto& c : customers)
                        if (ch == 2 || c.getStatus()) c.display();
                    pressEnter();
                }
                else if (ch == 4)
                {
                    int id = readInt("Enter Customer ID to deactivate: ");
                    bool found = false;
                    for (auto& c : customers)
                        if (c.getID() == id) { c.setActive(false); found = true; break; }
                    cout << (found ? "Customer deactivated.\n" : "ID not found.\n");
                    pressEnter();
                }
                else if (ch == 5)
                {
                    int id = readInt("Enter Customer ID: ");
                    bool found = false;
                    for (auto& c : customers)
                        if (c.getID() == id)
                        {
                            found = true;
                            cout << "Current balance: Rs. " << fixed << setprecision(2) << c.getBalance() << "\n";
                            double amt = readDouble("Payment amount: ");
                            c.payBalance(amt);
                            cout << "Payment recorded. New balance: Rs. " << c.getBalance() << "\n";
                            break;
                        }
                    if (!found) cout << "Customer not found.\n";
                    pressEnter();
                }
            } while (ch != 6);
        }

        else if (choice == 2)
        {
            int ch;
            do
            {
                clearScreen();
                cout << "\n--- Vendor Menu ---\n";
                cout << "1. Add Vendor\n";
                cout << "2. View Vendors\n";
                cout << "3. Back\n";
                ch = readInt("Choice: ");

                if (ch == 1)
                {
                    string name, phone, address, shop, area;
                    cout << "Name: ";      getline(cin, name);
                    cout << "Phone: ";     getline(cin, phone);
                    cout << "Address: ";   getline(cin, address);
                    cout << "Shop Name: "; getline(cin, shop);
                    cout << "Area: ";      getline(cin, area);
                    vendors.emplace_back(name, phone, address, shop, area);
                    cout << "Vendor added! ID: " << vendors.back().getID() << "\n";
                    pressEnter();
                }
                else if (ch == 2)
                {
                    cout << left
                         << setw(6)  << "ID"
                         << setw(15) << "Name"
                         << setw(15) << "Phone"
                         << setw(20) << "Address"
                         << setw(15) << "Shop"
                         << setw(15) << "Area"
                         << endl;
                    cout << string(86, '-') << endl;
                    for (const auto& v : vendors) v.display();
                    pressEnter();
                }
            } while (ch != 3);
        }

        else if (choice == 3)
        {
            int ch;
            do
            {
                clearScreen();
                cout << "\n--- Order Menu ---\n";
                cout << "1. Place New Order\n";
                cout << "2. View All Orders\n";
                cout << "3. Mark Order as Delivered\n";
                cout << "4. Back\n";
                ch = readInt("Choice: ");

                if (ch == 1)
                {
                    int buyerID = readInt("Buyer ID (Customer or Vendor): ");
                    string buyerName;
                    cout << "Buyer Name: "; getline(cin, buyerName);

                    cout << "Product type:\n  1. 19L\n  2. 500ML\n  3. 1500ML\n";
                    int pt = readInt("Choice: ");
                    string type  = (pt == 1) ? "19L" : (pt == 2) ? "500ML" : "1500ML";
                    double price = (type == "19L")    ? inventory.getPrice19L()
                                 : (type == "500ML")  ? inventory.getPrice500ml()
                                 :                      inventory.getPrice1500ml();

                    int qty = readInt("Quantity: ");
                    string date;
                    cout << "Date (YYYY-MM-DD): "; getline(cin, date);

                    try
                    {
                        if      (type == "19L")    inventory.dispatch19L(qty);
                        else if (type == "500ML")  inventory.dispatch500ml(qty);
                        else                       inventory.dispatch1500ml(qty);

                        orders.emplace_back(buyerID, buyerName, type, qty, price, date);
                        cout << "Order placed! ID: " << orders.back().getOrderID()
                             << "  Total: Rs. " << fixed << setprecision(2)
                             << orders.back().getTotal() << "\n";

                        for (auto& c : customers)
                            if (c.getID() == buyerID) { c.addBalance(orders.back().getTotal()); break; }
                    }
                    catch (const InsufficientStockException& e)
                    {
                        cout << "[!] Stock error: " << e.what() << "\n";
                    }
                    pressEnter();
                }
                else if (ch == 2)
                {
                    cout << left
                         << setw(6)  << "ID"
                         << setw(15) << "Name"
                         << setw(8)  << "BuyerID"
                         << setw(8)  << "Type"
                         << setw(6)  << "Qty"
                         << setw(10) << "Price"
                         << setw(10) << "Total"
                         << setw(12) << "Status"
                         << setw(12) << "Date"
                         << endl;
                    cout << string(87, '-') << endl;
                    for (const auto& o : orders) o.display();
                    pressEnter();
                }
                else if (ch == 3)
                {
                    int id = readInt("Enter Order ID to mark delivered: ");
                    bool found = false;
                    for (auto& o : orders)
                        if (o.getOrderID() == id)
                        {
                            o.setStatus("DELIVERED");
                            found = true;
                            cout << "Order " << id << " marked as DELIVERED.\n";
                            break;
                        }
                    if (!found) cout << "Order ID not found.\n";
                    pressEnter();
                }
            } while (ch != 4);
        }

        else if (choice == 4)
        {
            int ch;
            do
            {
                clearScreen();
                cout << "\n--- Inventory Menu ---\n";
                cout << "1. View Stock\n";
                cout << "2. Add 19L Bottles (Full)\n";
                cout << "3. Add 500ml Cases\n";
                cout << "4. Add 1.5L Cases\n";
                cout << "5. Receive Empty 19L Bottles\n";
                cout << "6. Refill Empty 19L Bottles\n";
                cout << "7. Back\n";
                ch = readInt("Choice: ");

                if      (ch == 1)
                {
                    inventory.display(); pressEnter();
                }
                else if (ch == 2)
                {
                    inventory.add19L(readInt("Quantity: "));
                    cout << "Updated.\n";  pressEnter();
                }
                else if (ch == 3)
                {
                    inventory.add500ml(readInt("Cases: "));
                    cout << "Updated.\n";  pressEnter();
                }
                else if (ch == 4)
                {
                    inventory.add1500ml(readInt("Cases: "));
                    cout << "Updated.\n";  pressEnter();
                }
                else if (ch == 5)
                {
                    inventory.receiveEmpty19L(readInt("Qty: "));
                    cout << "Received.\n"; pressEnter();
                }
                else if (ch == 6)
                {
                    inventory.refill19L(readInt("Qty to refill: ")); pressEnter();
                }
            } while (ch != 7);
        }

        else if (choice == 5)
        {
            int ch;
            do
            {
                clearScreen();
                cout << "\n--- Invoices & Billing ---\n";
                cout << "1. Generate Monthly Invoice for Customer\n";
                cout << "2. Generate Vendor Bulk Order Invoice\n";
                cout << "3. Back\n";
                ch = readInt("Choice: ");

                if (ch == 1)
                {
                    int id = readInt("Customer ID: ");
                    bool found = false;
                    for (const auto& c : customers)
                        if (c.getID() == id)
                        {
                            found = true;
                            MonthlyInvoice inv(c.getID(), c.getName(),
                                               c.getBottlesPerDelivery() * 30,
                                               c.getBalance());
                            inv.generateBill();
                            break;
                        }
                    if (!found) cout << "Customer not found.\n";
                    pressEnter();
                }
                else if (ch == 2)
                {
                    int id = readInt("Vendor ID: ");
                    bool found = false;
                    for (const auto& v : vendors)
                        if (v.getID() == id)
                        {
                            found = true;
                            string type;
                            int qty;
                            double price;
                            cout << "Product type (19L/500ML/1500ML): "; getline(cin, type);
                            qty   = readInt("Quantity: ");
                            price = readDouble("Price per unit: ");
                            BulkOrderInvoice inv(v.getID(), v.getName(), type, qty, qty * price);
                            inv.generateBill();
                            break;
                        }
                    if (!found) cout << "Vendor not found.\n";
                    pressEnter();
                }
            } while (ch != 3);
        }

        else if (choice == 6)
        {
            clearScreen();
            ProfitAnalysis::generateReport(orders, inventory);
            cout << "\nRevenue by type:\n";
            cout << "  19L    : Rs. " << fixed << setprecision(2) << ProfitAnalysis::revenueByType(orders, "19L")    << "\n";
            cout << "  500ML  : Rs. " << ProfitAnalysis::revenueByType(orders, "500ML")  << "\n";
            cout << "  1500ML : Rs. " << ProfitAnalysis::revenueByType(orders, "1500ML") << "\n";
            pressEnter();
        }

        else if (choice == 7)
        {
            int ch;
            do
            {
                clearScreen();
                cout << "\n--- Delivery Staff Menu ---\n";
                cout << "1. Add Delivery Boy\n";
                cout << "2. View All Staff\n";
                cout << "3. Assign Area\n";
                cout << "4. Record Delivery\n";
                cout << "5. Back\n";
                ch = readInt("Choice: ");

                if (ch == 1)
                {
                    string name, phone, addr, area;
                    double sal;
                    cout << "Name: ";    getline(cin, name);
                    cout << "Phone: ";   getline(cin, phone);
                    cout << "Address: "; getline(cin, addr);
                    sal = readDouble("Salary: ");
                    cout << "Area: ";    getline(cin, area);
                    staff.emplace_back(name, phone, addr, sal, area);
                    cout << "Staff added! ID: " << staff.back().getEmployeeID() << "\n";
                    pressEnter();
                }
                else if (ch == 2)
                {
                    if (staff.empty())
                    {
                        cout << "No staff records.\n"; pressEnter();
                        continue;
                    }
                    cout << left
                         << setw(6)  << "ID"
                         << setw(15) << "Name"
                         << setw(15) << "Phone"
                         << setw(20) << "Address"
                         << setw(15) << "Area"
                         << setw(10) << "Salary"
                         << setw(10) << "Deliveries"
                         << endl;
                    cout << string(91, '-') << endl;
                    for (const auto& d : staff) d.display();
                    pressEnter();
                }
                else if (ch == 3)
                {
                    int id = readInt("Employee ID: ");
                    bool found = false;
                    for (auto& d : staff)
                        if (d.getEmployeeID() == id)
                        {
                            found = true;
                            string area;
                            cout << "New area: "; getline(cin, area);
                            d.assignArea(area);
                            cout << "Area updated.\n";
                            break;
                        }
                    if (!found) cout << "Employee not found.\n";
                    pressEnter();
                }
                else if (ch == 4)
                {
                    int id = readInt("Employee ID: ");
                    bool found = false;
                    for (auto& d : staff)
                        if (d.getEmployeeID() == id)
                        {
                            d.increaseDelivery();
                            found = true;
                            cout << "Delivery recorded. Total: " << d.getDeliveryCount() << "\n";
                            break;
                        }
                    if (!found) cout << "Employee not found.\n";
                    pressEnter();
                }
            } while (ch != 5);
        }

        else if (choice == 8)
        {
            FileManager::saveCustomers(customers);
            FileManager::saveVendors(vendors);
            FileManager::saveOrders(orders);
            FileManager::saveStaff(staff);
            FileManager::saveInventory(inventory);
            cout << "All data saved. Goodbye!\n";
        }

    } while (choice != 8);

    return 0;
}
