//*Binary search tree implemented with LL

#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int data)
    {
        this->data = data;
        this->lchild = this->rchild = NULL;
    }
};

class BST
{
private:
    Node *root = NULL, *p = NULL;

public:
    void Insert(int key);
    Node *RecInsert(int key)
    {
        return RecInsert(root, key);
    }
    Node *RecInsert(Node *root, int key);
    //-----------------------------
    void Inorder()
    {
        Inorder(root);
    };
    void Inorder(Node *root);
    void Preorder()
    {
        Preorder(root);
    };
    void Preorder(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
    //-------------------------------
    Node *Search(int key);
    Node *RecSearch(int key)
    {
        root = RecSearch(root, key);
        return root;
    }
    Node *RecSearch(Node *p, int key);
    //------------------------------------
    Node *Delete(int key);
};

void BST::Insert(int key)
{
    Node *r = NULL;
    p = root;
    if (p == NULL)
    {
        p = new Node(key);
        root = p;
        return;
    }
    while (p != NULL)
    {
        r = p;
        if (key < p->data)
        {
            p = p->lchild;
        }
        else if (key > p->data)
        {
            p = p->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node(key);
    if (p->data < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

//! LOchaa haii ulfatt
Node *BST::RecInsert(Node *q, int key)
{
    Node *r = NULL;
    if (q == NULL)
    {
        r = new Node(key);
        root = r;
        return r;
    }
    if (key < q->data)
    {
        return RecInsert(q->lchild, key);
    }
    else if (key > q->data)
    {
        return RecInsert(q->rchild, key);
    }
    // return q;
}

void BST ::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *BST ::Search(int key)
{
    Node *t = root;
    while (t != NULL)
    {
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return t;
        }
    }
    return NULL;
}

Node *BST::RecSearch(Node *t, int key)
{
    if (t != NULL)
    {
        if (key > t->data)
        {
            return RecSearch(t->rchild, key);
        }
        else if (key < t->data)
        {
            return RecSearch(t->lchild, key);
        }
        else if (key == t->data)
        {
            return t;
        }
        else
        {
            return NULL;
        }
    }
    else
        return NULL;
}

Node *BST::Delete(int key)
{
    Node *t;
}

int main()
{
    // int x;
    // cout<<"Enter root node: ";
    // cin>>x;
    BST bt;
    bt.Insert(12);
    bt.Insert(8);
    bt.Insert(20);
    bt.Insert(14);
    bt.Insert(7);
    bt.Insert(9);
    bt.Insert(24);
    bt.Insert(1);
    bt.Preorder();
    cout << endl;

    //! Lochaa haii ulfattt
    // bt.RecInsert(10);
    // bt.RecInsert(5);
    // bt.RecInsert(20);
    // bt.RecInsert(8);
    // bt.RecInsert(30);
    // bt.Inorder();
    // cout << endl;

    //*Searching the eleme
    // if (bt.Search(10)) //? iterative search
    // {
    //     cout << "Element Found !!!" << endl;
    // }
    // else
    // {
    //     cout << "Element NOTTTTT Found !!!" << endl;
    // }
    // if (bt.Search(10)) //?Recursiv search
    // {
    //     cout << "Element Found !!!" << endl;
    // }
    // else
    // {
    //     cout << "Element NOTTTTT Found !!!" << endl;
    // }

    return 0;
}
