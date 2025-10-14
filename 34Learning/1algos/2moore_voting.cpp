 //majority element
 // given array of n elements. return element with freq more than n/2 . if not exist then return -1



 // m1 use hashmap 



 //m2 moore voting algo
 // The Moore’s Voting Algorithm is an efficient algorithm to find the majority element in an array (i.e., an element that appears more than ⌊n/2⌋ times) if it exists. It runs in O(n) time and uses O(1) space.

int majorityElement(vector<int>& nums) {
    int cnt=1;
    int element=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]==element) cnt++;
        else cnt--;
        if(cnt==0){
            cnt=1;
            element=nums[i];
        }
    }
    //if question guarantee ki majority element hai then element obtained abhi is ans
    // but if it doesnt guarantee that there is then we need to verify the element obtained 
    // if its freq >n/2 then its majority else there is no majority
    //verification
    int cnt1=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==element) cnt1++;
    }
    if(cnt1>n/2) return element;
    return -1;
}



// note: m3 (if ques guarantee that there is majority element) -> sort and return element at index n/2


//lc 169

//moore voting algo
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int cnt=1;
            int element=nums[0];
            for(int i=1;i<nums.size();i++){
                if(nums[i]==element) cnt++;
                else cnt--;
                if(cnt==0){
                    cnt=1;
                    element=nums[i];
                }
            }
          
            return element;
        }
    };


    // lc 2780

    //observe dominant element of nums array hi dominant element of subarrays hoga
// if nums ka dominant nhi toh not possible aayega

//hashmap
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n=nums.size();
            //finding dominant of nums..using hashmap
            unordered_map<int,int>m;
            int maxf=0;
            int maxi=-1;
            for(int i=0;i<nums.size();i++){
                m[nums[i]]++;
                if(m[nums[i]]>maxf){
                    maxi=nums[i];
                    maxf=m[nums[i]];
                }
            }

            if(maxf<=n/2) return -1;  // early return

            int ans=-1;
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==maxi){
                    cnt++;
                }
                    if(cnt>(i+1)/2 && (maxf-cnt)>(n-i-1)/2){
                        ans=i;
                        break;
                    }
                
            }
            return ans;
        }
    };

    // moore voting
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            // Find the majority element using  moore voting algo
            int x = nums[0], count = 0, xCount = 0, n = nums.size();
            for (auto& num : nums) {
                if (num == x) {
                    count++;
                } else {
                    count--;
                }
                if (count == 0) {
                    x = num;
                    count = 1;
                }
            }
    
            // Count frequency of majority element
            for (auto& num : nums) {
                if (num == x) {
                    xCount++;
                }
            }
    
            if(xCount<=n/2) return -1; // early return
          
            count = 0;
            int ans=-1;
            for (int index = 0; index < n; index++) {
                if (nums[index] == x) {
                    count++;
                }
                int remainingCount = xCount - count;
                if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                    ans= index;
                    break;
                }
            }
            return ans;
        }
    };