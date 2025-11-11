//lc 474

//take nottake

//rec

// class Solution {
// public:
//     map<int,int>ones;
//     map<int,int>zeros;
//     int s;
//     int solve(int idx,int one,int zero,int m,int n){
//         if(one>n||zero>m) return -1e9;
//         if(idx==s) return 0;
        

//         //take
//         int take=1+solve(idx+1,one+ones[idx],zero+zeros[idx],m,n);
//         //not take
//         int nottake=0+solve(idx+1,one,zero,m,n);

//         return max(take,nottake);

//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         s=strs.size();
//         for(int i=0;i<s;i++){
//             ones[i]=count(strs[i].begin(),strs[i].end(),'1');
//             zeros[i]=count(strs[i].begin(),strs[i].end(),'0');
//         }
//         int idx=0;
//         int one=0;
//         int zero=0;
//         int ans=solve(idx,one,zero,m,n);
//         return ans;
//     }
// };


//mem


class Solution {
public:
    map<int,int>ones;
    map<int,int>zeros;
    int s;
    int solve(int idx,int one,int zero,int m,int n,vector<vector<vector<int>>>&dp){
        if(one>n||zero>m) return -1e9;
        if(idx==s) return 0;
        
        if(dp[idx][one][zero]!=-1) return dp[idx][one][zero];
        //take
        int take=1+solve(idx+1,one+ones[idx],zero+zeros[idx],m,n,dp);
        //not take
        int nottake=0+solve(idx+1,one,zero,m,n,dp);

        return dp[idx][one][zero]=max(take,nottake);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        s=strs.size();
        for(int i=0;i<s;i++){
            ones[i]=count(strs[i].begin(),strs[i].end(),'1');
            zeros[i]=count(strs[i].begin(),strs[i].end(),'0');
        }
        int idx=0;
        int one=0;
        int zero=0;
        vector<vector<vector<int>>>dp(s+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        int ans=solve(idx,one,zero,m,n,dp);
        return ans;
    }
};