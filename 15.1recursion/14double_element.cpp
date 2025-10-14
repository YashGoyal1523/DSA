#include<iostream>   // double each element
using namespace std ;

void doublee(int arr[],int size,int index){
    if(index>=size) return;

    arr[index]=2*arr[index];
    doublee(arr,size,index+1);
    return;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int index=0;
    doublee(arr,size,index);


    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}