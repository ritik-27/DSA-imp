#include <iostream>
using namespace std;

int main()
{
    int key, mid, l, h;
    int A[] = {4, 18, 26, 29, 35, 58, 67};
    l = 0;
    h = sizeof(A) - 1;

    cout << "ENter value to be searched : ";
    cin >> key;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            cout << "Element found at index: " << mid;
            return 0;
        }
        else if (key > A[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << l;
}