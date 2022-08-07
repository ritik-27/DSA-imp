#include <iostream>
using namespace std;

int myfun(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == A[i])
        {
            cout << "Element found at index : " << i;
            return 0;
        }
    }
    cout << "Element not Found" << endl;
    return 0;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int elem;
    cout << "Enter element to be searched : ";
    cin >> elem;
    myfun(A, 5, elem);

    return 0;
}
