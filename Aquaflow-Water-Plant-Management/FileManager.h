#include <fstream>
#include <sstream>
#include <string>
#include "FileManager.h"

using namespace std;

void FileManager::saveCustomers(vector<Customer>& customers)
{
    ofstream file("customers.txt");
    for (int i = 0; i < (int)customers.size(); i++)
        file << customers[i].getID()               << "|"
             << customers[i].getName()             << "|"
             << customers[i].getPhone()            << "|"
             << customers[i].getAddress()          << "|"
             << customers[i].getPlan()             << "|"
             << customers[i].getBottlesPerDelivery()<< "|"
             << customers[i].getEmptyBottles()     << "|"
             << customers[i].getBalance()
             << endl;
    file.close();
}

void FileManager::loadCustomers(vector<Customer>& customers)
{
    ifstream file("customers.txt");
    if (!file)
    {
        customers.push_back(Customer("Ali Hassan",   "0312-1234567", "Saddar",       "DAILY",  2));  customers.back().addBalance(200.00); customers.back().addEmptyBottles(2);
        customers.push_back(Customer("Usman Riaz",   "0333-9876543", "Gulshan",      "WEEKLY", 5));  customers.back().addBalance(500.00); customers.back().addEmptyBottles(5);
        customers.push_back(Customer("Malik Tariq",  "0301-1112233", "Johar Town",   "CUSTOM", 10)); customers.back().addBalance(1000.00);customers.back().addEmptyBottles(1);
        customers.push_back(Customer("Zara Noor",    "0321-5557788", "DHA Phase 5",  "DAILY",  3));  customers.back().addBalance(300.00); customers.back().addEmptyBottles(3);
        customers.push_back(Customer("Bilal Ahmed",  "0345-6669900", "Model Town",   "WEEKLY", 4));  customers.back().addBalance(400.00); customers.back().addEmptyBottles(0);
        customers.push_back(Customer("Hina Shahid",  "0311-2223344", "Faisal Town",  "DAILY",  2));  customers.back().addBalance(0.00);   customers.back().addEmptyBottles(4);
        customers.push_back(Customer("Tariq Mehmood","0300-8887766", "Cantt Area",   "CUSTOM", 8));  customers.back().addBalance(800.00); customers.back().addEmptyBottles(2);
        customers.back().setActive(false);
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, phone, address, plan, temp;
        int id, bottles, empties;
        double balance;
        getline(ss, temp, '|');    id      = stoi(temp);
        getline(ss, name,    '|');
        getline(ss, phone,   '|');
        getline(ss, address, '|');
        getline(ss, plan,    '|');
        getline(ss, temp, '|');    bottles = stoi(temp);
        getline(ss, temp, '|');    empties = stoi(temp);
        getline(ss, temp, '|');    balance = stod(temp);
        Customer c(name, phone, address, plan, bottles);
        c.addEmptyBottles(empties);
        c.addBalance(balance);
        customers.push_back(c);
    }
    file.close();
}

void FileManager::saveVendors(vector<Vendor>& vendors)
{
    ofstream file("vendors.txt");
    for (int i = 0; i < (int)vendors.size(); i++)
        file << vendors[i].getID()       << "|"
             << vendors[i].getName()     << "|"
             << vendors[i].getPhone()    << "|"
             << vendors[i].getAddress()  << "|"
             << vendors[i].getShopName() << "|"
             << vendors[i].getArea()
             << endl;
    file.close();
}

void FileManager::loadVendors(vector<Vendor>& vendors)
{
    ifstream file("vendors.txt");
    if (!file) {
        vendors.push_back(Vendor("Aqib Saleem",  "0321-5556677", "Saddar",      "City Mart",     "Saddar Market"));
        vendors.push_back(Vendor("Umar Farooq",  "0345-8889900", "Gulberg",     "Fresh Store",   "Gulberg Area"));
        vendors.push_back(Vendor("Khalid Bros",  "0300-1112233", "Johar Town",  "Khalid Traders","Johar Town"));
        vendors.push_back(Vendor("Sara Imports", "0333-4445566", "DHA",         "Sara Depot",    "DHA Phase 2"));
        vendors.push_back(Vendor("Rehman & Co",  "0312-7778899", "Cantt",       "Rehman Store",  "Cantt Bazaar"));
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string temp, name, phone, address, shop, area;
        int id;
        getline(ss, temp,    '|'); id = stoi(temp);
        getline(ss, name,    '|');
        getline(ss, phone,   '|');
        getline(ss, address, '|');
        getline(ss, shop,    '|');
        getline(ss, area,    '|');
        vendors.push_back(Vendor(id, name, phone, address, shop, area));
    }
    file.close();
}

void FileManager::saveOrders(vector<Order>& orders)
{
    ofstream file("vendor_orders.txt");
    for (int i = 0; i < (int)orders.size(); i++)
        file << orders[i].getOrderID()     << "|"
             << orders[i].getBuyerID()     << "|"
             << orders[i].getBuyerName()   << "|"
             << orders[i].getType()        << "|"
             << orders[i].getStatus()      << "|"
             << orders[i].getQuantity()    << "|"
             << orders[i].getPricePerUnit()<< "|"
             << orders[i].getDate()
             << endl;
    file.close();
}

