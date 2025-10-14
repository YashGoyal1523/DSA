//lc 81 (can be duplicate eleemnts)

// same to pichla bas add a step of removing duplicates from left and right in while loop in finding pivot
// https://youtu.be/eneo_XPUEj0?si=iIr3YdaDqxWTkevn

class Solution {
public:
  
int pivotidx(vector<int>&nums)
{
    int n=nums.size();
int s=0;
int e=n-1;
while (s<=e)
{     

    // skip duplicates from left and right

    while(s<e && nums[s]==nums[s+1]) s++;
    while(s<e && nums[e]==nums[e-1]) e--;



    int mid=s+(e-s)/2;

    if (s==e)   //single element //corner case
    {
        return s;
    }
    
    if(mid+1<n&&nums[mid]>nums[mid+1])   //mid is pivot  // && ke phle wala for case like [1,3] ...isme mid+1 range ke bahar jaa skte ...toh andar wale hi le isiliye lagadi
   return mid;
   else if (mid-1>=0&&nums[mid]<nums[mid-1]) //mid-1 is pivot // && ke phle wala for case like [1,3] ...isme mid-1 range ke bahar jaa skte ...toh andar wale hi le isiliye lagadi
   return mid-1;
    else if (nums[s]>nums[mid])  // pivot ke right h , left chlo
    e=mid-1;
    else   // nums[s]<nums[mid]  // pivot ke left h , right chlo
    s=mid+1;
     
}

return -1;  // vse toh kabhi use nhi hoga..par return krna pdega kuch toh likhdia

}


bool binarysearch(vector<int>& nums,int start,int end,int target){
  
        
        while(start<=end){

            int mid=start+(end-start)/2 ;  //(start+end)/2..isme integer overflow ka chance hai ie sum of both may exceed range....or we can do start/2+end/2
            // found
            if(nums[mid]==target){
                return true;
            }
            // not found
            else if(nums[mid]<target){
                start=mid+1;
            }

            else if(nums[mid]>target){
                end=mid-1;
             }
        }
    // element not present
    return false;
}


    bool search(vector<int>& nums, int target) {

int n=nums.size();
int pvtidx=pivotidx(nums);

bool ans=false; 

 if(target>=nums[0] && target<=nums[pvtidx]){
    ans=binarysearch(nums,0,pvtidx,target);

 }
else    // target >=nums[pvtidx+1] && target<=nums[n-1]
 {
ans=binarysearch(nums,pvtidx+1,n-1,target);
}
return ans;
    }

};




// note : yeh pivot function mein ...bahar wala return -1 kabhi use hi na hoga...isko thoda modify ese kr skte
int pivotidx(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;

    while (s < e) {
        // skip duplicates from left and right

    while(s<e && nums[s]==nums[s+1]) s++;
    while(s<e && nums[e]==nums[e-1]) e--;


        int mid = s + (e - s) / 2;

        // If mid element is greater than next element, mid is pivot
        if (mid+1<nums.size()&&nums[mid] > nums[mid + 1])
            return mid;

        // If mid element is less than previous element, mid-1 is pivot
        if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
            return mid - 1;

        // Decide which half to search
        if (nums[s] < nums[mid]) {
            // Pivot must be in right half
            s = mid + 1;
        } else { // nums[s]>nums[mid]
            // Pivot must be in left half
            e = mid - 1;
        }
    }

    // s == e, it must be the pivot
    return s;
}

