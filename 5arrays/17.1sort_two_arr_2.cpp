//lc 88
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 
// m1 - nums2 wale elements ko nums1 mein aage lagado fir pura sort krdo

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int j=0;
//         for(int i=m;i<m+n;i++){
//             nums1[i]=nums2[j];
//             j++;
//         }
//         sort(nums1.begin(),nums1.end());
//     }
// };


//m2 two pointer

//using extra space

// tesra vector banalo 
// dono array ke start mein pointer rkhdo
// dono mein se chota uthake dalate jao teesre mein
//nums1 mein daaldo ans vector

//without using extra space

// phla array given hai n+m size ka ...usi m kr skte seedha

// normal two pointer method  se ulta krege....isme piche se traverse krege and bada daalege ans arr ke piche se hi and piche se aage travserse krege

// //We can start with two pointers i and j, initialized to m-1 and n-1, in arr nums1 and nums2 resp. We will also have another pointer k initialized to m+n-1 in nums1, which will be used to keep track of the position in nums1 where we will be placing the larger element. Then we can start iterating from the end of the arrays i and j, and compare the elements at these positions. We will place the larger element in nums1 at position k, and decrement the corresponding pointer i or j accordingly. agar dono ek saath khatm toh all good...agar nums1 phle khatm fir nums 2 as it is daalte rho....agar nums2 phle khatm toh bas rukjao as nums1 bacha hua h and voh toh phle se hi shi order m h...
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;
//         int j = n - 1;
//         int k = m + n - 1;
        
//         while (j >= 0) {  // nums2 khatm hone tak chalare  
//             if (i >= 0 && nums1[i] > nums2[j]) {  // yeh i wali will handle nums1 ka phle khatm hona  i>=0 satisfied means nums1 kjhatm nhi hua abhi
//                 nums1[k--] = nums1[i--];
//             } else {
//                 nums1[k--] = nums2[j--];
//             }                                             // iss logic se teeno case chaljayega.....agar equal h toh bhi nums2 khatm tak chalra toh chaljayega...nums2 phle khatm hora toh bhi nums2 tak hclra yeh and aage kuch nhi krna toh chaljayega...nums1 phle khatm par i>=0 wali sambhalri and else chalke nums2 dalta jaayega toh chal gyaa...
//         }
//     }
// };