#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head,int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=(*head);
    (*head)=newnode;
}

void print(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void skipMdeleteN(struct Node *head,int M,int N)
{
    struct Node *curr=head,*temp;
    int count;
    while(curr)
    {
        for(count=1;count<M&&curr!=NULL;count++)
             curr=curr->next;

        if(curr==NULL)
            return;

        temp=curr->next;
        for(count=1;count<=N&&temp!=NULL;count++)
        {
            struct Node *t=temp;
            temp=temp->next;
            free(t);
        }
        curr->next=temp;

        curr=temp;    
    }
}

int main()
{
    struct Node *head=NULL;
    int m=3,n=2;
    for(int i=1;i<=10;i++)
    {
        push(&head,i);
    }
    printf("\nGiven linked list:\n");
    print(head);

    skipMdeleteN(head,m,n);

    printf("\nLinked list after modification:\n");
    print(head);
}