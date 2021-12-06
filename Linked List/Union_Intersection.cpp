#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void PushNode(Node **head,int x)
{
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = *head;
    (*head) = new_node;
}

void PrintList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool isPresent(Node* head,int x)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node* getUnion(Node *head1,Node *head2)
{
    Node *result = NULL;
    struct Node *temp1 = head1, *temp2 = head2;
    while(temp1!=NULL)
    {
        PushNode(&result,temp1->data);
        temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
        if(!isPresent(result,temp2->data))
            PushNode(&result,temp2->data);
        temp2 = temp2->next;
    }
    return result;
}

Node* getIntersection(Node* head1,Node* head2)
{
    Node* result = NULL;
    Node* temp1 = head1;
    while(temp1!=NULL)
    {
        if(isPresent(head2,temp1->data))
            PushNode(&result,temp1->data);
        temp1 = temp1->next;
    }
    return result;
}

int main()
{
    Node *head1 = NULL;
    PushNode(&head1,3);
    PushNode(&head1,5);
    PushNode(&head1,12);
    PushNode(&head1,10);
    PushNode(&head1,15);

    Node* head2 = NULL;
    PushNode(&head2,4);
    PushNode(&head2,10);
    PushNode(&head2,12);
    PushNode(&head2,16);

    Node *Union = NULL, *Intersect = NULL;

    cout<<endl;
    Union = getUnion(head1,head2);
    PrintList(Union);

    cout<<endl;
    Intersect = getIntersection(head1,head2);
    PrintList(Intersect);

    return 0;
}