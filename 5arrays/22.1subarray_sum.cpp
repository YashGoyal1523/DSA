// given array ...store  sum of contingous(atleast 1 element present) subarrays 


// m1 : teen for loop se  : o(n^3)

// void SubArraySum(vector<int>& nums,vector<int>&ans) {

//     int n = nums.size();

//     // Iterate over all possible starting points of subarray
//     for (int start = 0; start < n; ++start) {
//         // Iterate over all possible ending points of subarray
//         for (int end = start; end < n; ++end) {
//             int currentSum = 0;
//             // Calculate sum of subarray from index 'start' to 'end'
//             for (int k = start; k <= end; ++k) {
//                 currentSum += nums[k];
//             }
// //   push sum in array
//      ans.push_back(currentSum);
//             }
//         }
//     }

//     return;
// }



// m2 : thoda optimise :  o(n^2)

// void SubArraySum(vector<int>& nums,vector<int>&ans) {
//     int n = nums.size();
// for(int i=0 ; i<n ; i++)
//     {
//         int currentsum = 0 ;
//         for(int j=i ; j<n ; j++)
//         {
//             currentsum += nums[j] ;
//             ans.push_back(currentsum) ;
//         }
//     }
//     return;
// }

