// // gfg 

// Common in three sorted array

// https://www.geeksforgeeks.org/problems/common-elements1132/1

// You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// If there are no such elements return an empty array. In this case, the output will be -1.

// Note: can you handle the duplicates without using any additional Data Structure?

// Examples :

// Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
// Output: [20, 80]
// Explanation: 20 and 80 are the only common elements in arr, brr and crr.
// Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
// Output: [-1]
// Explanation: There are no common elements in arr, brr and crr.
// Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: We do not need to consider duplicates





// //  handling duplicates with extra data structure


//m1 set datastructure stores only unique elements
// phle set m daal lege common elements ...last m set se ans array m daaldege

// class Solution {
//   public:
   
//     vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
//                                vector<int> &arr3) {
//           vector<int> ans;
//         set<int> st;
//         int i, j, k;
//         i = j = k = 0;
//         while (i < arr1.size() && j < arr2.size() && k < arr3.size())
//         {
//             if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
//             {
//                 st.insert(arr1[i]);
//                 i++, j++, k++;
//             }
//             else if (arr1[i] < arr2[j])
//             {
//                 i++;
//             }
//             else if (arr2[j] < arr3[k])
//             {
//                 j++;
//             }
//             else
//             {
//                 k++;
//             }
//         }
//         for (auto i : st)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };


//m2 : phle ans vector mein daalege saare common elements  fir usme se remove duplicates krdege 
// remove duplicates ese krdege  (refer to arrays folder 19)
// void remove(vector<int>&nums){     // by reference
    
//     vector<int>temp;  // isme ans array banayege baad mein original mein copy krdege isko
    
//     sort(nums.begin(),nums.end());  //  array ko sort krdo

//     temp.push_back(nums[0]);  // phla element toh daaldo temp mein
//     // ab baakio ke liye uske piche wale se dekhte hue chalo // if piche wale ke equal nahi h toh temp mein daldo vrna aage bhado
//     for(int i=1;i<nums.size();i++){
//             if(nums[i]!=nums[i-1]){  
//                 temp.push_back(nums[i]);
//             }
//     }
//     nums=temp;

//     return;
// }


// //  handling duplicates without extra data structure

// m1: remove duplicates inplace wali krdege (refer to arrays folder 19)


// m2 :


// vector<int> commonElements(int A[], int B[], int C[],              // n1 n2 n3 are sizes
//                            int n1, int n2, int n3)
// {
//     // Initialize starting indexes for A[], B[] and C[]
//     int i = 0, j = 0, k = 0;

//     vector<int> common;

//     // Iterate through three arrays while all arrays have
//     // elements
//     while (i < n1 && j < n2 && k < n3) {
//         // If A[i] = B[j] = C[k], push A[i] to common
//         // elements
//         if (A[i] == B[j] && B[j] == C[k]) {
//             common.push_back(A[i]);
//             i++;
//             j++;
//             k++;
//             // Skip duplicate elements in A[]
//             while (i < n1 && A[i] == A[i - 1])
//                 i++;

//             // Skip duplicate elements in B[]
//             while (j < n2 && B[j] == B[j - 1])
//                 j++;

//             // Skip duplicate elements in C[]
//             while (k < n3 && C[k] == C[k - 1])
//                 k++;
//         }

//         // If A[i] < B[j], then ith element cannot be common
//         else if (A[i] < B[j])
//             i++;

//         // If B[j] < C[k], then jth element cannot be common
//         else if (B[j] < C[k])
//             j++;
//         // If C[k] is smallest, then kth element cannot be
//         // common
//         else
//             k++;
//     }

//     return common;
// }