#include <iostream>
using namespace std;

int main()
{
    int i, sum = 0;
    float avg = 0;
    int A[] = {2, 3, 4, 11, 6, 10};
    for (auto x : A)
    {
        sum += x;
    }
    avg = (float)(sum / 6);
    cout << "Avg : " << avg;
    return 0;
}