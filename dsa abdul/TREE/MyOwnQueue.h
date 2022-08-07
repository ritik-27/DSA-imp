#ifndef MyOwnQueue_h
#define MyOwnQueue_h
#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q; // NOTEEEE

public:
    Queue()
    {
        front = rear = 0;
        size = 10;
        Q = new Node *[this->size]; // NOTEEEE
    }
    Queue(int sz)
    {
        this->size = sz;
        this->front = 0;
        this->rear = 0;
        this->Q = new Node *[this->size];
    }

    void Enqueue(Node *x);
    Node *Dequeue();
    int isEmpty();
};

void Queue::Enqueue(Node *x)
{
    if ((rear + 1) % size == front) //***
    {
        cout << "Elemnt NOT Inserted !! Queue is FULL !!" << endl;
    }
    else
    {
        rear = (rear + 1) % size; //***
        Q[rear] = x;
    }
}
Node *Queue::Dequeue() // NOTEEE
{
    Node *x = NULL; // NOTEEEEE
    if (rear == front)
    {
        cout << "Queue is EMPTY" << endl;
    }
    else
    {
        front = (front + 1) % size; //***
        x = Q[front];
    }
    return x;
}
int Queue::isEmpty()
{
    return front == rear;
}

#endif