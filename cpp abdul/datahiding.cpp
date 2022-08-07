#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, breadth;

public:
    void setLength(int l)
    {
        length = l;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }

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
    Rectangle r1;
    r1.setLength(10);
    r1.setBreadth(5);

    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;

    return 0;
}