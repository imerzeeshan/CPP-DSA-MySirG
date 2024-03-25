#include<bits/stdc++.h>
using namespace std;
class DynArray
{ 
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(int);
        void doubleArray();
        void halfArray();
        int size();
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int count();
        int find(int);
        void showArray();
        ~DynArray();

};
DynArray::~DynArray()
{
    delete []ptr;
}
void DynArray::showArray()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        cout<<ptr[i]<<" ";
    }
}
int DynArray::find(int data)
{
    for (int i = 0; i <=lastIndex; i++)
    {
        if(ptr[i]==data)
        {
            return i;
        }
    }
    return -1;
}
int DynArray::count()
{
    return lastIndex+1;
}
int DynArray::get(int index)
{
    if(index>=0 && index<=lastIndex)
    {
        return ptr[index];
    }
    else{
        cout<<"\nInvalid Index:\n";
        return -1;
    }
}
bool DynArray::isFull()
{
    return lastIndex == capacity-1;
}
void DynArray::del(int index)
{
    if(isEmpty())
    {
        cout<<"Array is Empty :)";
    }
    else if(index<0 || index>lastIndex)
    {
        cout<<"Invalid Index Entered by User :)";
    }
    else{
        for(int i=index; i<lastIndex; i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
        if(capacity/2 >= lastIndex+1 && capacity>1)
        {
            halfArray();
        }
    }
}
void DynArray::edit(int index,int data)
{
    if(index>=0 && index<=lastIndex)
    {
        ptr[index]=data;
    }
    else{
        cout<<"Invalid Index Entered by User :)";
    }
}
void DynArray::insert(int index,int data)
{
    if(index<0 || index > lastIndex+1)
    {
        cout<<"Invalid Index: ";
    }
    else{
        if(isFull())
        {
            doubleArray();
        }
        for(int i=lastIndex; i>=index; i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
}
void DynArray::append(int data)
{
    if(isFull())
    {
        doubleArray();
    }
    lastIndex++;
    ptr[lastIndex]=data;
}
bool DynArray::isEmpty()
{
    return lastIndex == -1;
    /*if(lastIndex<0)
    {
        cout<<"Array is Empty:";
        return 1;
    }
    else{
        cout<<"Array is not Empty:";
        return 0;
    }*/
 }
int DynArray::size()
{
    return capacity;
}
void DynArray::halfArray()
{
    int *temp = new int[capacity/2];
    for(int i=0; i<=lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete []ptr;
    ptr = temp;
    capacity/=2;
}
void DynArray::doubleArray()
{
    int *temp = new int[capacity*2];

    for(int i=0; i<=lastIndex; i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr = new int[capacity];
}
/*int main()
{
    DynArray obj(5);

    obj.insert(0,10);
    obj.insert(1,15);
    obj.insert(2,20);
    obj.insert(3,30);
    obj.insert(4,25);
    obj.insert(5,35);

    cout<<obj.size()<<endl;
    for(int i=0; i<obj.count(); i++)
    {
        cout<<obj.get(i)<<" ";
    }

    obj.showArray();
    return 0;
}*/