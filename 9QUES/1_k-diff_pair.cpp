// lc 532

// m1  
//need to check abs difference==k
// agar normal ek element ke liye pure mein check krte rhege linear search se ie saare pairs check krege toh (1,2 and 2,1 dono miljaayege...dikkat... ek hi count krna h)
//  sort krke ...element ke right m check krte rho .......(isse 1,2 and 2,1 mein sirf 1,2 hi milega)
//  unique ke liye...we use set

//linear search
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         set<pair<int,int> > s;       // set stores unique
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(abs(nums[i]-nums[j])==k){    //or abs(nums[j]-nums[i])==k ....or to be precise (sorted h ..j bada wala hoga)..... nums[j]-nums[i]==k
//                     s.insert({nums[i],nums[j]});
//                 }
//             }
//         }
//         return s.size();
//     }
// };

// binary search (sorted h toh kr skte)
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         set<pair<int,int> > st;
//         for(int i=0;i<nums.size()-1;i++){
//            int s=i+1;
//            int e=nums.size()-1;
//            while(s<=e){
//             int mid=(s+e)/2;
//             if(k==nums[mid]-nums[i]){            // mid bade wala hoga 
//                 st.insert({nums[i],nums[mid]});
//                 break; // terminates inner loop

//             }
//             else if(k<nums[mid]-nums[i]){
//                 e=mid-1;

//             }
//             else s=mid+1;
//            }
//         }
//         return st.size();
//     }
// };


// m2
// note : nums[i]-nums[j]=k => nums[j]=nums[i]+k : hume nums[i] ke liye nums[j] dhundna hai... so hume for every value nums[i] dhundhna hai ki if value nums[i]+k present or not...if present then pair milgya
// isme 1,2 and 2,1 mein se 1,2 hi milega..
// har element ke liye pure m dekho linear search se except voh 
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//       //  sort(nums.begin(),nums.end());
//         set<pair<int,int> > s;
//         for(int i=0;i<nums.size();i++){
//             for(int j=0;j<nums.size();j++){
//                 if(i!=j&&nums[i]+k==nums[j]){
//                     s.insert({nums[i],nums[j]});
//                 }
//             }
//         }
//         return s.size();
//     }
// };

//ya
//  sort krke ...element ke right m dekhte rho....(sort will help in right m hi dekhna as x+k x se bada hoga toh right m hi milega)

//linear search 

// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         set<pair<int,int> > s;
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+k==nums[j]){
//                     s.insert({nums[i],nums[j]});
//                 }
//             }
//         }
//         return s.size();
//     }
// };

// binary search (sorted m laga skte)

// class Solution {
// public:
// int bs (vector<int>&nums, int start, int x) {
// int end = nums.size()-1;
//    while(start<=end) {
// int mid = (start+end)/2;
// if (nums [mid] == x) {
// return mid;
// }
// else if (x > nums [mid]) {
// start = mid+1;
// }
// else{
// end=mid-1;
// }
// }
// return -1;

// }
// int findPairs (vector<int>& nums, int k) {
// sort(nums.begin(), nums.end());
// set<pair<int, int>>ans;
// for(int i=0;i<nums.size();i++){
// if(bs (nums, i+1, nums [i]+k) != -1){
// ans.insert({nums[i], nums [i] + k});
// }
// }
// return ans.size();
// }
// };



// m3 two pointer

// class Solution
// {
// public:
//     int findPairs(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         set<pair<int, int>> s;
//         int i = 0, j = 1;
//         while (j < nums.size())
//         {
//             int diff = nums[j] - nums[i];  // (sorted h ...i chota wla hoga ...j bada wala)  //or  diff=abs(nums[i]-nums[j]) 

//             if (diff == k)
//             {
//                 s.insert({nums[i], nums[j]});
//                 ++i;
//                 ++j;
//             }
//             else if (diff > k)
//             {
//                 i++;
//             }
//             else
//             {
//                 j++;
//             }

//             if (i == j)     // note: agar krte krte dono ek par aajaye toh j aage bhadado
//             { 
//                 j++;
//             }
//         }
//         return s.size();
//     }
// };


