#include<iostream> // given array , tell present or not 
using namespace std ;         

bool linearsearch(int arr[],int size,int target){
    for (int i = 0; i < size ; i++)
    {
        if(arr[i]==target){
            
            //found
            return true;            // suppose found:true, not found:false
        }
        
    }
    // idhar reached so
    // not found
     return false;
}

int main()
{
    int arr[5]={1,2,3,4,5};    
    int size=5;
    int target=6;
    bool ans=linearsearch(arr,size,target);  

    if (ans==1) // ans==true
    {
        cout<<"found";
    }
    else cout<<"not found";



return 0;
}



 // tc=O(n)