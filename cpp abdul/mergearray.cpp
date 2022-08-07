#include <iostream>
using namespace std;

int main()
{
    int counter = 0;
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {11, 12, 13, 14, 15};
    int C[10];

    for (int i = 0; i < 5; i++) // i=0,1,2,3,4
    {
        C[i] = A[i];
    }

    for (int i = 5; i < 10; i++)
    {
        C[i] = B[counter]; // C[9]=B[4];
        counter += 1;
    }
    cout << "New Array C is : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}