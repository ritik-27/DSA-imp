#include <bits/stdc++.h>
using namespace std;
void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
// void myswap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void insertionsrt(int A[], int n)
{
    int i, j, key;
    for (j = 1; j < n; j++)
    {
        i = j - 1;
        key = A[j];
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1; // noteee
        }
        A[i + 1] = key; // noteee
    }
}
int main()
{
    int A[] = {10, 9, 11, 6, 15, 2}, n = 6;
    insertionsrt(A, 6);
    printArr(A, 6);
    return 0;
}