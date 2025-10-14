// lc 1190

// Reverse Substrings Between Each Pair of Parentheses

// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

// ans link :  https://youtu.be/dUQRS4luBvA?si=rtCcXuQOFQLlIfaK

// method 1

// class Solution {
// public:
//     string reverseParentheses(string s) {
//         string ans="";
//         stack<int>st;  // stack is lifo // will store indexes of starting points of reversals in ans
//         int i=0;
//         int j=0;  //  point to indexes of starting points of reversals in ans
//         while(i<s.size()){
//             if(s[i]=='('){
//                 st.push(j);        // note j ka kaam ans.size() kr skta.....j maintain na krke ans.size() daalte jao
//                 i++;
//             }
//             else if(s[i]==')'){
//                 int l=st.top();
//                 reverse(ans.begin()+l,ans.end());
//                 i++;
//                 st.pop();
//             }
//             else {
//                 ans=ans+s[i];
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

// method 2

// wormhole teleportation technique

// class Solution
// {
// public:
//     string reverseParentheses(string s)
//     {
//         int n = s.length();
//         stack<int> st;       // will store indexes of openbrackets in s
//         vector<int> door(n); // will maintain indexes of entry exit points of brackets in s // map bhi bana skte

//         // brackets ka data banalete
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] == '(')
//             {
//                 st.push(i);
//             }
//             else if (s[i] == ')')
//             {
//                 int j = st.top();
//                 st.pop();
//                 door[i] = j; // i se j par jaa skte
//                 door[j] = i; // j se i par aa skte
//             }
//         }
//         string ans;
//         int flag = 1; // will help in changing direction of traversal
//         for (int i = 0; i < n; i = i + flag)
//         { // when flag=1 ->i=i+1 -> move forward , when flag = -1 ->i=i-1 -> move backward  // shuru mein forward se shuru krre
//             if (s[i] == '(' || s[i] == ')')
//             {
//                 i = door[i];
//                 flag = -flag; // changing the direction
//             }
//             else
//             {
//                 ans.push_back(s[i]);
//             }
//         }
//         return ans;
//     }
// };