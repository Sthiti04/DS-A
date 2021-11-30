#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void removeLoop(struct Node*,struct Node*);

int detectAndRemoveLoop(struct Node *head)
{
    struct Node *slow=head;
    struct Node *fast=head;

    while(slow&&fast&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    if(slow==fast)
    {
        removeLoop(slow,head);
        return 1;
    }

    return 0;
}

void removeLoop(struct Node *loop,struct Node *head)
{
    struct Node *ptr1=loop;
    struct Node *ptr2=loop;

    unsigned int k=1,i;
    while(ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        k++;
    }
    ptr1=head;
    ptr2=head;
    for(i=0;i<k;i++)
       ptr2=ptr2->next;

    while(ptr2!=ptr1)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    while(ptr2->next!=ptr1)
    {
        ptr2=ptr2->next;
    }
    ptr2->next=NULL;
}

void printList(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

struct Node* newnode(int data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node*));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void insert(struct Node** head,int data)
{
    struct Node* new_node=newnode(data);
    new_node->next=(*head);
    (*head)=new_node;
}

int main()
{
    struct Node *head=NULL;
    insert(&head,10);
    insert(&head,9);
    insert(&head,8);
    insert(&head,7);
    insert(&head,6);
    
    head->next->next->next->next->next=head->next->next;
    detectAndRemoveLoop(head);
    printf("\nLinked list after removing loop:\n");
    printList(head);
}