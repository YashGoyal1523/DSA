// lc 1380

// m1 bruteforce
// har element par jaake check krna...ki kya voh apni row ka min and col ka max h ya nhi

// class Solution
// {
// public:
//     vector<int> luckyNumbers(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size(), m = matrix[0].size();
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                int mini = INT_MAX, maxi = INT_MIN;
//                 for (int k = 0; k < m; k++)
//                 {
//                     mini = min(mini, matrix[i][k]);
//                 }
//                 for (int k = 0; k < n; k++)
//                 {
//                     maxi = max(maxi, matrix[k][j]);
//                 }
//                 if (matrix[i][j] == mini && matrix[i][j] == maxi)
//                 {
//                     ans.push_back(matrix[i][j]);
//                 }
//             }
//         }
//             return ans;
//         }
//     };

    // optimised m1
    // Find out and save the minimum of each row and maximum of each column in two lists
    // Then scan through the whole matrix to identify the elements that satisfy the criteria.

    // class Solution {
    // public:
    //     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    //         int m=matrix.size();
    //         int n=matrix[0].size();
    //         vector<int>max(n,-1);
    //         vector<int>min(m,-1);

    //       for(int i=0;i<m;i++){
    //         int mini=INT_MAX;
    //         for(int j=0;j<n;j++){
    //             if(matrix[i][j]<mini){
    //                 mini=matrix[i][j];
    //             }                                   // ya seedha mini=min(mini,matrix[i][j]) leletee

    //         }
    //          min[i]=mini;                     
    //       }
    //        for(int i=0;i<n;i++){
    //         int maxi=INT_MIN;
    //         for(int j=0;j<m;j++){
    //             if(matrix[j][i]>maxi){
    //                 maxi=matrix[j][i];
    //             }

    //         }
    //          max[i]=maxi;
    //       }

    //     vector<int>ans;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(matrix[i][j]==max[j]&&matrix[i][j]==min[i]){
    //                 ans.push_back(matrix[i][j]);
    //             }

    //         }
    //       }

    // return ans;
    //       }
    // };

    // m2
    // row ka min element dhundho fir check kroo kya voh uski col ka max bhi h ..if yes then push else chodho
    // move to next row and repeat
    // har row m krte jao ese

    // class Solution {
    // public:
    //     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    //         int m=matrix.size();
    //         int n=matrix[0].size();
    //         vector<int>ans;
    //         for(int i=0;i<m;i++){
    //          //   row ka min nikalte
    //             int mini=INT_MAX;
    //             int mincol=-1;  // min element ka col index store k liye
    //             for(int j=0;j<n;j++){
    //                 if(matrix[i][j]<mini){
    //                     mini=matrix[i][j];
    //                     mincol=j;
    //                 }
    //             }
    //             // min element milgya
    //             // uske column mein check krte ab ki kya voh usme max bhi h
    //             int maxi=INT_MIN;
    //             for(int k=0;k<m;k++){
    //                 if(matrix[k][mincol]>maxi){
    //                     maxi=matrix[k][mincol];
    //                 }
    //             }
    //             if(mini==maxi) ans.push_back(mini);

    //         }
    //         return ans;
    //     }
    // };