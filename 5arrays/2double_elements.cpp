// double each element of given array

#include<iostream>
using namespace std ;
int main()
{
    int arr[10];
    int n=10;  // size of array ...no of elements of array
    //input
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    //printing array
       for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    //doubling
    for (int i = 0; i < n; i++)
    {
        arr[i]=2*arr[i];
    }

    cout<<endl;

    //printing new array
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}