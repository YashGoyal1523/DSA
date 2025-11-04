vector<int> topKElements(vector<int>& nums, int k) {
    // Use a min-heap to store top k elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // remove smallest to keep only top k largest
        }
    }

    // Extract elements from heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

Time → O(n log k)