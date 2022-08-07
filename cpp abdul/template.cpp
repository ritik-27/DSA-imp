#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);

    T add()
    {
        T c;
        c = a + b;
        return c;
    }
    T sub();
    // {
    //     T c;
    //     c = a - b;
    //     return c;
    // }
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}
template <class T>
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}
int main()
{
    Arithmetic<int> ar(5, 10);
    cout << "Addition: " << ar.add();
    cout << "Subtraction: " << ar.sub();
    return 0;
}