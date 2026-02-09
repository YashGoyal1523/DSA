// lc 2391  Minimum Amount of Time to Collect Garbage

// // total time for a truck=pick time+travel time
// // total time = total time for all trucks

// class Solution {
// public:
//     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//         int pickP = 0;  //  p ka pick time
//         int pickM = 0;
//         int pickG = 0;

//         int travelP = 0; // p ka travel time  
//         int travelG = 0;
//         int travelM = 0;

//         int lastP = 0;  // last index where p is present ...this will help in finding travel time
//         int lastG = 0;
//         int lastM = 0;

//         //calculate pick time 
//         for(int i=0; i<garbage.size(); i++) {
//             string curr = garbage[i];
            
//             for(int j=0; j<curr.length(); j++) {
//                 char ch = curr[j];

//                 if(ch =='P') {
//                     pickP++;          // pick time to pick 1 unit is 1
//                     lastP = i;
//                 }
//                 else if(ch =='G') {
//                     pickG++;
//                     lastG = i;
//                 }
//                 else if(ch == 'M' ) {
//                     pickM++;
//                     lastM = i;
//                 }

//             }
            
//         }

//         //calculate travel time   ( time to reach index i in garbage array is given by sum of times till i-1 index in travel array  ) (0 index par hi khade initially ..uska time is zero)
//         for(int i=0; i<lastP; i++) {
//             travelP += travel[i];
//         }

//         for(int i=0; i<lastG; i++) {
//             travelG += travel[i];
//         }

//          for(int i=0; i<lastM; i++) {
//             travelM += travel[i];
//         }

//         int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
//         return ans;
//     }
// };