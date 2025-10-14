// given an array of elements(can be duplicate). give indices of greatest three elements

#include<iostream>
using namespace std ;
int main()
{
 vector<int>arr={3,4,5,3,1,4};
 
 vector<pair<int,int>>p;
 for(int i=0;i<arr.size();i++){
    p.push_back({arr[i],i});
 }

 sort(p.begin(),p.end(),greater<pair<int,int>>());

 cout<<p[0].second<<" "<<p[1].second<<" "<<p[2].second;
return 0;
}