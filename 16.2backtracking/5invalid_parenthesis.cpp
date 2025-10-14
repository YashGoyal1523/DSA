

// lc301

// class Solution {
// public:
//     void solve(string& s, int index, int left, int right, int bal, string &output, unordered_set<string>& ans ) {  // mle aara tha isiliye string,ouput by ref leliye
//         //base case
//         if(index >= s.length()) {
//             //valid ans
//             if(left ==0 && right ==0 && bal == 0 ) {
//                 ans.insert(output);
//             } 
//             return;
//         }

       
//         if(s[index] !='(' && s[index] != ')') {
//             // letter case
//             output.push_back(s[index]);
//             solve(s,index+1, left, right, bal, output, ans);
//             output.pop_back(); // backtrack
//         }
//         else {
//             //bracket wala case 
//             // 2 cases: ( and )
//              // include/ exclude
//             if(s[index] =='(') {
//                 // include
//                 // removal-inc
//                 //remove 
//                 if(left > 0) {
//                     solve(s, index + 1, left-1, right, bal, output, ans);
//                 }
//                 //exclude 
//                 //removal-exc
//                 //no remove
//                 output.push_back(s[index]);
//                 solve(s, index+1, left, right, bal+1,output, ans );
//                 output.pop_back(); // backtrack
//             }
//              if(s[index] == ')') {
//                 //removal - include
//                 if(right > 0 ) {
//                     solve(s, index+1, left, right-1, bal, output, ans);
//                 }
//                 //removal - exclude
//                 //removal nahi karna , lekin usi case jab corresponding left  bracket available hai 
//                 if(bal > 0 ) { // available h
//                     output.push_back(s[index]);
//                     solve(s, index + 1, left, right, bal-1, output, ans);
//                     output.pop_back(); // backtrack
//                 }
//             }
//         }
//     }
//     vector<string> removeInvalidParentheses(string s) {
//         unordered_set<string> ans;
//         int invalidLeft = 0;
//         int invalidRight = 0;
 
//         for(auto ch: s ){
//             if(ch == '(') 
//                 invalidLeft++;
//             if(ch == ')') {
//                 if(invalidLeft > 0) {
//                     --invalidLeft;
//                 }
//                 else {
//                     invalidRight++;
//                 }
//             }
//         }
//         int index = 0;
//         int balance = 0;
//         string output = "";
//         solve(s,index,invalidLeft,invalidRight,balance,output,ans);

//         return vector<string>(ans.begin(), ans.end());
//     }
// };