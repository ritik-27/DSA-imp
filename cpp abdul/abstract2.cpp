#include <bits/stdc++.h>
using namespace std;

class Shape
{
protected:
    int dimension;

public:
    void getDimension()
    {
        cin >> dimension;
    }

    virtual int calculateArea() = 0;
};

class Square : public Shape
{
public:
    int calculateArea()
    {
        return dimension * dimension;
    }
};

int main()
{
    Square s1;
    cout << "Enter Square dimension: ";
    s1.getDimension();
    cout << "Area of sq: " << s1.calculateArea();

    return 0;
}