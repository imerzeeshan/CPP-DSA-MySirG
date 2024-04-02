#include "assignment-1.cpp"
class Stack : private Array
{
    public:
        Stack(int);
        Stack(Stack &);
        void push(int);
        int peek();
        void pop();
        ~Stack();
        virtual bool isFull();
        virtual bool isEmpty();
        int getStackSize();
        void operator=(Stack &);
};
void Stack::operator=(Stack &s)
{
    Array::operator=(s);
}
int Stack::getStackSize()
{
    return getCapacity();
}
Stack::Stack(Stack &S):Array(S)
{
}
bool Stack::isEmpty()
{
    return Array::isEmpty();
}
bool Stack::isFull()
{
    return Array::isFull();
}
Stack::~Stack()
{
}
void Stack::pop()
{
    if(isEmpty())
    {
        cout<<"\nStack Underflow\n";
    }
    else{
        del(count()-1);
    }
}
int Stack::peek()
{
    if(!isEmpty())
    {
        return get(count()-1);
    }
    else
        cout<<"\nStack is Empty: \n";
    return 0;
}
void Stack::push(int data)
{
    if(isFull())
    {
        cout<<"Stack Overflow: ";
    }
    else
    {
        append(data);
    }
}
Stack::Stack(int cap):Array(cap)
{
}
void reverseStack(Stack &s1)
{
    Stack s2(s1.getStackSize());

    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
void pushInStack(Stack &s,Stack &minStack, int data)
{
    s.push(data);
    if(minStack.isEmpty())
    {
        minStack.push(data);
    }
    else{
        if(data>minStack.peek())
        {
            minStack.push(minStack.peek());
        }else{
            minStack.push(data);
        }
    }
}
void popFromStack(Stack &s,Stack &minStack)
{
    s.pop();
    minStack.pop();
}/*
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // Stack minStack(5);

    // pushInStack(s,minStack,50);
    // cout<<endl<<"Current Minimum Vlue is: "<<minStack.peek();

    // pushInStack(s,minStack,40);
    // cout<<endl<<"Current Minimum Vlue is: "<<minStack.peek();

    // pushInStack(s,minStack,60);
    // cout<<endl<<"Current Minimum Vlue is: "<<minStack.peek();

    // pushInStack(s,minStack,70);
    // cout<<endl<<"Current Minimum Vlue is: "<<minStack.peek();

    // pushInStack(s,minStack,30);
    // cout<<endl<<"Current Minimum Vlue is: "<<minStack.peek();


    // cout<<endl<<endl<<"Poping Start";

    // popFromStack(s,minStack);
    // cout<<endl<<"Current Minimum Value is: "<<minStack.peek();

    // popFromStack(s,minStack);
    // cout<<endl<<"Current Minimum Value is: "<<minStack.peek();

    // popFromStack(s,minStack);
    // cout<<endl<<"Current Minimum Value is: "<<minStack.peek();

    // popFromStack(s,minStack);
    // cout<<endl<<"Current Minimum Value is: "<<minStack.peek();

    // popFromStack(s,minStack);
    // cout<<endl<<"Current Minimum Value is: "<<minStack.peek();
    cout<<endl<<s.peek();

    reverseStack(s);
    cout<<endl<<s.peek();

    cout<<endl;
    return 0;
}*/