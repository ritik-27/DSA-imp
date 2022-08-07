#include <iostream>
using namespace std;

int main()
{
    int n;
    float disc = 0;
    cout << "ENter Totoal amount: ";
    cin >> n;

    if (n < 100)
    {
        cout << "No discount is provided for amount less than 100" << endl;
    }
    else if (n >= 0 && n < 500)
    {
        disc = (float)(n * 10) / 100;
    }
    else if (n >= 500)
    {
        disc = (float)(n * 20) / 100;
    }
    cout << "Bill amount is : " << n << endl;
    cout << "Discount in bill amount is : " << disc << endl;
    cout << "Final bill amount is : " << n - disc << endl;

    return 0;
}