#include <iostream>
#include <cstdio>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s)
{
    // cout << "Enter Dimensions: ";
    // cin >> s->m >> s->n;
    // cout << "Enter total num of non zero elems: ";
    // cin >> s->num;
    s->m = 4;
    s->n = 4;
    s->num = 4;
    s->e = new Element[s->num];
    // s->e[0].i = 0;
    // s->e[0].j = 1;
    // s->e[0].x = 14;

    // s->e[1].i = 1;
    // s->e[1].j = 0;
    // s->e[1].x = 24;

    // s->e[2].i = 1;
    // s->e[2].j = 1;
    // s->e[2].x = 38;
    cout << "Enter All non zero elems : row col elem" << endl;
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void Display(struct Sparse s)
{
    int i, j, k = 0;
    cout << "\nMatrix Displayed" << endl;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k].x << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    struct Sparse S1;
    Create(&S1);
    Display(S1);
    return 0;
}