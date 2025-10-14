// lc 14 longest common prefix

// m1 trie
// trie banalo sab strings ka
// root se traverse kro and jabtak single child wali nodes milti rhe unko ans m lete jao and  aage bhado ...jaha multi hojaye ya fir koi word khatm hojaye ruk jao ... 
// childcount variable m sabke child store krlo

// class TrieNode{
//   public:
//     char value;
//     TrieNode* children[26];
//     int childCount;
//     bool isTerminal; 
//     TrieNode(char val) {
//       this->value = val;
//       for(int i=0; i<26; i++) {
//         children[i] = NULL;
//       }
//       this->isTerminal = false;
//       this->childCount = 0;
//     }
// };

// class Solution {
// public:
//             //insertion
//         void insertWord(TrieNode* root, string word) {
//         //cout << "recieved word: " << word << " for insertion " << endl;
//         //base case
//         if(word.length() == 0) {
//             root->isTerminal = true;
//             return;
//         }

//         char ch = word[0];
//         int index = ch - 'a';
//         TrieNode* child;
//         if(root->children[index] != NULL) {
//             //present
//             child = root->children[index];
//         }
//         else {
//             //absent
//             child = new TrieNode(ch);
//             root->children[index] = child;
//             root->childCount++;
//         }

//         //recursion
//         insertWord(child, word.substr(1));

//         }


//     void findLCP( string& ans, TrieNode* root) {
//         //base case
//         if(root->isTerminal == true) {
//             return;
//         }

//         ///abhi main root node pr hu 
//         TrieNode* child;
//         if(root->childCount == 1) {
//             //child tk jao
//             for(int i=0; i<26; i++) {
//                 if(root->children[i] != NULL) {
//                     child = root->children[i];
//                 }
//             }
//             //ans me store karwao
//             ans.push_back(child->value);
//         }
//         else {
//             return;
//         }
//         //ab recursion ki baari 
//         findLCP(ans, child);
//     }
//     string longestCommonPrefix(vector<string>& strs) {
//         TrieNode* root = new TrieNode('-');
//         //insert all strings
//         for(auto str: strs) {
//             insertWord(root, str);
//         }
//         string ans = "";

//         findLCP( ans, root);
//         return ans;
//         }
// };


// m2 

// class Solution {
// public:
// string longestCommonPrefix(vector<string> &strs)
// {
//     string ans = "";
//     int i = 0;
//     while (true)
//     {
//         char curr_ch = 0;
//         for (auto str : strs)
//         {
//             if (i >= str.size())
//             { // out of bound
//                 curr_ch = 0;
//                 break;
//             }
            
//             if (curr_ch == 0)
//             { // just started
//                 curr_ch = str[i];
//             }
//             else if(str[i] != curr_ch)
//             { //char mismatch
//                 curr_ch = 0;
//                 break;
//             } // match case m kuch nhi krna aage check kro
//         }
//         if (curr_ch == 0)
//         {
//             break;
//         }
//         ans.push_back(curr_ch);
//         i++;
//     }
//     return ans;
// }
// };