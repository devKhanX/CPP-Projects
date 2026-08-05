#ifndef INSUFFICIENTSTOCKEXCEPTION_H
#define INSUFFICIENTSTOCKEXCEPTION_H

#include <string>
using namespace std;

class InsufficientStockException
{
private:
    string message;

public:
    InsufficientStockException(string msg) : message(msg) {}

    string what() const
    {
        return message;
    }
};

#endif // INSUFFICIENTSTOCKEXCEPTION_H
