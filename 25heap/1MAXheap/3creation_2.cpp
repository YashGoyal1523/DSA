// create a max heap from given array....

// last se har element ka downwards heapify krna bass...
  // (complete binary tree mein n/2+1 th se nth node leaf node hoti h (1 indexed))
  // n/2+1 th se nth tak ke elements leaf nodes hogi....unko krne ki zrurat nhi 
#include <iostream>
using namespace std;

// recursive heapify
void heapify(int *arr, int n, int index) {
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestKaIndex = index;

  //teeno me se max lao 
  if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
    largestKaIndex = leftIndex;
  }
  if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
    largestKaIndex = rightIndex;
  }
  //now largestKaIndex will be pointing towards largest elemnt among 3 
  if(index==largestKaIndex){
    return;
     }
 else {
    swap(arr[index], arr[largestKaIndex]);
    //ab recursion sambhal lega
    index = largestKaIndex;
    heapify(arr, n, index);
  }
  return;
}

void buildHeap(int arr[], int n) {
  // ( complete binary tree mein n/2+1 th se nth node leaf node hoti h )
  // n/2+1 th se nth tak ki nodes leaf nodes hogi....unko  krne ki zrurat nhi 
  for(int index = n/2; index>=1; index--) {   // 1 based indexing
    heapify(arr, n, index);
  }
}

int main() {
  int arr[] = {-1,5,10,15,20,25,12};       // 1 indexed
  int n = 6;
  buildHeap(arr,6);  // max heap
  
  cout << "printing heap: " << endl;
  for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  
  return 0;
}


// tc o(n) find kro kse