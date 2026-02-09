//Stringstream

//https://www.geeksforgeeks.org/stringstream-c-applications/


// Count no of words in a sentence
#include<iostream>
#include<sstream>
using namespace std ;
int main()
{
    string sentence="hi my name is yash";
    int count=0;

    // Breaking input into word 
    // using string stream

    stringstream s(sentence); // Used for breaking words
  
    string word;     // To store individual words

     while (s >> word){  // traverse on words 
        cout<<word<<" ";
        count++;
     }

     cout<<count;
 
return 0;
}



// // lc 1455

// //m1
// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         int n=sentence.size();
//         int m=searchWord.size();
//         int pos=1;
//         int i=0;
//         int j=0;
//         int flag=1; // 1-indicate word ki starting se check hora , 0- starting se check nhi hora
//         while(i<n&&j<m){
//             if(sentence[i]==' '){
//                 pos++;
//                 i++;
//                 j=0;
//                 flag=1;

//             }
//            else if(flag==1&&sentence[i]==searchWord[j]){
//                 i++;
//                 j++;
//             }
//             else {
//                 i++;
//                 flag=0;
//             }
//         }
//         if(j==m) return pos;

//         return -1;
//     }
// };

// //m2 using stringstream

// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         stringstream ss(sentence);
//         string word;
//         int index = 1; // 1-indexed position

//         while (ss >> word) {
//             if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
//                 return index;
//             }
//             index++;
//         }
//         return -1; // No match found
//     }
// };


// // lc 884

// // class Solution {
// // public:
// //     vector<string> uncommonFromSentences(string s1, string s2) {
// //         unordered_map<string,int>m;

// //         stringstream s(s1),ss(s2);
// //         string word;

// //         while(s>>word){
// //             m[word]++;
// //         }

// //         while(ss>>word){
// //             m[word]++;
// //         }

// //         vector<string>ans;

// //     for(auto i:m)
// //    {
// //     if(i.second==1) ans.push_back(i.first);
// //      }
// // return ans;
// //     }
// // };


//lc 151

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string result = "";
  
        while(ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length()-1);
    }
};