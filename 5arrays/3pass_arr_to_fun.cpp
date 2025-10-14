#include<iostream>
using namespace std ;

void printarr(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return;
}


int main()
{
    int arr[5]={1,2,3,4,5};
    int n=5;  // no of elements of array
    printarr(arr,n);  // good practice hai size bhi pass krna  // or in this case (arr,5)       
return 0;
}


// array gets passed by reference 