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
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int flag;
        for (j = 0; j < n - 1 - i; j++)
        {
            flag = 0;
            if (A[j] > A[j + 1])
            {
                myswap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void InsertionSort(int A[], int n)
{
    int i, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void selectionsort(int A[], int n)
{
    int i, j, k;
    for (int i = 0; i < n - 1; i++)
    {
        j = k = i;
        // j = k + 1;
        while (j < n)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
            j++;
        }
        myswap(&A[k], &A[i]);
    }
}

//! KICHKATTTTTTTTTTTT
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            myswap(&A[i], &A[j]);
        }

    } while (i < j);
    myswap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

//* FOr merging 2 sorted arrays
void mergearrs(int A[], int B[], int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int C[m + n];
    while (i < m && j < n) //?NOTEEE KRRRRRR
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (B[j] > A[i])
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n; j++)
    {
        C[k++] = B[j];
    }
}

void mergesort(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l; // NOTEEEEEEE
    int B[h + 1];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else if (A[j] > A[i])
        {
            B[k++] = A[j++];
        }
        else
        {
            B[k++] = A[i++];
            j++;
        }
    }
    for (; i < mid + 1; i++)
    {
        B[k++] = A[i];
    }
    for (; j < h + 1; j++)
    {
        B[k++] = A[j];
    }
    // Copying all elems of b baCK TO A
    for (int k = l; k < h + 1; k++) // NOTEE int k=0 mt kr tune low already liya hai as func. param
    {
        A[k] = B[k];
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
    // int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    // Bubble(A, 10);
    // InsertionSort(A, 10);
    // selectionsort(A, 10);
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX}, n = 11;
    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}