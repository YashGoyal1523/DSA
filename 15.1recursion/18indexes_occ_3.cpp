// return vector with indexes of occurrence stored in it
#include<iostream>
#include<vector>
using namespace std ;

vector<int> occ(int arr[],int size,int target,int index){

    vector<int>ans;
   
     if(index>=size) return ans; 

    if(arr[index]==target){
        ans.push_back(index);
    }
    vector<int>aagekaans=occ(arr,size,target,index+1);

    // dono ans combine krre alag vector mein
    vector<int>finalans;

    for (int i = 0; i < ans.size(); i++)
    {   
        finalans.push_back(ans[i]);
    }
    for (int i = 0; i < aagekaans.size(); i++)
    {   
        finalans.push_back(aagekaans[i]);
    }
    
    return finalans;
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