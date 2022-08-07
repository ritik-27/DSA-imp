// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
int F[100];
int mfib(int n) // m stands here for memoisation i.e reducing known function calls nd storing them in an array
{
    if (n <= 1)
    {
        F[n] = n;
        // cout << n << " ";
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = mfib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = mfib(n - 1);
        }
        F[n] = F[n - 2] + F[n - 1];
        // cout << F[n - 2] + F[n - 1] << " ";
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    int size = 5;
    // cout << "Enter the size of fibonacci series: ";
    // cin >> size;
    int F[size];

    for (int i = 0; i < size; i++)
    {
        F[i] = -1;
    }
    int res = mfib(size);
    cout << "Fibonacci Series: " << res;
    for (int i = 0; i < size; i++)
    {
        cout << F[i] << " ";
    }

    // cout << mfib(6) << endl;
    // cout << "Fib series for first 5 terms is " << res << endl;
    return 0;
}