// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *p = new int[5];
    int counter = 1;
    for (int i = 0; i < 5; i++)
    {
        p[i] = counter + 4;
        counter++;
    }
    cout << "Displaying old p array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    int *q = new int[8];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    for (int i = 5; i < 8; i++)
    {
        q[i] = counter;
        counter++;
    }
    delete[] p;
    p = q;
    q = NULL;
    cout << "Displaying new p array: " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}