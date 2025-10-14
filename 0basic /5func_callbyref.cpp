// method 1 is to pass variable address and store in pointer dabba

// method 2 is to pass variable name and store in reference variable

// see method 2

#include<iostream>
using namespace std ;

int increment(int& m){
    m++;
    return m;             // m is nickname for variable n in this block of code...can be used in this block for working with variable n
}                       // note agar hum &n hi banate toh idhar bhi n hi use kar skte the....



int main()
{
    int n;
    cout<<"enter n";
    cin>>n;
    int ans=increment(n);
    cout<<n;
return 0;
}





// int n=10;
// int y=n;  iska mtlb hai int dabbe y yaani int variable y  mein mein n store hora yaani n dabbe ki value store hori
// int& z=n;   iska mtlb hai reference variable z mein n store hora...yaani n dabbe ka nickname z bngya  (note koi new dabba of z nhi hota isme)