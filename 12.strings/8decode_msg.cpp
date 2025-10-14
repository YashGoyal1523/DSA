// leetcode ques 2325

// class Solution {
// public:
//     string decodeMessage(string key, string message) {
//         // phle map krlete keys
//         unordered_map<char,char>m;   // array m bhi kr skte mapping
//         char value='a';  // a se daalni shuru krni
//         for(int i=0;i<key.size();i++){
//             if(key[i]!=' ' && m[key[i]]=='\0'){   // yeh second condition uske liye lagadi ki kabhi ek letter phla aa chuka ho toh uska assign ho chuka ...ab dobara uska krdege toh uska change hoke galat hojayega...toh phle occurrence par hi assign ho isiliye and already assign krlia ho toh ignore
//             m[key[i]]=value;          
//             value++;                 // will map phla to 'a' ,dusra to 'b' ,teesra to 'c' and so on
//             }
//         }
//         // sab mapped h ...ab decode krte
//         string ans;
//         for(int i=0;i<message.size();i++){
//             if(message[i]==' ') ans.push_back(' ');
//             else ans.push_back(m[message[i]]);
//         }
//         return ans;
//     }
// };