void FileManager::loadOrders(vector<Order>& orders)
{
    ifstream file("vendor_orders.txt");
    if (!file)
    {
        orders.push_back(Order(1001, "Ali Hassan",   "19L",    10, 100, "2026-05-01")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(2001, "City Mart",    "500ML",  20, 350, "2026-05-02")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(1002, "Usman Riaz",   "19L",     5, 100, "2026-05-05")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(2002, "Fresh Store",  "1500ML", 15, 480, "2026-05-07")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(1003, "Malik Tariq",  "19L",     8, 100, "2026-05-10")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(2003, "Khalid Traders","500ML", 12, 350, "2026-05-12")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(1004, "Zara Noor",    "19L",     3, 100, "2026-05-15")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(2004, "Sara Depot",   "1500ML", 10, 480, "2026-05-18")); orders.back().setStatus("DELIVERED");
        orders.push_back(Order(1005, "Bilal Ahmed",  "19L",     6, 100, "2026-05-20")); orders.back().setStatus("PENDING");
        orders.push_back(Order(2005, "Rehman Store", "500ML",   8, 350, "2026-05-22")); orders.back().setStatus("PENDING");
        orders.push_back(Order(1006, "Hina Shahid",  "19L",     4, 100, "2026-05-25")); orders.back().setStatus("PENDING");
        orders.push_back(Order(2001, "City Mart",    "1500ML",  5, 480, "2026-05-28")); orders.back().setStatus("PENDING");
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string temp, name, type, status, date;
        int id, buyerID, qty;
        double price;
        getline(ss, temp,   '|'); id      = stoi(temp);
        getline(ss, temp,   '|'); buyerID = stoi(temp);
        getline(ss, name,   '|');
        getline(ss, type,   '|');
        getline(ss, status, '|');
        getline(ss, temp,   '|'); qty   = stoi(temp);
        getline(ss, temp,   '|'); price = stod(temp);
        getline(ss, date,   '|');
        Order o(buyerID, name, type, qty, price, date);
        o.setStatus(status);
        orders.push_back(o);
    }
    file.close();
}

void FileManager::saveStaff(vector<DeliveryBoy>& staff)
{
    ofstream file("staff.txt");
    for (int i = 0; i < (int)staff.size(); i++)
        file << staff[i].getEmployeeID()   << "|"
             << staff[i].getName()         << "|"
             << staff[i].getPhone()        << "|"
             << staff[i].getAddress()      << "|"
             << staff[i].getSalary()       << "|"
             << staff[i].getArea()         << "|"
             << staff[i].getDeliveryCount()
             << endl;
    file.close();
}

void FileManager::loadStaff(vector<DeliveryBoy>& staff)
{
    ifstream file("staff.txt");
    if (!file) {
        staff.push_back(DeliveryBoy(3001, "Kamran Ali",   "0311-4445566", "Saddar",     18000, "Saddar",      42));
        staff.push_back(DeliveryBoy(3002, "Faisal Raza",  "0322-7778899", "Gulshan",    16000, "Gulshan",     37));
        staff.push_back(DeliveryBoy(3003, "Imran Butt",   "0333-1112233", "Johar Town", 17500, "Johar Town",  55));
        staff.push_back(DeliveryBoy(3004, "Asad Iqbal",   "0300-5556677", "DHA",        19000, "DHA Phase 5", 28));
        staff.push_back(DeliveryBoy(3005, "Zubair Khan",  "0345-9990011", "Model Town", 15500, "Model Town",  61));
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string temp, name, phone, address, area;
        int id, dc;
        double sal;
        getline(ss, temp,    '|'); id  = stoi(temp);
        getline(ss, name,    '|');
        getline(ss, phone,   '|');
        getline(ss, address, '|');
        getline(ss, temp,    '|'); sal = stod(temp);
        getline(ss, area,    '|');
        getline(ss, temp,    '|'); dc  = stoi(temp);
        staff.push_back(DeliveryBoy(id, name, phone, address, sal, area, dc));
    }
    file.close();
}

void FileManager::saveInventory(Inventory& inv)
{
    ofstream file("inventory.txt");
    file << inv.getStock19L()   << "|"
         << inv.getStock500ml() << "|"
         << inv.getStock1500ml()
         << endl;
    file.close();
}

void FileManager::loadInventory(Inventory& inv)
{
    ifstream file("inventory.txt");
    if (!file)
    {
        inv.add19L(85);
        inv.add500ml(60);
        inv.add1500ml(45);
        inv.receiveEmpty19L(18);
        return;
    }
    string line, temp;
    getline(file, line);
    stringstream ss(line);
    int a, b, c;
    getline(ss, temp, '|'); a = stoi(temp);
    getline(ss, temp, '|'); b = stoi(temp);
    getline(ss, temp, '|'); c = stoi(temp);
    inv.add19L(a);
    inv.add500ml(b);
    inv.add1500ml(c);
    file.close();
}
