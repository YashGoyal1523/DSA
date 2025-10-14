// lc 221 maximal square
//https://youtu.be/MMr19RE7KYY?si=d9ILOuGmLOz_nkyi
// rec
class Solution {
public: 
    int solve(vector<vector<char> >& matrix, int i, int j, int row, int col) {
        //base case
        if(i >= row || j>= col) {
            return 0;
        }


        if(matrix[i][j]=='0') return 0;  // 0 pe h toh cant build
        else{
        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col);
        int diagnol = solve(matrix, i+1, j+1, row, col);
        int down = solve(matrix, i+1, j, row, col);

         int ans = 1 + min(right, min(down, diagnol));

         return ans;
        }
            
        
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 int ans = solve(matrix, i, j, row, col);
                 maxi=max(maxi,ans);
            }
        }
       
        return maxi*maxi;
    }
};
//mem
class Solution {
public: 
    int solve(vector<vector<char> >& matrix, int i, int j, int row, int col,vector<vector<int>>&dp) {
        //base case
        if(i >= row || j>= col) {
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];

        int ans;
        if(matrix[i][j]=='0') ans=0;  // 0 pe h toh cant build
    else{
        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col,dp);
        int diagnol = solve(matrix, i+1, j+1, row, col,dp);
        int down = solve(matrix, i+1, j, row, col,dp);

        ans = 1 + min(right, min(down, diagnol));;
    }
            return dp[i][j]=ans;
        
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 int ans = solve(matrix, i, j, row, col,dp);
                 maxi=max(maxi,ans);
            }
        }
       
        return maxi*maxi;
    }
};
//tabu
//note har starting k liye pura tabu chalana is redundant
//as yeh for loops chalege for a starting i,j
//      for(int x=m-1;x>=i;x--){
//         for(int y=n-1;y>=j;y--){   
// starting i,j se bottom right dp fill hogi
//ek baar tabulate krdo from starting as 0,0..... puri dp array fill hojayegi....har index par uska ans fill hojayega....
// sabme se max lelo
class Solution {
public: 
  
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
              int ans;
        if(matrix[i][j]=='0') ans=0;  // 0 pe h toh cant build
    else{
        //explore all 3 directions
        int right = dp[i][j+1];
        int diagnol = dp[i+1][j+1];
        int down = dp[i+1][j];

        ans = 1 + min(right, min(down, diagnol));;
    }
    dp[i][j]=ans;
            }
        }
       
int maxi=0;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        maxi=max(maxi,dp[i][j]);
    }
}


        return maxi*maxi;
    }
};