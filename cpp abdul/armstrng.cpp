#include <iostream>
using namespace std;

int main()
{
    int i, n, m, sum = 0, r = 0;
    cout << "Enter a number : ";
    cin >> n;
    m = n;
    while (n > 0)
    {
        r = n % 10;
        n = n / 10;
        sum += r * r * r;
    }
    if (sum == m)
    {
        cout << "armst";
    }
    else
    {
        cout << "Not armst";
    }

    return 0;
}