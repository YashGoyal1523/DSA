// given a vector with digits stored make no....eg 4 2 1 5 se 4215 banao
#include<iostream>
#include<vector>
using namespace std ;

void number(vector<int>v,int index,int&ans){
  
    if(index>=v.size()) return ;
 
    ans=ans*10+v[index];
    number(v,index+1,ans);
    return ;
}

int main()
{
    vector<int>v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    int index=0;
    
    int ans=0;
    number(v,index,ans);
    cout<<ans;
return 0;
}