#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Shape 
{
 protected:
    double x, y;

 public:
    Shape(double x, double y) : x(x), y(y) {} // короткий способ записать конструктор
    virtual double area() const = 0; //если функция не виртуальная, то для всех указателей на Shape вектор будет вызывать функцию area только для базового класса (пропадает смысл наследования)
    virtual ~Shape() {} // деструктор, в тело ничего не пишем, потому что деструктор удаляет из динамической памяти (выделенной специально, а мы-то не выделили динамическую)
};

class Circle : public Shape // обозначение наследования
{
protected:
    double r;

public:
    Circle(double x, double y, double r) : Shape(x, y) // сначала вызвать конструктор родителя, а оставшиеся поля надо заполнить самостоятельно
    {
        this->r = r;
    }

    virtual double area() const // константная функция не меняет this
    {
        return M_PI*r*r;
    }
    virtual ~Circle() {}
};

class Rectangle :  public Shape
{
protected:
    double w, h; // длина и ширина

public:
    Rectangle(double x, double y, double w, double h) : Shape(x, y) //сначала перечислаются поля родителя
    {
        this->w = w;
        this->h = h;
    }

    virtual double area() const
    {
        return w*h;
    }
    virtual ~Rectangle() {}
};

vector<Shape*> V; //вектор указателей

int main() 
{
    Circle a = Circle(3, 5, 7);
    V.push_back(&a);

    Rectangle b = Rectangle(0, 0, 5, 6);
    V.push_back(&b);

    for(int i = 0; i < V.size(); ++i)
    {
        cout << V[i]->area() << endl;
        
    }

    return 0;
}
