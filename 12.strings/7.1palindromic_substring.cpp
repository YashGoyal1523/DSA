// substring: all possible adjacent character combinations , subsequence : all possible character combinations
// eg for abc  -> substring: a,b,c,ab,bc and subsequence : a,b,c,ab,,bc,ac

// lc 647

// m1 :bruteforce- saare substring nikalke check krna and count krna : o(n^3)

// m2:optimised method : Expand aproach : centre ke around expand kr krke (using two pointers) check krna 

// class Solution
// {
// public:
//     int expand(string s, int i, int j)
//     {
//         int count = 0;
//         while (i >= 0 && j < s.length() && s[i] == s[j])
//         {
//             count++;
//             i--;
//             j++;
//         }
//         return count;
//     }
//     int countSubstrings(string s)
//     {
//         int totalCount = 0;
//         for (int center = 0; center < s.length(); center++)
//         {
//             // ODD length substring
//             int oddKaAns = expand(s, center, center);
//             // EVEN length substring
//             int evenKaAns = expand(s, center, center + 1);
//             totalCount = totalCount + oddKaAns + evenKaAns;
//         }
//         return totalCount;
//     }
// };