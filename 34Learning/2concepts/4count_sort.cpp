
// Counting Sort is a non-comparison-based sorting algorithm. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted.

// The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
// For example, for input [1, 4, 3, 2, 2, 1], the output should be [1, 1, 2, 2, 3, 4]. The important thing to notice is that the range of input elements is small and comparable to the size of the array.
// If the max element is of order more than n Log n where n is size of the array, then we can better sort the array using a standard comparison based sorting algorithm like Merge Sort.
// Counting Sort Algorithm
// Declare an auxiliary array countArray[] of size max(inputArray[])+1 and initialize it with 0.
// Traverse array inputArray[] and map each element of inputArray[] as an index of countArray[] array, i.e., execute countArray[inputArray[i]]++ for 0 <= i < N.
// Calculate the prefix sum at every index of array inputArray[].
// Create an array outputArray[] of size N.
// Traverse array inputArray[] from end and update outputArray[ countArray[ inputArray[i] ] - 1] = inputArray[i]. Also, update countArray[ inputArray[i] ] = countArray[ inputArray[i] ]- - .

//note:
// after comulating count array , count[i] tells us how many elements are ≤ i in the input array ...ie... in sorted array elements ≤ i end at index count[i]-1 (0 based indexing)
//note:
//We iterate the input array backwards (right to left).Going backwards ensures stability (i.e., if two elements have the same value, their original order is preserved).
      


#include <iostream>
#include <vector>
using namespace std;

vector<int> countsort(vector<int>& arr) {
    int n = arr.size();

    // find the maximum element
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

    // create and initialize count array
    vector<int> count(maxval + 1, 0);

    // count frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // compute prefix sum
    for (int i = 1; i <= maxval; i++)
        count[i] += count[i - 1];

  
    // build output array(stable)
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) { 
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    

    return ans;
}

int main() {
    vector<int> arr = {2,5,3,0,2,3,0,3};
    vector<int> sorted = countsort(arr);

    for (int x : sorted)
        cout << x << " ";

    return 0;
}


// Complexity:

// Time: O(n + k)
// (where n = number of elements, k = range of input values)

// Space: O(k) (extra array for counts)

// Stability: Yes (preserves order of equal elements).

// Advantage of Counting Sort:
// Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort, if the range of input is of the order of the number of input.
// Counting sort is easy to code
// Counting sort is a stable algorithm.
// Disadvantage of Counting Sort:
// Counting sort doesn’t work on decimal values.
// Counting sort is inefficient if the range of values to be sorted is very large.
// Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.
// Applications of Counting Sort:
// It is a commonly used algorithm for the cases where we have limited range items. For example, sort students by grades, sort a events by time, days, months, years, etc