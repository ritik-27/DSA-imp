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

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

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

int main()
{
    DigMatrix D(4);

    D.Set(1, 1, 10);
    D.Set(2, 2, 20);
    D.Set(3, 3, 30);
    D.Set(4, 4, 40);
    D.Display();
    cout << D.Get(2, 2);

    return 0;
}