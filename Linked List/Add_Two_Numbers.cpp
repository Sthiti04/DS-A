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
    cout<<endl;
}

void Swap(Node** a,Node** b)
{
    Node *t = *a;
    *a = *b;
    *b = t;
}

int getSize(Node* temp)
{
    int size = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

Node* AddSameSize(Node *head1,Node *head2,int *carry)
{
    if(head1 == NULL)
        return NULL;
    int sum;
    Node* result = new Node[sizeof(Node)];

    result->next = AddSameSize(head1->next,head2->next,carry);

    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    result->data = sum;
    return result;
}

void AddCarryToRemaining(Node* head1,Node* curr,int* carry,Node** result)
{
    int sum;
    if(head1 != curr)
    {
        AddCarryToRemaining(head1->next,curr,carry,result);
        sum = head1->data + *carry;
        *carry = sum / 10;
        sum %= 10;

        PushNode(result,sum);
    }
}

void AddList(Node* head1,Node* head2,Node** result)
{
    Node* curr;
    if(head1==NULL)
    {
        *result = head2;
        return;
    }
    if(head2==NULL)
    {
        *result = head1;
        return;
    }
    int size1 = getSize(head1);
    int size2 = getSize(head2);
    int carry = 0;

    if(size1 == size2)
        *result = AddSameSize(head1,head2,&carry);
    else
    {
        int diff = abs(size1 - size2);
        if(size1 < size2);
            Swap(&head1,&head2);

        for(curr = head1; diff--; curr = curr->next);

        *result = AddSameSize(curr,head2,&carry);

        AddCarryToRemaining(head1,curr,&carry,result); 
    }
    if(carry)
        PushNode(result,carry);

}

int main()
{
    Node *head1 = NULL, *head2 = NULL, *result = NULL;
    int arr1[] = {5,6,3};
    int arr2[] = {8,4,2};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    for(int i = size1-1; i>=0; i--)
        PushNode(&head1,arr1[i]);
    for(int i = size2-1; i>=0; i--)
        PushNode(&head2,arr2[i]);

    PrintList(head1);
    PrintList(head2);
    AddList(head1,head2,&result);

    PrintList(result);

    return 0;
}