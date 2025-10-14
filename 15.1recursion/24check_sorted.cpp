#include<iostream>
using namespace std ;


bool check(int arr[],int size,int index){

    if(index>=size)
     return true; // base case  // yaha tak pahuche sab sorted

    //processing
    if(arr[index]>arr[index-1]){
        // aage check kro
        //recursive call
        bool aagekaans=check(arr,size,index+1);
        return aagekaans;
    }

    else {  // sorted nhi hai
    return false;
    }

}








int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int index=1;

    bool ans=check(arr,size,index);

    if(ans==true) cout<<"yes";
    else cout<<"no";
return 0;
}