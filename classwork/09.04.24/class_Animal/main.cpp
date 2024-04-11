#include <iostream>
#include <vector>

using namespace std;

class Animal
{
protected:
    string name;
    int weight;

public:
    Animal(string n, int w) : name(n), weight(w) {};
    virtual void Print() {};
    /*
    {
        cout << "Имя: " << this->name << ", вес: " << this->weight << endl;
    } */
    virtual ~Animal() {};
};

class Cat : public Animal
{
protected:
    string breed;

public:
    Cat(string name, int weight, string breed) : Animal(name, weight), breed(breed) {};
    virtual void Print()
    {
        cout << "Name: " << this->name << ", weight: " << this->weight  << ", breed: " << this->breed << endl;
    }
    virtual ~Cat() {};
};

class Dog : public Animal
{
protected:
    string breed;

public:
    Dog(string name, int weight, string breed) : Animal(name, weight), breed(breed) {};
    virtual void Print()
    {
        cout << "Name: " << this->name << ", weight: " << this->weight << ", breed: " << this->breed << endl;
    }
    virtual ~Dog() {};
};

vector<Animal*> A;

int main()
{
    Cat a = Cat("Tuchka", 10, "mohnaty");
    Dog b = Dog("Karamelka", 15, "lysyi");
    A.push_back(&a);
    A.push_back(&b);

    for(int i = 0; i < A.size(); ++i)
    {
        A[i]->Print();
    }
    return 0;
}
