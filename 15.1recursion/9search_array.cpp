#include<iostream>        // tell whether target present or not
using namespace std ;

bool search(int arr[],int size,int target,int index){
    
    if(index>=size) return false; //base case

    if(arr[index]==target) return true;
    bool ans=search(arr,size,target,index+1);
    return ans;
}








int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int target=3;
    int index=0;

    cout<<"found or not "<<search(arr,size,target,index);
return 0;
}