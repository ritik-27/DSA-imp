#include <iostream>
using namespace std;

int main()
{
    int *ptr1 = NULL;
    int **ptr2 = &ptr1;

    *ptr1 = 28;
    **ptr2 = 36;

    cout << "Value of pointer variable 1 : " << *ptr1 << endl;
    delete ptr1;
    delete ptr2;
    return 0;
}
