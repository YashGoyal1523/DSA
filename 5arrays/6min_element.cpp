#include<iostream>
#include<limits.h>  // for  INT_MAX , INT_MIN
using namespace std ;

int findMinimumInArray(int arr[], int size) {
  //ans store variable
  int minAns = INT_MAX;

  for(int i=0; i<size; i++) {
    if(arr[i] < minAns) {
      minAns = arr[i];
    }
  }

  return minAns;
}
int main()
{
int arr[]={3,4,5,1,3,7,9};
int size=7;
int minimum=findMinimumInArray(arr,size);
cout<<"min is"<<minimum;

return 0;
}