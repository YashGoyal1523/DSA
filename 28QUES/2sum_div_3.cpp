//lc 1262

//dp[idx][sum] se nhi ho payega as sum value index range ke out jaayegi


//https://youtu.be/bKbLIDzLiGQ?si=ETC5G-OFj81iymYa

//dp[idx][sum_mod3] se krege

class Solution {
public:
    int solve(int idx,int mod,vector<int>& nums,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(mod==0) return 0;
            return INT_MIN;
        }
        if(dp[idx][mod]!=-1) return dp[idx][mod];

        int take=nums[idx]+solve(idx+1,(mod+nums[idx])%3,nums,dp);
        int nottake=solve(idx+1,mod,nums,dp);

        return dp[idx][mod]=max(take,nottake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        int mod=0;
        vector<vector<int>>dp(n+1,vector<int>(3,-1)); //dp[idx][sum_mod3]
        int ans=solve(idx,mod,nums,dp);
        return ans;
    }
};