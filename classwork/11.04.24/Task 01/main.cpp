#include <iostream>
#include <iostream>
#include <exception>

using namespace std;

class AgeRestrictionException : exception
{
private:
    string msg;
    int code;

public:
    AgeRestrictionException(string msg, int code) : msg(msg), code(code) {}

    const char* what() const noexcept // == throw() функция не бросает исключений
    {
        return msg.c_str();
    }

    int getCode() const noexcept
    {
        return code;
    }
};

void registerParticipant(int age)
{
    if (age < 18)
    {
        throw AgeRestrictionException("You are too young to participate", 100);
    }
    else if (age > 60)
    {
        throw AgeRestrictionException("You are too old to participate", 101);
    }

    cout << "Registration finished!" << endl;
    return ;
}

int main() 
{
    try 
    {
        registerParticipant(17);
    } 
    catch (AgeRestrictionException& e) 
    {
        cout << "Ошибка: " << e.what()  << e.getCode() << endl;
    }

    try 
    {
        registerParticipant(50);
    } 
    catch (AgeRestrictionException& e) 
    {
        cout << "Ошибка: " << e.what() << e.getCode() << endl;
    }

    return 0;
}
