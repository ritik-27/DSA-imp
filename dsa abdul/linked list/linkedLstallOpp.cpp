#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * first;
Node *second = NULL;
Node *third = NULL;

void CreateLL(int A[], int n) //???????????????
{
    int i;
    struct Node *temp, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL; // NOTE**** for Single = NULL, for circular =first
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL; // NOTE*** For single= NULL, for circular= last->next
        last->next = temp;
        last = temp;
    }
}

void CreateLL2(int B[], int n) //???????????????
{
    struct Node *temp, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = B[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void DisplayLL(struct Node *p)
{
    cout << "Displaying Linked List: " << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RecDisplayLL(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        RecDisplayLL(p->next);
    }
}

int Counter(struct Node *p)
{
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    return counter;
}
int Sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int Maximum(struct Node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data >= max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int Minimum(struct Node *p)
{
    int min = INT32_MAX;
    while (p != NULL)
    {
        if (p->data <= min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

struct Node *Linearsrch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Insert(int index, int x)
{
    struct Node *t = NULL;
    // if (index < 0 || index > Counter(p))
    // {
    //     cout << "Invalid index" << endl;
    //     return;
    // }
    t->data = x;
    if (index == 0)
    {
        t->next = first; // here u cant do =p even if p is passed as param.
        first = t;
        t = NULL;
    }
    else
    {
        struct Node *p;
        p = new Node;
        p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
void InsertFirst(struct Node *p, int x)
{
    struct Node *t = new Node;
    t->data = x;
    t->next = p;
    first = t;
    t = NULL;
}
void InsertLast(struct Node *p, int x) // LOCHaaa hai ulfatt
{
    // struct Node *t;
    struct Node *last;
    // t = new Node;
    // last = new Node;
    // t->data = x;
    // t->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    last->next = NULL;
    last->data = x;
    p->next = last;
    // if ( == NULL)
    // {
    //     first = last = t;
    // }
    // else
    // {
    //     last->next = t;
    //     last = t;
    // }
}

void InsertinSOrted(struct Node *p, int x)
{
    struct Node *q;
    q = new Node;
    q = NULL;
    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    struct Node *t;
    t = new Node;
    t->data = x;
    t->next = q->next;
    q->next = t;
}

int Delete(struct Node *p, int index)
{
    int x;
    struct Node *t = NULL;
    if (index == 0)
    {
        t = p;
        x = p->data;
        // p = p->next;      //isSE GHANTAA KUCHH NA HOGAA GLOBAL WALA FIRST KO NEXT POINT KARWANA PADEGA
        first = first->next; // VERYYYY VERYY IMPORTANT*****
        delete t;
        return x;
    }
    else if (index < Counter(p))
    {
        for (int i = 0; i < index && p; i++)
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
    else
    {
        return -1;
    }
}

int IsSorted(struct Node *p)
{
    int x = INT16_MIN;
    while (p != NULL)
    {
        if (p->data >= x)
        {
            x = p->data;
            p = p->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void duplicates(struct Node *p)
{
    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Reversing just the elements of Node, NOT reversing links ** this method NOT preferred
void reverseData(struct Node *p)
{
    int *A; // Created an Auxiliary Array
    int length = Counter(p);
    A = new int[length];
    int i = 0;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;

    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}
// Reversing the links **Mostly preferred
void reverseLinks(struct Node *p)
{
    Node *q = NULL, *r = NULL; // THis are called sliding pointers

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
// KICHKATTTTTTTT
void RecursiveReverseLinks(struct Node *p, struct Node *q)
{
    if (p != NULL)
    {
        RecursiveReverseLinks(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// Directly concatinating 2 linked lists
void Concatenate(struct Node *p, struct Node *q)
{
    p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

// Thodaa faarrr kichkatttt
//  Merging 2 sorted linked list and making a final sorted linked list...
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else if (q->data < p->data)
    {
        last = third = q;
        q = q->next;
        third->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int IsLoop(struct Node *p)
{
    Node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
    } while (p && q && p != q);
    if (p == q)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Middle(struct Node *p) // instead od finding length and then traversing othr node to len/2.., this method could be more usefull
{
    struct Node *q = first;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
            p = p->next;
        }
    }
    return p->data;
}

int main()
{
    struct Node *temp;
    int A[] = {11, 22, 33, 44, 55, 66};
    CreateLL(A, 6);

    // Basic:count, max,sum
    //  DisplayLL(first);
    //  RecDisplayLL(first); //Recusive function call
    // cout << "Number of elems: " << Counter(first) << endl;
    //  cout << "Sum of of elems: " << Sum(first) << endl;
    //  cout << "Maximum of of elems: " << Maximum(first) << endl;
    //  cout << "Minimum of of elems: " << Minimum(first) << endl;

    // Linear Search
    //  int key = 25;
    //  temp = Linearsrch(first, key);
    //  if (temp)
    //  {
    //      cout << "Element '" << temp->data << "' FOund !!!!" << endl;
    //  }
    //  else
    //  {
    //      cout << "Element '" << key << "' not found !!!!" << endl;
    //  }

    // Insertion
    //  Insert(2, 12);
    //  DisplayLL(first);
    // InsertLast(first, 12); // Lochaa haii ULFAttt
    // DisplayLL(first);

    // Deletion
    // cout << "Deleted Element: " << Delete(first, 0) << endl;
    // DisplayLL(first);

    // if (IsSorted(first))
    // {
    //     cout << "List is Sorted" << endl;
    // }
    // else
    // {
    //     cout << "Not SOrted !!!" << endl;
    // }

    // duplicates(first);
    // DisplayLL(first);

    // reverseData(first);
    // DisplayLL(first);
    // reverseLinks(first);
    // DisplayLL(first);
    // RecursiveReverseLinks(NULL, first); // KICHKATTTTT
    // DisplayLL(first);
    // int B[] = {13, 26, 45, 71, 78};
    // CreateLL2(B, 5);
    // cout << "Second LL: " << endl;
    // DisplayLL(second);
    // cout << "Merged LL: " << endl;
    // Concatenate(first, second);
    // DisplayLL(first);

    // int B[] = {13, 26, 45, 71, 78};
    // CreateLL2(B, 5);
    // Merge(first, second);
    // DisplayLL(third);

    // THis is how loop of linked list is created
    // struct Node *temp2;
    // temp = first->next->next;
    // temp2 = first->next->next->next->next;
    // temp2->next = temp;

    // if (IsLoop(first))
    // {
    //     cout << "Given list is in loop" << endl;
    // }
    // else
    // {
    //     cout << "List is not in the loop" << endl;
    // }

    cout << "Middle element of list is : " << Middle(first) << endl;
    return 0;
}