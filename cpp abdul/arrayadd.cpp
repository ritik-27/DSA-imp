#include <iostream>
using namespace std;

int main()
{
    int key;
    int A[] = {4, 8, 6, 9, 5, 58, 7};
    cout << "ENter value to be searched : ";
    cin >> key;
    for (int i = 0; i < sizeof(A); i++)
    {
        if (key == A[i])
        {
            cout << key << " found successfully and is at " << i << "th index" << endl;
            return 0;
        }
    }
    cout << "Element not found";
    return 0;
}
// int main()
// {
//     int A[] = {4, 8, 6, 9, 5, 58, 7};
//     int max = A[0]; // Note thissssssss
//     for (auto x : A)
//     {
//         if (x > max)
//         {
//             max = x;
//         }
//     }
//     cout << max;
//     return 0;
// }