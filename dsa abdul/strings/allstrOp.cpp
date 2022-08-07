#include <iostream>
using namespace std;
int Validstr(char *A)
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (!(A[i] >= 65 && A[i] <= 90) && !(A[i] >= 97 && A[i] <= 122 && !(A[i] >= 48 && A[i] <= 57)))
        {
            return 0;
        }
    }
    return 1;
}

void Reverse(char *A)
{
    char B[10];
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << B;
}

void Reverse2(char *A)
{
    int i, j;
    char temp;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    cout << A;
}

// FInding duplicates using hashing
void duplicate2(char *A)
{
    int H[26];
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << char(i + 97) << " : " << H[i] << endl;
        }
    }
}

int anagram(char *A, char *B) // using hashing
{
    int H[26];
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97]--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // char *A = "welcomooe";
    // if (Validstr(A))
    // {
    //     cout << "Special chars are Not present" << endl;
    // }
    // else
    // {
    //     cout << "Special chars are present";
    // }

    // Reverse(A);
    // Reverse2(A);

    // duplicate2(A);

    char *A = "twiangle";
    char *B = "integral";

    if (anagram(A, B))
    {
        cout << "This is anagram";
    }
    else
    {
        cout << "Not ANagram";
    }

    return 0;
}
