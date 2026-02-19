// observe how we are moving the pointer i to track consecutive elements


//lc 696 count binary substrings

// 000..0111..1  or  111..1000...0 has min(cnt0,cnt1) valid subarrays

//likhne ka tarika 1 

// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int prev0=0;
//         int prev1=0;
//         int i=0;
//         int ans=0;
//         while(i<s.size()){
//             char val=s[i];
//             int cnt=0;
//             while(i+1<s.size()&&s[i+1]==val){
//                 i++;
//                 cnt++;
//             }
//             cnt++;
//             if(val=='1') {
//                 ans+=min(cnt,prev0);
//                 prev1=cnt;
//             }
//             else{
//                 ans+=min(cnt,prev1);
//                 prev0=cnt;
//             }

//             i++;
//         }

//         return ans;
//     }
// };

//likhne ka tarika 2
// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int prev0=0;
//         int prev1=0;
//         int i=0;
//         int ans=0;
//         while(i<s.size()){
//             char val=s[i];
//             int cnt=0;
//             while(i<s.size()&&s[i]==val){
//                 i++;
//                 cnt++;
//             }
//             if(val=='1') {
//                 ans+=min(cnt,prev0);
//                 prev1=cnt;
//             }
//             else{
//                 ans+=min(cnt,prev1);
//                 prev0=cnt;
//             }
//         }

//         return ans;
//     }
// };

//likhne ka tarika 3

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int i=0;
        int ans=0;
        while(i<s.size()){
            char val=s[i];
            int cnt=0;
            while(i<s.size()&&s[i]==val){
                i++;
                cnt++;
            }
                ans+=min(cnt,prev);
                prev=cnt;  
        }

        return ans;
    }
};