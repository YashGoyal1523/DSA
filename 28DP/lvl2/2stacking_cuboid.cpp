// lc 1691

// longest increasing subsequence (lis) ques ke pattern par h 

// class Solution {
// public:
//     bool check(vector<int>& curr, vector<int>& prev) {
//         //curr -> bade wala dabba
//         //prev -> chotte wala dabba
//         if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
//     int solveUsingTabulationSO(vector<vector<int> >& cuboids ) {
//         int n = cuboids.size();
        
//         vector<int> currRow(n+1, 0);
//         vector<int> nextRow(n+1, 0);


//         for(int curr_index=n-1; curr_index>=0; curr_index--) {
//             for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) {

//                 int include = 0;
//                 if(prev_index == -1 || check( cuboids[curr_index] , cuboids[prev_index] ) ) { // idhar wale mein +1 ki need nhi as || ke baad h and prev -1 ka mtlb  phle wali true nikl gyi... toh yeh check hogi hi nhi seedha andar ghusegi
//                     int heightToAdd = cuboids[curr_index][2];
//                     include = heightToAdd + nextRow[curr_index+1]; // +1 krlia...
//                 }
//                 int exclude  = 0 + nextRow[prev_index+1]; // index shifting krlia..+1
//                 currRow[prev_index+1] = max(include, exclude);   // +1
//             }
//             //shifting
//             nextRow = currRow;
//         }
//         return nextRow[0]; // +1 krlia
//     }
//     int maxHeight(vector<vector<int>>& cuboids) {
// // dabbo ko  kse bhi ghuma ke rkh skte
// // dabbe ki max dimension ko uski height banayege isiliye dabbo ki dim sort krli ab  teesri dim ko height bnaeyeg...first second ko kuch maanlo no farak
//         for(auto &cuboid: cuboids) { // by ref lena pdega 
//             sort(cuboid.begin(), cuboid.end());   
//         }
// // sab dabbos ko apas m bhi sort kr lete on their first dimension...(isse yeh lis ques ke form m convert hojayega)
//         sort(cuboids.begin(), cuboids.end()); 
       
//         int ans = solveUsingTabulationSO(cuboids);
//         return ans;
//     }
// };


// binary search wala nhi kr skte as idhar just bada cuboid nhi dhund skte