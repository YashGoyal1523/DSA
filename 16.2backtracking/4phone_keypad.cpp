// // lc 17

// class Solution {
// public:
//     void solve(vector<string>& ans, string mapping[], string digits, int index,string output) {
//         //base case
//         if(index >= digits.length()) {
//             // output mein ans ban chuka hoga ...store
//             // empty wala nhi lena 
//             if(output.length() > 0){ 
//                 ans.push_back(output);
//             }
//             return;
//         }
//         string temp = mapping[digits[index] - '0'];
        
//         for(auto ch: temp) {
//             output.push_back(ch);
//             solve(ans,mapping,digits,index+1,output);
//             //backtrack
//             output.pop_back();
//         }

//     }
//     vector<string> letterCombinations(string digits) {
//         string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; // array of string // hash array //digit<->index: 0->empty,1->empty,2->abc,3->def,......9->wxyz
//          vector<string> ans;
//         int index = 0;
//         string output = "";
//         solve(ans, mapping, digits,index,output);
//         return ans;

        
//     }
// };