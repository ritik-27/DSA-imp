#include <iostream>
using namespace std;

int main()
{
    int A[100];
    int *p = A;

    int n;
    cout << "Enter the number of elements to be entred in arry: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value : ";
        cin >> *p;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "values are : ";
        cout << p[i];
    }

    return 0;
}