// lc 16

// bruteforce // n^3
// check all triplets


class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int closest_sum = 1e9;  
            
            for (int i = 0; i < nums.size() - 2; ++i) {
                for (int j = i + 1; j < nums.size() - 1; ++j) {
                    for (int k = j + 1; k < nums.size(); ++k) {
                        int current_sum = nums[i] + nums[j] + nums[k];
                        if (abs(current_sum - target) < abs(closest_sum - target)) {
                            closest_sum = current_sum;
                        }
                    }
                }
            }
            
            return closest_sum;
        }
    };


    // better // n^2
    // fixing one number and applying two pointers approach for other two numbers 
    class Solution {
        public:
            int threeSumClosest(vector<int>& nums, int target) {
                sort(nums.begin(), nums.end());
                int closest_sum = 1e9;  
                
                for (int i = 0; i < nums.size() - 2; ++i) {
                    int left =i+1, right = nums.size() - 1;
                    int current_sum=1e9;
                    while (left < right) {
                         current_sum = nums[i] + nums[left] + nums[right];
                        if(current_sum==target) return current_sum;
                         if (abs(current_sum - target) < abs(closest_sum - target)) {
                            closest_sum = current_sum;
                        }
                        
                      if (current_sum < target) {
                            ++left;
                        } 
                        else // current_sum > target
                        {
                            --right;
                        } 
        
                        
        
                    }
                   
                }
                
                return closest_sum;
            }
        };