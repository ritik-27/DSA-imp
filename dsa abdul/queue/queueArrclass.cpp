#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int *Q;

public:
    int size;
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[this->size];
    }
    Queue(int sz)
    {
        this->size = sz;
        this->front = -1;
        this->rear = -1;
        this->Q = new int[this->size];
    }

    void Enqueue(int x);
    int Dequeue();
    void Display();
};
void Queue::Enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Elemnt Not Inserted !! Queue is FULL !!" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::Dequeue()
{
    int x = -1;
    if (rear == front)
    {
        cout << "Queue is EMPTY" << endl;
    }
    else
    {
        x = Q[front + 1]; // Note thisss
        front++;
    }
    return x;
}
void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);
    q.Enqueue(11);
    q.Enqueue(22);
    q.Enqueue(33);
    q.Enqueue(44);
    q.Enqueue(55);

    q.Display();
    q.Dequeue();
    q.Display();

    return 0;
}