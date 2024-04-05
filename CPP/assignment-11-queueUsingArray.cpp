#include<bits/stdc++.h>
using namespace std;
class Queue
{
    private:
        int capacity;
        int front,rear;
        int *ptr;
    public:
        Queue(int);
        Queue(Queue&);
        bool isEmpty();
        bool isFull();
        void insert(int);
        int getRear();
        int getFront();
        void deleteFront();
        int count();
        Queue& operator=(Queue&);
        ~Queue();
};
Queue& Queue::operator=(Queue &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    if(ptr!=NULL)
    {
        delete []ptr;
    }
    ptr = new int[capacity];
    int n = Q.count();
    int i=Q.front;
    while (n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
        {
            i=0;
        }else{
            i++;
        }
        n--;
    }    
    return Q;
}
int Queue::count()
{
    if(isEmpty())
    {
        return 0;
    }
    else if(front<=rear)
    {
        return rear-front+1;
    }
    else{
        return capacity-front+rear+1;
    }
}
Queue::Queue(Queue &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr = new int[capacity];
    int n = Q.count();
    int i=Q.front;
    while (n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
        {
            i=0;
        }else{
            i++;
        }
        n--;
    }    
}
Queue::~Queue()
{
    delete []ptr;
}
void Queue::deleteFront()
{
    if(isEmpty())
    {
        cout<<"\nQueue is Empty: \n";
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if (front==capacity-1)
    {
        front=0;
    }
    else{
        front++;
    }
    
}
int Queue::getFront()
{
    if(!isEmpty())
    {
        return ptr[front];
    }
    cout<<"\nQueue is Empty";
    return -1;
}
int Queue::getRear()
{
    if(!isEmpty())
    {
        return ptr[rear];
    }
    cout<<"\nQueue is Empty:";
    return -1;
}
void Queue::insert(int data)
{
    if(isFull())
    {
        cout<<"\nQueue is OverFlow: \n";
    }
    else if(isEmpty())
    {
        front=rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear]=data;
    }
}
bool Queue::isFull()
{
    return ((rear==capacity-1 && front==0) || (rear+1==front));
}
bool Queue::isEmpty()
{
    return  (front==-1 && rear==-1); // or return rear==-1;
}
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}
/*int main()
{
    Queue q(5);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.deleteFront();
    cout<<endl<<q.getFront();
    cout<<endl<<q.getRear();
    return 0;
}*/