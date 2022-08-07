#include <iostream>
using namespace std;

int myfun(float A[])
{
    int days = 0;
    int counter = 0;
    for (int i = 0; i < 8; i++)
    {
        if (A[i] > 25)
        {
            if (A[i] > 30)
            {
                counter++;
                days++;
                continue;
            }
            days++;
        }
    }

    if (counter >= 3)
    {
        return days;
    }
    else
    {
        return 0;
    }
}
int main()
{
    float A[8] = {24.7, 25.1, 28.9, 31, 24, 30.6, 32.4, 23};
    int res = myfun(A);
    cout << res;
    return 0;
}