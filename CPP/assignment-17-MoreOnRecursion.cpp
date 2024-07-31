#include<bits/stdc++.h>
using namespace std;
int sumN(int n)
{
    if(n==1)
        return 1;
    return n + sumN(n-1);
}
int sumOddN(int n)
{
    if(n == 1)
        return 1;
    return 2*n-1 + sumOddN(n-1);
}
int sumEvenN(int n)
{
    if(n==1)
        return 2;
    return 2*n + sumEvenN(n-1);
}
int sumSquare(int n)
{
    if(n==1)
        return 1;
    return n*n + sumSquare(n-1);
}
int sumFactorial(int n)
{
    if(n==0) return 1;
    return n * sumFactorial(n-1);
}
int sumDigit(int n)
{
    if(n==0)
        return 0;
    return n%10 + sumDigit(n/10);
}
void dtob(int x)
{
    if(x>0)
    {
        dtob(x/2);
        cout<<x%2;
    }
}
int fib(int n)
{
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}
int hcf(int a, int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a>=b) return hcf(a%b,b);
    return hcf(a,b%a);
}
double power(double x, double y)
{
    if(y==0) return 1;
    if(y>0) return power(x,y-1)*x;
    else return power(x,y+1)*1/x;
}
int main()
{
    int n= 5;

    int ans = sumN(n);
    cout<<ans; 
    cout<<endl;   
    ans = sumOddN(n);
    cout<<ans;    
    cout<<endl<<sumEvenN(n);
    cout<<endl<<sumSquare(n);
    cout<<endl<<sumFactorial(n);
    cout<<endl<<sumDigit(1234);
    cout<<endl;
    dtob(15);
    cout<<endl<<fib(n);
    cout<<endl<<hcf(180,75);
    cout<<endl<<power(2,-3);
    return 0;
}