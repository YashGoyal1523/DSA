// to check palindrome in string datatype

// m1 - new string me reverse daalo iska...fir compare kro...
// m2 - two pointer


// lc 680

// class Solution {
// public:
    

//  bool checkPalindrome(string s, int i, int j) {   // two pointer
//         while( i<= j) {
//             if(s[i] != s[j] ) {
//                 return false;
//             }
//             else {
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }

//     bool validPalindrome(string s) {
//         int i = 0;
//         int j = s.length() - 1;

//         while( i <= j) {
//             if(s[i] == s[j]) {
//                 i++;
//                 j--;
//             }
//             else{
//                 //s[i]!=s[j]
//                 //1 removal allowed
//                 //check palindrome for remaining string after removal

//                 //ith character -> remove
//                 bool ans1 = checkPalindrome(s, i+1, j);
//                 //jth character -> remove
//                 bool ans2 = checkPalindrome(s, i, j-1);

//                 return ans1 || ans2;       // logic gate wala or
//             }
//         }
//         //agar yha tk pohoche ho
//         //iska matlab valid palindrome hai
//         //iska matlab -> 0 removal
//         return true;
//     }
// };


// tc o(n)