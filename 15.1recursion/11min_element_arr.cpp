#include<iostream>
using namespace std ;


int minm(int arr[],int size,int mini,int index){
    if(index>=size) return mini;

    if(arr[index]<mini) mini=arr[index];

    int ans=minm(arr,size,mini,index+1);
    return ans;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int index=0;
    int mini=__INT_MAX__;
    int ans=minm(arr,size,mini,index);
    cout<<ans;
return 0;
}