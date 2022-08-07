#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> &v)
{

    v.push_back(41);
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(21);
    v.push_back(23);
    // printVec(v);

    vector<int> v2 = v;
    v.push_back(36);
    printVec(v2);

    return 0;
}