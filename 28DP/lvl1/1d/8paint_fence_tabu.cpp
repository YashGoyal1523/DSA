#include<iostream>
using namespace std ;

int tabu(int n,int k){
    //1.
    vector<int>dp(n+1,-1);
    //2.
    dp[1]=k;
    dp[2]=k+(k*(k-1));
    //3.
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])*(k-1);
    }
    return dp[n];

}





int main()
{
    int n=3;
    int k=3;
    
    int ans=tabu(n,k);
    cout<<ans;
return 0;
}