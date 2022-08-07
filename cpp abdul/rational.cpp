#include <iostream>
using namespace std;
class Rational
{
private:
    int p;
    int q;

public:
    Rational()
    {
        p = 1;
        q = 1;
    }
    Rational(int p, int q)
    {
        this->p = p;
        this->q = q;
    }
    Rational(Rational &r)
    {
        this->p = r.p;
        this->q = r.q;
    }
    int getP() { return p; }
    int getQ() { return q; }
    void setP(int p)
    {
        this->p = p;
    }
    void setQ(int q)
    {
        this->q = q;
    }
};

int main()
{
    Rational r1(3, 4), r2(2, 5);
    int num = r1.getP() * r2.getQ() + r2.getP() * r1.getQ();
    int denom = r1.getQ() * r2.getQ();
    cout << "Sum is " << num << "/" << denom << endl;
}