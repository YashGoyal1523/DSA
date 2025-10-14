// yaha se sudoku tak bonus folder ke h

//lc 1079 Letter tile posssibilities

//note:
//ques type- total no of susbequences/subsets/permutations ----> backtraking ---> do - explore - undo



//bruteforce
//saare permutations ke saare subsequences mein se dekhlo
// -> har permutation uthao ..uske saare subsequences nikalo and ek set (to avoid duplicates) m store krte jao 


//mik 
//https://youtu.be/cD0D-QSKG20?si=GkrtzWKQuAdk6ktW 
//m1 

class Solution {
    public:
    int n;
    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr) { 
    result.insert(curr); 
    for(int i = 0; i < n; i++) { //always start from i = 0 
    if (used [i]) { 
    continue; 
    } 
    used[i] = true; 
    curr.push_back(tiles[i]); 
    solve(tiles, used, result, curr);
    used [i] = false; 
    curr.pop_back(); 
    }
    } 
    int numTilePossibilities(string tiles) { 
     n = tiles.length(); 
    vector<bool> used (n, false); 
    unordered_set<string> result; // to handle duplicates ...set mein store krlege
    string curr = ""; 
    solve(tiles, used, result, curr); 
    return result.size()-1; //exclude the empty sequence 
    }
    };


//m2

class Solution {
    public:
    int count; 
    void solve(vector<int>& vec) { 
    count++; //duplicate nhi aayege iss method m......set mein store krke krne ki need nhi.......hume count hi chahie...... seedha count variable hi rkhlo
    for(int i = 0; i < 26; i++) { //always start from i = 0 
    if (vec[i] == 0) { 
    continue; 
    }
    vec[i]--; //DO 
    solve (vec); //EXPLORE 
    vec[i]++; //UNDO 
    } 
    } 
    int numTilePossibilities (string tiles) { 
    count = 0; 
    vector<int> vec (26, 0); 
    for(char &ch: tiles) { 
    vec[ch-'A']++; 
    } 
    solve(vec); 
    return count-1; //exclude the empty sequence
    }
    };


//babbar (bonus folder mein h)

// class Solution {
// public:
//     int solve(vector<int>& freq) {
//         int ans = 0;
//         // har ek dabbe mein A-Z tk insert krne ka try krra hu
//         for(int i=0; i<26; i++) {
//             // check character exist ya nhi
//             if(freq[i] != 0) {
//                 // exist
//             // ek ans nikalgya
//                 ans++;
//             // freq update    
//                 freq[i]--;
//                 // baaki recursion
//                 int recursionKaAns= solve(freq);
//                 ans+=recursionKaAns ;
//                 // backtrack
//                 freq[i]++;
//             }
//         }
//         return ans;
//     }
//     int numTilePossibilities(string tiles) {
//         int n = tiles.length();

//         // count freq of characters
//         vector<int> freq(26,0);
//         for(auto ch: tiles) {
//             freq[ch-'A']++;
//         }

//         int ans= solve(freq);

//         return ans;
//     }
// };