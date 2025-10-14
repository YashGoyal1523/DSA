//find element in nearly sorted array ( ith index element present in i-1 or i or i+1 index)

// binary search 

#include<iostream>
using namespace std ;

int search(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    

    while(s<=e){

        int mid=s+(e-s)/2;

       
            if(mid-1>=0 && arr[mid-1]==target ){               // phli condition taaki index negative na pahuch jaaye ...ie array se bahar na aajaye
                return mid-1;
            }
            if( arr[mid]==target ){               
                return mid;
            }
            if (mid+1<n&&arr[mid+1]==target)                    //phli condition taaki index negative na pahuch jaaye......array se bahar na aajaye
            {
                return mid+1;
            }
            if(target>arr[mid]){
                //right aao
                s=mid+2;      // +2 as +1 krke jo aayega element voh already mid+1 m check hogya
            }
            else{     // target<arr[mid]
                    // left aoo
                    e=mid-2;
            }
        
    }
    return -1;
}





int main()
{
    int arr[]={20,10,30,50,40,70,60};
    int n=7;
    int target=70;

    int targetidx=search(arr,n,target);

    if(targetidx==-1){
        cout<<"element not found";
    }
    else{
        cout<<"element found at index"<<targetidx;
    }
return 0;
}