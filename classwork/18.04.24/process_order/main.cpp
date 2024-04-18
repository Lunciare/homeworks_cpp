#include <iostream>
#include <exception>
#include <string>

using namespace std;

class OrderException : exception
{
private:
    string msg;
    int code;

public:
    OrderException(string msg, int code) : msg(msg), code(code) {};

    const char* what() const noexcept
    {
        return msg.c_str();
    }

    int getErrorCode() const noexcept
    {
        return code;
    }
};

void processOrder(int quantity, double price)
{
    if (quantity < 0)
    {
        throw OrderException("The quantity is negative: ", 100);
    }
    else if (price < 10.0)
    {
        throw OrderException("The price is too low: ", 101);
    }
    cout << "\nOrder is processed!" << endl;
    return;
}

int main() 
{
    try 
    {
        processOrder(-99, 12.0);
    } 
    catch (const OrderException& e) 
    {
        cout << "Exception: " << e.what() << "\ncode: " << e.getErrorCode() << endl;
    }

    try 
    {
        processOrder(10, 5.0);
    } 
    catch (const OrderException& e) 
    {
        cout << "Exception: " << e.what() << "\ncode: " << e.getErrorCode() << endl;
    }

    try
    {
        processOrder(2, 100.5);
    }
    catch(const OrderException& e)
    {
        cout << "Exception: " << e.what() << "\ncode: " << e.getErrorCode() << '\n';
    }

    
    return 0;
}
