#include <bits/stdc++.h>
using namespace std;

void myswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                myswap(&A[j], &A[j + 1]);
            }
        }
    }
}

void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {10, 9, 11, 6, 15, 2}, n = 6;
    Bubble(A, 6);
    printArr(A, 6);
    return 0;
}