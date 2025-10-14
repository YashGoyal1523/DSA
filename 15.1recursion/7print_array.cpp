#include<iostream>
using namespace std ;

void print(int arr[],int size,int index){
    if(index>=size) return;

    cout<<arr[index]<<" ";
    print(arr,size,index+1);
    
    return;
}




int main()
{
    int arr[5]={1,2,3,4,5};
    int size=5;
    int index=0;

    print(arr,size,index);
return 0;
}