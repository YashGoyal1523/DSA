// given an integer ....print its digits.. eg 4215...print 4 2 1 5
#include<iostream>
using namespace std ;

void print(int n){

    if(n==0) return; // base case

    int digit=n%10;  //last digit
     n=n/10;  // no. update
    print(n);
    cout<<digit<<" ";                   // aate hue print kro
    return;

}

int main()
{
    int n;
    cout<<"enter no";
    cin>>n;
    print(n);
return 0;
}