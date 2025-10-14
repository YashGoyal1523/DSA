// lc 198 house robber


// max sum of non-adjacent elements

// method-include/exclude

// class Solution {
// public:
//     int solve(vector<int>& nums, int index) {
//         //base case
//         if(index >nums.size()-1 ) {
//             return 0;
//         }

//         //chori karlo -> ith index pr
//         int include = nums[index] + solve(nums, index+2);

//         //chori mat karo  -> ith index pr
//         int exclude = 0 + solve(nums,  index+1);

//         int finalAns = max(include, exclude);

//         return finalAns;
//     }
//     int rob(vector<int>& nums) {
//         int index = 0;
//         int ans = solve(nums,index);
//         return ans;

        
//     }
// };


// TLE dega as dp use krni pdegi