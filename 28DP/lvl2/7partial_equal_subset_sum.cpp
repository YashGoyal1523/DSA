// lc 416 partition equal subset sum
// given positive elements
// total sum: odd-> false as division not possible
// for even -> total sum ka half lelo . bas yeh half wale ke liye dhundhlo array m ki koi subset bana paayega yeh sum ya nhi. banalega toh true else false. use include/exclude

// class Solution
// {
// public:
//     bool solveUsingRecursion(vector<int> &arr, int index, int sum, int target)
//     {
//         if(index == arr.size())
//         {
//             return false;          // iss mein zruri nhi ki sum==target ke baad aayegi index wali jse subset sum problem m krte as yaha agar present hoge 2 subsets toh abtak ek mil chuka hoga and if yaha pahcuhe mtlb nhi h present
//         }
//         if(sum > target)
//         {
//             return false;  
//         }
//         if(sum == target)
//         {
//             return true; 
//         }

//         // recursion
//         bool include = solveUsingRecursion(arr, index + 1, sum + arr[index], target);
//         bool exclude = solveUsingRecursion(arr, index + 1, sum, target);
// //     bool ans=include||exclude;
// //     return ans;
//         return include || exclude;
//     }
//     bool canPartition(vector<int> &nums)
//     {
//         int totalSum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             totalSum += nums[i];
//         }
//         if (totalSum & 1)
//         {
//             // odd cannot be partioned
//             return false;
//         }

//         int target = totalSum / 2;
//         int currSum = 0;
//         int index = 0;
//         bool ans = solveUsingRecursion(nums, index, currSum, target);

//         return ans;
//     }
// };


// class Solution {
// public:
// bool solveUsingMem(vector<int>& arr, int index, int sum, int target,vector<vector<int> >& dp) {
// if(sum > target) {
// return false;
// }
// if(sum==target) {
// return true;            // 1 ya true chaljayega
// }
// if (index == arr.size()) {
// return 0;  // 0 ya false dono chaljayega
// }
// if (dp[index][sum]!= -1) {
// return dp[index][sum];
// }
// //recursion
// bool include = solveUsingMem(arr,index+1, sum+arr[index], target,dp);
// bool exclude = solveUsingMem(arr, index+1, sum, target,dp);
// // dp[index][sum] = (include || exclude);
// // return dp[index][sum];
// return dp[index][sum] = (include || exclude);
// }

//     bool canPartition(vector<int>& nums) {
//         int totalSum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             totalSum += nums[i];
//         }
//         if (totalSum & 1)
//         {
//             // odd cannot be partioned
//             return false;
//         }
//         int target = totalSum / 2;
//         int currSum = 0;
//         int index = 0;
// vector<vector<int> > dp(nums.size()+1, vector<int>(target+1, -1));   // int wala banake krna pdega as not visited case bhi chahie and bool m only two option // index nums.size tak jaaywga toh size+1 ka // sum ..>target bhi jaayega par kuch definite nhi h ki kitna jaayega toh index ke bina hi krlete ....voh handle hojayega uske liye indexes ki zrurat noi as base case mei handle hojayega
// bool ans = solveUsingMem(nums, index, currSum, target,dp);
// return ans;
//     }
// };



// class Solution {
// public:
// bool solveUsingTab(vector<int>& arr, int target) {
// int n = arr.size();
// vector<vector<int> > dp(n+1, vector<int>(target+1, 0));  // n row handle  // sum...>target ko bina index banaye hi handle krege as no definite
// for(int row=0; row<=n; row++) { //target col handle
// dp[row][target] = 1;
// }
// for(int ind=n-1; ind>=0; ind--) { // n handle h toh n-1 se
// for(int s = target-1; s>=0; s--) { //target handle h toh target-1 se
// bool include = 0;
// if(s+ arr[ind] <= target) // out of bound na chale jaaye isiliye krna pdega (sum....>target wala case handle hogya (> mein 0 hi h value) )
// include = dp[ind+1][s+arr[ind]];
// bool exclude = dp [ind+1] [s];
// dp[ind][s] = (include || exclude);
// }
// }
// return dp[0][0];
// }
//     bool canPartition(vector<int>& nums) {
//          int totalSum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             totalSum += nums[i];
//         }
//         if (totalSum & 1)
//         {
//             // odd cannot be partitioned
//             return false;
//         }

//         int target = totalSum / 2;
        
//         bool ans = solveUsingTab(nums, target);

//         return ans; 
//     }
// };



// // ek row ka ans uski next row par depend

// class Solution {
// public:
// bool solveUsingTabSO(vector<int>& arr, int target) {
// int n = arr.size();
// vector<int>curr(target+1,0); // initially at n-1 row
// vector<int>next(target+1,0); // initially at n row ....ans pata h...0...target index ko krlia agli line m
// // dono ka target index ka ans pata h 
// curr[target]=1; (varying value nhi h like in edit distance toh saari rows na bani ka tension nhi h.... toh krdo yhi shi h)
// next[target]=1;
// for(int ind=n-1; ind>=0; ind--) { 
// for(int s = target-1; s>=0; s--) { 
// bool include = 0;
// if(s+ arr[ind] <= target) 
// include = next[s+arr[ind]];
// bool exclude = next[s];
// curr[s] = (include || exclude);
// }
// //shift
// next=curr;
// }
// return next[0];
// }
//     bool canPartition(vector<int>& nums) {
//          int totalSum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             totalSum += nums[i];
//         }
//         if (totalSum & 1)
//         {
//             // odd cannot be partitioned
//             return false;
//         }

//         int target = totalSum / 2;
        
//         bool ans = solveUsingTabSO(nums, target);

//         return ans; 
//     }
// };