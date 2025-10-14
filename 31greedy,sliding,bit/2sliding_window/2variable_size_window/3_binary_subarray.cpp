
// lc 930 - binary subarray with sum
// note : entries are 0 or 1



// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int s = 0;
//         int e = 0;
//         int sum = 0;
//         int prefixZero = 0;
//         int count = 0;
        
//         while(e < nums.size() ) {
//             sum = sum + nums[e];

//             while(s < e && (sum > goal || nums[s] == 0)) {            
//             //minimise
//                 //ans
//                 if(nums[s] == 1 ){
//                     prefixZero = 0;
//                 }
//                 else {
//                     prefixZero += 1;
//                 }
//                 //sum
//                 sum = sum - nums[s];
//                 //start
//                 s++;
//             }
//             //verification
//             if(sum == goal) {
//                 count += prefixZero + 1;
//             }
//             e++;
//         }
//         return count;
//     }
// };