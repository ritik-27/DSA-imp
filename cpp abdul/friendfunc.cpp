#include <iostream>
using namespace std;

class My
{
public:
    int a;

private:
    int b;

public:
    int c;
    friend void func(My t);
};

void func(My t)
{
    // My t; // i haveto use object for using the variables outside
    t.a = 3;
    t.b = 4;
    t.c = 1;
    cout << t.a * t.b * t.c;
}

int main()
{
    My obj;
    func(obj);
    return 0;
}