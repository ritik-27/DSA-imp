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
    void Create();
    void Display();
};

void Sparse::Create()
{
    cout << "Enter Dimensions: ";
    cin >> m >> n;
    cout << "Enter total num of non zero elems: ";
    cin >> num;
    cout << "Enter All non zero elems : row col elem" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> e[i].i >> e[i].j >> e[i].x;
    }
}

void Sparse::Display()
{
    int i, j, k = 0;
    cout << "\nMatrix Displayed" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (e[k].i == i && e[k].j == j)
            {
                cout << e[k++].x << " ";
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
    Sparse S1(3, 3, 4);
    S1.Create();
    S1.Display();
    return 0;
}