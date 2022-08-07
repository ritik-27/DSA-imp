#include <iostream>
using namespace std;
class Shape
{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Rectangle : public Shape
{
private:
    int length, breadth;

public:
    Rectangle(int l = 1, int b = 1)
    {
        length = l;
        breadth = b;
    }
    float area()
    {
        return length * breadth;
    }
    float perimeter()
    {
        return 2 * (length + breadth);
    }
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int rad = 1) { radius = rad; }
    float area()
    {
        return 3.14 * radius * radius;
    }
    float perimeter()
    {
        return 2 * 3.14 * radius;
    }
};

int main()
{
    Shape *ptr = new Rectangle(4, 5);
    cout << "Area of rectangle: " << ptr->area() << endl;
    cout << "Perimeter of rectangle: " << ptr->perimeter() << endl;

    cout << "----------------------------" << endl;
    ptr = new Circle(5);

    cout << "Area of circle: " << ptr->area() << endl;
    cout << "Perimeter of circle: " << ptr->perimeter() << endl;
    return 0;
}