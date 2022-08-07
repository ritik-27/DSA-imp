#include <iostream>
using namespace std;

class Stack
{
private:
    int Top;
    int *S;

public:
    int size;
    Stack(int sz)
    {
        this->Top = -1;
        this->size = sz;
        S = new int[this->size];
    }

    // void Create(int x);
    void Display();
    void Push(int x);
    int Pop();
    int Peek(int index);
    int StackTop();
};

// void Stack::Create(int x)
// {
//     // cout << "Enter Size of Stack: ";
//     // cin >> st->size;
//     st->Top = -1;
//     st->S = new int[x];
// }

void Stack::Display()
{
    for (int i = Top; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}

void Stack::Push(int x)
{
    if (Top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        Top++;
        S[Top] = x;
    }
}

int Stack::Pop()
{
    int x = -1;
    if (Top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = S[Top];
        Top--;
    }
    return x;
}

int Stack::Peek(int index) // Position in stck
{
    int x = -1;
    if (Top - index + 1 <= 0)
    {
        cout << "Invalid index" << endl;
    }
    x = S[Top - index + 1];
    return x;
}

int Stack::StackTop() // Returns Top Elem of stckk
{
    if (Top != -1)
    {
        return S[Top];
    }
    else
        return -1;
}

int main()
{
    int size;
    cout << "Enter the size of stack: " << endl;
    cin >> size;
    Stack st(size);

    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Display();

    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    st.Display();

    return 0;
}