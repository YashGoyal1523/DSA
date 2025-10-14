// rotate give array right by 1 step or we can say shift elements of array to right by 1 position....ie if input array is 1 2 3 then output array is 3 1 2 



// method: first index se shuru hoke next mein pichla daaltte rho...ese toh nhi hogaa as previous change hota rhega....so last index se shuru hoke usme ek pichle ki value daalte rhege....par aise 1st wala rehgyaa and last wala bhi change hogya....toh 1st element ke liye phle hi last ko store krlege and fir daaldege usse first par
#include<iostream>
using namespace std ;

void rightshift(int arr[],int n){

        int temp=arr[n-1];

        for (int i = n-1; i >=1; i--)        // 0 tak mat daaldena i as vse bhi koi fayda nhi hoga usee andddd also usme i-1 ..-1 banjayega and error show hoga arr[-ve] ke karan
        {
            arr[i]=arr[i-1];      // arr[i-1]=arr[i] mat likhdena as usme phle wale m agle ki value dalegi
        }
        
        arr[0]=temp;

        return;
}





int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    //print array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    rightshift(arr,n);

cout<<endl;
    //print array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}





// for right  shift by k times........last ke k elements alag alag variables mein store krlena ya better hai temp mein array banalena last ke k elemnts ka....and arr[i]=arr[i-k]  karlena and loop n-1 se >=k tak chalana  ... fir shuru ke k jagahs mein temp daaldena