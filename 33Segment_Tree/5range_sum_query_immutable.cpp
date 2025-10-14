//lc 303



//Approach-1 (Brute Force )
//T.C : Constructor: O(n), where n is length of nums array
//       sumRange: O(n)
//S.C : O(n)
class NumArray {
public:
    vector<int> num;
    int n;
    NumArray(vector<int>& nums) {
        num = nums;
        n   = nums.size();
    }
    
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += num[i];
        }
        return sum;
    }
};


//NOTE : You can improve Approach-1 further by taking another array storing prefixSum (prefix sum approach  : sum[l,r] = presum[r]-presum[l])


//Approach-2 (Segment Tree)
//T.C : Constructor: O(n), where n is length of nums array
//      sumRange: O(logN)
//S.C : O(n)
// class NumArray {
// public:

//     int n;
//     vector<int> segmentTree;

//     void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
//         if(l == r) {
//             segmentTree[i] = nums[l];
//             return;
//         }
        
//         int mid = l + (r-l)/2;
//         buildSegmentTree(2*i+1, l, mid, nums);
//         buildSegmentTree(2*i+2, mid+1, r, nums);
//         segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
//     }

//     int querySegmentTree(int start, int end, int i, int l, int r) {
//         if(l > end || r < start) {
//             return 0;
//         }
        
//         if(l >= start && r <= end) {
//             return segmentTree[i];
//         }
        
//         int mid = l + (r-l)/2;
//         return querySegmentTree(start, end, 2*i+1, l,    mid) + 
//                querySegmentTree(start, end, 2*i+2, mid+1, r);
//     }

//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         segmentTree.resize(4*n);
//         buildSegmentTree(0, 0, n-1, nums);
//     }
    

//     int sumRange(int left, int right) {
//         return querySegmentTree(left, right, 0, 0, n-1);
//     }
// };


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */