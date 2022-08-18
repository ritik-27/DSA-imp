#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void show();
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Show in derived";
    }
};

int main()
{
    Derived d;
    d.show();
    return 0;
}