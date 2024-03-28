#include<bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        void insertAtFirst(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteAfterNode(node*);
        ~CLL();
        void showCLL();
};
CLL::~CLL()
{
    while(last)
    {
        deleteFirst();
    }
}
void CLL::deleteAfterNode(node* ptr)
{
    if(ptr)
    {
        node *t=last;
        while (t->next!=ptr)
        {
            t=t->next;
        }
        if(t==ptr)
        {
            delete ptr;
            last= NULL;
        }
        else{
            t->next=ptr->next;
            if(ptr==last)
            {
                last=t;
            }
            delete ptr;
        }
    }
    
}
void CLL::deleteLast()
{
    if(last)
    {
        node *t = last;
        while(t->next!=last)
        {
            t=t->next;
        }
        if(t==last)
        {
            delete last;
            last = NULL;
        }
        else{
            t->next=last->next;
            delete last;
            last = t;
        }
    }
}
void CLL::deleteFirst()
{
    if(last)
    {
        node *t=last->next;
        if(last->next==last)
        {
            last=NULL;
        }
        else{
            last->next=t->next;
        }
        delete t;
    }
}
void CLL::insertAfter(node *ptr,int data)
{
    if(last)
    {
        node *n = new node;
        n->item=data;
        n->next=ptr->next;
        ptr->next=n;
        if(ptr==last)
        {
            last=n;
        }
    }
}
node* CLL::search(int data)
{
    node *t = last;
    if(last)
    {
        do
        {
            if(t->item==data)
            {
                return t;
            }
            t=t->next;
        } while (t!=last);
    }
    return NULL;
}
void CLL::insertAtLast(int data)
{
    node *n = new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else{
        n->next=n;
        last=n;
    }
}
void CLL::insertAtFirst(int data)
{
    node *n = new node;
    n->item=data;
    if(last)
    {//when list is not empty
        n->next=last->next;
        last->next=n;
    }
    else
    {// when list is Empty
        n->next=n;
        last=n;
    }
}
void CLL::showCLL()
{
   node *t=last;

   if(last!=NULL)
    {
        do{
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=last);
    }
}
CLL::CLL()
{
    last=NULL;
}
int main()
{
    CLL obj;
    obj.insertAtFirst(20);
    obj.insertAtFirst(30);
    obj.insertAtFirst(25);
    obj.insertAtLast(90);
    obj.insertAfter(obj.search(30),900);
    obj.insertAtLast(100);
    obj.deleteFirst();
    obj.deleteLast();
    obj.deleteAfterNode(obj.search(30));
    obj.showCLL();
    cout<<endl;
    
    return 0;
}