#include <iostream>
using namespace std;

int main()
{
    int A[5] = {4, 5, 6, 7, 9};
    cout << "Array elements before reversing : ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 2; i++)
    {
        int temp = A[i]; // temp=A[1]  (temp=5)
        A[i] = A[4 - i]; // A[1]=A[2]  [7, 6,6 ,4]
        A[4 - i] = temp; // A[2]=temp  [7,6,5,4]
    }
    cout << "Array elements AFTER reversing : ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}