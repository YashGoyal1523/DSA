// lc 791


// class Solution {
// public:
   
//     static string str; // global variable banaliya as hume order ko comparator function m use krna par pass toh nhi kar skte toh global variable m order store krlege

//      //custom comparator
//     static bool compare(char char1, char char2) {
        
//          return (str.find(char1) < str.find(char2));

//     }
//     string customSortString(string order, string s) {
        
//         str = order;
//         sort(s.begin(), s.end(), compare);
//         return s;
//     }
// };
// string Solution::str;