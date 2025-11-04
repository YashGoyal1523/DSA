// Time: O(n log k)

vector<int> topKSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap; // max-heap

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k)
            maxHeap.pop(); // remove largest
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return result;
}