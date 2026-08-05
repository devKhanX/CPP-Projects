#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
    int full19L;
    int empty19L;
    int cases500ml;
    int cases1500ml;

    double price19L;
    double price500ml;
    double price1500ml;

    double cost19L;
    double cost500ml;
    double cost1500ml;

    int lowStockAlert;

public:
    Inventory();

    void dispatch19L(int qty);
    void dispatch500ml(int cases);
    void dispatch1500ml(int cases);

    void receiveEmpty19L(int qty);
    void refill19L(int qty);

    void add19L(int qty);
    void add500ml(int cases);
    void add1500ml(int cases);

    void setFull19L(int v);
    void setEmpty19L(int v);
    void set500ml(int v);
    void set1500ml(int v);

    void display();

    double getPrice19L();
    double getPrice500ml();
    double getPrice1500ml();

    double getCost19L();
    double getCost500ml();
    double getCost1500ml();

    int getStock19L();
    int getStock500ml();
    int getStock1500ml();
};

#endif // INVENTORY_H
