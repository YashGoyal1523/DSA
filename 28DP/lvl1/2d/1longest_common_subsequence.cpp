//lc 1143 longest common subsequence (lcs)

// //recursion

 
//  class Solution{
// public:
// int solveUsingRecursion(string a, string b, int i, int j) {
// //basecase
// if(i >= a.length()) {
// return 0;
// }
// if(j >=b.length()) {
// return 0;
// }
// //recursive call
// int ans = 0;
// if(a[i]==b[j]) {
// ans = 1 + solveUsingRecursion(a,b, i+1, j+1);
// }
// else {
// ans = 0 + max(solveUsingRecursion(a,b, i, j+1),solveUsingRecursion(a,b, i+1, j));
// }
// return ans;
// }
// int longestCommonSubsequence (string text1, string text2) {
// int i = 0;
// int j = 0;
// int ans = solveUsingRecursion(text1,text2,i,j);
// return ans;
// }
// }; 


// // top down

//  class Solution{
// public:
// int solveUsingMem(string a, string b, int i, int j,vector<vector<int> >& dp) {
// //basecase
// if(i >= a.length()) {
// return 0;
// }
// if(j >=b.length()) {
// return 0; 
// }
// //check if ans already exists
// if (dp[i][j] != -1) {
// return dp[i][j];
// }
// //recursive call
// int ans = 0;
// if(a[i] == b[j]) {
// ans = 1 + solveUsingMem(a,b, i+1, j+1,dp);
// }
// else {
// ans = 0 + max(solveUsingMem(a,b, i, j+1,dp), solveUsingMem(a,b, i+1, j,dp));
// }
// dp[i][j]=ans;
// return dp[i][j];
// }

// int longestCommonSubsequence(string text1, string text2) {
// int i = 0; // //text1 mein iterate k liye
// int j = 0; // //text2 mein iterate k liye
// vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));   // dp[i][j] reperesents a ki i index and b ki j index se leke  aage ka ans 
// int ans = solveUsingMem(text1,text2, i,j,dp);
// return ans;
// }
//  };

// // but this will show tle - soln: pass parameters by refernce ....sirf strings walo ko krne se kaam chaljaayega par agar i , j  walo ko bhi krna tohh...recursive call mein alag variable mein x=i+1 y=j+1 krke x,y pass krna fir &i &j kar skte function parameter mein 
// // dp ke baad bhi tle dikhe toh by ref try krna variable
//  class Solution{
// public:
// int solveUsingMem(string &a, string &b, int i, int j,vector<vector<int> >& dp) {
// //basecase
// if(i >= a.length()) {
// return 0;
// }
// if(j >=b.length()) {
// return 0; 
// }
// //check if ans already exists
// if (dp[i][j] != -1) {
// return dp[i][j];
// }
// //recursive call
// int ans = 0;
// if(a[i] == b[j]) {
// ans = 1 + solveUsingMem(a,b, i+1, j+1,dp);
// }
// else {
// ans = 0 + max(solveUsingMem(a,b, i, j+1,dp), solveUsingMem(a,b, i+1, j,dp));
// }
// dp[i][j]=ans;
// return dp[i][j];
// }

// int longestCommonSubsequence(string text1, string text2) {
// int i = 0; // //text1 mein iterate k liye
// int j = 0; // //text2 mein iterate k liye
// vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));
// int ans = solveUsingMem(text1,text2, i,j,dp);
// return ans;
// }
//  };


