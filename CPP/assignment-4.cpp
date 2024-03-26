#include<bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteAfter(node*);
        void showList();
        node* getFirstNode();
        int countList();
        ~SLL();
};
int SLL::countList()
{
    int count=0;
    while (start!=NULL);
    {
        count++;
        start=start->next;
    } 
    return count;    
}
SLL::~SLL()
{
    while (start)
    {
        deleteFirst();
    }    
}
node* SLL::getFirstNode()
{
    return start;
}
void SLL::showList()
{
   while(start != NULL)
   {
        cout<<start->item<<" ";
        start=start->next;
   } 
}
void SLL::deleteAfter(node *temp)
{
    if(start==NULL)
    {
        cout<<"\nList is Empty\n";
    }
    else
    {
        if(temp)
        {
            if(start==temp)
            {
                start = temp->next;
                delete temp;
            }
            else{
                node *t=start;
                while(t->next != temp)
                {
                    t=t->next;
                }
                t->next=temp->next;
                delete temp;
            }
        }
    }
}
void SLL::deleteLast()
{
    if(start==NULL)
    {
        cout<<"\nUnderflow List is Empty\n";
    }
    else if(start->next == NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        node *t = start;
        while (t->next->next != NULL)
        {
            t=t->next;
        }
        delete t->next;
        t->next=NULL;
    }
    
}
void SLL::deleteFirst()
{
    if (start)
    {
        node *t = start;
        start = start->next;
        delete t;
    }
    
}
void SLL::insertAfter(node *ptr,int data)
{
    node *n = new node;
    n->item=data;
    n->next=ptr->next;
    ptr->next=n;
}
node* SLL::search(int data)
{
    node *t=start;
    while(t->next!=NULL)
    {
        if(t->item==data)
        {
            return t;
        }
        t=t->next;
    }
    return NULL;
}
void SLL::insertAtLast(int data)
{
    node *n = new node;
    n->item=data;
    n->next=nullptr;
    node *t;
    if(start == NULL)
    {
        start=n;
    }
    else{
        t=start;
        while(t->next != NULL)
        {
            t=t->next;
        }
        t->next=n;
    }
}
void SLL::insertAtStart(int data)
{
    node *n = new node;
    n->item=data;
    n->next=start;
    start=n;
}
SLL::SLL()
{
    start=NULL;
}
int main()
{
    SLL obj;
    obj.insertAtStart(20);
    obj.insertAtStart(30);
    obj.insertAtStart(25);
    obj.insertAtStart(35);
    obj.insertAtLast(50);
    obj.insertAfter(obj.search(25),90);
    // obj.deleteFirst();
    // obj.deleteLast();
    // obj.deleteAfter(obj.search(30));
    // obj.getFirstNode();
    obj.showList();
    cout<<obj.countList();
}