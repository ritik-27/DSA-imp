#include <bits/stdc++.h>
using namespace std;

int getMissingnum(int arr[], int n)
{
    int i;
    n = n + 1;
    int total = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        total -= arr[i];
    }
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number: " << getMissingnum(arr, N);
    return 0;
}