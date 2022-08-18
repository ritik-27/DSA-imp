// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// possible pairs of gloves
int cntgloves(int arr[], int n)
{
    unordered_map<int, int> m;

    // Traversing through the array
    for (int i = 0; i < n; i++)
    {
        // Counting frequency
        m[arr[i]] += 1;
    }

    // To store the required count
    int count = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        count += (it->second) / 2;
    }

    return count;
}

// Driver code
int main()
{
    int arr[] = {6, 5, 2, 3, 5, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << cntgloves(arr, n);

    return 0;
}

// This code was contributed by pushpeshrajdx01
