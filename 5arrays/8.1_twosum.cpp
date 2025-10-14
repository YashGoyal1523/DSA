//given array . tell whether sum of any two elements is k or not


//m1 bruteforce : two for loops :n2

//m2 map
    bool ans=false;
    unordered_map<int,bool>mp;
    for(int i=0;i<nums.size();i++){
        int reqmore=k-nums[i];
        if(mp.find(reqmore)!=mp.end()){
            ans=true;
            break;
        }
        mp[nums[i]]=true;
    }
    return ans;


//m3
//two pointer

        bool ans=false;
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;
        while(s<e) {
            int sum = nums[s]+ nums[e];
            if(sum==k) {
                ans=true;
                break;
            }
            else if(sum<k) {
                s++;
            }
            else{ //sum>k
                e--;
            }
        }
        return ans;

// lc 1


//m1 map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++) {
            int element=nums[i];
            int more=target-element;
            if(mp.find(more)!=mp.end())
                return {mp[more], i};
            mp[element] = i;
        }
        
        return {};
    }
};



//m2 two pointer

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         vector<pair<int,int> > temp;
//         for(int i=0; i<nums.size(); i++) {
//             int index = i;
//             int value = nums[i];
//             pair<int,int> p = make_pair(value,index);
//             temp.push_back(p);
//         }
//         //sort basis on value
//         sort(temp.begin(), temp.end());
//         //logic
//         int s = 0;
//         int e = nums.size()-1;
//         vector<int> ans;
//         while(s<e) {
//             int sum = temp[s].first + temp[e].first;
//             if(sum == target) {
//                 ans.push_back(temp[s].second);
//                 ans.push_back(temp[e].second);
//                 return ans;
//             }
//             else if(sum > target) {
//                 e--;
//             }
//             else {
//                 s++;
//             }
//         }
//         return ans;
//     }
// };