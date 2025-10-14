#include<iostream>
using namespace std ;


int search(int arr[],int s,int e,int target){

// base case
    if(s>e) return -1; // not found 

//  processing
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
     return mid;
    } 

//recursive call
    if(arr[mid]>target){
        // e=mid-1;
        // int aagekaans=search(arr,s,e,target);
        // return aagekaans;
        return search(arr,s,mid-1,target);
    }
    else {  // arr[mid]<target
    return search(arr,mid+1,e,target);   
    }

}


int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int s=0;
    int e=size-1;
    int target=2;

    int foundidx=search(arr,s,e,target);

    if(foundidx==-1)
     cout<<"not found";

    else 
    cout<<"found at index "<<foundidx;
return 0;
}