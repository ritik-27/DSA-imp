#include <iostream>
using namespace std;

int main()
{
    char A[] = "welcOMe";
    int i = 0;
    while (A[i] != '\0')
    {
        if ('A' <= A[i] && A[i] <= 'Z')
        {
            A[i] = A[i] + 32;
            cout << A[i] << " ";
        }
        else if ('a' <= A[i] && A[i] <= 'z')
        {
            A[i] = A[i] - 32;
            cout << A[i] << " ";
        }
        i++;
    }

    return 0;
}
