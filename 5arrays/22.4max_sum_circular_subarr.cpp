//lc 918

// https://youtu.be/Za8V4wkZKkM?si=3gCWBNnlQ1XeqTwj


// bruteforce

// array ko right shift ya left shift karte jao ....and har array mein..max sum subarray (lc 53) (not circular) nikal lo kadane lagake fir sabme se max lelo    (n-1 right shift tak dekhlena...as n shift pe same hojayega starting wala)

// o(n^2)


// optimal
//o(n)

//case1:ans given array m hi h
//case2:ans circular hoke aayega

//case1->kadane
//case2->total-min_sum_subarray

//ans=max(case1,case2)

//min_sum_subarray ->kadane



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n   = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        
        int k_sum_min = 1e9;
        int min_sum   = 0;
        
        int k_sum_max = -1e9;
        int max_sum   = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            min_sum   = min(nums[i]+min_sum, nums[i]);
            k_sum_min = min(k_sum_min, min_sum);
            
            max_sum = max(nums[i]+max_sum, nums[i]);
            k_sum_max = max(k_sum_max, max_sum);
         
        }
        
        int circular_sum = SUM - k_sum_min;
        
        if(k_sum_max >= 0) {//to handle saare elemnts -ve case
            return max(k_sum_max, circular_sum);
        }
        
        return k_sum_max;
        
    }
};