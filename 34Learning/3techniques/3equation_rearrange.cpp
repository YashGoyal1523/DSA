//If you see something like f(i,j) = f(j,i), try to think if you can rephrase the problem to the form of g(i) = g(j) and see if that helps in solving
//jse ques mein index and index values m equation di ho jse j-i!=nums[j]-nums[i] toh usse rearrange krke  index and uski values same side krke solve krna is simpler => nums[j]-j != nums[i]-i

//lc 2364

//bruteforce n^2

//optimal
//  bad pair : j-i!=nums[j]-nums[i] => nums[j]-j != nums[i]-i

// no of bad pairs of index j (j is bade wala index of pair ) is  = no of positions to left with different nums[index]-index value from j ki
//                                                                = total no of positions to left  -  no of positions with same value                                                          
//                                                                =  j  -  no of positions with same value
//o^n

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int,int>mp; // (value: nums[index]-index, freq of value )
            long long ans=0;
            for(int i=0;i<nums.size();i++){
                int currValue=nums[i]-i;
                int prev=mp[currValue]; // no of prev postions with same value as curr  // good pairs
                int totalprev=i; // total prev positions // total pairs
                ans+=totalprev-prev;
                mp[currValue]++; // update curr in map
            }
    
            return ans;
        }
    };