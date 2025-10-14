// // lc 76

// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         // invalid case
//         int len1 = s.length();
//         int len2 = t.length();

//         if (len1 < len2)
//         {
//             return "";
//         }
//         // valid case
//         int ansIndex = -1;
//         int ansLen = INT_MAX;

//         unordered_map<char, int> sMap;
//         unordered_map<char, int> tMap;
//         // store freq of pattern string
//         for (char ch : t)
//         {
//             tMap[ch]++;
//         }
//         // initialise count variable, that basically shows count of actual
//         // pattern wale string k character presrnt in the current window
//         int count = 0;
//         int e = 0;
//         int st = 0;
//         while (e < s.length())
//         {
//             char ch = s[e];
//             // update freq in sMap
//             sMap[ch]++;
//             if (sMap[ch] <= tMap[ch]) // window ka char agar required string m present h toh count krlo par note required amount se zyada h toh ignore kro
//             { 
//                 // valid character
//                 count++;
//             }

//             if (count == len2)
//             {
//                 // window found, jisme poora pattern exist krta h
//                 //-> minimise
//                 // us case me karenga, jis case me
//                 // st index pr jo character present h, vo
//                 // required but extra hai
//                 // ya aisa character ho jo pattern k andar hi nahi h ......
//                 while (sMap[s[st]] > tMap[s[st]] || tMap[s[st]]== 0)
//                 {
//                     if (sMap[s[st]] > tMap[s[st]])
//                 {
//                         sMap[s[st]]--;
//             }
//                     st++;
//                 }
//                 // answer nikalo
//                 int windowLength = e - st + 1;
//                 if (windowLength < ansLen)
//                 {
//                     ansLen = windowLength;
//                     ansIndex = st;
//                 }
//             }
//             e++;
//         }

//         if (ansIndex == -1)
//         {
//             return "";
//         }
//         else
//         {
//             return s.substr(ansIndex, ansLen);
//         }
//     }
// };