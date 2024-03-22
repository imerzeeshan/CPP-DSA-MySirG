#include<bits/stdc++.h>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        Array(Array &);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int count();
        int find(int);
        void showData();
        ~Array();       
        int getCapacity();
        void operator=(Array &);
};
void Array::operator=(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr = new int[capacity];
    for(int i=0; i<=lastIndex; i++)
    {
        ptr[i]=arr.ptr[i];
    }
}
int Array::getCapacity()
{
    return capacity;
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr = new int[capacity];
    for(int i=0; i<=lastIndex; i++)
    {
        ptr[i]=arr.ptr[i];
    }
}
void Array::showData()
{
    for(int i=0; i<=lastIndex; i++)
    {
        cout<<ptr[i]<<" ";
    }
}
int Array::find(int data)
{
    for(int i=0; i<=lastIndex; i++)
    {
        if(ptr[i]==data)
        return i;
    }
    return -1;
}
Array::~Array()
{
    delete []ptr;
}
int Array::count()
{
    return lastIndex+1;
}
int Array::get(int index)
{
    if(index>=0 && index<=lastIndex)
    {
        return ptr[index];
    }
    else{
        cout<<"Invalid Index or Empty Index :)";
        return -1;
    }
}
bool Array::isFull()
{
    return lastIndex==capacity-1;
}
void Array::del(int index)
{
    if(isEmpty())
    {
        cout<<"Array is Empty:)";
    }
    else if(index<0 || index>lastIndex)
    {
        cout<<"Invalid Index:)";
    }
    else
    {
        for(int i=index; i<lastIndex; i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
    }
}
void Array::edit(int index,int data)
{
    if(index>=0 && index <= lastIndex)
    {
        ptr[index]=data;
    }
}
void Array::insert(int index,int data)
{
    if(lastIndex == capacity-1)
    {
        cout<<"Array is already full:)\n";
    }
    else if(index<0 || index>lastIndex+1)
    {
        cout<<"Invalid Index:";
    }
    else{
        for(int i=lastIndex; i>=index; i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::append(int data)
{
    if(lastIndex==capacity-1)
    {
        cout<<"Array is already full:)";
    }else{
        lastIndex++;
        ptr[lastIndex]=data; 
    }

}
bool Array::isEmpty()
{
    return lastIndex == -1;
}
Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[cap];
}