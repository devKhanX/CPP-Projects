# Aquaflow — Water Plant Management System

A console-based C++ application for managing the day-to-day operations of a water bottling/delivery plant — customers, vendors, delivery staff, orders, inventory, invoicing, and profit reporting. Built as an Object-Oriented Programming (OOP) project to demonstrate inheritance, polymorphism, encapsulation, operator overloading, exception handling, and file persistence.

## Features

- **Customer Management** — add customers, view active/all customers, deactivate accounts, record payments and track balances/empty bottle returns
- **Vendor Management** — add and view vendors supplying or purchasing in bulk
- **Order Management** — place orders (19L bottles, 500ml cases, 1.5L cases), track order status (PENDING/DELIVERED), view order history
- **Inventory Management** — track full/empty 19L bottles, 500ml and 1.5L case stock, refill empty bottles, low-stock alerts
- **Invoices & Billing** — generate monthly customer invoices and vendor bulk-order invoices
- **Profit & Reports** — revenue and net profit breakdown by product type
- **Delivery Staff Management** — add staff, assign delivery areas, track delivery counts
- **Persistent Storage** — all data is saved to and loaded from plain text files (`customers.txt`, `vendors.txt`, `vendor_orders.txt`, `staff.txt`, `inventory.txt`) so data survives between runs
- **Startup Alerts** — the main menu surfaces overdue balances, excess empty-bottle holdings, low stock, and pending orders at a glance

## OOP Concepts Demonstrated

| Concept | Where it appears |
|---|---|
| Abstraction / Pure virtual functions | `Person::display()`, `Invoice::generateBill()` |
| Inheritance | `Customer`, `Vendor`, `Employee` → `Person`; `DeliveryBoy` → `Employee`; `MonthlyInvoice`, `BulkOrderInvoice` → `Invoice` |
| Polymorphism | Overridden `display()` and `generateBill()` methods called through base pointers/references |
| Encapsulation | Private/protected member data with public getters/setters |
| Operator Overloading | `Order::operator<`, `Order::operator==` |
| Exception Handling | `InsufficientStockException` thrown by `Inventory` when stock runs out |
| Static Members | Auto-incrementing unique IDs (`nextCustomerID`, `nextVendorID`, `nextEmployeeID`, `nextOrderID`, `nextInvoiceID`) |
| File I/O | `FileManager` handles saving/loading all persistent data |

## Project Structure

```
Aquaflow-Water-Plant-Management/
├── main.cpp                       # Program entry point & menu-driven UI
│
├── Person.h / Person.cpp          # Abstract base class for all people
├── Customer.h / Customer.cpp      # Customer accounts, plans, balances
├── Vendor.h / Vendor.cpp          # Vendors buying in bulk
├── Employee.h / Employee.cpp      # Base class for staff
├── DeliveryBoy.h / DeliveryBoy.cpp# Delivery staff, assigned areas
│
├── Order.h / Order.cpp            # Orders placed by customers/vendors
├── InsufficientStockException.h   # Custom exception for stock errors
├── Inventory.h / Inventory.cpp    # Stock levels, pricing, costs
│
├── Invoice.h / Invoice.cpp        # Abstract base class for invoices
├── MonthlyInvoice.h / .cpp        # Customer monthly billing
├── BulkOrderInvoice.h / .cpp      # Vendor bulk-order billing
│
├── ProfitAnalysis.h / .cpp        # Revenue & profit reporting
├── FileManager.h / .cpp           # Save/load all data to/from text files
└── Utils.h / .cpp                 # Shared helpers (input, alerts, screen clear)
```

### Class Dependency Order

1. **Person.h** — base class, no dependencies
2. **Customer.h / Vendor.h / Employee.h** — inherit from `Person`
3. **DeliveryBoy.h** — inherits from `Employee`
4. **Order.h** — standalone
5. **InsufficientStockException.h** — standalone
6. **Inventory.h** — uses the exception class
7. **Invoice.h** — standalone abstract base
8. **MonthlyInvoice.h / BulkOrderInvoice.h** — inherit from `Invoice`
9. **ProfitAnalysis.h** — depends on `Order` and `Inventory`
10. **FileManager.h** — depends on `Customer`, `Vendor`, `Order`, `DeliveryBoy`, `Inventory`
11. **Utils.h** — depends on `Customer`, `Order`, `Inventory`
12. **main.cpp** — includes everything

## Requirements

- A C++ compiler supporting **C++11 or later** (g++, MSVC, Clang all work)
- Windows is assumed for `system("cls")` in `Utils.cpp` — on Linux/Mac, replace this with `system("clear")` if needed

## Building

### Using g++
```bash
g++ -std=c++17 *.cpp -o aquaflow
./aquaflow
```

### Using an IDE (Code::Blocks, Dev-C++, Visual Studio)
1. Create a new empty C++ project
2. Add all `.h` and `.cpp` files from this folder to the project
3. Build and run

## Usage

On launch, the app loads existing data (or seeds sample data on first run) and shows the main menu:

```
===== AQUAFLOW WATER PLANT MANAGEMENT =====
1. Customer Management
2. Vendor Management
3. Order Management
4. Inventory Management
5. Invoices & Billing
6. Profit & Reports
7. Delivery Staff
8. Save & Exit
```

Navigate using the number keys. Choosing **8** saves all data back to the text files before exiting.

## Sample Data

On first run (when no `.txt` data files exist), the app seeds itself with sample customers, vendors, orders, and delivery staff so you can explore all features immediately without manual data entry.

## License

This project was built for educational purposes as part of an OOP coursework assignment.
