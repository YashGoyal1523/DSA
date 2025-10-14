// lc 5

// bruteforce- saare substring nikalke ,palindrome check krke, longest wala lena
// o(n^3)

// class Solution {
// public:
//     bool isPalindrome(string& s, int start, int end) {
//         while (start < end) {
//             if (s[start] != s[end]) {
//                 return false;
//             }
//             start++, end--;
//         }
//             return true;
//         }
//         string longestPalindrome(string s) {
//             string ans = "";
//             for (int i = 0; i < s.size(); i++) {
//                 for (int j = i; j < s.size(); j++) {
//                     if (isPalindrome(s, i, j)) {
//                         string t = s.substr(i, j -i + 1);
//                         ans = t.size() > ans.size() ? t : ans;
//                     }
//                 }
//             }
//             return ans;
//         }
//     };


// better
// optimised : expand approach by using twopointer

//way1

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         string ans = "";
//         int maxlength = INT_MIN;

//      // odd length substring
//             for (int i = 0; i < s.size(); i++)
//             {
//                 int currlength = 0; 
//                 int j = i; 
//                 int k = i;
//                 while (j >= 0 && k < s.size() && s[j] == s[k])
//                 {
//                     currlength=k-j+1;
//                     j--;
//                     k++;
//                 }
//                 if (currlength > maxlength)
//                 {
//                     maxlength = currlength;
//                     ans = s.substr(j + 1, currlength);
//                 }
//             }
        
//         // even length substring
//             for(int i = 0; i < s.size() - 1; i += 1)
//             {     
//                     int currlength = 0;
//                     int j = i;
//                     int k = i+1;
//                     while (j >= 0 && k < s.size() && s[j] == s[k])
//                     {
//                         currlength=k-j+1;
//                         j--;
//                         k++;
//                     }
//                     if(currlength > maxlength)
//                     {
//                         maxlength = currlength;
//                         ans = s.substr(j + 1, currlength);
//                     }
//                 }
               
            
        
//         return ans;
//     }
// };


//way2

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         string ans = "";
//         int maxlength = INT_MIN;

//      // odd length substring
//             for (int i = 0; i < s.size(); i++)
//             {
//                 int currlength = 1; // centre wale ko leliya
//                 // aage piche dekhege ab
//                 int j = i - 1; 
//                 int k = i + 1;
//                 while (j >= 0 && k < s.size() && s[j] == s[k])
//                 {
//                     currlength += 2;
//                     j--;
//                     k++;
//                 }
//                 if (currlength > maxlength)
//                 {
//                     maxlength = currlength;
//                     ans = s.substr(j + 1, currlength);
//                 }
//             }
        
//         // even length substring
//             for(int i = 0; i < s.size() - 1; i += 1)
//             {     
//                 // centre walo se dekhna shuru kro
//                     int currlength = 0;
//                     int j = i;
//                     int k = i+1;
//                     while (j >= 0 && k < s.size() && s[j] == s[k])
//                     {
//                         currlength += 2;
//                         j--;
//                         k++;
//                     }
//                     if(currlength > maxlength)
//                     {
//                         maxlength = currlength;
//                         ans = s.substr(j + 1, currlength);
//                     }
//                 }
                    
//         return ans;
//     }
// };