// return vector with indexes of occurrence stored in it
#include<iostream>
#include<vector>
using namespace std ;


void occu(int arr[],int size,int target,int index,vector<int>&ans){    // by reference

    if(index>=size) return; // base case

    if(arr[index]==target) ans.push_back(index);
    occu(arr,size,target,index+1,ans);
    return;

}


vector<int> occ(int arr[],int size,int target,int index){

    vector<int>ans;
    occu(arr,size,target,index,ans);

    return ans;
}

int main()
{
    int arr[]={1,2,1,4,5};
    int size=5;
    int target=1;
    int index=0;
    
    vector<int>v=occ(arr,size,target,index);

  // printing vector
   int sizee=v.size();

    for (int i = 0; i < sizee; i++)
    {
       cout<<v[i]<<" ";
    }

return 0;
}