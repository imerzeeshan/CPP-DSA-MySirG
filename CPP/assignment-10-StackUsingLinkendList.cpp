#include<bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack&);
        void push(int);
        bool isEmpty();
        int peek();
        void pop();
        ~Stack();
        void reverse();
        void operator=(Stack&);
        string infixToPostFix(string);
        int postfixEvalution(string);
};
void Stack::operator=(Stack &s2)
{
}
Stack::Stack(Stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while (t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
        {
            top=n;
        }else{
            p->next=n;
        }
        t=t->next;
        p=n;
    }
    if(p!=NULL)
    {
        p->next=NULL;
    }
    
}
void Stack::reverse()
{
    if(top && top->next)
    {
        node *t2=NULL;
        node *t1;
        do
        {
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        } while (top->next!=NULL);
        top->next=t1;
    }
}
Stack::~Stack()
{
    while (top)
    {
        pop();
    }    
}
void Stack::pop()
{
    node *t;
    if(isEmpty())
    {
        cout<<"\nStack is Empty: ";
    }
    else
    {
        t=top;
        top=top->next;
        delete t;
    }
}
int Stack::peek()
{
    if(top==NULL)
    {
        cout<<"\nStack is Empty: ";
        return -1;
    }
    else{
        return top->item;
    }
}
void Stack::push(int data)
{
    node *n = new node;
    n->item=data;   
    n->next=top;
    top=n;
}
bool Stack::isEmpty()
{
    return top==NULL;
}
Stack::Stack()
{
    top=NULL;
}
void reverse(Stack &s1)
{
    Stack s2;
    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
int len(int x)
{
    int count = 0;
    while (x)
    {
        x/=10;
        count++;
    }
    return count;    
}
bool ispalindrome(int x)
{
    Stack s;
    int l=len(x);
    int i=l/2;
    while (i)
    {
        s.push(x%10);
        x/=10;
        i--;
    }
    if(l%2)
        x/=10;
    while (x)
    {
        if(x%10==s.peek())
        {
            s.pop();
            x/=10;
        }
        else
        {
            return false;
        }
    }
    return true;    
}
int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }else
    {
        return -1;
    }
}
string Stack::infixToPostFix(string s)
{
    Stack st;
    string res;
    for(int i=0; i<s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while (!st.isEmpty() && st.peek()!='(')
            {
                res+=st.peek();
                st.pop();
            }
            if(!st.isEmpty())
            {
                st.pop();
            }            
        }
        else{
            while (!st.isEmpty() && prec(st.peek())>prec(s[i]))
            {
                res+=st.peek();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isEmpty())
    {
        res+=st.peek();
        st.pop();
    }
    return res;    
}
int Stack::postfixEvalution(string s)
{
    Stack st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else{
            int op2=st.peek();
            st.pop();
            int op1=st.peek();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(op1^op2);
                break;
            }
        }
    }
    return st.peek();
}
int main()
{
    Stack s;
    s.push(10);
    //cout<<endl<<s.peek();

    s.push(20);
    //cout<<endl<<s.peek();

    s.push(30);
    //cout<<endl<<s.peek();

    s.push(40);
    //cout<<endl<<s.peek();

    //s.pop();

    cout<<endl<<s.peek();
    s.reverse();
    cout<<endl<<s.peek();
    cout<<endl<<ispalindrome(25652);
    cout<<endl<<endl;
    cout<<s.infixToPostFix("(a-b/c)*(a/k-l)");
    cout<<endl<<endl;
    cout<<s.postfixEvalution("46+2/5*7+");
    return 0;
}
//(a-b/c)*(a/k-l)