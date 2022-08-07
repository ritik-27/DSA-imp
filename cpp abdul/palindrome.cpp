#include <iostream>
using namespace std;

int main()
{
    int m, r, n, i, rev = 0;
    cout << "Enter the number to be checked :  ";
    cin >> n;
    m = n;

    while (n > 0)
    {
        r = n % 10;
        n = n / 10;
        rev = rev * 10 + r;
    }
    cout << "tHE REVERSE OF NUNMBER IS : " << rev << endl;
    if (rev == m)
    {
        cout << "The number entered is palindrome";
    }
    else
    {
        cout << "The number entered is NOT palindrome";
    }

    return 0;
}
