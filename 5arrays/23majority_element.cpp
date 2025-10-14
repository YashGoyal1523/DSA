//lc169 - Given an array nums of size n, return the majority element.The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

//m1
//The intuition behind this approach is that if an element occurs more than n/2 times in the array (where n is the size of the array), it will always occupy the middle position when the array is sorted. Therefore, we can sort the array and return the element at index n/2.

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return nums[n/2];
//     }
// };

//m2-MOORE'S VOTING ALGORITHM

// Intuition:
// The intuition behind the Moore's Voting Algorithm is based on the fact that if there is a majority element in an array, it will always remain in the lead, even after encountering other elements.

// Explanation:
// Algorithm:

// Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value.
// Iterate through the array nums:
// a. If count is 0, assign the current element as the new candidate and increment count by 1.
// b. If the current element is the same as the candidate, increment count by 1.
// c. If the current element is different from the candidate, decrement count by 1.
// After the iteration, the candidate variable will hold the majority element.

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count = 0;
//         int candidate = 0;
        
//         for (int num : nums) {
//             if (count == 0) {
//                 candidate = num;
//             }
            
//             if (num == candidate) {
//                 count++;
//             } else {
//                 count--;
//             }
//         }
        
//         return candidate;
//     }
// };



//  m3 : counting using map then check if it is more or not then ceil(n/2)


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int>m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
//         }
//         int ans;
//         float n=nums.size()/2;
//         for(auto i:m){
//             if(i.second>ceil(n)){
//                 ans=i.first;
//                 break;
//             }
//         }
//         return ans;
//     }
// };


// note y ceil(x) se bada h toh y x se bhi bada h....toh hum m3 m ceil(size/2) value ki jagah size/2 wale se bhi check kre toh bhi chal jaayega