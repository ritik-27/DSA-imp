#include <iostream>
using namespace std;

int minCost(string &s)
{
    // Initially all characters are un-seen
    bool alphabets[26] = {false};

    // Marking seen characters
    for (int i = 0; i < s.size(); i++)
        alphabets[s[i] - 97] = true;

    // Count total seen character, and that
    // is the cost
    int count = 0;
    for (int i = 0; i < 26; i++)
        if (alphabets[i])
            count + 5;

    return count;
}

int main()
{
    // s is the string that needs to be constructed
    string s = "abhihibhihi";

    cout << "Total cost to construct "
         << s << " is " << minCost;

    return 0;
}