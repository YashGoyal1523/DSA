//sort given array

//approach :
// “Count how many times each number occurs, then rewrite the array by placing each number exactly as many times as it appears, in increasing order.”

// Steps:
// ->Find the maximum element in the array
// Let maxVal = max(arr)
// This decides the size of the frequency array.

// ->Create a frequency array count of size maxVal + 1
// Initialize all values to 0.

// ->Count frequencies
// For each element x in arr, increment count[x].
// After this step, count[i] will store how many times i appears in the array.

// ->Reconstruct the sorted array
// Initialize idx = 0
// For each i from 0 to maxVal:
// Repeat count[i] times:
// Set arr[idx] = i
// Increment idx

// ->End
// Now arr is sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

void simpleCountingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Step 1: Find maximum element
    int maxVal = *max_element(arr.begin(), arr.end());

    // Step 2: Frequency array
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) {
        count[num]++;
    }

    // Step 3: Place elements back into arr
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[idx++] = i;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    simpleCountingSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}

