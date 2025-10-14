

// lc375 Guess no higher or lower 2


// PARTITIONING/MERGE INTERVAL PATTERN 


// 1 se n tak har ka dekhege ki usse shuru krte toh itne max chahie hote.. and sbka min lelege
// max wala tab milega jab har guess wrong kre last tak

// class Solution
// {
// public:
//     int solveUsingRecursion(int start, int end)
//     {
//         // base case
//         if (start >= end)// range se bahar , single number case m zero penalty
//         { 
//             return 0;
//         }
//         int ans = INT_MAX;
//         for (int i = start; i <= end; i++)
//         {
//             ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
//         }
//         return ans;
//     }
//     int getMoneyAmount(int n)
//     {
//         int start = 1;
//         int end = n;
//         int ans = solveUsingRecursion(start, end);
//         return ans;
//     }
// };




// class Solution
// {
// public:

//  int solveUsingMem(int start, int end,vector<vector<int> >& dp ) {
//         //base case
//         if(start >= end) {
//             return 0;
//         }

//         if(dp[start][end] != -1) {
//             return dp[start][end];
//         }

//         int ans = INT_MAX;
//         for(int i=start; i<=end; i++) {
//             ans = min(ans, i + max(solveUsingMem(start, i-1,dp), solveUsingMem(i+1, end,dp)));
//         }
//         dp[start][end] = ans;

//         return dp[start][end]; 
//     }

//  int getMoneyAmount(int n) {
//         int start = 1;
//         int end = n;
//         vector<vector<int> > dp(n+2, vector<int>(n+1, -1));   // start - 0 se  end+1 tak jaara toh index n+1 tak chahie, end- n se vaapis aara toh n index tak chahie
//         int ans = solveUsingMem(start,end,dp);
//         return ans;
//     }
// };


// class Solution
// {
// public:

//     int solveUsingTabulation(int n) {
//         vector<vector<int> > dp(n+2, vector<int>(n+1, 0));
//         for(int start_index = n-1; start_index>=1; start_index--) {
//             for(int end_index = 1; end_index<=n; end_index++) {

//                 if(start_index >= end_index) {
//                     //invalid range, single number
//                     continue;
//                 }
//                 int ans = INT_MAX;
//                 for(int i=start_index; i<=end_index; i++) {
//                     ans = min(ans, i + max(dp[start_index][i-1], dp[i+1][end_index] ) );
//                 }
//                 dp[start_index][end_index] = ans;
                
//             }
//         }
//         return dp[1][n];
//     }

//     int getMoneyAmount(int n) {
//         int start = 1;
//         int end = n;
//         int ans = solveUsingTabulation(n);
//         return ans;
//     }
// };


// // space opt nhi kr paayege