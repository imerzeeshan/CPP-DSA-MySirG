#include<bits/stdc++.h>
using namespace std;

void printNaturalno(int n)
{
    if(n > 0)
    {
        printNaturalno(n-1);
        cout<<n<<" ";
    }
}
void printNreverse(int n)
{
    if(n > 0)
    {
        cout<<n<<" ";
        printNreverse(n-1);
    }
}
void printNO(int n)
{
    if(n>0)
    {
        printNO(n-1);
        cout<<2*n-1<<" ";
    }
}
void printNOR(int n)
{
    if(n>0)
    {
        cout<<2*n-1<<" ";
        printNOR(n-1);
    }
}
void  printNEven(int n)
{
    if(n>0)
    {
        printNEven(n-1);
        cout<<2*n<<" ";
    }
}
void  printNEvenReverse(int n)
{
    if(n>0)
    {
        cout<<2*n<<" ";
        printNEven(n-1);
    }
}
void printNSqure(int n)
{
    if(n>0)
    {
        printNSqure(n-1);
        cout<<n*n<<" ";
    }
}
void printNSqureReverse(int n)
{
    if(n>0)
    {
        cout<<n*n<<" ";
        printNSqureReverse(n-1);
    }
}
void printNCube(int n)
{
    if(n>0)
    {
        printNCube(n-1);
        cout<<n*n*n<<" ";
    }
}
void printNCubeReverse(int n)
{
    if(n>0)
    {
        cout<<n*n*n<<" ";
        printNCubeReverse(n-1);
    }
}
int main()
{
    int n=5;
    printNaturalno(n);
    cout<<endl;
    
    printNreverse(n);
    cout<<endl;
    
    printNO(n);
    cout<<endl;
    
    printNOR(n);
    cout<<endl;
    
    printNEven(n);
    cout<<endl;
    
    printNEvenReverse(n);
    cout<<endl;
    
    printNSqure(n);
    cout<<endl;
    
    printNSqureReverse(n);
    cout<<endl;
    
    printNCube(n);
    cout<<endl;
    
    printNCubeReverse(n);
    return 0;
}