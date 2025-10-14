#include<iostream>                     
using namespace std ;

int factorial(int n){
    //base case
    if(n==0)
    return 1;
    
    //recursive call 
    int ans=n*factorial(n-1);
    return ans;
}


int main()
{
    int n;
    cout<<"enter number";
    cin>>n;

    int ans=factorial(n);
    cout<<"ans is "<<ans;
return 0;
}





 // tip: ek case hume solve karna baaki recursion will do 
  // base case...processing.....recursive call