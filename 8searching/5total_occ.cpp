// find total occ of a number in a sorted array

// m1 :linear se kar sktee...count++ krke..(sorted/non sorted dono m chaljaega)

// m2: in sorted :totalocc=lastoccidx-firstoccidx +1;
//linear se kr skte
//binary se krte....






#include<iostream>
using namespace std ;

int firstocc(int arr[],int n,int target){

        int start=0;
        int end=n-1;
        int ans=-1;      // for storing of idx
        
        while(start<=end){

            int mid=(start+end)/2;
            
            // found
            if(arr[mid]==target){
                // ek baar store krlo index
                 ans=mid;
                //left jao and repeat
                 end=mid-1;

            }
            // not found

            else if(arr[mid]<target){
                // right jao
                start=mid+1;
            }

            else if(arr[mid]>target){
                //left jao
                end=mid-1;
             }
        }
    
    return ans;
}


int lastocc(int arr[],int n,int target){

        int start=0;
        int end=n-1;
        int ans=-1;      // for initial storing of idx
        
        while(start<=end){

            int mid=(start+end)/2;
            
            // found
            if(arr[mid]==target){
                // ek baar store krlo index
                 ans=mid;
                //right jao and repeat
                 start=mid+1;

            }
            // not found


            else if(arr[mid]<target){
                // right jao
                start=mid+1;
            }

            else if(arr[mid]>target){
                //left jao
                end=mid-1;
             }
        }
    
    return ans;
}



int totalocc(int arr[],int n,int target){
    int firstoccidx=firstocc( arr, n, target);
    int lastoccidx=lastocc( arr, n, target);

    int totalocc=lastoccidx-firstoccidx +1;

    return totalocc;
}


int main()
{

int arr[]={1,2,3,4,4,4,4,5,6};
int n=9;
int target=4;

int count=totalocc(arr,n,target);

cout<<"total occ "<<count;

return 0;
}