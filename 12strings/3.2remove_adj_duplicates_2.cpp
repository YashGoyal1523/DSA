// lc 1209   Remove All Adjacent Duplicates In String 2                       // lakshay bhaiya 

// m1 : using string
// same pichle ques ke m1  jsa bas thoda difference which is
// s ke curr char ke liye ans ke last k-1 element dekho

// class Solution
// {
// public:
//     bool areLastKMinus1CharsSame(string &ans, char &ch, int k_1)  // by ref kre as mle aara tha
//     {
//         int it = ans.size() - 1;
//         for (int i = 1; i <= k_1; ++i)
//         {
//             if (ch != ans[it])
//                 return false;
//             it--;
//         }
//         return true;
//     }
//     string removeDuplicates(string s, int k)
//     {
//         string ans;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             char ch = s[i];
//             if (ans.size() >= k - 1 && areLastKMinus1CharsSame(ans, ch, k - 1))
//             {
//                 for (int j = 1; j <= k - 1; ++j)
//                     ans.pop_back();
//             }
//             else
//             {
//                 ans.push_back(ch);
//             }
//         }
//         return ans;
//     }
// };

// m2 : using stack

// class Solution
// {
// public:
//     string removeDuplicates(string s, int k)
//     {
//         stack<pair<char, int>> st; // <char,char freq>
//         for (int i = 0; i < s.size(); ++i)
//         {
//             char ch = s[i];
//             if (!st.empty() && st.top().first == ch)
//             {
//                 pair<char, int> temp = st.top();
//                 if (temp.second == k - 1)
//                 {
//                     st.pop();
//                 }
//                 else
//                 { // temp.second < k - 1
//                     st.pop();
//                     st.push({temp.first, temp.second + 1});
//                 }
//             }
//             else
//             {
//                 st.push({ch, 1});
//             }
//         }
//         string ans;
//         while (!st.empty())
//         {
//             while (st.top().second--)
//                 ans += st.top().first;
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// m3 : two pointer

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         int i = 0, j = 0;
//         vector<int> count(s.size());
//         while (j < s.size()) {
//             s[i] = s[j];
//             count[i] = 1;
//             if (i > 0 && s[i] == s[i - 1]){
//                 count[i] += count[i - 1];
//             }
//             if (count[i] == k){
//                 i -= k;
//             }
//             ++i, ++j;
//         }
//         return s.substr(0, i);
//     }
// };