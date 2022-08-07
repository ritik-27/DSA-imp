#include <iostream>
using namespace std;

int main()
{
    int A[8] = {2, 4, 6, 8, 15, 25, 26, 30};
    int l = 0;
    int h = 7;
    int mid = (l + h) / 2;
    int key = 15;

    while (l <= h)
    {

        mid = l + h / 2;
        if (key > A[mid])
        {
            l = mid + 1;
        }
        else if (key < A[mid])
        {
            h = mid - 1;
        }
        else
        {
            return key;
        }
    }

    cout << "Element found at index: " << key;
    return 0;
}