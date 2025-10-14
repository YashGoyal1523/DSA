// lc 724
// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// //m1 : bruteforce 
// // har index ke liye leftsum nikalo rightsum nikalo and check krte jao jisme same voh ans 
// // o(n^2)
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
       
//         for(int i=0;i<nums.size();i++){
//              int leftsum=0;
//              int rightsum=0;

//                 for(int j=i-1;j>=0;j--){
//                     leftsum=leftsum+nums[j];
//                 }


//                 for(int k=i+1;k<nums.size();k++){
//                     rightsum=rightsum+nums[k];
//                 }

//              if(leftsum==rightsum) return i;
//         }
//         return -1;
//     }
// };



// m2 :  prefix sum /suffix sum approach :excluding itself: prefixsum of nth element= value of (n-1)th  element + prefixsum of (n-1)th element  , suffixsum of nth  element = value of (n+1)th  element + suffixsum of (n+1)th  element ........ 
//                                       :including itself: prefixsum of nth element= value of nth element + prefixsum of (n-1)th element  , suffixsum of nth  element = value of nth element + suffixsum of (n+1)th  element ........ 
// excluding wale se nikal jaayega leftsum rightsum
//  class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//        vector<int>lsum(nums.size());   // iske i index par nums ke i index wale ka leftsum hoga
//         vector<int>rsum(nums.size());  // iske i index par nums ke i index wale ka rightsum hoga

// //  lsum array
// lsum[0]=0;  // phle wale ka leftsum is 0
// for(int i=1;i<nums.size();++i){
//      lsum[i] = lsum[i-1] + nums[i-1];
// }
// //  rsum array
// rsum[nums.size()-1]=0;   // last wale ka rightsum is 0
// for(int i=nums.size()-2;i>=0;--i) {
// rsum[i] = rsum[i+1] + nums[i+1];
// }
// // check krte hai 
// for(int i=0;i<nums.size();++i){
//      if(lsum[i] == rsum[i]) return i;
// }
// return -1;
//     }
// };