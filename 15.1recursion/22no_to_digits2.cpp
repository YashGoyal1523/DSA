// given an integer ....store its digits in a vector.. eg 4215...store 4 2 1 5

#include<iostream>
#include<vector>
using namespace std ;

void print(int n,vector<int>&v){

    if(n==0) return;

    int digit=n%10;
    // n=n/10;
    print(n/10,v);
     v.push_back(digit);    // aate hue store                
    return;

}

int main()
{
    int n;
    cout<<"enter no";
    cin>>n;
    vector<int>v;
    print(n,v);

    // printing vector
   for(int ans:v){
    cout<<ans<<" ";
   }
return 0;
}