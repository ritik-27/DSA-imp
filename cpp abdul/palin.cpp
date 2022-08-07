#include <iostream>
using namespace std;

string checkPalindrome(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            return "false";
        }
    }
    return "true";
}

int reverse(int num)
{
    int r = 0, temp = 0;
    while (num > 0)
    {
        r = num % 10;
        num = num / 10;
        temp = temp * 10 + r;
    }

    return temp;
}

int armstrng(int num)
{
    int t = num;
    int sum = 0;
    int r;
    while (num > 0)
    {
        r = num % 10;
        sum = sum + (r * r * r);
        num = num / 10;
    }
    return sum;
}

int main()
{
    // string str = "adcda";
    // cout << checkPalindrome(&str);
    // int num = 121;
    // int revnum = reverse(121);
    // if (num == reverse(num))
    // {
    //     cout << "true";
    // }
    // else
    // {
    //     cout << "false";
    // }

    int num = 407;
    int sum = armstrng(num);
    if (num == sum)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}