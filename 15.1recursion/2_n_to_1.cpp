#include<iostream>
using namespace std ;

void print(int n){
    if(n==0) return;// base case

    cout<<n<<" ";  // processing              // jaate hue print kro
    print(n-1);    // recursive call
  
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