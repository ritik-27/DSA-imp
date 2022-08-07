#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter the number :  ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "N is even";
    }
    else
    {
        cout << "n is odd";
    }

    return 0;
}
