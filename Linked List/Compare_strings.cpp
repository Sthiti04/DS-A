#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
};

void InsertBeginning(struct Node** head,char ch)
{
    struct Node* temp = new Node;
    temp->data = ch;
    temp->next = NULL;
    if(*head==NULL)
        *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void Display(struct Node **head)
{
    struct Node *temp = *head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
            cout<<temp->data<<"->";
        else
            cout<<temp->data;

        temp = temp->next;
    }
    cout<<endl;
}

int CompareStrings(struct Node* list1,struct Node* list2)
{
    while(list1 && list2 && list1->data == list2->data)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    if(list1 && list2)
    {
        if(list1->data > list2->data)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if(list1 && !list2)
    {
        return 1;
    }
    if(list2 && !list1)
    {
        return -1;
    }
    return 0;
}

int main()
{
    struct Node* list1 = NULL;
    InsertBeginning(&list1,'s');
    InsertBeginning(&list1,'k');
    InsertBeginning(&list1,'e');
    InsertBeginning(&list1,'e');
    InsertBeginning(&list1,'g');
    Display(&list1);

    struct Node* list2 = NULL;
    InsertBeginning(&list2,'y');
    InsertBeginning(&list2,'k');
    InsertBeginning(&list2,'e');
    InsertBeginning(&list2,'e');
    InsertBeginning(&list2,'g');
    Display(&list2);

    cout<<"\nFinal result: ";
    cout<<CompareStrings(list1,list2);
    return 0;
}