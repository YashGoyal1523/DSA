//heap - complete binary tree+ heap property

//max heap- parent>child ie node >left child and node >right child

// visualisation - tree  actual implementation - array

// create max heap by inserting elements one by one
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
      //1. insert to available position
      // 2. take to correct position (heapification) (upwards heapification)

    //1.
      if(size == capacity) {
        cout << "Heap OverFlow" << endl;
        return;
      }
     
      //size increase kar jaega
      size++;
      int index = size;                   // 1 indexed banaree , size wala  can be used for  index value ;)
      arr[index] = val;

    //2.  
      ///take the val to its correct position : heapify

  // in 1 indexed:
  // child to parent: i->i/2
  // parent to child : left child: i->2i , right child: i->2i+1

// child ka parent se compare krte jao .....parent child se bada nhi h toh  toh swap krte jao...jaha thik miljaye vaha ruukjao  ..... child node ko root node banne tak check krte jao...root par ruk jao
      while(index > 1) { //root node banne tak chaladiya... // root node ka index is 1...... 1 indexed hai
        int parentIndex = index/2;
        if(arr[index] > arr[parentIndex]) {    // assuming max heap
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
};

int main(){
  
  Heap h(20); // capacity 20 
  //insertion
  h.insert(1);
  h.insert(2);
  h.insert(3);
  h.insert(4);
  h.insert(5);

  cout << "Printing the content of heap: " << endl;
  h.printHeap();
  
  return 0;
}

// tc of insertion : o(logn)   { as tc of heapify : o(logn) as approx height is logn so logn baar chalega loop and ek iteration ki const hai}:  n - no of elements present in heap already

// whole creation : o(nlogn)  : n - no of elements which we will insert


 // heap can be accessed from top only ie  we can access only root node
 