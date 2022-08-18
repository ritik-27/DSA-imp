#include <bits/stdc++.h>
using namespace std;

void findMin(int val)
{
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int n = sizeof(deno) / sizeof(deno[0]);
    sort(deno, deno + n);

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (val >= deno[i])
        {
            val = val - deno[i];
            ans.push_back(deno[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 20206;
    cout << "Following is minimal"
         << " number of change for " << n << ": ";
    findMin(n);
    return 0;
}