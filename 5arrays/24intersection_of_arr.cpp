//lc 350
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.
 
 // m1 : two pointer
 // dono ko sort krlo
 // dono ke shuru par ptr rkhdo ...element compare kro if equal toh ans vector m push and dono aage bhadao  ......agar chota bada h toh  jo chota h uske wala incremenet krdo dusra vhi rkho ...ese ese krte rho till dono khatm hojaye ya koi ek khatm hojae
//  class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
        
//         int i = 0, // nums1 ki starting par
//         int j = 0;  // nums 2 ki starting par
//         vector<int> result;
        
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i] < nums2[j]) {
//                 i++;
//             } else if (nums1[i] > nums2[j]) {
//                 j++;
//             } else {
//                 result.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
        
//         return result;
//     }
// };

//m2: counting of elements using map

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         map<int,int>m1;
//         map<int,int>m2;
//         for(int i=0;i<nums1.size();i++){
//             m1[nums1[i]]++;
//         }
//          for(int i=0;i<nums2.size();i++){
//             m2[nums2[i]]++;
//         }
//         vector<int>ans;
//         for(auto i:m1){
//             for(int j=1;j<=min(m1[i.first],m2[i.first]);j++){
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     }
// };
