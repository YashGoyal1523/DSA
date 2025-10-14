
// // leetcode 239 sliding window max

// using sliding window

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         vector<int>ans; // will store max values of each window
//         deque<int>dq; // will store indexes of elements of nums

//         // first k elements ko process...ie first window ko process
//         for(int i=0;i<k;i++){
//             // remove the elements from queue that are smaller than current element of nums
//             while(!dq.empty() && nums[i]>nums[dq.back()]){
//                 dq.pop_back();
//             }
//             // now insert krdo current element
//             dq.push_back(i); // index krege add...index krre taaki out of range wala check kr skeee
//         }
//         // ans store of window 1
//         ans.push_back(nums[dq.front()]);

//         // processing rest elements...ie rest windows
//         for(int i=k;i<nums.size();i++){
//             // remove out of range elements
//             if(!dq.empty() &&  i - dq.front() >= k) {
//                 dq.pop_front();
//              }
//             /// remove elements which are less than current element
                
//                 while(!dq.empty() && nums[i] > nums[dq.back()]){
//                     dq.pop_back();
//                 }
//                 // addition of element
//                  dq.push_back(i);
//             // ans store of current window
//             ans.push_back(nums[dq.front()]);
//         }
//         return ans;
//     }
// };