#include<iostream>
using namespace std ;

int mem(int n,int k,vector<int>&dp){
    //1.
    if(n==1){
        return k;
    }
    if(n==2){
        return k+(k*(k-1));
    }
    //3.
    if(dp[n]!=-1){
        return dp[n];
    }
    //2.
    dp[n]=(mem(n-1,k,dp)+mem(n-2,k,dp))*(k-1);
    
    return dp[n];

}

int main()
{
    int n=3;
    int k=3;
    vector<int>dp(n+1,-1);    // dp[i] : stores the ans of i fences
    int ans=mem(n,k,dp);
    cout<<ans;
return 0;
}