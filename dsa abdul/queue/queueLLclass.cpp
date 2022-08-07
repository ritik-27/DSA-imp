#include <iostream>
using namespace std;
// LOCHaaa hauu ulfattt
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void Enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::Enqueue(int x)
{
    Node *t = new Node(x);
    if (t == NULL)
    {
        cout << "Queue is FULL !!! Elem not inserted" << endl;
    }
    else
    {
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::Dequeue()
{
    int x = -1;
    Node *p;
    if (front == NULL)
    {
        cout << "Queue Is Emptyyy!!" << endl;
    }
    else
    {
        p = front;
        x = front->data;
        front = front->next;
        delete p;
    }
    return x;
}
void Queue::Display()
{
    Node *p;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Queue q1;
    q1.Enqueue(11);
    q1.Enqueue(22);
    q1.Enqueue(33);
    q1.Enqueue(44);
    q1.Enqueue(55);
    q1.Display();
    return 0;
}