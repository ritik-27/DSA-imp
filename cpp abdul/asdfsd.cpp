#include <iostream>
using namespace std;
int main()
{
    int a, b[15], i = 0, t, k, s, h, n = 0;
    cin >> a;
    while (a != 0)
    {
        b[i++] = a % 10;
        a /= 10;
        n++;
    }
    for (s = 0; s < n; s++)
    {
        for (h = s + 1; h < n; h++)
        {
            if (b[s] > b[h])
            {
                t = b[s];
                b[s] = b[h];
                b[h] = t;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << b[i] << " ";
        return 0;
    }
}
