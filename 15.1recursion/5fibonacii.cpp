//  print nth term of fibonacii series
#include<iostream>
using namespace std ;

int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    int ans=fibo(n-1)+fibo(n-2);
    return ans;
}



int main()
{
   int n;
    cout<<"enter term number";
    cin>>n;
    int ans=fibo(n);
    cout<<ans;
return 0;
}