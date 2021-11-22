#include<stdio.h>
#include<stdlib.h>
#define bool int

struct snode{
    char data;
    struct snode* next;
};

void push(struct snode** top,int data);
int pop(struct snode** top);

bool isMatchingPair(char ch1,char ch2)
{
    if(ch1=='(' && ch2==')')
        return 1;
    else if(ch1=='{' && ch2=='}')
        return 1;
    else if(ch1=='[' && ch2==']')
        return 1;
    else
        return 0;
}

bool checkBalanced(char exp[])
{
    int i=0;
    struct snode* stack=NULL;

    while(exp[i])
    {
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
           push(&stack,exp[i]);

        if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
        {
            if(stack==NULL)
               return 0;
            else if(!isMatchingPair(pop(&stack),exp[i]))
               return 0;
        }
        i++;
    }
    if(stack==NULL)
       return 1; //balanced
    else
       return 0; //not balanced
}

int main()
{
    char exp[100]="{()}]";
    if(checkBalanced(exp))
       printf("Balanced \n");
    else
       printf("Not Balanced \n");
    return 0;
}

void push(struct snode** top,int newdata)
{
    struct snode* new_node=(struct snode*)malloc(sizeof(struct snode));
    if(new_node==NULL)
    {
        printf("Stack overflow \n");
    }
    new_node->data=newdata;
    new_node->next=*top;
    *top=new_node;
}

int pop(struct snode** top_ref)
{
    char res;
    struct snode* top;

    if(top_ref==NULL)
    {
        printf("Stack overflow\n");
    }
    else{
        top=*top_ref;
        res=top->data;
        *top_ref=top->next;
        free(top);
        return res;
    }
}