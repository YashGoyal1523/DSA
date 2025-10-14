// find first occurrence of a number in a sorted array

// linear se kr skte (sorted/non sorted dono m chaljayega)
// binary search mech se krre...LESS TC..(sorted diya h isiliye kr paare)
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
                // ek baar store krlo index ...fir dobara check kro left mein ..kya pata isse bhi phle aa rkha ho
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

int main()
{
    int arr[]={1,2,4,4,5,6,7};
    int n=7;
    int target=4;

    int ansidx=firstocc(arr,n,target);

    if(ansidx==-1){
        cout<<"not found";
        
    }
      else cout<<"idx is "<<ansidx;


return 0;
} 



// sorted array given aate hi sochna binary search se kar skte kyaa