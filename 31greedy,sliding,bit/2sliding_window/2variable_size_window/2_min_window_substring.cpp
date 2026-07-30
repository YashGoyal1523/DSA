//m1
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // invalid case
//         int len1 = s.length();
//         int len2 = t.length();

//         if (len1 < len2) {
//             return "";
//         }
//         // valid case
//         int ansIndex = -1;
//         int ansLen = INT_MAX;

//         unordered_map<char, int> sMap;
//         unordered_map<char, int> tMap;
//         // store freq of pattern string
//         for (char ch : t) {
//             tMap[ch]++;
//         }
//         // initialise count variable, that basically shows count of actual
//         // pattern wale string k character presrnt in the current window
//         int count = 0;
//         int e = 0;
//         int st = 0;
//         while (e < s.length()) {
//             char ch = s[e];
//             // update freq in sMap
//             sMap[ch]++;
//             if (sMap[ch] <=
//                 tMap[ch]) // window ka char agar required string m present h toh
//                           // count krlo par note required amount se zyada h toh
//                           // ignore kro
//             {
//                 // valid character
//                 count++;
//             }

//             if (count == len2) {
//                 // window found, jisme poora pattern exist krta h
//                 //-> minimise
//                 // thoda alag minimisation h .....voh wala nhi hora ki minimise
//                 // till valid cases milre..fir unvalid ar rukre. hum yaha sirf
//                 // usi case me karenga, jis case me st index pr jo character
//                 // present h, vop ya toh required but extra hai ya aisa
//                 // character ho jo pattern k andar hi nahi h ......(note iss
//                 // minimisation mein voh wala nhi hora ki minimise till valid
//                 // cases milre..fir unvalid ar rukre...alag system h isme
//                 // .....isme hum valid mein se unwanted elements ko remove krre
//                 // and after minimising we are left with valid case only)
//                 while (sMap[s[st]] > tMap[s[st]] || tMap[s[st]] == 0) {
//                     if (sMap[s[st]] > tMap[s[st]]) {
//                         sMap[s[st]]--;
//                     }
//                     st++;
//                 }
//                 // answer nikalo
//                 int windowLength = e - st + 1;
//                 if (windowLength < ansLen) {
//                     ansLen = windowLength;
//                     ansIndex = st;
//                 }
//             }
//             e++;
//         }

//         if (ansIndex == -1) {
//             return "";
//         } else {
//             return s.substr(ansIndex, ansLen);
//         }
//     }
// };


//m2 mik
// https://youtu.be/3Bp3OVD1EGc?si=rLIbkpCRq-9JV2Kl
//T.C : O(m+n) where m = length of s and n = length of t
//S.C : O(n)

//normal expand minimise 
//valid tak expand ... try to minimise jab tak valid milta rhe.. unvalid milne par fir expand and so on
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        
        for(char &ch : t) {
            mp[ch]++;
        }
        
        int requiredCount = t.length();
        int i = 0, j  = 0;
        int minStart  = 0;
        int minWindow = INT_MAX;
        while(j < n) {
            char ch_j = s[j];
            if(mp[ch_j] > 0)
                requiredCount--;
            
            mp[ch_j]--;
            
   //         if(requiredCount==0){ // valid mila
            while(requiredCount == 0) { //try to shrink the window
                if(minWindow > j-i+1) {
                    minWindow = j-i+1;
                    minStart  = i;
                }
                
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0)
                    requiredCount++;
                i++;
            }
     //   }
            
            j++; //Don't ever forget this :-)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};
