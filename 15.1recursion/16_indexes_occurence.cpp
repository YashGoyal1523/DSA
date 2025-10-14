// print indexes of occurences of target in array
#include<iostream>
using namespace std ;

void occ(int arr[],int size,int target,int index){
    if(index>=size) return; // base case

    if(arr[index]==target){
        cout<<index<<" ";
    }
    occ(arr,size,target,index+1);
    return;
}



int main()
{
    int arr[]={1,2,1,4,5};
    int size=5;
    int target=1;
    int index=0;
    occ(arr,size,target,index);
return 0;
}