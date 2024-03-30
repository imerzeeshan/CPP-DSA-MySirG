#include<bits/stdc++.h>
#include "assignment-4.cpp"
using namespace std;

void countList(SLL &obj)
{
    node *t=obj.getFirstNode();
    int count=0;
    if(t)
    {
        while (t!=NULL);
        {
            count++;
            t=t->next;
        } 
    }
    cout<<"\nNumber of Nodes is:: "<<count;    
}
int is_cycle(SLL &obj)
{
    node *t1,*t2;
    t1=obj.getFirstNode();
    t2=t1;
  
    do
    {
        if(t1==NULL)
        {
            return 0;
        }
        if(t1->next!=NULL)
        {
            t1=t1->next->next;
        }
        else{
            return 0;
        }
        t2=t2->next;
    } while (t1!=t2);
    return 1;
}
int length_of_cycle(SLL &obj)
{
    int count=1;
    node *t1,*t2;
    if(is_cycle(obj))
    {
        t2=t1=obj.getFirstNode();
        do
        {
            t1=t1->next->next;
            t2=t2->next;
        } while (t1!=t2);
        while (t1->next!=t2)
        {
            count++;
            t1=t1->next;
        }   
        return count++;
    }
    return 0;
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
    obj.deleteFirst();
    obj.deleteLast();
    obj.deleteAfter(obj.search(30));
    obj.showList();
    countList(obj);
    
    return 0;
}