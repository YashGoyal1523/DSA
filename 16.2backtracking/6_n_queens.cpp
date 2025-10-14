// // lc 51

//note:
//for all points in a left diagonal .... row_idx - col_idx is same
//for all points in a right diagonal .... row_idx + col_idx is same

// class Solution {
// public:

//     unordered_map<int,bool> rowCheck;
//     unordered_map<int,bool> leftDiagnolCheck;
//     unordered_map<int,bool> rightDiagnolCheck;

//     void storeSolution(vector<vector<char>> &board, int n, vector<vector<string> > &ans) {
//         vector<string> temp;
//         for(int i=0; i<n; i++) {
//             string output = "";
//             for(int j=0; j<n ;j++) {
//                 output.push_back(board[i][j]);
//             }
//             temp.push_back(output);
//         }
//         ans.push_back(temp);
//     }


//     bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
//  // col check ki no need, sirf row and dono diagonals m dekhna ki already queen h ya nhi 

//         if(rowCheck[row] == true )
//             return false;
            
//         if(leftDiagnolCheck[row-col] == true)
//             return false;
            
//         if(rightDiagnolCheck[row+col] == true)
//             return false;

//     // place is safe
//         return true;
// }


//     void solve(vector<vector<char>> &board, int col, int n, vector<vector<string> > &ans  ) {
//     //base case
//     if(col >= n) {
//         // saare column process hogyw h...yaani we have a soln to store
//         storeSolution(board, n, ans);
//         return ;
//     }

//     //main logic
//     //1 case solve karna h , baaki recursion sambhal lega
    
//     //iss column k hr row par queen place krke dekho
//     for(int row = 0; row <n; row++) {
//         if(isSafe(row, col, board, n)) {
//         //queen rakh do
//         board[row][col] = 'Q';
//         // mark in all three dir that q is placed here
//         rowCheck[row] = true;
//         leftDiagnolCheck[row-col] = true;
//         rightDiagnolCheck[row+col] = true;
            
//         //recursion solution laega
//         solve(board, col+1, n, ans); // agli col mein jao 
//         //backtracking
//         board[row][col] = '.';
//         rowCheck[row] = false;
//         leftDiagnolCheck[row-col] = false;
//         rightDiagnolCheck[row+col] = false;
//         }

//     }
// }


//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<char>> board(n, vector<char>(n,'.'));
//         vector<vector<string> > ans;
//         int col = 0; // col wise place krege queens ko //har col mein ek ek place krege
//         solve(board, col, n, ans);
//         return ans;
//     }
// };