#include <iostream>
using namespace std;
struct Rectangle
{
    int length, breadth;
};

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}
void changeLength(struct Rectangle *r, int newLength)
{
    r->length = newLength;
}
void initialize(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}
int main()
{
    struct Rectangle r;
    initialize(&r, 10, 5);
    int ar = area(r);
    cout << "Area of rect is: " << ar << endl;
    changeLength(&r, 20);
    ar = area(r);
    cout << "New Area of rect is: " << ar << endl;
    return 0;
}