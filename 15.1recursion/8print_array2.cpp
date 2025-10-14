#include<iostream>
using namespace std ;


void print(int arr[],int n){
    if(n==0) return;
    cout<<*arr<<" ";
    print(arr+1,n-1);
    return;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    print(arr,n);
return 0;
}