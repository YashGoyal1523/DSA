// store the indexes of occurrence in a vector
#include<iostream>
using namespace std ;

void occ(int arr[],int size,int target,int index,vector<int>&ans){    // by reference

    if(index>=size) return; // base case

    if(arr[index]==target) ans.push_back(index);
    occ(arr,size,target,index+1,ans);
    return;
}
   
int main()
{
    int arr[]={1,2,1,4,5};
    int size=5;
    int target=1;
    int index=0;
    vector<int>ans;
    occ(arr,size,target,index,ans);


     // printing vector
   int sizee=ans.size();

    for (int i = 0; i < sizee; i++)
    {
       cout<<ans[i]<<" ";
    }
return 0;
}