#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter Year to be checked : ";
    cin >> year;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            cout << "Entered year is leap year";
        }
        else
        {
            cout << "Entered year is NOT leap year";
        }
    }
    else if (year % 4 == 0)
    {
        cout << "Entered year is leap year";
    }
    else
    {
        cout << "Entered year is NOT leap year";
    }

    return 0;
}