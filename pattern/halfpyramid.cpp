#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n;
    cout << "Enter number of rows: ";
    cin >> n;

    //*Half Pyramid
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //*Inverted Half Pyramid
    // for (i = 0; i < n; i++)
    // {
    //     for (j = n; j > i; j--)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //*Right half pyramid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}