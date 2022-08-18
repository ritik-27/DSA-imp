#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *NewNode(int new_data)
{
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;
}

void sortedInsert(Node **head_ref, Node *new_Node)
{
    Node *current;

    // case for inserting before head
    if (*head_ref == NULL || (*head_ref)->data >= new_Node->data)
    {
        new_Node->next = *head_ref;
        *head_ref = new_Node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_Node->data)
        {
        }
    }
}

int main()
{

    return 0;
}