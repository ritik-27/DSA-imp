#include <iostream>
using namespace std;
// logic is simply make rear=front =0 instead of making it -1;
// Also to mak it circular bring rear to (rear+1)%size;
// NOte changesss marked ****
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
        front = rear = 0; //****
        size = 10;
        Q = new int[this->size];
    }
    Queue(int sz)
    {
        this->size = sz;
        this->front = 0; //***
        this->rear = 0;  //***
        this->Q = new int[this->size];
    }

    void Enqueue(int x);
    int Dequeue();
    void Display();
};
void Queue::Enqueue(int x)
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

int Queue::Dequeue()
{
    int x = -1;
    if (front == rear)
    {
        cout << "Queue is EMPTY" << endl;
    }
    else
    {
        front = (front + 1) % size; //***
        x = Q[front];               // Note thisss
    }
    return x;
}

void Queue::Display()
{
    int i = front + 1;
    do
    {
        cout << Q[i] << " ";
        i = (i + 1) % size;           //***
    } while (i != (rear + 1) % size); //***
    cout << endl;
}

int main()
{
    Queue q(5);
    q.Enqueue(11);
    q.Enqueue(22);
    q.Enqueue(33);
    q.Enqueue(44);
    q.Dequeue();
    q.Enqueue(55);
    // q.Enqueue(66);

    q.Display();

    return 0;
}