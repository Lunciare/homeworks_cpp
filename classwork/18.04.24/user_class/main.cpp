#include <string>
#include <iostream>

using namespace std;

class User
{
protected:
    string name;
public:
    User(string name) : name(name) {};

    virtual void levelOfaccess() const
    {
        cout << this->name << " has basic access" << endl;
    }
    virtual ~User() {};
};

class Employee : virtual public User
{
public:
    Employee(string name) : User(name) {};

    virtual void levelOfaccess() const
    {
        cout << this->name << " has staff access" << endl;
    }
    virtual ~Employee() {};
};

class Manager : virtual public User
{
public:
    Manager(string name) : User(name) {};

    virtual void levelOfaccess() const
    {
        cout << this->name << " has manager access" << endl;
    }
    virtual ~Manager() {};
};

class Administrator : public Employee, public Manager
{
public:
    Administrator(string name) : Employee(""), Manager(""), User(name) {};

    virtual void levelOfaccess() const
    {
        cout << this->name << " has administrator access" << endl;
    }
};

int main()
{
    User a = User("Masha");
    Employee b = Employee("Egor");
    Manager c = Manager("Rihanna");
    Administrator d = Administrator("Lev");

    a.levelOfaccess();
    b.levelOfaccess();
    c.levelOfaccess();
    d.levelOfaccess();
    return 0;
}
