#include <iostream>
using namespace std;

int main()
{
    char A[] = "welcOMe hero to   the new world";
    int i = 0;
    int spcount = 0;
    while (A[i] != '\0')
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
        {
            spcount++;
        }

        i++;
    }
    cout << spcount + 1;

    return 0;
}
