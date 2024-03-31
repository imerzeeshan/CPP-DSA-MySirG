#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
        node *start;
    public:
        CDLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfterNode(node*,int);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteAfterNode(node*);
        ~CDLL();
        void showList();
};
CDLL::~CDLL()
{
    while (start)
    {
        deleteFirstNode();
    }
}
void CDLL::deleteAfterNode(node* ptr)
{
    if(ptr)
    {
        if(start==start->next)
        {
            start=NULL;
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            if(start==ptr)
            {
                start=ptr->next;
            }
        }
        delete ptr;
    }
}
void CDLL::deleteLastNode()
{
    if(start)
    {
        node *t=start;
        if(start->prev==start)
        {
            start=NULL;
        }
        else{
            t=start->prev;
            t->prev->next=start;
            start->prev=t->prev;
        }
        delete t;
    }
}
void CDLL::deleteFirstNode()
{
    if(start)
    {
        node *t=start;
        if(start->next==start)
        {
            start=NULL;
        }
        else{
            t->next->prev=t->prev;
            t->prev->next=t->next;
            start=t->next;
        }
        delete t;
    }
}
void CDLL::insertAfterNode(node* ptr, int data)
{
    if(ptr)
    {
        node *n = new node;
        n->item=data;
        n->prev=ptr;
        n->next=ptr->next;
        ptr->next->prev=n;
        ptr->next=n;
    }
}
node* CDLL::search(int data)
{
    node *t = start;
    if(t)
    {
        do
        {
            if(t->item==data)
            {
                return t;
            }
            t=t->next;
        } while(t!=start);
    }
    return NULL;
}
void CDLL::insertAtLast(int data)
{
    node *n =new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else{
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
void CDLL::showList()
{
    if(start)
    {
        node *t=start;
        do
        {
            cout<<t->item<<" ";       
            t=t->next; 
        } while (t!=start);
    }
}
void CDLL::insertAtStart(int data)
{
    node *n = new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else{
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
CDLL::CDLL()
{
    start=NULL;
}
int main()
{
    CDLL obj;
    obj.insertAtLast(100);
     obj.insertAtStart(5);
    obj.insertAtStart(10);
    obj.insertAtStart(15);
    obj.insertAtLast(100);
    obj.insertAtStart(20);
    obj.insertAtStart(25);
    obj.insertAtLast(110);
    obj.insertAtLast(70);
    obj.insertAtStart(45);
    obj.insertAfterNode(obj.search(110),30);
    obj.deleteFirstNode();
    obj.insertAtStart(20);
    obj.deleteLastNode();
    obj.deleteAfterNode(obj.search(20));
    obj.showList();
    cout<<endl;
    cout<<obj.search(100);
    return 0;
}