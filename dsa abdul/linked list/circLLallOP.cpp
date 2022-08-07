#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * first;

void CreateLL(int A[], int n) //???????????????
{
    int i;
    struct Node *temp, *last;
    first = new Node;
    first->data = A[0];
    first->next = first; // NOTE**** for Single = NULL, for circular =first
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next; // NOTE*** For single= NULL, for circular= last->next
        last->next = temp;
        last = temp;
    }
}

void DisplayCircular(struct Node *p)
{
    // cout << "this is intial's address: " << p;
    do // NOTEEE THISSSSSS DO WGILE LOOP , FIRST EXECUTE THEN CHECK CONNECTION
    {
        cout << p->data << "; ";
        // cout << "this is next's address: " << p->next;
        p = p->next;
    } while (p != first);
}
void DisplayCircularRecursive(struct Node *p)
{
    static int flag = 0; // this is to avoid recreation of flag var in every recursive call
    if (p != first || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        DisplayCircularRecursive(p->next);
    }
    flag = 0;
}
int Length(struct Node *p)
{
    int counter = 1; // Note this
    while (p->next != first)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

void InsertinCirc(struct Node *p, int index, int x) // cant insert at index =0 coz logic is different if u want to include logic see in single linked allopp file
{
    if (index == 0 || index > Length(p)) // len+1 coz we r starting index frm 0;
    {
        cout << "Index is incorrect !!!!" << endl;
        cout << "Node Not addedd in the List !!!!" << endl;
    }
    else
    {
        struct Node *t;
        t = new Node;
        t->data = x;
        for (int i = 0; i < index - 1; i++) // Note this is index -1
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertAtfirstinCirc(struct Node *p, int x) // LALA now NO Locha hai ULFATTT....
{
    struct Node *t;
    struct Node *q = first;
    t = new Node;
    t->data = x;
    while (p->next != q) // LALA ERROR SORTED XD AAh YEAHH;;; loop is executing continuosly coz last node isnt pointing on first node(ERROR)
    {
        p = p->next;
    }
    p->next = t;
    t->next = first; // OR t->next=p;
    first = t;
}

int DeleteCirc(struct Node *p, int index)
{
    int elem;
    if (index == 0)
    {
        struct Node *q = first;
        while (p->next != first)
        {
            p = p->next;
        }
        p->next = q->next;
        first = q->next;
        elem = q->data;
        delete q;
        return elem;
    }
    else if (index < Length(p))
    {
        p = first;
        struct Node *q = NULL;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        elem = p->data;
        delete p;
        return elem;
    }
    else
    {
        cout << "Enter Proper index" << endl;
        return -1;
    }
}

int main()
{
    struct Node *temp;
    int A[] = {11, 22, 33, 44, 55};
    CreateLL(A, 5);

    // DisplayCircular(first);
    // DisplayCircularRecursive(first);
    // InsertinCirc(first, 5, 60); // Note here this wont be working for index = 0; Some errorrr
    // DisplayCircular(first);
    // InsertAtfirstinCirc(first, 60);
    // DisplayCircular(first);

    // cout << Length(first);

    // Circular hai to obivously loop hi hogaa
    //  STILL U CAN CHECKK FOR CONFIRMATION

    //   if (IsLoop(first))
    //   {
    //       cout << "Given list is in loop" << endl;
    //   }
    //   else
    //   {
    //       cout << "List is not in the loop" << endl;
    //   }

    // int res = DeleteCirc(first, 4);
    // if (res == -1)
    // {
    //     cout << "Node is not deleted !!!" << endl;
    // }
    // else
    // {
    //     cout << "Node successfully deleted !!!" << endl;
    //     cout << "Deleted element is : " << res << endl;
    //     DisplayCircular(first);
    // }

    return 0;
}