// return index of min element
#include<iostream>
#include<limits.h>  // for  INT_MAX , INT_MIN
using namespace std ;

int findMinimumInArray(int arr[], int size) {
  
  int minAns = INT_MAX;   
    int minidx;                // agar minans ko arr[0] lo toh minidx ko 0 leke karlena
  for(int i=0; i<size; i++) {
    if(arr[i] < minAns) {
      minAns = arr[i];
      minidx=i;
    }
  }

  return minidx;
}
int main()
{
int arr[]={3,4,5,1,3,7,9};
int size=7;
int minindex=findMinimumInArray(arr,size);
cout<<"index of min is "<<minindex;

return 0;
}
