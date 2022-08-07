#include <iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
};
int main()
{
    struct Rectangle r;
    r.length = 10;
    r.breadth = 20;
    cout << "Area of rectangle is : " << r.length * r.breadth << endl;
    return 0;
}