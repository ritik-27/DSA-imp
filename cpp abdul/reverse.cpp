#include <iostream>
using namespace std;

int main()
{
    int i, n, r = 0;
    cout << "ENter a number : ";
    cin >> n;
    while (n > 0)
    {
        r = n % 10;
        n = n / 10;
        cout << r;
    }

    return 0;
}