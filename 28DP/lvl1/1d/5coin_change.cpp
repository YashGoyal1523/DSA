// better striver : include/exclude


// //lc 322 coin change

// infinite supplies pattern

// method- explore all possible ways

// // RECURSION

// class Solution {
// public:

int solveUsingRecursion (vector<int>& coins, int amount) {
//base case
if (amount == 0) {
return 0;
}
//recursive relation
int mini = INT_MAX;
//find ans using ith coin
for(int i=0; i<coins.size(); i++) {
//call recursion only for valid amounts
if (amount-coins[i] >= 0) {
int recursionKaAns = solveUsingRecursion(coins, amount-coins[i]);
// if valid ans
if (recursionKaAns != INT_MAX) {
int ans = 1 + recursionKaAns; // // 1 add kiya for usage of current coin
mini = min(mini, ans);
}
}
}
return mini;
}
int coinChange (vector<int>& coins, int amount) {
int ans = solveUsingRecursion(coins, amount);
if (ans == INT_MAX)
return -1;
else {
return ans;
}

    }
// };

// // topdown

// class Solution {
// public:
//   int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
//     if (amount == 0) {
//     return 0;
//     }
//     //ans already exist
//     if(dp[amount]!=-1){
//     return dp[amount];
//     }

//     //recursive relation
//     int mini = INT_MAX;
//     for(int i=0; i<coins.size(); i++) {
//     //find ans using ith coin
//     //call recursion only for valid amounts 
//     if(amount-coins [i] >= 0) {
//     int recursionKaAns = solveUsingMem (coins, amount-coins[i], dp);
//     //if a valid answeer
//     if (recursionKaAns != INT_MAX) {
//     //considering uage of ith coin
//     int ans = 1 + recursionKaAns;
//     mini = min(mini, ans);
//         }
// }
// }
// dp[amount] = mini;
// return dp[amount];
// }
//     int coinChange(vector<int>& coins, int amount) {
//     int n=amount;
//     vector<int> dp(n+1, -1);      // dp[i]: stores the ans of amount i
//     int ans = solveUsingMem (coins, amount, dp);
//     if (ans == INT_MAX)
//     return -1;
//     else {
//     return ans;
//     }
//     }
// };

// // bottom up

// class Solution {
// public:
//     int solveUsingtabulation(vector<int>& coins, int amount) {
//         // step1: 
//         int n = amount;
//         vector<int> dp(n + 1, INT_MAX);
//         // step2: base case analyse
//         dp[0] = 0;
//         // for loop
//         for (int value = 1; value <= amount; value++) {
//             int mini = INT_MAX; 
//             for (int i = 0; i < coins.size(); i++) {
//                 if (value - coins[i] >= 0) {
//                 int recursionKaAns = dp[value-coins[i]];
//                      if (recursionKaAns!= INT_MAX) {
//                         int ans = 1 + recursionKaAns;
//                         mini = min(mini, ans);
//                     }
//                 }
//             }
//             dp[value] = mini;
//         }
//         return dp[amount];
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solveUsingtabulation(coins, amount);
//     if (ans == INT_MAX)
//     return -1;
//     else {
//     return ans;
//         }
//     }
// };


// // space opt not possible ..... dp[value] depends on dp[value-coins[i]] and this is not forming any pattern like ek piche do piche esa kuch...and can be any random one


