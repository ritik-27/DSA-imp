#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
    {
        return m.A[i - 1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    cout << "\nMatrix Displayed: " << endl;
    for (int i = 0; i < m.n; i++) // Note thisss i=1
    {
        for (int j = 0; j < m.n; j++) // Note thisss j=1
        {
            if (i == j)
            {
                cout << m.A[i] << " "; // Note thiss A[i-1]
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
    struct Matrix m;
    m.n = 4;

    Set(&m, 1, 1, 10);
    Set(&m, 2, 2, 20);
    Set(&m, 3, 3, 30);
    Set(&m, 4, 4, 40);
    Display(m);
    cout << Get(m, 2, 2);

    return 0;
}