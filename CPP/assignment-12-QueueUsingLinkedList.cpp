#include<bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Queue
{
    private:
        node *front,*rear;
    public:
        Queue();
        bool isEmpty();
        void insert(int);
        node* getRear();
        node* getFront();
        void deleteFront();
        int count();
        ~Queue();
        void sort();
};
void Queue::sort()
{
    node *t = front;
    while (t)
    {
        t=t->next;
        Queue Q,Q1;
        if(Q.isEmpty())
        {
            Q.insert(t->item);
        }
        else if(t->item >= Q.front->item)
        {
            Q.insert(t->item);
        }
        else{
            while (t->item  )
            {
                /* code */
            }
            
        }
    }
    
}
int Queue::count()
{
    node *t=front;
    int c=0;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;    
}
Queue::~Queue()
{
    while (!isEmpty())
    {
        deleteFront();
    }
}
void Queue::deleteFront()
{
    if(!isEmpty())
    {
        node *t=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete t;
    }
}
node* Queue::getFront()
{
    return front;
}
node* Queue::getRear()
{
    return rear;
}
void Queue::insert(int data)
{
    node *n = new node;
    n->item=data;
    n->next=NULL;
    if(isEmpty())
    {
        rear=n;
        front=n;
    }
    else
    {
       rear->next=n;
       rear=n;
    }
}
bool Queue::isEmpty()
{
    return rear==NULL;
}
Queue::Queue()
{
    front=rear=NULL;
}
int main()
{
    Queue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.deleteFront();
    cout<<endl<<q.count();
    return 0;
}