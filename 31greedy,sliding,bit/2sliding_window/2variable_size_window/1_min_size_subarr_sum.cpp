// variable size window type
// // contigous subarrays problems 

// we use two pointer 
// initially at 0
// dono variably khisakte aage



// // general approach for ques of finding minimum size subarray satisfying given condition
// // expand minimise approach
// // from starting ,expand window till we find phla valid(condition fulfilling) subarray ie phla valid milte hi stop,fir from starting ,minimise the window by contracting jabtak valid cases milte rhege(ie valid cases ko minimise krte rho)...and stop when non valid subbarray found...once non valid found now again expand from previous expand ending point till phla valid case found ie phla valid found,again minimisme frm previous minimise ending point till non valid case found  , repeat till no more expand available ..... in sab valid wal m se min size wala uthalo

// // general approach for ques of finding maximum size subarray satisfying given condition
// // expand minimise approach
// // from starting ,expand window jabtak  valid(condition fulfilling) subarray milte rhe and unvalid milte hi stop,fir from starting ,minimise the window by contracting jabtak phla valid case na mile ie  stop once valid subbarray found..now again expand from previous expand ending point jabtak valid case milre and stop unvalid milte hi ,again minimisme frm previous minimise ending point till phla valid case found  , repeat till no more expand available ..... in sab valid wal m se max size wala uthalo



// // lc 209 - minimum size subarray sum


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {

//         int s = 0; // contract wala
//         int e = 0; // expand wala 

//         int len = INT_MAX;
//         int sum = 0;

//         while(e < nums.size()) {
//             //sum me include karo value
//             sum = sum + nums[e];
//             //ho skta hai, sum == target ho
//             //ho skta hai sum > target ho
//             //ho skta hai, sum < target

//             //minimise -> equal or greater
//             //expand -> lesser

//          if(sum>=target){
//             // valid case found
//                 //minimise krna hoga 
//             while(sum >= target) {     // minimise krte jabtak valid cases mile
//          // minimise se phle length sambhal lete as valid case h
//             //current ki length 
//              int currlen=e-s+1;
//                //ans length 
//                 len = min(len , currlen);   // or if(currlen<len){len=currlen;}
//               // ab minimise krte
//                 //current element, pointed by start, should be removed from sum 
//                 sum = sum - nums[s];
//                 s++;
//             }
//            }
//             // yaha h iska matalb unvalid case hai ie guarantee -> sum < target   
//             //expand
//                 e++;
//         }
//         if(len == INT_MAX) {
//             return 0;
//         }
//         else {
//             return len;
//         }
        
//     }
// };

