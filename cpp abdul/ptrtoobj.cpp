#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length, breadth;

    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main()
{
    // Rectangle r1, r2;
    // r1.length = 10;
    // r1.breadth = 20;
    // r2.length = 120;
    // r2.breadth = 210;

    Rectangle *p;      // Declaration of ptr
    p = new Rectangle; //?????????????

    Rectangle *q = new Rectangle;
    p->length = 10;
    p->breadth = 20;
    q->length = 110;
    q->breadth = 220;

    cout << "Area of 1st rectangle: " << p->area() << endl;
    cout << "Perimeter of 1st rectangle: " << p->perimeter() << endl;
    cout << "-------------------------------------" << endl;
    cout << "Area of 1st rectangle: " << q->area() << endl;
    cout << "Perimeter of 1st rectangle: " << q->perimeter() << endl;
    return 0;
}