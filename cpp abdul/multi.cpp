#include <iostream>
using namespace std;

int main()
{
    int x, y, k;
    cout << "ENter rows and cols  : ";
    cin >> x >> y;
    int A[x][y];
    int B[x][y];
    int C[x][y];
    int mult[x][y];

    cout << "Enter elements of FIRST matriX";
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << "Enter (" << i << " ," << j << " ) of first matrix ";
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of SECOND matriX";
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << "Enter (" << i << " ," << j << " ) of second matrix ";
            cin >> B[i][j];
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    // Multiplying the matrix
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mult[i][j] = 0;
            for (k = 0; k < y; k++)
            {
                mult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Displaying the matrix
    cout << endl
         << "Output Matrix: " << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << " " << mult[i][j];
            if (j = y - 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}
