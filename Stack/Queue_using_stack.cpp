#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1,s2;

    void enQueue(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        if(s1.empty())
        {
            cout<<"Queue is empty";
            exit(0);
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;

    q.enQueue(40);

    cout<<q.deQueue()<<endl;
}