//lc 72

//approach : 

//i,j se traverse kro dono pe
// if char match then dono m aage bhado
// if char not match then 3 options: 1. replace ->dono m aage bhadjao 2. insert ->b mein bhadjao 3.delete ->a mein bhadjao


//ans=0;
// if char match 
//  ans= 0+rec(i+1,j+1);
// else (char not match) 
// replace = 1+rec(i+1,j+1);
// insert = 1+rec(i,j+1);
// delete = 1+rec(i+1,j) ;
// ans=min(replace,min(insert,delete));
// return ans;



// // RECURSION

// class Solution {
// public:
//     int solveUsingRecursion(string a, string b, int i, int j) {
// //base case
// if(i== a.length()) {     // agar a khatm hogya toh b ke jitne bach gye utne add krne pdege a mein toh utne hi add hojayege no of operation mein
// return b.length()-j;
// }
// if(j == b.length()) {  // agar b khatm hogya toh a ke jitne bach gye utne remove krne pdege a mein toh utne hi add hojayege no of operation mein
// return a.length()-i;
// }

// int ans = 0;
// if(a[i] == b[j]) { // match
// // koi operation nhi chahie
// ans = 0 + solveUsingRecursion(a,b,i+1,j+1);
// }
// else {  // no match
//  // operation kro
// // replace
// int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);
// // insert
// int insert = 1 + solveUsingRecursion(a,b,i,j+1);
// // remove
// int remove = 1 + solveUsingRecursion(a,b,i+1,j);
// ans = min(insert, min(remove, replace));
// }
// return ans;
// }
// int minDistance (string word1, string word2) {
// int i = 0;
// int j = 0;
// int ans = solveUsingRecursion(word1, word2, i,j);
// return ans;
        
//     }
// };

// // YEH MEMEORY LIMIT EXCEED KRDEGA TOH TO SAVE MEMORY string ko PASS BY REFERENCE krlia

// class Solution {
// public:
//     int solveUsingRecursion(string &a, string &b, int i, int j) {
// //base case
// if(i== a.length()) {     // agar a khatm hogya toh b ke jitne bach gye utne add krne dege a mein toh utne hi add hojayege no of operation mein
// return b.length()-j;
// }
// if(j == b.length()) {  // agar b khatm hogya toh a ke jitne bach gye utne remove krne pdege a mein toh utne hi add hojayege no of operation mein
// return a.length()-i;
// }
// int ans = 0;
// if(a[i] == b[j]) { 
// ans = 0 + solveUsingRecursion(a,b,i+1,j+1);
// }
// else {
// int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);
// int insert = 1 + solveUsingRecursion(a,b,i,j+1);
// int remove = 1 + solveUsingRecursion(a,b,i+1,j);
// ans = min(insert, min(remove, replace));
// }
// return ans;
// }
// int minDistance (string word1, string word2) {
// int i = 0;
// int j = 0;
// int ans = solveUsingRecursion(word1, word2, i,j);
// return ans;
        
//     }
// };

// // AB YEH DEGA TLE .... AB DP LAGALO

// // mem

// class Solution {
// public:
//  int solveUsingMem(string& a, string& b, int i, int j,vector<vector<int> >& dp) {
//         //base case
//         if(i == a.length()) {
//             return b.length()-j;
//         }
//         if(j == b.length()) {
//             return a.length()-i;
//         }

//         //check if ans already exits
//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int ans = 0;
//         if(a[i] == b[j] ) {
//             ans = 0 + solveUsingMem(a,b,i+1,j+1,dp);
//         }
//         else {
//             int replace = 1 + solveUsingMem(a,b,i+1,j+1,dp);
//             int insert = 1 + solveUsingMem(a,b,i,j+1,dp);
//             int remove = 1 + solveUsingMem(a,b,i+1,j,dp);
//             ans = min(insert,min(remove,replace));
//         }
//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     int minDistance(string word1, string word2) {
//         int i = 0;
//         int j = 0;
//         vector<vector<int> > dp(word1.length()+1,vector<int>(word2.length()+1,-1));
//         int ans = solveUsingMem(word1, word2, i,j,dp);
// return ans;
//     }
// };

// // TABU
// class Solution {
// public:

//     int solveUsingTabulation(string &a,string&b ,int i,int j){
//  //       1.
//         vector<vector<int> > dp(a.length()+1,vector<int>(b.length()+1,-1));
//  //        2.
//         for(int col=0; col<=b.length(); col++) {
//                 dp[a.length()][col] = b.length()-col;
//                 }
//         for(int row=0; row<=a.length(); row++) {
//                 dp[row][b.length()] = a.length()-row;
//                 }
//   //       3.
//           for(int i_index=a.length()-1; i_index>=0; i_index--) {
//          for(int j_index=b.length()-1; j_index>=0; j_index--) {
//          int ans = 0;
//          if(a[i_index] == b[j_index] ) {
//      ans = 0 + dp[i_index+1][j_index+1];
//          }
//          else {
//      int replace = 1 + dp[i_index+1] [j_index+1];
//          int insert = 1 + dp[i_index] [j_index+1];
//          int remove = 1 + dp[i_index+1] [j_index];
//          ans = min(insert, min(remove, replace));
//      }
//      dp[i_index] [j_index] = ans;
//          }
//      }
// return dp[0][0];
// }
    

//     int minDistance(string word1, string word2) {
//         int i=0;
//         int j=0;
//         int ans=solveUsingTabulation(word1,word2,i,j);
//         return ans;
//     }
// };

// //SO - req wala depend on next column same row ,next column next row , same column next row ....same common subseq jsa....req row ka on that row and next row
// class Solution {
// public:
// int solveUsingTabulationSO(string a, string b) {
// //1.
// vector<int> curr(b.length()+1, -1); // initially b.length se phle index wali row 
// vector<int> next(b.length()+1, -1); // initially b.length index wali row
// //2.
// // initial next ka ans pata hai....b.length()-j..insert krdete
//  for(int col=0; col<=b.length(); col++) { 
//      next[col] = b.length()-col;            
//   }
// // intitial curr ke last ka ans pata hai....a.length()-i...par dikkat h....har curr ke liye i is varyingg toh value is varying....and abhi saari row bani nhi toh dikkat h...baad m dekhege


// //3.
// for(int i_index=a.length()-1; i_index>=0; i_index--) {
//  // every row starts here   // curr ka last ka ans yaha insert krdete.....yaha sab chlra sahi....idhar se banta rhega har nye curr k last ka ans
//   curr[b.length()]=a.length()-i_index; 
// for(int j_index=b.length()-1; j_index>=0; j_index--) {
// int ans = 0;
// if(a[i_index] == b[j_index] ) {
// ans = 0 + next[j_index+1];
// }
// else {
// int replace = 1 + next[j_index+1];
// int insert = 1 + next[j_index];
// int remove = 1 + curr[j_index+1];
// ans = min(insert,min(remove, replace));
// }
// curr[j_index] = ans;
// }
// //shifting
// next = curr;
// }
// return next[0];
// }
//     int minDistance(string word1, string word2) {
//           int i=0;
//         int j=0;
//         int ans=solveUsingTabulationSO(word1,word2);
//          return ans;
//     }
// };



// NO MORE OPTIMISAIION POSSIBLE