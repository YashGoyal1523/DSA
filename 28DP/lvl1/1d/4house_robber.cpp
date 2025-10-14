// //lc `198


//* max sum of non-adjacent elements*  

// method-include/exclude

// // normal recursion

class Solution {
public:
int solveUsingRecursion(vector<int>& nums, int index) {
//base case
if(index>=nums.size()){
   return 0;
}
//recursive relation
int include = nums[index] + solveUsingRecursion(nums, index+2);
int exclude = 0 + solveUsingRecursion (nums, index+1);
int ans = max(include, exclude);
return ans;
}
};

// int rob(vector<int>& nums) {
// int index = 0;
// int ans = solveUsingRecursion(nums, index);
// return ans;
// }
// };              // // will show tle on lc....need dp



// // dp 

// // topdown

// class Solution {
// public:
// int topdown (vector<int>& nums, int index,vector<int>&dp) {
// //base case
// if(index>=nums.size()){
//    return 0;
// }
// if(dp[index]!=-1){
//     return dp[index];
// }
// //recursive relation
// int include = nums[index] + topdown(nums, index+2,dp);
// int exclude = 0 + topdown(nums, index+1,dp);
// dp[index] = max(include, exclude);
// return dp[index];
// }

// int rob(vector<int>& nums) {
// int index = 0;
// int n=nums.size();
// vector<int>dp(n,-1);    // dp[i]: stores the ans of nums from its ith index to right   // n size se hi kaam chal jaayega
// int ans = topdown(nums, index,dp);
// return ans;
// }
// }; 

// // tabu

// class Solution {
// public:

// int tabu(vector<int>& nums) {
// int n = nums.size();
// //step1
// vector<int> dp(n, -1);

// //step2 : initial value daalna ...(base case of recursion se nhi kar paayege)        (dp[i]: stores the ans of nums from its ith index to right )
// dp[n-1] = nums[n-1];  // // nums ke last ka ans pata h toh usse shuru krlia

// //step3
// for(int index = n-2; index>=0; index--) {   // // aab baaki bharo ...piche se aage aare  // // recursion se dekhe toh usme index 0 se n-1 tak jaara(doubt aa skta ki n bhi toh jaara par voh irrelevant h voh exist hi nhi krta) toh isme n-1 se 0 tak laao par n-1 handled toh n-2 se zero laaao
// int tempAns = 0;
// if(index + 2 < n) {     // // yeh case daalna pada for n-2 index as +2 hoke n banjayega which not exist
// tempAns = dp[index+2];
// }
// int include = nums[index] + tempAns;
// int exclude = 0 + dp[index+1];
// dp[index] = max(include, exclude);
// }
// return dp[0];    // recursion ke paramter ki initial value
// }



// int rob(vector<int>& nums) {
//     int ans=tabu(nums);
//     return ans;
// }
// }; 

// // space opti
 // // dp[index] depends on dp[index+1] and dp[index+2] : pattern observed -current ans depends on its next and next to next element ans

// class Solution {
// public:
//  int spaceopt(vector<int>& nums) {
// int n = nums.size(); 
// int next = nums[n-1];   // initialyy represent n-1 index of dp... ans pata hai 
// int nextnext = 0;  //  initialyy reresnt n index (bahar)....ans pata h....no house no money so zero
// int curr;
// for(int index = n-2; index>=0; index--) {
// int tempAns = 0;
// if(index + 2 < n) {
// tempAns = nextnext;
// }
// int include = nums[index] + tempAns;
// int exclude = 0 + next;
// curr = max(include, exclude);
// // shift
// nextnext=next;
// next=curr;
// }
// return next;  // curr se single element m dikkat ayegi ...next se krlete
// }

// int rob(vector<int>& nums) {
//     int ans=spaceopt(nums);
//     return ans;
// }
// };




// tip : agar topdown  mein tle aajaye toh jo parameter pass krre ho usko by ref ass krdena mostly solve hojayega
// tip : mostly tabu mein last m return dp[recursion mein bheja hua parameter ki value] hota hai