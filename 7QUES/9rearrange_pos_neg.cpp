// lc 2149 rearrange array elements by sign

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.



// method 1 : 

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>pos;  // size daalna chaho th daal lo n/2 ke banenge
//         vector<int>neg;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>0) pos.push_back(nums[i]);
//             else neg.push_back(nums[i]);
//         }
//         vector<int>temp;
//         for(int i=0;i<nums.size()/2;i++){  // pos,neg :n/2 size ke banenge   // or  //  i<pos.size() ya i<neg.size()  
//             temp.push_back(pos[i]);
//             temp.push_back(neg[i]);

//         }
//         nums=temp;
//         return nums;
//     }
// };


// method 2 : two pointer



// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>temp(nums.size(), -1);
//         int pos = 0; // index that stores +ve
//         int neg = 1; // index that stores -ve
//         for(int i=0;i<nums.size();++i){
//             if(nums[i] > 0){
//                 temp[pos] =nums[i];
//                 pos+= 2;
//             }
//             else{
//                 temp[neg] = nums[i];
//                 neg+=2;
//             }
//         }
//         nums=temp;
//     return nums;
        
//     }
// };


// note: isko ese bhi soch skte ...pos on even indexes and neg on odd ...
// same code bas likhne ka tarika alag

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>temp(nums.size(), -1);
//         int evenidx = 0; // stores +ve
//         int oddidx = 1; // stores -ve
//         for(int i=0;i<nums.size();++i){
//             if(nums[i] > 0){
//                 temp[evenidx] =nums[i];
//                 evenidx+= 2;
//             }
//             else{
//                 temp[oddidx] = nums[i];
//                 oddidx+=2;
//             }
//         }
//         nums=temp;
//     return nums;
        
//     }
// };