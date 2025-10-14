#include <iostream>   // ques...each element occurs even times except one.....repeating nos occurs in pairs and same pairs are not adjacent......(koi no lagataar 2 se zyada baar noi aayega)....find odd times occuring element.........
using namespace std;                                  

  // obersvations.....ans is on even index....left side ans ke par pair ka firs lement is on even and seccond on odd...on right ..pair ka first is on odd and second on even

int findOddOccuringElement(int arr[], int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;

  while(s <= e) {

    //single element   // corner case
    if(s == e) {
      return s;
    }

    //mid check -> even or odd

    if(mid & 1) {                                             // if mid&1 is true -> mid is odd number
    // mid is odd
      if(mid-1 >=0 && arr[mid-1] == arr[mid]) {
        //right me jao
        s = mid + 1;
      }
      else {
        //left me jao
        e = mid - 1;
      }
    }
    else {
      // mid is even
      if(mid+1 < n && arr[mid] == arr[mid+1]){
        //right me jao
        s = mid + 2;        // mid+1 wala  check ho chuka hai isiliye +2
      }
      else {
        //ya toh main right part pr khada hu
        //ya toh main answer k upar khada hu
        //that's why e = mid krra hu
        // kyoki e = mid - 1; se ans lost ho skta h 
        e = mid;    
      }
    }
    mid = s + (e-s)/2;
  }
  return -1;
}


int main() {

  int arr[] = {10,10,20,20,30,30,4,20,20,15,15};
  int n = 13;

  int ansIndex = findOddOccuringElement(arr, n);

  cout << "Final Ans is: "<< arr[ansIndex] << endl; 
 
  return 0;
}



// xor se hojayega.....but o(n)....kam k liye binary search method