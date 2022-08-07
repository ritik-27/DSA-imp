#include <iostream>
using namespace std;

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

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

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
    int dim;
    cout << "Enter the dimension: ";
    cin >> dim;
    LowTriMatrix Ltr(dim);

    int x;
    cout << "Enter All Elements" << endl;
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cin >> x;
            Ltr.Set(i, j, x);
        }
    }

    Ltr.Display();
    return 0;
}