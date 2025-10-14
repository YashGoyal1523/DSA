//Knuth-Morris-Pratt (kmp) algo tells whether a given string is present in a string or not
// https://www.geeksforgeeks.org/problems/search-pattern0205/1

// https://youtu.be/qases-9gOpk?si=GWXU-oiuiuDiSveQ

// note: 
// lps of
// a ->0
// aaa ->2 (aa aa)
// aba ->1 (a a)
// abab ->2 (ab ab)


//T.C : O(m+n)
//S.C : O(m) where m is the length of pattern
class Solution
{
    public:
        // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
        void computeLPS(string pattern, vector<int>& lps) {
            int M = pattern.length();
            int len = 0; // Length of the previous longest prefix & suffix
        
            lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
        
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1]; //You can also write, len = len-1;
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        vector <int> search(string pat, string txt) {
            int N = txt.length();
            int M = pat.length();
            vector<int> result;
            
            // Create an LPS array to store the longest proper prefix which is also a suffix
            //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
            vector<int> lps(M, 0);
            computeLPS(pat, lps);
        
            int i = 0; // Index for text
            int j = 0; // Index for pattern
        
            while (i < N) {
                if (pat[j] == txt[i]) {
                    i++;
                    j++;
                }
        
                if (j == M) {
                    result.push_back(i-M); 
                    j = lps[j - 1];
                } else if (i < N && pat[j] != txt[i]) {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            
            return result;
        }
     
};


 //// lc 28

// bruteforce
// har index se dekho banra h ya nhi
// bruteforce
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size();
        int n = needle.size();

         int index=-1;
        for (int i = 0; i <= m - n; i++)    // haystack m last window of needle size ka starting  will be at m-n index  ...(m-1)-n+1 =m-n  // isse aage dekhne ki need hi nhi
        {
          
            int x=i;
            int y=0;
            while(haystack[x]==needle[y]){
                x++;
                y++;
                if(y==n){
                    index=i;
                    break;
                }
            }
            if(index!=-1) break;


          
        }
        return index;
    }
};


// optimal 

// kmp algo 

class Solution
{
public:
 void computeLPS(string pattern, vector<int>& lps) {
            int M = pattern.length();
            int len = 0; // Length of the previous longest prefix & suffix
        
            lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
        
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1]; //You can also write, len = len-1;
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        int search(string pat, string txt) {
            int N = txt.length();
            int M = pat.length();
           int result=-1;
            
            // Create an LPS array to store the longest proper prefix which is also a suffix
            //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
            vector<int> lps(M, 0);
            computeLPS(pat, lps);
        
            int i = 0; // Index for text
            int j = 0; // Index for pattern
        
            while (i < N) {
                if (pat[j] == txt[i]) {
                    i++;
                    j++;
                }
        
                if (j == M) {
                    result=(i-M); 
                    break;
                } else if (i < N && pat[j] != txt[i]) {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            
            return result;
        }
    int strStr(string haystack, string needle)
    {
        

    int index=search(needle,haystack);

    return index;
    }
};


// string ke baad ques folder m h
//  // learning/algos/kmp m h
// striver /79 / string m h



// lc 1408 

// // m1-bruteforce
// class Solution {
// public:
//     vector<string> stringMatching(vector<string>& words) {
//         vector<string>ans;
//         for(int i=0;i<words.size();i++){
//             for(int j=0;j<words.size();j++){
//                 if(i==j) continue;
//                 if(words[j].find(words[i])!=string::npos) {
//                     ans.push_back(words[i]);
//                     break; // taaki repeated na dale
//                 }
//             }
//         }

//         return ans;
//     }
// };

// m2- kmp algo
//https://youtu.be/BsR6ZVwxrvE?si=KtVntqrsjya0wcJ5



// m3 trie




// ques_prac/string/ learned mein h
// ques_prac/trie/leanred mein h
// learing/algos/kmp m h




//lc 1910. Remove All Occurrences of a Substring

// bruteforce
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//          while(s.find(part)!=string::npos){
//         s.erase(s.find(part),part.length());
//     }
//     return s;
//     }
// };

// // stack se bhi kr skte h


// // find,erase ki implementation dekhlena thoda ..tc vgarah dekhlena



// better
// stack


class Solution {
    public:
    
        bool check(stack<char>st,string part){
            int j=part.size()-1;
            while(j>=0){
                if(st.top()==part[j]){
                    st.pop();
                    j--;
                }
                else return false;
            }
    
            return true;
        }
    
    
        string removeOccurrences(string s, string part) {
             stack<char>st;
             for(int i=0;i<s.size();i++){
                st.push(s[i]);
                if(st.size()>=part.size()){
                    if(check(st,part)){ // check if part string dala hai
                        int m=part.size();
                        while(m--){
                            st.pop();
                        }
                    }
                }
             }
             string ans="";
             while(!st.empty()){
                ans+=st.top();
                st.pop();
             }
    
             reverse(ans.begin(),ans.end());
             return ans;
        }
    };



    //optimal
    //kmp algo


    // /string mein h
    // learning/algos/kmp m h
    // ques_prac/stack/learned m h 
    // ques_prac/string/learned m h 
   
    

// lc 686

//bruteforce1

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    string repeated = "";
    int count = 0;

    while (repeated.length() < b.length()) {
        repeated += a;
        count++;
    }

    if (repeated.find(b) != string::npos) return count;

    // Try one more repetition
    repeated += a;
    count++;

    if (repeated.find(b) != string::npos) return count;

    return -1;
    }
};


// bruteforce2

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int flag=0;
        int x,y;
        for(int i=0;i<a.size();i++){
            
                x=i;y=0;
                while(y<b.size()&&b[y]==a[x%n]){
                    y++;
                    x++;
                }
                if(y==b.size()){
                    flag=1;
                    break;
                }
            
        }
        if(flag) return ceil((double)x/n);
        else return -1;
    }
};

//optimal
// kmp


// /learning/algos/kmp m h
// /striver/a2z/string m h