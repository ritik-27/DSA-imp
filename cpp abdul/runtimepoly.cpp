#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Prrint in base class";
    }
    void show()
    {
        cout << "Show in base class";
    }
};
class Derived : public Base
{
public:
    void print()
    {
        cout << "Print in Derived class";
    }
    void show()
    {
        cout << "Show in derived class";
    }
};
int main()
{
    Base *bptr;
    Derived d;
    bptr = &d;

    bptr->print(); // Derived because of virtual (((Runtime poly))))
    cout << endl;
    bptr->show(); // Base show
    return 0;
}