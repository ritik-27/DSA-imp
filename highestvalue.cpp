#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int len)
{
    int max = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max2 = max;
            max = arr[i];
        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

int main()
{
    int arr[] = {1, 2, 13, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << max(arr, len);

    return 0;
}
