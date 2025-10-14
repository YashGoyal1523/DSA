// lc 2643

// class Solution {
// public:
//     vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//         int ansCount=INT_MIN;  // will store max no of 1 
//         int ansIdx=-1;   // will store max no of 1 wali row ka idx
//         for(int i=0;i<mat.size();i++){
//             int count=0;
//             for(int j=0;j<mat[0].size();j++){
//                 if(mat[i][j]==1){
//                     count++;
//                 }
//             }
// //   row complete , now check
//             if(count>ansCount){          // note agar hume sirf max no of 1 batane hote and idx noi toh yaha ansCount=max(ansCount,count) krke kaam chaljata par hame idx bhi maintain krna h toh yeh if wala krke hi krna pdega ie check hi krna pdega ki bada h konsa 
//                 ansCount=count;
//                 ansIdx=i;
//             }
//         }
//         return {ansIdx,ansCount};
//     }
// };