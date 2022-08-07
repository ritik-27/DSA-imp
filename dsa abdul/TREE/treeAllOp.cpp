#include <iostream>
#include <stdio.h>
#include "MyOwnQueue.h"
#include <stack>
using namespace std;

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    void CreateTree();

    void Preorder() // NOTEE thiss defaultt  constructorr/ funtion !!!!, this is called to initiate the function i.e for root
    {
        Preorder(root);
    }
    void Preorder(Node *t);

    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *t);

    void Postorder()
    {
        Postorder(root);
    }
    void Postorder(Node *t);

    void Levelorder()
    {
        // cout<<root->data<<" ";
        Levelorder(root);
    }
    void Levelorder(Node *t);

    int Count()
    {
        return Count(root);
    }
    int Count(Node *root);

    int Height()
    {
        return Height(root);
    }
    int Height(Node *root);

    int Max()
    {
        return Max(root);
    }
    int Max(Node *root);
    int Min()
    {
        return Min(root);
    }
    int Min(Node *root);

    int LeafCount()
    {
        return LeafCount(root);
    }
    int LeafCount(Node *root);
    int NonLeafCount()
    {
        return NonLeafCount(root);
    }
    int NonLeafCount(Node *root);

    //--------------------
    void ItePreorder()
    {
        ItePreorder(root);
    }

    void ItePreorder(Node *t) // Locha hai ulfatt in pop function
    {
        stack<Node *> st;
        while (t != NULL || !st.empty())
        {
            if (t != NULL)
            {
                cout << t->data << " ";
            }
            else
            {
                t = st.top();
                st.pop(); // Lochaa haii ulfattt
            }
        }
    }
};

void Tree::CreateTree() // Very imp See it once
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter Root Value: ";
    cin >> x;

    root = new Node; // VV imp Noteeee DONT do here Node root= new Node, it should be only root = new Node
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.Enqueue(root);

    while (!q.isEmpty()) // checking wether queue is empty or not
    {
        p = q.Dequeue(); // Removing address frm queue

        cout << "Enter Left child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node; // Dont forget here to create new node of t pointer
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.Enqueue(t); // Dont forget to push address in queue again
        }

        cout << "Enter Right child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.Enqueue(t); // Dont forget to push address in queue again
        }
    }
}

void Tree::Preorder(Node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        Preorder(t->lchild);
        Preorder(t->rchild);
    }
}
void Tree::Inorder(Node *t)
{
    if (t != NULL)
    {
        Inorder(t->lchild);
        cout << t->data << " ";
        Inorder(t->rchild);
    }
}
void Tree::Postorder(Node *t)
{
    if (t != NULL)
    {
        Postorder(t->lchild);
        Postorder(t->rchild);
        cout << t->data << " ";
    }
}
// Thodaa faarr Kichkatttt Levl order
void Tree::Levelorder(Node *t)
{
    Queue q;
    cout << t->data << " ";
    q.Enqueue(t);

    while (!q.isEmpty())
    {
        t = q.Dequeue();
        if (t->lchild)
        {
            cout << t->lchild->data << " ";
            q.Enqueue(t->lchild);
        }
        if (t->rchild)
        {
            cout << t->rchild->data << " ";
            q.Enqueue(t->rchild);
        }
    }
}

int Tree::Count(Node *t)
{
    int x, y;
    if (t)
    {
        x = Count(t->lchild);
        y = Count(t->rchild);
        return x + y + 1;
    }
    else
        return 0;
}

int Tree::Height(Node *t) // Returns Height of B tree
{
    int x = 0, y = 0;
    if (t == 0)
    {
        return 0;
    }
    else
    {
        x = Height(t->lchild);
        y = Height(t->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
}
int Tree::Max(Node *t)
{
    int x = 0, y = 0;
    if (t == 0)
    {
        return INT16_MIN; // NOTE THiSSS
    }
    else
    {
        int res = t->data;
        x = Max(t->lchild);
        y = Max(t->rchild);
        if (x > res)
        {
            res = x;
        }
        if (y > res)
        {
            res = y;
        }
        return res;
    }
}
int Tree::Min(Node *t)
{
    int x, y;
    if (t == NULL)
    {
        return INT16_MAX; // NOtee thisss
    }
    else
    {
        int res = t->data;
        x = Min(t->lchild);
        y = Min(t->rchild);
        if (x < res)
        {
            res = x;
        }
        if (y < res)
        {
            res = y;
        }
        return res;
    }
}

int Tree::LeafCount(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = LeafCount(t->lchild);
        y = LeafCount(t->rchild);
        if (t->lchild == NULL && t->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int Tree::NonLeafCount(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = NonLeafCount(t->lchild);
        y = NonLeafCount(t->rchild);
        if (t->lchild != NULL && t->rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder Traversal: " << endl;
    t.Preorder();
    cout << endl;

    cout << "Inorder Traversal: " << endl;
    t.Inorder();
    cout << endl;

    cout << "Postorder Traversal: " << endl;
    t.Postorder();
    cout << endl;

    cout << "Levelorder Traversal: " << endl;
    t.Levelorder();
    cout << endl;

    cout << "Count: " << t.Count() << endl;
    cout << "Height: " << t.Height() << endl;
    cout << "Max: " << t.Max() << endl;
    cout << "Min: " << t.Min() << endl;
    cout << "Leaf Count: " << t.LeafCount() << endl;
    cout << "Non Leaf Count: " << t.NonLeafCount() << endl;

    return 0;
}