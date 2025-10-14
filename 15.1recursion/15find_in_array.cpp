// find target and return its index else return -1 if not found
#include<iostream>
using namespace std ;

int find(int arr[],int size,int target,int index){
    if(index>=size) return -1; //not found  //base case

    if(arr[index]==target) return index;
    int ans=find(arr,size,target,index+1);
    return ans;
    
}



int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int target=3;
    int index=0;
    int ans=find(arr,size,target,index);
    cout<<ans;
return 0;
}