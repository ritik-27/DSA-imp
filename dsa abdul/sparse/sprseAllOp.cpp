#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;

public:
    Element *e;
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] e;
    }

    Sparse operator+(Sparse &s);
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
    // void Create();
    // void Display();
};
// Insertion
istream &operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements: row col elem" << endl;
    for (int i = 0; i < s.num; i++)
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    return is;
}
// Extraction or display
ostream &operator<<(ostream &os, Sparse &s)
{
    // cout << "Enter Dimensions: ";
    // cin >> s.m >> s.n;
    // cout << "Enter total num of non zero elems: ";
    // cin >> s.num;
    int k = 0;
    cout << "\nMatrix Displayed" << endl;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
                cout << s.e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
        return Sparse(0, 0, 0);
    Sparse *sum = new Sparse(m, n, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i)
            sum->e[k++] = e[i++];
        else if (e[i].i > s.e[j].i)
            sum->e[k++] = s.e[j++];
        else
        {
            if (e[i].j < s.e[j].j)
                sum->e[k++] = e[i++];
            else if (e[i].j > s.e[j].j)
                sum->e[k++] = s.e[j++];
            else
            {
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->e[k++] = e[i];
    for (; j < s.num; j++)
        sum->e[k++] = s.e[j];
    sum->num = k;

    return *sum;
}

// void Sparse::Create()
// {
//     cout << "Enter Dimensions: ";
//     cin >> m >> n;
//     cout << "Enter total num of non zero elems: ";
//     cin >> num;
//     cout << "Enter All non zero elems : row col elem" << endl;
//     for (int i = 0; i < num; i++)
//     {
//         cin >> e[i].i >> e[i].j >> e[i].x;
//     }
// }

// void Sparse::Display()
// {
//     int i, j, k = 0;
//     cout << "\nMatrix Displayed" << endl;
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             if (e[k].i == i && e[k].j == j)
//             {
//                 cout << e[k++].x << " ";
//             }
//             else
//             {
//                 cout << "0 ";
//             }
//         }
//         cout << endl;
//     }
// }

int main()
{
    Sparse S1(3, 3, 3);
    Sparse S2(3, 3, 3);

    cout << "For First matrix:" << endl;
    cin >> S1;
    cout << "For Second matrix:" << endl;
    cin >> S2;

    Sparse sum = S1 + S2;

    cout << "\n\nFirst " << S1 << endl
         << "------------------------" << endl;
    cout << "Second " << S2 << endl
         << "------------------------" << endl
         << endl;
    cout << "Sum " << sum << endl
         << "------------------------";

    return 0;
}