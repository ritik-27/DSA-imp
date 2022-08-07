#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, sum = 0;
    cout << "Enter the number to be checked : ";
    cin >> n;
    while (i <= n)
    {
        sum = sum + i;
        i++;
    }
    cout << "Sum is " << sum;
    return 0;
}
