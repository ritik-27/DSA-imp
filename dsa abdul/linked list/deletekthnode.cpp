#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void displaylist(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void freelist(Node *ptr)
{
    while (ptr != NULL)
    {
        Node *next = ptr->next;
        delete (ptr);
        ptr = next;
    }
}

struct Node *kthnode(struct Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    { // we'll have to delete evry node for k=1
        while (head != NULL)
        {
            Node *next = head->next;
            delete (head);
            head = next;
        }
        // freelist(head);
        return NULL;
    }
    else
    {
        Node *ptr = head, *prev = NULL;
        int count = 0;
        while (ptr != NULL)
        {
            count++;

            if (k == count)
            {
                delete (prev->next);
                prev->next = ptr->next;

                count = 0;
            }

            if (count != 0)
            {
                prev = ptr;
            }
            ptr = prev->next;
        }
    }
    return head;
}

struct Node *deleteatindex(struct Node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *ptr = head;
    if (index == 0)
    {
        head = ptr->next;
        delete (ptr);
        return head;
    }
    else
    {
        Node *prev = NULL;
        // int count = 0;
        for (int i = 0; ptr != NULL && i < index; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        delete ptr;

        return head;
    }
}

int main()
{
    struct Node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);
    head->next->next->next->next->next = newNode(60);
    head->next->next->next->next->next->next = newNode(70);
    head->next->next->next->next->next->next->next = newNode(80);

    // head = kthnode(head, 1);
    head = deleteatindex(head, 8);
    displaylist(head);
    return 0;
}