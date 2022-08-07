#include <iostream>
using namespace std;

int division(int a, int b)
{
    if (b == 0)
    {
        throw string("This is division by zero");
    }
    else
    {
        return a / b;
    }
}
int main()
{
    int x = 10, y = 0;
    try
    {
        int c = division(x, y);
    }
    catch (string e)
    {
        cout << e << endl;
        ;
    }
    cout << "Byeee" << endl;
    return 0;
}