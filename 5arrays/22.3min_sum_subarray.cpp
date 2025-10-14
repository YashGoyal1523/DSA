// min subarray sum

//kadane

//tarika 1
int minSubArray(vector<int>& nums) {
    int sum = 0;
    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        mini = min(mini, sum);          // Update minimum sum so far
        if (sum > 0) sum = 0;    //min mainatain ke bad krna yeh step..dhyaan rkhna     // Reset sum if it becomes positive
    }

    // If you want to consider empty subarray with sum = 0 (optional):
    // if (mini > 0) mini = 0;

    return mini;
}


//tarika 2

int minSubarraySum(vector<int>& nums) {
    int currentMin = 0;
    int overallMin = 1e9;

    for (int i = 0; i < nums.size(); i++) {
        currentMin = min(nums[i], currentMin + nums[i]);
        overallMin = min(overallMin, currentMin);
    }

    return overallMin;
}
