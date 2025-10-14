//lc 643
// maximum average subarray 1
//You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// bruteforce : shuru se start hoke har individual window (subarray) ka check kro :nested loops : tle dega

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double ans=INT_MIN;
//         for(int i=0;i<nums.size()-k+1;i++){
//             double sum=0;
//             for(int j=i;j<i+k;j++){
//                 sum=sum+nums[j];
//             }
//             double avg=sum/k;
//             ans=max(ans,avg);
//         }
//         return ans;
//     }
// };


// sliding window method


// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double ans=INT_MIN;
// //   processing first k elements ie first window
//         double sum=0;
//       for(int i=0;i<k;i++){
//         sum=sum+nums[i];
//       }
//         double avg=sum/k;

//         ans=max(ans,avg);
// // baaki windows
//         for(int i=k;i<nums.size();i++){
//             sum=sum-nums[i-k]+nums[i]; // new add , purana remove
//             avg=sum/k;
//             ans=max(ans,avg);
//         }

//         return ans;
//     }
// };