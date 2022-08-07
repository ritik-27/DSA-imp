#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
void Create(int A[], int n) // Almost same as singleLL
{
    struct Node *temp, *last;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL; // NOTE**** for Single = NULL, for circular =first
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next; // NOTE*** For single= NULL, for circular and Doubly = last->next
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p) // Same as single LL
{
    cout << "Displaying Linked List: " << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Counter, sum,max, min same as single linked list;
int Length(struct Node *p)
{
    int counter = 1; // Note this
    while (p->next)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

void InsertatFirst(struct Node *p, int x)
{
    p = first;
    struct Node *t;
    t = new Node;
    t->data = x;
    t->prev = NULL;
    t->next = p;     // Note thiss =p its will NOT be p->next
    first->prev = t; // Note thiss =t its will NOT be t->next
    first = t;
    t = NULL;
}

void InsertatIndex(struct Node *p, int index, int x) // cant insert at index = 0 coz logic is different if u want that just insrt above functions line in if(index==0) block
{
    if (index == 0 || index > Length(p)) // len+1 coz we r starting index frm 0;
    {
        cout << "Index is incorrect !!!!" << endl;
    }
    else
    {

        struct Node *t;
        t = new Node;
        t->data = x;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL) // Notee Dont forget to check wether node is present next to indexed p
        {
            t->next->prev = t; // Note *** Accessing next of p
        }
        p->next = t;
    }
}

int DeleteDL(struct Node *p, int index) // Halka fulkaa Lochaa, krta baad mai sort
{
    struct Node *t;
    int elem;
    if (index == 0)
    {
        t = p;
        elem = t->data;
        p = t->next;
        p->prev = NULL;
        first = p;
        delete t;
        return elem;
    }
    else if (index < Length(p))
    {
        for (int i = 0; i < index + 1; i++)
        {
            t = t->next;
        }
        t->next = p;
        // p=t->prev;
        elem = t->data;
        p->next = t->next;
        delete t;
        return elem;
    }
    else
    {
        return -1;
    }
}

void ReverseDL(struct Node *p) // KICHKAATTTTTT
{
    struct Node *t;
    // temp = new Node;
    while (p != NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    // struct Node *temp;
    int A[] = {11, 22, 33, 44, 55};
    Create(A, 5);
    // Display(first);

    // InsertatFirst(first, 27);
    // Display(first);

    // InsertatIndex(first, 6, 27);
    // Display(first);

    // int res = DeleteDL(first, 2);
    // if (res == -1)
    // {
    //     cout << "Node is not deleted !!!" << endl;
    // }
    // else
    // {
    //     cout << "Node successfully deleted !!!" << endl;
    //     cout << "Deleted element is : " << res << endl;
    //     Display(first);
    // }
    ReverseDL(first);
    Display(first);

    return 0;
}