#include <iostream>
using namespace std;

int main()
{
    int dfs[12] = {20, -1, 5, 18, -90, 60, 0, 61, 43, 52};
    int x = NULL;
    int a = NULL;

    for (int b = 0; b < 10; b++)
    {
        if (x == NULL)
        {
            x = dfs[b];
            continue;
        }

        if (a == NULL)
        {
            if (x < dfs[b])
            {
                a = x;
                x = dfs[b];
                continue;
            }
            else
            {
                if (x == dfs[b])
                {
                    continue;
                }

                a = dfs[b];
                continue;
                ;
            }
        }

        if (x == dfs[b])
        {
            continue;
        }

        if (x < dfs[b])
        {
            a = x;
            x = dfs[b];
        }
        else if (x != dfs[b] && x >= a)
        {
            if (a > dfs[b])
            {
                continue;
            }
            a = dfs[b];
        }
    }
    cout << "x: " << x << endl;
    cout << "a: " << a << endl;

    return 0;
}