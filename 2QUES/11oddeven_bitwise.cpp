// normal methd :  if %2==0 then even if %2==1 then odd

#include<iostream>       //bitwise method  // if Lsb is 0 ie rightmost bit is 0 then no is even and if 1 then odd
using namespace std ;

int check(int n){
    int x=n&1;
    if (x==0)
    {
        return 0;       // lets take return 0 for even and return 1 fpr odd
    }
    else return 1;

}



int main()
{
    int n;
    cout<<"enter no";
    cin>>n;
    int ans=check(n);
    if (ans==0)
    {
       cout<<"even";
    }
    else cout<<"odd";
return 0;
}