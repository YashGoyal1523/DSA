#include<iostream>      // given an array ..insert its even elements in a vector
#include<vector>
using namespace std ;


void insert(int arr[],int size,int index,vector<int>&v){
    if(index>=size) return;

    if(arr[index]%2==0){
         v.push_back(arr[index]);
         }
    insert(arr,size,index+1,v);
    return;
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int size=6;
    int index=0;
    vector<int>v;
    insert(arr,size,index,v);
    cout<<v[0];
return 0;
}