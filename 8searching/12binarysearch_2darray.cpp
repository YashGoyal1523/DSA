//lc 74


//m1 linear search lagado and har ek element ko check krke dekhlo
//O(N X M), where N = given row number, M = given column number.


//m2 binary search

//2.1
// phle voh row dhundhlo jismein present hona chahie ...find it by checking har row mein if row ka first and last element value ke bich ki range mein target value lie krta ya nhi....jisme miljaye voh row pakadlo
//fir uss row m bs lagake nikal lo
//koi row hi na mile fir toh false h hi
//O(N + logM), where N = given row number, M = given column number.
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}
};

//2.2 
//poore matrix m ek saath bs lagake krna
//2d array ko 1d mei convert krke bs lagadege
// O(log(NxM)), where N = given row number, M = given column number.

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//          int row=matrix.size();
//     int col=matrix[0].size();
    
//     int n=row*col;  // total size

//     int start=0;
//     int end=n-1;

 
//     while (start<=end)
//     {
//        int mid=start+(end-start)/2;

//         //1d to 2d

//         int rowindex=mid/col;
//         int colindex=mid%col;

//         int element=matrix[rowindex][colindex];

//         if (element==target)
//         {
//             return true;
//         }
//         else if (element<target)
//         {
//             start=mid+1;
//         }
//         else 
//         end=mid-1;
//     }
    

// return false;

//     }
// };
