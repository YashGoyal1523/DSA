// suppose we are moving pointers inside an array like in variable sliding window technique and we want to maintain min max element of subarray
// for this we can use set data structure as it is implemented as balanced binary search tree and it maintains sorted order of elements and we can get min max element in O(1) time and insertion and deletion in O(logn) time 
// if elements are not unique we can use multiset as it allows duplicate elements and also maintains sorted order of elements and we can get min max element in O(1) time and insertion and deletion in O(logn) time



// rbegin() → iterator at last element
// rend() → iterator before first element

// set<int>st;
// int first element=*st.begin(); // gives minimum element of set
// int last element=*st.rbegin(); // gives maximum element of set
// //or
// int last element=*prev(st.end()); // gives maximum element of set


//eg ques lc 3835

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long cnt=0;
        int i=0;
        int j=0;
        multiset<int>s;
        while(j<n){
            s.insert(nums[j]);
            long long maxi=*s.rbegin(); //last element
            long long mini=*s.begin(); //front element
            long long cost=(maxi-mini)*(j-i+1);
            while(cost>k){
                s.erase(s.find(nums[i])); // s.erase(nums[i]) will erase all occurrences.....so s.erase(s.find(nums[i])) to erase only one occurrence if many present
                i++;
                maxi=*s.rbegin() ;
                mini=*s.begin();
                cost=(maxi-mini)*(j-i+1);
            }
            cnt=cnt+(j-i+1);
            j++;
        }
        return cnt;

    }
};