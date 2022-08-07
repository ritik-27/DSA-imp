#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int arr[n] = {2, 5, 6, 4, 7};
    int temp;
    cout << n / 2 << endl;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}