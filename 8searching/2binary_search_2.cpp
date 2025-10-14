// given sorted array ...tell index if present and if not present then index where it should be present
#include<iostream>
using namespace std ;      


int binarysearch(int arr[],int n,int target){

        int start=0;
        int end=n-1;

        
        while(start<=end){

            int mid=start+(end-start)/2 ;  
            if(arr[mid]==target){
                return mid;
            }
            // not found
            else if(arr[mid]<target){
                start=mid+1;
            }

            else if(arr[mid]>target){
                end=mid-1;
             }
        }
    // element not present...note: start is at the position which should be its position
    return start;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    int target=6;

    int ansidx=binarysearch(arr,n,target);

    cout<<ansidx;


return 0;
} 
   