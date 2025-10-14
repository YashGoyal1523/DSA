

//max product subbarray

// lc 152

//bruteforce : teen for loop

//thoda optimise : do for loop

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi=INT_MIN;
//        for(int i=0;i<nums.size();i++){
//         int product=1;
//         for(int j=i;j<nums.size();j++){
//             product*=nums[j];
//             maxi=max(product,maxi);
//         }
//        }
//         return maxi;
//     }
// };


// kadane algo 
// product lete jao .....max maintain krte jao....jaha zero banjaye vaha reset krdo ....
// ek baar left se shuru hoke aage jaana , ek baar right se shuru hoke piche aana...dono m se max lena
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi=INT_MIN;
//         int product=1;
//         //left to right
//         for(int i=0;i<nums.size();i++){
//             product*=nums[i];
//             maxi=max(product,maxi);
//             if(product==0) product=1;
//         }

//         product=1;

//         // right to left
//         for(int i=nums.size()-1;i>=0;i--){
//             product*=nums[i];
//             maxi=max(product,maxi);
//             if(product==0) product=1;
//         }

//         return maxi;
//     }
// };