// find the missing element from range [1,n] in a sorted array of size n in tc less than o(n)....agar sab present hai toh return n+1

// SUM se kr skte , linear search se kr skte ,xor se kr skte , par sabme tc o(n)
//  tc less than O(n) , find krna , sorted array ...sab binary search ko ishara karre

#include<iostream>
using namespace std ;

int missing(int arr[],int n){

    int s=0;
    int e=n-1;
    int ans=-1;           

    while(s<=e){
        int mid=s+(e-s)/2;
        int diff=arr[mid]-mid;


        if (diff==1)
        {
            // shi chlra right chalo
            s=mid+1;
        }
        
        else if(diff!=1){
            // gadbad hogyi .....mtlb yeh toh galat h....par kya pata yeh phla galat na ho .....toh ab isse ek baar store krke left chlo
            ans=mid;                                //or // ans =arr[mid];  
            e=mid-1;
        }
    }

    if (ans+1==0)      // sab order mein....n ke agla missing krdete
    {
        return n+1;
        }

return ans+1;                        // or // return ans-1;
}


int main()
{

    int arr[]={1,2,3,4,5,7};
    int n=6;
    int ans=missing(arr,n);
    cout<<ans;
return 0;
}             // O(logn)


// yeh n+1 wale ke liye humne extra condition lagayi h....code modify kro ki ese alag se na lagani pade and main logic m hi adjust hojaye yeh bhi


// try ques: gfg : https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
//Given an array of size n-1 such that it only contains distinct integers in the range of 1 to n. Return the missing element.