// given max heap....sort it
#include <iostream>
using namespace std;

void heapify(int *arr, int n, int index) { // downwards heapify
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
  //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
  if(index == largestKaIndex) {
    return;
    }
    else{
    swap(arr[index], arr[largestKaIndex]);
    //ab recursion sambhal lega
    index = largestKaIndex;
    heapify(arr, n, index);
  }
  return;
}

void buildHeap(int arr[], int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}

// given max heap
void heapSort(int arr[], int n) {
//approach : max heap hai toh root wala(phla element) sabse bada hoga in heap....usko last par lagao...(swap krdo)....ab yeh last wale ko bhuljao ki yeh exist krta ..uske baad first  wale ko heapify (downwards)  krdo(excluding last wala)...ab root(phla element) par next bada aagya hoga...usko fir last(excluding pichle last ) se swap  and repeat krte jao jabtak ek element na bachjaye
//-> first last ko swap ..last ko delete maanlo.... fir first ko heapify downwards....repeat till ek element bach jaaye


  while(n != 1 ) {    // jabtak ek element na bach jaaye
    swap(arr[1], arr[n]);  // note: last wala is at n not n-1...1 indexed hai
    n--; // for last wale ko delete manna
    heapify(arr,n,1);
  }
}


int main() {
  int arr[] = {-1,5,10,15,20,25,12};
  int n = 6;
  buildHeap(arr,6);
  
  cout << "printing heap: " << endl;
  for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);
    cout << "printing heap: " << endl;
    for(int i=1; i<=6; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  


 
  return 0;
}





// heap sort : tc : o(nlogn) .....n-2 baar heapify (logn) hora ...approx krke nlogn