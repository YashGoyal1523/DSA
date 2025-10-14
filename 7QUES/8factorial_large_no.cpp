// factorial of a large no

// gfg - https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// chote no. ka toh factorial int m store krwa skte par bade no ka factorial out of bound jaayega toh normal method se nhi kr paayege (long long vagarah  se bhi dukhi hojayege)

// hume ans ko array m store krwana pdega


// class Solution
// {
// public:
//     vector<int> factorial(int N)
//     {
//         vector<int> ans;
//         ans.push_back(1);
//         int carry = 0;
//         for (int i = 2; i <= N; i++)
//         {
//             for (int j = 0; j < ans.size(); j++)
//             {
//                 int x = ans[j] * i + carry;
//                 ans[j] = x % 10;
//                 carry = x / 10;
//             }
//             while(carry != 0)  {         // last wala carry .... digitwise        
//                     ans.push_back(carry%10);
//                     carry/= 10;
//             }
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };