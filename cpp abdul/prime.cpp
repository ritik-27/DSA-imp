#include <iostream>
using namespace std;

int main()
{
    int i, n, count = 0;
    cout << "Enter the number to be checked : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count <= 2)
    {
        cout << "Entered Number is prime" << endl;
    }
    else
    {
        cout << "Number is non-prime";
    }
    return 0;
}
