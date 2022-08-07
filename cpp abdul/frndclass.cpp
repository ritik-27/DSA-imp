#include <iostream>
using namespace std;

class Friend_class;
class Base
{
private:
    int a = 4;

protected:
    int b = 2;

public:
    int c = 3;

    friend class Friend_class;
};
class Friend_class
{
public:
    Base obj1;
    void func()
    {
        obj1.a;
        obj1.b;
        obj1.c;
        cout << obj1.a + obj1.b + obj1.c;
    }
};

int main()
{
    // Base obj3;
    Friend_class obj4;
    obj4.func();
    return 0;
}