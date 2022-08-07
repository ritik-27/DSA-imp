#include <iostream>
using namespace std;

class DigMatrix
{
private:
    int n;
    int *A;

public:
    DigMatrix()
    {
        n = 3;
        A = new int[n];
    }
    DigMatrix(int num)
    {
        this->n = num;
        A = new int[n];
    }
    ~DigMatrix()
    {
        delete[] A;
    }

    void Create();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void DigMatrix::Create()
{
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            Set(i, j, x);
        }
    }
}

void DigMatrix::Set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int DigMatrix::Get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}

void DigMatrix::Display()
{
    cout << "\nDigagonal Matrix Displayed: " << endl;
    for (int i = 0; i < n; i++) // Note thisss i=1
    {
        for (int j = 0; j < n; j++) // Note thisss j=1
        {
            if (i == j)
            {
                cout << A[i] << " "; // Note thiss A[i-1]
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

class LowTriMatrix
{
private:
    int n;
    int *A;

public:
    LowTriMatrix(int num)
    {
        this->n = num;
        A = new int[n * (n + 1) / 2];
    }
    ~LowTriMatrix()
    {
        delete[] A;
    }

    void Create();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void LowTriMatrix::Create()
{
    int x;
    cout << "ENter " << n * (n + 1) / 2 << " elems" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (i >= j)
            {
                A[(i * (i - 1) / 2) + j - 1] = x;
            }
        }
    }
}

void LowTriMatrix::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[((i) * (i - 1) / 2) + j - 1] = x;
    }
}

int LowTriMatrix::Get(int i, int j)
{
    if (i == j)
    {
        return A[((i) * (i - 1) / 2) + j - 1];
    }
    else
    {
        return 0;
    }
}

void LowTriMatrix::Display()
{
    cout << "\nLower Triangular Matrix Displayed: " << endl;
    for (int i = 1; i <= n; i++) // Note thisss i=1
    {
        for (int j = 1; j <= n; j++) // Note thisss j=1
        {
            if (i <= j)
            {
                cout << A[((i) * (i - 1) / 2) + j - 1] << " "; // Note thiss A[i-1]
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    LowTriMatrix D(4);
    D.Create();
    D.Display();
    cout << D.Get(2, 2);

    return 0;
}