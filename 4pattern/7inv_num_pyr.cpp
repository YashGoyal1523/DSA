#include<iostream>
using namespace std ;
int main()
{
int n; // rows
cout<<"enter rows";
cin>>n;
    
for (int i = 0; i < n; i++)        //row
{
    for (int j = 0; j<n-i; j++)        // column   
    {
        cout<<j+1<<" ";
    }
    cout<<endl;
}



return 0;
}