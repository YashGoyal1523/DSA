
// given an array with elements (can have duplicate elements). find total no of pairs whose sum is equal to k
// (a,b) is same as (b,a)
// each element to be used in one pair only


//map
int countUniquePairsWithSum(const vector<int>& arr, int k) {
    unordered_map<int, int> freq; // To store the frequency of each element
    int count = 0;

    for (int num : arr) {
        // If the complement exists in the map, it means we can form a valid pair
        int complement = k - num;
        
        // Check if the complement has appeared previously
        if (freq[complement] > 0) {
            count++;
            // Decrease the frequency of the complement as its paired with current number
            freq[complement]--;
        } else {
            // Otherwise, store the frequency of the current number
            freq[num]++;
        }
    }

    return count;
}


// two pointer
int countPairsWithSum(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end()); // Step 1: Sort the array
    int left = 0, right = arr.size() - 1;
    int count = 0;

    while (left < right) { // Step 2: Two-pointer approach
        int sum = arr[left] + arr[right];

        if (sum == k) {
            count++;
            left++;   // Move left pointer to the right
            right--;  // Move right pointer to the left
        } else if (sum < k) {
            left++;   // Increase the sum
        } else {
            right--;  // Decrease the sum
        }
    }

    return count;
}



// given an array with elements (can have duplicate elements). find total no of pairs whose sum is equal to k
// (a,b) is same as (b,a)


//map
int countPairsWithSum(const vector<int>& arr, int k) {
    unordered_map<int, int> freq; // To store frequencies of elements
    int count = 0;

    for (int num : arr) {
        int complement = k - num;

        // If the complement exists in the map, count the pairs
        if (freq.find(complement) != freq.end()) {
            count += freq[complement];
        }

        // Increment the frequency of the current number
        freq[num]++;
    }

    return count;
}

//two pointer
int countPairsWithSum(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end()); // Step 1: Sort the array
    int left = 0, right = arr.size() - 1;
    int count = 0;

    while (left <= right) { // Step 2: Two-pointer approach
        int sum = arr[left] + arr[right];

        if (sum == k) {
            //to handle duplicates
            if (arr[left] == arr[right]) { // saare hi same h bich ke
                int freq = right - left + 1;
                count += (freq * (freq - 1)) / 2; // nC2 pairs
                break; // All pairs are counted, no need to continue
            } 
            else {
                // Count pairs using all occurrences of arr[left] and arr[right]
                int freqLeft = 1, freqRight = 1;

                // Count duplicates of arr[left]
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    freqLeft++;
                    left++;
                }

                // Count duplicates of arr[right]
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    freqRight++;
                    right--;
                }

                // Add all pairs formed by these frequencies
                count += freqLeft * freqRight;

                // Move both pointers inward
                left++;
                right--;
            }
        } else if (sum < k) {
            left++; // Increase the sum
        } else {
            right--; // Decrease the sum
        }
    }

    return count;
}