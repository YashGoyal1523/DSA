// lc 516

// bruteforce
// generate all subsequrence, check for palindromic and take longest wala

// lcs method - take string 2 as string 1 ka reverse and unka longest comman subsequence nikaaldo bas

// class Solution {
// public:
// int solveUsingTabulationSO(string a, string b) {
// vector<int> curr(b.length()+1, 0);
// vector<int> next(b.length()+1, 0);

// for(int i_index=a.length()-1; i_index>=0; i_index--) {
// for(int j_index=b.length()-1; j_index>=0; j_index--) {           //  rowwise ans build hora right to left ,bottom to top
// int ans = 0;
// if (a[i_index] == b[j_index]) {
// ans = 1 + next[j_index+1];
// }
// else {
// ans = 0 + max(next[j_index], curr[j_index+1]);
// }
// curr[j_index] = ans;
// }
// //shifting
// next = curr;
// }
// return next[0];
// }
//     int longestPalindromeSubseq(string s) {
//         string a=s;
//         reverse(a.begin(),a.end());
//         int ans=solveUsingTabulationSO( s, a);
//         return ans;
//     }
// };