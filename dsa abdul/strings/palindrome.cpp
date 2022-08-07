#include <iostream>
using namespace std;

int main()
{

    char A[] = "Agt";
    int j;
    bool b;

    for (j = 0; j < A[j] != '\0'; j++)
    {
    }
    j = j - 1;

    for (int i = 0; i < j; i++, j--)
    {
        if (A[i] == A[j])
        {
            b = true;
        }

        else
        {
            b = false;
            break;
        }
    }
    if (b)
    {
        cout << "PALINDROME";
    }
    else
    {
        cout << "nhi bola na ";
    }
    return 0;
}