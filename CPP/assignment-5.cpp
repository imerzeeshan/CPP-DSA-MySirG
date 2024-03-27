#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private:
        node *start;
    public:
        DLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node*);
        void showList();
        ~DLL();
};
DLL::~DLL()
{
    while (start)
    {
        deleteFirstNode();
    }    
}
void DLL::showList()
{
    cout<<"\n";
    while (start != NULL)
    {
        cout<<start->item<<" ";
        start=start->next;
    }
}
void DLL::deleteNode(node *ptr)
{
    if(ptr)
    {
        if(ptr->prev)
        {
            ptr->prev->next=ptr->next;
        }
        else{
            start=ptr->next;
        }
        if(ptr->next)
        {
            ptr->next->prev=ptr->prev;
        }
        delete ptr;
        /*if(ptr->next==NULL && ptr->prev!=NULL)
        {
            ptr->prev->next=NULL;
            delete ptr;
        }
        else if(ptr->prev==NULL && ptr->next!=NULL)
        {
            start=start->next;
            delete ptr;
        }
        else if(ptr->prev!=NULL && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            delete ptr;
        }
        else{
            delete ptr;
            start=NULL;
        }*/
    }
}
void DLL::deleteLastNode()
{
    if(start)
    {
        node *t;
        t=start;
        while (t->next!=NULL)
        {
            t=t->next;
        }
        if(t->prev)
        {
            t->prev->next=NULL;
        }
        else{
            start=NULL;
        }
        delete t;        
    }

   /* if(start)
    {
        node *t = start;
        if(t->next)
        {
            while (t->next->next != NULL)
            {
                t=t->next;
            }
            delete t->next;
            t->next=NULL;
        }
        if(t->prev==NULL)
        {
            delete t;
            start=NULL;
        }        
    }*/
}
void DLL::deleteFirstNode()
{
    if(start)
    {
        node *r = start;
        start=start->next;
        if(r->next)
            start->prev=NULL;
        delete r;        
    }
}
void DLL::insertAfter(node *ptr,int data)
{
    if(ptr)
    {
        node *n = new node;
        n->prev=ptr;
        n->item=data;
        n->next=ptr->next;
        if(ptr->next)
            ptr->next->prev=n;
        ptr->next=n;
    }
}
node* DLL::search(int data)
{
    node *t = start;
    while (t!=NULL)
    {
        if(t->item==data)
        {
            return t;
        }
        t=t->next;
    }
    return t;    
}
void DLL::insertAtLast(int data)
{
    node *n = new node;
    n->item=data;
    n->next=NULL;
    node *t = start;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else{
        while (t->next!=NULL)
        {
            t=t->next;
        }
        n->prev=t;
        t->next=n;
    }
}
void DLL::insertAtStart(int data)
{
    node *n = new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start!=NULL)
    {
        start->prev=n;
    }
    start=n;
}
DLL::DLL()
{
    start=NULL;
}
int main()
{
    DLL obj;
    obj.insertAtStart(50);
    obj.insertAtLast(20);
    obj.insertAtLast(25);
    obj.insertAtLast(30);
    //cout<<obj.search(20);
    obj.insertAfter(obj.search(25),90);

    obj.deleteFirstNode();
    obj.deleteLastNode();
    obj.deleteNode(obj.search(25));
    obj.showList();
    return 0;
}