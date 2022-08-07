#include <iostream>
using namespace std;
void myfun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        cout << "Before fun call" << endl;
        myfun(n - 1);
        cout << "X: " << n + x << endl;
        cout << "After fun call" << endl;
    }
}
int main()
{
    int x = 2;
    myfun(x);
    return 0;
}