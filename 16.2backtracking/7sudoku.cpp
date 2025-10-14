//lc 36,37

//phle lc 36 dekhte h...not of backtracking par....sudoku ques hi h

//lc 36

//tarika 1 
//checking safe by loops

class Solution {
public:

    bool safe(int row,int col,char value,vector<vector<char>>& board){
     // same row m voh number na ho
        // same col m voh number na ho 
        // same 3*3 m voh number na ho
        // toh safe h


        int n = board.size();

       
            //row check
             for(int i=0; i<n; i++) {
            if(i!=col&&board[row][i] == value)
                return false;
             }
            //col check
             for(int i=0; i<n; i++) {
            if(i!=row&&board[i][col] == value) 
                return false;
             }
            //3*3 box check
//              for(int i=0; i<n; i++) {
//   // x % y will give result from range [0,y-1] only.....0,1,2,,y-1,0,1,.... periodically  // x % 3 will give result from range [0,2] only....0,1,2,0,....periodically
//             int r = 3 * (row / 3) + i / 3;
//             int c = 3 * (col / 3) + i % 3;
//             if ((r!=row&&c!=col)&&board[r][c] == value)
//                 return false;
//             } 
        //}
            //or
        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                int r=start_i+k;
                int c=start_j+l;
                if ((r!=row&&c!=col)&&board[r][c] == value)
                return false;
            } 
         }
        
            

        // safe h
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool ans=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;

                char ch=board[i][j];
               
                if(!safe(i,j,ch,board)){//not safe
                    ans=false;
                    break;
                }    
            }
            if(ans==false) break;
        }
        return ans;
    }
};

//tarika 2
//checking safe by maps


class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>box(9,vector<int>(10,0));
        vector<vector<int>>row(9,vector<int>(10,0));
        vector<vector<int>>col(9,vector<int>(10,0));
        bool ans=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int no=board[i][j]-'0';
                int b=(i/3)*3+(j/3);//we have indexed the 3x3 sized boxes as
//  0 1 2
//  3 4 5
//  6 7 8    
                if(row[i][no]||col[j][no]||box[b][no]){ //not safe
                    ans=false;
                    break;
                }
                //safe h mark krdo 
                box[b][no]=1;
                row[i][no]=1;
                col[j][no]=1;
            }
            if(!ans) break;
        }
        return ans;
    }
};



// lc 37

//tarika 1
//using loops to check safe

class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        // same row m voh number na ho
        // same col m voh number na ho 
        // same 3*3 m voh number na ho
        // toh safe h


        int n = board.size();

       
            //row check
             for(int i=0; i<n; i++) {
            if(board[row][i] == value)
                return false;
             }
            //col check
             for(int i=0; i<n; i++) {
            if(board[i][col] == value) 
                return false;
             }
            //3*3 box check
//              for(int i=0; i<n; i++) {
//   // x % y will give result from range [0,y-1] only.....0,1,2,,y-1,0,1,.... periodically  // x % 3 will give result from range [0,2] only....0,1,2,0,....periodically
//             int r = 3 * (row / 3) + i / 3;
//             int c = 3 * (col / 3) + i % 3;
//             if (board[r][c] == value)
//                 return false;
//         }
    //or
        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                int r=start_i+k;
                int c=start_j+l;
                if (board[r][c] == value)
                return false;
            } 
         }
        // safe h
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //check for empty cell
                if(board[i][j] == '.') {
                    //try to fill with values ranging from 1 to 9
                    for(char val = '1'; val<='9'; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            //place
                            board[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSoln=solve(board);
                            if(remainingBoardSoln== true) {
                                return true;
                            }
                            else {
                                // recursion ans nhi laa paya 
                                // iska mtlb jo ch insert kiya voh galat tha
                                // dusra ch dekho
                                //backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution
                    //nahi nikla ,current cell pr, 
                    //that means piche kahin pr galti h , 
                    //go back returning false
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};



//tarika 2
//using map to check safe
class Solution {
public:

    vector<vector<int>> row = vector<vector<int>>(9, vector<int>(10, 0));
    vector<vector<int>> col = vector<vector<int>>(9, vector<int>(10, 0));
    vector<vector<int>> box = vector<vector<int>>(9, vector<int>(10, 0));//we have indexed the 3x3 sized boxes as
//  0 1 2
//  3 4 5
//  6 7 8    

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                //check for empty cell
                if (board[i][j] == '.') {
                    //try all values from 1 to 9
                    for (char val = '1'; val <= '9'; val++) {
                        int num = val - '0';
                        int b = (i / 3) * 3 + (j / 3); //index of 3*3 box
                        
                        //check if placing val is safe
                        if (!row[i][num] && !col[j][num] && !box[b][num]) {
                            //place val
                            board[i][j] = val;
                            row[i][num] = col[j][num] = box[b][num] = 1;

                            //recursion sambhal lega
                            bool remainingBoardSoln=solve(board);
                            if(remainingBoardSoln== true) {
                                return true;
                            }
                            else {
                            //recursion ans nahi laa paya
                            //iska matlab jo ch insert kiya voh galat tha
                            //dusra ch dekho
                            //backtrack
                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[b][num] = 0;
                            }
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution nahi nikla current cell par
                    //that means piche kahin par galti hai, go back returning false
                    return false;
                }
            }
        }
        //all cells filled
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //initialize row, col, box arrays from the given board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int b = (i / 3) * 3 + (j / 3); //index of 3*3 box
                    row[i][num] = col[j][num] = box[b][num] = 1;
                }
            }
        }

        solve(board);
    }
};