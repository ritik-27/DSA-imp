#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}
int cr(int n, int r) // Using normal ncr formula
{
    int num, denom;
    num = fact(n);
    denom = fact(r) * fact(n - r);
    return num / denom;
}
int ncr(int n, int r) // using pascals triangle propert ""ncr=(n-1)^C(r-1)+(n-1)^C(r)""
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
}
int main()
{
    cout << "ncr: " << ncr(5, 2);
    return 0;
}