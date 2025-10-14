// lc 2125 


// ek vector banao
//ab shuru se ek ek row uthao and usme present count of 1 dekho ..if >0 then vector m push krdo ..and if 0 then ignore  ie no pushing .... and aage bhado ......ese krlo sabme
// ab vector ke consecutive elements ke mutilply ka sum krlo

// class Solution {
// public:
//     int numberOfBeams(vector<string>& bank) {
//         vector<int>devices;
//         for(int i=0;i<bank.size();i++){
//             int cnt1=count(bank[i].begin(),bank[i].end(),'1');           
//             if(cnt1>0) devices.push_back(cnt1);
//         }
//         if(devices.size()<2) return 0;
//         int ans=0;
//         for(int i=0;i<devices.size()-1;i++){
//             ans=ans+(devices[i]*devices[i+1]);
//         }
//         return ans;
//     }
// };