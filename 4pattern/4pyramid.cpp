#include<iostream>
using namespace std ;
int main()
{ 
    
      int n;  // row
cout<<"enter no of rows";
cin>>n;
for (int row = 0; row < n; row++)         //<=n-1
{
    for (int col = 0; col<row+1; col++)          //<=row
    {
        cout<<"* ";
    }
    cout<<endl;
}



return 0;
}