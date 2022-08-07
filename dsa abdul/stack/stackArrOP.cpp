#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int Top;
    int *S;
};

void Create(Stack *st, int x)
{
    // cout << "Enter Size of Stack: ";
    // cin >> st->size;
    st->Top = -1;
    st->S = new int[x];
}

void Display(Stack st)
{
    for (int i = st.Top; i >= 0; i--)
    {
        cout << st.S[i] << " ";
    }
    cout << endl;
}

void Push(Stack *st, int x)
{
    if (st->Top == st->size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        st->Top++;
        st->S[st->Top] = x;
    }
}

int Pop(Stack *st)
{
    int x = -1;
    if (st->Top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = st->S[st->Top];
        st->Top--;
    }
    return x;
}

int Peek(Stack st, int index)
{
    int x = -1;
    if (st.Top - index + 1 <= 0)
    {
        cout << "Invalid index" << endl;
    }
    x = st.S[st.Top - index + 1];
    return x;
}

int StackTop(Stack st)
{
    if (st.Top != -1)
    {
        return st.S[st.Top];
    }
    else
        return -1;
}

int main()
{
    struct Stack st;
    st.size = 4;
    Create(&st, st.size);

    Push(&st, 11);
    Push(&st, 22);
    Push(&st, 33);
    Push(&st, 44);
    cout << "After Push: " << endl;
    Display(st);

    // cout << "Poped out an element which is : " << Pop(&st) << endl;
    // cout << "Poped out an element which is : " << Pop(&st) << endl;
    // cout << "After POP: " << endl;
    // Display(st);
    // cout << "Stack Top: " << StackTop(st) << endl;
    cout << "Peek: " << Peek(st, 2);

    return 0;
}