// // lc 15

// https://youtu.be/DhFh8Kw7ymk?si=LePQEFUqt5fj-HxC


// //  bruteforce O(N3 * log(no. of unique triplets))
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         int n=nums.size();
//     // check all possible triplets:
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (nums[i] + nums[j] + nums[k] == 0) {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }

//     //store the set elements in the answer:
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
//     }
// };


// // better O(N2 * log(no. of unique triplets))

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//          set<vector<int>> st;
//     int n=nums.size();
//     for (int i = 0; i < n; i++) {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++) {
//             //Calculate the 3rd element:
//             int third = -(nums[i] + nums[j]);
//             //Find the element in the set:
//             if (hashset.find(third) != hashset.end()) {
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//     }

//     //store the set in the answer:
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
//     }
// };

// //optimal
// // two pointer  O(NlogN)+O(N2),
// // fix one element and for other two use two pointer

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n=nums.size();
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < n; i++) {
//         //remove duplicates:
//         if (i != 0 && nums[i] == nums[i - 1]) continue;

//         //moving 2 pointers:
//         int j = i + 1;
//         int k = n - 1;
//         while (j < k) {
//             int sum = nums[i] + nums[j] +nums[k];
//             if (sum < 0) {
//                 j++;
//             }
//             else if (sum > 0) {
//                 k--;
//             }
//             else {
//                 vector<int> temp = {nums[i], nums[j], nums[k]};
//                 ans.push_back(temp);
//                 j++;
//                 k--;
//                 //skip the duplicates:
//                 while (j < k && nums[j] == nums[j - 1]) j++;
//                 while (j < k && nums[k] == nums[k + 1]) k--;
//             }
//         }
//     }
//     return ans;
//     }
// };

// note: isme duplicates handle krne ka hum set se bhi kr skte
//  yeh remove duplicates wale dono jagah se step hatado and triplets phle set m store krlo fir baad mein ans mein


