// lc 890

//we will normalise all the words and pattern into a similar format and then compare them
//string ke phle distinct character ko a , dusre ko b , teesre ko c and so on ese ese leke modify krlege pattern and words ko .... jo word.. pattern ke same bangya voh ans h

// class Solution {
// public:
// //this function normalises all the words and pattern into a similar format
// //so that we can compare them and find the solution
//     void modify(string& str) {
        
//         char value = 'a';
//         char mapping[300] = {0};

//         for(auto ch: str) {
//             if(mapping[ch] == 0) {  // already mapped h toh aage bhadna and nhi h toh banao
//                 mapping[ch] = value;
//                 value++;
//             }
//         }

//         //update the string
//         for(int i=0; i<str.length(); i++) {
//             char ch = str[i];
//             str[i] = mapping[ch];
//         }
//     }
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         vector<string> ans;

//         //firstly normalise the pattern
//         modify(pattern);

//         //saare words ek ek krke lete h 
//         for(string s: words) {
//             string tempString = s;         
//             //normalise tempString
//             modify(tempString);
//             if(tempString == pattern) {
//                 //it means, that "s" wali string was a valid answer
//                 ans.push_back(s);
//             }
//         }
//     return ans;
        
//     }
// };