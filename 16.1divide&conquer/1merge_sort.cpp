// merge sort  //  divide and conquer   

#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {

	int mid = (s+e)/2;

	int lenLeft = mid - s + 1;
	int lenRight = e - mid;

	//create left and right array
	int *left = new int[lenLeft];
	int *right = new int[lenRight];

	//copy values from original array to left array
	int k = s; //starting index of left array values in original array is s
	for(int i=0; i<lenLeft; i++) {
		left[i] = arr[k];
		k++;
	}

	//copy values from original array to right array
	k = mid+1; //starting index of right array values in original array is mid+1
	for(int i=0; i<lenRight; i++) {
		right[i] = arr[k];
		k++;
	}

	//actual merge logic here

	//left array is already sorted
	//right array is already sorted
    // dono ko vaapis m merge karna together sorted in main array 
	int leftIndex = 0;//for traversal in left array // starting index of left array is 0
	int rightIndex = 0;//for traversal in right array // starting index of right array is 0
	int mainArrayIndex = s;//for traversal in main array //starting index of main array is s ......it is not 0 

    
	while(leftIndex < lenLeft &&  rightIndex < lenRight) {
		
		if(left[leftIndex] < right[rightIndex] ) {
			arr[mainArrayIndex] =  left[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			arr[mainArrayIndex] =  right[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	}
	
	//left array exhaust but agar right array me element abhi bhi bache hai
	while(rightIndex < lenRight) {
		arr[mainArrayIndex] =  right[rightIndex];
		mainArrayIndex++;
		rightIndex++;
	}
	// right array exhaust but agar left array me element abhi bhi bache hai
	while(leftIndex < lenLeft) {
		arr[mainArrayIndex] =  left[leftIndex];
		mainArrayIndex++;
		leftIndex++;
	}

	// memory free
	delete[] left;
	delete[] right;
}

void mergeSort(int arr[], int s, int e) {
	//base case
	if(s >= e) { // s>e : invalid array , s==e :single element  -> no sorting needed 
		return;
	}

	//break array
	int mid = (s+e)/2;

	//recusive call for left array sort:[s,mid]
	mergeSort(arr,s, mid);
	//recusive call for right array sort: [mid+1,e]
	mergeSort(arr, mid+1, e);

	//merge 2 sorted arrays
	merge(arr,s,e);
 
    return;
}

int main() {

	int arr[] = {2,1,6,9,4,5};
	int size = 6;
	int s = 0;
	int e = size - 1;

	cout << "Before merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	mergeSort(arr,s,e);

	cout << "After merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}


// tc  o(nlogn)  // sc o(n)  {additional+recursive : O(n)+O(logn)= o(n)}



// note : new and delete heavy operation hote
// better kr skte 
// merging ka ka kaam ek temp array m krke krlege



// lc 912

// uper wala bhi chaljayega

// better wala dekhte

// class Solution {
// public:
//     void merge(vector<int>&v, vector<int>&temp, int start, int mid, int end){
//         // first array = start -> mid
//         // second array = mid + 1 -> end
//         // merged array => start -> end
//         int i = start, j = mid + 1;
//         int k = start;

//         while(i <= mid && j <= end){
//             if(v[i] <= v[j])
//                 temp[k++] = v[i++];
//             else
//                 temp[k++] = v[j++];
//         }

//         // handle remaining elements in case of diff array size
//         while(i <= mid)
//             temp[k++] = v[i++];

//          while(j <= end)
//             temp[k++] = v[j++];

//         // lets copy merged data
//         while(start <= end){
//             v[start] = temp[start];
//             start++;
//         }
//     }

//     void mergeSort(vector<int>&v, vector<int>&temp, int start, int end){
//         if(start >= end) return;

//         int mid = (start + end) / 2;

//         mergeSort(v, temp, start, mid);
//         mergeSort(v, temp, mid + 1, end);

//         merge(v, temp, start, mid, end);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         vector<int>temp(nums.size(), 0);
//			int start = 0;
//			int end = nums.size() - 1;
//         mergeSort(nums, temp,start,end);
//         return nums;
//     }
// };