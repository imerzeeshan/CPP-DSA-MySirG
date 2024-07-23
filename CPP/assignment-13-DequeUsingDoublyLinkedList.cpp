#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
    private:
        node *front=NULL,*rear=NULL;
    public:
        Deque();
        Deque(Deque &);
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        node* getFront();
        node* getRear();
        ~Deque();
        bool isEmptyDeque();
        Deque& operator=(Deque &);
        void getData(node*);
};
void Deque::getData(node *A)
{
    cout<<endl<<A->item;
}
Deque& Deque::operator=(Deque &D)
{
    
    while(!D.isEmptyDeque())
    {
        insertFront(D.front->item);
        D.deleteFront();
    }
}
Deque::Deque(Deque &D)
{
    while(!D.isEmptyDeque())
    {
        insertFront(D.front->item);
        D.deleteFront();
    }
}
bool Deque::isEmptyDeque()
{
    if(front)
        return false;
    else
        return true;
}
Deque::~Deque()
{
    while (front)
    {
        deleteFront();
    }    
}
node* Deque::getRear()
{
    return rear;
}
node* Deque::getFront()
{
    return front;
}
void Deque::deleteRear()
{
    if(rear)
    {
        node *t = rear;
        if(rear == front)
            front = rear = NULL;
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        delete t;
    }
}
void Deque::deleteFront()
{
    if(front)
    {
        node *t = front;
        if(front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }
        delete t;
    }
}
void Deque::insertRear(int data)
{
    node *n = new node;
    n->next = NULL;
    n->item = data;
    n->prev = rear;
    if(rear)
        rear->next = n;
    else 
        front = n;
    rear = n;
}
void Deque::insertFront(int data)
{
    node *n = new node;
    n->prev = NULL;
    n->item = data;
    n->next = front;
    if(front)
        front->prev = n;
    else
        rear = n;
    front = n;
}
Deque::Deque()
{
    front=rear=NULL;
}

// -----------D.R.I.V.E.R---C.O.D.E------------------

int main()
{
    Deque D,F;
    D.insertFront(10);
    D.insertFront(20);
    D.insertFront(30);
    D.insertFront(40);
    D.insertFront(50);

    // D.getData(D.getFront());
    // D.getData(D.getRear());

    F=D;

    // F.deleteFront();
    // F.deleteFront();
    // F.deleteFront();
    // F.deleteFront();
    // F.deleteFront();
    //F.getData(F.getFront());

    F.deleteRear();
    F.deleteRear();
    F.deleteRear();
    F.deleteRear();
    F.deleteRear();
    F.getData(F.getRear());


    return 0;
}