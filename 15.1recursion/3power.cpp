#include<iostream>      //a^b
using namespace std ;

int power(int a,int b){
    if(b==0)return 1;
    int ans=a*power(a,b-1);
    return ans;
}

int main()
{
    int a,b;
    cout<<"enter a,b";
    cin>>a>>b;
   int ans= power(a,b);
   cout<<ans;
return 0;
}