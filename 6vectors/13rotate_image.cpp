// // lc 48

// class Solution
// {
// public:
//     void rotate(vector<vector<int>> &matrix)
//     {

//         // transpose
//         for (int i = 0; i < matrix.size(); i++)
//         {

//             for (int j = i; j < matrix[i].size(); j++)
//             {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         // reverse -> 2D MATTIX ki ssaari rows ko

//         for (int i = 0; i < matrix.size(); i++)
//         {
//             // hr row ko reverse krna h
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };

// // lets do by writing code for reversing also



// class Solution
// {
// public:
// void reverseRow(vector<int>& arr) {
// int n = arr.size();
// int start = 0;
// int end = n-1;
// while(start < end) {
// swap(arr[start], arr[end]);
// start++;
// end--;
// }
// }
//     void rotate(vector<vector<int>> &matrix)
//     {

//         // transpose
//         for (int i = 0; i < matrix.size(); i++)
//         {

//             for (int j = i; j < matrix[i].size(); j++)
//             {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         // reverse -> 2D MATTIX ki ssaari rows ko

//         for (int i = 0; i < matrix.size(); i++)
//         {
//             // hr row ko reverse krna h
//             reverseRow(matrix[i]);
//         }
//     }
// };



// o(n^2)