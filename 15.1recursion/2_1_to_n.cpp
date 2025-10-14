#include<iostream>
using namespace std ;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<" ";                           // aate hue print kro
    return;
}


int main()
{
    int n;
    cout<<"enter number";
    cin>>n;
    print(n);
return 0;
}