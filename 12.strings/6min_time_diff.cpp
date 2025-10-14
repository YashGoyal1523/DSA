// // LC 539
//  // saare given time ... in terms of minutes (in int) store krlo vector m
//  // sort krlo
//  // ab consecutive ka diff ka min niklo
//  // note: to handle last wala rotation wala case ie eg last mein time 23:50 pahuchke fir vaapis starting time 00:05 ke bich diff is 15 wala case.....sort krne ke baad last m ... 1440 (24:00 in minute form)+vector[0] push krlo




// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         // saare given time ...minute form m nikal lo
//         vector<int>num;
//         for(int i=0;i<timePoints.size();i++){
//             int hrs=stoi(timePoints[i].substr(0,2));
//             int mins=stoi(timePoints[i].substr(3,2));
//             int totalmin=(hrs*60)+mins;
//             num.push_back(totalmin);
//         }
//         //sab minutes milgyi
//         // ab sort krdo 
//         sort(num.begin(),num.end());
//         //24:00 push
//         num.push_back(1440+num[0]); // 24:00 is 1440 minutes ((24*60)+0)
//         // consecutive ke diff ka min uthalo
//         int ans=INT_MAX;
//         for(int i=0;i<num.size()-1;i++){
//             int diff=num[i+1]-num[i];
//             ans=min(ans,diff);
//         }
//         return ans;
//     }
// };