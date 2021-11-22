#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100

struct Stack
{
    int top;
    int items[STACKSIZE];
};

void push(struct Stack* st,int x)
{
    if(st->top==STACKSIZE-1)
    {
        printf("Error: Stack overflow");
        getchar();
        exit(0);
    }
    else{
        st->top+=1;
        int top=st->top;
        st->items[top]=x;
    }
}

bool isEmpty(struct Stack* st)
{
    return (st->top==-1)?true:false;
}

int pop(struct Stack* st)
{
    int temp;
    if(st->top==-1)
    {
        printf("Error: stack underflow");
        getchar();
        exit(0);
    }
    else{
        int top=st->top;
        temp=st->items[top];
        st->top-=1;
        return temp;
    }
}

void printNGE(int arr[],int n)
{
    int i=0;
    struct Stack s;
    s.top=-1;
    int element,next;

    push(&s,arr[0]);

    for(i=0;i<n;i++)
    {
        next=arr[i];

        if(isEmpty(&s)==false)
        {
            element=pop(&s);
            while(element<next)
            {
                printf("\n %d --> %d",element,next);
                if(isEmpty(&s)==true)
                   break;
                element=pop(&s);
            }

            if(element>next)
               push(&s,element);
        }
        push(&s,next);
    }
    while(isEmpty(&s)==false)
    {
        element=pop(&s);
        next=-1;
        printf("\n %d --> %d",element,next);
    }
}

int main()
{
    int arr[]={11,13,21,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    printNGE(arr,size);
    getchar();
    return 0;
}