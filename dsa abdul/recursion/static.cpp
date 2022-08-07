#include <iostream>
using namespace std;
int myfun(int n)
{
    if (n > 0)
    {
        return myfun(n - 1) + n;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a = 5;
    cout << "Output: " << myfun(a);
    return 0;
}