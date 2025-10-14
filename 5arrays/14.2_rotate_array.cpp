// lc 189 




// m1 : normally k baar shift  har element ko 

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
        
//               while(k>=1){
//             int last=nums[n-1];
//             int i=n-1;
//             while(i>=1){
//                 nums[i]=nums[i-1];
//                 i--;
//             }
//             nums[0]=last;
//             k--;
//         }
        
//         return ;
//     }
// };

// TLE DEGA


// note: ISKO THODA OPTIMISE KAR SKTE HAI
// note : n shift ke baad toh same hi banjayega... 
// toh k>=n case k liye thoda change kr skte h

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         if(k==n) {        // n baar shift ke baad toh same hi banega
//             return ;
//         }
//         else{  // k>n ya k<n case
// //        note:  as n shift ke baad same banjata h toh if k>n toh hume uper ka remainder times shift krna h bas as har n shift ke baad toh same hi banjayega .....  k<n mein toh k baar hi hoga no alterations
//             int x=k%n;  // % gives remainder  // will give uper ka remainder in k>n and k in k<n  // dono sambhal jaayge // k>n optimise hogya
//               while(x>=1){
//             int last=nums[n-1];
//             int i=n-1;
//             while(i>=1){
//                 nums[i]=nums[i-1];
//                 i--;
//             }
//             nums[0]=last;
//             x--;
//         }
//         }
//         return ;
//     }
// };

// WILL GIVE TLE



// m2 :  x index wala rotate ke baad (x+k)%n index par chala jaayega

// class Solution {
// public:
// void rotate(vector<int>& nums, int k) {
// int n = nums.size();
// vector<int> ans(n);
// for(int index=0; index<n; index++) {
// int newIndex = (index + k ) % n;
// ans[newIndex] = nums[index];
// }
// nums = ans;
// }
// };


// m3: last k store krkr

// class Solution {
// public:
// void rotate(vector<int>& nums, int k) {
    
//     int n=nums.size();
//     k=k%n;
// vector<int>temp;

// for(int i=(n-1)-k+1;i<n;i++){
//     temp.push_back(nums[i]);
    
// }
// for(int i=n-1;i>=k;i--){
//     nums[i]=nums[i-k];
// }
// for(int i=0;i<k;i++){
//     nums[i]=temp[i];

// }
// }
// };

// // note iska space optimise wala tle dega
