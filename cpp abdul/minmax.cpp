#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << " Enter the size of array : " << endl;
    cin >> n;
    int A[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Maximun elwem in the array is : " << max << endl;
    cout << "Minimun elwem in the array is : " << min << endl;
    return 0;
}