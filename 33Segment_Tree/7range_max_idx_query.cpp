//range max index query


    // Builds the segment tree 
    void buildSegmentTree(int i, int l, int r, vector<int>&segmentTree, vector<int>& arr) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
        
        // Store the index of the maximum element
        segmentTree[i] = (arr[segmentTree[2 * i + 1]] >= arr[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    
    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree, vector<int>& arr) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, arr);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, arr);

        // Return the index of the maximum element
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    

    vector<int> rangeMaximumIndexQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>segmentTree(4*n);
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);

        vector<int> result;
        for(auto& query: queries){
            int a = query[0];
            int b = query[1];

            int idx = querySegmentTree(a, b, 0, 0, n - 1, segmentTree, arr);
            result.push_back(idx);
        }
        return result;
    }