// //tabulation
// class Solution {
// public:
// int solveUsingTabulation(string a, string b) {
// // 1.,2. 
// vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0)); // last walo (i=a.length wali row j=b.length wali col ) par zero daalna tha acc to base case par itni mhnat na karni padi isiliye sabko hi zero krdia...isse bhi chaljayega
// //3.
// for(int i_index=a.length()-1; i_index>=0; i_index--) {  // rec se ulta chalana flow .. a.length ka hogya tha isiliye aage se shuru
// for(int j_index=b.length()-1; j_index>=0; j_index--){  // rec se ulta chalana  flow
// int ans = 0;
// if(a[i_index] == b[j_index]) {
// ans = 1 + dp[i_index+1][j_index+1];
// }
// else {
// ans = 0 + max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
// }
// dp[i_index][j_index] = ans;
// }                               // rowise ans build hora from right to left, bottom to top 
// }
// return dp[0][0];    // recursion ka parameter ki initial value hi return 
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int i = 0;
//         int j = 0;
//         int ans= solveUsingTabulation (text1,text2);
//         return ans;
//     }
// };

// // SO
// element ans depends on element - next col same row, next col next row , same col next row....so req row ka ans on voh row and next row

// class Solution {
// public:
// int solveUsingTabulationSO(string a, string b) {
// vector<int> curr(b.length()+1, 0); // intially second last row ie a.length-1 wali row.....iske last ka ans pata h ..zero chahie...mhnat na krni pde isiliye saare 0 krdie
// vector<int> next(b.length()+1, 0); // initially last row....ie a.length wali row .....ans pata h zero chahie

// for(int i_index=a.length()-1; i_index>=0; i_index--) {
// for(int j_index=b.length()-1; j_index>=0; j_index--) {           //  rowwise ans build hora right to left ,bottom to top
// int ans = 0;
// if (a[i_index] == b[j_index]) {
// ans = 1 + next[j_index+1];         //dp[i_index+1]__ -> next__
// }
// else {
// ans = 0 + max(curr[j_index+1],next[j_index]);   // dp[i_index]__ -> curr__
// }
// curr[j_index] = ans;
// }
// //shifting
// next = curr;
// }
// return next[0];
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int i = 0;
//         int j = 0;

//         int ans =solveUsingTabulationSO(text1,text2);
//    return ans;
//     }
// };

// // aur nhi ho skta optimise





// // note: tabu, SO m colwise ans build bhi kr skte

// //  bas loops inter change krdo ....
// // SO mein row size ke array banana


// class Solution {
// public:
// int solveUsingTabulation(string a, string b) {
// // 1.,2. 
// vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0)); // last walo (i=a.length wali row j=b.length wali col ) par zero daalna tha acc to base case par itni mhnat na karni padi isiliye sabko hi zero krdia...isse bhi chaljayega
// //3.
// // loops interchange for colwise
// for(int j_index=b.length()-1; j_index>=0; j_index--) {
// for(int i_index=a.length()-1; i_index>=0; i_index--) { 
// int ans = 0;
// if(a[i_index] == b[j_index]) {
// ans = 1 + dp[i_index+1][j_index+1];
// }
// else {
// ans = 0 + max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
// }
// dp[i_index][j_index] = ans;
// }
// }
// return dp[0][0];    //  colwise ans build hora bottom to top,right to left 
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int i = 0;
//         int j = 0;
//         int ans= solveUsingTabulation (text1,text2);
//         return ans;
//     }
// };



//element ans depends on element - next col same row, next col next row , same col next row....so req col ka ans on voh col and next col

// class Solution {
// public:
// int solveUsingTabulationSO(string a, string b) {

// // row size ke array 
// vector<int> curr(a.length()+1, 0);
// vector<int> next(a.length()+1, 0); 

// // loops interchange 
// for(int j_index=b.length()-1; j_index>=0; j_index--) {
// for(int i_index=a.length()-1; i_index>=0; i_index--) {           //  colwise ans build hora bottom to top,right to left 
// int ans = 0;
// if (a[i_index] == b[j_index]) {
// ans = 1 + next[i_index+1];        // dp__[j_index+1] -> next__
// }
// else {
// ans = 0 + max(next[i_index],curr[i_index+1]);   // dp__[j_index] -> curr__
// } 
// curr[i_index] = ans;
// }
// //shifting
// next = curr;
// }
// return next[0];
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int i = 0;
//         int j = 0;

//         int ans =solveUsingTabulationSO(text1,text2);
//    return ans;
//     }
// };