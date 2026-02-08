//lc 3834
//stack

//tarika 1 using stack datastructure
// class Solution {
// public:
//     vector<long long> mergeAdjacent(vector<int>& nums) {
//         int n=nums.size();
//         stack<long long>st;
//         for(int i=0;i<n;i++){
//             long long curr=nums[i];
//             while(!st.empty()&&st.top()==curr){
//                 long long sum=st.top()+curr;
//                 st.pop();
//                 curr=sum;
//             }
//             st.push(curr);
//         }
//         vector<long long>ans;
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(begin(ans),end(ans));
//         return ans;
//     }
// };

//tarika 2 seedha ans vector mein stack ki trah krna
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans;
        for(int i=0;i<n;i++){
            long long curr=nums[i];
            while(ans.size()&&ans.back()==curr){
                long long sum=ans.back()+curr;
                ans.pop_back();
                curr=sum;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};