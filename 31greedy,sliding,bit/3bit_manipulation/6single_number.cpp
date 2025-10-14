//lc 136

// class Solution {
// public:
// // xor of same is zero , xor of anything with zero is that anything only
//     int singleNumber(vector<int>& nums) {
//         int n=nums.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans=ans^nums[i];
//         }
//         return ans;
//     }
// };