#include <iostream>    
using namespace std;

class Heap{
  public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
      this->arr = new int[capacity];
      this->capacity = capacity;
      //size = current number of elements in heap
      this->size = 0 ;
    }

    void insert(int val) {
      if(size == capacity) {
        cout << "Heap OverFlow" << endl;
        return;
      }
      //size increase kar jaega
      size++;
      int index = size;
      arr[index] = val;

      ///take the val to its correct position : heapify : (upwards heapify)
      while(index > 1) {
        int parentIndex = index/2;
        if(arr[index] > arr[parentIndex]) {
          swap(arr[index], arr[parentIndex]);
          index = parentIndex;
        }
        else {
          break;
        }
      }
    }
    void printHeap() {
      for(int i=1; i<=size; i++) {
         cout << arr[i] << " ";
     }
    }

    int deleteFromHeap() {
      // we can access only root node in heap
      // we can only delete root node

      int answer = arr[1];

      //replacement :root ko last level ke rightmost se replace kkrdo as rightmost par dusre dependant nhi h......(last level ka rightmost ke alawa aur koi uthayege toh left to right filling disturb hogi .....yuhi kisi level ka koi uthayege toh uske child disturb hoge(if present nhi h toh thik h dikkat nhi aayegi)...toh last level ka rightmost is apt in all cases)
      arr[1] = arr[size];

      //last element ko delete uski original position se
      size--; // signifies deletion of last

      //heapify of new root node (downwards heapify)
      // parent ko dono child se compare krte jao...and agar parent largest nhi h toh parent ko largest se swap krte jao....jaha thik miljaye vaha ruk jao...parent ko last eleemnt banne tak check krlo
      int index = 1;
      while(index < size ) {  //  last element banne tak chaladiya...last pe ruk jao
          int leftIndex = 2*index;
          int rightIndex = 2*index+1;

          //find out karna h , sabse bada kon

          int largestKaIndex = index;
          // check left child
          if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]) {
            largestKaIndex = leftIndex;
          }
          // check right child 
          if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]) {
            largestKaIndex = rightIndex;
          }
          //now largestKaIndex will be pointing towards largest elemnt among 3 
          if(index == largestKaIndex) { // vhi bada h
            break;
          }
          else 
           {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
          }
      }
      return answer;
    }
};


int main() {
 

  Heap h(20);
  //insertion
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(11);
  h.insert(6);

  cout << "Printing the content of heap: " << endl;
  h.printHeap();
  cout<<endl;
  int removed = h.deleteFromHeap();     // will return deleted one
  cout << "removed: " << removed << endl;
  cout << "Printing the content of heap: " << endl;
  h.printHeap();
  return 0;
}


// tc o(logn) as heapify...


// note:

// recursive heapify

// void heapify(int *arr, int n, int index) {

// if(index==n){
//   return;   
// }                      // vse yeh base case na bhi likho toh bhi chaljayega aage jaake apne aap return hojayega par likhliya koina

//   int leftIndex = 2*index;
//   int rightIndex = 2*index+1;
//   int largestKaIndex = index;

//   //teeno me se max dekho
//   if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
//     largestKaIndex = leftIndex;
//   }
//   if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
//     largestKaIndex = rightIndex;
//   }
//   //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
//   if(index==largestKaIndex){
//     return;
//      }
//  else {
//     swap(arr[index], arr[largestKaIndex]);
//     //ab recursion sambhal lega
//     index = largestKaIndex;
//     heapify(arr, n, index);
//   }

//   return;
// }




// o(logn) ....logn baar func chalega and func ki constant hai 