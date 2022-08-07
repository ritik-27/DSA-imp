#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void Push(int x);
    int Pop();
    void Display();
};
void Stack::Push(int x)
{
    Node *t;
    t = new Node;
    if (t == NULL)
    {
        cout << "Stack is FUll so new node cant be created" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::Pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is Empty, Element cannot be POPED out." << endl;
    }
    else
    {
        Node *p;
        p = top;
        top = top->next;
        x = p->data;
    }
    return x;
}

void Stack::Display()
{
    Node *p;
    p = top;
    cout << "Displaying List: " << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    st.Push(60);
    st.Display();

    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    cout << "Poped element : " << st.Pop() << endl;
    st.Display();
    return 0;
}