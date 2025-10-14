// find last occurrence of a number in a sorted array


// linear se krne m store krke chalna pdta ans (sorted/non sorted dono m chaljayega)
// binary search se krre  (sorted diya h isiliye kr paare)
#include<iostream>
using namespace std ;      


int lastocc(int arr[],int n,int target){

        int start=0;
        int end=n-1;
        int ans=-1;      // for  storing of idx
        
        while(start<=end){

            int mid=(start+end)/2;
            
            // found
            if(arr[mid]==target){
                // ek baar store krlo index....fir  right men dobara check kro...kya pata iske baad fir aa rkha ho
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

int main()
{
    int arr[]={1,2,4,4,5,6,7};
    int n=7;
    int target=4;

    int ansidx=lastocc(arr,n,target);

    if(ansidx==-1){
        cout<<"not found";
        
    }
      else cout<<"idx is "<<ansidx;


return 0;
} 
