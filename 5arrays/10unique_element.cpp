
// given an array with elements each twice except one . find that unique

//m1 bitwise
// xor of same(decimal) will give resultant 0(decimal)
// xor of anything(decimal) with zero(decimal) will give resultant that anything(decimal) only

#include<iostream>
using namespace std ;

int unique(int arr[],int n){
    int ans=0;
    for (int i = 0; i < n; i++)
    {
       
       ans=ans^arr[i];
    }
    return ans;
}


int main()
{
    int arr[]={2,5,7,8,5,7,2};
    int n=7;
    int finalans=unique(arr,n);

    cout<<"unique is"<<finalans;
return 0;
}


// m2 map use krke freq nikalke kar skte

// m3 sort krke ,linear search se kr skte

//m4 sort krke ,binary search
//lc 540

//https://youtu.be/AZOmHuHadxQ?si=zeLNUtdpUS02vRpF
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
           int n = nums.size(); //size of the nums.

    //Edge cases handle krlete vrna inke liye alag checks lagane pdege
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int low = 1, high = n - 2;
    int ans;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if nums[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
            ans= nums[mid];
            break;
        }

        //we are in the left:
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

   
    return ans;
}
    
};