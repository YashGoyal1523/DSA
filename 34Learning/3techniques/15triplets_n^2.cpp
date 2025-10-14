// for finding no of triplets in n^2

// ek fix krke baaki do two pointer se

//eg
// lc 611

//for n^2
//sort krlo
//largest no fix krke other 2 nos two pointer se krlo
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=n-1;i>=0;i--){ //largest no among 3
            int a=nums[i];
            //other 2 nos
            int j=0;
            int k=i-1;
            while(j<k){
                int b=nums[j];
                int c=nums[k];
                if(b+c>a) {
                    cnt+=k-j;
                    k--;
                }
                else j++;
            }
        }
        return cnt;
    }
};