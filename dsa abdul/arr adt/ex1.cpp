#include <iostream>
using namespace std;
class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        int low = 4;
        int high = 8;
        int *A;
        A = new int[high];
        for (int i = 0; i < high; i++)
        {
            A[i] = 0;
            A[arr[i]] = 1;
        }

        for (int i = 0; i < high; i++)
        {
            if (A[arr[i]] == 1)
            {
            }
        }
    }
};
int main()
{
    Solution s1;
    int arr[5] = {4, 6, 8, 5, 7};
    int small = s1.kthSmallest(arr, 0, 4, 3);
    return 0;
}