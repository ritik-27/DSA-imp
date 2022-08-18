#include <bits/stdc++.h>

using namespace std;

class Battleship
{
public:
    string teamName;
    int sectorX;
    int sectorY;
};

void printCor(vector<Battleship> &v)
{
    map<pair<int, int>, int> m;

    int maxy = INT_MIN;
    int maxx = INT_MIN;

    map<pair<int, int>, string> mp;

    for (int i = 0; i < v.size(); i++)
    {
        mp[{v[i].sectorX, v[i].sectorY}] = v[i].teamName;
        maxx = max(maxx, v[i].sectorX);
        maxy = max(maxy, v[i].sectorY);
    }

    for (int i = maxy; i > 0; i--)
    {

        for (int j = 1; j <= maxx; j++)
        {
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 1; j <= maxx; j++)
        {
            cout << "|";
            if (mp.find({j, i}) != mp.end())
            {
                if (m.find({j, i}) != m.end())
                {
                    string t = mp[{j, i}];
                    for (int i = 0; i < t.length(); i++)
                    {
                        t[i] = tolower(t[i]);
                    }
                    cout << " " << t << " ";
                }
                else
                {
                    cout << " " << mp[{j, i}] << " ";
                }
                m.clear();
                m[{j - 1, i}]++;
                m[{j - 1, i - 1}]++;
                m[{j - 1, i + 1}]++;
                m[{j, i - 1}]++;
                m[{j + 1, i - 1}]++;
                m[{j + 1, i}]++;
                m[{j + 1, i + 1}]++;
                m[{j, i + 1}]++;
            }
            else
            {
                cout << "   ";
            }
        }
        cout << "| " << i << endl;
    }
    for (int j = 1; j <= maxx; j++)
    {
        cout << "+---";
    }
    cout << "+" << endl;
    for (int i = 1; i <= maxx; i++)
    {
        cout << "  " << i << " ";
    }
}

int main()
{
    vector<Battleship> v;
    v.push_back({"ALPHA", 3, 5});
    v.push_back({"Z", 7, 1});
    v.push_back({"Z", 7, 1});
    v.push_back({"ZABJSHB", 4, 4});
    v.push_back({"A", 2, 6});

    printCor(v);
}
