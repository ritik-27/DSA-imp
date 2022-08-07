#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        multiset<long long> bags;
        for (int i = 0; i < N; i++)
        {
            long candiescnt;
            cin >> candiescnt;
            bags.insert(candiescnt);
        }
        long long totalCandies = 0;
        for (int i = 0; i < K; i++)
        {
            auto last_ite = --bags.end(); // NOTE PREINCREMENT
            long long candiecnt = *(last_ite);
            totalCandies += candiecnt;
            bags.erase(last_ite);
            bags.insert(candiecnt / 2);
        }
        cout << totalCandies;
    }
    return 0;
}