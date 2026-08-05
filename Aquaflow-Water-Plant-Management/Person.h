#include "Person.h"

Person::Person(string n, string p, string a)
{
    name = n;
    phone = p;
    address = a;
}

void Person::setName(string n)
{
    name = n;
}
void Person::setPhone(string p)
{
    phone = p;
}
void Person::setAddress(string a)
{
    address = a;
}

string Person::getName() const
{
    return name;
}

string Person::getPhone() const
{
    return phone;
}
string Person::getAddress() const
{
    return address;
}

Person::~Person() {}
