#include<iostream>
using namespace std ;
int main()
{
    int arr[5]={1,2,3,4,5};

    // pointer to int array  // pointer to entire bada dabba made of chote dabbes
    // int (*ptr)[5];        // ptr is pointer to array of size 5 and  storing address of array arr (ie storing its base address)
    // ptr=&arr;

    int (*ptr)[5]=&arr;


    // note : as ptr is pointer to entire array so iski operations toh normal pointer to single dabbe jse hi hoge par outputs alag hogi
    // it will behave same as &arr works ie
    //  ptr will work same as &arr : base add
   //   *ptr will work same as *(&arr)->arr : arr pointer
   //    ptr[i] will work same as (&arr)[i]-> *(&arr+i)  : i array dabbe shift ke baad address
    //  (*ptr)[i] will work same as (*(&arr))[i])->arr[i]   : value at i index


    cout<<ptr<<endl;// print base add         &arr
    cout<<*ptr<<endl;// print base add         *(&arr)
    cout<<ptr[2]<<endl; // print add of byte after skipping 2 dabba of array size    (&arr)[i]
  
    
    cout<<(*ptr)[0]<<endl; // print element at 0 index // ( ) are necessary as * has lower precedence then array subscript[]   //(*(&arr))[i])  
    cout<<(*ptr)[1]<<endl; // element at 1 index
    
return 0;
}





