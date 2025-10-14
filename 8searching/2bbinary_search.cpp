#include<iostream>   //given sorted array, if present tell index else return -1
using namespace std ;      

// binary search works in sorted array only

int binarysearch(int arr[],int n,int target){

        int start=0;
        int end=n-1;

        
        while(start<=end){   // note < se nhi hoga as usme jab ans last bacha hua single element hoga ....ya array m hi ek single element ho tab..... yeh phle hi rukjaayega (last wale single element case m) ya ghusega hi nhi(single element case m) and uspe process hi nhi hoga // tip jab bhi start=mid+1 and end=mid-1 kre hge toh start<=end hi hoga // tip: yaad rkhna start==end ..single element batata h

            int mid=start+(end-start)/2 ;  //(start+end)/2..isme integer overflow ka chance hai ie sum of both may exceed range....or we can do start/2+end/2
            // found
            if(arr[mid]==target){
                return mid;
            }
            // not found
            else if(arr[mid]<target){
                //right m jao
                start=mid+1;
            }

            else if(arr[mid]>target){
                //left m jao 
                end=mid-1;
             }
        }
    // yaha pahuche mtlb element not present
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    int target=6;

    int ansidx=binarysearch(arr,n,target);

    if(ansidx==-1){
        cout<<"not found";
        
    }
      else cout<<"idx is "<<ansidx;


return 0;
} 
//need sorted array (either ascending or descending) for binary search
//  tc=logn.....(proof: n/2^k=1)
// if start==end...means single element present    