//lc 1262
//dp[idx][sum] nhi kar payege as sum. out of range of array index jayega
// class Solution {
// public:
//     int solve(int idx,int sum,vector<int>& nums,vector<vector<int>>&dp){
//         if(idx==nums.size()){
//             if(sum%3==0) return sum;
//             return -1e9;
//         }
//         if(dp[idx][sum]!=-1) return dp[idx][sum];

//         int take=solve(idx+1,sum+nums[idx],nums);
//         int nottake=solve(idx+1,sum,nums);

//         return dp[idx][sum]=max(take,nottake);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int n=nums.size();
//         int idx=0;
//         int sum=0;
//         vector<vector<int>>dp(n+1,vector<int>(1e9,-1));
//         int ans=solve(idx,sum,nums,dp);
//         return ans;
//     }
// };


//dp[idx][sum_mod3] se krege

//NOTE: THIS IS WRONG
// class Solution {
// public:
//     int solve(int idx,int sum,vector<int>& nums,vector<vector<int>>&dp){
//         if(idx==nums.size()){
//             if(sum%3==0) return sum;
//             return INT_MIN;
//         }
//         if(dp[idx][sum%3]!=-1) return dp[idx][sum%3];

//         int take=solve(idx+1,sum+nums[idx],nums,dp);
//         int nottake=solve(idx+1,sum,nums,dp);

//         return dp[idx][sum%3]=max(take,nottake);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         int n=nums.size();
//         int idx=0;
//         int sum=0;
//         vector<vector<int>>dp(n+1,vector<int>(3,-1)); //dp[idx][sum_mod3]
//         int ans=solve(idx,sum,nums,dp);
//         return ans;
//     }
// };

//CORRECT
//https://youtu.be/bKbLIDzLiGQ?si=ETC5G-OFj81iymYa

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