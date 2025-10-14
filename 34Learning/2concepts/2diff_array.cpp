// difference array technique
// technique used to efficiently apply range updates(+/-) to an array. It allows multiple updates in O(1) time per update and enables retrieving the final values in O(n) time.
// ideal for range modification (+/-) problems 
// https://youtu.be/ZHNVmtm08WY?si=6kxjxhFNJkETvSgn


//difference array stores how much each element is modified



// range addition 

// // build difference array
// take diff array ={0}
// [l,r,x] -> diff[l]+=x , diff[r+1]-=x if r+1<n  
// // find resultant change at each index
// at end take commulative sum (prefix sum) 
// // apply change (difference array stores how much each element increases )
// original arr + diff arr ie add each element


// range subtraction

// // build difference array
// take diff array ={0}
// [l,r,x] -> diff[l]+=x , diff[r+1]-=x if r+1<n  
// // find resultant change at each index
// at end take commulative sum (prefix sum) 
// // apply change (difference array stores how much each element decreases)
// original arr - diff arr ie subtract each element



//eg

//lc 3356

// o(n) mein krna h
// range updation required 
// ->difference array technique



class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       vector<int>diff(n,0);

       for(int i = 0; i <= queries.size()-1; i++) {
                    int l = queries[i][0];
                    int r   = queries[i][1];
                    int x   = 1;
        
                    diff[l] += x;
                    if(r+1 < n)
                        diff[r+1] -= x;
                }
        
                int cumSum = 0;
               
                for(int i = 0; i < n; i++) {
                    cumSum += diff[i];
        
                    diff[i] = cumSum;
        
                    if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                        return false;
                    }
                }
        
                return true;
        
    }
};