#include<iostream>           // printing diagonal elements of a square 2d array from top left to bottom right
using namespace std ;
int main()
{
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int row=3;                                    
    int col=3;  // square: row=col

    // printing
    for (int i = 0; i < row; i++)        // row ki jagah col bhi kar skte
    {
        cout<<arr[i][i]<<" ";
    }




    cout<<endl;
    
    // sum
    int sum=0;
    for (int i = 0; i < row; i++)        // row ki jagah col bhi kar skte
    {           
        sum=sum+arr[i][i];
    }
    cout<<sum;
return 0;
}