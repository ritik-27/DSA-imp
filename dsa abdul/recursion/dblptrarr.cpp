#include <iostream>
using namespace std;

int main()
{
    int **A;
    A = new int *[3];
    A[0] = new int[4]; // Note this its NOT *A[0] its just A[0] REMEMBER ****
    A[1] = new int[4];
    A[2] = new int[4];
    int counter = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A[i][j] = counter;
            counter++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}