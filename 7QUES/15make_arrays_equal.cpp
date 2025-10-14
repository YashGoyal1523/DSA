// lc 1460 

// // agar elements(including freq) same ho  dono m toh kar skte.......
// // pairs ko swap kr krke banalege

// // bas elements check krne

// m1 sorting
// dono ko sort krdo, if become same then true else false
// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         sort(target.begin(),target.end()) ;
//         sort(arr.begin(),arr.end()) ;

//         return target==arr ;
//     }
// };

// m2 hashing
// dono ke element frequency compare krlo, if same then true else false

// way1

// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//             vector<int>freqa(1001);
//         vector<int>freqt(1001);

//         for(int i=0;i<arr.size();i++){
//             freqa[arr[i]]++;
//         }
//          for(int i=0;i<target.size();i++){
//             freqt[target[i]]++;
//         }

//         return freqa==freqt;
//     }
// };

// way 2

// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//             vector<int>freq(1001);
        

//         for(int i=0;i<arr.size();i++){
//             freq[arr[i]]++;
//         }
//          for(int i=0;i<target.size();i++){
//             freq[target[i]]--;
//         }

//        for(int i=0;i<freq.size();i++){
//         if(freq[i]!=0) return false;
//        }
//        return true;
//     }
// };