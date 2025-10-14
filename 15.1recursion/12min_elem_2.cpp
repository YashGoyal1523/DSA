#include<iostream>
using namespace std ;


 void minm(int arr[],int size,int &mini,int index){   // &mini kara hai
    if(index>=size) return ;

    mini=min(arr[index],mini);       // in built min function

    minm(arr,size,mini,index+1);
    return ;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int index=0;
    int mini=__INT_MAX__;
    minm(arr,size,mini,index);
    cout<<mini;
return 0;
}