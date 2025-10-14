// lc 354

// stackig cuboid wale ques ke pattern par h 

// class Solution {
// public:

//     bool check(vector<int>& curr, vector<int>& prev) {
//         //curr -> bade wala enveloe
//         //prev -> chootte wala envelope
//         if(prev[0] < curr[0] && prev[1] < curr[1]) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     int solveUsingTabulationSO(vector<vector<int> >& env ) {
//         int n = env.size();
        
//         vector<int> currRow(n+1, 0);
//         vector<int> nextRow(n+1, 0);


//         for(int curr_index=n-1; curr_index>=0; curr_index--) {
//             for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) {

//                 int include = 0;
//                 if(prev_index == -1 || check( env[curr_index] , env[prev_index] ) ) { // +1 ki no need yaha
                   
//                     include = 1 + nextRow[curr_index+1]; //+1 krlia as har jagah needed
//                 }
//                 int exclude  = 0 + nextRow[prev_index+1]; // index shifting krdi..+1 done
//                 currRow[prev_index+1] = max(include, exclude); //+1 done
//             }
//             //shifting
//             nextRow = currRow;
//         }
//         return nextRow[0]; //+1 needed...krlia
//     }
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//    // rotate nhi kr skte toh individual sorting toh nhi krege
//         sort(envelopes.begin(), envelopes.end()); // overall apas mein sorting
//         int ans = solveUsingTabulationSO(envelopes);
//         return ans;
//     }
// };


// yeh tle degaa
// binary search se krna pdega