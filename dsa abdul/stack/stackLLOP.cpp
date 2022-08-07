#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void Push(int x)
{
    struct Node *t;
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

int Pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        struct Node *p;
        p = top;
        top = top->next;
        x = p->data;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);

    Display();

    cout << "Poped element : " << Pop() << endl;
    Display();

    return 0;
}