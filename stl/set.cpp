#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    set<int> s1;
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);

    // for (auto &x : s1)
    // {
    //     cout << x << " ";
    // }

    set<int, greater<int>>::iterator itr;
    cout << "S1 Vector: " << endl;
    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    set<int> s2(s1.begin(), s1.end()); // copied elems of s1 in s2

    s2.erase(30);
    s2.erase(20);
    cout << "S2 vector: " << endl;
    for (itr = s2.begin(); itr != s2.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << *s1.lower_bound(40);

    return 0;
}