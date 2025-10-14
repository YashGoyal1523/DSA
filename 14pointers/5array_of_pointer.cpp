#include<iostream>
using namespace std ;
int main()
{
    int arr[3]={1,2,3};

    //array of pointers to int
    int*ptr[3];                             // syntax difference from pointer to array is only in brackets

    // assigning addresses to pointers 
    ptr[0]=&arr[0];
    ptr[1]=&arr[1];
    ptr[2]=&arr[2];

// accessing address stored
    cout<<ptr[0]<<endl; // value of 0 index of ptr array ie value of pointer at 0 index ie adddress stored at 0 index will be print
    // accessing values at address stored
    cout<<*ptr[0]<<endl; // value at address at 0 index will print

return 0;
}