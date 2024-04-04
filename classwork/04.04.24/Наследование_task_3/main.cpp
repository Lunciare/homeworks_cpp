#include <iostream>
#include <iterator>
#include <string>

using namespace std;

class User 
{
protected:
    string name;

public:
    User(string name) : name(name) {}
    virtual void accessResources() const 
    {
        cout << name << " has basic user access." << endl;
    }
    virtual ~User() {}
};


class Employee : virtual public User
{
public:
    Employee(string name) : User(name) {};
    virtual void accessResources() const 
    {
        cout << name << " has a level of access to resources specific for staff." << endl;
    }

    virtual ~Employee() {};
};


class Manager : virtual public User
{
public:
    Manager(string name) : User(name) {};
    virtual void accessResources() const 
    {
        cout << name << " can manage department resources." << endl;
    }

    virtual ~Manager() {};
};


class Administrator : public Employee, public Manager
{
public:
    Administrator(string name) : Employee(""), Manager(""), User(name) {};
    virtual void accessResources() const 
    {
        cout << name << " can manage all levels of resources." << endl;
    }
};

int main()
{
    User Kennedy_John = {"Kennedy"};
    Kennedy_John.accessResources();
    Employee Lincoln_Abraham = {"Lincoln"};
    Lincoln_Abraham.accessResources();
    Manager Roosevelt_Franklin = {"Roosevelt"};
    Roosevelt_Franklin.accessResources();
    Administrator Washington_George = {"Washington"};
    Washington_George.accessResources();

    return 0;
}
