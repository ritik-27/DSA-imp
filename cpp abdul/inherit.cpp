#include <iostream>
using namespace std;
class Rectangle
{
private:
    int length, breadth;

public:
    Rectangle();
    Rectangle(int l, int b);
    Rectangle(Rectangle &r);
    void setLength(int l)
    {
        length = l;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
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
class Cuboid : public Rectangle
{
private:
    int height;

public:
    Cuboid(int l = 0, int b = 0, int h = 0)
    {
        height = h;
        setLength(l);
        setBreadth(b);
    }

    void setHeight(int h)
    {
        height = h;
    }
    int getHeight()
    {
        return height;
    }
    int volume()
    {
        return getLength() * getBreadth() * height;
    }
};

int main()
{
    Cuboid c(10, 5, 3);
    cout << "Area of rect in cuboid: " << c.area() << endl;
    cout << "Perimeter of rect in cuboid: " << c.perimeter() << endl;
    cout << "Volume of cuboid: " << c.volume() << endl;
}