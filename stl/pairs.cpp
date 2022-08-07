#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, string> p1;
    p1.first = 10;
    p1.second = "RJ";
    //?OR
    p1 = make_pair(28, "abcd");

    pair<int, string> p2(27, "p"); // Initialized at time of dec.
    cout << p1.first << " ";
    cout << p1.second;

    return 0;
}