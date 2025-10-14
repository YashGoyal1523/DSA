// lc 213 house robber 2

 // max sum of non-adjacent elements in circle

 // method-
 // note phle house m krli toh  last m nhi kar skta and last m krli toh phle m nhi kr skta
// do case banalo : last m nhi krre : last wala ignore krke baaki me normal include exclude lagalo and uska ans nikalo
//                : first m nhi krre : first wale ko ignore krke baaki me normal include exclude lagalo and uska ans nikalo
// dono mein se zyada wala lelo




// class Solution {
// public:
//     int solve(vector<int>& nums, int index,int e) {
//         //base case
//         if(index >e ) {
//             return 0;
//         }

//         //chori karlo -> ith index pr
//         int include = nums[index] + solve(nums, index+2,e);

//         //chori mat karo  -> ith index pr
//         int exclude = 0 + solve(nums,  index+1,e);

//         int finalAns = max(include, exclude);

//         return finalAns;
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();

//      if(n==1){  // single element case handle nhi hopayegi idhar ...alag se smbhaliya
//      return nums[0];        
//     }
// //     last m nhi krre
//         int case1 = solve(nums,0,n-2);
// //     phla m nhi krre
//         int case2 = solve(nums,1,n-1);
//       int ans=max(case1,case2);

//         return ans;

        
//     }
// };


// tle dega dp lagani degi